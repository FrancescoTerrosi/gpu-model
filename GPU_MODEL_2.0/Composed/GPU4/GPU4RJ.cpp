#include "Composed/GPU4/GPU4RJ.h"
char * GPU4RJ__SharedNames[] = {"KO_READ", "MEM_OP_COMPLETE", "OK_READ", "READ_DRAM", "READ_L2", "RESULT_KO", "RESULT_OK", "WRITE_DRAM", "WRITE_L2"};

GPU4RJ::GPU4RJ():Join("DEVICE", 3, 9,GPU4RJ__SharedNames) {
  STREAMING_MULTIPROCESSOR = new GPU4RJ__STREAMING_MULTIPROCESSOR();
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
    KO_READ = new Place("KO_READ");
    addSharedPtr(KO_READ, "KO_READ" );
    if (STREAMING_MULTIPROCESSOR->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR->KO_READ));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR->KO_READ), KO_READ, STREAMING_MULTIPROCESSOR);
    }
    if (DRAM->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(DRAM->KO_READ));
      addSharingInfo(getSharableSVPointer(DRAM->KO_READ), KO_READ, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(L2_CACHE->KO_READ));
      addSharingInfo(getSharableSVPointer(L2_CACHE->KO_READ), KO_READ, L2_CACHE);
    }

    //Shared variable 1
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

    //Shared variable 2
    OK_READ = new Place("OK_READ");
    addSharedPtr(OK_READ, "OK_READ" );
    if (STREAMING_MULTIPROCESSOR->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(STREAMING_MULTIPROCESSOR->OK_READ));
      addSharingInfo(getSharableSVPointer(STREAMING_MULTIPROCESSOR->OK_READ), OK_READ, STREAMING_MULTIPROCESSOR);
    }
    if (DRAM->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(DRAM->OK_READ));
      addSharingInfo(getSharableSVPointer(DRAM->OK_READ), OK_READ, DRAM);
    }
    if (L2_CACHE->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(L2_CACHE->OK_READ));
      addSharingInfo(getSharableSVPointer(L2_CACHE->OK_READ), OK_READ, L2_CACHE);
    }

    //Shared variable 3
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

    //Shared variable 4
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

    //Shared variable 5
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

    //Shared variable 6
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

    //Shared variable 7
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

    //Shared variable 8
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

GPU4RJ::~GPU4RJ() {
  if (!AllChildrenEmpty()) {
    delete KO_READ;
    delete MEM_OP_COMPLETE;
    delete OK_READ;
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
