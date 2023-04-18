OBJS=GPU_STUDY_GEMM_512SetStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_STUDY_GEMM_512SetStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libGPU_STUDY_GEMM_512SetStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_STUDY_GEMM_512SetStudy.a: FORCE
	$(MAKE) lib TARGET=libGPU_STUDY_GEMM_512SetStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libGPU_STUDY_GEMM_512SetStudy_debug.a: FORCE
	$(MAKE) lib TARGET=libGPU_STUDY_GEMM_512SetStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

