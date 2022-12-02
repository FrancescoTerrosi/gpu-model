#ifndef _GPU_COMPOSED_REWARD_PVMODEL_
#define _GPU_COMPOSED_REWARD_PVMODEL_
#include "GPU_COMPOSED_REWARDPVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Composed/GPU/GPURJ.h"
class GPU_COMPOSED_REWARDPVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  GPU_COMPOSED_REWARDPVModel(bool expandtimepoints);
};

#endif
