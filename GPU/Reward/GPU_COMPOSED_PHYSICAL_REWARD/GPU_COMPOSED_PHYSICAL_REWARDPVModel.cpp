#include "GPU_COMPOSED_PHYSICAL_REWARDPVModel.h"

GPU_COMPOSED_PHYSICAL_REWARDPVModel::GPU_COMPOSED_PHYSICAL_REWARDPVModel(bool expandTimeArrays) {
  TheModel=new GPU_PHYSICALRJ();
  DefineName("GPU_COMPOSED_PHYSICAL_REWARDPVModel");
  StateMode = 1;
  CreatePVList(12, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* GPU_COMPOSED_PHYSICAL_REWARDPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new GPU_COMPOSED_PHYSICAL_REWARDPV0(timeindex);
    break;
  case 1:
    return new GPU_COMPOSED_PHYSICAL_REWARDPV1(timeindex);
    break;
  case 2:
    return new GPU_COMPOSED_PHYSICAL_REWARDPV2(timeindex);
    break;
  case 3:
    return new GPU_COMPOSED_PHYSICAL_REWARDPV3(timeindex);
    break;
  case 4:
    return new GPU_COMPOSED_PHYSICAL_REWARDPV4(timeindex);
    break;
  case 5:
    return new GPU_COMPOSED_PHYSICAL_REWARDPV5(timeindex);
    break;
  case 6:
    return new GPU_COMPOSED_PHYSICAL_REWARDPV6(timeindex);
    break;
  case 7:
    return new GPU_COMPOSED_PHYSICAL_REWARDPV7(timeindex);
    break;
  case 8:
    return new GPU_COMPOSED_PHYSICAL_REWARDPV8(timeindex);
    break;
  case 9:
    return new GPU_COMPOSED_PHYSICAL_REWARDPV9(timeindex);
    break;
  case 10:
    return new GPU_COMPOSED_PHYSICAL_REWARDPV10(timeindex);
    break;
  case 11:
    return new GPU_COMPOSED_PHYSICAL_REWARDPV11(timeindex);
    break;
  }
  return NULL;
}
