#ifndef _GPU_COMPOSED_PHYSICAL_REWARD_PVMODEL_
#define _GPU_COMPOSED_PHYSICAL_REWARD_PVMODEL_
#include "GPU_COMPOSED_PHYSICAL_REWARDPVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Composed/GPU_PHYSICAL/GPU_PHYSICALRJ.h"
class GPU_COMPOSED_PHYSICAL_REWARDPVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  GPU_COMPOSED_PHYSICAL_REWARDPVModel(bool expandtimepoints);
};

#endif
