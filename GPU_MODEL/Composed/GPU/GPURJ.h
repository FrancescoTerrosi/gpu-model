#ifndef GPURJ_H_
#define GPURJ_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Atomic/COMPUTE_UNIT/COMPUTE_UNITSAN.h"
#include "Atomic/DRAM/DRAMSAN.h"
#include "Atomic/L2_CACHE/L2_CACHESAN.h"
#include "Atomic/L1_CACHE/L1_CACHESAN.h"
#include "Atomic/INITIAL_MEMORY_MODEL/INITIAL_MEMORY_MODELSAN.h"
#include "Atomic/INTERMEDIATE_MEMORY_MODEL/INTERMEDIATE_MEMORY_MODELSAN.h"
#include "Atomic/FINAL_MEMORY_MODEL/FINAL_MEMORY_MODELSAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short size;

class GPURJ: public Join {
 public:
  COMPUTE_UNITSAN * COMPUTE_UNIT;
  DRAMSAN * DRAM;
  L2_CACHESAN * L2_CACHE;
  L1_CACHESAN * L1_CACHE;
  INITIAL_MEMORY_MODELSAN * INITIAL_MEMORY_MODEL;
  INTERMEDIATE_MEMORY_MODELSAN * INTERMEDIATE_MEMORY_MODEL;
  FINAL_MEMORY_MODELSAN * FINAL_MEMORY_MODEL;
  Place * KO_READ;
  Place * MEM_OP_COMPLETE;
  Place * OK_READ;
  Place * READ_DRAM;
  Place * READ_INITIAL_MEMORY;
  Place * READ_INTERMEDIATE_MEMORY;
  Place * READ_L1;
  Place * READ_L2;
  Place * RESULT_KO;
  Place * RESULT_OK;
  Place * WRITE_DRAM;
  Place * WRITE_FINAL_MEMORY;
  Place * WRITE_INTERMEDIATE_MEMORY;
  Place * WRITE_L1;
  Place * WRITE_L2;

  GPURJ();
  ~GPURJ();
};

#endif
