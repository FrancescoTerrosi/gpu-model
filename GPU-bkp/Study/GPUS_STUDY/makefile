OBJS=GPUS_STUDYSetStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPUS_STUDYSetStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPUS_STUDYSetStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPUS_STUDYSetStudy.a: FORCE
	$(MAKE) lib TARGET=libGPUS_STUDYSetStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPUS_STUDYSetStudy_debug.a: FORCE
	$(MAKE) lib TARGET=libGPUS_STUDYSetStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

