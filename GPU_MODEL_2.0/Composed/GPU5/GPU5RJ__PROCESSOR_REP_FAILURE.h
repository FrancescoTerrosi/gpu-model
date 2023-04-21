#ifndef GPU5RJ__PROCESSOR_REP_FAILURE_H_
#define GPU5RJ__PROCESSOR_REP_FAILURE_H_
#include <math.h>
#include "Cpp/Composer/Rep.h"
#include "Cpp/Composer/AllStateVariableTypes.h"

//Submodel header files
#include "Composed/GPU5/GPU5RJ__PROCESSOR_FAILURE.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;
extern Short nsm;
extern Short nfailedprocessors;
extern Short nfailedsm;
extern Short nfailedwarps;

class GPU5RJ__PROCESSOR_REP_FAILURE: public Rep {
 public:
  GPU5RJ__PROCESSOR_FAILURE ** InstanceArray;

  GPU5RJ__PROCESSOR_REP_FAILURE();
  ~GPU5RJ__PROCESSOR_REP_FAILURE();

  // Declare new variables
  Place * INSTRUCTION_READY;
  Place * MEM_FAILURE;
  Place * READ_DRAM;
  Place * READ_L1;
  Place * READ_L2;
  Place * WARP_ACCESS_DRAM;
  Place * WARP_ACCESS_L1;
  Place * WARP_ACCESS_L2;
  Place * WRITE_DRAM;
  Place * WRITE_L1;
  Place * WRITE_L2;
};

#endif
