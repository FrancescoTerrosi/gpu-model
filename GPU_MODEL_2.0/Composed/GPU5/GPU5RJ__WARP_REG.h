#ifndef GPU5RJ__WARP_REG_H_
#define GPU5RJ__WARP_REG_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Atomic/REGISTER_FILE/REGISTER_FILESAN.h"
#include "Atomic/WARP/WARPSAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;
extern Short nsm;

class GPU5RJ__WARP_REG: public Join {
 public:
  REGISTER_FILESAN * REGISTER_FILE;
  WARPSAN * WARP;
  Place * FLOAT_ALU_FAILURE;
  Place * INSTRUCTION_READY;
  Place * INST_COUNTER;
  Place * INT_ALU_FAILURE;
  Place * KO_CONTENT;
  Place * MEM_FAILURE;
  Place * MEM_OP_COMPLETE;
  Place * OK_CONTENT;
  Place * REGISTERS_FILL;
  Place * REG_FAILURE;
  Place * RESULT_KO;
  Place * RESULT_OK;
  Place * SCHEDULER;
  Place * WARP_ACCESS_DRAM;
  Place * WARP_ACCESS_L1;
  Place * WARP_ACCESS_L2;

  GPU5RJ__WARP_REG();
  ~GPU5RJ__WARP_REG();
};

#endif
