#ifndef _L2_REWARD_PVS_
#define _L2_REWARD_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/L2_CACHE/L2_CACHESAN.h"
#include "Cpp/Performance_Variables/InstantOfTime.hpp"


class L2_REWARDPV0Worker:public InstantOfTime
{
 public:
  L2_CACHESAN *L2_CACHE;
  
  L2_REWARDPV0Worker();
  ~L2_REWARDPV0Worker();
  double Reward_Function();
};

class L2_REWARDPV0:public PerformanceVariableNode
{
 public:
  L2_CACHESAN *TheL2_CACHESAN;

  L2_REWARDPV0Worker *L2_REWARDPV0WorkerList;

  L2_REWARDPV0(int timeindex=0);
  ~L2_REWARDPV0();
  void CreateWorkerList(void);
};

#endif
