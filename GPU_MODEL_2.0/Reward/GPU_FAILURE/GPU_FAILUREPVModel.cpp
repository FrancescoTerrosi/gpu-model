#include "GPU_FAILUREPVModel.h"

GPU_FAILUREPVModel::GPU_FAILUREPVModel(bool expandTimeArrays) {
  TheModel=new GPU_FAILURERJ();
  DefineName("GPU_FAILUREPVModel");
  StateMode = 1;
  CreatePVList(3, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* GPU_FAILUREPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new GPU_FAILUREPV0(timeindex);
    break;
  case 1:
    return new GPU_FAILUREPV1(timeindex);
    break;
  case 2:
    return new GPU_FAILUREPV2(timeindex);
    break;
  }
  return NULL;
}
