OBJS=GPURJ.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPURJ.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPURJ_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPURJ.a: FORCE
	$(MAKE) lib TARGET=libGPURJ.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPURJ_debug.a: FORCE
	$(MAKE) lib TARGET=libGPURJ_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

