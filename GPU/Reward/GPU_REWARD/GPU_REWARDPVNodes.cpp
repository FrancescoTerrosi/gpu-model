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

GPU_REWARDPV0::GPU_REWARDPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_MODEL_ATOMIC_COMPOSITIONSAN);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("token_game",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("DISPATCHER","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse0);
}

GPU_REWARDPV0::~GPU_REWARDPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_REWARDPV0::CreateWorkerList(void) {
}
GPU_REWARDPV1Impulse0::GPU_REWARDPV1Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV1Impulse0::~GPU_REWARDPV1Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV1Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV1Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV1Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV1::GPU_REWARDPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_MODEL_ATOMIC_COMPOSITIONSAN);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("memory_ok",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("T_WRITE_RESULT_case1","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse0);
}

GPU_REWARDPV1::~GPU_REWARDPV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_REWARDPV1::CreateWorkerList(void) {
}
GPU_REWARDPV2Impulse0::GPU_REWARDPV2Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV2Impulse0::~GPU_REWARDPV2Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV2Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV2Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV2Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV2::GPU_REWARDPV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_MODEL_ATOMIC_COMPOSITIONSAN);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("memory_ko",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("T_WRITE_RESULT_case2","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse0);
}

GPU_REWARDPV2::~GPU_REWARDPV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_REWARDPV2::CreateWorkerList(void) {
}
GPU_REWARDPV3Impulse0::GPU_REWARDPV3Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV3Impulse0::~GPU_REWARDPV3Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV3Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV3Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV3Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV3::GPU_REWARDPV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_MODEL_ATOMIC_COMPOSITIONSAN);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("output_ok",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("T_WRITE_OUTPUT_case1","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse0);
}

GPU_REWARDPV3::~GPU_REWARDPV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_REWARDPV3::CreateWorkerList(void) {
}
GPU_REWARDPV4Impulse0::GPU_REWARDPV4Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV4Impulse0::~GPU_REWARDPV4Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV4Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV4Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV4Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV4::GPU_REWARDPV4(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_MODEL_ATOMIC_COMPOSITIONSAN);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("output_ko",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("T_WRITE_OUTPUT_case2","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse0);
}

GPU_REWARDPV4::~GPU_REWARDPV4() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_REWARDPV4::CreateWorkerList(void) {
}
GPU_REWARDPV5Impulse0::GPU_REWARDPV5Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV5Impulse0::~GPU_REWARDPV5Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV5Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV5Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV5Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV5::GPU_REWARDPV5(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_MODEL_ATOMIC_COMPOSITIONSAN);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("alu_ops_ok",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("COMPUTE_OK","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse0);
}

GPU_REWARDPV5::~GPU_REWARDPV5() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_REWARDPV5::CreateWorkerList(void) {
}
GPU_REWARDPV6Impulse0::GPU_REWARDPV6Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV6Impulse0::~GPU_REWARDPV6Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV6Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV6Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV6Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV6::GPU_REWARDPV6(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_MODEL_ATOMIC_COMPOSITIONSAN);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("alu_ops_ko",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("COMPUTE_KO","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse0);
}

GPU_REWARDPV6::~GPU_REWARDPV6() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_REWARDPV6::CreateWorkerList(void) {
}
GPU_REWARDPV7Impulse0::GPU_REWARDPV7Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV7Impulse0::~GPU_REWARDPV7Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV7Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV7Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV7Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV7Impulse1::GPU_REWARDPV7Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV7Impulse1::~GPU_REWARDPV7Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV7Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV7Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV7Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV7::GPU_REWARDPV7(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_MODEL_ATOMIC_COMPOSITIONSAN);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("result_writes",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("T_WRITE_RESULT_case1","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse0);
  AddImpulse("T_WRITE_RESULT_case2","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse1);
}

GPU_REWARDPV7::~GPU_REWARDPV7() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_REWARDPV7::CreateWorkerList(void) {
}
GPU_REWARDPV8Impulse0::GPU_REWARDPV8Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV8Impulse0::~GPU_REWARDPV8Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV8Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV8Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV8Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV8Impulse1::GPU_REWARDPV8Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV8Impulse1::~GPU_REWARDPV8Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV8Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV8Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV8Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV8::GPU_REWARDPV8(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_MODEL_ATOMIC_COMPOSITIONSAN);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("alu_ops",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("COMPUTE_OK","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse0);
  AddImpulse("COMPUTE_KO","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse1);
}

GPU_REWARDPV8::~GPU_REWARDPV8() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_REWARDPV8::CreateWorkerList(void) {
}
GPU_REWARDPV9Impulse0::GPU_REWARDPV9Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV9Impulse0::~GPU_REWARDPV9Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV9Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV9Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV9Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV9Impulse1::GPU_REWARDPV9Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV9Impulse1::~GPU_REWARDPV9Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV9Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV9Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV9Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV9::GPU_REWARDPV9(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_MODEL_ATOMIC_COMPOSITIONSAN);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("output_writes",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("T_WRITE_OUTPUT_case1","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse0);
  AddImpulse("T_WRITE_OUTPUT_case2","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse1);
}

GPU_REWARDPV9::~GPU_REWARDPV9() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_REWARDPV9::CreateWorkerList(void) {
}
GPU_REWARDPV10Impulse0::GPU_REWARDPV10Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV10Impulse0::~GPU_REWARDPV10Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV10Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV10Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV10Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV10Impulse1::GPU_REWARDPV10Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV10Impulse1::~GPU_REWARDPV10Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV10Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV10Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV10Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV10::GPU_REWARDPV10(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_MODEL_ATOMIC_COMPOSITIONSAN);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("total_read",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("T_READ_TOTAL_case1","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse0);
  AddImpulse("T_READ_TOTAL_case2","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse1);
}

GPU_REWARDPV10::~GPU_REWARDPV10() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_REWARDPV10::CreateWorkerList(void) {
}
GPU_REWARDPV11Impulse0::GPU_REWARDPV11Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV11Impulse0::~GPU_REWARDPV11Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV11Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV11Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV11Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV11Impulse1::GPU_REWARDPV11Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV11Impulse1::~GPU_REWARDPV11Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV11Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV11Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV11Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV11::GPU_REWARDPV11(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_MODEL_ATOMIC_COMPOSITIONSAN);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("result_read",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("T_READ_RESULT_case1","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse0);
  AddImpulse("T_READ_RESULT_case2","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse1);
}

GPU_REWARDPV11::~GPU_REWARDPV11() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_REWARDPV11::CreateWorkerList(void) {
}
GPU_REWARDPV12Impulse0::GPU_REWARDPV12Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV12Impulse0::~GPU_REWARDPV12Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV12Impulse0::Impulse_Function(double FiringTime)
{
return 2;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV12Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV12Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV12Impulse1::GPU_REWARDPV12Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV12Impulse1::~GPU_REWARDPV12Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV12Impulse1::Impulse_Function(double FiringTime)
{
return 2;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV12Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV12Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV12Impulse2::GPU_REWARDPV12Impulse2()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV12Impulse2::~GPU_REWARDPV12Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV12Impulse2::Impulse_Function(double FiringTime)
{
return 360;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV12Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV12Impulse2;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV12Impulse3::GPU_REWARDPV12Impulse3()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV12Impulse3::~GPU_REWARDPV12Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV12Impulse3::Impulse_Function(double FiringTime)
{
return 32;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV12Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV12Impulse3;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV12Impulse4::GPU_REWARDPV12Impulse4()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV12Impulse4::~GPU_REWARDPV12Impulse4() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV12Impulse4::Impulse_Function(double FiringTime)
{
return 32;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV12Impulse4::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV12Impulse4;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV12Impulse5::GPU_REWARDPV12Impulse5()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV12Impulse5::~GPU_REWARDPV12Impulse5() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV12Impulse5::Impulse_Function(double FiringTime)
{
return 32;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV12Impulse5::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV12Impulse5;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV12Impulse6::GPU_REWARDPV12Impulse6()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV12Impulse6::~GPU_REWARDPV12Impulse6() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV12Impulse6::Impulse_Function(double FiringTime)
{
return 64;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV12Impulse6::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV12Impulse6;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV12Impulse7::GPU_REWARDPV12Impulse7()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV12Impulse7::~GPU_REWARDPV12Impulse7() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV12Impulse7::Impulse_Function(double FiringTime)
{
return 64;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV12Impulse7::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV12Impulse7;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV12Impulse8::GPU_REWARDPV12Impulse8()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV12Impulse8::~GPU_REWARDPV12Impulse8() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV12Impulse8::Impulse_Function(double FiringTime)
{
return 360;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV12Impulse8::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV12Impulse8;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV12Impulse9::GPU_REWARDPV12Impulse9()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV12Impulse9::~GPU_REWARDPV12Impulse9() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV12Impulse9::Impulse_Function(double FiringTime)
{
return 64;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV12Impulse9::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV12Impulse9;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV12Impulse10::GPU_REWARDPV12Impulse10()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GPU_MODEL_ATOMIC_COMPOSITION);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV12Impulse10::~GPU_REWARDPV12Impulse10() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV12Impulse10::Impulse_Function(double FiringTime)
{
return 32;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV12Impulse10::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV12Impulse10;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV12::GPU_REWARDPV12(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_MODEL_ATOMIC_COMPOSITIONSAN);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("clock_steps",(RewardType)1,1, startpts, stoppts, timeindex, 11,0, 0);
  AddImpulse("COMPUTE_OK","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse0);
  AddImpulse("COMPUTE_KO","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse1);
  AddImpulse("T_WRITE_OUTPUT_case2","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse2);
  AddImpulse("T_WRITE_RESULT_case2","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse3);
  AddImpulse("T_READ_RESULT_case1","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse4);
  AddImpulse("T_READ_RESULT_case2","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse5);
  AddImpulse("T_READ_TOTAL_case2","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse6);
  AddImpulse("T_READ_TOTAL_case1","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse7);
  AddImpulse("T_WRITE_OUTPUT_case1","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse8);
  AddImpulse("DISPATCHER","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse9);
  AddImpulse("T_WRITE_RESULT_case1","GPU_MODEL_ATOMIC_COMPOSITION",&Impulse10);
}

GPU_REWARDPV12::~GPU_REWARDPV12() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_REWARDPV12::CreateWorkerList(void) {
}
