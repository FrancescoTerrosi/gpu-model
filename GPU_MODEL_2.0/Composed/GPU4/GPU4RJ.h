#ifndef GPU4RJ_H_
#define GPU4RJ_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Composed/GPU4/GPU4RJ__STREAMING_MULTIPROCESSOR.h"
#include "Atomic/DRAM/DRAMSAN.h"
#include "Atomic/L2_CACHE/L2_CACHESAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;

class GPU4RJ: public Join {
 public:
  GPU4RJ__STREAMING_MULTIPROCESSOR * STREAMING_MULTIPROCESSOR;
  DRAMSAN * DRAM;
  L2_CACHESAN * L2_CACHE;
  Place * KO_READ;
  Place * MEM_OP_COMPLETE;
  Place * OK_READ;
  Place * READ_DRAM;
  Place * READ_L2;
  Place * RESULT_KO;
  Place * RESULT_OK;
  Place * WRITE_DRAM;
  Place * WRITE_L2;

  GPU4RJ();
  ~GPU4RJ();
};

#endif
