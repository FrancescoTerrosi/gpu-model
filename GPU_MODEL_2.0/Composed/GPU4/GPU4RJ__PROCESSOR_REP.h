#ifndef GPU4RJ__PROCESSOR_REP_H_
#define GPU4RJ__PROCESSOR_REP_H_
#include <math.h>
#include "Cpp/Composer/Rep.h"
#include "Cpp/Composer/AllStateVariableTypes.h"

//Submodel header files
#include "Composed/GPU4/GPU4RJ__PROCESSOR.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;

class GPU4RJ__PROCESSOR_REP: public Rep {
 public:
  GPU4RJ__PROCESSOR ** InstanceArray;

  GPU4RJ__PROCESSOR_REP();
  ~GPU4RJ__PROCESSOR_REP();

  // Declare new variables
  Place * KO_READ;
  Place * MEM_OP_COMPLETE;
  Place * OK_READ;
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
