#include "Composed/GPU4.BKP/GPU4.BKPRJ__Rep1.h"
char * GPU4.BKPRJ__Rep1__SharedNames[] = {"INSTRUCTION_READY", "SCHEDULER"};

GPU4.BKPRJ__Rep1::GPU4.BKPRJ__Rep1():Rep("Rep1", 1, 2, GPU4.BKPRJ__Rep1__SharedNames)
{
  InstanceArray = new WARPSAN * [NumModels];
  delete[] ModelArray;
  ModelArray = (BaseModelClass **) InstanceArray;
  for (counter = 0; counter < NumModels; counter++)
    InstanceArray[counter] = new WARPSAN();

  SetupActions();
  if (NumModels == 0) return;

  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************** Initialize local variables ****************
    INSTRUCTION_READY = new Place("INSTRUCTION_READY");
    addSharedPtr(INSTRUCTION_READY, "INSTRUCTION_READY");
    INSTRUCTION_READY->ShareWith(InstanceArray[0]->INSTRUCTION_READY);

    SCHEDULER = new Place("SCHEDULER");
    addSharedPtr(SCHEDULER, "SCHEDULER");
    SCHEDULER->ShareWith(InstanceArray[0]->SCHEDULER);


    //Share state in submodels
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->INSTRUCTION_READY, INSTRUCTION_READY);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->SCHEDULER, SCHEDULER);
    }
    for (counter = 1; counter < NumModels; counter++) {
      InstanceArray[0]->INSTRUCTION_READY->ShareWith(InstanceArray[counter]->INSTRUCTION_READY);
      InstanceArray[0]->SCHEDULER->ShareWith(InstanceArray[counter]->SCHEDULER);
    }
  }
  Setup("WARP");
}

GPU4.BKPRJ__Rep1::~GPU4.BKPRJ__Rep1() {
  if (NumModels == 0) return;
  delete INSTRUCTION_READY;
  delete SCHEDULER;
  for (int i = 0; i < NumModels; i++)
    delete InstanceArray[i];
}

