#ifndef _GPU4_PVS_
#define _GPU4_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Composed/GPU4/GPU4RJ__Rep1.h"
#include "Composed/GPU4/GPU4RJ__PROCESSOR_REP.h"
#include "Composed/GPU4/GPU4RJ__PROCESSOR.h"
#include "Composed/GPU4/GPU4RJ__STREAMING_MULTIPROCESSOR.h"
#include "Composed/GPU4/GPU4RJ.h"
#include "Cpp/Performance_Variables/IntervalOfTime.hpp"
#include "Cpp/Performance_Variables/IntervalOfTimeImpulse.hpp"

extern Short end;


class GPU4PV0Impulse0:public IntervalOfTimeImpulse
{
 public:
  WARPSAN *WARP;

  GPU4PV0Impulse0();
  ~GPU4PV0Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4PV0:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4PV0Impulse0 Impulse0;

  GPU4PV0(int timeindex=0);
  ~GPU4PV0();
  void CreateWorkerList(void);
};


class GPU4PV1Impulse0:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU4PV1Impulse0();
  ~GPU4PV1Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV1Impulse1:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU4PV1Impulse1();
  ~GPU4PV1Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4PV1:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4PV1Impulse0 Impulse0;
  GPU4PV1Impulse1 Impulse1;

  GPU4PV1(int timeindex=0);
  ~GPU4PV1();
  void CreateWorkerList(void);
};


class GPU4PV2Impulse0:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU4PV2Impulse0();
  ~GPU4PV2Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV2Impulse1:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU4PV2Impulse1();
  ~GPU4PV2Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4PV2:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4PV2Impulse0 Impulse0;
  GPU4PV2Impulse1 Impulse1;

  GPU4PV2(int timeindex=0);
  ~GPU4PV2();
  void CreateWorkerList(void);
};


class GPU4PV3Impulse0:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU4PV3Impulse0();
  ~GPU4PV3Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV3Impulse1:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU4PV3Impulse1();
  ~GPU4PV3Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4PV3:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4PV3Impulse0 Impulse0;
  GPU4PV3Impulse1 Impulse1;

  GPU4PV3(int timeindex=0);
  ~GPU4PV3();
  void CreateWorkerList(void);
};


class GPU4PV4Impulse0:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU4PV4Impulse0();
  ~GPU4PV4Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV4Impulse1:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU4PV4Impulse1();
  ~GPU4PV4Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4PV4:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4PV4Impulse0 Impulse0;
  GPU4PV4Impulse1 Impulse1;

  GPU4PV4(int timeindex=0);
  ~GPU4PV4();
  void CreateWorkerList(void);
};


class GPU4PV5Impulse0:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU4PV5Impulse0();
  ~GPU4PV5Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV5Impulse1:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU4PV5Impulse1();
  ~GPU4PV5Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4PV5:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4PV5Impulse0 Impulse0;
  GPU4PV5Impulse1 Impulse1;

  GPU4PV5(int timeindex=0);
  ~GPU4PV5();
  void CreateWorkerList(void);
};


class GPU4PV6Impulse0:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU4PV6Impulse0();
  ~GPU4PV6Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV6Impulse1:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU4PV6Impulse1();
  ~GPU4PV6Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4PV6:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4PV6Impulse0 Impulse0;
  GPU4PV6Impulse1 Impulse1;

  GPU4PV6(int timeindex=0);
  ~GPU4PV6();
  void CreateWorkerList(void);
};


class GPU4PV7Impulse0:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  WARPSAN *WARP;

  GPU4PV7Impulse0();
  ~GPU4PV7Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse1:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  WARPSAN *WARP;

  GPU4PV7Impulse1();
  ~GPU4PV7Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse2:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  WARPSAN *WARP;

  GPU4PV7Impulse2();
  ~GPU4PV7Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse3:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse3();
  ~GPU4PV7Impulse3();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse4:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse4();
  ~GPU4PV7Impulse4();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse5:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse5();
  ~GPU4PV7Impulse5();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse6:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse6();
  ~GPU4PV7Impulse6();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse7:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse7();
  ~GPU4PV7Impulse7();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse8:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse8();
  ~GPU4PV7Impulse8();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse9:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse9();
  ~GPU4PV7Impulse9();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse10:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse10();
  ~GPU4PV7Impulse10();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse11:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse11();
  ~GPU4PV7Impulse11();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse12:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse12();
  ~GPU4PV7Impulse12();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse13:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  WARPSAN *WARP;

  GPU4PV7Impulse13();
  ~GPU4PV7Impulse13();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse14:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse14();
  ~GPU4PV7Impulse14();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse15:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse15();
  ~GPU4PV7Impulse15();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse16:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse16();
  ~GPU4PV7Impulse16();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse17:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse17();
  ~GPU4PV7Impulse17();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse18:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse18();
  ~GPU4PV7Impulse18();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse19:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse19();
  ~GPU4PV7Impulse19();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV7Impulse20:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4PV7Impulse20();
  ~GPU4PV7Impulse20();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4PV7:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4PV7Impulse0 Impulse0;
  GPU4PV7Impulse1 Impulse1;
  GPU4PV7Impulse2 Impulse2;
  GPU4PV7Impulse3 Impulse3;
  GPU4PV7Impulse4 Impulse4;
  GPU4PV7Impulse5 Impulse5;
  GPU4PV7Impulse6 Impulse6;
  GPU4PV7Impulse7 Impulse7;
  GPU4PV7Impulse8 Impulse8;
  GPU4PV7Impulse9 Impulse9;
  GPU4PV7Impulse10 Impulse10;
  GPU4PV7Impulse11 Impulse11;
  GPU4PV7Impulse12 Impulse12;
  GPU4PV7Impulse13 Impulse13;
  GPU4PV7Impulse14 Impulse14;
  GPU4PV7Impulse15 Impulse15;
  GPU4PV7Impulse16 Impulse16;
  GPU4PV7Impulse17 Impulse17;
  GPU4PV7Impulse18 Impulse18;
  GPU4PV7Impulse19 Impulse19;
  GPU4PV7Impulse20 Impulse20;

  GPU4PV7(int timeindex=0);
  ~GPU4PV7();
  void CreateWorkerList(void);
};


class GPU4PV8Impulse0:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;

  GPU4PV8Impulse0();
  ~GPU4PV8Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV8Impulse1:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;

  GPU4PV8Impulse1();
  ~GPU4PV8Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4PV8:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4PV8Impulse0 Impulse0;
  GPU4PV8Impulse1 Impulse1;

  GPU4PV8(int timeindex=0);
  ~GPU4PV8();
  void CreateWorkerList(void);
};


class GPU4PV9Impulse0:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;

  GPU4PV9Impulse0();
  ~GPU4PV9Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4PV9Impulse1:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;

  GPU4PV9Impulse1();
  ~GPU4PV9Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4PV9:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4PV9Impulse0 Impulse0;
  GPU4PV9Impulse1 Impulse1;

  GPU4PV9(int timeindex=0);
  ~GPU4PV9();
  void CreateWorkerList(void);
};


class GPU4PV10Impulse0:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;

  GPU4PV10Impulse0();
  ~GPU4PV10Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4PV10:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4PV10Impulse0 Impulse0;

  GPU4PV10(int timeindex=0);
  ~GPU4PV10();
  void CreateWorkerList(void);
};

#endif
