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
PROJECTLIBS=-lGPU_STUDY_KMEANS_1SetStudy -lGPU5PV -lGPU5RJ -lREGISTER_FILESAN -lL1_CACHESAN -lDRAMSAN -lL2_CACHESAN -lWARPSAN -lEXEC_UNITSAN -lMEMORYSAN 
PROJECTLIBS_debug=-lGPU_STUDY_KMEANS_1SetStudy_debug -lGPU5PV_debug -lGPU5RJ_debug -lREGISTER_FILESAN_debug -lL1_CACHESAN_debug -lDRAMSAN_debug -lL2_CACHESAN_debug -lWARPSAN_debug -lEXEC_UNITSAN_debug -lMEMORYSAN_debug 
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
	cd ../../Atomic/MEMORY/ && $(MAKE) clean
	cd ../../Atomic/EXEC_UNIT/ && $(MAKE) clean
	cd ../../Atomic/WARP/ && $(MAKE) clean
	cd ../../Atomic/L2_CACHE/ && $(MAKE) clean
	cd ../../Atomic/DRAM/ && $(MAKE) clean
	cd ../../Atomic/L1_CACHE/ && $(MAKE) clean
	cd ../../Atomic/REGISTER_FILE/ && $(MAKE) clean
	cd ../../Composed/GPU5/ && $(MAKE) clean
	cd ../../Reward/GPU5/ && $(MAKE) clean
	cd ../../Study/GPU_STUDY_KMEANS_1/ && $(MAKE) clean

SUBMODELS/opt SUBMODELS/debug:
	@echo "NEW_SUBMODEL_LIB:[MEMORY]"
	cd ../../Atomic/MEMORY/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[EXEC_UNIT]"
	cd ../../Atomic/EXEC_UNIT/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[WARP]"
	cd ../../Atomic/WARP/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[L2_CACHE]"
	cd ../../Atomic/L2_CACHE/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[DRAM]"
	cd ../../Atomic/DRAM/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[L1_CACHE]"
	cd ../../Atomic/L1_CACHE/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[REGISTER_FILE]"
	cd ../../Atomic/REGISTER_FILE/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[GPU5]"
	cd ../../Composed/GPU5/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[GPU5]"
	cd ../../Reward/GPU5/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[GPU_STUDY_KMEANS_1]"
	cd ../../Study/GPU_STUDY_KMEANS_1/ && $(MAKE) $(@F)


