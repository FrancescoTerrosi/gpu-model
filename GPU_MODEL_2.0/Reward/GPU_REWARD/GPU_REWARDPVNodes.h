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
  DRAMSAN *DRAM;

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
  DRAMSAN *DRAM;

  GPU_REWARDPV1Impulse1();
  ~GPU_REWARDPV1Impulse1();
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

  GPU_REWARDPV1(int timeindex=0);
  ~GPU_REWARDPV1();
  void CreateWorkerList(void);
};


class GPU_REWARDPV2Impulse0:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

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
  L2_CACHESAN *L2_CACHE;

  GPU_REWARDPV2Impulse1();
  ~GPU_REWARDPV2Impulse1();
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

  GPU_REWARDPV2(int timeindex=0);
  ~GPU_REWARDPV2();
  void CreateWorkerList(void);
};


class GPU_REWARDPV3Impulse0:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

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
  L1_CACHESAN *L1_CACHE;

  GPU_REWARDPV3Impulse1();
  ~GPU_REWARDPV3Impulse1();
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

  GPU_REWARDPV3(int timeindex=0);
  ~GPU_REWARDPV3();
  void CreateWorkerList(void);
};


class GPU_REWARDPV4Impulse0:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  DRAMSAN *DRAM;
  REGISTER_FILESAN *REGISTER_FILE;

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
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  DRAMSAN *DRAM;
  REGISTER_FILESAN *REGISTER_FILE;

  GPU_REWARDPV4Impulse1();
  ~GPU_REWARDPV4Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV4Impulse2:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  REGISTER_FILESAN *REGISTER_FILE;

  GPU_REWARDPV4Impulse2();
  ~GPU_REWARDPV4Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV4Impulse3:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  REGISTER_FILESAN *REGISTER_FILE;

  GPU_REWARDPV4Impulse3();
  ~GPU_REWARDPV4Impulse3();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV4Impulse4:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  REGISTER_FILESAN *REGISTER_FILE;

  GPU_REWARDPV4Impulse4();
  ~GPU_REWARDPV4Impulse4();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV4Impulse5:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  REGISTER_FILESAN *REGISTER_FILE;

  GPU_REWARDPV4Impulse5();
  ~GPU_REWARDPV4Impulse5();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV4Impulse6:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  DRAMSAN *DRAM;

  GPU_REWARDPV4Impulse6();
  ~GPU_REWARDPV4Impulse6();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_REWARDPV4Impulse7:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  DRAMSAN *DRAM;

  GPU_REWARDPV4Impulse7();
  ~GPU_REWARDPV4Impulse7();
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
  GPU_REWARDPV4Impulse2 Impulse2;
  GPU_REWARDPV4Impulse3 Impulse3;
  GPU_REWARDPV4Impulse4 Impulse4;
  GPU_REWARDPV4Impulse5 Impulse5;
  GPU_REWARDPV4Impulse6 Impulse6;
  GPU_REWARDPV4Impulse7 Impulse7;

  GPU_REWARDPV4(int timeindex=0);
  ~GPU_REWARDPV4();
  void CreateWorkerList(void);
};

#endif
