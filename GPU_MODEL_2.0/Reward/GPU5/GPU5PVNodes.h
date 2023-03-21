#ifndef _GPU5_PVS_
#define _GPU5_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Composed/GPU5/GPU5RJ__Rep1.h"
#include "Composed/GPU5/GPU5RJ__PROCESSOR_REP.h"
#include "Composed/GPU5/GPU5RJ.h"
#include "Composed/GPU5/GPU5RJ__PROCESSOR.h"
#include "Composed/GPU5/GPU5RJ__STREAMING_MULTIPROCESSOR.h"
#include "Composed/GPU5/GPU5RJ__DEVICE.h"
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


class GPU5PV1Impulse0:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU5PV1Impulse0();
  ~GPU5PV1Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU5PV1Impulse1:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU5PV1Impulse1();
  ~GPU5PV1Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU5PV1:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV1Impulse0 Impulse0;
  GPU5PV1Impulse1 Impulse1;

  GPU5PV1(int timeindex=0);
  ~GPU5PV1();
  void CreateWorkerList(void);
};


class GPU5PV2Impulse0:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU5PV2Impulse0();
  ~GPU5PV2Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU5PV2Impulse1:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU5PV2Impulse1();
  ~GPU5PV2Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU5PV2:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV2Impulse0 Impulse0;
  GPU5PV2Impulse1 Impulse1;

  GPU5PV2(int timeindex=0);
  ~GPU5PV2();
  void CreateWorkerList(void);
};


class GPU5PV3Impulse0:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU5PV3Impulse0();
  ~GPU5PV3Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU5PV3Impulse1:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU5PV3Impulse1();
  ~GPU5PV3Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU5PV3:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV3Impulse0 Impulse0;
  GPU5PV3Impulse1 Impulse1;

  GPU5PV3(int timeindex=0);
  ~GPU5PV3();
  void CreateWorkerList(void);
};


class GPU5PV4Impulse0:public IntervalOfTimeImpulse
{
 public:
  EXEC_UNITSAN *EXEC_UNIT;

  GPU5PV4Impulse0();
  ~GPU5PV4Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU5PV4:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV4Impulse0 Impulse0;

  GPU5PV4(int timeindex=0);
  ~GPU5PV4();
  void CreateWorkerList(void);
};


class GPU5PV5Impulse0:public IntervalOfTimeImpulse
{
 public:
  EXEC_UNITSAN *EXEC_UNIT;

  GPU5PV5Impulse0();
  ~GPU5PV5Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU5PV5:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV5Impulse0 Impulse0;

  GPU5PV5(int timeindex=0);
  ~GPU5PV5();
  void CreateWorkerList(void);
};

#endif
