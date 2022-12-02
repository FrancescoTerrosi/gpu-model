#include "gppuuPVNodes.h"

gppuuPV0Impulse0::gppuuPV0Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

gppuuPV0Impulse0::~gppuuPV0Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double gppuuPV0Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** gppuuPV0Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new gppuuPV0Impulse0;
  }

  return ImpulseWorkerList;
}

gppuuPV0::gppuuPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU2RJ);
  double startpts[1]={0.0};
  double stoppts[1]={100};
  Initialize("disp1",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("DISPATCHER_Copy","WARP",&Impulse0);
}

gppuuPV0::~gppuuPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void gppuuPV0::CreateWorkerList(void) {
}
gppuuPV1Impulse0::gppuuPV1Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP1);
  ImpulseWorkerListLength = 0;
}

gppuuPV1Impulse0::~gppuuPV1Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double gppuuPV1Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** gppuuPV1Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new gppuuPV1Impulse0;
  }

  return ImpulseWorkerList;
}

gppuuPV1::gppuuPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU2RJ);
  double startpts[1]={0.0};
  double stoppts[1]={100};
  Initialize("disp2",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("DISPATCHER_Copy","WARP1",&Impulse0);
}

gppuuPV1::~gppuuPV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void gppuuPV1::CreateWorkerList(void) {
}
