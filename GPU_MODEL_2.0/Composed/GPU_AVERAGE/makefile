OBJS=GPU_AVERAGERJ__Join1.o GPU_AVERAGERJ__STREAMING_MULTIPROCESSOR.o GPU_AVERAGERJ.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_AVERAGERJ.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_AVERAGERJ_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_AVERAGERJ.a: FORCE
	$(MAKE) lib TARGET=libGPU_AVERAGERJ.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_AVERAGERJ_debug.a: FORCE
	$(MAKE) lib TARGET=libGPU_AVERAGERJ_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

