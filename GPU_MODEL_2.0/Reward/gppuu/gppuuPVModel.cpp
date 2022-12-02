#include "gppuuPVModel.h"

gppuuPVModel::gppuuPVModel(bool expandTimeArrays) {
  TheModel=new GPU2RJ();
  DefineName("gppuuPVModel");
  StateMode = 1;
  CreatePVList(2, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* gppuuPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new gppuuPV0(timeindex);
    break;
  case 1:
    return new gppuuPV1(timeindex);
    break;
  }
  return NULL;
}
