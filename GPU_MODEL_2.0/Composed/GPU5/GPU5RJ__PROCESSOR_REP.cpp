#include "Composed/GPU5/GPU5RJ__PROCESSOR_REP.h"
char * GPU5RJ__PROCESSOR_REP__SharedNames[] = {"MEM_OP_COMPLETE", "READ_DRAM", "READ_L1", "READ_L2", "RESULT_KO", "RESULT_OK", "WRITE_DRAM", "WRITE_L1", "WRITE_L2"};

GPU5RJ__PROCESSOR_REP::GPU5RJ__PROCESSOR_REP():Rep("PROCESSOR_REP", nprocessors, 9, GPU5RJ__PROCESSOR_REP__SharedNames)
{
  InstanceArray = new GPU5RJ__PROCESSOR * [NumModels];
  delete[] ModelArray;
  ModelArray = (BaseModelClass **) InstanceArray;
  for (counter = 0; counter < NumModels; counter++)
    InstanceArray[counter] = new GPU5RJ__PROCESSOR();

  SetupActions();
  if (NumModels == 0) return;

  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************** Initialize local variables ****************
    MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE");
    addSharedPtr(MEM_OP_COMPLETE, "MEM_OP_COMPLETE");
    MEM_OP_COMPLETE->ShareWith(InstanceArray[0]->MEM_OP_COMPLETE);

    READ_DRAM = new Place("READ_DRAM");
    addSharedPtr(READ_DRAM, "READ_DRAM");
    READ_DRAM->ShareWith(InstanceArray[0]->READ_DRAM);

    READ_L1 = new Place("READ_L1");
    addSharedPtr(READ_L1, "READ_L1");
    READ_L1->ShareWith(InstanceArray[0]->READ_L1);

    READ_L2 = new Place("READ_L2");
    addSharedPtr(READ_L2, "READ_L2");
    READ_L2->ShareWith(InstanceArray[0]->READ_L2);

    RESULT_KO = new Place("RESULT_KO");
    addSharedPtr(RESULT_KO, "RESULT_KO");
    RESULT_KO->ShareWith(InstanceArray[0]->RESULT_KO);

    RESULT_OK = new Place("RESULT_OK");
    addSharedPtr(RESULT_OK, "RESULT_OK");
    RESULT_OK->ShareWith(InstanceArray[0]->RESULT_OK);

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
      addSharingInfo(InstanceArray[counter]->MEM_OP_COMPLETE, MEM_OP_COMPLETE);
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
      addSharingInfo(InstanceArray[counter]->RESULT_KO, RESULT_KO);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->RESULT_OK, RESULT_OK);
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
      InstanceArray[0]->MEM_OP_COMPLETE->ShareWith(InstanceArray[counter]->MEM_OP_COMPLETE);
      InstanceArray[0]->READ_DRAM->ShareWith(InstanceArray[counter]->READ_DRAM);
      InstanceArray[0]->READ_L1->ShareWith(InstanceArray[counter]->READ_L1);
      InstanceArray[0]->READ_L2->ShareWith(InstanceArray[counter]->READ_L2);
      InstanceArray[0]->RESULT_KO->ShareWith(InstanceArray[counter]->RESULT_KO);
      InstanceArray[0]->RESULT_OK->ShareWith(InstanceArray[counter]->RESULT_OK);
      InstanceArray[0]->WRITE_DRAM->ShareWith(InstanceArray[counter]->WRITE_DRAM);
      InstanceArray[0]->WRITE_L1->ShareWith(InstanceArray[counter]->WRITE_L1);
      InstanceArray[0]->WRITE_L2->ShareWith(InstanceArray[counter]->WRITE_L2);
    }
  }
  Setup("PROCESSOR");
}

GPU5RJ__PROCESSOR_REP::~GPU5RJ__PROCESSOR_REP() {
  if (NumModels == 0) return;
  delete MEM_OP_COMPLETE;
  delete READ_DRAM;
  delete READ_L1;
  delete READ_L2;
  delete RESULT_KO;
  delete RESULT_OK;
  delete WRITE_DRAM;
  delete WRITE_L1;
  delete WRITE_L2;
  for (int i = 0; i < NumModels; i++)
    delete InstanceArray[i];
}

