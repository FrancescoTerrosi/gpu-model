OBJS=GPU4.o GPU4.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPU4.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPU4_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPU4.a: FORCE
	$(MAKE) lib TARGET=libGPU4.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPU4_debug.a: FORCE
	$(MAKE) lib TARGET=libGPU4_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

