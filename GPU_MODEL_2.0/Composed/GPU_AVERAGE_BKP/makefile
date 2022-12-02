OBJS=GPU_AVERAGE_BKPRJ__Join1.o GPU_AVERAGE_BKPRJ__STREAMING_MULTIPROCESSOR.o GPU_AVERAGE_BKPRJ.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_AVERAGE_BKPRJ.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_AVERAGE_BKPRJ_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_AVERAGE_BKPRJ.a: FORCE
	$(MAKE) lib TARGET=libGPU_AVERAGE_BKPRJ.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_AVERAGE_BKPRJ_debug.a: FORCE
	$(MAKE) lib TARGET=libGPU_AVERAGE_BKPRJ_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

