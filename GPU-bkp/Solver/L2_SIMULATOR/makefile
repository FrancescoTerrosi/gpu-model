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
PROJECTLIBS=-lL2_STUDYSetStudy -lL2_REWARDPV 
PROJECTLIBS_debug=-lL2_STUDYSetStudy_debug -lL2_REWARDPV_debug 
MOBIUSLIBS=-lTRex -lStudy -lPV 
MOBIUSLIBS_debug=-lTRex_debug -lStudy_debug -lPV_debug 
USERDEFLIBNAME=
USERDEFLIBDIR=

all: normal

opt \
L2_SIMULATORSim_$(ARCH): SUBMODELS/opt
	$(MAKE) exec3 "TARGET=L2_SIMULATORSim_$(ARCH)" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB) -l$(SIMLIB) $(USERDEFLIBNAME) $(PROJECTLIBS) $(USERDEFLIBNAME) $(MOBIUSLIBS)" 

normal debug \
L2_SIMULATORSim_$(ARCH)_debug: SUBMODELS/debug
	$(MAKE) exec3 "TARGET=L2_SIMULATORSim_$(ARCH)_debug" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_debug) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

trace \
L2_SIMULATORSim_$(ARCH)_trace:
	$(MAKE) exec3 "TARGET=L2_SIMULATORSim_$(ARCH)_trace" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_trace) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

clean_sub_dirs:
	cd ../../Reward/L2_REWARD/ && $(MAKE) clean
	cd ../../Study/L2_STUDY/ && $(MAKE) clean

SUBMODELS/opt SUBMODELS/debug:
	@echo "NEW_SUBMODEL_LIB:[L2_REWARD]"
	cd ../../Reward/L2_REWARD/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[L2_STUDY]"
	cd ../../Study/L2_STUDY/ && $(MAKE) $(@F)


