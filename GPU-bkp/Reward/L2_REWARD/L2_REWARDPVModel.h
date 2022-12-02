#ifndef _L2_REWARD_PVMODEL_
#define _L2_REWARD_PVMODEL_
#include "L2_REWARDPVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/L2_CACHE/L2_CACHESAN.h"
class L2_REWARDPVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  L2_REWARDPVModel(bool expandtimepoints);
};

#endif
