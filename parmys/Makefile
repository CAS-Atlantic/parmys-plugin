NAME = parmys
SOURCES = parmys.cc \
		  parmys_arch.cc \
		  parmys_update.cc \
		  parmys_utils.cc \
		  parmys_resolve.cc \
		  adders.cc \
		  enum_str.cc \
		  MixingOptimization.cc \
		  read_xml_config_file.cc \
		  odin_error.cc \
		  odin_util.cc \
		  netlist_statistic.cc \
		  netlist_utils.cc \
		  netlist_check.cc \
		  netlist_cleanup.cc \
		  node_creation_library.cc \
		  multipliers.cc \
		  subtractions.cc \
		  HardSoftLogicMixer.cc \
		  odin_ii.cc \
		  string_cache.cc \
		  partial_map.cc \
		  hard_blocks.cc \
		  BlockMemories.cc \
		  memories.cc \
		  netlist_visualizer.cc \
		  Hashtable.cc \
		  ast_util.cc \
		  ../third_party/libvtrutil/src/vtr_util.cc \
		  ../third_party/libvtrutil/src/vtr_token.cc \
		  ../third_party/libvtrutil/src/vtr_memory.cc \
		  ../third_party/libvtrutil/src/vtr_list.cc \
		  ../third_party/libvtrutil/src/vtr_log.cc \
		  ../third_party/libvtrutil/src/vtr_expr_eval.cc \
		  ../third_party/libvtrutil/src/vtr_digest.cc \
		  ../third_party/libvtrutil/src/vtr_math.cc \
		  ../third_party/libvtrutil/src/vtr_path.cc \
		  ../third_party/libvtrutil/src/vtr_assert.cc \
		  ../third_party/liblog/src/log.cc \
		  ../third_party/libpugixml/src/pugixml.cc \
		  ../third_party/libargparse/src/argparse.cc \
		  ../third_party/libargparse/src/argparse_formatter.cc \
		  ../third_party/libargparse/src/argparse_util.cc \
		  ../third_party/librtlnumber/src/rtl_int.cc \
		  ../third_party/librtlnumber/src/rtl_utils.cc \
		  ../third_party/libpugiutil/src/pugixml_loc.cc \
		  ../third_party/libpugiutil/src/pugixml_util.cc \
		  ../third_party/libarchfpga/src/physical_types.cc \
		  ../third_party/libarchfpga/src/read_xml_util.cc \
		  ../third_party/libarchfpga/src/arch_error.cc \
		  ../third_party/libarchfpga/src/physical_types_util.cc \
		  ../third_party/libarchfpga/src/arch_check.cc \
		  ../third_party/libarchfpga/src/arch_util.cc \
		  ../third_party/libarchfpga/src/read_xml_arch_file.cc \
		  ../third_party/libarchfpga/src/parse_switchblocks.cc \
		  ../third_party/libarchfpga/src/echo_arch.cc

include ../Makefile_plugin.common

CXXFLAGS += -I../third_party/libpugixml/src
CXXFLAGS += -I../third_party/libarchfpga/src
CXXFLAGS += -I../third_party/liblog/src
CXXFLAGS += -I../third_party/libpugiutil/src
CXXFLAGS += -I../third_party/librtlnumber/src/include
CXXFLAGS += -I../third_party/librtlnumber/src
CXXFLAGS += -I../third_party/libvtrutil/src
CXXFLAGS += -I../third_party/libargparse/src

CXXSTD := c++14
CXXFLAGS += -std=$(CXXSTD) -Os

LDLIBS += -lpthread

install:
	install -D ../misc/adff2dff.v $(DATA_DIR)/parmys/adff2dff.v
	install -D ../misc/adffe2dff.v $(DATA_DIR)/parmys/adffe2dff.v
	install -D ../misc/aldff2dff.v $(DATA_DIR)/parmys/aldff2dff.v
	install -D ../misc/aldffe2dff.v $(DATA_DIR)/parmys/aldffe2dff.v
	install -D ../misc/primitives.v $(DATA_DIR)/parmys/vtr_primitives.v