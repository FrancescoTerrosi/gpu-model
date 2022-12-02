#include "Composed/GPU4.BKP/GPU4.BKPRJ__PROCESSOR.h"
char * GPU4.BKPRJ__PROCESSOR__SharedNames[] = {"INSTRUCTION_READY", "KO_READ", "MEM_OP_COMPLETE", "OK_READ", "READ_DRAM", "READ_GLOBAL_MEMORY", "READ_L1", "READ_L2", "READ_LOCAL_MEMORY", "READ_REGISTER_FILE", "RESULT_KO", "RESULT_OK", "SCHEDULER", "WRITE_DRAM", "WRITE_GLOBAL_MEMORY", "WRITE_L1", "WRITE_L2", "WRITE_LOCAL_MEMORY", "WRITE_OUTPUT_MEMORY", "WRITE_REGISTER_FILE"};

GPU4.BKPRJ__PROCESSOR::GPU4.BKPRJ__PROCESSOR():Join("PROCESSOR", 6, 20,GPU4.BKPRJ__PROCESSOR__SharedNames) {
  Rep1 = new GPU4.BKPRJ__Rep1();
  ModelArray[0] = (BaseModelClass*) Rep1;
  ModelArray[0]->DefineName("Rep1");
  COMPUTE_UNIT = new COMPUTE_UNITSAN();
  ModelArray[1] = (BaseModelClass*) COMPUTE_UNIT;
  ModelArray[1]->DefineName("COMPUTE_UNIT");
  LOCAL_MEMORY = new LOCAL_MEMORYSAN();
  ModelArray[2] = (BaseModelClass*) LOCAL_MEMORY;
  ModelArray[2]->DefineName("LOCAL_MEMORY");
  GLOBAL_MEMORY = new GLOBAL_MEMORYSAN();
  ModelArray[3] = (BaseModelClass*) GLOBAL_MEMORY;
  ModelArray[3]->DefineName("GLOBAL_MEMORY");
  REGISTER_FILE = new REGISTER_FILESAN();
  ModelArray[4] = (BaseModelClass*) REGISTER_FILE;
  ModelArray[4]->DefineName("REGISTER_FILE");
  OUTPUT_MEMORY = new OUTPUT_MEMORYSAN();
  ModelArray[5] = (BaseModelClass*) OUTPUT_MEMORY;
  ModelArray[5]->DefineName("OUTPUT_MEMORY");

  SetupActions();
  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************  State sharing info  **************
    //Shared variable 0
    INSTRUCTION_READY = new Place("INSTRUCTION_READY");
    addSharedPtr(INSTRUCTION_READY, "INSTRUCTION_READY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->INSTRUCTION_READY), INSTRUCTION_READY, COMPUTE_UNIT);
    }
    if (Rep1->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(Rep1->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(Rep1->INSTRUCTION_READY), INSTRUCTION_READY, Rep1);
    }

    //Shared variable 1
    KO_READ = new Place("KO_READ");
    addSharedPtr(KO_READ, "KO_READ" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(COMPUTE_UNIT->KO_READ));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->KO_READ), KO_READ, COMPUTE_UNIT);
    }
    if (REGISTER_FILE->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(REGISTER_FILE->KO_READ));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->KO_READ), KO_READ, REGISTER_FILE);
    }

    //Shared variable 2
    MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE");
    addSharedPtr(MEM_OP_COMPLETE, "MEM_OP_COMPLETE" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(COMPUTE_UNIT->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->MEM_OP_COMPLETE), MEM_OP_COMPLETE, COMPUTE_UNIT);
    }
    if (REGISTER_FILE->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(REGISTER_FILE->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->MEM_OP_COMPLETE), MEM_OP_COMPLETE, REGISTER_FILE);
    }

    //Shared variable 3
    OK_READ = new Place("OK_READ");
    addSharedPtr(OK_READ, "OK_READ" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(COMPUTE_UNIT->OK_READ));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->OK_READ), OK_READ, COMPUTE_UNIT);
    }
    if (REGISTER_FILE->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(REGISTER_FILE->OK_READ));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->OK_READ), OK_READ, REGISTER_FILE);
    }

    //Shared variable 4
    READ_DRAM = new Place("READ_DRAM");
    addSharedPtr(READ_DRAM, "READ_DRAM" );
    if (LOCAL_MEMORY->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(LOCAL_MEMORY->READ_DRAM));
      addSharingInfo(getSharableSVPointer(LOCAL_MEMORY->READ_DRAM), READ_DRAM, LOCAL_MEMORY);
    }
    if (GLOBAL_MEMORY->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(GLOBAL_MEMORY->READ_DRAM));
      addSharingInfo(getSharableSVPointer(GLOBAL_MEMORY->READ_DRAM), READ_DRAM, GLOBAL_MEMORY);
    }

    //Shared variable 5
    READ_GLOBAL_MEMORY = new Place("READ_GLOBAL_MEMORY");
    addSharedPtr(READ_GLOBAL_MEMORY, "READ_GLOBAL_MEMORY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      READ_GLOBAL_MEMORY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->READ_GLOBAL_MEMORY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->READ_GLOBAL_MEMORY), READ_GLOBAL_MEMORY, COMPUTE_UNIT);
    }
    if (GLOBAL_MEMORY->NumStateVariables > 0) {
      READ_GLOBAL_MEMORY->ShareWith(getSharableSVPointer(GLOBAL_MEMORY->READ_GLOBAL_MEMORY));
      addSharingInfo(getSharableSVPointer(GLOBAL_MEMORY->READ_GLOBAL_MEMORY), READ_GLOBAL_MEMORY, GLOBAL_MEMORY);
    }

    //Shared variable 6
    READ_L1 = new Place("READ_L1");
    addSharedPtr(READ_L1, "READ_L1" );
    if (LOCAL_MEMORY->NumStateVariables > 0) {
      READ_L1->ShareWith(getSharableSVPointer(LOCAL_MEMORY->READ_L1));
      addSharingInfo(getSharableSVPointer(LOCAL_MEMORY->READ_L1), READ_L1, LOCAL_MEMORY);
    }
    if (GLOBAL_MEMORY->NumStateVariables > 0) {
      READ_L1->ShareWith(getSharableSVPointer(GLOBAL_MEMORY->READ_L1));
      addSharingInfo(getSharableSVPointer(GLOBAL_MEMORY->READ_L1), READ_L1, GLOBAL_MEMORY);
    }

    //Shared variable 7
    READ_L2 = new Place("READ_L2");
    addSharedPtr(READ_L2, "READ_L2" );
    if (LOCAL_MEMORY->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(LOCAL_MEMORY->READ_L2));
      addSharingInfo(getSharableSVPointer(LOCAL_MEMORY->READ_L2), READ_L2, LOCAL_MEMORY);
    }
    if (GLOBAL_MEMORY->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(GLOBAL_MEMORY->READ_L2));
      addSharingInfo(getSharableSVPointer(GLOBAL_MEMORY->READ_L2), READ_L2, GLOBAL_MEMORY);
    }

    //Shared variable 8
    READ_LOCAL_MEMORY = new Place("READ_LOCAL_MEMORY");
    addSharedPtr(READ_LOCAL_MEMORY, "READ_LOCAL_MEMORY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      READ_LOCAL_MEMORY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->READ_LOCAL_MEMORY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->READ_LOCAL_MEMORY), READ_LOCAL_MEMORY, COMPUTE_UNIT);
    }
    if (LOCAL_MEMORY->NumStateVariables > 0) {
      READ_LOCAL_MEMORY->ShareWith(getSharableSVPointer(LOCAL_MEMORY->READ_LOCAL_MEMORY));
      addSharingInfo(getSharableSVPointer(LOCAL_MEMORY->READ_LOCAL_MEMORY), READ_LOCAL_MEMORY, LOCAL_MEMORY);
    }

    //Shared variable 9
    READ_REGISTER_FILE = new Place("READ_REGISTER_FILE");
    addSharedPtr(READ_REGISTER_FILE, "READ_REGISTER_FILE" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      READ_REGISTER_FILE->ShareWith(getSharableSVPointer(COMPUTE_UNIT->READ_REGISTER_FILE));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->READ_REGISTER_FILE), READ_REGISTER_FILE, COMPUTE_UNIT);
    }
    if (REGISTER_FILE->NumStateVariables > 0) {
      READ_REGISTER_FILE->ShareWith(getSharableSVPointer(REGISTER_FILE->READ_REGISTER_FILE));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->READ_REGISTER_FILE), READ_REGISTER_FILE, REGISTER_FILE);
    }

    //Shared variable 10
    RESULT_KO = new Place("RESULT_KO");
    addSharedPtr(RESULT_KO, "RESULT_KO" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(COMPUTE_UNIT->RESULT_KO));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->RESULT_KO), RESULT_KO, COMPUTE_UNIT);
    }
    if (REGISTER_FILE->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(REGISTER_FILE->RESULT_KO));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->RESULT_KO), RESULT_KO, REGISTER_FILE);
    }

    //Shared variable 11
    RESULT_OK = new Place("RESULT_OK");
    addSharedPtr(RESULT_OK, "RESULT_OK" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(COMPUTE_UNIT->RESULT_OK));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->RESULT_OK), RESULT_OK, COMPUTE_UNIT);
    }
    if (REGISTER_FILE->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(REGISTER_FILE->RESULT_OK));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->RESULT_OK), RESULT_OK, REGISTER_FILE);
    }

    //Shared variable 12
    SCHEDULER = new Place("SCHEDULER");
    addSharedPtr(SCHEDULER, "SCHEDULER" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      SCHEDULER->ShareWith(getSharableSVPointer(COMPUTE_UNIT->SCHEDULER));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->SCHEDULER), SCHEDULER, COMPUTE_UNIT);
    }
    if (Rep1->NumStateVariables > 0) {
      SCHEDULER->ShareWith(getSharableSVPointer(Rep1->SCHEDULER));
      addSharingInfo(getSharableSVPointer(Rep1->SCHEDULER), SCHEDULER, Rep1);
    }

    //Shared variable 13
    WRITE_DRAM = new Place("WRITE_DRAM");
    addSharedPtr(WRITE_DRAM, "WRITE_DRAM" );
    if (LOCAL_MEMORY->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(LOCAL_MEMORY->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(LOCAL_MEMORY->WRITE_DRAM), WRITE_DRAM, LOCAL_MEMORY);
    }
    if (GLOBAL_MEMORY->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(GLOBAL_MEMORY->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(GLOBAL_MEMORY->WRITE_DRAM), WRITE_DRAM, GLOBAL_MEMORY);
    }
    if (OUTPUT_MEMORY->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(OUTPUT_MEMORY->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(OUTPUT_MEMORY->WRITE_DRAM), WRITE_DRAM, OUTPUT_MEMORY);
    }

    //Shared variable 14
    WRITE_GLOBAL_MEMORY = new Place("WRITE_GLOBAL_MEMORY");
    addSharedPtr(WRITE_GLOBAL_MEMORY, "WRITE_GLOBAL_MEMORY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      WRITE_GLOBAL_MEMORY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->WRITE_GLOBAL_MEMORY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->WRITE_GLOBAL_MEMORY), WRITE_GLOBAL_MEMORY, COMPUTE_UNIT);
    }
    if (GLOBAL_MEMORY->NumStateVariables > 0) {
      WRITE_GLOBAL_MEMORY->ShareWith(getSharableSVPointer(GLOBAL_MEMORY->WRITE_GLOBAL_MEMORY));
      addSharingInfo(getSharableSVPointer(GLOBAL_MEMORY->WRITE_GLOBAL_MEMORY), WRITE_GLOBAL_MEMORY, GLOBAL_MEMORY);
    }

    //Shared variable 15
    WRITE_L1 = new Place("WRITE_L1");
    addSharedPtr(WRITE_L1, "WRITE_L1" );
    if (LOCAL_MEMORY->NumStateVariables > 0) {
      WRITE_L1->ShareWith(getSharableSVPointer(LOCAL_MEMORY->WRITE_L1));
      addSharingInfo(getSharableSVPointer(LOCAL_MEMORY->WRITE_L1), WRITE_L1, LOCAL_MEMORY);
    }
    if (GLOBAL_MEMORY->NumStateVariables > 0) {
      WRITE_L1->ShareWith(getSharableSVPointer(GLOBAL_MEMORY->WRITE_L1));
      addSharingInfo(getSharableSVPointer(GLOBAL_MEMORY->WRITE_L1), WRITE_L1, GLOBAL_MEMORY);
    }

    //Shared variable 16
    WRITE_L2 = new Place("WRITE_L2");
    addSharedPtr(WRITE_L2, "WRITE_L2" );
    if (LOCAL_MEMORY->NumStateVariables > 0) {
      WRITE_L2->ShareWith(getSharableSVPointer(LOCAL_MEMORY->WRITE_L2));
      addSharingInfo(getSharableSVPointer(LOCAL_MEMORY->WRITE_L2), WRITE_L2, LOCAL_MEMORY);
    }
    if (GLOBAL_MEMORY->NumStateVariables > 0) {
      WRITE_L2->ShareWith(getSharableSVPointer(GLOBAL_MEMORY->WRITE_L2));
      addSharingInfo(getSharableSVPointer(GLOBAL_MEMORY->WRITE_L2), WRITE_L2, GLOBAL_MEMORY);
    }

    //Shared variable 17
    WRITE_LOCAL_MEMORY = new Place("WRITE_LOCAL_MEMORY");
    addSharedPtr(WRITE_LOCAL_MEMORY, "WRITE_LOCAL_MEMORY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      WRITE_LOCAL_MEMORY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->WRITE_LOCAL_MEMORY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->WRITE_LOCAL_MEMORY), WRITE_LOCAL_MEMORY, COMPUTE_UNIT);
    }
    if (LOCAL_MEMORY->NumStateVariables > 0) {
      WRITE_LOCAL_MEMORY->ShareWith(getSharableSVPointer(LOCAL_MEMORY->WRITE_LOCAL_MEMORY));
      addSharingInfo(getSharableSVPointer(LOCAL_MEMORY->WRITE_LOCAL_MEMORY), WRITE_LOCAL_MEMORY, LOCAL_MEMORY);
    }

    //Shared variable 18
    WRITE_OUTPUT_MEMORY = new Place("WRITE_OUTPUT_MEMORY");
    addSharedPtr(WRITE_OUTPUT_MEMORY, "WRITE_OUTPUT_MEMORY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      WRITE_OUTPUT_MEMORY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->WRITE_OUTPUT_MEMORY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->WRITE_OUTPUT_MEMORY), WRITE_OUTPUT_MEMORY, COMPUTE_UNIT);
    }
    if (OUTPUT_MEMORY->NumStateVariables > 0) {
      WRITE_OUTPUT_MEMORY->ShareWith(getSharableSVPointer(OUTPUT_MEMORY->WRITE_OUTPUT_MEMORY));
      addSharingInfo(getSharableSVPointer(OUTPUT_MEMORY->WRITE_OUTPUT_MEMORY), WRITE_OUTPUT_MEMORY, OUTPUT_MEMORY);
    }

    //Shared variable 19
    WRITE_REGISTER_FILE = new Place("WRITE_REGISTER_FILE");
    addSharedPtr(WRITE_REGISTER_FILE, "WRITE_REGISTER_FILE" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      WRITE_REGISTER_FILE->ShareWith(getSharableSVPointer(COMPUTE_UNIT->WRITE_REGISTER_FILE));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->WRITE_REGISTER_FILE), WRITE_REGISTER_FILE, COMPUTE_UNIT);
    }
    if (REGISTER_FILE->NumStateVariables > 0) {
      WRITE_REGISTER_FILE->ShareWith(getSharableSVPointer(REGISTER_FILE->WRITE_REGISTER_FILE));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->WRITE_REGISTER_FILE), WRITE_REGISTER_FILE, REGISTER_FILE);
    }

  }

  Setup();
}

GPU4.BKPRJ__PROCESSOR::~GPU4.BKPRJ__PROCESSOR() {
  if (!AllChildrenEmpty()) {
    delete INSTRUCTION_READY;
    delete KO_READ;
    delete MEM_OP_COMPLETE;
    delete OK_READ;
    delete READ_DRAM;
    delete READ_GLOBAL_MEMORY;
    delete READ_L1;
    delete READ_L2;
    delete READ_LOCAL_MEMORY;
    delete READ_REGISTER_FILE;
    delete RESULT_KO;
    delete RESULT_OK;
    delete SCHEDULER;
    delete WRITE_DRAM;
    delete WRITE_GLOBAL_MEMORY;
    delete WRITE_L1;
    delete WRITE_L2;
    delete WRITE_LOCAL_MEMORY;
    delete WRITE_OUTPUT_MEMORY;
    delete WRITE_REGISTER_FILE;
  }
  delete Rep1;
  delete COMPUTE_UNIT;
  delete LOCAL_MEMORY;
  delete GLOBAL_MEMORY;
  delete REGISTER_FILE;
  delete OUTPUT_MEMORY;
}
