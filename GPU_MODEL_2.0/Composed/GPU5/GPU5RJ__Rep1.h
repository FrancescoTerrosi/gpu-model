#ifndef GPU5RJ__Rep1_H_
#define GPU5RJ__Rep1_H_
#include <math.h>
#include "Cpp/Composer/Rep.h"
#include "Cpp/Composer/AllStateVariableTypes.h"

//Submodel header files
#include "Atomic/WARP/WARPSAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;
extern Short nsm;

class GPU5RJ__Rep1: public Rep {
 public:
  WARPSAN ** InstanceArray;

  GPU5RJ__Rep1();
  ~GPU5RJ__Rep1();

  // Declare new variables
  Place * FLOAT_ALU_FAILURE;
  Place * INSTRUCTION_READY;
  Place * INT_ALU_FAILURE;
  Place * MEM_FAILURE;
  Place * REGISTERS_FILL;
  Place * REG_FAILURE;
  Place * SCHEDULER;
  Place * WARP_ACCESS_DRAM;
  Place * WARP_ACCESS_L1;
  Place * WARP_ACCESS_L2;
};

#endif
