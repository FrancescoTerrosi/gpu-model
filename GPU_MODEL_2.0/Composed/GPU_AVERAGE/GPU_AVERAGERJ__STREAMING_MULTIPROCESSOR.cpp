#include "Composed/GPU_AVERAGE/GPU_AVERAGERJ__STREAMING_MULTIPROCESSOR.h"
char * GPU_AVERAGERJ__STREAMING_MULTIPROCESSOR__SharedNames[] = {"INSTRUCTION_READY", "KO_READ", "MEM_OP_COMPLETE", "OK_READ", "READ_L1", "RESULT_KO", "RESULT_OK", "WRITE_L1"};

GPU_AVERAGERJ__STREAMING_MULTIPROCESSOR::GPU_AVERAGERJ__STREAMING_MULTIPROCESSOR():Join("STREAMING_MULTIPROCESSOR", 2, 8,GPU_AVERAGERJ__STREAMING_MULTIPROCESSOR__SharedNames) {
  Join1 = new GPU_AVERAGERJ__Join1();
  ModelArray[0] = (BaseModelClass*) Join1;
  ModelArray[0]->DefineName("Join1");
  L1_CACHE = new L1_CACHESAN();
  ModelArray[1] = (BaseModelClass*) L1_CACHE;
  ModelArray[1]->DefineName("L1_CACHE");

  SetupActions();
  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************  State sharing info  **************
    //Shared variable 0
    INSTRUCTION_READY = new Place("INSTRUCTION_READY");
    addSharedPtr(INSTRUCTION_READY, "INSTRUCTION_READY" );
    if (Join1->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(Join1->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(Join1->INSTRUCTION_READY), INSTRUCTION_READY, Join1);
    }

    //Shared variable 1
    KO_READ = new Place("KO_READ");
    addSharedPtr(KO_READ, "KO_READ" );
    if (L1_CACHE->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(L1_CACHE->KO_READ));
      addSharingInfo(getSharableSVPointer(L1_CACHE->KO_READ), KO_READ, L1_CACHE);
    }
    if (Join1->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(Join1->KO_READ));
      addSharingInfo(getSharableSVPointer(Join1->KO_READ), KO_READ, Join1);
    }

    //Shared variable 2
    MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE");
    addSharedPtr(MEM_OP_COMPLETE, "MEM_OP_COMPLETE" );
    if (L1_CACHE->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(L1_CACHE->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(L1_CACHE->MEM_OP_COMPLETE), MEM_OP_COMPLETE, L1_CACHE);
    }
    if (Join1->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(Join1->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(Join1->MEM_OP_COMPLETE), MEM_OP_COMPLETE, Join1);
    }

    //Shared variable 3
    OK_READ = new Place("OK_READ");
    addSharedPtr(OK_READ, "OK_READ" );
    if (L1_CACHE->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(L1_CACHE->OK_READ));
      addSharingInfo(getSharableSVPointer(L1_CACHE->OK_READ), OK_READ, L1_CACHE);
    }
    if (Join1->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(Join1->OK_READ));
      addSharingInfo(getSharableSVPointer(Join1->OK_READ), OK_READ, Join1);
    }

    //Shared variable 4
    READ_L1 = new Place("READ_L1");
    addSharedPtr(READ_L1, "READ_L1" );
    if (Join1->NumStateVariables > 0) {
      READ_L1->ShareWith(getSharableSVPointer(Join1->READ_L1));
      addSharingInfo(getSharableSVPointer(Join1->READ_L1), READ_L1, Join1);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      READ_L1->ShareWith(getSharableSVPointer(L1_CACHE->READ_L1));
      addSharingInfo(getSharableSVPointer(L1_CACHE->READ_L1), READ_L1, L1_CACHE);
    }

    //Shared variable 5
    RESULT_KO = new Place("RESULT_KO");
    addSharedPtr(RESULT_KO, "RESULT_KO" );
    if (L1_CACHE->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(L1_CACHE->RESULT_KO));
      addSharingInfo(getSharableSVPointer(L1_CACHE->RESULT_KO), RESULT_KO, L1_CACHE);
    }
    if (Join1->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(Join1->RESULT_KO));
      addSharingInfo(getSharableSVPointer(Join1->RESULT_KO), RESULT_KO, Join1);
    }

    //Shared variable 6
    RESULT_OK = new Place("RESULT_OK");
    addSharedPtr(RESULT_OK, "RESULT_OK" );
    if (L1_CACHE->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(L1_CACHE->RESULT_OK));
      addSharingInfo(getSharableSVPointer(L1_CACHE->RESULT_OK), RESULT_OK, L1_CACHE);
    }
    if (Join1->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(Join1->RESULT_OK));
      addSharingInfo(getSharableSVPointer(Join1->RESULT_OK), RESULT_OK, Join1);
    }

    //Shared variable 7
    WRITE_L1 = new Place("WRITE_L1");
    addSharedPtr(WRITE_L1, "WRITE_L1" );
    if (L1_CACHE->NumStateVariables > 0) {
      WRITE_L1->ShareWith(getSharableSVPointer(L1_CACHE->WRITE_L1));
      addSharingInfo(getSharableSVPointer(L1_CACHE->WRITE_L1), WRITE_L1, L1_CACHE);
    }
    if (Join1->NumStateVariables > 0) {
      WRITE_L1->ShareWith(getSharableSVPointer(Join1->WRITE_L1));
      addSharingInfo(getSharableSVPointer(Join1->WRITE_L1), WRITE_L1, Join1);
    }

  }

  Setup();
}

GPU_AVERAGERJ__STREAMING_MULTIPROCESSOR::~GPU_AVERAGERJ__STREAMING_MULTIPROCESSOR() {
  if (!AllChildrenEmpty()) {
    delete INSTRUCTION_READY;
    delete KO_READ;
    delete MEM_OP_COMPLETE;
    delete OK_READ;
    delete READ_L1;
    delete RESULT_KO;
    delete RESULT_OK;
    delete WRITE_L1;
  }
  delete Join1;
  delete L1_CACHE;
}
