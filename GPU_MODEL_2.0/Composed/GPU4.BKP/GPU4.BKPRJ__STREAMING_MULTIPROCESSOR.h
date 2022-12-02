#ifndef GPU4.BKPRJ__STREAMING_MULTIPROCESSOR_H_
#define GPU4.BKPRJ__STREAMING_MULTIPROCESSOR_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Composed/GPU4.BKP/GPU4.BKPRJ__PROCESSOR.h"
#include "Atomic/L1_CACHE/L1_CACHESAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"

class GPU4.BKPRJ__STREAMING_MULTIPROCESSOR: public Join {
 public:
  GPU4.BKPRJ__PROCESSOR * PROCESSOR;
  L1_CACHESAN * L1_CACHE;
  Place * KO_READ;
  Place * MEM_OP_COMPLETE;
  Place * OK_READ;
  Place * READ_DRAM;
  Place * READ_L1;
  Place * READ_L2;
  Place * RESULT_KO;
  Place * RESULT_OK;
  Place * WRITE_DRAM;
  Place * WRITE_L1;
  Place * WRITE_L2;

  GPU4.BKPRJ__STREAMING_MULTIPROCESSOR();
  ~GPU4.BKPRJ__STREAMING_MULTIPROCESSOR();
};

#endif
