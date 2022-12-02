OBJS=GPU_AVERAGEPVNodes.o GPU_AVERAGEPVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_AVERAGEPV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_AVERAGEPV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_AVERAGEPV.a: FORCE
	$(MAKE) lib TARGET=libGPU_AVERAGEPV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_AVERAGEPV_debug.a: FORCE
	$(MAKE) lib TARGET=libGPU_AVERAGEPV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

