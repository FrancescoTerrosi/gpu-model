#ifndef GPU_FAILURERJ_H_
#define GPU_FAILURERJ_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__SM_REP.h"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__STREAMING_MULTIPROCESSOR_FAILURE.h"
#include "Atomic/DRAM/DRAMSAN.h"
#include "Atomic/L2_CACHE/L2_CACHESAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;
extern Short nsm;
extern Short nfailedprocessors;
extern Short nfailedsm;
extern Short nfailedwarps;

class GPU_FAILURERJ: public Join {
 public:
  GPU_FAILURERJ__SM_REP * SM_REP;
  GPU_FAILURERJ__STREAMING_MULTIPROCESSOR_FAILURE * STREAMING_MULTIPROCESSOR_FAILURE;
  DRAMSAN * DRAM;
  L2_CACHESAN * L2_CACHE;
  Place * INSTRUCTION_READY;
  Place * KO_CONTENT;
  Place * MEMORY_KO;
  Place * MEMORY_OK;
  Place * MEM_FAILURE;
  Place * OK_CONTENT;
  Place * READ_DRAM;
  Place * READ_L2;
  Place * WRITE_DRAM;
  Place * WRITE_L2;

  GPU_FAILURERJ();
  ~GPU_FAILURERJ();
};

#endif
