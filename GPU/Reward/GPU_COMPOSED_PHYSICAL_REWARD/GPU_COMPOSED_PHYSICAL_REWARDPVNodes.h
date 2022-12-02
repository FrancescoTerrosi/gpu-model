#ifndef _GPU_COMPOSED_PHYSICAL_REWARD_PVS_
#define _GPU_COMPOSED_PHYSICAL_REWARD_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Composed/GPU_PHYSICAL/GPU_PHYSICALRJ.h"
#include "Cpp/Performance_Variables/IntervalOfTime.hpp"
#include "Cpp/Performance_Variables/IntervalOfTimeImpulse.hpp"



class GPU_COMPOSED_PHYSICAL_REWARDPV0Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU_COMPOSED_PHYSICAL_REWARDPV0Impulse0();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV0Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_PHYSICAL_REWARDPV0:public PerformanceVariableNode
{
 public:
  GPU_PHYSICALRJ *TheGPU_PHYSICALRJ;

  GPU_COMPOSED_PHYSICAL_REWARDPV0Impulse0 Impulse0;

  GPU_COMPOSED_PHYSICAL_REWARDPV0(int timeindex=0);
  ~GPU_COMPOSED_PHYSICAL_REWARDPV0();
  void CreateWorkerList(void);
};


class GPU_COMPOSED_PHYSICAL_REWARDPV1Impulse0:public IntervalOfTimeImpulse
{
 public:
  OUTPUT_MEMORY_PHYSICALSAN *OUTPUT_MEMORY_PHYSICAL;

  GPU_COMPOSED_PHYSICAL_REWARDPV1Impulse0();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV1Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_PHYSICAL_REWARDPV1:public PerformanceVariableNode
{
 public:
  GPU_PHYSICALRJ *TheGPU_PHYSICALRJ;

  GPU_COMPOSED_PHYSICAL_REWARDPV1Impulse0 Impulse0;

  GPU_COMPOSED_PHYSICAL_REWARDPV1(int timeindex=0);
  ~GPU_COMPOSED_PHYSICAL_REWARDPV1();
  void CreateWorkerList(void);
};


class GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse0:public IntervalOfTimeImpulse
{
 public:
  RESULT_MEMORY_MODEL_PHYSICALSAN *RESULT_MEMORY_MODEL_PHYSICAL;

  GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse0();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse1:public IntervalOfTimeImpulse
{
 public:
  RESULT_MEMORY_MODEL_PHYSICALSAN *RESULT_MEMORY_MODEL_PHYSICAL;

  GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse1();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse2:public IntervalOfTimeImpulse
{
 public:
  RESULT_MEMORY_MODEL_PHYSICALSAN *RESULT_MEMORY_MODEL_PHYSICAL;

  GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse2();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_PHYSICAL_REWARDPV2:public PerformanceVariableNode
{
 public:
  GPU_PHYSICALRJ *TheGPU_PHYSICALRJ;

  GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse0 Impulse0;
  GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse1 Impulse1;
  GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse2 Impulse2;

  GPU_COMPOSED_PHYSICAL_REWARDPV2(int timeindex=0);
  ~GPU_COMPOSED_PHYSICAL_REWARDPV2();
  void CreateWorkerList(void);
};


class GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse0:public IntervalOfTimeImpulse
{
 public:
  RESULT_MEMORY_MODEL_PHYSICALSAN *RESULT_MEMORY_MODEL_PHYSICAL;

  GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse0();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse1:public IntervalOfTimeImpulse
{
 public:
  RESULT_MEMORY_MODEL_PHYSICALSAN *RESULT_MEMORY_MODEL_PHYSICAL;

  GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse1();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse2:public IntervalOfTimeImpulse
{
 public:
  RESULT_MEMORY_MODEL_PHYSICALSAN *RESULT_MEMORY_MODEL_PHYSICAL;

  GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse2();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_PHYSICAL_REWARDPV3:public PerformanceVariableNode
{
 public:
  GPU_PHYSICALRJ *TheGPU_PHYSICALRJ;

  GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse0 Impulse0;
  GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse1 Impulse1;
  GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse2 Impulse2;

  GPU_COMPOSED_PHYSICAL_REWARDPV3(int timeindex=0);
  ~GPU_COMPOSED_PHYSICAL_REWARDPV3();
  void CreateWorkerList(void);
};


class GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse0:public IntervalOfTimeImpulse
{
 public:
  TOTAL_MEMORY_MODEL_PHYSICALSAN *TOTAL_MEMORY_MODEL_PHYSICAL;

  GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse0();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse1:public IntervalOfTimeImpulse
{
 public:
  TOTAL_MEMORY_MODEL_PHYSICALSAN *TOTAL_MEMORY_MODEL_PHYSICAL;

  GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse1();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse2:public IntervalOfTimeImpulse
{
 public:
  TOTAL_MEMORY_MODEL_PHYSICALSAN *TOTAL_MEMORY_MODEL_PHYSICAL;

  GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse2();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_PHYSICAL_REWARDPV4:public PerformanceVariableNode
{
 public:
  GPU_PHYSICALRJ *TheGPU_PHYSICALRJ;

  GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse0 Impulse0;
  GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse1 Impulse1;
  GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse2 Impulse2;

  GPU_COMPOSED_PHYSICAL_REWARDPV4(int timeindex=0);
  ~GPU_COMPOSED_PHYSICAL_REWARDPV4();
  void CreateWorkerList(void);
};


class GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse0();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse1:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse1();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_PHYSICAL_REWARDPV5:public PerformanceVariableNode
{
 public:
  GPU_PHYSICALRJ *TheGPU_PHYSICALRJ;

  GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse0 Impulse0;
  GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse1 Impulse1;

  GPU_COMPOSED_PHYSICAL_REWARDPV5(int timeindex=0);
  ~GPU_COMPOSED_PHYSICAL_REWARDPV5();
  void CreateWorkerList(void);
};


class GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse0:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse0();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse1:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse1();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_PHYSICAL_REWARDPV6:public PerformanceVariableNode
{
 public:
  GPU_PHYSICALRJ *TheGPU_PHYSICALRJ;

  GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse0 Impulse0;
  GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse1 Impulse1;

  GPU_COMPOSED_PHYSICAL_REWARDPV6(int timeindex=0);
  ~GPU_COMPOSED_PHYSICAL_REWARDPV6();
  void CreateWorkerList(void);
};


class GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse0:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse0();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse1:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse1();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_PHYSICAL_REWARDPV7:public PerformanceVariableNode
{
 public:
  GPU_PHYSICALRJ *TheGPU_PHYSICALRJ;

  GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse0 Impulse0;
  GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse1 Impulse1;

  GPU_COMPOSED_PHYSICAL_REWARDPV7(int timeindex=0);
  ~GPU_COMPOSED_PHYSICAL_REWARDPV7();
  void CreateWorkerList(void);
};


class GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse0:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse0();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse1:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse1();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_PHYSICAL_REWARDPV8:public PerformanceVariableNode
{
 public:
  GPU_PHYSICALRJ *TheGPU_PHYSICALRJ;

  GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse0 Impulse0;
  GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse1 Impulse1;

  GPU_COMPOSED_PHYSICAL_REWARDPV8(int timeindex=0);
  ~GPU_COMPOSED_PHYSICAL_REWARDPV8();
  void CreateWorkerList(void);
};


class GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse0:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse0();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse1:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse1();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_PHYSICAL_REWARDPV9:public PerformanceVariableNode
{
 public:
  GPU_PHYSICALRJ *TheGPU_PHYSICALRJ;

  GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse0 Impulse0;
  GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse1 Impulse1;

  GPU_COMPOSED_PHYSICAL_REWARDPV9(int timeindex=0);
  ~GPU_COMPOSED_PHYSICAL_REWARDPV9();
  void CreateWorkerList(void);
};


class GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse0:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse0();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse1:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse1();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_PHYSICAL_REWARDPV10:public PerformanceVariableNode
{
 public:
  GPU_PHYSICALRJ *TheGPU_PHYSICALRJ;

  GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse0 Impulse0;
  GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse1 Impulse1;

  GPU_COMPOSED_PHYSICAL_REWARDPV10(int timeindex=0);
  ~GPU_COMPOSED_PHYSICAL_REWARDPV10();
  void CreateWorkerList(void);
};


class GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse0:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse0();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse1:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse1();
  ~GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_PHYSICAL_REWARDPV11:public PerformanceVariableNode
{
 public:
  GPU_PHYSICALRJ *TheGPU_PHYSICALRJ;

  GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse0 Impulse0;
  GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse1 Impulse1;

  GPU_COMPOSED_PHYSICAL_REWARDPV11(int timeindex=0);
  ~GPU_COMPOSED_PHYSICAL_REWARDPV11();
  void CreateWorkerList(void);
};

#endif
