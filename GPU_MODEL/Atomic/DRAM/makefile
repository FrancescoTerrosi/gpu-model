OBJS=DRAMSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libDRAMSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libDRAMSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libDRAMSAN.a: FORCE
	$(MAKE) lib TARGET=libDRAMSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libDRAMSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libDRAMSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

