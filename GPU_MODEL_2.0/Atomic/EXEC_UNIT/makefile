OBJS=EXEC_UNITSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libEXEC_UNITSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libEXEC_UNITSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libEXEC_UNITSAN.a: FORCE
	$(MAKE) lib TARGET=libEXEC_UNITSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libEXEC_UNITSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libEXEC_UNITSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

