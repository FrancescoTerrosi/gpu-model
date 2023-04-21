#include "Composed/GPU_FAILURE/GPU_FAILURERJ__WARP_REG_FAILURE.h"
char * GPU_FAILURERJ__WARP_REG_FAILURE__SharedNames[] = {"FAILURE_INST", "FLOAT_ALU_FAILURE", "INSTRUCTION_READY", "INT_ALU_FAILURE", "KO_CONTENT", "MEM_FAILURE", "OK_CONTENT", "REGISTERS_FILL", "REG_FAILURE", "RESULT_KO", "RESULT_OK", "SCHEDULER", "WARP_ACCESS_DRAM", "WARP_ACCESS_L1", "WARP_ACCESS_L2"};

GPU_FAILURERJ__WARP_REG_FAILURE::GPU_FAILURERJ__WARP_REG_FAILURE():Join("WARP_REG_FAILURE", 2, 15,GPU_FAILURERJ__WARP_REG_FAILURE__SharedNames) {
  WARP_FAILURE = new WARPSAN();
  ModelArray[0] = (BaseModelClass*) WARP_FAILURE;
  ModelArray[0]->DefineName("WARP_FAILURE");
  REGISTER_FILE_FAILURE = new REGISTER_FILESAN();
  ModelArray[1] = (BaseModelClass*) REGISTER_FILE_FAILURE;
  ModelArray[1]->DefineName("REGISTER_FILE_FAILURE");

  SetupActions();
  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************  State sharing info  **************
    //Shared variable 0
    FAILURE_INST = new Place("FAILURE_INST");
    addSharedPtr(FAILURE_INST, "FAILURE_INST" );
    if (WARP_FAILURE->NumStateVariables > 0) {
      FAILURE_INST->ShareWith(getSharableSVPointer(WARP_FAILURE->FAILURE_INST));
      addSharingInfo(getSharableSVPointer(WARP_FAILURE->FAILURE_INST), FAILURE_INST, WARP_FAILURE);
    }

    //Shared variable 1
    FLOAT_ALU_FAILURE = new Place("FLOAT_ALU_FAILURE");
    addSharedPtr(FLOAT_ALU_FAILURE, "FLOAT_ALU_FAILURE" );
    if (WARP_FAILURE->NumStateVariables > 0) {
      FLOAT_ALU_FAILURE->ShareWith(getSharableSVPointer(WARP_FAILURE->FLOAT_ALU_FAILURE));
      addSharingInfo(getSharableSVPointer(WARP_FAILURE->FLOAT_ALU_FAILURE), FLOAT_ALU_FAILURE, WARP_FAILURE);
    }

    //Shared variable 2
    INSTRUCTION_READY = new Place("INSTRUCTION_READY");
    addSharedPtr(INSTRUCTION_READY, "INSTRUCTION_READY" );
    if (WARP_FAILURE->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(WARP_FAILURE->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(WARP_FAILURE->INSTRUCTION_READY), INSTRUCTION_READY, WARP_FAILURE);
    }

    //Shared variable 3
    INT_ALU_FAILURE = new Place("INT_ALU_FAILURE");
    addSharedPtr(INT_ALU_FAILURE, "INT_ALU_FAILURE" );
    if (WARP_FAILURE->NumStateVariables > 0) {
      INT_ALU_FAILURE->ShareWith(getSharableSVPointer(WARP_FAILURE->INT_ALU_FAILURE));
      addSharingInfo(getSharableSVPointer(WARP_FAILURE->INT_ALU_FAILURE), INT_ALU_FAILURE, WARP_FAILURE);
    }

    //Shared variable 4
    KO_CONTENT = new Place("KO_CONTENT");
    addSharedPtr(KO_CONTENT, "KO_CONTENT" );
    if (REGISTER_FILE_FAILURE->NumStateVariables > 0) {
      KO_CONTENT->ShareWith(getSharableSVPointer(REGISTER_FILE_FAILURE->KO_CONTENT));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE_FAILURE->KO_CONTENT), KO_CONTENT, REGISTER_FILE_FAILURE);
    }

    //Shared variable 5
    MEM_FAILURE = new Place("MEM_FAILURE");
    addSharedPtr(MEM_FAILURE, "MEM_FAILURE" );
    if (WARP_FAILURE->NumStateVariables > 0) {
      MEM_FAILURE->ShareWith(getSharableSVPointer(WARP_FAILURE->MEM_FAILURE));
      addSharingInfo(getSharableSVPointer(WARP_FAILURE->MEM_FAILURE), MEM_FAILURE, WARP_FAILURE);
    }

    //Shared variable 6
    OK_CONTENT = new Place("OK_CONTENT");
    addSharedPtr(OK_CONTENT, "OK_CONTENT" );
    if (REGISTER_FILE_FAILURE->NumStateVariables > 0) {
      OK_CONTENT->ShareWith(getSharableSVPointer(REGISTER_FILE_FAILURE->OK_CONTENT));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE_FAILURE->OK_CONTENT), OK_CONTENT, REGISTER_FILE_FAILURE);
    }

    //Shared variable 7
    REGISTERS_FILL = new Place("REGISTERS_FILL");
    addSharedPtr(REGISTERS_FILL, "REGISTERS_FILL" );
    if (WARP_FAILURE->NumStateVariables > 0) {
      REGISTERS_FILL->ShareWith(getSharableSVPointer(WARP_FAILURE->REGISTERS_FILL));
      addSharingInfo(getSharableSVPointer(WARP_FAILURE->REGISTERS_FILL), REGISTERS_FILL, WARP_FAILURE);
    }
    if (REGISTER_FILE_FAILURE->NumStateVariables > 0) {
      REGISTERS_FILL->ShareWith(getSharableSVPointer(REGISTER_FILE_FAILURE->REGISTERS_FILL));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE_FAILURE->REGISTERS_FILL), REGISTERS_FILL, REGISTER_FILE_FAILURE);
    }

    //Shared variable 8
    REG_FAILURE = new Place("REG_FAILURE");
    addSharedPtr(REG_FAILURE, "REG_FAILURE" );
    if (WARP_FAILURE->NumStateVariables > 0) {
      REG_FAILURE->ShareWith(getSharableSVPointer(WARP_FAILURE->REG_FAILURE));
      addSharingInfo(getSharableSVPointer(WARP_FAILURE->REG_FAILURE), REG_FAILURE, WARP_FAILURE);
    }
    if (REGISTER_FILE_FAILURE->NumStateVariables > 0) {
      REG_FAILURE->ShareWith(getSharableSVPointer(REGISTER_FILE_FAILURE->REG_FAILURE));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE_FAILURE->REG_FAILURE), REG_FAILURE, REGISTER_FILE_FAILURE);
    }

    //Shared variable 9
    RESULT_KO = new Place("RESULT_KO");
    addSharedPtr(RESULT_KO, "RESULT_KO" );
    if (REGISTER_FILE_FAILURE->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(REGISTER_FILE_FAILURE->RESULT_KO));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE_FAILURE->RESULT_KO), RESULT_KO, REGISTER_FILE_FAILURE);
    }

    //Shared variable 10
    RESULT_OK = new Place("RESULT_OK");
    addSharedPtr(RESULT_OK, "RESULT_OK" );
    if (REGISTER_FILE_FAILURE->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(REGISTER_FILE_FAILURE->RESULT_OK));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE_FAILURE->RESULT_OK), RESULT_OK, REGISTER_FILE_FAILURE);
    }

    //Shared variable 11
    SCHEDULER = new Place("SCHEDULER");
    addSharedPtr(SCHEDULER, "SCHEDULER" );
    if (WARP_FAILURE->NumStateVariables > 0) {
      SCHEDULER->ShareWith(getSharableSVPointer(WARP_FAILURE->SCHEDULER));
      addSharingInfo(getSharableSVPointer(WARP_FAILURE->SCHEDULER), SCHEDULER, WARP_FAILURE);
    }

    //Shared variable 12
    WARP_ACCESS_DRAM = new Place("WARP_ACCESS_DRAM");
    addSharedPtr(WARP_ACCESS_DRAM, "WARP_ACCESS_DRAM" );
    if (WARP_FAILURE->NumStateVariables > 0) {
      WARP_ACCESS_DRAM->ShareWith(getSharableSVPointer(WARP_FAILURE->WARP_ACCESS_DRAM));
      addSharingInfo(getSharableSVPointer(WARP_FAILURE->WARP_ACCESS_DRAM), WARP_ACCESS_DRAM, WARP_FAILURE);
    }

    //Shared variable 13
    WARP_ACCESS_L1 = new Place("WARP_ACCESS_L1");
    addSharedPtr(WARP_ACCESS_L1, "WARP_ACCESS_L1" );
    if (WARP_FAILURE->NumStateVariables > 0) {
      WARP_ACCESS_L1->ShareWith(getSharableSVPointer(WARP_FAILURE->WARP_ACCESS_L1));
      addSharingInfo(getSharableSVPointer(WARP_FAILURE->WARP_ACCESS_L1), WARP_ACCESS_L1, WARP_FAILURE);
    }

    //Shared variable 14
    WARP_ACCESS_L2 = new Place("WARP_ACCESS_L2");
    addSharedPtr(WARP_ACCESS_L2, "WARP_ACCESS_L2" );
    if (WARP_FAILURE->NumStateVariables > 0) {
      WARP_ACCESS_L2->ShareWith(getSharableSVPointer(WARP_FAILURE->WARP_ACCESS_L2));
      addSharingInfo(getSharableSVPointer(WARP_FAILURE->WARP_ACCESS_L2), WARP_ACCESS_L2, WARP_FAILURE);
    }

  }

  Setup();
}

GPU_FAILURERJ__WARP_REG_FAILURE::~GPU_FAILURERJ__WARP_REG_FAILURE() {
  if (!AllChildrenEmpty()) {
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
  }
  delete WARP_FAILURE;
  delete REGISTER_FILE_FAILURE;
}
