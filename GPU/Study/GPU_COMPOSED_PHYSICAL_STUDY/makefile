OBJS=GPU_COMPOSED_PHYSICAL_STUDYSetStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_COMPOSED_PHYSICAL_STUDYSetStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_COMPOSED_PHYSICAL_STUDYSetStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_COMPOSED_PHYSICAL_STUDYSetStudy.a: FORCE
	$(MAKE) lib TARGET=libGPU_COMPOSED_PHYSICAL_STUDYSetStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_COMPOSED_PHYSICAL_STUDYSetStudy_debug.a: FORCE
	$(MAKE) lib TARGET=libGPU_COMPOSED_PHYSICAL_STUDYSetStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

