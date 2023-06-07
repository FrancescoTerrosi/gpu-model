OBJS=DRAM_nofailSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libDRAM_nofailSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libDRAM_nofailSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libDRAM_nofailSAN.a: FORCE
	$(MAKE) lib TARGET=libDRAM_nofailSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libDRAM_nofailSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libDRAM_nofailSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

