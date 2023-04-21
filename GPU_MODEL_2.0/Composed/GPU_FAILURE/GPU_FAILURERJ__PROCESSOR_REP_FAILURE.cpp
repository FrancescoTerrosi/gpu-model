#include "Composed/GPU_FAILURE/GPU_FAILURERJ__PROCESSOR_REP_FAILURE.h"
char * GPU_FAILURERJ__PROCESSOR_REP_FAILURE__SharedNames[] = {"INSTRUCTION_READY", "MEM_FAILURE", "READ_DRAM", "READ_L1", "READ_L2", "WARP_ACCESS_DRAM", "WARP_ACCESS_L1", "WARP_ACCESS_L2", "WRITE_DRAM", "WRITE_L1", "WRITE_L2"};

GPU_FAILURERJ__PROCESSOR_REP_FAILURE::GPU_FAILURERJ__PROCESSOR_REP_FAILURE():Rep("PROCESSOR_REP_FAILURE", nfailedprocessors, 11, GPU_FAILURERJ__PROCESSOR_REP_FAILURE__SharedNames)
{
  InstanceArray = new GPU_FAILURERJ__PROCESSOR_FAILURE * [NumModels];
  delete[] ModelArray;
  ModelArray = (BaseModelClass **) InstanceArray;
  for (counter = 0; counter < NumModels; counter++)
    InstanceArray[counter] = new GPU_FAILURERJ__PROCESSOR_FAILURE();

  SetupActions();
  if (NumModels == 0) return;

  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************** Initialize local variables ****************
    INSTRUCTION_READY = new Place("INSTRUCTION_READY");
    addSharedPtr(INSTRUCTION_READY, "INSTRUCTION_READY");
    INSTRUCTION_READY->ShareWith(InstanceArray[0]->INSTRUCTION_READY);

    MEM_FAILURE = new Place("MEM_FAILURE");
    addSharedPtr(MEM_FAILURE, "MEM_FAILURE");
    MEM_FAILURE->ShareWith(InstanceArray[0]->MEM_FAILURE);

    READ_DRAM = new Place("READ_DRAM");
    addSharedPtr(READ_DRAM, "READ_DRAM");
    READ_DRAM->ShareWith(InstanceArray[0]->READ_DRAM);

    READ_L1 = new Place("READ_L1");
    addSharedPtr(READ_L1, "READ_L1");
    READ_L1->ShareWith(InstanceArray[0]->READ_L1);

    READ_L2 = new Place("READ_L2");
    addSharedPtr(READ_L2, "READ_L2");
    READ_L2->ShareWith(InstanceArray[0]->READ_L2);

    WARP_ACCESS_DRAM = new Place("WARP_ACCESS_DRAM");
    addSharedPtr(WARP_ACCESS_DRAM, "WARP_ACCESS_DRAM");
    WARP_ACCESS_DRAM->ShareWith(InstanceArray[0]->WARP_ACCESS_DRAM);

    WARP_ACCESS_L1 = new Place("WARP_ACCESS_L1");
    addSharedPtr(WARP_ACCESS_L1, "WARP_ACCESS_L1");
    WARP_ACCESS_L1->ShareWith(InstanceArray[0]->WARP_ACCESS_L1);

    WARP_ACCESS_L2 = new Place("WARP_ACCESS_L2");
    addSharedPtr(WARP_ACCESS_L2, "WARP_ACCESS_L2");
    WARP_ACCESS_L2->ShareWith(InstanceArray[0]->WARP_ACCESS_L2);

    WRITE_DRAM = new Place("WRITE_DRAM");
    addSharedPtr(WRITE_DRAM, "WRITE_DRAM");
    WRITE_DRAM->ShareWith(InstanceArray[0]->WRITE_DRAM);

    WRITE_L1 = new Place("WRITE_L1");
    addSharedPtr(WRITE_L1, "WRITE_L1");
    WRITE_L1->ShareWith(InstanceArray[0]->WRITE_L1);

    WRITE_L2 = new Place("WRITE_L2");
    addSharedPtr(WRITE_L2, "WRITE_L2");
    WRITE_L2->ShareWith(InstanceArray[0]->WRITE_L2);


    //Share state in submodels
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->INSTRUCTION_READY, INSTRUCTION_READY);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->MEM_FAILURE, MEM_FAILURE);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->READ_DRAM, READ_DRAM);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->READ_L1, READ_L1);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->READ_L2, READ_L2);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->WARP_ACCESS_DRAM, WARP_ACCESS_DRAM);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->WARP_ACCESS_L1, WARP_ACCESS_L1);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->WARP_ACCESS_L2, WARP_ACCESS_L2);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->WRITE_DRAM, WRITE_DRAM);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->WRITE_L1, WRITE_L1);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->WRITE_L2, WRITE_L2);
    }
    for (counter = 1; counter < NumModels; counter++) {
      InstanceArray[0]->INSTRUCTION_READY->ShareWith(InstanceArray[counter]->INSTRUCTION_READY);
      InstanceArray[0]->MEM_FAILURE->ShareWith(InstanceArray[counter]->MEM_FAILURE);
      InstanceArray[0]->READ_DRAM->ShareWith(InstanceArray[counter]->READ_DRAM);
      InstanceArray[0]->READ_L1->ShareWith(InstanceArray[counter]->READ_L1);
      InstanceArray[0]->READ_L2->ShareWith(InstanceArray[counter]->READ_L2);
      InstanceArray[0]->WARP_ACCESS_DRAM->ShareWith(InstanceArray[counter]->WARP_ACCESS_DRAM);
      InstanceArray[0]->WARP_ACCESS_L1->ShareWith(InstanceArray[counter]->WARP_ACCESS_L1);
      InstanceArray[0]->WARP_ACCESS_L2->ShareWith(InstanceArray[counter]->WARP_ACCESS_L2);
      InstanceArray[0]->WRITE_DRAM->ShareWith(InstanceArray[counter]->WRITE_DRAM);
      InstanceArray[0]->WRITE_L1->ShareWith(InstanceArray[counter]->WRITE_L1);
      InstanceArray[0]->WRITE_L2->ShareWith(InstanceArray[counter]->WRITE_L2);
    }
  }
  Setup("PROCESSOR_FAILURE");
}

GPU_FAILURERJ__PROCESSOR_REP_FAILURE::~GPU_FAILURERJ__PROCESSOR_REP_FAILURE() {
  if (NumModels == 0) return;
  delete INSTRUCTION_READY;
  delete MEM_FAILURE;
  delete READ_DRAM;
  delete READ_L1;
  delete READ_L2;
  delete WARP_ACCESS_DRAM;
  delete WARP_ACCESS_L1;
  delete WARP_ACCESS_L2;
  delete WRITE_DRAM;
  delete WRITE_L1;
  delete WRITE_L2;
  for (int i = 0; i < NumModels; i++)
    delete InstanceArray[i];
}

