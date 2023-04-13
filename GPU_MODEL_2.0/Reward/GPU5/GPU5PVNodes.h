#ifndef _GPU5_PVS_
#define _GPU5_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Composed/GPU5/GPU5RJ__Rep1.h"
#include "Composed/GPU5/GPU5RJ__PROCESSOR_REP.h"
#include "Composed/GPU5/GPU5RJ__SM_REP.h"
#include "Composed/GPU5/GPU5RJ__PROCESSOR.h"
#include "Composed/GPU5/GPU5RJ__STREAMING_MULTIPROCESSOR.h"
#include "Composed/GPU5/GPU5RJ.h"
#include "Cpp/Performance_Variables/IntervalOfTime.hpp"
#include "Cpp/Performance_Variables/IntervalOfTimeImpulse.hpp"
#include "Cpp/Performance_Variables/InstantOfTime.hpp"

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
  EXEC_UNITSAN *EXEC_UNIT;

  GPU5PV1Impulse0();
  ~GPU5PV1Impulse0();
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

  GPU5PV1(int timeindex=0);
  ~GPU5PV1();
  void CreateWorkerList(void);
};


class GPU5PV2Impulse0:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

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
  L1_CACHESAN *L1_CACHE;

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
  L2_CACHESAN *L2_CACHE;

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
  L2_CACHESAN *L2_CACHE;

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
  DRAMSAN *DRAM;

  GPU5PV4Impulse0();
  ~GPU5PV4Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU5PV4Impulse1:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU5PV4Impulse1();
  ~GPU5PV4Impulse1();
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
  GPU5PV4Impulse1 Impulse1;

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


class GPU5PV6Impulse0:public IntervalOfTimeImpulse
{
 public:
  EXEC_UNITSAN *EXEC_UNIT;

  GPU5PV6Impulse0();
  ~GPU5PV6Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU5PV6:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV6Impulse0 Impulse0;

  GPU5PV6(int timeindex=0);
  ~GPU5PV6();
  void CreateWorkerList(void);
};


class GPU5PV7Impulse0:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU5PV7Impulse0();
  ~GPU5PV7Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU5PV7:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV7Impulse0 Impulse0;

  GPU5PV7(int timeindex=0);
  ~GPU5PV7();
  void CreateWorkerList(void);
};


class GPU5PV8Impulse0:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU5PV8Impulse0();
  ~GPU5PV8Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU5PV8Impulse1:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU5PV8Impulse1();
  ~GPU5PV8Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU5PV8:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV8Impulse0 Impulse0;
  GPU5PV8Impulse1 Impulse1;

  GPU5PV8(int timeindex=0);
  ~GPU5PV8();
  void CreateWorkerList(void);
};


class GPU5PV9Impulse0:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU5PV9Impulse0();
  ~GPU5PV9Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU5PV9Impulse1:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU5PV9Impulse1();
  ~GPU5PV9Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU5PV9:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV9Impulse0 Impulse0;
  GPU5PV9Impulse1 Impulse1;

  GPU5PV9(int timeindex=0);
  ~GPU5PV9();
  void CreateWorkerList(void);
};

class GPU5PV10Worker:public InstantOfTime
{
 public:
  DRAMSAN *DRAM;
  
  GPU5PV10Worker();
  ~GPU5PV10Worker();
  double Reward_Function();
};

class GPU5PV10:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV10Worker *GPU5PV10WorkerList;

  GPU5PV10(int timeindex=0);
  ~GPU5PV10();
  void CreateWorkerList(void);
};


class GPU5PV11Impulse0:public IntervalOfTimeImpulse
{
 public:
  WARPSAN *WARP;

  GPU5PV11Impulse0();
  ~GPU5PV11Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU5PV11:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV11Impulse0 Impulse0;

  GPU5PV11(int timeindex=0);
  ~GPU5PV11();
  void CreateWorkerList(void);
};


class GPU5PV12Impulse0:public IntervalOfTimeImpulse
{
 public:
  WARPSAN *WARP;

  GPU5PV12Impulse0();
  ~GPU5PV12Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU5PV12:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV12Impulse0 Impulse0;

  GPU5PV12(int timeindex=0);
  ~GPU5PV12();
  void CreateWorkerList(void);
};


class GPU5PV13Impulse0:public IntervalOfTimeImpulse
{
 public:
  WARPSAN *WARP;

  GPU5PV13Impulse0();
  ~GPU5PV13Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU5PV13:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV13Impulse0 Impulse0;

  GPU5PV13(int timeindex=0);
  ~GPU5PV13();
  void CreateWorkerList(void);
};


class GPU5PV14Impulse0:public IntervalOfTimeImpulse
{
 public:
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;

  GPU5PV14Impulse0();
  ~GPU5PV14Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU5PV14Impulse1:public IntervalOfTimeImpulse
{
 public:
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;

  GPU5PV14Impulse1();
  ~GPU5PV14Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU5PV14Impulse2:public IntervalOfTimeImpulse
{
 public:
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;

  GPU5PV14Impulse2();
  ~GPU5PV14Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU5PV14Impulse3:public IntervalOfTimeImpulse
{
 public:
  EXEC_UNITSAN *EXEC_UNIT;
  WARPSAN *WARP;
  MEMORYSAN *MEMORY;

  GPU5PV14Impulse3();
  ~GPU5PV14Impulse3();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU5PV14Impulse4:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;

  GPU5PV14Impulse4();
  ~GPU5PV14Impulse4();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU5PV14Impulse5:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;

  GPU5PV14Impulse5();
  ~GPU5PV14Impulse5();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU5PV14:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV14Impulse0 Impulse0;
  GPU5PV14Impulse1 Impulse1;
  GPU5PV14Impulse2 Impulse2;
  GPU5PV14Impulse3 Impulse3;
  GPU5PV14Impulse4 Impulse4;
  GPU5PV14Impulse5 Impulse5;

  GPU5PV14(int timeindex=0);
  ~GPU5PV14();
  void CreateWorkerList(void);
};

class GPU5PV15Worker:public InstantOfTime
{
 public:
  WARPSAN *WARP;
  
  GPU5PV15Worker();
  ~GPU5PV15Worker();
  double Reward_Function();
};

class GPU5PV15:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV15Worker *GPU5PV15WorkerList;

  GPU5PV15(int timeindex=0);
  ~GPU5PV15();
  void CreateWorkerList(void);
};

class GPU5PV16Worker:public InstantOfTime
{
 public:
  WARPSAN *WARP;
  
  GPU5PV16Worker();
  ~GPU5PV16Worker();
  double Reward_Function();
};

class GPU5PV16:public PerformanceVariableNode
{
 public:
  GPU5RJ *TheGPU5RJ;

  GPU5PV16Worker *GPU5PV16WorkerList;

  GPU5PV16(int timeindex=0);
  ~GPU5PV16();
  void CreateWorkerList(void);
};

#endif
