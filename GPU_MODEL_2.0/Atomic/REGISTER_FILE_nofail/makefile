OBJS=REGISTER_FILE_nofailSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libREGISTER_FILE_nofailSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libREGISTER_FILE_nofailSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libREGISTER_FILE_nofailSAN.a: FORCE
	$(MAKE) lib TARGET=libREGISTER_FILE_nofailSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libREGISTER_FILE_nofailSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libREGISTER_FILE_nofailSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

