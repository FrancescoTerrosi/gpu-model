OBJS=OUTPUT_MEMORY_PHYSICALSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libOUTPUT_MEMORY_PHYSICALSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libOUTPUT_MEMORY_PHYSICALSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libOUTPUT_MEMORY_PHYSICALSAN.a: FORCE
	$(MAKE) lib TARGET=libOUTPUT_MEMORY_PHYSICALSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libOUTPUT_MEMORY_PHYSICALSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libOUTPUT_MEMORY_PHYSICALSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

