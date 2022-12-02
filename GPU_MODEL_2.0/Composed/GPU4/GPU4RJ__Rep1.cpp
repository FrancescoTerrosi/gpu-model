#include "Composed/GPU4/GPU4RJ__Rep1.h"
char * GPU4RJ__Rep1__SharedNames[] = {"INSTRUCTION_READY", "REGISTERS_FILL", "SCHEDULER"};

GPU4RJ__Rep1::GPU4RJ__Rep1():Rep("Rep1", nwarps, 3, GPU4RJ__Rep1__SharedNames)
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

    REGISTERS_FILL = new Place("REGISTERS_FILL");
    addSharedPtr(REGISTERS_FILL, "REGISTERS_FILL");
    REGISTERS_FILL->ShareWith(InstanceArray[0]->REGISTERS_FILL);

    SCHEDULER = new Place("SCHEDULER");
    addSharedPtr(SCHEDULER, "SCHEDULER");
    SCHEDULER->ShareWith(InstanceArray[0]->SCHEDULER);


    //Share state in submodels
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->INSTRUCTION_READY, INSTRUCTION_READY);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->REGISTERS_FILL, REGISTERS_FILL);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->SCHEDULER, SCHEDULER);
    }
    for (counter = 1; counter < NumModels; counter++) {
      InstanceArray[0]->INSTRUCTION_READY->ShareWith(InstanceArray[counter]->INSTRUCTION_READY);
      InstanceArray[0]->REGISTERS_FILL->ShareWith(InstanceArray[counter]->REGISTERS_FILL);
      InstanceArray[0]->SCHEDULER->ShareWith(InstanceArray[counter]->SCHEDULER);
    }
  }
  Setup("WARP");
}

GPU4RJ__Rep1::~GPU4RJ__Rep1() {
  if (NumModels == 0) return;
  delete INSTRUCTION_READY;
  delete REGISTERS_FILL;
  delete SCHEDULER;
  for (int i = 0; i < NumModels; i++)
    delete InstanceArray[i];
}

