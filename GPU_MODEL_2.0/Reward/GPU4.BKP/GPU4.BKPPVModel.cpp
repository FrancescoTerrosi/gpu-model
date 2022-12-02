#include "GPU4.BKPPVModel.h"

GPU4.BKPPVModel::GPU4.BKPPVModel(bool expandTimeArrays) {
  TheModel=new GPU4RJ();
  DefineName("GPU4.BKPPVModel");
  StateMode = 1;
  CreatePVList(8, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* GPU4.BKPPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new GPU4.BKPPV0(timeindex);
    break;
  case 1:
    return new GPU4.BKPPV1(timeindex);
    break;
  case 2:
    return new GPU4.BKPPV2(timeindex);
    break;
  case 3:
    return new GPU4.BKPPV3(timeindex);
    break;
  case 4:
    return new GPU4.BKPPV4(timeindex);
    break;
  case 5:
    return new GPU4.BKPPV5(timeindex);
    break;
  case 6:
    return new GPU4.BKPPV6(timeindex);
    break;
  case 7:
    return new GPU4.BKPPV7(timeindex);
    break;
  }
  return NULL;
}
