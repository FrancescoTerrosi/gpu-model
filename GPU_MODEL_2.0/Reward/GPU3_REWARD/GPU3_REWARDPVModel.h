#ifndef _GPU3_REWARD_PVMODEL_
#define _GPU3_REWARD_PVMODEL_
#include "GPU3_REWARDPVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Composed/GPU3/GPU3RJ__Rep1.h"
#include "Composed/GPU3/GPU3RJ__PROCESSOR.h"
#include "Composed/GPU3/GPU3RJ__STREAMING_MULTIPROCESSOR.h"
#include "Composed/GPU3/GPU3RJ.h"
class GPU3_REWARDPVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  GPU3_REWARDPVModel(bool expandtimepoints);
};

#endif
