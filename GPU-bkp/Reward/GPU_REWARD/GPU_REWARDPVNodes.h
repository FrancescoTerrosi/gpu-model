#ifndef _GPU_REWARD_PVS_
#define _GPU_REWARD_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/GPU_MODEL_ATOMIC_COMPOSITION/GPU_MODEL_ATOMIC_COMPOSITIONSAN.h"
#include "Cpp/Performance_Variables/IntervalOfTime.hpp"
#include "Cpp/Performance_Variables/IntervalOfTimeImpulse.hpp"



class GPU_REWARDPV0Impulse0:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV0Impulse0();
  ~GPU_REWARDPV0Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV0Impulse1:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV0Impulse1();
  ~GPU_REWARDPV0Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV0Impulse2:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV0Impulse2();
  ~GPU_REWARDPV0Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV0Impulse3:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV0Impulse3();
  ~GPU_REWARDPV0Impulse3();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV0Impulse4:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV0Impulse4();
  ~GPU_REWARDPV0Impulse4();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV0Impulse5:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV0Impulse5();
  ~GPU_REWARDPV0Impulse5();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV0Impulse6:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV0Impulse6();
  ~GPU_REWARDPV0Impulse6();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV0:public PerformanceVariableNode
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *TheGPU_MODEL_ATOMIC_COMPOSITIONSAN;

  GPU_REWARDPV0Impulse0 Impulse0;
  GPU_REWARDPV0Impulse1 Impulse1;
  GPU_REWARDPV0Impulse2 Impulse2;
  GPU_REWARDPV0Impulse3 Impulse3;
  GPU_REWARDPV0Impulse4 Impulse4;
  GPU_REWARDPV0Impulse5 Impulse5;
  GPU_REWARDPV0Impulse6 Impulse6;

  GPU_REWARDPV0(int timeindex=0);
  ~GPU_REWARDPV0();
  void CreateWorkerList(void);
};

#endif
