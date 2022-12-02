#ifndef _GPU4.BKP_PVMODEL_
#define _GPU4.BKP_PVMODEL_
#include "GPU4.BKPPVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Composed/GPU4/GPU4RJ__Rep1.h"
#include "Composed/GPU4/GPU4RJ__PROCESSOR_REP.h"
#include "Composed/GPU4/GPU4RJ__PROCESSOR.h"
#include "Composed/GPU4/GPU4RJ__STREAMING_MULTIPROCESSOR.h"
#include "Composed/GPU4/GPU4RJ.h"
class GPU4.BKPPVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  GPU4.BKPPVModel(bool expandtimepoints);
};

#endif
