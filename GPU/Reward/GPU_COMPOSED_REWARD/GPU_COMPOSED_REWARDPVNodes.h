#ifndef _GPU_COMPOSED_REWARD_PVS_
#define _GPU_COMPOSED_REWARD_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Composed/GPU/GPURJ.h"
#include "Cpp/Performance_Variables/IntervalOfTime.hpp"
#include "Cpp/Performance_Variables/IntervalOfTimeImpulse.hpp"



class GPU_COMPOSED_REWARDPV0Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU_COMPOSED_REWARDPV0Impulse0();
  ~GPU_COMPOSED_REWARDPV0Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_REWARDPV0:public PerformanceVariableNode
{
 public:
  GPURJ *TheGPURJ;

  GPU_COMPOSED_REWARDPV0Impulse0 Impulse0;

  GPU_COMPOSED_REWARDPV0(int timeindex=0);
  ~GPU_COMPOSED_REWARDPV0();
  void CreateWorkerList(void);
};


class GPU_COMPOSED_REWARDPV1Impulse0:public IntervalOfTimeImpulse
{
 public:
  RESULT_MEMORY_MODELSAN *RESULT_MEMORY;

  GPU_COMPOSED_REWARDPV1Impulse0();
  ~GPU_COMPOSED_REWARDPV1Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_REWARDPV1:public PerformanceVariableNode
{
 public:
  GPURJ *TheGPURJ;

  GPU_COMPOSED_REWARDPV1Impulse0 Impulse0;

  GPU_COMPOSED_REWARDPV1(int timeindex=0);
  ~GPU_COMPOSED_REWARDPV1();
  void CreateWorkerList(void);
};


class GPU_COMPOSED_REWARDPV2Impulse0:public IntervalOfTimeImpulse
{
 public:
  RESULT_MEMORY_MODELSAN *RESULT_MEMORY;

  GPU_COMPOSED_REWARDPV2Impulse0();
  ~GPU_COMPOSED_REWARDPV2Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_REWARDPV2:public PerformanceVariableNode
{
 public:
  GPURJ *TheGPURJ;

  GPU_COMPOSED_REWARDPV2Impulse0 Impulse0;

  GPU_COMPOSED_REWARDPV2(int timeindex=0);
  ~GPU_COMPOSED_REWARDPV2();
  void CreateWorkerList(void);
};


class GPU_COMPOSED_REWARDPV3Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU_COMPOSED_REWARDPV3Impulse0();
  ~GPU_COMPOSED_REWARDPV3Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_REWARDPV3:public PerformanceVariableNode
{
 public:
  GPURJ *TheGPURJ;

  GPU_COMPOSED_REWARDPV3Impulse0 Impulse0;

  GPU_COMPOSED_REWARDPV3(int timeindex=0);
  ~GPU_COMPOSED_REWARDPV3();
  void CreateWorkerList(void);
};


class GPU_COMPOSED_REWARDPV4Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU_COMPOSED_REWARDPV4Impulse0();
  ~GPU_COMPOSED_REWARDPV4Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_REWARDPV4:public PerformanceVariableNode
{
 public:
  GPURJ *TheGPURJ;

  GPU_COMPOSED_REWARDPV4Impulse0 Impulse0;

  GPU_COMPOSED_REWARDPV4(int timeindex=0);
  ~GPU_COMPOSED_REWARDPV4();
  void CreateWorkerList(void);
};


class GPU_COMPOSED_REWARDPV5Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  TOTAL_MEMORY_MODELSAN *TOTAL_MEMORY;
  OUTPUT_MEMORY_MODELSAN *OUTPUT_MEMORY;
  RESULT_MEMORY_MODELSAN *RESULT_MEMORY;

  GPU_COMPOSED_REWARDPV5Impulse0();
  ~GPU_COMPOSED_REWARDPV5Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_REWARDPV5Impulse1:public IntervalOfTimeImpulse
{
 public:
  RESULT_MEMORY_MODELSAN *RESULT_MEMORY;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  TOTAL_MEMORY_MODELSAN *TOTAL_MEMORY;
  OUTPUT_MEMORY_MODELSAN *OUTPUT_MEMORY;

  GPU_COMPOSED_REWARDPV5Impulse1();
  ~GPU_COMPOSED_REWARDPV5Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_REWARDPV5Impulse2:public IntervalOfTimeImpulse
{
 public:
  OUTPUT_MEMORY_MODELSAN *OUTPUT_MEMORY;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  TOTAL_MEMORY_MODELSAN *TOTAL_MEMORY;
  RESULT_MEMORY_MODELSAN *RESULT_MEMORY;

  GPU_COMPOSED_REWARDPV5Impulse2();
  ~GPU_COMPOSED_REWARDPV5Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_REWARDPV5Impulse3:public IntervalOfTimeImpulse
{
 public:
  TOTAL_MEMORY_MODELSAN *TOTAL_MEMORY;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  OUTPUT_MEMORY_MODELSAN *OUTPUT_MEMORY;
  RESULT_MEMORY_MODELSAN *RESULT_MEMORY;

  GPU_COMPOSED_REWARDPV5Impulse3();
  ~GPU_COMPOSED_REWARDPV5Impulse3();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_REWARDPV5Impulse4:public IntervalOfTimeImpulse
{
 public:
  RESULT_MEMORY_MODELSAN *RESULT_MEMORY;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  TOTAL_MEMORY_MODELSAN *TOTAL_MEMORY;
  OUTPUT_MEMORY_MODELSAN *OUTPUT_MEMORY;

  GPU_COMPOSED_REWARDPV5Impulse4();
  ~GPU_COMPOSED_REWARDPV5Impulse4();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_REWARDPV5Impulse5:public IntervalOfTimeImpulse
{
 public:
  RESULT_MEMORY_MODELSAN *RESULT_MEMORY;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  TOTAL_MEMORY_MODELSAN *TOTAL_MEMORY;
  OUTPUT_MEMORY_MODELSAN *OUTPUT_MEMORY;

  GPU_COMPOSED_REWARDPV5Impulse5();
  ~GPU_COMPOSED_REWARDPV5Impulse5();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_REWARDPV5Impulse6:public IntervalOfTimeImpulse
{
 public:
  TOTAL_MEMORY_MODELSAN *TOTAL_MEMORY;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  OUTPUT_MEMORY_MODELSAN *OUTPUT_MEMORY;
  RESULT_MEMORY_MODELSAN *RESULT_MEMORY;

  GPU_COMPOSED_REWARDPV5Impulse6();
  ~GPU_COMPOSED_REWARDPV5Impulse6();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_REWARDPV5Impulse7:public IntervalOfTimeImpulse
{
 public:
  OUTPUT_MEMORY_MODELSAN *OUTPUT_MEMORY;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  TOTAL_MEMORY_MODELSAN *TOTAL_MEMORY;
  RESULT_MEMORY_MODELSAN *RESULT_MEMORY;

  GPU_COMPOSED_REWARDPV5Impulse7();
  ~GPU_COMPOSED_REWARDPV5Impulse7();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_REWARDPV5Impulse8:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  TOTAL_MEMORY_MODELSAN *TOTAL_MEMORY;
  OUTPUT_MEMORY_MODELSAN *OUTPUT_MEMORY;
  RESULT_MEMORY_MODELSAN *RESULT_MEMORY;

  GPU_COMPOSED_REWARDPV5Impulse8();
  ~GPU_COMPOSED_REWARDPV5Impulse8();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_REWARDPV5Impulse9:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  TOTAL_MEMORY_MODELSAN *TOTAL_MEMORY;
  OUTPUT_MEMORY_MODELSAN *OUTPUT_MEMORY;
  RESULT_MEMORY_MODELSAN *RESULT_MEMORY;

  GPU_COMPOSED_REWARDPV5Impulse9();
  ~GPU_COMPOSED_REWARDPV5Impulse9();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_COMPOSED_REWARDPV5Impulse10:public IntervalOfTimeImpulse
{
 public:
  RESULT_MEMORY_MODELSAN *RESULT_MEMORY;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  TOTAL_MEMORY_MODELSAN *TOTAL_MEMORY;
  OUTPUT_MEMORY_MODELSAN *OUTPUT_MEMORY;

  GPU_COMPOSED_REWARDPV5Impulse10();
  ~GPU_COMPOSED_REWARDPV5Impulse10();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_COMPOSED_REWARDPV5:public PerformanceVariableNode
{
 public:
  GPURJ *TheGPURJ;

  GPU_COMPOSED_REWARDPV5Impulse0 Impulse0;
  GPU_COMPOSED_REWARDPV5Impulse1 Impulse1;
  GPU_COMPOSED_REWARDPV5Impulse2 Impulse2;
  GPU_COMPOSED_REWARDPV5Impulse3 Impulse3;
  GPU_COMPOSED_REWARDPV5Impulse4 Impulse4;
  GPU_COMPOSED_REWARDPV5Impulse5 Impulse5;
  GPU_COMPOSED_REWARDPV5Impulse6 Impulse6;
  GPU_COMPOSED_REWARDPV5Impulse7 Impulse7;
  GPU_COMPOSED_REWARDPV5Impulse8 Impulse8;
  GPU_COMPOSED_REWARDPV5Impulse9 Impulse9;
  GPU_COMPOSED_REWARDPV5Impulse10 Impulse10;

  GPU_COMPOSED_REWARDPV5(int timeindex=0);
  ~GPU_COMPOSED_REWARDPV5();
  void CreateWorkerList(void);
};

#endif
