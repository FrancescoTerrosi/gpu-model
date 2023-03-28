#include "Composed/GPU5/GPU5RJ__PROCESSOR.h"
char * GPU5RJ__PROCESSOR__SharedNames[] = {"FLOAT_ALU_FAILURE", "INSTRUCTION_READY", "INT_ALU_FAILURE", "KO_CONTENT", "MEM_FAILURE", "MEM_OP_COMPLETE", "OK_CONTENT", "READ", "READ_DRAM", "READ_L1", "READ_L2", "REGISTERS_FILL", "REG_FAILURE", "RESULT_KO", "RESULT_OK", "SCHEDULER", "WRITE", "WRITE_DRAM", "WRITE_L1", "WRITE_L2"};

GPU5RJ__PROCESSOR::GPU5RJ__PROCESSOR():Join("PROCESSOR", 4, 20,GPU5RJ__PROCESSOR__SharedNames) {
  Rep1 = new GPU5RJ__Rep1();
  ModelArray[0] = (BaseModelClass*) Rep1;
  ModelArray[0]->DefineName("Rep1");
  REGISTER_FILE = new REGISTER_FILESAN();
  ModelArray[1] = (BaseModelClass*) REGISTER_FILE;
  ModelArray[1]->DefineName("REGISTER_FILE");
  EXEC_UNIT = new EXEC_UNITSAN();
  ModelArray[2] = (BaseModelClass*) EXEC_UNIT;
  ModelArray[2]->DefineName("EXEC_UNIT");
  MEMORY = new MEMORYSAN();
  ModelArray[3] = (BaseModelClass*) MEMORY;
  ModelArray[3]->DefineName("MEMORY");

  SetupActions();
  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************  State sharing info  **************
    //Shared variable 0
    FLOAT_ALU_FAILURE = new Place("FLOAT_ALU_FAILURE");
    addSharedPtr(FLOAT_ALU_FAILURE, "FLOAT_ALU_FAILURE" );
    if (Rep1->NumStateVariables > 0) {
      FLOAT_ALU_FAILURE->ShareWith(getSharableSVPointer(Rep1->FLOAT_ALU_FAILURE));
      addSharingInfo(getSharableSVPointer(Rep1->FLOAT_ALU_FAILURE), FLOAT_ALU_FAILURE, Rep1);
    }
    if (EXEC_UNIT->NumStateVariables > 0) {
      FLOAT_ALU_FAILURE->ShareWith(getSharableSVPointer(EXEC_UNIT->FLOAT_ALU_FAILURE));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT->FLOAT_ALU_FAILURE), FLOAT_ALU_FAILURE, EXEC_UNIT);
    }

    //Shared variable 1
    INSTRUCTION_READY = new Place("INSTRUCTION_READY");
    addSharedPtr(INSTRUCTION_READY, "INSTRUCTION_READY" );
    if (Rep1->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(Rep1->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(Rep1->INSTRUCTION_READY), INSTRUCTION_READY, Rep1);
    }
    if (EXEC_UNIT->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(EXEC_UNIT->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT->INSTRUCTION_READY), INSTRUCTION_READY, EXEC_UNIT);
    }

    //Shared variable 2
    INT_ALU_FAILURE = new Place("INT_ALU_FAILURE");
    addSharedPtr(INT_ALU_FAILURE, "INT_ALU_FAILURE" );
    if (Rep1->NumStateVariables > 0) {
      INT_ALU_FAILURE->ShareWith(getSharableSVPointer(Rep1->INT_ALU_FAILURE));
      addSharingInfo(getSharableSVPointer(Rep1->INT_ALU_FAILURE), INT_ALU_FAILURE, Rep1);
    }
    if (EXEC_UNIT->NumStateVariables > 0) {
      INT_ALU_FAILURE->ShareWith(getSharableSVPointer(EXEC_UNIT->INT_ALU_FAILURE));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT->INT_ALU_FAILURE), INT_ALU_FAILURE, EXEC_UNIT);
    }

    //Shared variable 3
    KO_CONTENT = new Place("KO_CONTENT");
    addSharedPtr(KO_CONTENT, "KO_CONTENT" );
    if (REGISTER_FILE->NumStateVariables > 0) {
      KO_CONTENT->ShareWith(getSharableSVPointer(REGISTER_FILE->KO_CONTENT));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->KO_CONTENT), KO_CONTENT, REGISTER_FILE);
    }
    if (EXEC_UNIT->NumStateVariables > 0) {
      KO_CONTENT->ShareWith(getSharableSVPointer(EXEC_UNIT->KO_CONTENT));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT->KO_CONTENT), KO_CONTENT, EXEC_UNIT);
    }

    //Shared variable 4
    MEM_FAILURE = new Place("MEM_FAILURE");
    addSharedPtr(MEM_FAILURE, "MEM_FAILURE" );
    if (Rep1->NumStateVariables > 0) {
      MEM_FAILURE->ShareWith(getSharableSVPointer(Rep1->MEM_FAILURE));
      addSharingInfo(getSharableSVPointer(Rep1->MEM_FAILURE), MEM_FAILURE, Rep1);
    }

    //Shared variable 5
    MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE");
    addSharedPtr(MEM_OP_COMPLETE, "MEM_OP_COMPLETE" );
    if (EXEC_UNIT->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(EXEC_UNIT->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT->MEM_OP_COMPLETE), MEM_OP_COMPLETE, EXEC_UNIT);
    }

    //Shared variable 6
    OK_CONTENT = new Place("OK_CONTENT");
    addSharedPtr(OK_CONTENT, "OK_CONTENT" );
    if (REGISTER_FILE->NumStateVariables > 0) {
      OK_CONTENT->ShareWith(getSharableSVPointer(REGISTER_FILE->OK_CONTENT));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->OK_CONTENT), OK_CONTENT, REGISTER_FILE);
    }
    if (EXEC_UNIT->NumStateVariables > 0) {
      OK_CONTENT->ShareWith(getSharableSVPointer(EXEC_UNIT->OK_CONTENT));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT->OK_CONTENT), OK_CONTENT, EXEC_UNIT);
    }

    //Shared variable 7
    READ = new Place("READ");
    addSharedPtr(READ, "READ" );
    if (EXEC_UNIT->NumStateVariables > 0) {
      READ->ShareWith(getSharableSVPointer(EXEC_UNIT->READ));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT->READ), READ, EXEC_UNIT);
    }
    if (MEMORY->NumStateVariables > 0) {
      READ->ShareWith(getSharableSVPointer(MEMORY->READ));
      addSharingInfo(getSharableSVPointer(MEMORY->READ), READ, MEMORY);
    }

    //Shared variable 8
    READ_DRAM = new Place("READ_DRAM");
    addSharedPtr(READ_DRAM, "READ_DRAM" );
    if (MEMORY->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(MEMORY->READ_DRAM));
      addSharingInfo(getSharableSVPointer(MEMORY->READ_DRAM), READ_DRAM, MEMORY);
    }

    //Shared variable 9
    READ_L1 = new Place("READ_L1");
    addSharedPtr(READ_L1, "READ_L1" );
    if (MEMORY->NumStateVariables > 0) {
      READ_L1->ShareWith(getSharableSVPointer(MEMORY->READ_L1));
      addSharingInfo(getSharableSVPointer(MEMORY->READ_L1), READ_L1, MEMORY);
    }

    //Shared variable 10
    READ_L2 = new Place("READ_L2");
    addSharedPtr(READ_L2, "READ_L2" );
    if (MEMORY->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(MEMORY->READ_L2));
      addSharingInfo(getSharableSVPointer(MEMORY->READ_L2), READ_L2, MEMORY);
    }

    //Shared variable 11
    REGISTERS_FILL = new Place("REGISTERS_FILL");
    addSharedPtr(REGISTERS_FILL, "REGISTERS_FILL" );
    if (Rep1->NumStateVariables > 0) {
      REGISTERS_FILL->ShareWith(getSharableSVPointer(Rep1->REGISTERS_FILL));
      addSharingInfo(getSharableSVPointer(Rep1->REGISTERS_FILL), REGISTERS_FILL, Rep1);
    }
    if (REGISTER_FILE->NumStateVariables > 0) {
      REGISTERS_FILL->ShareWith(getSharableSVPointer(REGISTER_FILE->REGISTERS_FILL));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->REGISTERS_FILL), REGISTERS_FILL, REGISTER_FILE);
    }
    if (EXEC_UNIT->NumStateVariables > 0) {
      REGISTERS_FILL->ShareWith(getSharableSVPointer(EXEC_UNIT->REGISTERS_FILL));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT->REGISTERS_FILL), REGISTERS_FILL, EXEC_UNIT);
    }

    //Shared variable 12
    REG_FAILURE = new Place("REG_FAILURE");
    addSharedPtr(REG_FAILURE, "REG_FAILURE" );
    if (Rep1->NumStateVariables > 0) {
      REG_FAILURE->ShareWith(getSharableSVPointer(Rep1->REG_FAILURE));
      addSharingInfo(getSharableSVPointer(Rep1->REG_FAILURE), REG_FAILURE, Rep1);
    }
    if (REGISTER_FILE->NumStateVariables > 0) {
      REG_FAILURE->ShareWith(getSharableSVPointer(REGISTER_FILE->REG_FAILURE));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->REG_FAILURE), REG_FAILURE, REGISTER_FILE);
    }

    //Shared variable 13
    RESULT_KO = new Place("RESULT_KO");
    addSharedPtr(RESULT_KO, "RESULT_KO" );
    if (REGISTER_FILE->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(REGISTER_FILE->RESULT_KO));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->RESULT_KO), RESULT_KO, REGISTER_FILE);
    }
    if (EXEC_UNIT->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(EXEC_UNIT->RESULT_KO));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT->RESULT_KO), RESULT_KO, EXEC_UNIT);
    }

    //Shared variable 14
    RESULT_OK = new Place("RESULT_OK");
    addSharedPtr(RESULT_OK, "RESULT_OK" );
    if (REGISTER_FILE->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(REGISTER_FILE->RESULT_OK));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->RESULT_OK), RESULT_OK, REGISTER_FILE);
    }
    if (EXEC_UNIT->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(EXEC_UNIT->RESULT_OK));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT->RESULT_OK), RESULT_OK, EXEC_UNIT);
    }

    //Shared variable 15
    SCHEDULER = new Place("SCHEDULER");
    addSharedPtr(SCHEDULER, "SCHEDULER" );
    if (Rep1->NumStateVariables > 0) {
      SCHEDULER->ShareWith(getSharableSVPointer(Rep1->SCHEDULER));
      addSharingInfo(getSharableSVPointer(Rep1->SCHEDULER), SCHEDULER, Rep1);
    }
    if (EXEC_UNIT->NumStateVariables > 0) {
      SCHEDULER->ShareWith(getSharableSVPointer(EXEC_UNIT->SCHEDULER));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT->SCHEDULER), SCHEDULER, EXEC_UNIT);
    }

    //Shared variable 16
    WRITE = new Place("WRITE");
    addSharedPtr(WRITE, "WRITE" );
    if (EXEC_UNIT->NumStateVariables > 0) {
      WRITE->ShareWith(getSharableSVPointer(EXEC_UNIT->WRITE));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT->WRITE), WRITE, EXEC_UNIT);
    }
    if (MEMORY->NumStateVariables > 0) {
      WRITE->ShareWith(getSharableSVPointer(MEMORY->WRITE));
      addSharingInfo(getSharableSVPointer(MEMORY->WRITE), WRITE, MEMORY);
    }

    //Shared variable 17
    WRITE_DRAM = new Place("WRITE_DRAM");
    addSharedPtr(WRITE_DRAM, "WRITE_DRAM" );
    if (MEMORY->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(MEMORY->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(MEMORY->WRITE_DRAM), WRITE_DRAM, MEMORY);
    }

    //Shared variable 18
    WRITE_L1 = new Place("WRITE_L1");
    addSharedPtr(WRITE_L1, "WRITE_L1" );
    if (MEMORY->NumStateVariables > 0) {
      WRITE_L1->ShareWith(getSharableSVPointer(MEMORY->WRITE_L1));
      addSharingInfo(getSharableSVPointer(MEMORY->WRITE_L1), WRITE_L1, MEMORY);
    }

    //Shared variable 19
    WRITE_L2 = new Place("WRITE_L2");
    addSharedPtr(WRITE_L2, "WRITE_L2" );
    if (MEMORY->NumStateVariables > 0) {
      WRITE_L2->ShareWith(getSharableSVPointer(MEMORY->WRITE_L2));
      addSharingInfo(getSharableSVPointer(MEMORY->WRITE_L2), WRITE_L2, MEMORY);
    }

  }

  Setup();
}

GPU5RJ__PROCESSOR::~GPU5RJ__PROCESSOR() {
  if (!AllChildrenEmpty()) {
    delete FLOAT_ALU_FAILURE;
    delete INSTRUCTION_READY;
    delete INT_ALU_FAILURE;
    delete KO_CONTENT;
    delete MEM_FAILURE;
    delete MEM_OP_COMPLETE;
    delete OK_CONTENT;
    delete READ;
    delete READ_DRAM;
    delete READ_L1;
    delete READ_L2;
    delete REGISTERS_FILL;
    delete REG_FAILURE;
    delete RESULT_KO;
    delete RESULT_OK;
    delete SCHEDULER;
    delete WRITE;
    delete WRITE_DRAM;
    delete WRITE_L1;
    delete WRITE_L2;
  }
  delete Rep1;
  delete REGISTER_FILE;
  delete EXEC_UNIT;
  delete MEMORY;
}
