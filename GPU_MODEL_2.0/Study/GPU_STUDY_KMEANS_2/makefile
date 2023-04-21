OBJS=GPU_STUDY_KMEANS_2SetStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_STUDY_KMEANS_2SetStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_STUDY_KMEANS_2SetStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_STUDY_KMEANS_2SetStudy.a: FORCE
	$(MAKE) lib TARGET=libGPU_STUDY_KMEANS_2SetStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_STUDY_KMEANS_2SetStudy_debug.a: FORCE
	$(MAKE) lib TARGET=libGPU_STUDY_KMEANS_2SetStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

