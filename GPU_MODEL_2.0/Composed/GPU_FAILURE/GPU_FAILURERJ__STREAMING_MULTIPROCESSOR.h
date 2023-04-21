#ifndef GPU_FAILURERJ__STREAMING_MULTIPROCESSOR_H_
#define GPU_FAILURERJ__STREAMING_MULTIPROCESSOR_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__PROCESSOR_REP.h"
#include "Atomic/L1_CACHE/L1_CACHESAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;
extern Short nsm;
extern Short nfailedprocessors;
extern Short nfailedsm;
extern Short nfailedwarps;

class GPU_FAILURERJ__STREAMING_MULTIPROCESSOR: public Join {
 public:
  GPU_FAILURERJ__PROCESSOR_REP * PROCESSOR_REP;
  L1_CACHESAN * L1_CACHE;
  Place * INSTRUCTION_READY;
  Place * MEM_FAILURE;
  Place * READ_DRAM;
  Place * READ_L1;
  Place * READ_L2;
  Place * WRITE_DRAM;
  Place * WRITE_L1;
  Place * WRITE_L2;

  GPU_FAILURERJ__STREAMING_MULTIPROCESSOR();
  ~GPU_FAILURERJ__STREAMING_MULTIPROCESSOR();
};

#endif
