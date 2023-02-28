#include "Composed/GPU5/GPU5RJ__PROCESSOR.h"
char * GPU5RJ__PROCESSOR__SharedNames[] = {"INSTRUCTION_READY", "KO_READ", "MEM_OP_COMPLETE", "OK_CONTENT", "OK_READ", "READ", "READ_DRAM", "READ_L1", "READ_L2", "READ_REGISTER_FILE", "REGISTERS_FILL", "RESULT_KO", "RESULT_OK", "SCHEDULER", "WRITE", "WRITE_DRAM", "WRITE_L1", "WRITE_L2", "WRITE_REGISTER_FILE"};

GPU5RJ__PROCESSOR::GPU5RJ__PROCESSOR():Join("PROCESSOR", 4, 19,GPU5RJ__PROCESSOR__SharedNames) {
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

    //Shared variable 1
    KO_READ = new Place("KO_READ");
    addSharedPtr(KO_READ, "KO_READ" );
    if (REGISTER_FILE->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(REGISTER_FILE->KO_READ));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->KO_READ), KO_READ, REGISTER_FILE);
    }
    if (EXEC_UNIT->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(EXEC_UNIT->KO_READ));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT->KO_READ), KO_READ, EXEC_UNIT);
    }

    //Shared variable 2
    MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE");
    addSharedPtr(MEM_OP_COMPLETE, "MEM_OP_COMPLETE" );
    if (REGISTER_FILE->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(REGISTER_FILE->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->MEM_OP_COMPLETE), MEM_OP_COMPLETE, REGISTER_FILE);
    }
    if (EXEC_UNIT->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(EXEC_UNIT->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT->MEM_OP_COMPLETE), MEM_OP_COMPLETE, EXEC_UNIT);
    }

    //Shared variable 3
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

    //Shared variable 4
    OK_READ = new Place("OK_READ");
    addSharedPtr(OK_READ, "OK_READ" );
    if (REGISTER_FILE->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(REGISTER_FILE->OK_READ));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->OK_READ), OK_READ, REGISTER_FILE);
    }
    if (EXEC_UNIT->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(EXEC_UNIT->OK_READ));
      addSharingInfo(getSharableSVPointer(EXEC_UNIT->OK_READ), OK_READ, EXEC_UNIT);
    }

    //Shared variable 5
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

    //Shared variable 6
    READ_DRAM = new Place("READ_DRAM");
    addSharedPtr(READ_DRAM, "READ_DRAM" );
    if (MEMORY->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(MEMORY->READ_DRAM));
      addSharingInfo(getSharableSVPointer(MEMORY->READ_DRAM), READ_DRAM, MEMORY);
    }

    //Shared variable 7
    READ_L1 = new Place("READ_L1");
    addSharedPtr(READ_L1, "READ_L1" );
    if (MEMORY->NumStateVariables > 0) {
      READ_L1->ShareWith(getSharableSVPointer(MEMORY->READ_L1));
      addSharingInfo(getSharableSVPointer(MEMORY->READ_L1), READ_L1, MEMORY);
    }

    //Shared variable 8
    READ_L2 = new Place("READ_L2");
    addSharedPtr(READ_L2, "READ_L2" );
    if (MEMORY->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(MEMORY->READ_L2));
      addSharingInfo(getSharableSVPointer(MEMORY->READ_L2), READ_L2, MEMORY);
    }

    //Shared variable 9
    READ_REGISTER_FILE = new Place("READ_REGISTER_FILE");
    addSharedPtr(READ_REGISTER_FILE, "READ_REGISTER_FILE" );
    if (REGISTER_FILE->NumStateVariables > 0) {
      READ_REGISTER_FILE->ShareWith(getSharableSVPointer(REGISTER_FILE->READ_REGISTER_FILE));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->READ_REGISTER_FILE), READ_REGISTER_FILE, REGISTER_FILE);
    }
    if (MEMORY->NumStateVariables > 0) {
      READ_REGISTER_FILE->ShareWith(getSharableSVPointer(MEMORY->READ_REGISTER_FILE));
      addSharingInfo(getSharableSVPointer(MEMORY->READ_REGISTER_FILE), READ_REGISTER_FILE, MEMORY);
    }

    //Shared variable 10
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

    //Shared variable 11
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

    //Shared variable 12
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

    //Shared variable 13
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

    //Shared variable 14
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

    //Shared variable 15
    WRITE_DRAM = new Place("WRITE_DRAM");
    addSharedPtr(WRITE_DRAM, "WRITE_DRAM" );
    if (MEMORY->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(MEMORY->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(MEMORY->WRITE_DRAM), WRITE_DRAM, MEMORY);
    }

    //Shared variable 16
    WRITE_L1 = new Place("WRITE_L1");
    addSharedPtr(WRITE_L1, "WRITE_L1" );
    if (MEMORY->NumStateVariables > 0) {
      WRITE_L1->ShareWith(getSharableSVPointer(MEMORY->WRITE_L1));
      addSharingInfo(getSharableSVPointer(MEMORY->WRITE_L1), WRITE_L1, MEMORY);
    }

    //Shared variable 17
    WRITE_L2 = new Place("WRITE_L2");
    addSharedPtr(WRITE_L2, "WRITE_L2" );
    if (MEMORY->NumStateVariables > 0) {
      WRITE_L2->ShareWith(getSharableSVPointer(MEMORY->WRITE_L2));
      addSharingInfo(getSharableSVPointer(MEMORY->WRITE_L2), WRITE_L2, MEMORY);
    }

    //Shared variable 18
    WRITE_REGISTER_FILE = new Place("WRITE_REGISTER_FILE");
    addSharedPtr(WRITE_REGISTER_FILE, "WRITE_REGISTER_FILE" );
    if (REGISTER_FILE->NumStateVariables > 0) {
      WRITE_REGISTER_FILE->ShareWith(getSharableSVPointer(REGISTER_FILE->WRITE_REGISTER_FILE));
      addSharingInfo(getSharableSVPointer(REGISTER_FILE->WRITE_REGISTER_FILE), WRITE_REGISTER_FILE, REGISTER_FILE);
    }
    if (MEMORY->NumStateVariables > 0) {
      WRITE_REGISTER_FILE->ShareWith(getSharableSVPointer(MEMORY->WRITE_REGISTER_FILE));
      addSharingInfo(getSharableSVPointer(MEMORY->WRITE_REGISTER_FILE), WRITE_REGISTER_FILE, MEMORY);
    }

  }

  Setup();
}

GPU5RJ__PROCESSOR::~GPU5RJ__PROCESSOR() {
  if (!AllChildrenEmpty()) {
    delete INSTRUCTION_READY;
    delete KO_READ;
    delete MEM_OP_COMPLETE;
    delete OK_CONTENT;
    delete OK_READ;
    delete READ;
    delete READ_DRAM;
    delete READ_L1;
    delete READ_L2;
    delete READ_REGISTER_FILE;
    delete REGISTERS_FILL;
    delete RESULT_KO;
    delete RESULT_OK;
    delete SCHEDULER;
    delete WRITE;
    delete WRITE_DRAM;
    delete WRITE_L1;
    delete WRITE_L2;
    delete WRITE_REGISTER_FILE;
  }
  delete Rep1;
  delete REGISTER_FILE;
  delete EXEC_UNIT;
  delete MEMORY;
}
