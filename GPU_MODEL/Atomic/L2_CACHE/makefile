OBJS=L2_CACHESAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libL2_CACHESAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libL2_CACHESAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libL2_CACHESAN.a: FORCE
	$(MAKE) lib TARGET=libL2_CACHESAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libL2_CACHESAN_debug.a: FORCE
	$(MAKE) lib TARGET=libL2_CACHESAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

