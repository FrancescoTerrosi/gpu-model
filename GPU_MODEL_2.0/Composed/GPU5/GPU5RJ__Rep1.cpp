#include "Composed/GPU5/GPU5RJ__Rep1.h"
char * GPU5RJ__Rep1__SharedNames[] = {"FLOAT_ALU_FAILURE", "INSTRUCTION_READY", "INT_ALU_FAILURE", "MEM_FAILURE", "REGISTERS_FILL", "REG_FAILURE", "SCHEDULER"};

GPU5RJ__Rep1::GPU5RJ__Rep1():Rep("Rep1", nwarps, 7, GPU5RJ__Rep1__SharedNames)
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
    FLOAT_ALU_FAILURE = new Place("FLOAT_ALU_FAILURE");
    addSharedPtr(FLOAT_ALU_FAILURE, "FLOAT_ALU_FAILURE");
    FLOAT_ALU_FAILURE->ShareWith(InstanceArray[0]->FLOAT_ALU_FAILURE);

    INSTRUCTION_READY = new Place("INSTRUCTION_READY");
    addSharedPtr(INSTRUCTION_READY, "INSTRUCTION_READY");
    INSTRUCTION_READY->ShareWith(InstanceArray[0]->INSTRUCTION_READY);

    INT_ALU_FAILURE = new Place("INT_ALU_FAILURE");
    addSharedPtr(INT_ALU_FAILURE, "INT_ALU_FAILURE");
    INT_ALU_FAILURE->ShareWith(InstanceArray[0]->INT_ALU_FAILURE);

    MEM_FAILURE = new Place("MEM_FAILURE");
    addSharedPtr(MEM_FAILURE, "MEM_FAILURE");
    MEM_FAILURE->ShareWith(InstanceArray[0]->MEM_FAILURE);

    REGISTERS_FILL = new Place("REGISTERS_FILL");
    addSharedPtr(REGISTERS_FILL, "REGISTERS_FILL");
    REGISTERS_FILL->ShareWith(InstanceArray[0]->REGISTERS_FILL);

    REG_FAILURE = new Place("REG_FAILURE");
    addSharedPtr(REG_FAILURE, "REG_FAILURE");
    REG_FAILURE->ShareWith(InstanceArray[0]->REG_FAILURE);

    SCHEDULER = new Place("SCHEDULER");
    addSharedPtr(SCHEDULER, "SCHEDULER");
    SCHEDULER->ShareWith(InstanceArray[0]->SCHEDULER);


    //Share state in submodels
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->FLOAT_ALU_FAILURE, FLOAT_ALU_FAILURE);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->INSTRUCTION_READY, INSTRUCTION_READY);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->INT_ALU_FAILURE, INT_ALU_FAILURE);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->MEM_FAILURE, MEM_FAILURE);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->REGISTERS_FILL, REGISTERS_FILL);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->REG_FAILURE, REG_FAILURE);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->SCHEDULER, SCHEDULER);
    }
    for (counter = 1; counter < NumModels; counter++) {
      InstanceArray[0]->FLOAT_ALU_FAILURE->ShareWith(InstanceArray[counter]->FLOAT_ALU_FAILURE);
      InstanceArray[0]->INSTRUCTION_READY->ShareWith(InstanceArray[counter]->INSTRUCTION_READY);
      InstanceArray[0]->INT_ALU_FAILURE->ShareWith(InstanceArray[counter]->INT_ALU_FAILURE);
      InstanceArray[0]->MEM_FAILURE->ShareWith(InstanceArray[counter]->MEM_FAILURE);
      InstanceArray[0]->REGISTERS_FILL->ShareWith(InstanceArray[counter]->REGISTERS_FILL);
      InstanceArray[0]->REG_FAILURE->ShareWith(InstanceArray[counter]->REG_FAILURE);
      InstanceArray[0]->SCHEDULER->ShareWith(InstanceArray[counter]->SCHEDULER);
    }
  }
  Setup("WARP");
}

GPU5RJ__Rep1::~GPU5RJ__Rep1() {
  if (NumModels == 0) return;
  delete FLOAT_ALU_FAILURE;
  delete INSTRUCTION_READY;
  delete INT_ALU_FAILURE;
  delete MEM_FAILURE;
  delete REGISTERS_FILL;
  delete REG_FAILURE;
  delete SCHEDULER;
  for (int i = 0; i < NumModels; i++)
    delete InstanceArray[i];
}

