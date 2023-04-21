#ifndef GPU_FAILURERJ__WARP_REG_FAILURE_H_
#define GPU_FAILURERJ__WARP_REG_FAILURE_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Atomic/WARP/WARPSAN.h"
#include "Atomic/REGISTER_FILE/REGISTER_FILESAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;
extern Short nsm;
extern Short nfailedprocessors;
extern Short nfailedsm;
extern Short nfailedwarps;

class GPU_FAILURERJ__WARP_REG_FAILURE: public Join {
 public:
  WARPSAN * WARP_FAILURE;
  REGISTER_FILESAN * REGISTER_FILE_FAILURE;
  Place * FAILURE_INST;
  Place * FLOAT_ALU_FAILURE;
  Place * INSTRUCTION_READY;
  Place * INT_ALU_FAILURE;
  Place * KO_CONTENT;
  Place * MEM_FAILURE;
  Place * OK_CONTENT;
  Place * REGISTERS_FILL;
  Place * REG_FAILURE;
  Place * RESULT_KO;
  Place * RESULT_OK;
  Place * SCHEDULER;
  Place * WARP_ACCESS_DRAM;
  Place * WARP_ACCESS_L1;
  Place * WARP_ACCESS_L2;

  GPU_FAILURERJ__WARP_REG_FAILURE();
  ~GPU_FAILURERJ__WARP_REG_FAILURE();
};

#endif
