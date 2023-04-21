#ifndef _GPU_FAILURE_PVS_
#define _GPU_FAILURE_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__Rep1.h"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__PROCESSOR_REP.h"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__SM_REP.h"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__Rep2.h"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__PROCESSOR_REP_FAILURE.h"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__PROCESSOR.h"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__STREAMING_MULTIPROCESSOR.h"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ.h"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__WARP_REG.h"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__WARP_REG_FAILURE.h"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__PROCESSOR_FAILURE.h"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__STREAMING_MULTIPROCESSOR_FAILURE.h"
#include "Cpp/Performance_Variables/IntervalOfTime.hpp"
#include "Cpp/Performance_Variables/IntervalOfTimeImpulse.hpp"

extern Short end;
extern Short nwarps;
extern Short nsm;
extern Short nprocessors;


class GPU_FAILUREPV0Impulse0:public IntervalOfTimeImpulse
{
 public:
  WARPSAN *WARP;
  WARPSAN *WARP_FAILURE;

  GPU_FAILUREPV0Impulse0();
  ~GPU_FAILUREPV0Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV0Impulse1:public IntervalOfTimeImpulse
{
 public:
  WARPSAN *WARP_FAILURE;
  WARPSAN *WARP;

  GPU_FAILUREPV0Impulse1();
  ~GPU_FAILUREPV0Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_FAILUREPV0:public PerformanceVariableNode
{
 public:
  GPU_FAILURERJ *TheGPU_FAILURERJ;

  GPU_FAILUREPV0Impulse0 Impulse0;
  GPU_FAILUREPV0Impulse1 Impulse1;

  GPU_FAILUREPV0(int timeindex=0);
  ~GPU_FAILUREPV0();
  void CreateWorkerList(void);
};


class GPU_FAILUREPV1Impulse0:public IntervalOfTimeImpulse
{
 public:
  EXEC_UNITSAN *EXEC_UNIT;

  GPU_FAILUREPV1Impulse0();
  ~GPU_FAILUREPV1Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_FAILUREPV1:public PerformanceVariableNode
{
 public:
  GPU_FAILURERJ *TheGPU_FAILURERJ;

  GPU_FAILUREPV1Impulse0 Impulse0;

  GPU_FAILUREPV1(int timeindex=0);
  ~GPU_FAILUREPV1();
  void CreateWorkerList(void);
};


class GPU_FAILUREPV2Impulse0:public IntervalOfTimeImpulse
{
 public:
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse0();
  ~GPU_FAILUREPV2Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse1:public IntervalOfTimeImpulse
{
 public:
  EXEC_UNITSAN *EXEC_UNIT;
  WARPSAN *WARP;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse1();
  ~GPU_FAILUREPV2Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse2:public IntervalOfTimeImpulse
{
 public:
  EXEC_UNITSAN *EXEC_UNIT;
  WARPSAN *WARP;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse2();
  ~GPU_FAILUREPV2Impulse2();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse3:public IntervalOfTimeImpulse
{
 public:
  WARPSAN *WARP_FAILURE;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse3();
  ~GPU_FAILUREPV2Impulse3();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse4:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse4();
  ~GPU_FAILUREPV2Impulse4();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse5:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse5();
  ~GPU_FAILUREPV2Impulse5();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse6:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse6();
  ~GPU_FAILUREPV2Impulse6();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse7:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse7();
  ~GPU_FAILUREPV2Impulse7();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse8:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse8();
  ~GPU_FAILUREPV2Impulse8();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse9:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse9();
  ~GPU_FAILUREPV2Impulse9();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse10:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse10();
  ~GPU_FAILUREPV2Impulse10();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse11:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse11();
  ~GPU_FAILUREPV2Impulse11();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse12:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse12();
  ~GPU_FAILUREPV2Impulse12();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse13:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse13();
  ~GPU_FAILUREPV2Impulse13();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse14:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse14();
  ~GPU_FAILUREPV2Impulse14();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse15:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse15();
  ~GPU_FAILUREPV2Impulse15();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse16:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY_FAILURE;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;

  GPU_FAILUREPV2Impulse16();
  ~GPU_FAILUREPV2Impulse16();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse17:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY_FAILURE;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;

  GPU_FAILUREPV2Impulse17();
  ~GPU_FAILUREPV2Impulse17();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse18:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY_FAILURE;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;

  GPU_FAILUREPV2Impulse18();
  ~GPU_FAILUREPV2Impulse18();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse19:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY_FAILURE;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;

  GPU_FAILUREPV2Impulse19();
  ~GPU_FAILUREPV2Impulse19();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse20:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY_FAILURE;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;

  GPU_FAILUREPV2Impulse20();
  ~GPU_FAILUREPV2Impulse20();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse21:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY_FAILURE;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;

  GPU_FAILUREPV2Impulse21();
  ~GPU_FAILUREPV2Impulse21();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse22:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY_FAILURE;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;

  GPU_FAILUREPV2Impulse22();
  ~GPU_FAILUREPV2Impulse22();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse23:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY_FAILURE;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;

  GPU_FAILUREPV2Impulse23();
  ~GPU_FAILUREPV2Impulse23();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse24:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY_FAILURE;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;

  GPU_FAILUREPV2Impulse24();
  ~GPU_FAILUREPV2Impulse24();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse25:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY_FAILURE;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;

  GPU_FAILUREPV2Impulse25();
  ~GPU_FAILUREPV2Impulse25();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse26:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY_FAILURE;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;

  GPU_FAILUREPV2Impulse26();
  ~GPU_FAILUREPV2Impulse26();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse27:public IntervalOfTimeImpulse
{
 public:
  MEMORYSAN *MEMORY_FAILURE;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;

  GPU_FAILUREPV2Impulse27();
  ~GPU_FAILUREPV2Impulse27();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse28:public IntervalOfTimeImpulse
{
 public:
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse28();
  ~GPU_FAILUREPV2Impulse28();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class GPU_FAILUREPV2Impulse29:public IntervalOfTimeImpulse
{
 public:
  EXEC_UNITSAN *EXEC_UNIT_FAILURE;
  WARPSAN *WARP;
  EXEC_UNITSAN *EXEC_UNIT;
  MEMORYSAN *MEMORY;
  WARPSAN *WARP_FAILURE;
  MEMORYSAN *MEMORY_FAILURE;

  GPU_FAILUREPV2Impulse29();
  ~GPU_FAILUREPV2Impulse29();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class GPU_FAILUREPV2:public PerformanceVariableNode
{
 public:
  GPU_FAILURERJ *TheGPU_FAILURERJ;

  GPU_FAILUREPV2Impulse0 Impulse0;
  GPU_FAILUREPV2Impulse1 Impulse1;
  GPU_FAILUREPV2Impulse2 Impulse2;
  GPU_FAILUREPV2Impulse3 Impulse3;
  GPU_FAILUREPV2Impulse4 Impulse4;
  GPU_FAILUREPV2Impulse5 Impulse5;
  GPU_FAILUREPV2Impulse6 Impulse6;
  GPU_FAILUREPV2Impulse7 Impulse7;
  GPU_FAILUREPV2Impulse8 Impulse8;
  GPU_FAILUREPV2Impulse9 Impulse9;
  GPU_FAILUREPV2Impulse10 Impulse10;
  GPU_FAILUREPV2Impulse11 Impulse11;
  GPU_FAILUREPV2Impulse12 Impulse12;
  GPU_FAILUREPV2Impulse13 Impulse13;
  GPU_FAILUREPV2Impulse14 Impulse14;
  GPU_FAILUREPV2Impulse15 Impulse15;
  GPU_FAILUREPV2Impulse16 Impulse16;
  GPU_FAILUREPV2Impulse17 Impulse17;
  GPU_FAILUREPV2Impulse18 Impulse18;
  GPU_FAILUREPV2Impulse19 Impulse19;
  GPU_FAILUREPV2Impulse20 Impulse20;
  GPU_FAILUREPV2Impulse21 Impulse21;
  GPU_FAILUREPV2Impulse22 Impulse22;
  GPU_FAILUREPV2Impulse23 Impulse23;
  GPU_FAILUREPV2Impulse24 Impulse24;
  GPU_FAILUREPV2Impulse25 Impulse25;
  GPU_FAILUREPV2Impulse26 Impulse26;
  GPU_FAILUREPV2Impulse27 Impulse27;
  GPU_FAILUREPV2Impulse28 Impulse28;
  GPU_FAILUREPV2Impulse29 Impulse29;

  GPU_FAILUREPV2(int timeindex=0);
  ~GPU_FAILUREPV2();
  void CreateWorkerList(void);
};

#endif
