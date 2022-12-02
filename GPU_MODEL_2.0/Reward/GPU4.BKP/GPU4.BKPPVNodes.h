#ifndef _GPU4.BKP_PVS_
#define _GPU4.BKP_PVS_
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


class GPU4.BKPPV0Impulse0:public IntervalOfTimeImpulse
{
 public:
  WARPSAN *WARP;

  GPU4.BKPPV0Impulse0();
  ~GPU4.BKPPV0Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4.BKPPV0:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4.BKPPV0Impulse0 Impulse0;

  GPU4.BKPPV0(int timeindex=0);
  ~GPU4.BKPPV0();
  void CreateWorkerList(void);
};


class GPU4.BKPPV1Impulse0:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU4.BKPPV1Impulse0();
  ~GPU4.BKPPV1Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV1Impulse1:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU4.BKPPV1Impulse1();
  ~GPU4.BKPPV1Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4.BKPPV1:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4.BKPPV1Impulse0 Impulse0;
  GPU4.BKPPV1Impulse1 Impulse1;

  GPU4.BKPPV1(int timeindex=0);
  ~GPU4.BKPPV1();
  void CreateWorkerList(void);
};


class GPU4.BKPPV2Impulse0:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU4.BKPPV2Impulse0();
  ~GPU4.BKPPV2Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV2Impulse1:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;

  GPU4.BKPPV2Impulse1();
  ~GPU4.BKPPV2Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4.BKPPV2:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4.BKPPV2Impulse0 Impulse0;
  GPU4.BKPPV2Impulse1 Impulse1;

  GPU4.BKPPV2(int timeindex=0);
  ~GPU4.BKPPV2();
  void CreateWorkerList(void);
};


class GPU4.BKPPV3Impulse0:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU4.BKPPV3Impulse0();
  ~GPU4.BKPPV3Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV3Impulse1:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU4.BKPPV3Impulse1();
  ~GPU4.BKPPV3Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4.BKPPV3:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4.BKPPV3Impulse0 Impulse0;
  GPU4.BKPPV3Impulse1 Impulse1;

  GPU4.BKPPV3(int timeindex=0);
  ~GPU4.BKPPV3();
  void CreateWorkerList(void);
};


class GPU4.BKPPV4Impulse0:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU4.BKPPV4Impulse0();
  ~GPU4.BKPPV4Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV4Impulse1:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;

  GPU4.BKPPV4Impulse1();
  ~GPU4.BKPPV4Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4.BKPPV4:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4.BKPPV4Impulse0 Impulse0;
  GPU4.BKPPV4Impulse1 Impulse1;

  GPU4.BKPPV4(int timeindex=0);
  ~GPU4.BKPPV4();
  void CreateWorkerList(void);
};


class GPU4.BKPPV5Impulse0:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU4.BKPPV5Impulse0();
  ~GPU4.BKPPV5Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV5Impulse1:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU4.BKPPV5Impulse1();
  ~GPU4.BKPPV5Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4.BKPPV5:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4.BKPPV5Impulse0 Impulse0;
  GPU4.BKPPV5Impulse1 Impulse1;

  GPU4.BKPPV5(int timeindex=0);
  ~GPU4.BKPPV5();
  void CreateWorkerList(void);
};


class GPU4.BKPPV6Impulse0:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU4.BKPPV6Impulse0();
  ~GPU4.BKPPV6Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV6Impulse1:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;

  GPU4.BKPPV6Impulse1();
  ~GPU4.BKPPV6Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4.BKPPV6:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4.BKPPV6Impulse0 Impulse0;
  GPU4.BKPPV6Impulse1 Impulse1;

  GPU4.BKPPV6(int timeindex=0);
  ~GPU4.BKPPV6();
  void CreateWorkerList(void);
};


class GPU4.BKPPV7Impulse0:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse0();
  ~GPU4.BKPPV7Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse1:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse1();
  ~GPU4.BKPPV7Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse2:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse2();
  ~GPU4.BKPPV7Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse3:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse3();
  ~GPU4.BKPPV7Impulse3();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse4:public IntervalOfTimeImpulse
{
 public:
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse4();
  ~GPU4.BKPPV7Impulse4();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse5:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse5();
  ~GPU4.BKPPV7Impulse5();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse6:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse6();
  ~GPU4.BKPPV7Impulse6();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse7:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse7();
  ~GPU4.BKPPV7Impulse7();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse8:public IntervalOfTimeImpulse
{
 public:
  REGISTER_FILESAN *REGISTER_FILE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse8();
  ~GPU4.BKPPV7Impulse8();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse9:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse9();
  ~GPU4.BKPPV7Impulse9();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse10:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse10();
  ~GPU4.BKPPV7Impulse10();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse11:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse11();
  ~GPU4.BKPPV7Impulse11();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse12:public IntervalOfTimeImpulse
{
 public:
  L1_CACHESAN *L1_CACHE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  DRAMSAN *DRAM;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse12();
  ~GPU4.BKPPV7Impulse12();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse13:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse13();
  ~GPU4.BKPPV7Impulse13();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse14:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse14();
  ~GPU4.BKPPV7Impulse14();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse15:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse15();
  ~GPU4.BKPPV7Impulse15();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse16:public IntervalOfTimeImpulse
{
 public:
  DRAMSAN *DRAM;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  L2_CACHESAN *L2_CACHE;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse16();
  ~GPU4.BKPPV7Impulse16();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse17:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse17();
  ~GPU4.BKPPV7Impulse17();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse18:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse18();
  ~GPU4.BKPPV7Impulse18();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse19:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse19();
  ~GPU4.BKPPV7Impulse19();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU4.BKPPV7Impulse20:public IntervalOfTimeImpulse
{
 public:
  L2_CACHESAN *L2_CACHE;
  COMPUTE_UNITSAN *COMPUTE_UNIT;
  REGISTER_FILESAN *REGISTER_FILE;
  L1_CACHESAN *L1_CACHE;
  DRAMSAN *DRAM;
  WARPSAN *WARP;

  GPU4.BKPPV7Impulse20();
  ~GPU4.BKPPV7Impulse20();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU4.BKPPV7:public PerformanceVariableNode
{
 public:
  GPU4RJ *TheGPU4RJ;

  GPU4.BKPPV7Impulse0 Impulse0;
  GPU4.BKPPV7Impulse1 Impulse1;
  GPU4.BKPPV7Impulse2 Impulse2;
  GPU4.BKPPV7Impulse3 Impulse3;
  GPU4.BKPPV7Impulse4 Impulse4;
  GPU4.BKPPV7Impulse5 Impulse5;
  GPU4.BKPPV7Impulse6 Impulse6;
  GPU4.BKPPV7Impulse7 Impulse7;
  GPU4.BKPPV7Impulse8 Impulse8;
  GPU4.BKPPV7Impulse9 Impulse9;
  GPU4.BKPPV7Impulse10 Impulse10;
  GPU4.BKPPV7Impulse11 Impulse11;
  GPU4.BKPPV7Impulse12 Impulse12;
  GPU4.BKPPV7Impulse13 Impulse13;
  GPU4.BKPPV7Impulse14 Impulse14;
  GPU4.BKPPV7Impulse15 Impulse15;
  GPU4.BKPPV7Impulse16 Impulse16;
  GPU4.BKPPV7Impulse17 Impulse17;
  GPU4.BKPPV7Impulse18 Impulse18;
  GPU4.BKPPV7Impulse19 Impulse19;
  GPU4.BKPPV7Impulse20 Impulse20;

  GPU4.BKPPV7(int timeindex=0);
  ~GPU4.BKPPV7();
  void CreateWorkerList(void);
};

#endif
