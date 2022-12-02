#ifndef _GPPUU_PVS_
#define _GPPUU_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Composed/GPU2/GPU2RJ__Rep1.h"
#include "Composed/GPU2/GPU2RJ__Rep2.h"
#include "Composed/GPU2/GPU2RJ.h"
#include "Composed/GPU2/GPU2RJ__Join2.h"
#include "Composed/GPU2/GPU2RJ__Join1.h"
#include "Composed/GPU2/GPU2RJ__Join3.h"
#include "Composed/GPU2/GPU2RJ__Join4.h"
#include "Cpp/Performance_Variables/IntervalOfTime.hpp"
#include "Cpp/Performance_Variables/IntervalOfTimeImpulse.hpp"



class gppuuPV0Impulse0:public IntervalOfTimeImpulse
{
 public:
  WARPSAN *WARP;

  gppuuPV0Impulse0();
  ~gppuuPV0Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class gppuuPV0:public PerformanceVariableNode
{
 public:
  GPU2RJ *TheGPU2RJ;

  gppuuPV0Impulse0 Impulse0;

  gppuuPV0(int timeindex=0);
  ~gppuuPV0();
  void CreateWorkerList(void);
};


class gppuuPV1Impulse0:public IntervalOfTimeImpulse
{
 public:
  WARPSAN *WARP1;

  gppuuPV1Impulse0();
  ~gppuuPV1Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class gppuuPV1:public PerformanceVariableNode
{
 public:
  GPU2RJ *TheGPU2RJ;

  gppuuPV1Impulse0 Impulse0;

  gppuuPV1(int timeindex=0);
  ~gppuuPV1();
  void CreateWorkerList(void);
};

#endif
