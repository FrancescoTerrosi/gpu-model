OBJS=GPU3_REWARDPVNodes.o GPU3_REWARDPVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPU3_REWARDPV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPU3_REWARDPV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPU3_REWARDPV.a: FORCE
	$(MAKE) lib TARGET=libGPU3_REWARDPV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPU3_REWARDPV_debug.a: FORCE
	$(MAKE) lib TARGET=libGPU3_REWARDPV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

