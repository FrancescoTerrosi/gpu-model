#ifndef _GPU_AVERAGE_PVS_
#define _GPU_AVERAGE_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Composed/GPU_AVERAGE/GPU_AVERAGERJ__Join1.h"
#include "Composed/GPU_AVERAGE/GPU_AVERAGERJ__STREAMING_MULTIPROCESSOR.h"
#include "Composed/GPU_AVERAGE/GPU_AVERAGERJ.h"
#include "Cpp/Performance_Variables/IntervalOfTime.hpp"
#include "Cpp/Performance_Variables/IntervalOfTimeImpulse.hpp"

extern Short end;


class GPU_AVERAGEPV0Impulse0:public IntervalOfTimeImpulse
{
 public:
  WARP_AVERAGESAN *WARP_AVERAGE;

  GPU_AVERAGEPV0Impulse0();
  ~GPU_AVERAGEPV0Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_AVERAGEPV0:public PerformanceVariableNode
{
 public:
  GPU_AVERAGERJ *TheGPU_AVERAGERJ;

  GPU_AVERAGEPV0Impulse0 Impulse0;

  GPU_AVERAGEPV0(int timeindex=0);
  ~GPU_AVERAGEPV0();
  void CreateWorkerList(void);
};


class GPU_AVERAGEPV1Impulse0:public IntervalOfTimeImpulse
{
 public:
  LOCAL_MEMORYSAN *LOCAL_MEMORY;

  GPU_AVERAGEPV1Impulse0();
  ~GPU_AVERAGEPV1Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV1Impulse1:public IntervalOfTimeImpulse
{
 public:
  LOCAL_MEMORYSAN *LOCAL_MEMORY;

  GPU_AVERAGEPV1Impulse1();
  ~GPU_AVERAGEPV1Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV1Impulse2:public IntervalOfTimeImpulse
{
 public:
  LOCAL_MEMORYSAN *LOCAL_MEMORY;

  GPU_AVERAGEPV1Impulse2();
  ~GPU_AVERAGEPV1Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV1Impulse3:public IntervalOfTimeImpulse
{
 public:
  LOCAL_MEMORYSAN *LOCAL_MEMORY;

  GPU_AVERAGEPV1Impulse3();
  ~GPU_AVERAGEPV1Impulse3();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV1Impulse4:public IntervalOfTimeImpulse
{
 public:
  LOCAL_MEMORYSAN *LOCAL_MEMORY;

  GPU_AVERAGEPV1Impulse4();
  ~GPU_AVERAGEPV1Impulse4();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV1Impulse5:public IntervalOfTimeImpulse
{
 public:
  LOCAL_MEMORYSAN *LOCAL_MEMORY;

  GPU_AVERAGEPV1Impulse5();
  ~GPU_AVERAGEPV1Impulse5();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_AVERAGEPV1:public PerformanceVariableNode
{
 public:
  GPU_AVERAGERJ *TheGPU_AVERAGERJ;

  GPU_AVERAGEPV1Impulse0 Impulse0;
  GPU_AVERAGEPV1Impulse1 Impulse1;
  GPU_AVERAGEPV1Impulse2 Impulse2;
  GPU_AVERAGEPV1Impulse3 Impulse3;
  GPU_AVERAGEPV1Impulse4 Impulse4;
  GPU_AVERAGEPV1Impulse5 Impulse5;

  GPU_AVERAGEPV1(int timeindex=0);
  ~GPU_AVERAGEPV1();
  void CreateWorkerList(void);
};


class GPU_AVERAGEPV2Impulse0:public IntervalOfTimeImpulse
{
 public:
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;

  GPU_AVERAGEPV2Impulse0();
  ~GPU_AVERAGEPV2Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV2Impulse1:public IntervalOfTimeImpulse
{
 public:
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;

  GPU_AVERAGEPV2Impulse1();
  ~GPU_AVERAGEPV2Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV2Impulse2:public IntervalOfTimeImpulse
{
 public:
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;

  GPU_AVERAGEPV2Impulse2();
  ~GPU_AVERAGEPV2Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV2Impulse3:public IntervalOfTimeImpulse
{
 public:
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;

  GPU_AVERAGEPV2Impulse3();
  ~GPU_AVERAGEPV2Impulse3();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV2Impulse4:public IntervalOfTimeImpulse
{
 public:
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;

  GPU_AVERAGEPV2Impulse4();
  ~GPU_AVERAGEPV2Impulse4();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV2Impulse5:public IntervalOfTimeImpulse
{
 public:
  GLOBAL_MEMORYSAN *GLOBAL_MEMORY;

  GPU_AVERAGEPV2Impulse5();
  ~GPU_AVERAGEPV2Impulse5();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_AVERAGEPV2:public PerformanceVariableNode
{
 public:
  GPU_AVERAGERJ *TheGPU_AVERAGERJ;

  GPU_AVERAGEPV2Impulse0 Impulse0;
  GPU_AVERAGEPV2Impulse1 Impulse1;
  GPU_AVERAGEPV2Impulse2 Impulse2;
  GPU_AVERAGEPV2Impulse3 Impulse3;
  GPU_AVERAGEPV2Impulse4 Impulse4;
  GPU_AVERAGEPV2Impulse5 Impulse5;

  GPU_AVERAGEPV2(int timeindex=0);
  ~GPU_AVERAGEPV2();
  void CreateWorkerList(void);
};


class GPU_AVERAGEPV3Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU_AVERAGEPV3Impulse0();
  ~GPU_AVERAGEPV3Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV3Impulse1:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU_AVERAGEPV3Impulse1();
  ~GPU_AVERAGEPV3Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_AVERAGEPV3:public PerformanceVariableNode
{
 public:
  GPU_AVERAGERJ *TheGPU_AVERAGERJ;

  GPU_AVERAGEPV3Impulse0 Impulse0;
  GPU_AVERAGEPV3Impulse1 Impulse1;

  GPU_AVERAGEPV3(int timeindex=0);
  ~GPU_AVERAGEPV3();
  void CreateWorkerList(void);
};


class GPU_AVERAGEPV4Impulse0:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  DRAMSAN *DRAM;

  GPU_AVERAGEPV4Impulse0();
  ~GPU_AVERAGEPV4Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV4Impulse1:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  DRAMSAN *DRAM;

  GPU_AVERAGEPV4Impulse1();
  ~GPU_AVERAGEPV4Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV4Impulse2:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  DRAMSAN *DRAM;

  GPU_AVERAGEPV4Impulse2();
  ~GPU_AVERAGEPV4Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV4Impulse3:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  DRAMSAN *DRAM;

  GPU_AVERAGEPV4Impulse3();
  ~GPU_AVERAGEPV4Impulse3();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV4Impulse4:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;

  GPU_AVERAGEPV4Impulse4();
  ~GPU_AVERAGEPV4Impulse4();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV4Impulse5:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;

  GPU_AVERAGEPV4Impulse5();
  ~GPU_AVERAGEPV4Impulse5();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV4Impulse6:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;

  GPU_AVERAGEPV4Impulse6();
  ~GPU_AVERAGEPV4Impulse6();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV4Impulse7:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;

  GPU_AVERAGEPV4Impulse7();
  ~GPU_AVERAGEPV4Impulse7();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV4Impulse8:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;

  GPU_AVERAGEPV4Impulse8();
  ~GPU_AVERAGEPV4Impulse8();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV4Impulse9:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;

  GPU_AVERAGEPV4Impulse9();
  ~GPU_AVERAGEPV4Impulse9();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV4Impulse10:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;

  GPU_AVERAGEPV4Impulse10();
  ~GPU_AVERAGEPV4Impulse10();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV4Impulse11:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;

  GPU_AVERAGEPV4Impulse11();
  ~GPU_AVERAGEPV4Impulse11();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_AVERAGEPV4:public PerformanceVariableNode
{
 public:
  GPU_AVERAGERJ *TheGPU_AVERAGERJ;

  GPU_AVERAGEPV4Impulse0 Impulse0;
  GPU_AVERAGEPV4Impulse1 Impulse1;
  GPU_AVERAGEPV4Impulse2 Impulse2;
  GPU_AVERAGEPV4Impulse3 Impulse3;
  GPU_AVERAGEPV4Impulse4 Impulse4;
  GPU_AVERAGEPV4Impulse5 Impulse5;
  GPU_AVERAGEPV4Impulse6 Impulse6;
  GPU_AVERAGEPV4Impulse7 Impulse7;
  GPU_AVERAGEPV4Impulse8 Impulse8;
  GPU_AVERAGEPV4Impulse9 Impulse9;
  GPU_AVERAGEPV4Impulse10 Impulse10;
  GPU_AVERAGEPV4Impulse11 Impulse11;

  GPU_AVERAGEPV4(int timeindex=0);
  ~GPU_AVERAGEPV4();
  void CreateWorkerList(void);
};


class GPU_AVERAGEPV5Impulse0:public IntervalOfTimeImpulse
{
 public:
  WARP_AVERAGESAN *WARP_AVERAGE;

  GPU_AVERAGEPV5Impulse0();
  ~GPU_AVERAGEPV5Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_AVERAGEPV5:public PerformanceVariableNode
{
 public:
  GPU_AVERAGERJ *TheGPU_AVERAGERJ;

  GPU_AVERAGEPV5Impulse0 Impulse0;

  GPU_AVERAGEPV5(int timeindex=0);
  ~GPU_AVERAGEPV5();
  void CreateWorkerList(void);
};


class GPU_AVERAGEPV6Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU_AVERAGEPV6Impulse0();
  ~GPU_AVERAGEPV6Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_AVERAGEPV6:public PerformanceVariableNode
{
 public:
  GPU_AVERAGERJ *TheGPU_AVERAGERJ;

  GPU_AVERAGEPV6Impulse0 Impulse0;

  GPU_AVERAGEPV6(int timeindex=0);
  ~GPU_AVERAGEPV6();
  void CreateWorkerList(void);
};


class GPU_AVERAGEPV7Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU_AVERAGEPV7Impulse0();
  ~GPU_AVERAGEPV7Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV7Impulse1:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU_AVERAGEPV7Impulse1();
  ~GPU_AVERAGEPV7Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_AVERAGEPV7:public PerformanceVariableNode
{
 public:
  GPU_AVERAGERJ *TheGPU_AVERAGERJ;

  GPU_AVERAGEPV7Impulse0 Impulse0;
  GPU_AVERAGEPV7Impulse1 Impulse1;

  GPU_AVERAGEPV7(int timeindex=0);
  ~GPU_AVERAGEPV7();
  void CreateWorkerList(void);
};


class GPU_AVERAGEPV8Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU_AVERAGEPV8Impulse0();
  ~GPU_AVERAGEPV8Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_AVERAGEPV8:public PerformanceVariableNode
{
 public:
  GPU_AVERAGERJ *TheGPU_AVERAGERJ;

  GPU_AVERAGEPV8Impulse0 Impulse0;

  GPU_AVERAGEPV8(int timeindex=0);
  ~GPU_AVERAGEPV8();
  void CreateWorkerList(void);
};


class GPU_AVERAGEPV9Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU_AVERAGEPV9Impulse0();
  ~GPU_AVERAGEPV9Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_AVERAGEPV9Impulse1:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;

  GPU_AVERAGEPV9Impulse1();
  ~GPU_AVERAGEPV9Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_AVERAGEPV9:public PerformanceVariableNode
{
 public:
  GPU_AVERAGERJ *TheGPU_AVERAGERJ;

  GPU_AVERAGEPV9Impulse0 Impulse0;
  GPU_AVERAGEPV9Impulse1 Impulse1;

  GPU_AVERAGEPV9(int timeindex=0);
  ~GPU_AVERAGEPV9();
  void CreateWorkerList(void);
};

#endif
