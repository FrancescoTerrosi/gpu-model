#ifndef GPU5RJ_H_
#define GPU5RJ_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Composed/GPU5/GPU5RJ__SM_REP.h"
#include "Atomic/DRAM/DRAMSAN.h"
#include "Atomic/L2_CACHE/L2_CACHESAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;
extern Short nsm;

class GPU5RJ: public Join {
 public:
  GPU5RJ__SM_REP * SM_REP;
  DRAMSAN * DRAM;
  L2_CACHESAN * L2_CACHE;
  Place * KO_CONTENT;
  Place * MEMORY_KO;
  Place * MEMORY_OK;
  Place * MEM_FAILURE;
  Place * MEM_OP_COMPLETE;
  Place * OK_CONTENT;
  Place * READ_DRAM;
  Place * READ_L2;
  Place * WRITE_DRAM;
  Place * WRITE_L2;

  GPU5RJ();
  ~GPU5RJ();
};

#endif
