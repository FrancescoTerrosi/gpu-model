#include "Composed/GPU5/GPU5RJ__STREAMING_MULTIPROCESSOR.h"
char * GPU5RJ__STREAMING_MULTIPROCESSOR__SharedNames[] = {"KO_READ", "MEM_OP_COMPLETE", "OK_READ", "READ_DRAM", "READ_L1", "READ_L2", "RESULT_KO", "RESULT_OK", "WRITE_DRAM", "WRITE_L1", "WRITE_L2"};

GPU5RJ__STREAMING_MULTIPROCESSOR::GPU5RJ__STREAMING_MULTIPROCESSOR():Join("STREAMING_MULTIPROCESSOR", 2, 11,GPU5RJ__STREAMING_MULTIPROCESSOR__SharedNames) {
  PROCESSOR_REP = new GPU5RJ__PROCESSOR_REP();
  ModelArray[0] = (BaseModelClass*) PROCESSOR_REP;
  ModelArray[0]->DefineName("PROCESSOR_REP");
  L1_CACHE = new L1_CACHESAN();
  ModelArray[1] = (BaseModelClass*) L1_CACHE;
  ModelArray[1]->DefineName("L1_CACHE");

  SetupActions();
  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************  State sharing info  **************
    //Shared variable 0
    KO_READ = new Place("KO_READ");
    addSharedPtr(KO_READ, "KO_READ" );
    if (PROCESSOR_REP->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(PROCESSOR_REP->KO_READ));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP->KO_READ), KO_READ, PROCESSOR_REP);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      KO_READ->ShareWith(getSharableSVPointer(L1_CACHE->KO_READ));
      addSharingInfo(getSharableSVPointer(L1_CACHE->KO_READ), KO_READ, L1_CACHE);
    }

    //Shared variable 1
    MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE");
    addSharedPtr(MEM_OP_COMPLETE, "MEM_OP_COMPLETE" );
    if (PROCESSOR_REP->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(PROCESSOR_REP->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP->MEM_OP_COMPLETE), MEM_OP_COMPLETE, PROCESSOR_REP);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      MEM_OP_COMPLETE->ShareWith(getSharableSVPointer(L1_CACHE->MEM_OP_COMPLETE));
      addSharingInfo(getSharableSVPointer(L1_CACHE->MEM_OP_COMPLETE), MEM_OP_COMPLETE, L1_CACHE);
    }

    //Shared variable 2
    OK_READ = new Place("OK_READ");
    addSharedPtr(OK_READ, "OK_READ" );
    if (PROCESSOR_REP->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(PROCESSOR_REP->OK_READ));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP->OK_READ), OK_READ, PROCESSOR_REP);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      OK_READ->ShareWith(getSharableSVPointer(L1_CACHE->OK_READ));
      addSharingInfo(getSharableSVPointer(L1_CACHE->OK_READ), OK_READ, L1_CACHE);
    }

    //Shared variable 3
    READ_DRAM = new Place("READ_DRAM");
    addSharedPtr(READ_DRAM, "READ_DRAM" );
    if (PROCESSOR_REP->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(PROCESSOR_REP->READ_DRAM));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP->READ_DRAM), READ_DRAM, PROCESSOR_REP);
    }

    //Shared variable 4
    READ_L1 = new Place("READ_L1");
    addSharedPtr(READ_L1, "READ_L1" );
    if (PROCESSOR_REP->NumStateVariables > 0) {
      READ_L1->ShareWith(getSharableSVPointer(PROCESSOR_REP->READ_L1));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP->READ_L1), READ_L1, PROCESSOR_REP);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      READ_L1->ShareWith(getSharableSVPointer(L1_CACHE->READ_L1));
      addSharingInfo(getSharableSVPointer(L1_CACHE->READ_L1), READ_L1, L1_CACHE);
    }

    //Shared variable 5
    READ_L2 = new Place("READ_L2");
    addSharedPtr(READ_L2, "READ_L2" );
    if (PROCESSOR_REP->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(PROCESSOR_REP->READ_L2));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP->READ_L2), READ_L2, PROCESSOR_REP);
    }

    //Shared variable 6
    RESULT_KO = new Place("RESULT_KO");
    addSharedPtr(RESULT_KO, "RESULT_KO" );
    if (PROCESSOR_REP->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(PROCESSOR_REP->RESULT_KO));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP->RESULT_KO), RESULT_KO, PROCESSOR_REP);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      RESULT_KO->ShareWith(getSharableSVPointer(L1_CACHE->RESULT_KO));
      addSharingInfo(getSharableSVPointer(L1_CACHE->RESULT_KO), RESULT_KO, L1_CACHE);
    }

    //Shared variable 7
    RESULT_OK = new Place("RESULT_OK");
    addSharedPtr(RESULT_OK, "RESULT_OK" );
    if (PROCESSOR_REP->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(PROCESSOR_REP->RESULT_OK));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP->RESULT_OK), RESULT_OK, PROCESSOR_REP);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      RESULT_OK->ShareWith(getSharableSVPointer(L1_CACHE->RESULT_OK));
      addSharingInfo(getSharableSVPointer(L1_CACHE->RESULT_OK), RESULT_OK, L1_CACHE);
    }

    //Shared variable 8
    WRITE_DRAM = new Place("WRITE_DRAM");
    addSharedPtr(WRITE_DRAM, "WRITE_DRAM" );
    if (PROCESSOR_REP->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(PROCESSOR_REP->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP->WRITE_DRAM), WRITE_DRAM, PROCESSOR_REP);
    }

    //Shared variable 9
    WRITE_L1 = new Place("WRITE_L1");
    addSharedPtr(WRITE_L1, "WRITE_L1" );
    if (PROCESSOR_REP->NumStateVariables > 0) {
      WRITE_L1->ShareWith(getSharableSVPointer(PROCESSOR_REP->WRITE_L1));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP->WRITE_L1), WRITE_L1, PROCESSOR_REP);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      WRITE_L1->ShareWith(getSharableSVPointer(L1_CACHE->WRITE_L1));
      addSharingInfo(getSharableSVPointer(L1_CACHE->WRITE_L1), WRITE_L1, L1_CACHE);
    }

    //Shared variable 10
    WRITE_L2 = new Place("WRITE_L2");
    addSharedPtr(WRITE_L2, "WRITE_L2" );
    if (PROCESSOR_REP->NumStateVariables > 0) {
      WRITE_L2->ShareWith(getSharableSVPointer(PROCESSOR_REP->WRITE_L2));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP->WRITE_L2), WRITE_L2, PROCESSOR_REP);
    }

  }

  Setup();
}

GPU5RJ__STREAMING_MULTIPROCESSOR::~GPU5RJ__STREAMING_MULTIPROCESSOR() {
  if (!AllChildrenEmpty()) {
    delete KO_READ;
    delete MEM_OP_COMPLETE;
    delete OK_READ;
    delete READ_DRAM;
    delete READ_L1;
    delete READ_L2;
    delete RESULT_KO;
    delete RESULT_OK;
    delete WRITE_DRAM;
    delete WRITE_L1;
    delete WRITE_L2;
  }
  delete PROCESSOR_REP;
  delete L1_CACHE;
}
