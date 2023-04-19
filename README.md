# Parmys (Partial Mapper for Yosys) Plugin

This repository contains the intelligent partial mapping features from [Odin-II](https://github.com/verilog-to-routing/vtr-verilog-to-routing/tree/master/ODIN_II) wrapped in a plug-in for [Yosys](https://github.com/YosysHQ/yosys.git).

The project build skeleton is based on the [Yosys F4PGA Plugins](https://github.com/chipsalliance/yosys-f4pga-plugins.git) project.

It is highly recommended to utilize this plugin through the [Verilog to Routing (VTR)](https://github.com/verilog-to-routing/vtr-verilog-to-routing.git) project.

**Now the Parmys frontend is the default elaborator (using Yosys) and partial mapper (using the Parmys plug-in) in the VTR flow (Parmys -> ABC -> VPR).**

## Build as a plugin

- Clone, make, and install [Yosys](https://github.com/YosysHQ/yosys.git)
- Clone, make, and install [VTR](https://github.com/verilog-to-routing/vtr-verilog-to-routing.git)
- Build and install Parmys

```makefile
make VTR_INSTALL_DIR=`path to VTR build/install directory` plugins -j`nproc`
sudo make install
```

## Parameters
Available paramters are:
```
    -a ARCHITECTURE_FILE
        VTR FPGA architecture description file (XML)

    -c XML_CONFIGURATION_FILE
        Configuration file

    -top top_module
        set the specified module as design top module

    -nopass
        No additional passes will be executed.

    -exact_mults int_value
        To enable mixing hard block and soft logic implementation of adders

    -mults_ratio float_value
        To enable mixing hard block and soft logic implementation of adders

    -vtr_prim
        loads vtr primitives as modules, if the design uses vtr prmitives then this flag is mandatory for first run
        
    -viz
        visualizes the netlist at 3 different stages: elaborated, optimized, and mapped.
```

## Simple usage example (without VTR)

Example for simple partial mapping with parmys:

```sh
# run yosys
yosys

# load the plugin
plugin -i parmys

# read verilog files
read_verilog my_verilog.v

# use parmys to read the architecture file and partial mapping
parmys -a simple_vtr_fpga_architecture.xml

```

## Simple usage example (within the VTR flow)

- Clone [VTR](https://github.com/verilog-to-routing/vtr-verilog-to-routing.git)
- [Set up the Environment](https://docs.verilogtorouting.org/en/latest/BUILDING/#setting-up-your-environment)
- Build
- Run the VTR flow

```makefile
cd vtr_flow/scripts/

# this command runs the vtr flow [yosys+parmys, abc, vpr]
./run_vtr_flow.py my_verilog.v fpga_architecture.xml
```

For detailed information please refer to the [VTR documentation](https://docs.verilogtorouting.org/en/latest/).

Detailed help on the supported command(s) can be obtained by running `help parmys` in Yosys.
