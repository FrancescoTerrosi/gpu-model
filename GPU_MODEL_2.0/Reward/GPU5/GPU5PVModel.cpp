#include "GPU5PVModel.h"

GPU5PVModel::GPU5PVModel(bool expandTimeArrays) {
  TheModel=new GPU5RJ();
  DefineName("GPU5PVModel");
  StateMode = 1;
  CreatePVList(25, expandTimeArrays);
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
  case 6:
    return new GPU5PV6(timeindex);
    break;
  case 7:
    return new GPU5PV7(timeindex);
    break;
  case 8:
    return new GPU5PV8(timeindex);
    break;
  case 9:
    return new GPU5PV9(timeindex);
    break;
  case 10:
    return new GPU5PV10(timeindex);
    break;
  case 11:
    return new GPU5PV11(timeindex);
    break;
  case 12:
    return new GPU5PV12(timeindex);
    break;
  case 13:
    return new GPU5PV13(timeindex);
    break;
  case 14:
    return new GPU5PV14(timeindex);
    break;
  case 15:
    return new GPU5PV15(timeindex);
    break;
  case 16:
    return new GPU5PV16(timeindex);
    break;
  case 17:
    return new GPU5PV17(timeindex);
    break;
  case 18:
    return new GPU5PV18(timeindex);
    break;
  case 19:
    return new GPU5PV19(timeindex);
    break;
  case 20:
    return new GPU5PV20(timeindex);
    break;
  case 21:
    return new GPU5PV21(timeindex);
    break;
  case 22:
    return new GPU5PV22(timeindex);
    break;
  case 23:
    return new GPU5PV23(timeindex);
    break;
  case 24:
    return new GPU5PV24(timeindex);
    break;
  }
  return NULL;
}
