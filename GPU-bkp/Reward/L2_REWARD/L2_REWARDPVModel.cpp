#include "L2_REWARDPVModel.h"

L2_REWARDPVModel::L2_REWARDPVModel(bool expandTimeArrays) {
  TheModel=new L2_CACHESAN();
  DefineName("L2_REWARDPVModel");
  CreatePVList(1, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* L2_REWARDPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new L2_REWARDPV0(timeindex);
    break;
  }
  return NULL;
}
