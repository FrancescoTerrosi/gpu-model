#include "GPU_AVERAGEPVModel.h"

GPU_AVERAGEPVModel::GPU_AVERAGEPVModel(bool expandTimeArrays) {
  TheModel=new GPU_AVERAGERJ();
  DefineName("GPU_AVERAGEPVModel");
  StateMode = 1;
  CreatePVList(10, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* GPU_AVERAGEPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new GPU_AVERAGEPV0(timeindex);
    break;
  case 1:
    return new GPU_AVERAGEPV1(timeindex);
    break;
  case 2:
    return new GPU_AVERAGEPV2(timeindex);
    break;
  case 3:
    return new GPU_AVERAGEPV3(timeindex);
    break;
  case 4:
    return new GPU_AVERAGEPV4(timeindex);
    break;
  case 5:
    return new GPU_AVERAGEPV5(timeindex);
    break;
  case 6:
    return new GPU_AVERAGEPV6(timeindex);
    break;
  case 7:
    return new GPU_AVERAGEPV7(timeindex);
    break;
  case 8:
    return new GPU_AVERAGEPV8(timeindex);
    break;
  case 9:
    return new GPU_AVERAGEPV9(timeindex);
    break;
  }
  return NULL;
}
