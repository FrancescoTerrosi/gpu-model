OBJS=L2_STUDYSetStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libL2_STUDYSetStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libL2_STUDYSetStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libL2_STUDYSetStudy.a: FORCE
	$(MAKE) lib TARGET=libL2_STUDYSetStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libL2_STUDYSetStudy_debug.a: FORCE
	$(MAKE) lib TARGET=libL2_STUDYSetStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

