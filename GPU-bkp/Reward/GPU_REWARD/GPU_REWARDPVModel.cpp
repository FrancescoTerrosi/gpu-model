#include "GPU_REWARDPVModel.h"

GPU_REWARDPVModel::GPU_REWARDPVModel(bool expandTimeArrays) {
  TheModel=new GPU_MODEL_ATOMIC_COMPOSITIONSAN();
  DefineName("GPU_REWARDPVModel");
  StateMode = 1;
  CreatePVList(1, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* GPU_REWARDPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new GPU_REWARDPV0(timeindex);
    break;
  }
  return NULL;
}
