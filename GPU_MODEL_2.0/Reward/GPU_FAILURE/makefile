OBJS=GPU_FAILUREPVNodes.o GPU_FAILUREPVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_FAILUREPV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_FAILUREPV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_FAILUREPV.a: FORCE
	$(MAKE) lib TARGET=libGPU_FAILUREPV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_FAILUREPV_debug.a: FORCE
	$(MAKE) lib TARGET=libGPU_FAILUREPV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

