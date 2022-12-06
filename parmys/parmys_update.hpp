#ifndef __DESIGN_UPDATE_H__
#define __DESIGN_UPDATE_H__

#include "odin_types.h"

#define DEFAULT_CLOCK_NAME "GLOBAL_SIM_BASE_CLK"

void define_logical_function_yosys(nnode_t *node, Yosys::Module *module);
void update_design(Yosys::Design *design, netlist_t *netlist);
void define_MUX_function_yosys(nnode_t *node, Yosys::Module *module);
void define_FF_yosys(nnode_t *node, Yosys::Module *module);

#endif //__DESIGN_UPDATE_H__