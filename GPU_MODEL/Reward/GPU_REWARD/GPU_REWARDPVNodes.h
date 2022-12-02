#ifndef _GPU_REWARD_PVS_
#define _GPU_REWARD_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Composed/GPU/GPURJ.h"
#include "Cpp/Performance_Variables/IntervalOfTime.hpp"
#include "Cpp/Performance_Variables/IntervalOfTimeImpulse.hpp"

extern Short end;


class GPU_REWARDPV0Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

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
  GPURJ *TheGPURJ;

  GPU_REWARDPV0Impulse0 Impulse0;

  GPU_REWARDPV0(int timeindex=0);
  ~GPU_REWARDPV0();
  void CreateWorkerList(void);
};


class GPU_REWARDPV1Impulse0:public IntervalOfTimeImpulse
{
 public:
  INITIAL_MEMORY_MODELSAN *INITIAL_MEMORY_MODEL;

  GPU_REWARDPV1Impulse0();
  ~GPU_REWARDPV1Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV1Impulse1:public IntervalOfTimeImpulse
{
 public:
  INITIAL_MEMORY_MODELSAN *INITIAL_MEMORY_MODEL;

  GPU_REWARDPV1Impulse1();
  ~GPU_REWARDPV1Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV1Impulse2:public IntervalOfTimeImpulse
{
 public:
  INITIAL_MEMORY_MODELSAN *INITIAL_MEMORY_MODEL;

  GPU_REWARDPV1Impulse2();
  ~GPU_REWARDPV1Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV1Impulse3:public IntervalOfTimeImpulse
{
 public:
  INITIAL_MEMORY_MODELSAN *INITIAL_MEMORY_MODEL;

  GPU_REWARDPV1Impulse3();
  ~GPU_REWARDPV1Impulse3();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV1:public PerformanceVariableNode
{
 public:
  GPURJ *TheGPURJ;

  GPU_REWARDPV1Impulse0 Impulse0;
  GPU_REWARDPV1Impulse1 Impulse1;
  GPU_REWARDPV1Impulse2 Impulse2;
  GPU_REWARDPV1Impulse3 Impulse3;

  GPU_REWARDPV1(int timeindex=0);
  ~GPU_REWARDPV1();
  void CreateWorkerList(void);
};


class GPU_REWARDPV2Impulse0:public IntervalOfTimeImpulse
{
 public:
  INTERMEDIATE_MEMORY_MODELSAN *INTERMEDIATE_MEMORY_MODEL;

  GPU_REWARDPV2Impulse0();
  ~GPU_REWARDPV2Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV2Impulse1:public IntervalOfTimeImpulse
{
 public:
  INTERMEDIATE_MEMORY_MODELSAN *INTERMEDIATE_MEMORY_MODEL;

  GPU_REWARDPV2Impulse1();
  ~GPU_REWARDPV2Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV2Impulse2:public IntervalOfTimeImpulse
{
 public:
  INTERMEDIATE_MEMORY_MODELSAN *INTERMEDIATE_MEMORY_MODEL;

  GPU_REWARDPV2Impulse2();
  ~GPU_REWARDPV2Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV2Impulse3:public IntervalOfTimeImpulse
{
 public:
  INTERMEDIATE_MEMORY_MODELSAN *INTERMEDIATE_MEMORY_MODEL;

  GPU_REWARDPV2Impulse3();
  ~GPU_REWARDPV2Impulse3();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV2Impulse4:public IntervalOfTimeImpulse
{
 public:
  INTERMEDIATE_MEMORY_MODELSAN *INTERMEDIATE_MEMORY_MODEL;

  GPU_REWARDPV2Impulse4();
  ~GPU_REWARDPV2Impulse4();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV2Impulse5:public IntervalOfTimeImpulse
{
 public:
  INTERMEDIATE_MEMORY_MODELSAN *INTERMEDIATE_MEMORY_MODEL;

  GPU_REWARDPV2Impulse5();
  ~GPU_REWARDPV2Impulse5();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV2:public PerformanceVariableNode
{
 public:
  GPURJ *TheGPURJ;

  GPU_REWARDPV2Impulse0 Impulse0;
  GPU_REWARDPV2Impulse1 Impulse1;
  GPU_REWARDPV2Impulse2 Impulse2;
  GPU_REWARDPV2Impulse3 Impulse3;
  GPU_REWARDPV2Impulse4 Impulse4;
  GPU_REWARDPV2Impulse5 Impulse5;

  GPU_REWARDPV2(int timeindex=0);
  ~GPU_REWARDPV2();
  void CreateWorkerList(void);
};


class GPU_REWARDPV3Impulse0:public IntervalOfTimeImpulse
{
 public:
  INTERMEDIATE_MEMORY_MODELSAN *INTERMEDIATE_MEMORY_MODEL;

  GPU_REWARDPV3Impulse0();
  ~GPU_REWARDPV3Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV3Impulse1:public IntervalOfTimeImpulse
{
 public:
  INTERMEDIATE_MEMORY_MODELSAN *INTERMEDIATE_MEMORY_MODEL;

  GPU_REWARDPV3Impulse1();
  ~GPU_REWARDPV3Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV3Impulse2:public IntervalOfTimeImpulse
{
 public:
  INTERMEDIATE_MEMORY_MODELSAN *INTERMEDIATE_MEMORY_MODEL;

  GPU_REWARDPV3Impulse2();
  ~GPU_REWARDPV3Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV3Impulse3:public IntervalOfTimeImpulse
{
 public:
  INTERMEDIATE_MEMORY_MODELSAN *INTERMEDIATE_MEMORY_MODEL;

  GPU_REWARDPV3Impulse3();
  ~GPU_REWARDPV3Impulse3();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV3Impulse4:public IntervalOfTimeImpulse
{
 public:
  INTERMEDIATE_MEMORY_MODELSAN *INTERMEDIATE_MEMORY_MODEL;

  GPU_REWARDPV3Impulse4();
  ~GPU_REWARDPV3Impulse4();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV3Impulse5:public IntervalOfTimeImpulse
{
 public:
  INTERMEDIATE_MEMORY_MODELSAN *INTERMEDIATE_MEMORY_MODEL;

  GPU_REWARDPV3Impulse5();
  ~GPU_REWARDPV3Impulse5();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV3:public PerformanceVariableNode
{
 public:
  GPURJ *TheGPURJ;

  GPU_REWARDPV3Impulse0 Impulse0;
  GPU_REWARDPV3Impulse1 Impulse1;
  GPU_REWARDPV3Impulse2 Impulse2;
  GPU_REWARDPV3Impulse3 Impulse3;
  GPU_REWARDPV3Impulse4 Impulse4;
  GPU_REWARDPV3Impulse5 Impulse5;

  GPU_REWARDPV3(int timeindex=0);
  ~GPU_REWARDPV3();
  void CreateWorkerList(void);
};


class GPU_REWARDPV4Impulse0:public IntervalOfTimeImpulse
{
 public:
  FINAL_MEMORY_MODELSAN *FINAL_MEMORY_MODEL;

  GPU_REWARDPV4Impulse0();
  ~GPU_REWARDPV4Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV4Impulse1:public IntervalOfTimeImpulse
{
 public:
  FINAL_MEMORY_MODELSAN *FINAL_MEMORY_MODEL;

  GPU_REWARDPV4Impulse1();
  ~GPU_REWARDPV4Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV4:public PerformanceVariableNode
{
 public:
  GPURJ *TheGPURJ;

  GPU_REWARDPV4Impulse0 Impulse0;
  GPU_REWARDPV4Impulse1 Impulse1;

  GPU_REWARDPV4(int timeindex=0);
  ~GPU_REWARDPV4();
  void CreateWorkerList(void);
};


class GPU_REWARDPV5Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU_REWARDPV5Impulse0();
  ~GPU_REWARDPV5Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV5Impulse1:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU_REWARDPV5Impulse1();
  ~GPU_REWARDPV5Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV5:public PerformanceVariableNode
{
 public:
  GPURJ *TheGPURJ;

  GPU_REWARDPV5Impulse0 Impulse0;
  GPU_REWARDPV5Impulse1 Impulse1;

  GPU_REWARDPV5(int timeindex=0);
  ~GPU_REWARDPV5();
  void CreateWorkerList(void);
};


class GPU_REWARDPV6Impulse0:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU_REWARDPV6Impulse0();
  ~GPU_REWARDPV6Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV6Impulse1:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU_REWARDPV6Impulse1();
  ~GPU_REWARDPV6Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_REWARDPV6:public PerformanceVariableNode
{
 public:
  GPURJ *TheGPURJ;

  GPU_REWARDPV6Impulse0 Impulse0;
  GPU_REWARDPV6Impulse1 Impulse1;

  GPU_REWARDPV6(int timeindex=0);
  ~GPU_REWARDPV6();
  void CreateWorkerList(void);
};


class GPU_REWARDPV7Impulse0:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

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
  L2_CACHESAN *L2_CACHE;

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
  GPURJ *TheGPURJ;

  GPU_REWARDPV7Impulse0 Impulse0;
  GPU_REWARDPV7Impulse1 Impulse1;

  GPU_REWARDPV7(int timeindex=0);
  ~GPU_REWARDPV7();
  void CreateWorkerList(void);
};


class GPU_REWARDPV8Impulse0:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

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
  L1_CACHESAN *L1_CACHE;

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
  GPURJ *TheGPURJ;

  GPU_REWARDPV8Impulse0 Impulse0;
  GPU_REWARDPV8Impulse1 Impulse1;

  GPU_REWARDPV8(int timeindex=0);
  ~GPU_REWARDPV8();
  void CreateWorkerList(void);
};


class GPU_REWARDPV9Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

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
  COMPUTE_UNITSAN *COMPUTE_UNIT;

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
  GPURJ *TheGPURJ;

  GPU_REWARDPV9Impulse0 Impulse0;
  GPU_REWARDPV9Impulse1 Impulse1;

  GPU_REWARDPV9(int timeindex=0);
  ~GPU_REWARDPV9();
  void CreateWorkerList(void);
};

#endif
