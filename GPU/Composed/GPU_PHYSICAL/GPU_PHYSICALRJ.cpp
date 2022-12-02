#include "Composed/GPU_PHYSICAL/GPU_PHYSICALRJ.h"
char * GPU_PHYSICALRJ__SharedNames[] = {"KO_READ", "MEM_OP_COMPLETE", "OK_READ", "READ_DRAM", "READ_L1", "READ_L2", "READ_RESULT_MEMORY", "READ_TOTAL_MEMORY", "RESULT_KO", "RESULT_OK", "WRITE_DRAM", "WRITE_L1", "WRITE_L2", "WRITE_OUTPUT_MEMORY", "WRITE_RESULT_MEMORY"};

GPU_PHYSICALRJ::GPU_PHYSICALRJ():Join("Join", 7, 15,GPU_PHYSICALRJ__SharedNames) {
  COMPUTE_UNIT = new COMPUTE_UNITSAN();
  ModelArray[0] = (BaseModelClass*) COMPUTE_UNIT;
  ModelArray[0]->DefineName("COMPUTE_UNIT");
  TOTAL_MEMORY_MODEL_PHYSICAL = new TOTAL_MEMORY_MODEL_PHYSICALSAN();
  ModelArray[1] = (BaseModelClass*) TOTAL_MEMORY_MODEL_PHYSICAL;
  ModelArray[1]->DefineName("TOTAL_MEMORY_MODEL_PHYSICAL");
  DRAM = new DRAMSAN();
  ModelArray[2] = (BaseModelClass*) DRAM;
  ModelArray[2]->DefineName("DRAM");
  OUTPUT_MEMORY_PHYSICAL = new OUTPUT_MEMORY_PHYSICALSAN();
  ModelArray[3] = (BaseModelClass*) OUTPUT_MEMORY_PHYSICAL;
  ModelArray[3]->DefineName("OUTPUT_MEMORY_PHYSICAL");
  RESULT_MEMORY_MODEL_PHYSICAL = new RESULT_MEMORY_MODEL_PHYSICALSAN();
  ModelArray[4] = (BaseModelClass*) RESULT_MEMORY_MODEL_PHYSICAL;
  ModelArray[4]->DefineName("RESULT_MEMORY_MODEL_PHYSICAL");
  L2_CACHE = new L2_CACHESAN();
  ModelArray[5] = (BaseModelClass*) L2_CACHE;
  ModelArray[5]->DefineName("L2_CACHE");
  L1_CACHE = new L1_CACHESAN();
  ModelArray[6] = (BaseModelClass*) L1_CACHE;
  ModelArray[6]->DefineName("L1_CACHE");

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
    if (TOTAL_MEMORY_MODEL_PHYSICAL->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(TOTAL_MEMORY_MODEL_PHYSICAL->READ_DRAM));
      addSharingInfo(getSharableSVPointer(TOTAL_MEMORY_MODEL_PHYSICAL->READ_DRAM), READ_DRAM, TOTAL_MEMORY_MODEL_PHYSICAL);
    }
    if (DRAM->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(DRAM->READ_DRAM));
      addSharingInfo(getSharableSVPointer(DRAM->READ_DRAM), READ_DRAM, DRAM);
    }
    if (RESULT_MEMORY_MODEL_PHYSICAL->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(RESULT_MEMORY_MODEL_PHYSICAL->READ_DRAM));
      addSharingInfo(getSharableSVPointer(RESULT_MEMORY_MODEL_PHYSICAL->READ_DRAM), READ_DRAM, RESULT_MEMORY_MODEL_PHYSICAL);
    }

    //Shared variable 4
    READ_L1 = new Place("READ_L1");
    addSharedPtr(READ_L1, "READ_L1" );
    if (RESULT_MEMORY_MODEL_PHYSICAL->NumStateVariables > 0) {
      READ_L1->ShareWith(getSharableSVPointer(RESULT_MEMORY_MODEL_PHYSICAL->READ_L1));
      addSharingInfo(getSharableSVPointer(RESULT_MEMORY_MODEL_PHYSICAL->READ_L1), READ_L1, RESULT_MEMORY_MODEL_PHYSICAL);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      READ_L1->ShareWith(getSharableSVPointer(L1_CACHE->READ_L1));
      addSharingInfo(getSharableSVPointer(L1_CACHE->READ_L1), READ_L1, L1_CACHE);
    }

    //Shared variable 5
    READ_L2 = new Place("READ_L2");
    addSharedPtr(READ_L2, "READ_L2" );
    if (TOTAL_MEMORY_MODEL_PHYSICAL->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(TOTAL_MEMORY_MODEL_PHYSICAL->READ_L2));
      addSharingInfo(getSharableSVPointer(TOTAL_MEMORY_MODEL_PHYSICAL->READ_L2), READ_L2, TOTAL_MEMORY_MODEL_PHYSICAL);
    }
    if (RESULT_MEMORY_MODEL_PHYSICAL->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(RESULT_MEMORY_MODEL_PHYSICAL->READ_L2));
      addSharingInfo(getSharableSVPointer(RESULT_MEMORY_MODEL_PHYSICAL->READ_L2), READ_L2, RESULT_MEMORY_MODEL_PHYSICAL);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(L2_CACHE->READ_L2));
      addSharingInfo(getSharableSVPointer(L2_CACHE->READ_L2), READ_L2, L2_CACHE);
    }

    //Shared variable 6
    READ_RESULT_MEMORY = new Place("READ_RESULT_MEMORY");
    addSharedPtr(READ_RESULT_MEMORY, "READ_RESULT_MEMORY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      READ_RESULT_MEMORY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->READ_RESULT_MEMORY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->READ_RESULT_MEMORY), READ_RESULT_MEMORY, COMPUTE_UNIT);
    }
    if (RESULT_MEMORY_MODEL_PHYSICAL->NumStateVariables > 0) {
      READ_RESULT_MEMORY->ShareWith(getSharableSVPointer(RESULT_MEMORY_MODEL_PHYSICAL->READ_RESULT_MEMORY));
      addSharingInfo(getSharableSVPointer(RESULT_MEMORY_MODEL_PHYSICAL->READ_RESULT_MEMORY), READ_RESULT_MEMORY, RESULT_MEMORY_MODEL_PHYSICAL);
    }

    //Shared variable 7
    READ_TOTAL_MEMORY = new Place("READ_TOTAL_MEMORY");
    addSharedPtr(READ_TOTAL_MEMORY, "READ_TOTAL_MEMORY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      READ_TOTAL_MEMORY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->READ_TOTAL_MEMORY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->READ_TOTAL_MEMORY), READ_TOTAL_MEMORY, COMPUTE_UNIT);
    }
    if (TOTAL_MEMORY_MODEL_PHYSICAL->NumStateVariables > 0) {
      READ_TOTAL_MEMORY->ShareWith(getSharableSVPointer(TOTAL_MEMORY_MODEL_PHYSICAL->READ_TOTAL_MEMORY));
      addSharingInfo(getSharableSVPointer(TOTAL_MEMORY_MODEL_PHYSICAL->READ_TOTAL_MEMORY), READ_TOTAL_MEMORY, TOTAL_MEMORY_MODEL_PHYSICAL);
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
    if (OUTPUT_MEMORY_PHYSICAL->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(OUTPUT_MEMORY_PHYSICAL->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(OUTPUT_MEMORY_PHYSICAL->WRITE_DRAM), WRITE_DRAM, OUTPUT_MEMORY_PHYSICAL);
    }
    if (RESULT_MEMORY_MODEL_PHYSICAL->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(RESULT_MEMORY_MODEL_PHYSICAL->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(RESULT_MEMORY_MODEL_PHYSICAL->WRITE_DRAM), WRITE_DRAM, RESULT_MEMORY_MODEL_PHYSICAL);
    }

    //Shared variable 11
    WRITE_L1 = new Place("WRITE_L1");
    addSharedPtr(WRITE_L1, "WRITE_L1" );
    if (RESULT_MEMORY_MODEL_PHYSICAL->NumStateVariables > 0) {
      WRITE_L1->ShareWith(getSharableSVPointer(RESULT_MEMORY_MODEL_PHYSICAL->WRITE_L1));
      addSharingInfo(getSharableSVPointer(RESULT_MEMORY_MODEL_PHYSICAL->WRITE_L1), WRITE_L1, RESULT_MEMORY_MODEL_PHYSICAL);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      WRITE_L1->ShareWith(getSharableSVPointer(L1_CACHE->WRITE_L1));
      addSharingInfo(getSharableSVPointer(L1_CACHE->WRITE_L1), WRITE_L1, L1_CACHE);
    }

    //Shared variable 12
    WRITE_L2 = new Place("WRITE_L2");
    addSharedPtr(WRITE_L2, "WRITE_L2" );
    if (RESULT_MEMORY_MODEL_PHYSICAL->NumStateVariables > 0) {
      WRITE_L2->ShareWith(getSharableSVPointer(RESULT_MEMORY_MODEL_PHYSICAL->WRITE_L2));
      addSharingInfo(getSharableSVPointer(RESULT_MEMORY_MODEL_PHYSICAL->WRITE_L2), WRITE_L2, RESULT_MEMORY_MODEL_PHYSICAL);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      WRITE_L2->ShareWith(getSharableSVPointer(L2_CACHE->WRITE_L2));
      addSharingInfo(getSharableSVPointer(L2_CACHE->WRITE_L2), WRITE_L2, L2_CACHE);
    }

    //Shared variable 13
    WRITE_OUTPUT_MEMORY = new Place("WRITE_OUTPUT_MEMORY");
    addSharedPtr(WRITE_OUTPUT_MEMORY, "WRITE_OUTPUT_MEMORY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      WRITE_OUTPUT_MEMORY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->WRITE_OUTPUT_MEMORY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->WRITE_OUTPUT_MEMORY), WRITE_OUTPUT_MEMORY, COMPUTE_UNIT);
    }
    if (OUTPUT_MEMORY_PHYSICAL->NumStateVariables > 0) {
      WRITE_OUTPUT_MEMORY->ShareWith(getSharableSVPointer(OUTPUT_MEMORY_PHYSICAL->WRITE_OUTPUT_MEMORY));
      addSharingInfo(getSharableSVPointer(OUTPUT_MEMORY_PHYSICAL->WRITE_OUTPUT_MEMORY), WRITE_OUTPUT_MEMORY, OUTPUT_MEMORY_PHYSICAL);
    }

    //Shared variable 14
    WRITE_RESULT_MEMORY = new Place("WRITE_RESULT_MEMORY");
    addSharedPtr(WRITE_RESULT_MEMORY, "WRITE_RESULT_MEMORY" );
    if (COMPUTE_UNIT->NumStateVariables > 0) {
      WRITE_RESULT_MEMORY->ShareWith(getSharableSVPointer(COMPUTE_UNIT->WRITE_RESULT_MEMORY));
      addSharingInfo(getSharableSVPointer(COMPUTE_UNIT->WRITE_RESULT_MEMORY), WRITE_RESULT_MEMORY, COMPUTE_UNIT);
    }
    if (RESULT_MEMORY_MODEL_PHYSICAL->NumStateVariables > 0) {
      WRITE_RESULT_MEMORY->ShareWith(getSharableSVPointer(RESULT_MEMORY_MODEL_PHYSICAL->WRITE_RESULT_MEMORY));
      addSharingInfo(getSharableSVPointer(RESULT_MEMORY_MODEL_PHYSICAL->WRITE_RESULT_MEMORY), WRITE_RESULT_MEMORY, RESULT_MEMORY_MODEL_PHYSICAL);
    }

  }

  Setup();
}

GPU_PHYSICALRJ::~GPU_PHYSICALRJ() {
  if (!AllChildrenEmpty()) {
    delete KO_READ;
    delete MEM_OP_COMPLETE;
    delete OK_READ;
    delete READ_DRAM;
    delete READ_L1;
    delete READ_L2;
    delete READ_RESULT_MEMORY;
    delete READ_TOTAL_MEMORY;
    delete RESULT_KO;
    delete RESULT_OK;
    delete WRITE_DRAM;
    delete WRITE_L1;
    delete WRITE_L2;
    delete WRITE_OUTPUT_MEMORY;
    delete WRITE_RESULT_MEMORY;
  }
  delete COMPUTE_UNIT;
  delete TOTAL_MEMORY_MODEL_PHYSICAL;
  delete DRAM;
  delete OUTPUT_MEMORY_PHYSICAL;
  delete RESULT_MEMORY_MODEL_PHYSICAL;
  delete L2_CACHE;
  delete L1_CACHE;
}
