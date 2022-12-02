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
PROJECTLIBS=-lGPU_STUDYSetStudy -lGPU_REWARDPV -lGPURJ -lCOMPUTE_UNITSAN -lDRAMSAN -lL2_CACHESAN -lL1_CACHESAN -lINITIAL_MEMORY_MODELSAN -lINTERMEDIATE_MEMORY_MODELSAN -lFINAL_MEMORY_MODELSAN 
PROJECTLIBS_debug=-lGPU_STUDYSetStudy_debug -lGPU_REWARDPV_debug -lGPURJ_debug -lCOMPUTE_UNITSAN_debug -lDRAMSAN_debug -lL2_CACHESAN_debug -lL1_CACHESAN_debug -lINITIAL_MEMORY_MODELSAN_debug -lINTERMEDIATE_MEMORY_MODELSAN_debug -lFINAL_MEMORY_MODELSAN_debug 
MOBIUSLIBS=-lTRex -lStudy -lPV -lComposer_RepJoin -lSAN -lbase -lstate -lmobutil -ldist 
MOBIUSLIBS_debug=-lTRex_debug -lStudy_debug -lPV_debug -lComposer_RepJoin_debug -lSAN_debug -lbase_debug -lstate_debug -lmobutil_debug -ldist_debug 
USERDEFLIBNAME=
USERDEFLIBDIR=

all: normal

opt \
GPU_SOLVERSim_$(ARCH): SUBMODELS/opt
	$(MAKE) exec3 "TARGET=GPU_SOLVERSim_$(ARCH)" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB) -l$(SIMLIB) $(USERDEFLIBNAME) $(PROJECTLIBS) $(USERDEFLIBNAME) $(MOBIUSLIBS)" 

normal debug \
GPU_SOLVERSim_$(ARCH)_debug: SUBMODELS/debug
	$(MAKE) exec3 "TARGET=GPU_SOLVERSim_$(ARCH)_debug" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_debug) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

trace \
GPU_SOLVERSim_$(ARCH)_trace:
	$(MAKE) exec3 "TARGET=GPU_SOLVERSim_$(ARCH)_trace" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_trace) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

clean_sub_dirs:
	cd ../../Atomic/FINAL_MEMORY_MODEL/ && $(MAKE) clean
	cd ../../Atomic/INTERMEDIATE_MEMORY_MODEL/ && $(MAKE) clean
	cd ../../Atomic/INITIAL_MEMORY_MODEL/ && $(MAKE) clean
	cd ../../Atomic/L1_CACHE/ && $(MAKE) clean
	cd ../../Atomic/L2_CACHE/ && $(MAKE) clean
	cd ../../Atomic/DRAM/ && $(MAKE) clean
	cd ../../Atomic/COMPUTE_UNIT/ && $(MAKE) clean
	cd ../../Composed/GPU/ && $(MAKE) clean
	cd ../../Reward/GPU_REWARD/ && $(MAKE) clean
	cd ../../Study/GPU_STUDY/ && $(MAKE) clean

SUBMODELS/opt SUBMODELS/debug:
	@echo "NEW_SUBMODEL_LIB:[FINAL_MEMORY_MODEL]"
	cd ../../Atomic/FINAL_MEMORY_MODEL/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[INTERMEDIATE_MEMORY_MODEL]"
	cd ../../Atomic/INTERMEDIATE_MEMORY_MODEL/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[INITIAL_MEMORY_MODEL]"
	cd ../../Atomic/INITIAL_MEMORY_MODEL/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[L1_CACHE]"
	cd ../../Atomic/L1_CACHE/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[L2_CACHE]"
	cd ../../Atomic/L2_CACHE/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[DRAM]"
	cd ../../Atomic/DRAM/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[COMPUTE_UNIT]"
	cd ../../Atomic/COMPUTE_UNIT/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[GPU]"
	cd ../../Composed/GPU/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[GPU_REWARD]"
	cd ../../Reward/GPU_REWARD/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[GPU_STUDY]"
	cd ../../Study/GPU_STUDY/ && $(MAKE) $(@F)


