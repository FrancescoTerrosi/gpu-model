OBJS=COMPUTE_UNITSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libCOMPUTE_UNITSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libCOMPUTE_UNITSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libCOMPUTE_UNITSAN.a: FORCE
	$(MAKE) lib TARGET=libCOMPUTE_UNITSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libCOMPUTE_UNITSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libCOMPUTE_UNITSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

