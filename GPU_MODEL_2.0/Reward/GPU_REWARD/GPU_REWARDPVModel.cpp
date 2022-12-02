#include "GPU_REWARDPVModel.h"

GPU_REWARDPVModel::GPU_REWARDPVModel(bool expandTimeArrays) {
  TheModel=new GPURJ();
  DefineName("GPU_REWARDPVModel");
  StateMode = 1;
  CreatePVList(5, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* GPU_REWARDPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new GPU_REWARDPV0(timeindex);
    break;
  case 1:
    return new GPU_REWARDPV1(timeindex);
    break;
  case 2:
    return new GPU_REWARDPV2(timeindex);
    break;
  case 3:
    return new GPU_REWARDPV3(timeindex);
    break;
  case 4:
    return new GPU_REWARDPV4(timeindex);
    break;
  }
  return NULL;
}
