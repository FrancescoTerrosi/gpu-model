#include "Composed/GPU4/GPU4RJ__WARPS.h"
char * GPU4RJ__WARPS__SharedNames[] = {"INSTRUCTION_READY", "SCHEDULER"};

GPU4RJ__WARPS::GPU4RJ__WARPS():Join("WARPS", 3, 2,GPU4RJ__WARPS__SharedNames) {
  WARP = new WARPSAN();
  ModelArray[0] = (BaseModelClass*) WARP;
  ModelArray[0]->DefineName("WARP");
  WARP1 = new WARPSAN();
  ModelArray[1] = (BaseModelClass*) WARP1;
  ModelArray[1]->DefineName("WARP1");
  WARP2 = new WARPSAN();
  ModelArray[2] = (BaseModelClass*) WARP2;
  ModelArray[2]->DefineName("WARP2");

  SetupActions();
  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************  State sharing info  **************
    //Shared variable 0
    INSTRUCTION_READY = new Place("INSTRUCTION_READY");
    addSharedPtr(INSTRUCTION_READY, "INSTRUCTION_READY" );
    if (WARP->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(WARP->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(WARP->INSTRUCTION_READY), INSTRUCTION_READY, WARP);
    }
    if (WARP1->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(WARP1->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(WARP1->INSTRUCTION_READY), INSTRUCTION_READY, WARP1);
    }
    if (WARP2->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(WARP2->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(WARP2->INSTRUCTION_READY), INSTRUCTION_READY, WARP2);
    }

    //Shared variable 1
    SCHEDULER = new Place("SCHEDULER");
    addSharedPtr(SCHEDULER, "SCHEDULER" );
    if (WARP->NumStateVariables > 0) {
      SCHEDULER->ShareWith(getSharableSVPointer(WARP->SCHEDULER));
      addSharingInfo(getSharableSVPointer(WARP->SCHEDULER), SCHEDULER, WARP);
    }
    if (WARP1->NumStateVariables > 0) {
      SCHEDULER->ShareWith(getSharableSVPointer(WARP1->SCHEDULER));
      addSharingInfo(getSharableSVPointer(WARP1->SCHEDULER), SCHEDULER, WARP1);
    }
    if (WARP2->NumStateVariables > 0) {
      SCHEDULER->ShareWith(getSharableSVPointer(WARP2->SCHEDULER));
      addSharingInfo(getSharableSVPointer(WARP2->SCHEDULER), SCHEDULER, WARP2);
    }

  }

  Setup();
}

GPU4RJ__WARPS::~GPU4RJ__WARPS() {
  if (!AllChildrenEmpty()) {
    delete INSTRUCTION_READY;
    delete SCHEDULER;
  }
  delete WARP;
  delete WARP1;
  delete WARP2;
}
