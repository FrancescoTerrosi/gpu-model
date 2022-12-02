#ifndef GPU_AVERAGERJ_H_
#define GPU_AVERAGERJ_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Composed/GPU_AVERAGE/GPU_AVERAGERJ__STREAMING_MULTIPROCESSOR.h"
#include "Atomic/L2_CACHE/L2_CACHESAN.h"
#include "Atomic/DRAM/DRAMSAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"

class GPU_AVERAGERJ: public Join {
 public:
  GPU_AVERAGERJ__STREAMING_MULTIPROCESSOR * STREAMING_MULTIPROCESSOR;
  L2_CACHESAN * L2_CACHE;
  DRAMSAN * DRAM;
  Place * INSTRUCTION_READY;
  Place * KO_CONTENT;
  Place * KO_READ;
  Place * MEMORY_KO;
  Place * MEMORY_OK;
  Place * MEM_OP_COMPLETE;
  Place * OK_CONTENT;
  Place * OK_READ;
  Place * RESULT_KO;
  Place * RESULT_OK;

  GPU_AVERAGERJ();
  ~GPU_AVERAGERJ();
};

#endif
