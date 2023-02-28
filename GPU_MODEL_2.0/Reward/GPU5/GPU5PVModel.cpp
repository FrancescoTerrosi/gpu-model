#include "GPU5PVModel.h"

GPU5PVModel::GPU5PVModel(bool expandTimeArrays) {
  TheModel=new GPU5RJ();
  DefineName("GPU5PVModel");
  StateMode = 1;
  CreatePVList(1, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* GPU5PVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new GPU5PV0(timeindex);
    break;
  }
  return NULL;
}
