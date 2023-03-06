#include "Composed/GPU5/GPU5RJ.h"
char * GPU5RJ__SharedNames[] = {};

GPU5RJ::GPU5RJ():Rep("Rep", 50, 0, GPU5RJ__SharedNames)
{
  InstanceArray = new GPU5RJ__DEVICE * [NumModels];
  delete[] ModelArray;
  ModelArray = (BaseModelClass **) InstanceArray;
  for (counter = 0; counter < NumModels; counter++)
    InstanceArray[counter] = new GPU5RJ__DEVICE();

  SetupActions();
  if (NumModels == 0) return;

  if (AllChildrenEmpty())
    NumSharedStateVariables = 0;
  Setup("DEVICE");
}

GPU5RJ::~GPU5RJ() {
  if (NumModels == 0) return;
  for (int i = 0; i < NumModels; i++)
    delete InstanceArray[i];
}

