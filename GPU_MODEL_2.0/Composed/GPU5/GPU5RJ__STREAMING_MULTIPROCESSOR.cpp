#include "Composed/GPU5/GPU5RJ__STREAMING_MULTIPROCESSOR.h"
char * GPU5RJ__STREAMING_MULTIPROCESSOR__SharedNames[] = {"INSTRUCTION_READY", "MEM_FAILURE", "READ_DRAM", "READ_L1", "READ_L2", "WRITE_DRAM", "WRITE_L1", "WRITE_L2"};

GPU5RJ__STREAMING_MULTIPROCESSOR::GPU5RJ__STREAMING_MULTIPROCESSOR():Join("STREAMING_MULTIPROCESSOR", 2, 8,GPU5RJ__STREAMING_MULTIPROCESSOR__SharedNames) {
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
    INSTRUCTION_READY = new Place("INSTRUCTION_READY");
    addSharedPtr(INSTRUCTION_READY, "INSTRUCTION_READY" );
    if (PROCESSOR_REP->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(PROCESSOR_REP->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP->INSTRUCTION_READY), INSTRUCTION_READY, PROCESSOR_REP);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(L1_CACHE->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(L1_CACHE->INSTRUCTION_READY), INSTRUCTION_READY, L1_CACHE);
    }

    //Shared variable 1
    MEM_FAILURE = new Place("MEM_FAILURE");
    addSharedPtr(MEM_FAILURE, "MEM_FAILURE" );
    if (PROCESSOR_REP->NumStateVariables > 0) {
      MEM_FAILURE->ShareWith(getSharableSVPointer(PROCESSOR_REP->MEM_FAILURE));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP->MEM_FAILURE), MEM_FAILURE, PROCESSOR_REP);
    }
    if (L1_CACHE->NumStateVariables > 0) {
      MEM_FAILURE->ShareWith(getSharableSVPointer(L1_CACHE->MEM_FAILURE));
      addSharingInfo(getSharableSVPointer(L1_CACHE->MEM_FAILURE), MEM_FAILURE, L1_CACHE);
    }

    //Shared variable 2
    READ_DRAM = new Place("READ_DRAM");
    addSharedPtr(READ_DRAM, "READ_DRAM" );
    if (PROCESSOR_REP->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(PROCESSOR_REP->READ_DRAM));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP->READ_DRAM), READ_DRAM, PROCESSOR_REP);
    }

    //Shared variable 3
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

    //Shared variable 4
    READ_L2 = new Place("READ_L2");
    addSharedPtr(READ_L2, "READ_L2" );
    if (PROCESSOR_REP->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(PROCESSOR_REP->READ_L2));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP->READ_L2), READ_L2, PROCESSOR_REP);
    }

    //Shared variable 5
    WRITE_DRAM = new Place("WRITE_DRAM");
    addSharedPtr(WRITE_DRAM, "WRITE_DRAM" );
    if (PROCESSOR_REP->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(PROCESSOR_REP->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP->WRITE_DRAM), WRITE_DRAM, PROCESSOR_REP);
    }

    //Shared variable 6
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

    //Shared variable 7
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
    delete INSTRUCTION_READY;
    delete MEM_FAILURE;
    delete READ_DRAM;
    delete READ_L1;
    delete READ_L2;
    delete WRITE_DRAM;
    delete WRITE_L1;
    delete WRITE_L2;
  }
  delete PROCESSOR_REP;
  delete L1_CACHE;
}
