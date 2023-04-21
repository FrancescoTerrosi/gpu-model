#ifndef GPU_FAILURERJ__Rep2_H_
#define GPU_FAILURERJ__Rep2_H_
#include <math.h>
#include "Cpp/Composer/Rep.h"
#include "Cpp/Composer/AllStateVariableTypes.h"

//Submodel header files
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__WARP_REG_FAILURE.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;
extern Short nsm;
extern Short nfailedprocessors;
extern Short nfailedsm;
extern Short nfailedwarps;

class GPU_FAILURERJ__Rep2: public Rep {
 public:
  GPU_FAILURERJ__WARP_REG_FAILURE ** InstanceArray;

  GPU_FAILURERJ__Rep2();
  ~GPU_FAILURERJ__Rep2();

  // Declare new variables
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
};

#endif
