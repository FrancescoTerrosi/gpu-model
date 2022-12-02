#ifndef GPU4RJ__Rep1_H_
#define GPU4RJ__Rep1_H_
#include <math.h>
#include "Cpp/Composer/Rep.h"
#include "Cpp/Composer/AllStateVariableTypes.h"

//Submodel header files
#include "Atomic/WARP/WARPSAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;

class GPU4RJ__Rep1: public Rep {
 public:
  WARPSAN ** InstanceArray;

  GPU4RJ__Rep1();
  ~GPU4RJ__Rep1();

  // Declare new variables
  Place * INSTRUCTION_READY;
  Place * REGISTERS_FILL;
  Place * SCHEDULER;
};

#endif
