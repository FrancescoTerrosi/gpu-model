#include "Composed/GPU5/GPU5RJ__DEVICE.h"
char * GPU5RJ__DEVICE__SharedNames[] = {"KO_CONTENT", "MEMORY_KO", "MEMORY_OK", "MEM_OP_COMPLETE", "OK_CONTENT", "READ_DRAM", "READ_L2", "RESULT_KO", "RESULT_OK", "WRITE_DRAM", "WRITE_L2"};

GPU5RJ__DEVICE::GPU5RJ__DEVICE():Join("DEVICE", 3, 11,GPU5RJ__DEVICE__SharedNames) {
  STREAMING_MULTIPROCESSOR = new GPU5RJ__STREAMING_MULTIPROCESSOR();
  ModelArray[0] = (BaseModelClass*) STREAMING_MULTIPROCESSOR;
  ModelArray[0]->DefineName("STREAMING_MULTIPROCESSOR");
  DRAM = new DRAMSAN();
  ModelArray[1] = (BaseModelClass*) DRAM;
  ModelArray[1]->DefineName("DRAM");
  L2_CACHE = new L2_CACHESAN();
  ModelArray[2] = (BaseModelClass*) L2_CACHE;
  ModelArray[2]->DefineName("L2_CACHE");

  SetupActions();
  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************  State sharing info  **************
    //Shared variable 0
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

    //Shared variable 1
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

    //Shared variable 2
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

    //Shared variable 3
    MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE");
    addSharedPtr(MEM_OP_COMPLETE, "MEM_OP_COMPLETE" );
    if (STREAMING_MULTIPROCESSOR->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR->MEM_OP_COMPLETE), MEM_OP_COMPLETE, STREAMING_MULTIPROCESSOR);
    }
    if (DRAM->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(DRAM->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(DRAM->MEM_OP_COMPLETE), MEM_OP_COMPLETE, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(L2_CACHE->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(L2_CACHE->MEM_OP_COMPLETE), MEM_OP_COMPLETE, L2_CACHE);
    }

    //Shared variable 4
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

    //Shared variable 5
    READ_DRAM = new Place("READ_DRAM");
    addSharedPtr(READ_DRAM, "READ_DRAM" );
    if (STREAMING_MULTIPROCESSOR->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR->READ_DRAM));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR->READ_DRAM), READ_DRAM, STREAMING_MULTIPROCESSOR);
    }
    if (DRAM->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(DRAM->READ_DRAM));
      addSharingInfo(getSharableSVPointer(DRAM->READ_DRAM), READ_DRAM, DRAM);
    }

    //Shared variable 6
    READ_L2 = new Place("READ_L2");
    addSharedPtr(READ_L2, "READ_L2" );
    if (STREAMING_MULTIPROCESSOR->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR->READ_L2));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR->READ_L2), READ_L2, STREAMING_MULTIPROCESSOR);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(L2_CACHE->READ_L2));
      addSharingInfo(getSharableSVPointer(L2_CACHE->READ_L2), READ_L2, L2_CACHE);
    }

    //Shared variable 7
    RESULT_KO = new Place("RESULT_KO");
    addSharedPtr(RESULT_KO, "RESULT_KO" );
    if (STREAMING_MULTIPROCESSOR->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR->RESULT_KO));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR->RESULT_KO), RESULT_KO, STREAMING_MULTIPROCESSOR);
    }
    if (DRAM->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(DRAM->RESULT_KO));
      addSharingInfo(getSharableSVPointer(DRAM->RESULT_KO), RESULT_KO, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(L2_CACHE->RESULT_KO));
      addSharingInfo(getSharableSVPointer(L2_CACHE->RESULT_KO), RESULT_KO, L2_CACHE);
    }

    //Shared variable 8
    RESULT_OK = new Place("RESULT_OK");
    addSharedPtr(RESULT_OK, "RESULT_OK" );
    if (STREAMING_MULTIPROCESSOR->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR->RESULT_OK));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR->RESULT_OK), RESULT_OK, STREAMING_MULTIPROCESSOR);
    }
    if (DRAM->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(DRAM->RESULT_OK));
      addSharingInfo(getSharableSVPointer(DRAM->RESULT_OK), RESULT_OK, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(L2_CACHE->RESULT_OK));
      addSharingInfo(getSharableSVPointer(L2_CACHE->RESULT_OK), RESULT_OK, L2_CACHE);
    }

    //Shared variable 9
    WRITE_DRAM = new Place("WRITE_DRAM");
    addSharedPtr(WRITE_DRAM, "WRITE_DRAM" );
    if (STREAMING_MULTIPROCESSOR->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR->WRITE_DRAM), WRITE_DRAM, STREAMING_MULTIPROCESSOR);
    }
    if (DRAM->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(DRAM->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(DRAM->WRITE_DRAM), WRITE_DRAM, DRAM);
    }

    //Shared variable 10
    WRITE_L2 = new Place("WRITE_L2");
    addSharedPtr(WRITE_L2, "WRITE_L2" );
    if (STREAMING_MULTIPROCESSOR->NumStateVariables > 0) {
      WRITE_L2->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR->WRITE_L2));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR->WRITE_L2), WRITE_L2, STREAMING_MULTIPROCESSOR);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      WRITE_L2->ShareWith(getSharableSVPointer(L2_CACHE->WRITE_L2));
      addSharingInfo(getSharableSVPointer(L2_CACHE->WRITE_L2), WRITE_L2, L2_CACHE);
    }

  }

  Setup();
}

GPU5RJ__DEVICE::~GPU5RJ__DEVICE() {
  if (!AllChildrenEmpty()) {
    delete KO_CONTENT;
    delete MEMORY_KO;
    delete MEMORY_OK;
    delete MEM_OP_COMPLETE;
    delete OK_CONTENT;
    delete READ_DRAM;
    delete READ_L2;
    delete RESULT_KO;
    delete RESULT_OK;
    delete WRITE_DRAM;
    delete WRITE_L2;
  }
  delete STREAMING_MULTIPROCESSOR;
  delete DRAM;
  delete L2_CACHE;
}
