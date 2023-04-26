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
  TheModelPtr[0] = (BaseModelClass**)(&EXEC_UNIT);
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
return 1;

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

GPU5PV1::GPU5PV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("exec_dispatch",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("DISPATCHER","EXEC_UNIT",&Impulse0);
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

GPU5PV2Impulse1::GPU5PV2Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU5PV2Impulse1::~GPU5PV2Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV2Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU5PV2Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV2Impulse1;
  }

  return ImpulseWorkerList;
}

GPU5PV2::GPU5PV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("l1_read",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case1","L1_CACHE",&Impulse0);
  AddImpulse("READ_FROM_case2","L1_CACHE",&Impulse1);
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
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
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

GPU5PV3Impulse1::GPU5PV3Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU5PV3Impulse1::~GPU5PV3Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV3Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU5PV3Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV3Impulse1;
  }

  return ImpulseWorkerList;
}

GPU5PV3::GPU5PV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("l2_read",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case2","L2_CACHE",&Impulse0);
  AddImpulse("READ_FROM_case1","L2_CACHE",&Impulse1);
}

GPU5PV3::~GPU5PV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV3::CreateWorkerList(void) {
}
GPU5PV4Impulse0::GPU5PV4Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU5PV4Impulse0::~GPU5PV4Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV4Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU5PV4Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV4Impulse0;
  }

  return ImpulseWorkerList;
}

GPU5PV4Impulse1::GPU5PV4Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU5PV4Impulse1::~GPU5PV4Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV4Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU5PV4Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV4Impulse1;
  }

  return ImpulseWorkerList;
}

GPU5PV4::GPU5PV4(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("dram_read",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case1","DRAM",&Impulse0);
  AddImpulse("READ_FROM_case2","DRAM",&Impulse1);
}

GPU5PV4::~GPU5PV4() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV4::CreateWorkerList(void) {
}
GPU5PV5Impulse0::GPU5PV5Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU5PV5Impulse0::~GPU5PV5Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV5Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU5PV5Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV5Impulse0;
  }

  return ImpulseWorkerList;
}

GPU5PV5::GPU5PV5(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("alu_ok",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("Instantaneous_Activity2_case2","EXEC_UNIT",&Impulse0);
}

GPU5PV5::~GPU5PV5() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV5::CreateWorkerList(void) {
}
GPU5PV6Impulse0::GPU5PV6Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU5PV6Impulse0::~GPU5PV6Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV6Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU5PV6Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV6Impulse0;
  }

  return ImpulseWorkerList;
}

GPU5PV6::GPU5PV6(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("alu_ko",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("Instantaneous_Activity2_case1","EXEC_UNIT",&Impulse0);
}

GPU5PV6::~GPU5PV6() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV6::CreateWorkerList(void) {
}
GPU5PV7Impulse0::GPU5PV7Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU5PV7Impulse0::~GPU5PV7Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV7Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU5PV7Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV7Impulse0;
  }

  return ImpulseWorkerList;
}

GPU5PV7::GPU5PV7(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("l1_read_ko",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("dhn","L1_CACHE",&Impulse0);
}

GPU5PV7::~GPU5PV7() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV7::CreateWorkerList(void) {
}
GPU5PV8Impulse0::GPU5PV8Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU5PV8Impulse0::~GPU5PV8Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV8Impulse0::Impulse_Function(double FiringTime)
{
return L2_CACHE->MEM_FAILURE_COUNT->Mark();

return(0);
}

ImpulseNodeClass** GPU5PV8Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV8Impulse0;
  }

  return ImpulseWorkerList;
}

GPU5PV8Impulse1::GPU5PV8Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU5PV8Impulse1::~GPU5PV8Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV8Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU5PV8Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV8Impulse1;
  }

  return ImpulseWorkerList;
}

GPU5PV8::GPU5PV8(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("l2_read_ko",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case2","L2_CACHE",&Impulse0);
  AddImpulse("dhn","L2_CACHE",&Impulse1);
}

GPU5PV8::~GPU5PV8() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV8::CreateWorkerList(void) {
}
GPU5PV9Impulse0::GPU5PV9Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU5PV9Impulse0::~GPU5PV9Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV9Impulse0::Impulse_Function(double FiringTime)
{
return DRAM->MEM_FAILURE_COUNT->Mark();

return(0);
}

ImpulseNodeClass** GPU5PV9Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV9Impulse0;
  }

  return ImpulseWorkerList;
}

GPU5PV9Impulse1::GPU5PV9Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU5PV9Impulse1::~GPU5PV9Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV9Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU5PV9Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV9Impulse1;
  }

  return ImpulseWorkerList;
}

GPU5PV9::GPU5PV9(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("dram_read_ko",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case2","DRAM",&Impulse0);
  AddImpulse("dhn","DRAM",&Impulse1);
}

GPU5PV9::~GPU5PV9() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV9::CreateWorkerList(void) {
}
GPU5PV10Worker::GPU5PV10Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
}

GPU5PV10Worker::~GPU5PV10Worker() {
  delete [] TheModelPtr;
}

double GPU5PV10Worker::Reward_Function(void) {

return DRAM->Place1->Mark();

return (0);



}

GPU5PV10::GPU5PV10(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={end};
  double stoppts[1]={end};
  Initialize("failure",(RewardType)0,1, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("Place1","DRAM");
}

GPU5PV10::~GPU5PV10() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV10::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new GPU5PV10Worker;
}
GPU5PV11Impulse0::GPU5PV11Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU5PV11Impulse0::~GPU5PV11Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV11Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU5PV11Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV11Impulse0;
  }

  return ImpulseWorkerList;
}

GPU5PV11::GPU5PV11(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("l1_access",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("L1_CLOCK","WARP",&Impulse0);
}

GPU5PV11::~GPU5PV11() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV11::CreateWorkerList(void) {
}
GPU5PV12Impulse0::GPU5PV12Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU5PV12Impulse0::~GPU5PV12Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV12Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU5PV12Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV12Impulse0;
  }

  return ImpulseWorkerList;
}

GPU5PV12::GPU5PV12(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("l2_access",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("L2_CLOCK","WARP",&Impulse0);
}

GPU5PV12::~GPU5PV12() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV12::CreateWorkerList(void) {
}
GPU5PV13Impulse0::GPU5PV13Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU5PV13Impulse0::~GPU5PV13Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV13Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU5PV13Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV13Impulse0;
  }

  return ImpulseWorkerList;
}

GPU5PV13::GPU5PV13(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("dram_access",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("DRAM_CLOCK","WARP",&Impulse0);
}

GPU5PV13::~GPU5PV13() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV13::CreateWorkerList(void) {
}
GPU5PV14Worker::GPU5PV14Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
}

GPU5PV14Worker::~GPU5PV14Worker() {
  delete [] TheModelPtr;
}

double GPU5PV14Worker::Reward_Function(void) {

return WARP->INST_COUNTER->Mark();

return (0);



}

GPU5PV14::GPU5PV14(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={end};
  double stoppts[1]={end};
  Initialize("inst_ready",(RewardType)0,1, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("INST_COUNTER","WARP");
}

GPU5PV14::~GPU5PV14() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV14::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new GPU5PV14Worker;
}
GPU5PV15Impulse0::GPU5PV15Impulse0()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU5PV15Impulse0::~GPU5PV15Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV15Impulse0::Impulse_Function(double FiringTime)
{
return 2.0/(nsm * nprocessors);

return(0);
}

ImpulseNodeClass** GPU5PV15Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV15Impulse0;
  }

  return ImpulseWorkerList;
}

GPU5PV15Impulse1::GPU5PV15Impulse1()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU5PV15Impulse1::~GPU5PV15Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV15Impulse1::Impulse_Function(double FiringTime)
{
return 2.0/(nsm * nprocessors);

return(0);
}

ImpulseNodeClass** GPU5PV15Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV15Impulse1;
  }

  return ImpulseWorkerList;
}

GPU5PV15Impulse2::GPU5PV15Impulse2()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  TheModelPtr[1] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU5PV15Impulse2::~GPU5PV15Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV15Impulse2::Impulse_Function(double FiringTime)
{
return 2.0/(nsm * nprocessors);

return(0);
}

ImpulseNodeClass** GPU5PV15Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV15Impulse2;
  }

  return ImpulseWorkerList;
}

GPU5PV15Impulse3::GPU5PV15Impulse3()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU5PV15Impulse3::~GPU5PV15Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV15Impulse3::Impulse_Function(double FiringTime)
{
return 2.0/(nsm * nprocessors);

return(0);
}

ImpulseNodeClass** GPU5PV15Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV15Impulse3;
  }

  return ImpulseWorkerList;
}

GPU5PV15Impulse4::GPU5PV15Impulse4()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU5PV15Impulse4::~GPU5PV15Impulse4() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV15Impulse4::Impulse_Function(double FiringTime)
{
return 2.0/(nsm * nprocessors);

return(0);
}

ImpulseNodeClass** GPU5PV15Impulse4::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV15Impulse4;
  }

  return ImpulseWorkerList;
}

GPU5PV15Impulse5::GPU5PV15Impulse5()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  TheModelPtr[1] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU5PV15Impulse5::~GPU5PV15Impulse5() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV15Impulse5::Impulse_Function(double FiringTime)
{
return 300.0/(nsm * nprocessors);

return(0);
}

ImpulseNodeClass** GPU5PV15Impulse5::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV15Impulse5;
  }

  return ImpulseWorkerList;
}

GPU5PV15Impulse6::GPU5PV15Impulse6()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  TheModelPtr[1] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU5PV15Impulse6::~GPU5PV15Impulse6() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV15Impulse6::Impulse_Function(double FiringTime)
{
return 175.0/(nsm * nprocessors);

return(0);
}

ImpulseNodeClass** GPU5PV15Impulse6::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV15Impulse6;
  }

  return ImpulseWorkerList;
}

GPU5PV15Impulse7::GPU5PV15Impulse7()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  TheModelPtr[1] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU5PV15Impulse7::~GPU5PV15Impulse7() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV15Impulse7::Impulse_Function(double FiringTime)
{
return 100.0/(nsm * nprocessors);

return(0);
}

ImpulseNodeClass** GPU5PV15Impulse7::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV15Impulse7;
  }

  return ImpulseWorkerList;
}

GPU5PV15::GPU5PV15(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("clocks",(RewardType)1,1, startpts, stoppts, timeindex, 8,0, 0);
  AddImpulse("handle_failure","EXEC_UNIT",&Impulse0);
  AddImpulseModelDependency("WARP",&Impulse0);
  AddImpulseModelDependency("MEMORY",&Impulse0);
  AddImpulse("PERFORM_READ","MEMORY",&Impulse1);
  AddImpulseModelDependency("WARP",&Impulse1);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse1);
  AddImpulse("DISPATCHER_Copy","WARP",&Impulse2);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse2);
  AddImpulseModelDependency("MEMORY",&Impulse2);
  AddImpulse("DISPATCHER","EXEC_UNIT",&Impulse3);
  AddImpulseModelDependency("WARP",&Impulse3);
  AddImpulseModelDependency("MEMORY",&Impulse3);
  AddImpulse("PERFORM_WRITE","MEMORY",&Impulse4);
  AddImpulseModelDependency("WARP",&Impulse4);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse4);
  AddImpulse("DRAM_CLOCK","WARP",&Impulse5);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse5);
  AddImpulseModelDependency("MEMORY",&Impulse5);
  AddImpulse("L2_CLOCK","WARP",&Impulse6);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse6);
  AddImpulseModelDependency("MEMORY",&Impulse6);
  AddImpulse("L1_CLOCK","WARP",&Impulse7);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse7);
  AddImpulseModelDependency("MEMORY",&Impulse7);
}

GPU5PV15::~GPU5PV15() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV15::CreateWorkerList(void) {
}
GPU5PV16Impulse0::GPU5PV16Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU5PV16Impulse0::~GPU5PV16Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV16Impulse0::Impulse_Function(double FiringTime)
{
return 2;

return(0);
}

ImpulseNodeClass** GPU5PV16Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV16Impulse0;
  }

  return ImpulseWorkerList;
}

GPU5PV16Impulse1::GPU5PV16Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU5PV16Impulse1::~GPU5PV16Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV16Impulse1::Impulse_Function(double FiringTime)
{
return 30;

return(0);
}

ImpulseNodeClass** GPU5PV16Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV16Impulse1;
  }

  return ImpulseWorkerList;
}

GPU5PV16Impulse2::GPU5PV16Impulse2()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU5PV16Impulse2::~GPU5PV16Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV16Impulse2::Impulse_Function(double FiringTime)
{
return 400;

return(0);
}

ImpulseNodeClass** GPU5PV16Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV16Impulse2;
  }

  return ImpulseWorkerList;
}

GPU5PV16Impulse3::GPU5PV16Impulse3()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU5PV16Impulse3::~GPU5PV16Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV16Impulse3::Impulse_Function(double FiringTime)
{
return 600;

return(0);
}

ImpulseNodeClass** GPU5PV16Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV16Impulse3;
  }

  return ImpulseWorkerList;
}

GPU5PV16::GPU5PV16(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("clocks2",(RewardType)1,1, startpts, stoppts, timeindex, 4,0, 0);
  AddImpulse("DISPATCHER_Copy","WARP",&Impulse0);
  AddImpulse("L1_CLOCK","WARP",&Impulse1);
  AddImpulse("L2_CLOCK","WARP",&Impulse2);
  AddImpulse("DRAM_CLOCK","WARP",&Impulse3);
}

GPU5PV16::~GPU5PV16() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV16::CreateWorkerList(void) {
}
GPU5PV17Impulse0::GPU5PV17Impulse0()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  TheModelPtr[1] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU5PV17Impulse0::~GPU5PV17Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV17Impulse0::Impulse_Function(double FiringTime)
{
return 2;

return(0);
}

ImpulseNodeClass** GPU5PV17Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV17Impulse0;
  }

  return ImpulseWorkerList;
}

GPU5PV17Impulse1::GPU5PV17Impulse1()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU5PV17Impulse1::~GPU5PV17Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV17Impulse1::Impulse_Function(double FiringTime)
{
return 2;

return(0);
}

ImpulseNodeClass** GPU5PV17Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV17Impulse1;
  }

  return ImpulseWorkerList;
}

GPU5PV17Impulse2::GPU5PV17Impulse2()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU5PV17Impulse2::~GPU5PV17Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV17Impulse2::Impulse_Function(double FiringTime)
{
return 2;

return(0);
}

ImpulseNodeClass** GPU5PV17Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV17Impulse2;
  }

  return ImpulseWorkerList;
}

GPU5PV17Impulse3::GPU5PV17Impulse3()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU5PV17Impulse3::~GPU5PV17Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV17Impulse3::Impulse_Function(double FiringTime)
{
return 600;

return(0);
}

ImpulseNodeClass** GPU5PV17Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV17Impulse3;
  }

  return ImpulseWorkerList;
}

GPU5PV17Impulse4::GPU5PV17Impulse4()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU5PV17Impulse4::~GPU5PV17Impulse4() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV17Impulse4::Impulse_Function(double FiringTime)
{
return 30;

return(0);
}

ImpulseNodeClass** GPU5PV17Impulse4::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV17Impulse4;
  }

  return ImpulseWorkerList;
}

GPU5PV17Impulse5::GPU5PV17Impulse5()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU5PV17Impulse5::~GPU5PV17Impulse5() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV17Impulse5::Impulse_Function(double FiringTime)
{
return 400;

return(0);
}

ImpulseNodeClass** GPU5PV17Impulse5::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV17Impulse5;
  }

  return ImpulseWorkerList;
}

GPU5PV17Impulse6::GPU5PV17Impulse6()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU5PV17Impulse6::~GPU5PV17Impulse6() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV17Impulse6::Impulse_Function(double FiringTime)
{
return 400;

return(0);
}

ImpulseNodeClass** GPU5PV17Impulse6::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV17Impulse6;
  }

  return ImpulseWorkerList;
}

GPU5PV17Impulse7::GPU5PV17Impulse7()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU5PV17Impulse7::~GPU5PV17Impulse7() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV17Impulse7::Impulse_Function(double FiringTime)
{
return 30;

return(0);
}

ImpulseNodeClass** GPU5PV17Impulse7::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV17Impulse7;
  }

  return ImpulseWorkerList;
}

GPU5PV17Impulse8::GPU5PV17Impulse8()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU5PV17Impulse8::~GPU5PV17Impulse8() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV17Impulse8::Impulse_Function(double FiringTime)
{
return 400;

return(0);
}

ImpulseNodeClass** GPU5PV17Impulse8::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV17Impulse8;
  }

  return ImpulseWorkerList;
}

GPU5PV17Impulse9::GPU5PV17Impulse9()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU5PV17Impulse9::~GPU5PV17Impulse9() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV17Impulse9::Impulse_Function(double FiringTime)
{
return 30;

return(0);
}

ImpulseNodeClass** GPU5PV17Impulse9::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV17Impulse9;
  }

  return ImpulseWorkerList;
}

GPU5PV17Impulse10::GPU5PV17Impulse10()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU5PV17Impulse10::~GPU5PV17Impulse10() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV17Impulse10::Impulse_Function(double FiringTime)
{
return 600;

return(0);
}

ImpulseNodeClass** GPU5PV17Impulse10::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV17Impulse10;
  }

  return ImpulseWorkerList;
}

GPU5PV17Impulse11::GPU5PV17Impulse11()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU5PV17Impulse11::~GPU5PV17Impulse11() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV17Impulse11::Impulse_Function(double FiringTime)
{
return 600;

return(0);
}

ImpulseNodeClass** GPU5PV17Impulse11::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV17Impulse11;
  }

  return ImpulseWorkerList;
}

GPU5PV17Impulse12::GPU5PV17Impulse12()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU5PV17Impulse12::~GPU5PV17Impulse12() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV17Impulse12::Impulse_Function(double FiringTime)
{
return 30;

return(0);
}

ImpulseNodeClass** GPU5PV17Impulse12::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV17Impulse12;
  }

  return ImpulseWorkerList;
}

GPU5PV17Impulse13::GPU5PV17Impulse13()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU5PV17Impulse13::~GPU5PV17Impulse13() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV17Impulse13::Impulse_Function(double FiringTime)
{
return 400;

return(0);
}

ImpulseNodeClass** GPU5PV17Impulse13::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV17Impulse13;
  }

  return ImpulseWorkerList;
}

GPU5PV17Impulse14::GPU5PV17Impulse14()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU5PV17Impulse14::~GPU5PV17Impulse14() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV17Impulse14::Impulse_Function(double FiringTime)
{
return 600;

return(0);
}

ImpulseNodeClass** GPU5PV17Impulse14::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV17Impulse14;
  }

  return ImpulseWorkerList;
}

GPU5PV17Impulse15::GPU5PV17Impulse15()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU5PV17Impulse15::~GPU5PV17Impulse15() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU5PV17Impulse15::Impulse_Function(double FiringTime)
{
return 2000;

return(0);
}

ImpulseNodeClass** GPU5PV17Impulse15::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU5PV17Impulse15;
  }

  return ImpulseWorkerList;
}

GPU5PV17::GPU5PV17(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU5RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("clocks3",(RewardType)1,1, startpts, stoppts, timeindex, 16,0, 0);
  AddImpulse("DISPATCHER_Copy","WARP",&Impulse0);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse0);
  AddImpulseModelDependency("MEMORY",&Impulse0);
  AddImpulse("handle_failure","EXEC_UNIT",&Impulse1);
  AddImpulseModelDependency("WARP",&Impulse1);
  AddImpulseModelDependency("MEMORY",&Impulse1);
  AddImpulse("DISPATCHER","EXEC_UNIT",&Impulse2);
  AddImpulseModelDependency("WARP",&Impulse2);
  AddImpulseModelDependency("MEMORY",&Impulse2);
  AddImpulse("LOCAL_READ_FROM_case3","MEMORY",&Impulse3);
  AddImpulseModelDependency("WARP",&Impulse3);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse3);
  AddImpulse("LOCAL_READ_FROM_case1","MEMORY",&Impulse4);
  AddImpulseModelDependency("WARP",&Impulse4);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse4);
  AddImpulse("LOCAL_READ_FROM_case2","MEMORY",&Impulse5);
  AddImpulseModelDependency("WARP",&Impulse5);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse5);
  AddImpulse("GLOBAL_READ_FROM_case2","MEMORY",&Impulse6);
  AddImpulseModelDependency("WARP",&Impulse6);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse6);
  AddImpulse("LOCAL_WRITE_TO_case1","MEMORY",&Impulse7);
  AddImpulseModelDependency("WARP",&Impulse7);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse7);
  AddImpulse("LOCAL_WRITE_TO_case2","MEMORY",&Impulse8);
  AddImpulseModelDependency("WARP",&Impulse8);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse8);
  AddImpulse("GLOBAL_WRITE_TO_case1","MEMORY",&Impulse9);
  AddImpulseModelDependency("WARP",&Impulse9);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse9);
  AddImpulse("LOCAL_WRITE_TO_case3","MEMORY",&Impulse10);
  AddImpulseModelDependency("WARP",&Impulse10);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse10);
  AddImpulse("GLOBAL_WRITE_TO_case3","MEMORY",&Impulse11);
  AddImpulseModelDependency("WARP",&Impulse11);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse11);
  AddImpulse("GLOBAL_READ_FROM_case1","MEMORY",&Impulse12);
  AddImpulseModelDependency("WARP",&Impulse12);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse12);
  AddImpulse("GLOBAL_WRITE_TO_case2","MEMORY",&Impulse13);
  AddImpulseModelDependency("WARP",&Impulse13);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse13);
  AddImpulse("GLOBAL_READ_FROM_case3","MEMORY",&Impulse14);
  AddImpulseModelDependency("WARP",&Impulse14);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse14);
  AddImpulse("BARRIER_SYNC","EXEC_UNIT",&Impulse15);
  AddImpulseModelDependency("WARP",&Impulse15);
  AddImpulseModelDependency("MEMORY",&Impulse15);
}

GPU5PV17::~GPU5PV17() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU5PV17::CreateWorkerList(void) {
}
