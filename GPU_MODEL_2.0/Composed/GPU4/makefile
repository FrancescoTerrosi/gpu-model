OBJS=GPU4RJ__Rep1.o GPU4RJ__PROCESSOR_REP.o GPU4RJ__PROCESSOR.o GPU4RJ__STREAMING_MULTIPROCESSOR.o GPU4RJ.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPU4RJ.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPU4RJ_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPU4RJ.a: FORCE
	$(MAKE) lib TARGET=libGPU4RJ.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPU4RJ_debug.a: FORCE
	$(MAKE) lib TARGET=libGPU4RJ_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

