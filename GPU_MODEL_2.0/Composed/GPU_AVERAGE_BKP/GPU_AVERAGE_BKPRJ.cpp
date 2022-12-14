#include "Composed/GPU_AVERAGE_BKP/GPU_AVERAGE_BKPRJ.h"
char * GPU_AVERAGE_BKPRJ__SharedNames[] = {"INSTRUCTION_READY", "KO_CONTENT", "KO_READ", "MEMORY_KO", "MEMORY_OK", "MEM_OP_COMPLETE", "OK_CONTENT", "OK_READ", "RESULT_KO", "RESULT_OK"};

GPU_AVERAGE_BKPRJ::GPU_AVERAGE_BKPRJ():Join("GPU", 3, 10,GPU_AVERAGE_BKPRJ__SharedNames) {
  STREAMING_MULTIPROCESSOR = new GPU_AVERAGE_BKPRJ__STREAMING_MULTIPROCESSOR();
  ModelArray[0] = (BaseModelClass*) STREAMING_MULTIPROCESSOR;
  ModelArray[0]->DefineName("STREAMING_MULTIPROCESSOR");
  L2_CACHE = new L2_CACHESAN();
  ModelArray[1] = (BaseModelClass*) L2_CACHE;
  ModelArray[1]->DefineName("L2_CACHE");
  DRAM = new DRAMSAN();
  ModelArray[2] = (BaseModelClass*) DRAM;
  ModelArray[2]->DefineName("DRAM");

  SetupActions();
  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************  State sharing info  **************
    //Shared variable 0
    INSTRUCTION_READY = new Place("INSTRUCTION_READY");
    addSharedPtr(INSTRUCTION_READY, "INSTRUCTION_READY" );
    if (STREAMING_MULTIPROCESSOR->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR->INSTRUCTION_READY), INSTRUCTION_READY, STREAMING_MULTIPROCESSOR);
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
    KO_READ = new Place("KO_READ");
    addSharedPtr(KO_READ, "KO_READ" );
    if (DRAM->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(DRAM->KO_READ));
      addSharingInfo(getSharableSVPointer(DRAM->KO_READ), KO_READ, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(L2_CACHE->KO_READ));
      addSharingInfo(getSharableSVPointer(L2_CACHE->KO_READ), KO_READ, L2_CACHE);
    }
    if (STREAMING_MULTIPROCESSOR->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR->KO_READ));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR->KO_READ), KO_READ, STREAMING_MULTIPROCESSOR);
    }

    //Shared variable 3
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

    //Shared variable 4
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

    //Shared variable 5
    MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE");
    addSharedPtr(MEM_OP_COMPLETE, "MEM_OP_COMPLETE" );
    if (DRAM->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(DRAM->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(DRAM->MEM_OP_COMPLETE), MEM_OP_COMPLETE, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(L2_CACHE->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(L2_CACHE->MEM_OP_COMPLETE), MEM_OP_COMPLETE, L2_CACHE);
    }
    if (STREAMING_MULTIPROCESSOR->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR->MEM_OP_COMPLETE), MEM_OP_COMPLETE, STREAMING_MULTIPROCESSOR);
    }

    //Shared variable 6
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

    //Shared variable 7
    OK_READ = new Place("OK_READ");
    addSharedPtr(OK_READ, "OK_READ" );
    if (DRAM->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(DRAM->OK_READ));
      addSharingInfo(getSharableSVPointer(DRAM->OK_READ), OK_READ, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(L2_CACHE->OK_READ));
      addSharingInfo(getSharableSVPointer(L2_CACHE->OK_READ), OK_READ, L2_CACHE);
    }
    if (STREAMING_MULTIPROCESSOR->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR->OK_READ));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR->OK_READ), OK_READ, STREAMING_MULTIPROCESSOR);
    }

    //Shared variable 8
    RESULT_KO = new Place("RESULT_KO");
    addSharedPtr(RESULT_KO, "RESULT_KO" );
    if (DRAM->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(DRAM->RESULT_KO));
      addSharingInfo(getSharableSVPointer(DRAM->RESULT_KO), RESULT_KO, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(L2_CACHE->RESULT_KO));
      addSharingInfo(getSharableSVPointer(L2_CACHE->RESULT_KO), RESULT_KO, L2_CACHE);
    }
    if (STREAMING_MULTIPROCESSOR->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR->RESULT_KO));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR->RESULT_KO), RESULT_KO, STREAMING_MULTIPROCESSOR);
    }

    //Shared variable 9
    RESULT_OK = new Place("RESULT_OK");
    addSharedPtr(RESULT_OK, "RESULT_OK" );
    if (DRAM->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(DRAM->RESULT_OK));
      addSharingInfo(getSharableSVPointer(DRAM->RESULT_OK), RESULT_OK, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(L2_CACHE->RESULT_OK));
      addSharingInfo(getSharableSVPointer(L2_CACHE->RESULT_OK), RESULT_OK, L2_CACHE);
    }
    if (STREAMING_MULTIPROCESSOR->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR->RESULT_OK));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR->RESULT_OK), RESULT_OK, STREAMING_MULTIPROCESSOR);
    }

  }

  Setup();
}

GPU_AVERAGE_BKPRJ::~GPU_AVERAGE_BKPRJ() {
  if (!AllChildrenEmpty()) {
    delete INSTRUCTION_READY;
    delete KO_CONTENT;
    delete KO_READ;
    delete MEMORY_KO;
    delete MEMORY_OK;
    delete MEM_OP_COMPLETE;
    delete OK_CONTENT;
    delete OK_READ;
    delete RESULT_KO;
    delete RESULT_OK;
  }
  delete STREAMING_MULTIPROCESSOR;
  delete L2_CACHE;
  delete DRAM;
}
