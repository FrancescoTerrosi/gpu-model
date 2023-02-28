#include "GPU5PVNodes.h"

GPU5PV0Impulse0::GPU5PV0Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU5PV0Impulse0::~GPU5PV0Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV0Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU5PV0Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV0Impulse0;
  }

  return ImpulseWorkerList;
}

GPU5PV0::GPU5PV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("warp",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("DISPATCHER_Copy","WARP",&Impulse0);
}

GPU5PV0::~GPU5PV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV0::CreateWorkerList(void) {
}
