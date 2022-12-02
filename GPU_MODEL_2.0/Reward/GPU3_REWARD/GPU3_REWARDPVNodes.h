#ifndef _GPU3_REWARD_PVS_
#define _GPU3_REWARD_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Composed/GPU3/GPU3RJ__Rep1.h"
#include "Composed/GPU3/GPU3RJ__PROCESSOR.h"
#include "Composed/GPU3/GPU3RJ__STREAMING_MULTIPROCESSOR.h"
#include "Composed/GPU3/GPU3RJ.h"
#include "Cpp/Performance_Variables/IntervalOfTime.hpp"
#include "Cpp/Performance_Variables/IntervalOfTimeImpulse.hpp"

extern Short end;


class GPU3_REWARDPV0Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU3_REWARDPV0Impulse0();
  ~GPU3_REWARDPV0Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU3_REWARDPV0:public PerformanceVariableNode
{
 public:
  GPU3RJ *TheGPU3RJ;

  GPU3_REWARDPV0Impulse0 Impulse0;

  GPU3_REWARDPV0(int timeindex=0);
  ~GPU3_REWARDPV0();
  void CreateWorkerList(void);
};


class GPU3_REWARDPV1Impulse0:public IntervalOfTimeImpulse
{
 public:
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;
  REGISTER_FILESAN *REGISTER_FILE;

  GPU3_REWARDPV1Impulse0();
  ~GPU3_REWARDPV1Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV1Impulse1:public IntervalOfTimeImpulse
{
 public:
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;
  REGISTER_FILESAN *REGISTER_FILE;

  GPU3_REWARDPV1Impulse1();
  ~GPU3_REWARDPV1Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV1Impulse2:public IntervalOfTimeImpulse
{
 public:
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;
  REGISTER_FILESAN *REGISTER_FILE;

  GPU3_REWARDPV1Impulse2();
  ~GPU3_REWARDPV1Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV1Impulse3:public IntervalOfTimeImpulse
{
 public:
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  REGISTER_FILESAN *REGISTER_FILE;

  GPU3_REWARDPV1Impulse3();
  ~GPU3_REWARDPV1Impulse3();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV1Impulse4:public IntervalOfTimeImpulse
{
 public:
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  REGISTER_FILESAN *REGISTER_FILE;

  GPU3_REWARDPV1Impulse4();
  ~GPU3_REWARDPV1Impulse4();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV1Impulse5:public IntervalOfTimeImpulse
{
 public:
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  REGISTER_FILESAN *REGISTER_FILE;

  GPU3_REWARDPV1Impulse5();
  ~GPU3_REWARDPV1Impulse5();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV1Impulse6:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;

  GPU3_REWARDPV1Impulse6();
  ~GPU3_REWARDPV1Impulse6();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV1Impulse7:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;

  GPU3_REWARDPV1Impulse7();
  ~GPU3_REWARDPV1Impulse7();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU3_REWARDPV1:public PerformanceVariableNode
{
 public:
  GPU3RJ *TheGPU3RJ;

  GPU3_REWARDPV1Impulse0 Impulse0;
  GPU3_REWARDPV1Impulse1 Impulse1;
  GPU3_REWARDPV1Impulse2 Impulse2;
  GPU3_REWARDPV1Impulse3 Impulse3;
  GPU3_REWARDPV1Impulse4 Impulse4;
  GPU3_REWARDPV1Impulse5 Impulse5;
  GPU3_REWARDPV1Impulse6 Impulse6;
  GPU3_REWARDPV1Impulse7 Impulse7;

  GPU3_REWARDPV1(int timeindex=0);
  ~GPU3_REWARDPV1();
  void CreateWorkerList(void);
};


class GPU3_REWARDPV2Impulse0:public IntervalOfTimeImpulse
{
 public:
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;
  REGISTER_FILESAN *REGISTER_FILE;
  OUTPUT_MEMORYSAN *OUTPUT_MEMORY;

  GPU3_REWARDPV2Impulse0();
  ~GPU3_REWARDPV2Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV2Impulse1:public IntervalOfTimeImpulse
{
 public:
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;
  REGISTER_FILESAN *REGISTER_FILE;
  OUTPUT_MEMORYSAN *OUTPUT_MEMORY;

  GPU3_REWARDPV2Impulse1();
  ~GPU3_REWARDPV2Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV2Impulse2:public IntervalOfTimeImpulse
{
 public:
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;
  REGISTER_FILESAN *REGISTER_FILE;
  OUTPUT_MEMORYSAN *OUTPUT_MEMORY;

  GPU3_REWARDPV2Impulse2();
  ~GPU3_REWARDPV2Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV2Impulse3:public IntervalOfTimeImpulse
{
 public:
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  REGISTER_FILESAN *REGISTER_FILE;
  OUTPUT_MEMORYSAN *OUTPUT_MEMORY;

  GPU3_REWARDPV2Impulse3();
  ~GPU3_REWARDPV2Impulse3();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV2Impulse4:public IntervalOfTimeImpulse
{
 public:
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  REGISTER_FILESAN *REGISTER_FILE;
  OUTPUT_MEMORYSAN *OUTPUT_MEMORY;

  GPU3_REWARDPV2Impulse4();
  ~GPU3_REWARDPV2Impulse4();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV2Impulse5:public IntervalOfTimeImpulse
{
 public:
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  REGISTER_FILESAN *REGISTER_FILE;
  OUTPUT_MEMORYSAN *OUTPUT_MEMORY;

  GPU3_REWARDPV2Impulse5();
  ~GPU3_REWARDPV2Impulse5();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV2Impulse6:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;
  OUTPUT_MEMORYSAN *OUTPUT_MEMORY;

  GPU3_REWARDPV2Impulse6();
  ~GPU3_REWARDPV2Impulse6();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV2Impulse7:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;
  OUTPUT_MEMORYSAN *OUTPUT_MEMORY;

  GPU3_REWARDPV2Impulse7();
  ~GPU3_REWARDPV2Impulse7();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV2Impulse8:public IntervalOfTimeImpulse
{
 public:
  OUTPUT_MEMORYSAN *OUTPUT_MEMORY;
  LOCAL_MEMORYSAN *LOCAL_MEMORY;
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;
  REGISTER_FILESAN *REGISTER_FILE;

  GPU3_REWARDPV2Impulse8();
  ~GPU3_REWARDPV2Impulse8();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU3_REWARDPV2:public PerformanceVariableNode
{
 public:
  GPU3RJ *TheGPU3RJ;

  GPU3_REWARDPV2Impulse0 Impulse0;
  GPU3_REWARDPV2Impulse1 Impulse1;
  GPU3_REWARDPV2Impulse2 Impulse2;
  GPU3_REWARDPV2Impulse3 Impulse3;
  GPU3_REWARDPV2Impulse4 Impulse4;
  GPU3_REWARDPV2Impulse5 Impulse5;
  GPU3_REWARDPV2Impulse6 Impulse6;
  GPU3_REWARDPV2Impulse7 Impulse7;
  GPU3_REWARDPV2Impulse8 Impulse8;

  GPU3_REWARDPV2(int timeindex=0);
  ~GPU3_REWARDPV2();
  void CreateWorkerList(void);
};


class GPU3_REWARDPV3Impulse0:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU3_REWARDPV3Impulse0();
  ~GPU3_REWARDPV3Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV3Impulse1:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU3_REWARDPV3Impulse1();
  ~GPU3_REWARDPV3Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU3_REWARDPV3:public PerformanceVariableNode
{
 public:
  GPU3RJ *TheGPU3RJ;

  GPU3_REWARDPV3Impulse0 Impulse0;
  GPU3_REWARDPV3Impulse1 Impulse1;

  GPU3_REWARDPV3(int timeindex=0);
  ~GPU3_REWARDPV3();
  void CreateWorkerList(void);
};


class GPU3_REWARDPV4Impulse0:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU3_REWARDPV4Impulse0();
  ~GPU3_REWARDPV4Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV4Impulse1:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU3_REWARDPV4Impulse1();
  ~GPU3_REWARDPV4Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU3_REWARDPV4:public PerformanceVariableNode
{
 public:
  GPU3RJ *TheGPU3RJ;

  GPU3_REWARDPV4Impulse0 Impulse0;
  GPU3_REWARDPV4Impulse1 Impulse1;

  GPU3_REWARDPV4(int timeindex=0);
  ~GPU3_REWARDPV4();
  void CreateWorkerList(void);
};


class GPU3_REWARDPV5Impulse0:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU3_REWARDPV5Impulse0();
  ~GPU3_REWARDPV5Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV5Impulse1:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU3_REWARDPV5Impulse1();
  ~GPU3_REWARDPV5Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU3_REWARDPV5:public PerformanceVariableNode
{
 public:
  GPU3RJ *TheGPU3RJ;

  GPU3_REWARDPV5Impulse0 Impulse0;
  GPU3_REWARDPV5Impulse1 Impulse1;

  GPU3_REWARDPV5(int timeindex=0);
  ~GPU3_REWARDPV5();
  void CreateWorkerList(void);
};


class GPU3_REWARDPV6Impulse0:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU3_REWARDPV6Impulse0();
  ~GPU3_REWARDPV6Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV6Impulse1:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU3_REWARDPV6Impulse1();
  ~GPU3_REWARDPV6Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU3_REWARDPV6:public PerformanceVariableNode
{
 public:
  GPU3RJ *TheGPU3RJ;

  GPU3_REWARDPV6Impulse0 Impulse0;
  GPU3_REWARDPV6Impulse1 Impulse1;

  GPU3_REWARDPV6(int timeindex=0);
  ~GPU3_REWARDPV6();
  void CreateWorkerList(void);
};


class GPU3_REWARDPV7Impulse0:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU3_REWARDPV7Impulse0();
  ~GPU3_REWARDPV7Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV7Impulse1:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU3_REWARDPV7Impulse1();
  ~GPU3_REWARDPV7Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU3_REWARDPV7:public PerformanceVariableNode
{
 public:
  GPU3RJ *TheGPU3RJ;

  GPU3_REWARDPV7Impulse0 Impulse0;
  GPU3_REWARDPV7Impulse1 Impulse1;

  GPU3_REWARDPV7(int timeindex=0);
  ~GPU3_REWARDPV7();
  void CreateWorkerList(void);
};


class GPU3_REWARDPV8Impulse0:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU3_REWARDPV8Impulse0();
  ~GPU3_REWARDPV8Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU3_REWARDPV8Impulse1:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU3_REWARDPV8Impulse1();
  ~GPU3_REWARDPV8Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU3_REWARDPV8:public PerformanceVariableNode
{
 public:
  GPU3RJ *TheGPU3RJ;

  GPU3_REWARDPV8Impulse0 Impulse0;
  GPU3_REWARDPV8Impulse1 Impulse1;

  GPU3_REWARDPV8(int timeindex=0);
  ~GPU3_REWARDPV8();
  void CreateWorkerList(void);
};


class GPU3_REWARDPV9Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU3_REWARDPV9Impulse0();
  ~GPU3_REWARDPV9Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU3_REWARDPV9:public PerformanceVariableNode
{
 public:
  GPU3RJ *TheGPU3RJ;

  GPU3_REWARDPV9Impulse0 Impulse0;

  GPU3_REWARDPV9(int timeindex=0);
  ~GPU3_REWARDPV9();
  void CreateWorkerList(void);
};

class GPU3_REWARDPV10:public PerformanceVariableNode
{
 public:
  GPU3RJ *TheGPU3RJ;


  GPU3_REWARDPV10(int timeindex=0);
  ~GPU3_REWARDPV10();
  void CreateWorkerList(void);
};


class GPU3_REWARDPV11Impulse0:public IntervalOfTimeImpulse
{
 public:
  WARPSAN *WARP3;

  GPU3_REWARDPV11Impulse0();
  ~GPU3_REWARDPV11Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU3_REWARDPV11:public PerformanceVariableNode
{
 public:
  GPU3RJ *TheGPU3RJ;

  GPU3_REWARDPV11Impulse0 Impulse0;

  GPU3_REWARDPV11(int timeindex=0);
  ~GPU3_REWARDPV11();
  void CreateWorkerList(void);
};

#endif
