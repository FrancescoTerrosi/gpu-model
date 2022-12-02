#include "GPU_REWARDPVModel.h"

GPU_REWARDPVModel::GPU_REWARDPVModel(bool expandTimeArrays) {
  TheModel=new GPURJ();
  DefineName("GPU_REWARDPVModel");
  StateMode = 1;
  CreatePVList(10, expandTimeArrays);
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
  case 5:
    return new GPU_REWARDPV5(timeindex);
    break;
  case 6:
    return new GPU_REWARDPV6(timeindex);
    break;
  case 7:
    return new GPU_REWARDPV7(timeindex);
    break;
  case 8:
    return new GPU_REWARDPV8(timeindex);
    break;
  case 9:
    return new GPU_REWARDPV9(timeindex);
    break;
  }
  return NULL;
}
