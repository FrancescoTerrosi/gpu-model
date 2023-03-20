#ifndef GPU5RJ__DEVICE_H_
#define GPU5RJ__DEVICE_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Composed/GPU5/GPU5RJ__STREAMING_MULTIPROCESSOR.h"
#include "Atomic/DRAM/DRAMSAN.h"
#include "Atomic/L2_CACHE/L2_CACHESAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;

class GPU5RJ__DEVICE: public Join {
 public:
  GPU5RJ__STREAMING_MULTIPROCESSOR * STREAMING_MULTIPROCESSOR;
  DRAMSAN * DRAM;
  L2_CACHESAN * L2_CACHE;
  Place * KO_CONTENT;
  Place * MEMORY_KO;
  Place * MEMORY_OK;
  Place * MEM_OP_COMPLETE;
  Place * OK_CONTENT;
  Place * READ_DRAM;
  Place * READ_L2;
  Place * RESULT_KO;
  Place * RESULT_OK;
  Place * WRITE_DRAM;
  Place * WRITE_L2;

  GPU5RJ__DEVICE();
  ~GPU5RJ__DEVICE();
};

#endif
