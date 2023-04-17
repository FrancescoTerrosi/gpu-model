#include "Composed/GPU5/GPU5RJ__WARP_REG.h"
char * GPU5RJ__WARP_REG__SharedNames[] = {"FLOAT_ALU_FAILURE", "INSTRUCTION_READY", "INST_COUNTER", "INT_ALU_FAILURE", "KO_CONTENT", "MEM_FAILURE", "OK_CONTENT", "REGISTERS_FILL", "REG_FAILURE", "RESULT_KO", "RESULT_OK", "SCHEDULER", "WARP_ACCESS_DRAM", "WARP_ACCESS_L1", "WARP_ACCESS_L2"};

GPU5RJ__WARP_REG::GPU5RJ__WARP_REG():Join("WARP_REG", 2, 15,GPU5RJ__WARP_REG__SharedNames) {
  REGISTER_FILE = new REGISTER_FILESAN();
  ModelArray[0] = (BaseModelClass*) REGISTER_FILE;
  ModelArray[0]->DefineName("REGISTER_FILE");
  WARP = new WARPSAN();
  ModelArray[1] = (BaseModelClass*) WARP;
  ModelArray[1]->DefineName("WARP");

  SetupActions();
  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************  State sharing info  **************
    //Shared variable 0
    FLOAT_ALU_FAILURE = new Place("FLOAT_ALU_FAILURE");
    addSharedPtr(FLOAT_ALU_FAILURE, "FLOAT_ALU_FAILURE" );
    if (WARP->NumStateVariables > 0) {
      FLOAT_ALU_FAILURE->ShareWith(getSharableSVPointer(WARP->FLOAT_ALU_FAILURE));
      addSharingInfo(getSharableSVPointer(WARP->FLOAT_ALU_FAILURE), FLOAT_ALU_FAILURE, WARP);
    }

    //Shared variable 1
    INSTRUCTION_READY = new Place("INSTRUCTION_READY");
    addSharedPtr(INSTRUCTION_READY, "INSTRUCTION_READY" );
    if (WARP->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(WARP->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(WARP->INSTRUCTION_READY), INSTRUCTION_READY, WARP);
    }

    //Shared variable 2
    INST_COUNTER = new Place("INST_COUNTER");
    addSharedPtr(INST_COUNTER, "INST_COUNTER" );
    if (WARP->NumStateVariables > 0) {
      INST_COUNTER->ShareWith(getSharableSVPointer(WARP->INST_COUNTER));
      addSharingInfo(getSharableSVPointer(WARP->INST_COUNTER), INST_COUNTER, WARP);
    }

    //Shared variable 3
    INT_ALU_FAILURE = new Place("INT_ALU_FAILURE");
    addSharedPtr(INT_ALU_FAILURE, "INT_ALU_FAILURE" );
    if (WARP->NumStateVariables > 0) {
      INT_ALU_FAILURE->ShareWith(getSharableSVPointer(WARP->INT_ALU_FAILURE));
      addSharingInfo(getSharableSVPointer(WARP->INT_ALU_FAILURE), INT_ALU_FAILURE, WARP);
    }

    //Shared variable 4
    KO_CONTENT = new Place("KO_CONTENT");
    addSharedPtr(KO_CONTENT, "KO_CONTENT" );
    if (REGISTER_FILE->NumStateVariables > 0) {
      KO_CONTENT->ShareWith(getSharableSVPointer(REGISTER_FILE->KO_CONTENT));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->KO_CONTENT), KO_CONTENT, REGISTER_FILE);
    }

    //Shared variable 5
    MEM_FAILURE = new Place("MEM_FAILURE");
    addSharedPtr(MEM_FAILURE, "MEM_FAILURE" );
    if (WARP->NumStateVariables > 0) {
      MEM_FAILURE->ShareWith(getSharableSVPointer(WARP->MEM_FAILURE));
      addSharingInfo(getSharableSVPointer(WARP->MEM_FAILURE), MEM_FAILURE, WARP);
    }

    //Shared variable 6
    OK_CONTENT = new Place("OK_CONTENT");
    addSharedPtr(OK_CONTENT, "OK_CONTENT" );
    if (REGISTER_FILE->NumStateVariables > 0) {
      OK_CONTENT->ShareWith(getSharableSVPointer(REGISTER_FILE->OK_CONTENT));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->OK_CONTENT), OK_CONTENT, REGISTER_FILE);
    }

    //Shared variable 7
    REGISTERS_FILL = new Place("REGISTERS_FILL");
    addSharedPtr(REGISTERS_FILL, "REGISTERS_FILL" );
    if (REGISTER_FILE->NumStateVariables > 0) {
      REGISTERS_FILL->ShareWith(getSharableSVPointer(REGISTER_FILE->REGISTERS_FILL));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->REGISTERS_FILL), REGISTERS_FILL, REGISTER_FILE);
    }
    if (WARP->NumStateVariables > 0) {
      REGISTERS_FILL->ShareWith(getSharableSVPointer(WARP->REGISTERS_FILL));
      addSharingInfo(getSharableSVPointer(WARP->REGISTERS_FILL), REGISTERS_FILL, WARP);
    }

    //Shared variable 8
    REG_FAILURE = new Place("REG_FAILURE");
    addSharedPtr(REG_FAILURE, "REG_FAILURE" );
    if (WARP->NumStateVariables > 0) {
      REG_FAILURE->ShareWith(getSharableSVPointer(WARP->REG_FAILURE));
      addSharingInfo(getSharableSVPointer(WARP->REG_FAILURE), REG_FAILURE, WARP);
    }

    //Shared variable 9
    RESULT_KO = new Place("RESULT_KO");
    addSharedPtr(RESULT_KO, "RESULT_KO" );
    if (REGISTER_FILE->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(REGISTER_FILE->RESULT_KO));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->RESULT_KO), RESULT_KO, REGISTER_FILE);
    }

    //Shared variable 10
    RESULT_OK = new Place("RESULT_OK");
    addSharedPtr(RESULT_OK, "RESULT_OK" );
    if (REGISTER_FILE->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(REGISTER_FILE->RESULT_OK));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->RESULT_OK), RESULT_OK, REGISTER_FILE);
    }

    //Shared variable 11
    SCHEDULER = new Place("SCHEDULER");
    addSharedPtr(SCHEDULER, "SCHEDULER" );
    if (WARP->NumStateVariables > 0) {
      SCHEDULER->ShareWith(getSharableSVPointer(WARP->SCHEDULER));
      addSharingInfo(getSharableSVPointer(WARP->SCHEDULER), SCHEDULER, WARP);
    }

    //Shared variable 12
    WARP_ACCESS_DRAM = new Place("WARP_ACCESS_DRAM");
    addSharedPtr(WARP_ACCESS_DRAM, "WARP_ACCESS_DRAM" );
    if (WARP->NumStateVariables > 0) {
      WARP_ACCESS_DRAM->ShareWith(getSharableSVPointer(WARP->WARP_ACCESS_DRAM));
      addSharingInfo(getSharableSVPointer(WARP->WARP_ACCESS_DRAM), WARP_ACCESS_DRAM, WARP);
    }

    //Shared variable 13
    WARP_ACCESS_L1 = new Place("WARP_ACCESS_L1");
    addSharedPtr(WARP_ACCESS_L1, "WARP_ACCESS_L1" );
    if (WARP->NumStateVariables > 0) {
      WARP_ACCESS_L1->ShareWith(getSharableSVPointer(WARP->WARP_ACCESS_L1));
      addSharingInfo(getSharableSVPointer(WARP->WARP_ACCESS_L1), WARP_ACCESS_L1, WARP);
    }

    //Shared variable 14
    WARP_ACCESS_L2 = new Place("WARP_ACCESS_L2");
    addSharedPtr(WARP_ACCESS_L2, "WARP_ACCESS_L2" );
    if (WARP->NumStateVariables > 0) {
      WARP_ACCESS_L2->ShareWith(getSharableSVPointer(WARP->WARP_ACCESS_L2));
      addSharingInfo(getSharableSVPointer(WARP->WARP_ACCESS_L2), WARP_ACCESS_L2, WARP);
    }

  }

  Setup();
}

GPU5RJ__WARP_REG::~GPU5RJ__WARP_REG() {
  if (!AllChildrenEmpty()) {
    delete FLOAT_ALU_FAILURE;
    delete INSTRUCTION_READY;
    delete INST_COUNTER;
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
  delete REGISTER_FILE;
  delete WARP;
}
