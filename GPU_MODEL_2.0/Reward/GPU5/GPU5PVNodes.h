#ifndef _GPU5_PVS_
#define _GPU5_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Composed/GPU5/GPU5RJ__Rep1.h"
#include "Composed/GPU5/GPU5RJ__PROCESSOR_REP.h"
#include "Composed/GPU5/GPU5RJ__PROCESSOR.h"
#include "Composed/GPU5/GPU5RJ__STREAMING_MULTIPROCESSOR.h"
#include "Composed/GPU5/GPU5RJ.h"
#include "Cpp/Performance_Variables/IntervalOfTime.hpp"
#include "Cpp/Performance_Variables/IntervalOfTimeImpulse.hpp"

extern Short end;


class GPU5PV0Impulse0:public IntervalOfTimeImpulse
{
 public:
  WARPSAN *WARP;

  GPU5PV0Impulse0();
  ~GPU5PV0Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU5PV0:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV0Impulse0 Impulse0;

  GPU5PV0(int timeindex=0);
  ~GPU5PV0();
  void CreateWorkerList(void);
};

#endif
