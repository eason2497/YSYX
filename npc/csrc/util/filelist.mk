ifdef CONFIG_ITRACE
CXXSRC = csrc/util/disasm.cc
CXXFLAGS += $(shell llvm-config --cxxflags) -fPIE
LIBS += $(shell llvm-config --libs)
endif