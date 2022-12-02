OBJS=WARPSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libWARPSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libWARPSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libWARPSAN.a: FORCE
	$(MAKE) lib TARGET=libWARPSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libWARPSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libWARPSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

