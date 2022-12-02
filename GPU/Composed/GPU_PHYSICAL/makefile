OBJS=GPU_PHYSICALRJ.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_PHYSICALRJ.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_PHYSICALRJ_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_PHYSICALRJ.a: FORCE
	$(MAKE) lib TARGET=libGPU_PHYSICALRJ.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_PHYSICALRJ_debug.a: FORCE
	$(MAKE) lib TARGET=libGPU_PHYSICALRJ_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

