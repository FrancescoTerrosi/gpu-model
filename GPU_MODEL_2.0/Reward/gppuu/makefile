OBJS=gppuuPVNodes.o gppuuPVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libgppuuPV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libgppuuPV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libgppuuPV.a: FORCE
	$(MAKE) lib TARGET=libgppuuPV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libgppuuPV_debug.a: FORCE
	$(MAKE) lib TARGET=libgppuuPV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

