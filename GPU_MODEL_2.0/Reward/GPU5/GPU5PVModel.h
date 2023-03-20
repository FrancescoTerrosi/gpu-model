#ifndef _GPU5_PVMODEL_
#define _GPU5_PVMODEL_
#include "GPU5PVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Composed/GPU5/GPU5RJ__Rep1.h"
#include "Composed/GPU5/GPU5RJ__PROCESSOR_REP.h"
#include "Composed/GPU5/GPU5RJ.h"
#include "Composed/GPU5/GPU5RJ__PROCESSOR.h"
#include "Composed/GPU5/GPU5RJ__STREAMING_MULTIPROCESSOR.h"
#include "Composed/GPU5/GPU5RJ__DEVICE.h"
class GPU5PVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  GPU5PVModel(bool expandtimepoints);
};

#endif
