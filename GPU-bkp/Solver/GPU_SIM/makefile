OBJS=


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

BINDIR=
MAINLIB=-lsimMain
MAINLIB_debug=-lsimMain_debug
SIMLIB=sim
SIMLIB_debug=sim_debug
SIMLIB_trace=sim_trace
PROJECTLIBS=-lGPUS_STUDYSetStudy -lGPU_REWARDPV -lGPU_MODEL_ATOMIC_COMPOSITIONSAN 
PROJECTLIBS_debug=-lGPUS_STUDYSetStudy_debug -lGPU_REWARDPV_debug -lGPU_MODEL_ATOMIC_COMPOSITIONSAN_debug 
MOBIUSLIBS=-lTRex -lStudy -lPV -lSAN -lbase -lstate -lmobutil -ldist 
MOBIUSLIBS_debug=-lTRex_debug -lStudy_debug -lPV_debug -lSAN_debug -lbase_debug -lstate_debug -lmobutil_debug -ldist_debug 
USERDEFLIBNAME=
USERDEFLIBDIR=

all: normal

opt \
GPU_SIMSim_$(ARCH): SUBMODELS/opt
	$(MAKE) exec3 "TARGET=GPU_SIMSim_$(ARCH)" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB) -l$(SIMLIB) $(USERDEFLIBNAME) $(PROJECTLIBS) $(USERDEFLIBNAME) $(MOBIUSLIBS)" 

normal debug \
GPU_SIMSim_$(ARCH)_debug: SUBMODELS/debug
	$(MAKE) exec3 "TARGET=GPU_SIMSim_$(ARCH)_debug" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_debug) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

trace \
GPU_SIMSim_$(ARCH)_trace:
	$(MAKE) exec3 "TARGET=GPU_SIMSim_$(ARCH)_trace" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_trace) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

clean_sub_dirs:
	cd ../../Atomic/GPU_MODEL_ATOMIC_COMPOSITION/ && $(MAKE) clean
	cd ../../Reward/GPU_REWARD/ && $(MAKE) clean
	cd ../../Study/GPUS_STUDY/ && $(MAKE) clean

SUBMODELS/opt SUBMODELS/debug:
	@echo "NEW_SUBMODEL_LIB:[GPU_MODEL_ATOMIC_COMPOSITION]"
	cd ../../Atomic/GPU_MODEL_ATOMIC_COMPOSITION/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[GPU_REWARD]"
	cd ../../Reward/GPU_REWARD/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[GPUS_STUDY]"
	cd ../../Study/GPUS_STUDY/ && $(MAKE) $(@F)


