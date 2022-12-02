#include "Composed/GPU/GPURJ.h"
char * GPURJ__SharedNames[] = {"KO_READ", "MEM_OP_COMPLETE", "OK_READ", "READ_DRAM", "READ_INITIAL_MEMORY", "READ_INTERMEDIATE_MEMORY", "READ_L1", "READ_L2", "RESULT_KO", "RESULT_OK", "WRITE_DRAM", "WRITE_FINAL_MEMORY", "WRITE_INTERMEDIATE_MEMORY", "WRITE_L1", "WRITE_L2"};

GPURJ::GPURJ():Join("Join", 7, 15,GPURJ__SharedNames) {
  COMPUTE_UNIT = new COMPUTE_UNITSAN();
  ModelArray[0] = (BaseModelClass*) COMPUTE_UNIT;
  ModelArray[0]->DefineName("COMPUTE_UNIT");
  DRAM = new DRAMSAN();
  ModelArray[1] = (BaseModelClass*) DRAM;
  ModelArray[1]->DefineName("DRAM");
  L2_CACHE = new L2_CACHESAN();
  ModelArray[2] = (BaseModelClass*) L2_CACHE;
  ModelArray[2]->DefineName("L2_CACHE");
  L1_CACHE = new L1_CACHESAN();
  ModelArray[3] = (BaseModelClass*) L1_CACHE;
  ModelArray[3]->DefineName("L1_CACHE");
  INITIAL_MEMORY_MODEL = new INITIAL_MEMORY_MODELSAN();
  ModelArray[4] = (BaseModelClass*) INITIAL_MEMORY_MODEL;
  ModelArray[4]->DefineName("INITIAL_MEMORY_MODEL");
  INTERMEDIATE_MEMORY_MODEL = new INTERMEDIATE_MEMORY_MODELSAN();
  ModelArray[5] = (BaseModelClass*) INTERMEDIATE_MEMORY_MODEL;
  ModelArray[5]->DefineName("INTERMEDIATE_MEMORY_MODEL");
  FINAL_MEMORY_MODEL = new FINAL_MEMORY_MODELSAN();
  ModelArray[6] = (BaseModelClass*) FINAL_MEMORY_MODEL;
  ModelArray[6]->DefineName("FINAL_MEMORY_MODEL");

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
    if (DRAM->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(DRAM->KO_READ));
      addSharingInfo(getSharableSVPointer(DRAM->KO_READ), KO_READ, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(L2_CACHE->KO_READ));
      addSharingInfo(getSharableSVPointer(L2_CACHE->KO_READ), KO_READ, L2_CACHE);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(L1_CACHE->KO_READ));
      addSharingInfo(getSharableSVPointer(L1_CACHE->KO_READ), KO_READ, L1_CACHE);
    }

    //Shared variable 1
    MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE");
    addSharedPtr(MEM_OP_COMPLETE, "MEM_OP_COMPLETE" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(COMPUTE_UNIT->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->MEM_OP_COMPLETE), MEM_OP_COMPLETE, COMPUTE_UNIT);
    }
    if (DRAM->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(DRAM->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(DRAM->MEM_OP_COMPLETE), MEM_OP_COMPLETE, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(L2_CACHE->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(L2_CACHE->MEM_OP_COMPLETE), MEM_OP_COMPLETE, L2_CACHE);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(L1_CACHE->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(L1_CACHE->MEM_OP_COMPLETE), MEM_OP_COMPLETE, L1_CACHE);
    }

    //Shared variable 2
    OK_READ = new Place("OK_READ");
    addSharedPtr(OK_READ, "OK_READ" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(COMPUTE_UNIT->OK_READ));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->OK_READ), OK_READ, COMPUTE_UNIT);
    }
    if (DRAM->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(DRAM->OK_READ));
      addSharingInfo(getSharableSVPointer(DRAM->OK_READ), OK_READ, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(L2_CACHE->OK_READ));
      addSharingInfo(getSharableSVPointer(L2_CACHE->OK_READ), OK_READ, L2_CACHE);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(L1_CACHE->OK_READ));
      addSharingInfo(getSharableSVPointer(L1_CACHE->OK_READ), OK_READ, L1_CACHE);
    }

    //Shared variable 3
    READ_DRAM = new Place("READ_DRAM");
    addSharedPtr(READ_DRAM, "READ_DRAM" );
    if (DRAM->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(DRAM->READ_DRAM));
      addSharingInfo(getSharableSVPointer(DRAM->READ_DRAM), READ_DRAM, DRAM);
    }
    if (INITIAL_MEMORY_MODEL->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(INITIAL_MEMORY_MODEL->READ_DRAM));
      addSharingInfo(getSharableSVPointer(INITIAL_MEMORY_MODEL->READ_DRAM), READ_DRAM, INITIAL_MEMORY_MODEL);
    }
    if (INTERMEDIATE_MEMORY_MODEL->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(INTERMEDIATE_MEMORY_MODEL->READ_DRAM));
      addSharingInfo(getSharableSVPointer(INTERMEDIATE_MEMORY_MODEL->READ_DRAM), READ_DRAM, INTERMEDIATE_MEMORY_MODEL);
    }

    //Shared variable 4
    READ_INITIAL_MEMORY = new Place("READ_INITIAL_MEMORY");
    addSharedPtr(READ_INITIAL_MEMORY, "READ_INITIAL_MEMORY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      READ_INITIAL_MEMORY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->READ_INITIAL_MEMORY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->READ_INITIAL_MEMORY), READ_INITIAL_MEMORY, COMPUTE_UNIT);
    }
    if (INITIAL_MEMORY_MODEL->NumStateVariables > 0) {
      READ_INITIAL_MEMORY->ShareWith(getSharableSVPointer(INITIAL_MEMORY_MODEL->READ_INITIAL_MEMORY));
      addSharingInfo(getSharableSVPointer(INITIAL_MEMORY_MODEL->READ_INITIAL_MEMORY), READ_INITIAL_MEMORY, INITIAL_MEMORY_MODEL);
    }

    //Shared variable 5
    READ_INTERMEDIATE_MEMORY = new Place("READ_INTERMEDIATE_MEMORY");
    addSharedPtr(READ_INTERMEDIATE_MEMORY, "READ_INTERMEDIATE_MEMORY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      READ_INTERMEDIATE_MEMORY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->READ_INTERMEDIATE_MEMORY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->READ_INTERMEDIATE_MEMORY), READ_INTERMEDIATE_MEMORY, COMPUTE_UNIT);
    }
    if (INTERMEDIATE_MEMORY_MODEL->NumStateVariables > 0) {
      READ_INTERMEDIATE_MEMORY->ShareWith(getSharableSVPointer(INTERMEDIATE_MEMORY_MODEL->READ_INTERMEDIATE_MEMORY));
      addSharingInfo(getSharableSVPointer(INTERMEDIATE_MEMORY_MODEL->READ_INTERMEDIATE_MEMORY), READ_INTERMEDIATE_MEMORY, INTERMEDIATE_MEMORY_MODEL);
    }

    //Shared variable 6
    READ_L1 = new Place("READ_L1");
    addSharedPtr(READ_L1, "READ_L1" );
    if (L1_CACHE->NumStateVariables > 0) {
      READ_L1->ShareWith(getSharableSVPointer(L1_CACHE->READ_L1));
      addSharingInfo(getSharableSVPointer(L1_CACHE->READ_L1), READ_L1, L1_CACHE);
    }
    if (INTERMEDIATE_MEMORY_MODEL->NumStateVariables > 0) {
      READ_L1->ShareWith(getSharableSVPointer(INTERMEDIATE_MEMORY_MODEL->READ_L1));
      addSharingInfo(getSharableSVPointer(INTERMEDIATE_MEMORY_MODEL->READ_L1), READ_L1, INTERMEDIATE_MEMORY_MODEL);
    }

    //Shared variable 7
    READ_L2 = new Place("READ_L2");
    addSharedPtr(READ_L2, "READ_L2" );
    if (L2_CACHE->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(L2_CACHE->READ_L2));
      addSharingInfo(getSharableSVPointer(L2_CACHE->READ_L2), READ_L2, L2_CACHE);
    }
    if (INITIAL_MEMORY_MODEL->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(INITIAL_MEMORY_MODEL->READ_L2));
      addSharingInfo(getSharableSVPointer(INITIAL_MEMORY_MODEL->READ_L2), READ_L2, INITIAL_MEMORY_MODEL);
    }
    if (INTERMEDIATE_MEMORY_MODEL->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(INTERMEDIATE_MEMORY_MODEL->READ_L2));
      addSharingInfo(getSharableSVPointer(INTERMEDIATE_MEMORY_MODEL->READ_L2), READ_L2, INTERMEDIATE_MEMORY_MODEL);
    }

    //Shared variable 8
    RESULT_KO = new Place("RESULT_KO");
    addSharedPtr(RESULT_KO, "RESULT_KO" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(COMPUTE_UNIT->RESULT_KO));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->RESULT_KO), RESULT_KO, COMPUTE_UNIT);
    }
    if (DRAM->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(DRAM->RESULT_KO));
      addSharingInfo(getSharableSVPointer(DRAM->RESULT_KO), RESULT_KO, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(L2_CACHE->RESULT_KO));
      addSharingInfo(getSharableSVPointer(L2_CACHE->RESULT_KO), RESULT_KO, L2_CACHE);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(L1_CACHE->RESULT_KO));
      addSharingInfo(getSharableSVPointer(L1_CACHE->RESULT_KO), RESULT_KO, L1_CACHE);
    }

    //Shared variable 9
    RESULT_OK = new Place("RESULT_OK");
    addSharedPtr(RESULT_OK, "RESULT_OK" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(COMPUTE_UNIT->RESULT_OK));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->RESULT_OK), RESULT_OK, COMPUTE_UNIT);
    }
    if (DRAM->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(DRAM->RESULT_OK));
      addSharingInfo(getSharableSVPointer(DRAM->RESULT_OK), RESULT_OK, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(L2_CACHE->RESULT_OK));
      addSharingInfo(getSharableSVPointer(L2_CACHE->RESULT_OK), RESULT_OK, L2_CACHE);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(L1_CACHE->RESULT_OK));
      addSharingInfo(getSharableSVPointer(L1_CACHE->RESULT_OK), RESULT_OK, L1_CACHE);
    }

    //Shared variable 10
    WRITE_DRAM = new Place("WRITE_DRAM");
    addSharedPtr(WRITE_DRAM, "WRITE_DRAM" );
    if (DRAM->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(DRAM->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(DRAM->WRITE_DRAM), WRITE_DRAM, DRAM);
    }
    if (INTERMEDIATE_MEMORY_MODEL->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(INTERMEDIATE_MEMORY_MODEL->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(INTERMEDIATE_MEMORY_MODEL->WRITE_DRAM), WRITE_DRAM, INTERMEDIATE_MEMORY_MODEL);
    }
    if (FINAL_MEMORY_MODEL->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(FINAL_MEMORY_MODEL->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(FINAL_MEMORY_MODEL->WRITE_DRAM), WRITE_DRAM, FINAL_MEMORY_MODEL);
    }

    //Shared variable 11
    WRITE_FINAL_MEMORY = new Place("WRITE_FINAL_MEMORY");
    addSharedPtr(WRITE_FINAL_MEMORY, "WRITE_FINAL_MEMORY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      WRITE_FINAL_MEMORY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->WRITE_FINAL_MEMORY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->WRITE_FINAL_MEMORY), WRITE_FINAL_MEMORY, COMPUTE_UNIT);
    }
    if (FINAL_MEMORY_MODEL->NumStateVariables > 0) {
      WRITE_FINAL_MEMORY->ShareWith(getSharableSVPointer(FINAL_MEMORY_MODEL->WRITE_FINAL_MEMORY));
      addSharingInfo(getSharableSVPointer(FINAL_MEMORY_MODEL->WRITE_FINAL_MEMORY), WRITE_FINAL_MEMORY, FINAL_MEMORY_MODEL);
    }

    //Shared variable 12
    WRITE_INTERMEDIATE_MEMORY = new Place("WRITE_INTERMEDIATE_MEMORY");
    addSharedPtr(WRITE_INTERMEDIATE_MEMORY, "WRITE_INTERMEDIATE_MEMORY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      WRITE_INTERMEDIATE_MEMORY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->WRITE_INTERMEDIATE_MEMORY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->WRITE_INTERMEDIATE_MEMORY), WRITE_INTERMEDIATE_MEMORY, COMPUTE_UNIT);
    }
    if (INTERMEDIATE_MEMORY_MODEL->NumStateVariables > 0) {
      WRITE_INTERMEDIATE_MEMORY->ShareWith(getSharableSVPointer(INTERMEDIATE_MEMORY_MODEL->WRITE_INTERMEDIATE_MEMORY));
      addSharingInfo(getSharableSVPointer(INTERMEDIATE_MEMORY_MODEL->WRITE_INTERMEDIATE_MEMORY), WRITE_INTERMEDIATE_MEMORY, INTERMEDIATE_MEMORY_MODEL);
    }

    //Shared variable 13
    WRITE_L1 = new Place("WRITE_L1");
    addSharedPtr(WRITE_L1, "WRITE_L1" );
    if (L1_CACHE->NumStateVariables > 0) {
      WRITE_L1->ShareWith(getSharableSVPointer(L1_CACHE->WRITE_L1));
      addSharingInfo(getSharableSVPointer(L1_CACHE->WRITE_L1), WRITE_L1, L1_CACHE);
    }
    if (INTERMEDIATE_MEMORY_MODEL->NumStateVariables > 0) {
      WRITE_L1->ShareWith(getSharableSVPointer(INTERMEDIATE_MEMORY_MODEL->WRITE_L1));
      addSharingInfo(getSharableSVPointer(INTERMEDIATE_MEMORY_MODEL->WRITE_L1), WRITE_L1, INTERMEDIATE_MEMORY_MODEL);
    }

    //Shared variable 14
    WRITE_L2 = new Place("WRITE_L2");
    addSharedPtr(WRITE_L2, "WRITE_L2" );
    if (L2_CACHE->NumStateVariables > 0) {
      WRITE_L2->ShareWith(getSharableSVPointer(L2_CACHE->WRITE_L2));
      addSharingInfo(getSharableSVPointer(L2_CACHE->WRITE_L2), WRITE_L2, L2_CACHE);
    }
    if (INTERMEDIATE_MEMORY_MODEL->NumStateVariables > 0) {
      WRITE_L2->ShareWith(getSharableSVPointer(INTERMEDIATE_MEMORY_MODEL->WRITE_L2));
      addSharingInfo(getSharableSVPointer(INTERMEDIATE_MEMORY_MODEL->WRITE_L2), WRITE_L2, INTERMEDIATE_MEMORY_MODEL);
    }

  }

  Setup();
}

GPURJ::~GPURJ() {
  if (!AllChildrenEmpty()) {
    delete KO_READ;
    delete MEM_OP_COMPLETE;
    delete OK_READ;
    delete READ_DRAM;
    delete READ_INITIAL_MEMORY;
    delete READ_INTERMEDIATE_MEMORY;
    delete READ_L1;
    delete READ_L2;
    delete RESULT_KO;
    delete RESULT_OK;
    delete WRITE_DRAM;
    delete WRITE_FINAL_MEMORY;
    delete WRITE_INTERMEDIATE_MEMORY;
    delete WRITE_L1;
    delete WRITE_L2;
  }
  delete COMPUTE_UNIT;
  delete DRAM;
  delete L2_CACHE;
  delete L1_CACHE;
  delete INITIAL_MEMORY_MODEL;
  delete INTERMEDIATE_MEMORY_MODEL;
  delete FINAL_MEMORY_MODEL;
}
