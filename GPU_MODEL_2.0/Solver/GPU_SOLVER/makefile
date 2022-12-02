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
PROJECTLIBS=-lGPU_STUDYSetStudy -lGPU4PV -lGPU4RJ -lCOMPUTE_UNITSAN -lLOCAL_MEMORYSAN -lGLOBAL_MEMORYSAN -lREGISTER_FILESAN -lOUTPUT_MEMORYSAN -lL1_CACHESAN -lDRAMSAN -lL2_CACHESAN -lWARPSAN 
PROJECTLIBS_debug=-lGPU_STUDYSetStudy_debug -lGPU4PV_debug -lGPU4RJ_debug -lCOMPUTE_UNITSAN_debug -lLOCAL_MEMORYSAN_debug -lGLOBAL_MEMORYSAN_debug -lREGISTER_FILESAN_debug -lOUTPUT_MEMORYSAN_debug -lL1_CACHESAN_debug -lDRAMSAN_debug -lL2_CACHESAN_debug -lWARPSAN_debug 
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
	cd ../../Atomic/WARP/ && $(MAKE) clean
	cd ../../Atomic/L2_CACHE/ && $(MAKE) clean
	cd ../../Atomic/DRAM/ && $(MAKE) clean
	cd ../../Atomic/L1_CACHE/ && $(MAKE) clean
	cd ../../Atomic/OUTPUT_MEMORY/ && $(MAKE) clean
	cd ../../Atomic/REGISTER_FILE/ && $(MAKE) clean
	cd ../../Atomic/GLOBAL_MEMORY/ && $(MAKE) clean
	cd ../../Atomic/LOCAL_MEMORY/ && $(MAKE) clean
	cd ../../Atomic/COMPUTE_UNIT/ && $(MAKE) clean
	cd ../../Composed/GPU4/ && $(MAKE) clean
	cd ../../Reward/GPU4/ && $(MAKE) clean
	cd ../../Study/GPU_STUDY/ && $(MAKE) clean

SUBMODELS/opt SUBMODELS/debug:
	@echo "NEW_SUBMODEL_LIB:[WARP]"
	cd ../../Atomic/WARP/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[L2_CACHE]"
	cd ../../Atomic/L2_CACHE/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[DRAM]"
	cd ../../Atomic/DRAM/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[L1_CACHE]"
	cd ../../Atomic/L1_CACHE/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[OUTPUT_MEMORY]"
	cd ../../Atomic/OUTPUT_MEMORY/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[REGISTER_FILE]"
	cd ../../Atomic/REGISTER_FILE/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[GLOBAL_MEMORY]"
	cd ../../Atomic/GLOBAL_MEMORY/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[LOCAL_MEMORY]"
	cd ../../Atomic/LOCAL_MEMORY/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[COMPUTE_UNIT]"
	cd ../../Atomic/COMPUTE_UNIT/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[GPU4]"
	cd ../../Composed/GPU4/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[GPU4]"
	cd ../../Reward/GPU4/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[GPU_STUDY]"
	cd ../../Study/GPU_STUDY/ && $(MAKE) $(@F)


