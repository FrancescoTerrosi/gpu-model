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

class GPU_REWARDPV0:public PerformanceVariableNode
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *TheGPU_MODEL_ATOMIC_COMPOSITIONSAN;

  GPU_REWARDPV0Impulse0 Impulse0;

  GPU_REWARDPV0(int timeindex=0);
  ~GPU_REWARDPV0();
  void CreateWorkerList(void);
};


class GPU_REWARDPV1Impulse0:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV1Impulse0();
  ~GPU_REWARDPV1Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV1:public PerformanceVariableNode
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *TheGPU_MODEL_ATOMIC_COMPOSITIONSAN;

  GPU_REWARDPV1Impulse0 Impulse0;

  GPU_REWARDPV1(int timeindex=0);
  ~GPU_REWARDPV1();
  void CreateWorkerList(void);
};


class GPU_REWARDPV2Impulse0:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV2Impulse0();
  ~GPU_REWARDPV2Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV2:public PerformanceVariableNode
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *TheGPU_MODEL_ATOMIC_COMPOSITIONSAN;

  GPU_REWARDPV2Impulse0 Impulse0;

  GPU_REWARDPV2(int timeindex=0);
  ~GPU_REWARDPV2();
  void CreateWorkerList(void);
};


class GPU_REWARDPV3Impulse0:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV3Impulse0();
  ~GPU_REWARDPV3Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV3:public PerformanceVariableNode
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *TheGPU_MODEL_ATOMIC_COMPOSITIONSAN;

  GPU_REWARDPV3Impulse0 Impulse0;

  GPU_REWARDPV3(int timeindex=0);
  ~GPU_REWARDPV3();
  void CreateWorkerList(void);
};


class GPU_REWARDPV4Impulse0:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV4Impulse0();
  ~GPU_REWARDPV4Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV4:public PerformanceVariableNode
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *TheGPU_MODEL_ATOMIC_COMPOSITIONSAN;

  GPU_REWARDPV4Impulse0 Impulse0;

  GPU_REWARDPV4(int timeindex=0);
  ~GPU_REWARDPV4();
  void CreateWorkerList(void);
};


class GPU_REWARDPV5Impulse0:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV5Impulse0();
  ~GPU_REWARDPV5Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV5:public PerformanceVariableNode
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *TheGPU_MODEL_ATOMIC_COMPOSITIONSAN;

  GPU_REWARDPV5Impulse0 Impulse0;

  GPU_REWARDPV5(int timeindex=0);
  ~GPU_REWARDPV5();
  void CreateWorkerList(void);
};


class GPU_REWARDPV6Impulse0:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV6Impulse0();
  ~GPU_REWARDPV6Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV6:public PerformanceVariableNode
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *TheGPU_MODEL_ATOMIC_COMPOSITIONSAN;

  GPU_REWARDPV6Impulse0 Impulse0;

  GPU_REWARDPV6(int timeindex=0);
  ~GPU_REWARDPV6();
  void CreateWorkerList(void);
};


class GPU_REWARDPV7Impulse0:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV7Impulse0();
  ~GPU_REWARDPV7Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV7Impulse1:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV7Impulse1();
  ~GPU_REWARDPV7Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV7:public PerformanceVariableNode
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *TheGPU_MODEL_ATOMIC_COMPOSITIONSAN;

  GPU_REWARDPV7Impulse0 Impulse0;
  GPU_REWARDPV7Impulse1 Impulse1;

  GPU_REWARDPV7(int timeindex=0);
  ~GPU_REWARDPV7();
  void CreateWorkerList(void);
};


class GPU_REWARDPV8Impulse0:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV8Impulse0();
  ~GPU_REWARDPV8Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV8Impulse1:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV8Impulse1();
  ~GPU_REWARDPV8Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV8:public PerformanceVariableNode
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *TheGPU_MODEL_ATOMIC_COMPOSITIONSAN;

  GPU_REWARDPV8Impulse0 Impulse0;
  GPU_REWARDPV8Impulse1 Impulse1;

  GPU_REWARDPV8(int timeindex=0);
  ~GPU_REWARDPV8();
  void CreateWorkerList(void);
};


class GPU_REWARDPV9Impulse0:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV9Impulse0();
  ~GPU_REWARDPV9Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV9Impulse1:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV9Impulse1();
  ~GPU_REWARDPV9Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV9:public PerformanceVariableNode
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *TheGPU_MODEL_ATOMIC_COMPOSITIONSAN;

  GPU_REWARDPV9Impulse0 Impulse0;
  GPU_REWARDPV9Impulse1 Impulse1;

  GPU_REWARDPV9(int timeindex=0);
  ~GPU_REWARDPV9();
  void CreateWorkerList(void);
};


class GPU_REWARDPV10Impulse0:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV10Impulse0();
  ~GPU_REWARDPV10Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV10Impulse1:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV10Impulse1();
  ~GPU_REWARDPV10Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV10:public PerformanceVariableNode
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *TheGPU_MODEL_ATOMIC_COMPOSITIONSAN;

  GPU_REWARDPV10Impulse0 Impulse0;
  GPU_REWARDPV10Impulse1 Impulse1;

  GPU_REWARDPV10(int timeindex=0);
  ~GPU_REWARDPV10();
  void CreateWorkerList(void);
};


class GPU_REWARDPV11Impulse0:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV11Impulse0();
  ~GPU_REWARDPV11Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV11Impulse1:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV11Impulse1();
  ~GPU_REWARDPV11Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV11:public PerformanceVariableNode
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *TheGPU_MODEL_ATOMIC_COMPOSITIONSAN;

  GPU_REWARDPV11Impulse0 Impulse0;
  GPU_REWARDPV11Impulse1 Impulse1;

  GPU_REWARDPV11(int timeindex=0);
  ~GPU_REWARDPV11();
  void CreateWorkerList(void);
};


class GPU_REWARDPV12Impulse0:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV12Impulse0();
  ~GPU_REWARDPV12Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV12Impulse1:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV12Impulse1();
  ~GPU_REWARDPV12Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV12Impulse2:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV12Impulse2();
  ~GPU_REWARDPV12Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV12Impulse3:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV12Impulse3();
  ~GPU_REWARDPV12Impulse3();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV12Impulse4:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV12Impulse4();
  ~GPU_REWARDPV12Impulse4();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV12Impulse5:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV12Impulse5();
  ~GPU_REWARDPV12Impulse5();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV12Impulse6:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV12Impulse6();
  ~GPU_REWARDPV12Impulse6();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV12Impulse7:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV12Impulse7();
  ~GPU_REWARDPV12Impulse7();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV12Impulse8:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV12Impulse8();
  ~GPU_REWARDPV12Impulse8();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV12Impulse9:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV12Impulse9();
  ~GPU_REWARDPV12Impulse9();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV12Impulse10:public IntervalOfTimeImpulse
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *GPU_MODEL_ATOMIC_COMPOSITION;

  GPU_REWARDPV12Impulse10();
  ~GPU_REWARDPV12Impulse10();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV12:public PerformanceVariableNode
{
 public:
  GPU_MODEL_ATOMIC_COMPOSITIONSAN *TheGPU_MODEL_ATOMIC_COMPOSITIONSAN;

  GPU_REWARDPV12Impulse0 Impulse0;
  GPU_REWARDPV12Impulse1 Impulse1;
  GPU_REWARDPV12Impulse2 Impulse2;
  GPU_REWARDPV12Impulse3 Impulse3;
  GPU_REWARDPV12Impulse4 Impulse4;
  GPU_REWARDPV12Impulse5 Impulse5;
  GPU_REWARDPV12Impulse6 Impulse6;
  GPU_REWARDPV12Impulse7 Impulse7;
  GPU_REWARDPV12Impulse8 Impulse8;
  GPU_REWARDPV12Impulse9 Impulse9;
  GPU_REWARDPV12Impulse10 Impulse10;

  GPU_REWARDPV12(int timeindex=0);
  ~GPU_REWARDPV12();
  void CreateWorkerList(void);
};

#endif
