OBJS=INITIAL_MEMORY_MODELSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libINITIAL_MEMORY_MODELSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libINITIAL_MEMORY_MODELSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libINITIAL_MEMORY_MODELSAN.a: FORCE
	$(MAKE) lib TARGET=libINITIAL_MEMORY_MODELSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libINITIAL_MEMORY_MODELSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libINITIAL_MEMORY_MODELSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

