#ifndef GPU4RJ__WARPS_H_
#define GPU4RJ__WARPS_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Atomic/WARP/WARPSAN.h"
#include "Atomic/WARP/WARPSAN.h"
#include "Atomic/WARP/WARPSAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"

class GPU4RJ__WARPS: public Join {
 public:
  WARPSAN * WARP;
  WARPSAN * WARP1;
  WARPSAN * WARP2;
  Place * INSTRUCTION_READY;
  Place * SCHEDULER;

  GPU4RJ__WARPS();
  ~GPU4RJ__WARPS();
};

#endif
