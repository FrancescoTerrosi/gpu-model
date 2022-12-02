#ifndef GPU_AVERAGE_BKPRJ__STREAMING_MULTIPROCESSOR_H_
#define GPU_AVERAGE_BKPRJ__STREAMING_MULTIPROCESSOR_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Composed/GPU_AVERAGE_BKP/GPU_AVERAGE_BKPRJ__Join1.h"
#include "Atomic/L1_CACHE/L1_CACHESAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"

class GPU_AVERAGE_BKPRJ__STREAMING_MULTIPROCESSOR: public Join {
 public:
  GPU_AVERAGE_BKPRJ__Join1 * Join1;
  L1_CACHESAN * L1_CACHE;
  Place * INSTRUCTION_READY;
  Place * KO_READ;
  Place * MEM_OP_COMPLETE;
  Place * OK_READ;
  Place * READ_L1;
  Place * RESULT_KO;
  Place * RESULT_OK;
  Place * WRITE_L1;

  GPU_AVERAGE_BKPRJ__STREAMING_MULTIPROCESSOR();
  ~GPU_AVERAGE_BKPRJ__STREAMING_MULTIPROCESSOR();
};

#endif
