OBJS=GPU4PVNodes.o GPU4PVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPU4PV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPU4PV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPU4PV.a: FORCE
	$(MAKE) lib TARGET=libGPU4PV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPU4PV_debug.a: FORCE
	$(MAKE) lib TARGET=libGPU4PV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

