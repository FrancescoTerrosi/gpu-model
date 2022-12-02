#include "Composed/GPU/GPURJ.h"
char * GPURJ__SharedNames[] = {"KO_READ", "MEM_OP_COMPLETE", "OK_READ", "READ_RESULT_MEMORY", "READ_TOTAL_MEMORY", "RESULT_KO", "RESULT_OK", "WRITE_OUTPUT_MEMORY", "WRITE_RESULT_MEMORY"};

GPURJ::GPURJ():Join("Join", 4, 9,GPURJ__SharedNames) {
  COMPUTE_UNIT = new COMPUTE_UNITSAN();
  ModelArray[0] = (BaseModelClass*) COMPUTE_UNIT;
  ModelArray[0]->DefineName("COMPUTE_UNIT");
  TOTAL_MEMORY = new TOTAL_MEMORY_MODELSAN();
  ModelArray[1] = (BaseModelClass*) TOTAL_MEMORY;
  ModelArray[1]->DefineName("TOTAL_MEMORY");
  OUTPUT_MEMORY = new OUTPUT_MEMORY_MODELSAN();
  ModelArray[2] = (BaseModelClass*) OUTPUT_MEMORY;
  ModelArray[2]->DefineName("OUTPUT_MEMORY");
  RESULT_MEMORY = new RESULT_MEMORY_MODELSAN();
  ModelArray[3] = (BaseModelClass*) RESULT_MEMORY;
  ModelArray[3]->DefineName("RESULT_MEMORY");

  SetupActions();
  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************  State sharing info  **************
    //Shared variable 0
    KO_READ = new Place("KO_READ");
    addSharedPtr(KO_READ, "KO_READ" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(COMPUTE_UNIT->KO_READ));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->KO_READ), KO_READ, COMPUTE_UNIT);
    }
    if (TOTAL_MEMORY->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(TOTAL_MEMORY->KO_READ));
      addSharingInfo(getSharableSVPointer(TOTAL_MEMORY->KO_READ), KO_READ, TOTAL_MEMORY);
    }
    if (RESULT_MEMORY->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(RESULT_MEMORY->KO_READ));
      addSharingInfo(getSharableSVPointer(RESULT_MEMORY->KO_READ), KO_READ, RESULT_MEMORY);
    }

    //Shared variable 1
    MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE");
    addSharedPtr(MEM_OP_COMPLETE, "MEM_OP_COMPLETE" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(COMPUTE_UNIT->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->MEM_OP_COMPLETE), MEM_OP_COMPLETE, COMPUTE_UNIT);
    }
    if (TOTAL_MEMORY->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(TOTAL_MEMORY->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(TOTAL_MEMORY->MEM_OP_COMPLETE), MEM_OP_COMPLETE, TOTAL_MEMORY);
    }
    if (OUTPUT_MEMORY->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(OUTPUT_MEMORY->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(OUTPUT_MEMORY->MEM_OP_COMPLETE), MEM_OP_COMPLETE, OUTPUT_MEMORY);
    }
    if (RESULT_MEMORY->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(RESULT_MEMORY->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(RESULT_MEMORY->MEM_OP_COMPLETE), MEM_OP_COMPLETE, RESULT_MEMORY);
    }

    //Shared variable 2
    OK_READ = new Place("OK_READ");
    addSharedPtr(OK_READ, "OK_READ" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(COMPUTE_UNIT->OK_READ));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->OK_READ), OK_READ, COMPUTE_UNIT);
    }
    if (TOTAL_MEMORY->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(TOTAL_MEMORY->OK_READ));
      addSharingInfo(getSharableSVPointer(TOTAL_MEMORY->OK_READ), OK_READ, TOTAL_MEMORY);
    }
    if (RESULT_MEMORY->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(RESULT_MEMORY->OK_READ));
      addSharingInfo(getSharableSVPointer(RESULT_MEMORY->OK_READ), OK_READ, RESULT_MEMORY);
    }

    //Shared variable 3
    READ_RESULT_MEMORY = new Place("READ_RESULT_MEMORY");
    addSharedPtr(READ_RESULT_MEMORY, "READ_RESULT_MEMORY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      READ_RESULT_MEMORY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->READ_RESULT_MEMORY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->READ_RESULT_MEMORY), READ_RESULT_MEMORY, COMPUTE_UNIT);
    }
    if (RESULT_MEMORY->NumStateVariables > 0) {
      READ_RESULT_MEMORY->ShareWith(getSharableSVPointer(RESULT_MEMORY->READ_RESULT_MEMORY));
      addSharingInfo(getSharableSVPointer(RESULT_MEMORY->READ_RESULT_MEMORY), READ_RESULT_MEMORY, RESULT_MEMORY);
    }

    //Shared variable 4
    READ_TOTAL_MEMORY = new Place("READ_TOTAL_MEMORY");
    addSharedPtr(READ_TOTAL_MEMORY, "READ_TOTAL_MEMORY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      READ_TOTAL_MEMORY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->READ_TOTAL_MEMORY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->READ_TOTAL_MEMORY), READ_TOTAL_MEMORY, COMPUTE_UNIT);
    }
    if (TOTAL_MEMORY->NumStateVariables > 0) {
      READ_TOTAL_MEMORY->ShareWith(getSharableSVPointer(TOTAL_MEMORY->READ_TOTAL_MEMORY));
      addSharingInfo(getSharableSVPointer(TOTAL_MEMORY->READ_TOTAL_MEMORY), READ_TOTAL_MEMORY, TOTAL_MEMORY);
    }

    //Shared variable 5
    RESULT_KO = new Place("RESULT_KO");
    addSharedPtr(RESULT_KO, "RESULT_KO" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(COMPUTE_UNIT->RESULT_KO));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->RESULT_KO), RESULT_KO, COMPUTE_UNIT);
    }
    if (RESULT_MEMORY->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(RESULT_MEMORY->RESULT_KO));
      addSharingInfo(getSharableSVPointer(RESULT_MEMORY->RESULT_KO), RESULT_KO, RESULT_MEMORY);
    }

    //Shared variable 6
    RESULT_OK = new Place("RESULT_OK");
    addSharedPtr(RESULT_OK, "RESULT_OK" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(COMPUTE_UNIT->RESULT_OK));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->RESULT_OK), RESULT_OK, COMPUTE_UNIT);
    }
    if (RESULT_MEMORY->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(RESULT_MEMORY->RESULT_OK));
      addSharingInfo(getSharableSVPointer(RESULT_MEMORY->RESULT_OK), RESULT_OK, RESULT_MEMORY);
    }

    //Shared variable 7
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

    //Shared variable 8
    WRITE_RESULT_MEMORY = new Place("WRITE_RESULT_MEMORY");
    addSharedPtr(WRITE_RESULT_MEMORY, "WRITE_RESULT_MEMORY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      WRITE_RESULT_MEMORY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->WRITE_RESULT_MEMORY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->WRITE_RESULT_MEMORY), WRITE_RESULT_MEMORY, COMPUTE_UNIT);
    }
    if (RESULT_MEMORY->NumStateVariables > 0) {
      WRITE_RESULT_MEMORY->ShareWith(getSharableSVPointer(RESULT_MEMORY->WRITE_RESULT_MEMORY));
      addSharingInfo(getSharableSVPointer(RESULT_MEMORY->WRITE_RESULT_MEMORY), WRITE_RESULT_MEMORY, RESULT_MEMORY);
    }

  }

  Setup();
}

GPURJ::~GPURJ() {
  if (!AllChildrenEmpty()) {
    delete KO_READ;
    delete MEM_OP_COMPLETE;
    delete OK_READ;
    delete READ_RESULT_MEMORY;
    delete READ_TOTAL_MEMORY;
    delete RESULT_KO;
    delete RESULT_OK;
    delete WRITE_OUTPUT_MEMORY;
    delete WRITE_RESULT_MEMORY;
  }
  delete COMPUTE_UNIT;
  delete TOTAL_MEMORY;
  delete OUTPUT_MEMORY;
  delete RESULT_MEMORY;
}
