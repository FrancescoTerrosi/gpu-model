#ifndef _GPU_REWARD_PVMODEL_
#define _GPU_REWARD_PVMODEL_
#include "GPU_REWARDPVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Composed/GPU/GPURJ.h"
class GPU_REWARDPVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  GPU_REWARDPVModel(bool expandtimepoints);
};

#endif
