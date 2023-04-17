#ifndef GPU5RJ__SM_REP_H_
#define GPU5RJ__SM_REP_H_
#include <math.h>
#include "Cpp/Composer/Rep.h"
#include "Cpp/Composer/AllStateVariableTypes.h"

//Submodel header files
#include "Composed/GPU5/GPU5RJ__STREAMING_MULTIPROCESSOR.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;
extern Short nsm;

class GPU5RJ__SM_REP: public Rep {
 public:
  GPU5RJ__STREAMING_MULTIPROCESSOR ** InstanceArray;

  GPU5RJ__SM_REP();
  ~GPU5RJ__SM_REP();

  // Declare new variables
  Place * INSTRUCTION_READY;
  Place * MEM_FAILURE;
  Place * READ_DRAM;
  Place * READ_L2;
  Place * WRITE_DRAM;
  Place * WRITE_L2;
};

#endif
