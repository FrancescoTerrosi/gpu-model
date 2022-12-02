OBJS=GPU2RJ.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPU2RJ.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPU2RJ_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPU2RJ.a: FORCE
	$(MAKE) lib TARGET=libGPU2RJ.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPU2RJ_debug.a: FORCE
	$(MAKE) lib TARGET=libGPU2RJ_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

