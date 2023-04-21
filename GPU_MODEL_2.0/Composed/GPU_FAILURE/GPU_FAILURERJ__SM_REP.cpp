#include "Composed/GPU_FAILURE/GPU_FAILURERJ__SM_REP.h"
char * GPU_FAILURERJ__SM_REP__SharedNames[] = {"INSTRUCTION_READY", "MEM_FAILURE", "READ_DRAM", "READ_L2", "WRITE_DRAM", "WRITE_L2"};

GPU_FAILURERJ__SM_REP::GPU_FAILURERJ__SM_REP():Rep("SM_REP", nsm, 6, GPU_FAILURERJ__SM_REP__SharedNames)
{
  InstanceArray = new GPU_FAILURERJ__STREAMING_MULTIPROCESSOR * [NumModels];
  delete[] ModelArray;
  ModelArray = (BaseModelClass **) InstanceArray;
  for (counter = 0; counter < NumModels; counter++)
    InstanceArray[counter] = new GPU_FAILURERJ__STREAMING_MULTIPROCESSOR();

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

    READ_L2 = new Place("READ_L2");
    addSharedPtr(READ_L2, "READ_L2");
    READ_L2->ShareWith(InstanceArray[0]->READ_L2);

    WRITE_DRAM = new Place("WRITE_DRAM");
    addSharedPtr(WRITE_DRAM, "WRITE_DRAM");
    WRITE_DRAM->ShareWith(InstanceArray[0]->WRITE_DRAM);

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
      addSharingInfo(InstanceArray[counter]->READ_L2, READ_L2);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->WRITE_DRAM, WRITE_DRAM);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->WRITE_L2, WRITE_L2);
    }
    for (counter = 1; counter < NumModels; counter++) {
      InstanceArray[0]->INSTRUCTION_READY->ShareWith(InstanceArray[counter]->INSTRUCTION_READY);
      InstanceArray[0]->MEM_FAILURE->ShareWith(InstanceArray[counter]->MEM_FAILURE);
      InstanceArray[0]->READ_DRAM->ShareWith(InstanceArray[counter]->READ_DRAM);
      InstanceArray[0]->READ_L2->ShareWith(InstanceArray[counter]->READ_L2);
      InstanceArray[0]->WRITE_DRAM->ShareWith(InstanceArray[counter]->WRITE_DRAM);
      InstanceArray[0]->WRITE_L2->ShareWith(InstanceArray[counter]->WRITE_L2);
    }
  }
  Setup("STREAMING_MULTIPROCESSOR");
}

GPU_FAILURERJ__SM_REP::~GPU_FAILURERJ__SM_REP() {
  if (NumModels == 0) return;
  delete INSTRUCTION_READY;
  delete MEM_FAILURE;
  delete READ_DRAM;
  delete READ_L2;
  delete WRITE_DRAM;
  delete WRITE_L2;
  for (int i = 0; i < NumModels; i++)
    delete InstanceArray[i];
}

