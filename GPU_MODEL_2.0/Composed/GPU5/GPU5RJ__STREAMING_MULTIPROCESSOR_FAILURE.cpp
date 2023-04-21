#include "Composed/GPU5/GPU5RJ__STREAMING_MULTIPROCESSOR_FAILURE.h"
char * GPU5RJ__STREAMING_MULTIPROCESSOR_FAILURE__SharedNames[] = {"INSTRUCTION_READY", "MEM_FAILURE", "READ_DRAM", "READ_L1", "READ_L2", "WRITE_DRAM", "WRITE_L1", "WRITE_L2"};

GPU5RJ__STREAMING_MULTIPROCESSOR_FAILURE::GPU5RJ__STREAMING_MULTIPROCESSOR_FAILURE():Join("STREAMING_MULTIPROCESSOR_FAILURE", 2, 8,GPU5RJ__STREAMING_MULTIPROCESSOR_FAILURE__SharedNames) {
  L1_CACHE_FAILURE = new L1_CACHESAN();
  ModelArray[0] = (BaseModelClass*) L1_CACHE_FAILURE;
  ModelArray[0]->DefineName("L1_CACHE_FAILURE");
  PROCESSOR_REP_FAILURE = new GPU5RJ__PROCESSOR_REP_FAILURE();
  ModelArray[1] = (BaseModelClass*) PROCESSOR_REP_FAILURE;
  ModelArray[1]->DefineName("PROCESSOR_REP_FAILURE");

  SetupActions();
  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  else {
    //**************  State sharing info  **************
    //Shared variable 0
    INSTRUCTION_READY = new Place("INSTRUCTION_READY");
    addSharedPtr(INSTRUCTION_READY, "INSTRUCTION_READY" );
    if (L1_CACHE_FAILURE->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(L1_CACHE_FAILURE->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(L1_CACHE_FAILURE->INSTRUCTION_READY), INSTRUCTION_READY, L1_CACHE_FAILURE);
    }
    if (PROCESSOR_REP_FAILURE->NumStateVariables > 0) {
      INSTRUCTION_READY->ShareWith(getSharableSVPointer(PROCESSOR_REP_FAILURE->INSTRUCTION_READY));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP_FAILURE->INSTRUCTION_READY), INSTRUCTION_READY, PROCESSOR_REP_FAILURE);
    }

    //Shared variable 1
    MEM_FAILURE = new Place("MEM_FAILURE");
    addSharedPtr(MEM_FAILURE, "MEM_FAILURE" );
    if (L1_CACHE_FAILURE->NumStateVariables > 0) {
      MEM_FAILURE->ShareWith(getSharableSVPointer(L1_CACHE_FAILURE->MEM_FAILURE_COUNT));
      addSharingInfo(getSharableSVPointer(L1_CACHE_FAILURE->MEM_FAILURE_COUNT), MEM_FAILURE, L1_CACHE_FAILURE);
    }
    if (PROCESSOR_REP_FAILURE->NumStateVariables > 0) {
      MEM_FAILURE->ShareWith(getSharableSVPointer(PROCESSOR_REP_FAILURE->MEM_FAILURE));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP_FAILURE->MEM_FAILURE), MEM_FAILURE, PROCESSOR_REP_FAILURE);
    }

    //Shared variable 2
    READ_DRAM = new Place("READ_DRAM");
    addSharedPtr(READ_DRAM, "READ_DRAM" );
    if (PROCESSOR_REP_FAILURE->NumStateVariables > 0) {
      READ_DRAM->ShareWith(getSharableSVPointer(PROCESSOR_REP_FAILURE->READ_DRAM));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP_FAILURE->READ_DRAM), READ_DRAM, PROCESSOR_REP_FAILURE);
    }

    //Shared variable 3
    READ_L1 = new Place("READ_L1");
    addSharedPtr(READ_L1, "READ_L1" );
    if (L1_CACHE_FAILURE->NumStateVariables > 0) {
      READ_L1->ShareWith(getSharableSVPointer(L1_CACHE_FAILURE->READ_L1));
      addSharingInfo(getSharableSVPointer(L1_CACHE_FAILURE->READ_L1), READ_L1, L1_CACHE_FAILURE);
    }
    if (PROCESSOR_REP_FAILURE->NumStateVariables > 0) {
      READ_L1->ShareWith(getSharableSVPointer(PROCESSOR_REP_FAILURE->READ_L1));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP_FAILURE->READ_L1), READ_L1, PROCESSOR_REP_FAILURE);
    }

    //Shared variable 4
    READ_L2 = new Place("READ_L2");
    addSharedPtr(READ_L2, "READ_L2" );
    if (PROCESSOR_REP_FAILURE->NumStateVariables > 0) {
      READ_L2->ShareWith(getSharableSVPointer(PROCESSOR_REP_FAILURE->READ_L2));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP_FAILURE->READ_L2), READ_L2, PROCESSOR_REP_FAILURE);
    }

    //Shared variable 5
    WRITE_DRAM = new Place("WRITE_DRAM");
    addSharedPtr(WRITE_DRAM, "WRITE_DRAM" );
    if (PROCESSOR_REP_FAILURE->NumStateVariables > 0) {
      WRITE_DRAM->ShareWith(getSharableSVPointer(PROCESSOR_REP_FAILURE->WRITE_DRAM));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP_FAILURE->WRITE_DRAM), WRITE_DRAM, PROCESSOR_REP_FAILURE);
    }

    //Shared variable 6
    WRITE_L1 = new Place("WRITE_L1");
    addSharedPtr(WRITE_L1, "WRITE_L1" );
    if (L1_CACHE_FAILURE->NumStateVariables > 0) {
      WRITE_L1->ShareWith(getSharableSVPointer(L1_CACHE_FAILURE->WRITE_L1));
      addSharingInfo(getSharableSVPointer(L1_CACHE_FAILURE->WRITE_L1), WRITE_L1, L1_CACHE_FAILURE);
    }
    if (PROCESSOR_REP_FAILURE->NumStateVariables > 0) {
      WRITE_L1->ShareWith(getSharableSVPointer(PROCESSOR_REP_FAILURE->WRITE_L1));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP_FAILURE->WRITE_L1), WRITE_L1, PROCESSOR_REP_FAILURE);
    }

    //Shared variable 7
    WRITE_L2 = new Place("WRITE_L2");
    addSharedPtr(WRITE_L2, "WRITE_L2" );
    if (PROCESSOR_REP_FAILURE->NumStateVariables > 0) {
      WRITE_L2->ShareWith(getSharableSVPointer(PROCESSOR_REP_FAILURE->WRITE_L2));
      addSharingInfo(getSharableSVPointer(PROCESSOR_REP_FAILURE->WRITE_L2), WRITE_L2, PROCESSOR_REP_FAILURE);
    }

  }

  Setup();
}

GPU5RJ__STREAMING_MULTIPROCESSOR_FAILURE::~GPU5RJ__STREAMING_MULTIPROCESSOR_FAILURE() {
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
  delete L1_CACHE_FAILURE;
  delete PROCESSOR_REP_FAILURE;
}
