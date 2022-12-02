#include "GPU_REWARDPVNodes.h"

GPU_REWARDPV0Impulse0::GPU_REWARDPV0Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV0Impulse0::~GPU_REWARDPV0Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV0Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV0Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV0Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV0Impulse1::GPU_REWARDPV0Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV0Impulse1::~GPU_REWARDPV0Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV0Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV0Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV0Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV0Impulse2::GPU_REWARDPV0Impulse2()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV0Impulse2::~GPU_REWARDPV0Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV0Impulse2::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV0Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV0Impulse2;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV0Impulse3::GPU_REWARDPV0Impulse3()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV0Impulse3::~GPU_REWARDPV0Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV0Impulse3::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV0Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV0Impulse3;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV0Impulse4::GPU_REWARDPV0Impulse4()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV0Impulse4::~GPU_REWARDPV0Impulse4() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV0Impulse4::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV0Impulse4::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV0Impulse4;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV0Impulse5::GPU_REWARDPV0Impulse5()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV0Impulse5::~GPU_REWARDPV0Impulse5() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV0Impulse5::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV0Impulse5::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV0Impulse5;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV0Impulse6::GPU_REWARDPV0Impulse6()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV0Impulse6::~GPU_REWARDPV0Impulse6() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV0Impulse6::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV0Impulse6::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV0Impulse6;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV0::GPU_REWARDPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_MODEL_ATOMIC_COMPOSITIONSAN);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("token_game",(RewardType)1,1, startpts, stoppts, timeindex, 7,0, 0);
  AddImpulse("DISPATCHER","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse0);
  AddImpulse("READ_FROM_case1","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse1);
  AddImpulse("READ_FROM_case2","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse2);
  AddImpulse("WRITE_TO_case1","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse3);
  AddImpulse("WRITE_TO_case2","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse4);
  AddImpulse("COMPUTE_case1","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse5);
  AddImpulse("COMPUTE_case2","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse6);
}

GPU_REWARDPV0::~GPU_REWARDPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_REWARDPV0::CreateWorkerList(void) {
}
