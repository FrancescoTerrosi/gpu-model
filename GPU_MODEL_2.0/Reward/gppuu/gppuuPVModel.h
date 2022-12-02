#ifndef _GPPUU_PVMODEL_
#define _GPPUU_PVMODEL_
#include "gppuuPVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Composed/GPU2/GPU2RJ__Rep1.h"
#include "Composed/GPU2/GPU2RJ__Rep2.h"
#include "Composed/GPU2/GPU2RJ.h"
#include "Composed/GPU2/GPU2RJ__Join2.h"
#include "Composed/GPU2/GPU2RJ__Join1.h"
#include "Composed/GPU2/GPU2RJ__Join3.h"
#include "Composed/GPU2/GPU2RJ__Join4.h"
class gppuuPVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  gppuuPVModel(bool expandtimepoints);
};

#endif
