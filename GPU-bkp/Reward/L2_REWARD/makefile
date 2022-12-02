OBJS=L2_REWARDPVNodes.o L2_REWARDPVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libL2_REWARDPV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libL2_REWARDPV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libL2_REWARDPV.a: FORCE
	$(MAKE) lib TARGET=libL2_REWARDPV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libL2_REWARDPV_debug.a: FORCE
	$(MAKE) lib TARGET=libL2_REWARDPV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

