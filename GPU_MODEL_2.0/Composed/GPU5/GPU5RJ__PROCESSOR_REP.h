#ifndef GPU5RJ__PROCESSOR_REP_H_
#define GPU5RJ__PROCESSOR_REP_H_
#include <math.h>
#include "Cpp/Composer/Rep.h"
#include "Cpp/Composer/AllStateVariableTypes.h"

//Submodel header files
#include "Composed/GPU5/GPU5RJ__PROCESSOR.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;
extern Short ngpu;

class GPU5RJ__PROCESSOR_REP: public Rep {
 public:
  GPU5RJ__PROCESSOR ** InstanceArray;

  GPU5RJ__PROCESSOR_REP();
  ~GPU5RJ__PROCESSOR_REP();

  // Declare new variables
  Place * MEM_OP_COMPLETE;
  Place * READ_DRAM;
  Place * READ_L1;
  Place * READ_L2;
  Place * RESULT_KO;
  Place * RESULT_OK;
  Place * WRITE_DRAM;
  Place * WRITE_L1;
  Place * WRITE_L2;
};

#endif
