OBJS=MEMORYSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libMEMORYSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libMEMORYSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libMEMORYSAN.a: FORCE
	$(MAKE) lib TARGET=libMEMORYSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libMEMORYSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libMEMORYSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

