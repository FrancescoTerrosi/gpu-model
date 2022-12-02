OBJS=LOCAL_MEMORYSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libLOCAL_MEMORYSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libLOCAL_MEMORYSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libLOCAL_MEMORYSAN.a: FORCE
	$(MAKE) lib TARGET=libLOCAL_MEMORYSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libLOCAL_MEMORYSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libLOCAL_MEMORYSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

