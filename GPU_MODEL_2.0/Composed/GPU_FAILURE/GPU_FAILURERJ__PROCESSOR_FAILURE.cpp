#include "Composed/GPU_FAILURE/GPU_FAILURERJ__PROCESSOR_FAILURE.h"
char * GPU_FAILURERJ__PROCESSOR_FAILURE__SharedNames[] = {"FLOAT_ALU_FAILURE", "INSTRUCTION_READY", "INT_ALU_FAILURE", "KO_CONTENT", "MEM_FAILURE", "OK_CONTENT", "READ", "READ_DRAM", "READ_L1", "READ_L2", "REGISTERS_FILL", "RESULT_KO", "RESULT_OK", "SCHEDULER", "WARP_ACCESS_DRAM", "WARP_ACCESS_L1", "WARP_ACCESS_L2", "WRITE", "WRITE_DRAM", "WRITE_L1", "WRITE_L2"};

GPU_FAILURERJ__PROCESSOR_FAILURE::GPU_FAILURERJ__PROCESSOR_FAILURE():Join("PROCESSOR_FAILURE", 3, 21,GPU_FAILURERJ__PROCESSOR_FAILURE__SharedNames) {
  Rep2 = new GPU_FAILURERJ__Rep2();
  ModelArray[0] = (BaseModelClass*) Rep2;
  ModelArray[0]->DefineName("Rep2");
  EXEC_UNIT_FAILURE = new EXEC_UNITSAN();
  ModelArray[1] = (BaseModelClass*) EXEC_UNIT_FAILURE;
  ModelArray[1]->DefineName("EXEC_UNIT_FAILURE");
  MEMORY_FAILURE = new MEMORYSAN();
  ModelArray[2] = (BaseModelClass*) MEMORY_FAILURE;
  ModelArray[2]->DefineName("MEMORY_FAILURE");

  SetupActions();
  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************  State sharing info  **************
    //Shared variable 0
    FLOAT_ALU_FAILURE = new Place("FLOAT_ALU_FAILURE");
    addSharedPtr(FLOAT_ALU_FAILURE, "FLOAT_ALU_FAILURE" );
    if (EXEC_UNIT_FAILURE->NumStateVariables > 0) {
      FLOAT_ALU_FAILURE->ShareWith(getSharableSVPointer(EXEC_UNIT_FAILURE->FLOAT_ALU_FAILURE));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT_FAILURE->FLOAT_ALU_FAILURE), FLOAT_ALU_FAILURE, EXEC_UNIT_FAILURE);
    }
    if (Rep2->NumStateVariables > 0) {
      FLOAT_ALU_FAILURE->ShareWith(getSharableSVPointer(Rep2->FLOAT_ALU_FAILURE));
      addSharingInfo(getSharableSVPointer(Rep2->FLOAT_ALU_FAILURE), FLOAT_ALU_FAILURE, Rep2);
    }

    //Shared variable 1
    INSTRUCTION_READY = new Place("INSTRUCTION_READY");
    addSharedPtr(INSTRUCTION_READY, "INSTRUCTION_READY" );
    if (EXEC_UNIT_FAILURE->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(EXEC_UNIT_FAILURE->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT_FAILURE->INSTRUCTION_READY), INSTRUCTION_READY, EXEC_UNIT_FAILURE);
    }
    if (Rep2->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(Rep2->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(Rep2->INSTRUCTION_READY), INSTRUCTION_READY, Rep2);
    }

    //Shared variable 2
    INT_ALU_FAILURE = new Place("INT_ALU_FAILURE");
    addSharedPtr(INT_ALU_FAILURE, "INT_ALU_FAILURE" );
    if (EXEC_UNIT_FAILURE->NumStateVariables > 0) {
      INT_ALU_FAILURE->ShareWith(getSharableSVPointer(EXEC_UNIT_FAILURE->INT_ALU_FAILURE));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT_FAILURE->INT_ALU_FAILURE), INT_ALU_FAILURE, EXEC_UNIT_FAILURE);
    }
    if (Rep2->NumStateVariables > 0) {
      INT_ALU_FAILURE->ShareWith(getSharableSVPointer(Rep2->INT_ALU_FAILURE));
      addSharingInfo(getSharableSVPointer(Rep2->INT_ALU_FAILURE), INT_ALU_FAILURE, Rep2);
    }

    //Shared variable 3
    KO_CONTENT = new Place("KO_CONTENT");
    addSharedPtr(KO_CONTENT, "KO_CONTENT" );
    if (EXEC_UNIT_FAILURE->NumStateVariables > 0) {
      KO_CONTENT->ShareWith(getSharableSVPointer(EXEC_UNIT_FAILURE->KO_CONTENT));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT_FAILURE->KO_CONTENT), KO_CONTENT, EXEC_UNIT_FAILURE);
    }
    if (Rep2->NumStateVariables > 0) {
      KO_CONTENT->ShareWith(getSharableSVPointer(Rep2->KO_CONTENT));
      addSharingInfo(getSharableSVPointer(Rep2->KO_CONTENT), KO_CONTENT, Rep2);
    }

    //Shared variable 4
    MEM_FAILURE = new Place("MEM_FAILURE");
    addSharedPtr(MEM_FAILURE, "MEM_FAILURE" );
    if (Rep2->NumStateVariables > 0) {
      MEM_FAILURE->ShareWith(getSharableSVPointer(Rep2->MEM_FAILURE));
      addSharingInfo(getSharableSVPointer(Rep2->MEM_FAILURE), MEM_FAILURE, Rep2);
    }

    //Shared variable 5
    OK_CONTENT = new Place("OK_CONTENT");
    addSharedPtr(OK_CONTENT, "OK_CONTENT" );
    if (EXEC_UNIT_FAILURE->NumStateVariables > 0) {
      OK_CONTENT->ShareWith(getSharableSVPointer(EXEC_UNIT_FAILURE->OK_CONTENT));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT_FAILURE->OK_CONTENT), OK_CONTENT, EXEC_UNIT_FAILURE);
    }
    if (Rep2->NumStateVariables > 0) {
      OK_CONTENT->ShareWith(getSharableSVPointer(Rep2->OK_CONTENT));
      addSharingInfo(getSharableSVPointer(Rep2->OK_CONTENT), OK_CONTENT, Rep2);
    }

    //Shared variable 6
    READ = new Place("READ");
    addSharedPtr(READ, "READ" );
    if (EXEC_UNIT_FAILURE->NumStateVariables > 0) {
      READ->ShareWith(getSharableSVPointer(EXEC_UNIT_FAILURE->READ));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT_FAILURE->READ), READ, EXEC_UNIT_FAILURE);
    }
    if (MEMORY_FAILURE->NumStateVariables > 0) {
      READ->ShareWith(getSharableSVPointer(MEMORY_FAILURE->READ));
      addSharingInfo(getSharableSVPointer(MEMORY_FAILURE->READ), READ, MEMORY_FAILURE);
    }

    //Shared variable 7
    READ_DRAM = new Place("READ_DRAM");
    addSharedPtr(READ_DRAM, "READ_DRAM" );
    if (MEMORY_FAILURE->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(MEMORY_FAILURE->READ_DRAM));
      addSharingInfo(getSharableSVPointer(MEMORY_FAILURE->READ_DRAM), READ_DRAM, MEMORY_FAILURE);
    }

    //Shared variable 8
    READ_L1 = new Place("READ_L1");
    addSharedPtr(READ_L1, "READ_L1" );
    if (MEMORY_FAILURE->NumStateVariables > 0) {
      READ_L1->ShareWith(getSharableSVPointer(MEMORY_FAILURE->READ_L1));
      addSharingInfo(getSharableSVPointer(MEMORY_FAILURE->READ_L1), READ_L1, MEMORY_FAILURE);
    }

    //Shared variable 9
    READ_L2 = new Place("READ_L2");
    addSharedPtr(READ_L2, "READ_L2" );
    if (MEMORY_FAILURE->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(MEMORY_FAILURE->READ_L2));
      addSharingInfo(getSharableSVPointer(MEMORY_FAILURE->READ_L2), READ_L2, MEMORY_FAILURE);
    }

    //Shared variable 10
    REGISTERS_FILL = new Place("REGISTERS_FILL");
    addSharedPtr(REGISTERS_FILL, "REGISTERS_FILL" );
    if (EXEC_UNIT_FAILURE->NumStateVariables > 0) {
      REGISTERS_FILL->ShareWith(getSharableSVPointer(EXEC_UNIT_FAILURE->REGISTERS_FILL));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT_FAILURE->REGISTERS_FILL), REGISTERS_FILL, EXEC_UNIT_FAILURE);
    }
    if (Rep2->NumStateVariables > 0) {
      REGISTERS_FILL->ShareWith(getSharableSVPointer(Rep2->REGISTERS_FILL));
      addSharingInfo(getSharableSVPointer(Rep2->REGISTERS_FILL), REGISTERS_FILL, Rep2);
    }

    //Shared variable 11
    RESULT_KO = new Place("RESULT_KO");
    addSharedPtr(RESULT_KO, "RESULT_KO" );
    if (EXEC_UNIT_FAILURE->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(EXEC_UNIT_FAILURE->RESULT_KO));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT_FAILURE->RESULT_KO), RESULT_KO, EXEC_UNIT_FAILURE);
    }
    if (Rep2->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(Rep2->RESULT_KO));
      addSharingInfo(getSharableSVPointer(Rep2->RESULT_KO), RESULT_KO, Rep2);
    }

    //Shared variable 12
    RESULT_OK = new Place("RESULT_OK");
    addSharedPtr(RESULT_OK, "RESULT_OK" );
    if (EXEC_UNIT_FAILURE->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(EXEC_UNIT_FAILURE->RESULT_OK));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT_FAILURE->RESULT_OK), RESULT_OK, EXEC_UNIT_FAILURE);
    }
    if (Rep2->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(Rep2->RESULT_OK));
      addSharingInfo(getSharableSVPointer(Rep2->RESULT_OK), RESULT_OK, Rep2);
    }

    //Shared variable 13
    SCHEDULER = new Place("SCHEDULER");
    addSharedPtr(SCHEDULER, "SCHEDULER" );
    if (EXEC_UNIT_FAILURE->NumStateVariables > 0) {
      SCHEDULER->ShareWith(getSharableSVPointer(EXEC_UNIT_FAILURE->SCHEDULER));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT_FAILURE->SCHEDULER), SCHEDULER, EXEC_UNIT_FAILURE);
    }
    if (Rep2->NumStateVariables > 0) {
      SCHEDULER->ShareWith(getSharableSVPointer(Rep2->SCHEDULER));
      addSharingInfo(getSharableSVPointer(Rep2->SCHEDULER), SCHEDULER, Rep2);
    }

    //Shared variable 14
    WARP_ACCESS_DRAM = new Place("WARP_ACCESS_DRAM");
    addSharedPtr(WARP_ACCESS_DRAM, "WARP_ACCESS_DRAM" );
    if (Rep2->NumStateVariables > 0) {
      WARP_ACCESS_DRAM->ShareWith(getSharableSVPointer(Rep2->WARP_ACCESS_DRAM));
      addSharingInfo(getSharableSVPointer(Rep2->WARP_ACCESS_DRAM), WARP_ACCESS_DRAM, Rep2);
    }

    //Shared variable 15
    WARP_ACCESS_L1 = new Place("WARP_ACCESS_L1");
    addSharedPtr(WARP_ACCESS_L1, "WARP_ACCESS_L1" );
    if (Rep2->NumStateVariables > 0) {
      WARP_ACCESS_L1->ShareWith(getSharableSVPointer(Rep2->WARP_ACCESS_L1));
      addSharingInfo(getSharableSVPointer(Rep2->WARP_ACCESS_L1), WARP_ACCESS_L1, Rep2);
    }

    //Shared variable 16
    WARP_ACCESS_L2 = new Place("WARP_ACCESS_L2");
    addSharedPtr(WARP_ACCESS_L2, "WARP_ACCESS_L2" );
    if (Rep2->NumStateVariables > 0) {
      WARP_ACCESS_L2->ShareWith(getSharableSVPointer(Rep2->WARP_ACCESS_L2));
      addSharingInfo(getSharableSVPointer(Rep2->WARP_ACCESS_L2), WARP_ACCESS_L2, Rep2);
    }

    //Shared variable 17
    WRITE = new Place("WRITE");
    addSharedPtr(WRITE, "WRITE" );
    if (EXEC_UNIT_FAILURE->NumStateVariables > 0) {
      WRITE->ShareWith(getSharableSVPointer(EXEC_UNIT_FAILURE->WRITE));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT_FAILURE->WRITE), WRITE, EXEC_UNIT_FAILURE);
    }
    if (MEMORY_FAILURE->NumStateVariables > 0) {
      WRITE->ShareWith(getSharableSVPointer(MEMORY_FAILURE->WRITE));
      addSharingInfo(getSharableSVPointer(MEMORY_FAILURE->WRITE), WRITE, MEMORY_FAILURE);
    }

    //Shared variable 18
    WRITE_DRAM = new Place("WRITE_DRAM");
    addSharedPtr(WRITE_DRAM, "WRITE_DRAM" );
    if (MEMORY_FAILURE->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(MEMORY_FAILURE->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(MEMORY_FAILURE->WRITE_DRAM), WRITE_DRAM, MEMORY_FAILURE);
    }

    //Shared variable 19
    WRITE_L1 = new Place("WRITE_L1");
    addSharedPtr(WRITE_L1, "WRITE_L1" );
    if (MEMORY_FAILURE->NumStateVariables > 0) {
      WRITE_L1->ShareWith(getSharableSVPointer(MEMORY_FAILURE->WRITE_L1));
      addSharingInfo(getSharableSVPointer(MEMORY_FAILURE->WRITE_L1), WRITE_L1, MEMORY_FAILURE);
    }

    //Shared variable 20
    WRITE_L2 = new Place("WRITE_L2");
    addSharedPtr(WRITE_L2, "WRITE_L2" );
    if (MEMORY_FAILURE->NumStateVariables > 0) {
      WRITE_L2->ShareWith(getSharableSVPointer(MEMORY_FAILURE->WRITE_L2));
      addSharingInfo(getSharableSVPointer(MEMORY_FAILURE->WRITE_L2), WRITE_L2, MEMORY_FAILURE);
    }

  }

  Setup();
}

GPU_FAILURERJ__PROCESSOR_FAILURE::~GPU_FAILURERJ__PROCESSOR_FAILURE() {
  if (!AllChildrenEmpty()) {
    delete FLOAT_ALU_FAILURE;
    delete INSTRUCTION_READY;
    delete INT_ALU_FAILURE;
    delete KO_CONTENT;
    delete MEM_FAILURE;
    delete OK_CONTENT;
    delete READ;
    delete READ_DRAM;
    delete READ_L1;
    delete READ_L2;
    delete REGISTERS_FILL;
    delete RESULT_KO;
    delete RESULT_OK;
    delete SCHEDULER;
    delete WARP_ACCESS_DRAM;
    delete WARP_ACCESS_L1;
    delete WARP_ACCESS_L2;
    delete WRITE;
    delete WRITE_DRAM;
    delete WRITE_L1;
    delete WRITE_L2;
  }
  delete Rep2;
  delete EXEC_UNIT_FAILURE;
  delete MEMORY_FAILURE;
}
