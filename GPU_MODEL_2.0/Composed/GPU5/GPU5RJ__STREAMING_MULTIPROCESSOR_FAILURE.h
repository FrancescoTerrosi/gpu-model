#ifndef GPU5RJ__STREAMING_MULTIPROCESSOR_FAILURE_H_
#define GPU5RJ__STREAMING_MULTIPROCESSOR_FAILURE_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Atomic/L1_CACHE/L1_CACHESAN.h"
#include "Composed/GPU5/GPU5RJ__PROCESSOR_REP_FAILURE.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;
extern Short nsm;
extern Short nfailedprocessors;
extern Short nfailedsm;
extern Short nfailedwarps;

class GPU5RJ__STREAMING_MULTIPROCESSOR_FAILURE: public Join {
 public:
  L1_CACHESAN * L1_CACHE_FAILURE;
  GPU5RJ__PROCESSOR_REP_FAILURE * PROCESSOR_REP_FAILURE;
  Place * INSTRUCTION_READY;
  Place * MEM_FAILURE;
  Place * READ_DRAM;
  Place * READ_L1;
  Place * READ_L2;
  Place * WRITE_DRAM;
  Place * WRITE_L1;
  Place * WRITE_L2;

  GPU5RJ__STREAMING_MULTIPROCESSOR_FAILURE();
  ~GPU5RJ__STREAMING_MULTIPROCESSOR_FAILURE();
};

#endif
