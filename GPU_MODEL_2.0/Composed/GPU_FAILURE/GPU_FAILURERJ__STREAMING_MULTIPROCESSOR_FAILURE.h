#ifndef GPU_FAILURERJ__STREAMING_MULTIPROCESSOR_FAILURE_H_
#define GPU_FAILURERJ__STREAMING_MULTIPROCESSOR_FAILURE_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__PROCESSOR_REP_FAILURE.h"
#include "Atomic/L1_CACHE/L1_CACHESAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;
extern Short nsm;
extern Short nfailedprocessors;
extern Short nfailedsm;
extern Short nfailedwarps;

class GPU_FAILURERJ__STREAMING_MULTIPROCESSOR_FAILURE: public Join {
 public:
  GPU_FAILURERJ__PROCESSOR_REP_FAILURE * PROCESSOR_REP_FAILURE;
  L1_CACHESAN * L1_CACHE_FAILURE;
  Place * INSTRUCTION_READY;
  Place * MEM_FAILURE;
  Place * READ_DRAM;
  Place * READ_L1;
  Place * READ_L2;
  Place * WRITE_DRAM;
  Place * WRITE_L1;
  Place * WRITE_L2;

  GPU_FAILURERJ__STREAMING_MULTIPROCESSOR_FAILURE();
  ~GPU_FAILURERJ__STREAMING_MULTIPROCESSOR_FAILURE();
};

#endif
