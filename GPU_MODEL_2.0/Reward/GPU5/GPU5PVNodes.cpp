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
GPU5PV1Impulse0::GPU5PV1Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&REGISTER_FILE);
  ImpulseWorkerListLength = 0;
}

GPU5PV1Impulse0::~GPU5PV1Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV1Impulse0::Impulse_Function(double FiringTime)
{
return REGISTER_FILE->OK_CONTENT->Mark();

return(0);
}

ImpulseNodeClass** GPU5PV1Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV1Impulse0;
  }

  return ImpulseWorkerList;
}

GPU5PV1Impulse1::GPU5PV1Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&REGISTER_FILE);
  ImpulseWorkerListLength = 0;
}

GPU5PV1Impulse1::~GPU5PV1Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV1Impulse1::Impulse_Function(double FiringTime)
{
return REGISTER_FILE->OK_CONTENT->Mark();

return(0);
}

ImpulseNodeClass** GPU5PV1Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV1Impulse1;
  }

  return ImpulseWorkerList;
}

GPU5PV1::GPU5PV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("reg_ok",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("WRITE_WITH_OK_DATA","REGISTER_FILE",&Impulse0);
  AddImpulse("Instantaneous_Activity3","REGISTER_FILE",&Impulse1);
}

GPU5PV1::~GPU5PV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV1::CreateWorkerList(void) {
}
GPU5PV2Impulse0::GPU5PV2Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU5PV2Impulse0::~GPU5PV2Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV2Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU5PV2Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV2Impulse0;
  }

  return ImpulseWorkerList;
}

GPU5PV2::GPU5PV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("temp",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("READ_FROM_case1","L1_CACHE",&Impulse0);
}

GPU5PV2::~GPU5PV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV2::CreateWorkerList(void) {
}
GPU5PV3Impulse0::GPU5PV3Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&REGISTER_FILE);
  ImpulseWorkerListLength = 0;
}

GPU5PV3Impulse0::~GPU5PV3Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV3Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU5PV3Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV3Impulse0;
  }

  return ImpulseWorkerList;
}

GPU5PV3::GPU5PV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("temp_due",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("READ_FROM_case2","REGISTER_FILE",&Impulse0);
}

GPU5PV3::~GPU5PV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV3::CreateWorkerList(void) {
}