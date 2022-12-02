OBJS=REGISTER_FILESAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libREGISTER_FILESAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libREGISTER_FILESAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libREGISTER_FILESAN.a: FORCE
	$(MAKE) lib TARGET=libREGISTER_FILESAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libREGISTER_FILESAN_debug.a: FORCE
	$(MAKE) lib TARGET=libREGISTER_FILESAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

