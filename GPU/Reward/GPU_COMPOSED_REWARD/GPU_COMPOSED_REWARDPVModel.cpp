#include "GPU_COMPOSED_REWARDPVModel.h"

GPU_COMPOSED_REWARDPVModel::GPU_COMPOSED_REWARDPVModel(bool expandTimeArrays) {
  TheModel=new GPURJ();
  DefineName("GPU_COMPOSED_REWARDPVModel");
  StateMode = 1;
  CreatePVList(6, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* GPU_COMPOSED_REWARDPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new GPU_COMPOSED_REWARDPV0(timeindex);
    break;
  case 1:
    return new GPU_COMPOSED_REWARDPV1(timeindex);
    break;
  case 2:
    return new GPU_COMPOSED_REWARDPV2(timeindex);
    break;
  case 3:
    return new GPU_COMPOSED_REWARDPV3(timeindex);
    break;
  case 4:
    return new GPU_COMPOSED_REWARDPV4(timeindex);
    break;
  case 5:
    return new GPU_COMPOSED_REWARDPV5(timeindex);
    break;
  }
  return NULL;
}
