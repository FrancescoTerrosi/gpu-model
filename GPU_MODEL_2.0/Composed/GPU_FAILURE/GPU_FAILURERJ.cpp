#include "Composed/GPU_FAILURE/GPU_FAILURERJ.h"
char * GPU_FAILURERJ__SharedNames[] = {"INSTRUCTION_READY", "KO_CONTENT", "MEMORY_KO", "MEMORY_OK", "MEM_FAILURE", "OK_CONTENT", "READ_DRAM", "READ_L2", "WRITE_DRAM", "WRITE_L2"};

GPU_FAILURERJ::GPU_FAILURERJ():Join("DEVICE", 4, 10,GPU_FAILURERJ__SharedNames) {
  SM_REP = new GPU_FAILURERJ__SM_REP();
  ModelArray[0] = (BaseModelClass*) SM_REP;
  ModelArray[0]->DefineName("SM_REP");
  STREAMING_MULTIPROCESSOR_FAILURE = new GPU_FAILURERJ__STREAMING_MULTIPROCESSOR_FAILURE();
  ModelArray[1] = (BaseModelClass*) STREAMING_MULTIPROCESSOR_FAILURE;
  ModelArray[1]->DefineName("STREAMING_MULTIPROCESSOR_FAILURE");
  DRAM = new DRAMSAN();
  ModelArray[2] = (BaseModelClass*) DRAM;
  ModelArray[2]->DefineName("DRAM");
  L2_CACHE = new L2_CACHESAN();
  ModelArray[3] = (BaseModelClass*) L2_CACHE;
  ModelArray[3]->DefineName("L2_CACHE");

  SetupActions();
  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************  State sharing info  **************
    //Shared variable 0
    INSTRUCTION_READY = new Place("INSTRUCTION_READY");
    addSharedPtr(INSTRUCTION_READY, "INSTRUCTION_READY" );
    if (SM_REP->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(SM_REP->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(SM_REP->INSTRUCTION_READY), INSTRUCTION_READY, SM_REP);
    }
    if (DRAM->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(DRAM->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(DRAM->INSTRUCTION_READY), INSTRUCTION_READY, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(L2_CACHE->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(L2_CACHE->INSTRUCTION_READY), INSTRUCTION_READY, L2_CACHE);
    }
    if (STREAMING_MULTIPROCESSOR_FAILURE->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR_FAILURE->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR_FAILURE->INSTRUCTION_READY), INSTRUCTION_READY, STREAMING_MULTIPROCESSOR_FAILURE);
    }

    //Shared variable 1
    KO_CONTENT = new Place("KO_CONTENT");
    addSharedPtr(KO_CONTENT, "KO_CONTENT" );
    if (DRAM->NumStateVariables > 0) {
      KO_CONTENT->ShareWith(getSharableSVPointer(DRAM->KO_CONTENT));
      addSharingInfo(getSharableSVPointer(DRAM->KO_CONTENT), KO_CONTENT, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      KO_CONTENT->ShareWith(getSharableSVPointer(L2_CACHE->KO_CONTENT));
      addSharingInfo(getSharableSVPointer(L2_CACHE->KO_CONTENT), KO_CONTENT, L2_CACHE);
    }

    //Shared variable 2
    MEMORY_KO = new Place("MEMORY_KO");
    addSharedPtr(MEMORY_KO, "MEMORY_KO" );
    if (DRAM->NumStateVariables > 0) {
      MEMORY_KO->ShareWith(getSharableSVPointer(DRAM->MEMORY_KO));
      addSharingInfo(getSharableSVPointer(DRAM->MEMORY_KO), MEMORY_KO, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      MEMORY_KO->ShareWith(getSharableSVPointer(L2_CACHE->MEMORY_KO));
      addSharingInfo(getSharableSVPointer(L2_CACHE->MEMORY_KO), MEMORY_KO, L2_CACHE);
    }

    //Shared variable 3
    MEMORY_OK = new Place("MEMORY_OK");
    addSharedPtr(MEMORY_OK, "MEMORY_OK" );
    if (DRAM->NumStateVariables > 0) {
      MEMORY_OK->ShareWith(getSharableSVPointer(DRAM->MEMORY_OK));
      addSharingInfo(getSharableSVPointer(DRAM->MEMORY_OK), MEMORY_OK, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      MEMORY_OK->ShareWith(getSharableSVPointer(L2_CACHE->MEMORY_OK));
      addSharingInfo(getSharableSVPointer(L2_CACHE->MEMORY_OK), MEMORY_OK, L2_CACHE);
    }

    //Shared variable 4
    MEM_FAILURE = new Place("MEM_FAILURE");
    addSharedPtr(MEM_FAILURE, "MEM_FAILURE" );
    if (DRAM->NumStateVariables > 0) {
      MEM_FAILURE->ShareWith(getSharableSVPointer(DRAM->MEM_FAILURE));
      addSharingInfo(getSharableSVPointer(DRAM->MEM_FAILURE), MEM_FAILURE, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      MEM_FAILURE->ShareWith(getSharableSVPointer(L2_CACHE->MEM_FAILURE));
      addSharingInfo(getSharableSVPointer(L2_CACHE->MEM_FAILURE), MEM_FAILURE, L2_CACHE);
    }

    //Shared variable 5
    OK_CONTENT = new Place("OK_CONTENT");
    addSharedPtr(OK_CONTENT, "OK_CONTENT" );
    if (DRAM->NumStateVariables > 0) {
      OK_CONTENT->ShareWith(getSharableSVPointer(DRAM->OK_CONTENT));
      addSharingInfo(getSharableSVPointer(DRAM->OK_CONTENT), OK_CONTENT, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      OK_CONTENT->ShareWith(getSharableSVPointer(L2_CACHE->OK_CONTENT));
      addSharingInfo(getSharableSVPointer(L2_CACHE->OK_CONTENT), OK_CONTENT, L2_CACHE);
    }

    //Shared variable 6
    READ_DRAM = new Place("READ_DRAM");
    addSharedPtr(READ_DRAM, "READ_DRAM" );
    if (SM_REP->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(SM_REP->READ_DRAM));
      addSharingInfo(getSharableSVPointer(SM_REP->READ_DRAM), READ_DRAM, SM_REP);
    }
    if (DRAM->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(DRAM->READ_DRAM));
      addSharingInfo(getSharableSVPointer(DRAM->READ_DRAM), READ_DRAM, DRAM);
    }
    if (STREAMING_MULTIPROCESSOR_FAILURE->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR_FAILURE->READ_DRAM));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR_FAILURE->READ_DRAM), READ_DRAM, STREAMING_MULTIPROCESSOR_FAILURE);
    }

    //Shared variable 7
    READ_L2 = new Place("READ_L2");
    addSharedPtr(READ_L2, "READ_L2" );
    if (SM_REP->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(SM_REP->READ_L2));
      addSharingInfo(getSharableSVPointer(SM_REP->READ_L2), READ_L2, SM_REP);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(L2_CACHE->READ_L2));
      addSharingInfo(getSharableSVPointer(L2_CACHE->READ_L2), READ_L2, L2_CACHE);
    }
    if (STREAMING_MULTIPROCESSOR_FAILURE->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR_FAILURE->READ_L2));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR_FAILURE->READ_L2), READ_L2, STREAMING_MULTIPROCESSOR_FAILURE);
    }

    //Shared variable 8
    WRITE_DRAM = new Place("WRITE_DRAM");
    addSharedPtr(WRITE_DRAM, "WRITE_DRAM" );
    if (SM_REP->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(SM_REP->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(SM_REP->WRITE_DRAM), WRITE_DRAM, SM_REP);
    }
    if (DRAM->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(DRAM->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(DRAM->WRITE_DRAM), WRITE_DRAM, DRAM);
    }
    if (STREAMING_MULTIPROCESSOR_FAILURE->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR_FAILURE->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR_FAILURE->WRITE_DRAM), WRITE_DRAM, STREAMING_MULTIPROCESSOR_FAILURE);
    }

    //Shared variable 9
    WRITE_L2 = new Place("WRITE_L2");
    addSharedPtr(WRITE_L2, "WRITE_L2" );
    if (SM_REP->NumStateVariables > 0) {
      WRITE_L2->ShareWith(getSharableSVPointer(SM_REP->WRITE_L2));
      addSharingInfo(getSharableSVPointer(SM_REP->WRITE_L2), WRITE_L2, SM_REP);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      WRITE_L2->ShareWith(getSharableSVPointer(L2_CACHE->WRITE_L2));
      addSharingInfo(getSharableSVPointer(L2_CACHE->WRITE_L2), WRITE_L2, L2_CACHE);
    }
    if (STREAMING_MULTIPROCESSOR_FAILURE->NumStateVariables > 0) {
      WRITE_L2->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR_FAILURE->WRITE_L2));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR_FAILURE->WRITE_L2), WRITE_L2, STREAMING_MULTIPROCESSOR_FAILURE);
    }

  }

  Setup();
}

GPU_FAILURERJ::~GPU_FAILURERJ() {
  if (!AllChildrenEmpty()) {
    delete INSTRUCTION_READY;
    delete KO_CONTENT;
    delete MEMORY_KO;
    delete MEMORY_OK;
    delete MEM_FAILURE;
    delete OK_CONTENT;
    delete READ_DRAM;
    delete READ_L2;
    delete WRITE_DRAM;
    delete WRITE_L2;
  }
  delete SM_REP;
  delete STREAMING_MULTIPROCESSOR_FAILURE;
  delete DRAM;
  delete L2_CACHE;
}
