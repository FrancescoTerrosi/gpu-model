#ifndef _GPU_FAILURE_PVMODEL_
#define _GPU_FAILURE_PVMODEL_
#include "GPU_FAILUREPVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
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
class GPU_FAILUREPVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  GPU_FAILUREPVModel(bool expandtimepoints);
};

#endif
