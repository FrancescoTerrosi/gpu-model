#include "GPU5PVModel.h"

GPU5PVModel::GPU5PVModel(bool expandTimeArrays) {
  TheModel=new GPU5RJ();
  DefineName("GPU5PVModel");
  StateMode = 1;
  CreatePVList(6, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* GPU5PVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new GPU5PV0(timeindex);
    break;
  case 1:
    return new GPU5PV1(timeindex);
    break;
  case 2:
    return new GPU5PV2(timeindex);
    break;
  case 3:
    return new GPU5PV3(timeindex);
    break;
  case 4:
    return new GPU5PV4(timeindex);
    break;
  case 5:
    return new GPU5PV5(timeindex);
    break;
  }
  return NULL;
}
