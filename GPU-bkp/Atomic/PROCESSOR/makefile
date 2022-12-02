OBJS=PROCESSORSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libPROCESSORSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libPROCESSORSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libPROCESSORSAN.a: FORCE
	$(MAKE) lib TARGET=libPROCESSORSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libPROCESSORSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libPROCESSORSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

