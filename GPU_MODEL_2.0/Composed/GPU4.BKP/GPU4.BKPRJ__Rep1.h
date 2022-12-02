#ifndef GPU4.BKPRJ__Rep1_H_
#define GPU4.BKPRJ__Rep1_H_
#include <math.h>
#include "Cpp/Composer/Rep.h"
#include "Cpp/Composer/AllStateVariableTypes.h"

//Submodel header files
#include "Atomic/WARP/WARPSAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"

class GPU4.BKPRJ__Rep1: public Rep {
 public:
  WARPSAN ** InstanceArray;

  GPU4.BKPRJ__Rep1();
  ~GPU4.BKPRJ__Rep1();

  // Declare new variables
  Place * INSTRUCTION_READY;
  Place * SCHEDULER;
};

#endif
