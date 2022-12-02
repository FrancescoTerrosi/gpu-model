#include "GPU4PVModel.h"

GPU4PVModel::GPU4PVModel(bool expandTimeArrays) {
  TheModel=new GPU4RJ();
  DefineName("GPU4PVModel");
  StateMode = 1;
  CreatePVList(11, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* GPU4PVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new GPU4PV0(timeindex);
    break;
  case 1:
    return new GPU4PV1(timeindex);
    break;
  case 2:
    return new GPU4PV2(timeindex);
    break;
  case 3:
    return new GPU4PV3(timeindex);
    break;
  case 4:
    return new GPU4PV4(timeindex);
    break;
  case 5:
    return new GPU4PV5(timeindex);
    break;
  case 6:
    return new GPU4PV6(timeindex);
    break;
  case 7:
    return new GPU4PV7(timeindex);
    break;
  case 8:
    return new GPU4PV8(timeindex);
    break;
  case 9:
    return new GPU4PV9(timeindex);
    break;
  case 10:
    return new GPU4PV10(timeindex);
    break;
  }
  return NULL;
}
