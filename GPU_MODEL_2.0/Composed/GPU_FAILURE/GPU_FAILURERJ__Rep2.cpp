#include "Composed/GPU_FAILURE/GPU_FAILURERJ__Rep2.h"
char * GPU_FAILURERJ__Rep2__SharedNames[] = {"FAILURE_INST", "FLOAT_ALU_FAILURE", "INSTRUCTION_READY", "INT_ALU_FAILURE", "KO_CONTENT", "MEM_FAILURE", "OK_CONTENT", "REGISTERS_FILL", "REG_FAILURE", "RESULT_KO", "RESULT_OK", "SCHEDULER", "WARP_ACCESS_DRAM", "WARP_ACCESS_L1", "WARP_ACCESS_L2"};

GPU_FAILURERJ__Rep2::GPU_FAILURERJ__Rep2():Rep("Rep2", nfailedwarps, 15, GPU_FAILURERJ__Rep2__SharedNames)
{
  InstanceArray = new GPU_FAILURERJ__WARP_REG_FAILURE * [NumModels];
  delete[] ModelArray;
  ModelArray = (BaseModelClass **) InstanceArray;
  for (counter = 0; counter < NumModels; counter++)
    InstanceArray[counter] = new GPU_FAILURERJ__WARP_REG_FAILURE();

  SetupActions();
  if (NumModels == 0) return;

  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************** Initialize local variables ****************
    FAILURE_INST = new Place("FAILURE_INST");
    addSharedPtr(FAILURE_INST, "FAILURE_INST");
    FAILURE_INST->ShareWith(InstanceArray[0]->FAILURE_INST);

    FLOAT_ALU_FAILURE = new Place("FLOAT_ALU_FAILURE");
    addSharedPtr(FLOAT_ALU_FAILURE, "FLOAT_ALU_FAILURE");
    FLOAT_ALU_FAILURE->ShareWith(InstanceArray[0]->FLOAT_ALU_FAILURE);

    INSTRUCTION_READY = new Place("INSTRUCTION_READY");
    addSharedPtr(INSTRUCTION_READY, "INSTRUCTION_READY");
    INSTRUCTION_READY->ShareWith(InstanceArray[0]->INSTRUCTION_READY);

    INT_ALU_FAILURE = new Place("INT_ALU_FAILURE");
    addSharedPtr(INT_ALU_FAILURE, "INT_ALU_FAILURE");
    INT_ALU_FAILURE->ShareWith(InstanceArray[0]->INT_ALU_FAILURE);

    KO_CONTENT = new Place("KO_CONTENT");
    addSharedPtr(KO_CONTENT, "KO_CONTENT");
    KO_CONTENT->ShareWith(InstanceArray[0]->KO_CONTENT);

    MEM_FAILURE = new Place("MEM_FAILURE");
    addSharedPtr(MEM_FAILURE, "MEM_FAILURE");
    MEM_FAILURE->ShareWith(InstanceArray[0]->MEM_FAILURE);

    OK_CONTENT = new Place("OK_CONTENT");
    addSharedPtr(OK_CONTENT, "OK_CONTENT");
    OK_CONTENT->ShareWith(InstanceArray[0]->OK_CONTENT);

    REGISTERS_FILL = new Place("REGISTERS_FILL");
    addSharedPtr(REGISTERS_FILL, "REGISTERS_FILL");
    REGISTERS_FILL->ShareWith(InstanceArray[0]->REGISTERS_FILL);

    REG_FAILURE = new Place("REG_FAILURE");
    addSharedPtr(REG_FAILURE, "REG_FAILURE");
    REG_FAILURE->ShareWith(InstanceArray[0]->REG_FAILURE);

    RESULT_KO = new Place("RESULT_KO");
    addSharedPtr(RESULT_KO, "RESULT_KO");
    RESULT_KO->ShareWith(InstanceArray[0]->RESULT_KO);

    RESULT_OK = new Place("RESULT_OK");
    addSharedPtr(RESULT_OK, "RESULT_OK");
    RESULT_OK->ShareWith(InstanceArray[0]->RESULT_OK);

    SCHEDULER = new Place("SCHEDULER");
    addSharedPtr(SCHEDULER, "SCHEDULER");
    SCHEDULER->ShareWith(InstanceArray[0]->SCHEDULER);

    WARP_ACCESS_DRAM = new Place("WARP_ACCESS_DRAM");
    addSharedPtr(WARP_ACCESS_DRAM, "WARP_ACCESS_DRAM");
    WARP_ACCESS_DRAM->ShareWith(InstanceArray[0]->WARP_ACCESS_DRAM);

    WARP_ACCESS_L1 = new Place("WARP_ACCESS_L1");
    addSharedPtr(WARP_ACCESS_L1, "WARP_ACCESS_L1");
    WARP_ACCESS_L1->ShareWith(InstanceArray[0]->WARP_ACCESS_L1);

    WARP_ACCESS_L2 = new Place("WARP_ACCESS_L2");
    addSharedPtr(WARP_ACCESS_L2, "WARP_ACCESS_L2");
    WARP_ACCESS_L2->ShareWith(InstanceArray[0]->WARP_ACCESS_L2);


    //Share state in submodels
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->FAILURE_INST, FAILURE_INST);
    }
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
      addSharingInfo(InstanceArray[counter]->KO_CONTENT, KO_CONTENT);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->MEM_FAILURE, MEM_FAILURE);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->OK_CONTENT, OK_CONTENT);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->REGISTERS_FILL, REGISTERS_FILL);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->REG_FAILURE, REG_FAILURE);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->RESULT_KO, RESULT_KO);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->RESULT_OK, RESULT_OK);
    }
    for (counter = 0; counter < NumModels; counter++) {
      addSharingInfo(InstanceArray[counter]->SCHEDULER, SCHEDULER);
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
    for (counter = 1; counter < NumModels; counter++) {
      InstanceArray[0]->FAILURE_INST->ShareWith(InstanceArray[counter]->FAILURE_INST);
      InstanceArray[0]->FLOAT_ALU_FAILURE->ShareWith(InstanceArray[counter]->FLOAT_ALU_FAILURE);
      InstanceArray[0]->INSTRUCTION_READY->ShareWith(InstanceArray[counter]->INSTRUCTION_READY);
      InstanceArray[0]->INT_ALU_FAILURE->ShareWith(InstanceArray[counter]->INT_ALU_FAILURE);
      InstanceArray[0]->KO_CONTENT->ShareWith(InstanceArray[counter]->KO_CONTENT);
      InstanceArray[0]->MEM_FAILURE->ShareWith(InstanceArray[counter]->MEM_FAILURE);
      InstanceArray[0]->OK_CONTENT->ShareWith(InstanceArray[counter]->OK_CONTENT);
      InstanceArray[0]->REGISTERS_FILL->ShareWith(InstanceArray[counter]->REGISTERS_FILL);
      InstanceArray[0]->REG_FAILURE->ShareWith(InstanceArray[counter]->REG_FAILURE);
      InstanceArray[0]->RESULT_KO->ShareWith(InstanceArray[counter]->RESULT_KO);
      InstanceArray[0]->RESULT_OK->ShareWith(InstanceArray[counter]->RESULT_OK);
      InstanceArray[0]->SCHEDULER->ShareWith(InstanceArray[counter]->SCHEDULER);
      InstanceArray[0]->WARP_ACCESS_DRAM->ShareWith(InstanceArray[counter]->WARP_ACCESS_DRAM);
      InstanceArray[0]->WARP_ACCESS_L1->ShareWith(InstanceArray[counter]->WARP_ACCESS_L1);
      InstanceArray[0]->WARP_ACCESS_L2->ShareWith(InstanceArray[counter]->WARP_ACCESS_L2);
    }
  }
  Setup("WARP_REG_FAILURE");
}

GPU_FAILURERJ__Rep2::~GPU_FAILURERJ__Rep2() {
  if (NumModels == 0) return;
  delete FAILURE_INST;
  delete FLOAT_ALU_FAILURE;
  delete INSTRUCTION_READY;
  delete INT_ALU_FAILURE;
  delete KO_CONTENT;
  delete MEM_FAILURE;
  delete OK_CONTENT;
  delete REGISTERS_FILL;
  delete REG_FAILURE;
  delete RESULT_KO;
  delete RESULT_OK;
  delete SCHEDULER;
  delete WARP_ACCESS_DRAM;
  delete WARP_ACCESS_L1;
  delete WARP_ACCESS_L2;
  for (int i = 0; i < NumModels; i++)
    delete InstanceArray[i];
}

