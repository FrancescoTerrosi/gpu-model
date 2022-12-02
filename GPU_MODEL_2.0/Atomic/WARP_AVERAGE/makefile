OBJS=WARP_AVERAGESAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libWARP_AVERAGESAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libWARP_AVERAGESAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libWARP_AVERAGESAN.a: FORCE
	$(MAKE) lib TARGET=libWARP_AVERAGESAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libWARP_AVERAGESAN_debug.a: FORCE
	$(MAKE) lib TARGET=libWARP_AVERAGESAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

