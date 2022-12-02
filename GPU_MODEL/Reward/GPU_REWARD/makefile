OBJS=GPU_REWARDPVNodes.o GPU_REWARDPVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_REWARDPV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_REWARDPV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_REWARDPV.a: FORCE
	$(MAKE) lib TARGET=libGPU_REWARDPV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_REWARDPV_debug.a: FORCE
	$(MAKE) lib TARGET=libGPU_REWARDPV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

