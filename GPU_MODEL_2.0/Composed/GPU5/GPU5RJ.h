#ifndef GPU5RJ_H_
#define GPU5RJ_H_
#include <math.h>
#include "Cpp/Composer/Rep.h"
#include "Cpp/Composer/AllStateVariableTypes.h"

//Submodel header files
#include "Composed/GPU5/GPU5RJ__DEVICE.h"
extern Short nwarps;
extern Short nprocessors;

class GPU5RJ: public Rep {
 public:
  GPU5RJ__DEVICE ** InstanceArray;

  GPU5RJ();
  ~GPU5RJ();

};

#endif
