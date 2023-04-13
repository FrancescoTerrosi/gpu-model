OBJS=GPU5RJ__Rep1.o GPU5RJ__PROCESSOR_REP.o GPU5RJ__SM_REP.o GPU5RJ__PROCESSOR.o GPU5RJ__STREAMING_MULTIPROCESSOR.o GPU5RJ.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPU5RJ.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPU5RJ_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPU5RJ.a: FORCE
	$(MAKE) lib TARGET=libGPU5RJ.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPU5RJ_debug.a: FORCE
	$(MAKE) lib TARGET=libGPU5RJ_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

