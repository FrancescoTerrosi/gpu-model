#ifndef GPU_AVERAGERJ__Join1_H_
#define GPU_AVERAGERJ__Join1_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Atomic/LOCAL_MEMORY/LOCAL_MEMORYSAN.h"
#include "Atomic/WARP_AVERAGE/WARP_AVERAGESAN.h"
#include "Atomic/GLOBAL_MEMORY/GLOBAL_MEMORYSAN.h"
#include "Atomic/REGISTER_FILE/REGISTER_FILESAN.h"
#include "Atomic/COMPUTE_UNIT/COMPUTE_UNITSAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"

class GPU_AVERAGERJ__Join1: public Join {
 public:
  LOCAL_MEMORYSAN * LOCAL_MEMORY;
  WARP_AVERAGESAN * WARP_AVERAGE;
  GLOBAL_MEMORYSAN * GLOBAL_MEMORY;
  REGISTER_FILESAN * REGISTER_FILE;
  COMPUTE_UNITSAN * COMPUTE_UNIT;
  Place * INSTRUCTION_READY;
  Place * KO_READ;
  Place * MEM_OP_COMPLETE;
  Place * OK_READ;
  Place * READ_DRAM;
  Place * READ_GLOBAL_MEMORY;
  Place * READ_L1;
  Place * READ_L2;
  Place * READ_LOCAL_MEMORY;
  Place * READ_REGISTER_FILE;
  Place * RESULT_KO;
  Place * RESULT_OK;
  Place * SCHEDULER;
  Place * WRITE_DRAM;
  Place * WRITE_GLOBAL_MEMORY;
  Place * WRITE_L1;
  Place * WRITE_L2;
  Place * WRITE_LOCAL_MEMORY;
  Place * WRITE_REGISTER_FILE;

  GPU_AVERAGERJ__Join1();
  ~GPU_AVERAGERJ__Join1();
};

#endif
