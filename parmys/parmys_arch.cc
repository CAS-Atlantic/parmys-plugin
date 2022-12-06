#include "kernel/yosys.h"

#include "arch_util.h"
#include "odin_types.h"
#include "parmys_utils.hpp"
#include "read_xml_arch_file.h"

USING_YOSYS_NAMESPACE
PRIVATE_NAMESPACE_BEGIN

struct ParmysArchPass : public Pass {

    static void add_hb_to_design(t_model *hb, Design *design)
    {
        Module *module = nullptr;
        dict<IdString, std::pair<int, bool>> wideports_cache;

        module = new Module;
        module->name = RTLIL::escape_id(hb->name);

        if (design->module(module->name))
            Yosys::log_error("Duplicate definition of module %s!\n", log_id(module->name));
        design->add(module);

        t_model_ports *input_port = hb->inputs;
        while (input_port) {
            for (int i = 0; i < input_port->size; i++) {
                std::string w_name = stringf("%s[%d]", input_port->name, i);
                Yosys::RTLIL::Wire *wire = to_wire(w_name, module);
                wire->port_input = true;
                std::pair<Yosys::RTLIL::IdString, int> wp = wideports_split(w_name);
                if (!wp.first.empty() && wp.second >= 0) {
                    wideports_cache[wp.first].first = std::max(wideports_cache[wp.first].first, wp.second + 1);
                    wideports_cache[wp.first].second = true;
                }
            }

            input_port = input_port->next;
        }

        t_model_ports *output_port = hb->outputs;
        while (output_port) {
            for (int i = 0; i < output_port->size; i++) {
                std::string w_name = stringf("%s[%d]", output_port->name, i);
                Yosys::RTLIL::Wire *wire = to_wire(w_name, module);
                wire->port_output = true;
                std::pair<Yosys::RTLIL::IdString, int> wp = wideports_split(w_name);
                if (!wp.first.empty() && wp.second >= 0) {
                    wideports_cache[wp.first].first = std::max(wideports_cache[wp.first].first, wp.second + 1);
                    wideports_cache[wp.first].second = false;
                }
            }

            output_port = output_port->next;
        }

        handle_wideports_cache(&wideports_cache, module);

        module->fixup_ports();
        wideports_cache.clear();

        module->attributes[ID::blackbox] = RTLIL::Const(1);
    }

    ParmysArchPass() : Pass("parmys_arch", "loads available hard blocks within the architecture to Yosys Design") {}

    void help() override
    {
        log("\n");
        log("    -a ARCHITECTURE_FILE\n");
        log("        VTR FPGA architecture description file (XML)\n");
    }

    void execute(std::vector<std::string> args, RTLIL::Design *design) override
    {
        size_t argidx = 1;
        std::string arch_file_path;
        if (args[argidx] == "-a" && argidx + 1 < args.size()) {
            arch_file_path = args[++argidx];
            argidx++;
        }
        extra_args(args, argidx, design);

        t_arch arch;

        std::vector<t_physical_tile_type> physical_tile_types;
        std::vector<t_logical_block_type> logical_block_types;

        try {
            XmlReadArch(arch_file_path.c_str(), false, &arch, physical_tile_types, logical_block_types);
        } catch (vtr::VtrError &vtr_error) {
            log_error("Odin Failed to load architecture file: %s with exit code %s at line: %ld\n", vtr_error.what(), "ERROR_PARSE_ARCH",
                      vtr_error.line());
        }

        t_model *hb = arch.models;
        while (hb) {
            if (strcmp(hb->name, SINGLE_PORT_RAM_string) && strcmp(hb->name, DUAL_PORT_RAM_string) && strcmp(hb->name, "multiply") &&
                strcmp(hb->name, "adder")) {
                add_hb_to_design(hb, design);
                log("Hard block added to the Design ---> `%s`\n", hb->name);
            }

            hb = hb->next;
        }

        // CLEAN UP
        free_arch(&arch);
        free_type_descriptors(physical_tile_types);
        free_type_descriptors(logical_block_types);

        log("parmys_arch pass finished.\n");
    }

} ParmysArchPass;

PRIVATE_NAMESPACE_END