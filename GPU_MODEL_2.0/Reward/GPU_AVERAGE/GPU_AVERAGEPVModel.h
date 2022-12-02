#ifndef _GPU_AVERAGE_PVMODEL_
#define _GPU_AVERAGE_PVMODEL_
#include "GPU_AVERAGEPVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Composed/GPU_AVERAGE/GPU_AVERAGERJ__Join1.h"
#include "Composed/GPU_AVERAGE/GPU_AVERAGERJ__STREAMING_MULTIPROCESSOR.h"
#include "Composed/GPU_AVERAGE/GPU_AVERAGERJ.h"
class GPU_AVERAGEPVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  GPU_AVERAGEPVModel(bool expandtimepoints);
};

#endif
