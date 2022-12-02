#include "GPU4.BKPPVNodes.h"

GPU4.BKPPV0Impulse0::GPU4.BKPPV0Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV0Impulse0::~GPU4.BKPPV0Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV0Impulse0::Impulse_Function(double FiringTime)
{
return (1.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV0Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV0Impulse0;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV0::GPU4.BKPPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU4RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("warp",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("DISPATCHER_Copy","WARP",&Impulse0);
}

GPU4.BKPPV0::~GPU4.BKPPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU4.BKPPV0::CreateWorkerList(void) {
}
GPU4.BKPPV1Impulse0::GPU4.BKPPV1Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV1Impulse0::~GPU4.BKPPV1Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV1Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU4.BKPPV1Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV1Impulse0;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV1Impulse1::GPU4.BKPPV1Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV1Impulse1::~GPU4.BKPPV1Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV1Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU4.BKPPV1Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV1Impulse1;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV1::GPU4.BKPPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU4RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("read_l1",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case1","L1_CACHE",&Impulse0);
  AddImpulse("READ_FROM_case2","L1_CACHE",&Impulse1);
}

GPU4.BKPPV1::~GPU4.BKPPV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU4.BKPPV1::CreateWorkerList(void) {
}
GPU4.BKPPV2Impulse0::GPU4.BKPPV2Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV2Impulse0::~GPU4.BKPPV2Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV2Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU4.BKPPV2Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV2Impulse0;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV2Impulse1::GPU4.BKPPV2Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV2Impulse1::~GPU4.BKPPV2Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV2Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU4.BKPPV2Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV2Impulse1;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV2::GPU4.BKPPV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU4RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("write_l1",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("WRITE_WITH_KO_DATA","L1_CACHE",&Impulse0);
  AddImpulse("WRITE_WITH_OK_DATA","L1_CACHE",&Impulse1);
}

GPU4.BKPPV2::~GPU4.BKPPV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU4.BKPPV2::CreateWorkerList(void) {
}
GPU4.BKPPV3Impulse0::GPU4.BKPPV3Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV3Impulse0::~GPU4.BKPPV3Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV3Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU4.BKPPV3Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV3Impulse0;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV3Impulse1::GPU4.BKPPV3Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV3Impulse1::~GPU4.BKPPV3Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV3Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU4.BKPPV3Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV3Impulse1;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV3::GPU4.BKPPV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU4RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("read_l2",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case1","L2_CACHE",&Impulse0);
  AddImpulse("READ_FROM_case2","L2_CACHE",&Impulse1);
}

GPU4.BKPPV3::~GPU4.BKPPV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU4.BKPPV3::CreateWorkerList(void) {
}
GPU4.BKPPV4Impulse0::GPU4.BKPPV4Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV4Impulse0::~GPU4.BKPPV4Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV4Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU4.BKPPV4Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV4Impulse0;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV4Impulse1::GPU4.BKPPV4Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV4Impulse1::~GPU4.BKPPV4Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV4Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU4.BKPPV4Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV4Impulse1;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV4::GPU4.BKPPV4(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU4RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("write_l2",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("WRITE_WITH_KO_DATA","L2_CACHE",&Impulse0);
  AddImpulse("WRITE_WITH_OK_DATA","L2_CACHE",&Impulse1);
}

GPU4.BKPPV4::~GPU4.BKPPV4() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU4.BKPPV4::CreateWorkerList(void) {
}
GPU4.BKPPV5Impulse0::GPU4.BKPPV5Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV5Impulse0::~GPU4.BKPPV5Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV5Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU4.BKPPV5Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV5Impulse0;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV5Impulse1::GPU4.BKPPV5Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV5Impulse1::~GPU4.BKPPV5Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV5Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU4.BKPPV5Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV5Impulse1;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV5::GPU4.BKPPV5(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU4RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("read_dram",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case1","DRAM",&Impulse0);
  AddImpulse("READ_FROM_case2","DRAM",&Impulse1);
}

GPU4.BKPPV5::~GPU4.BKPPV5() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU4.BKPPV5::CreateWorkerList(void) {
}
GPU4.BKPPV6Impulse0::GPU4.BKPPV6Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV6Impulse0::~GPU4.BKPPV6Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV6Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU4.BKPPV6Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV6Impulse0;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV6Impulse1::GPU4.BKPPV6Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV6Impulse1::~GPU4.BKPPV6Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV6Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU4.BKPPV6Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV6Impulse1;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV6::GPU4.BKPPV6(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU4RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("write_dram",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("WRITE_WITH_KO_DATA","DRAM",&Impulse0);
  AddImpulse("WRITE_WITH_OK_DATA","DRAM",&Impulse1);
}

GPU4.BKPPV6::~GPU4.BKPPV6() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU4.BKPPV6::CreateWorkerList(void) {
}
GPU4.BKPPV7Impulse0::GPU4.BKPPV7Impulse0()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[1] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[2] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[3] = (BaseModelClass**)(&DRAM);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse0::~GPU4.BKPPV7Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse0::Impulse_Function(double FiringTime)
{
return (2.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse0;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse1::GPU4.BKPPV7Impulse1()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[1] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[2] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[3] = (BaseModelClass**)(&DRAM);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse1::~GPU4.BKPPV7Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse1::Impulse_Function(double FiringTime)
{
return (4.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse1;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse2::GPU4.BKPPV7Impulse2()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[1] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[2] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[3] = (BaseModelClass**)(&DRAM);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse2::~GPU4.BKPPV7Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse2::Impulse_Function(double FiringTime)
{
return (4.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse2;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse3::GPU4.BKPPV7Impulse3()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[1] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[2] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[3] = (BaseModelClass**)(&DRAM);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse3::~GPU4.BKPPV7Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse3::Impulse_Function(double FiringTime)
{
return (2.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse3;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse4::GPU4.BKPPV7Impulse4()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[1] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[2] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[3] = (BaseModelClass**)(&DRAM);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse4::~GPU4.BKPPV7Impulse4() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse4::Impulse_Function(double FiringTime)
{
return (2.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse4::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse4;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse5::GPU4.BKPPV7Impulse5()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[3] = (BaseModelClass**)(&DRAM);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse5::~GPU4.BKPPV7Impulse5() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse5::Impulse_Function(double FiringTime)
{
return (2.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse5::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse5;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse6::GPU4.BKPPV7Impulse6()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[3] = (BaseModelClass**)(&DRAM);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse6::~GPU4.BKPPV7Impulse6() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse6::Impulse_Function(double FiringTime)
{
return (2.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse6::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse6;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse7::GPU4.BKPPV7Impulse7()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[3] = (BaseModelClass**)(&DRAM);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse7::~GPU4.BKPPV7Impulse7() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse7::Impulse_Function(double FiringTime)
{
return (2.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse7::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse7;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse8::GPU4.BKPPV7Impulse8()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[3] = (BaseModelClass**)(&DRAM);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse8::~GPU4.BKPPV7Impulse8() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse8::Impulse_Function(double FiringTime)
{
return (2.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse8::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse8;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse9::GPU4.BKPPV7Impulse9()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&DRAM);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse9::~GPU4.BKPPV7Impulse9() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse9::Impulse_Function(double FiringTime)
{
return (50.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse9::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse9;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse10::GPU4.BKPPV7Impulse10()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&DRAM);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse10::~GPU4.BKPPV7Impulse10() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse10::Impulse_Function(double FiringTime)
{
return (50.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse10::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse10;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse11::GPU4.BKPPV7Impulse11()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&DRAM);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse11::~GPU4.BKPPV7Impulse11() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse11::Impulse_Function(double FiringTime)
{
return (50.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse11::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse11;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse12::GPU4.BKPPV7Impulse12()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&DRAM);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse12::~GPU4.BKPPV7Impulse12() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse12::Impulse_Function(double FiringTime)
{
return (50.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse12::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse12;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse13::GPU4.BKPPV7Impulse13()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse13::~GPU4.BKPPV7Impulse13() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse13::Impulse_Function(double FiringTime)
{
return (360.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse13::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse13;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse14::GPU4.BKPPV7Impulse14()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse14::~GPU4.BKPPV7Impulse14() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse14::Impulse_Function(double FiringTime)
{
return (360.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse14::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse14;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse15::GPU4.BKPPV7Impulse15()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse15::~GPU4.BKPPV7Impulse15() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse15::Impulse_Function(double FiringTime)
{
return (360.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse15::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse15;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse16::GPU4.BKPPV7Impulse16()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[4] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse16::~GPU4.BKPPV7Impulse16() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse16::Impulse_Function(double FiringTime)
{
return (360.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse16::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse16;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse17::GPU4.BKPPV7Impulse17()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[4] = (BaseModelClass**)(&DRAM);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse17::~GPU4.BKPPV7Impulse17() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse17::Impulse_Function(double FiringTime)
{
return (100.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse17::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse17;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse18::GPU4.BKPPV7Impulse18()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[4] = (BaseModelClass**)(&DRAM);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse18::~GPU4.BKPPV7Impulse18() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse18::Impulse_Function(double FiringTime)
{
return (100.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse18::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse18;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse19::GPU4.BKPPV7Impulse19()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[4] = (BaseModelClass**)(&DRAM);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse19::~GPU4.BKPPV7Impulse19() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse19::Impulse_Function(double FiringTime)
{
return (100.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse19::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse19;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7Impulse20::GPU4.BKPPV7Impulse20()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[4] = (BaseModelClass**)(&DRAM);
  TheModelPtr[5] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU4.BKPPV7Impulse20::~GPU4.BKPPV7Impulse20() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU4.BKPPV7Impulse20::Impulse_Function(double FiringTime)
{
return (100.0/nwarps);

return(0);
}

ImpulseNodeClass** GPU4.BKPPV7Impulse20::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU4.BKPPV7Impulse20;
  }

  return ImpulseWorkerList;
}

GPU4.BKPPV7::GPU4.BKPPV7(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU4RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("clock_cycles",(RewardType)1,1, startpts, stoppts, timeindex, 21,0, 0);
  AddImpulse("DISPATCHER","COMPUTE_UNIT",&Impulse0);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse0);
  AddImpulseModelDependency("L1_CACHE",&Impulse0);
  AddImpulseModelDependency("DRAM",&Impulse0);
  AddImpulseModelDependency("L2_CACHE",&Impulse0);
  AddImpulseModelDependency("WARP",&Impulse0);
  AddImpulse("COMPUTE_WITH_KO_DATA","COMPUTE_UNIT",&Impulse1);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse1);
  AddImpulseModelDependency("L1_CACHE",&Impulse1);
  AddImpulseModelDependency("DRAM",&Impulse1);
  AddImpulseModelDependency("L2_CACHE",&Impulse1);
  AddImpulseModelDependency("WARP",&Impulse1);
  AddImpulse("COMPUTE_WITH_OK_DATA","COMPUTE_UNIT",&Impulse2);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse2);
  AddImpulseModelDependency("L1_CACHE",&Impulse2);
  AddImpulseModelDependency("DRAM",&Impulse2);
  AddImpulseModelDependency("L2_CACHE",&Impulse2);
  AddImpulseModelDependency("WARP",&Impulse2);
  AddImpulse("Instantaneous_Activity2_case1","COMPUTE_UNIT",&Impulse3);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse3);
  AddImpulseModelDependency("L1_CACHE",&Impulse3);
  AddImpulseModelDependency("DRAM",&Impulse3);
  AddImpulseModelDependency("L2_CACHE",&Impulse3);
  AddImpulseModelDependency("WARP",&Impulse3);
  AddImpulse("Instantaneous_Activity2_case2","COMPUTE_UNIT",&Impulse4);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse4);
  AddImpulseModelDependency("L1_CACHE",&Impulse4);
  AddImpulseModelDependency("DRAM",&Impulse4);
  AddImpulseModelDependency("L2_CACHE",&Impulse4);
  AddImpulseModelDependency("WARP",&Impulse4);
  AddImpulse("WRITE_WITH_KO_DATA","REGISTER_FILE",&Impulse5);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse5);
  AddImpulseModelDependency("L1_CACHE",&Impulse5);
  AddImpulseModelDependency("DRAM",&Impulse5);
  AddImpulseModelDependency("L2_CACHE",&Impulse5);
  AddImpulseModelDependency("WARP",&Impulse5);
  AddImpulse("WRITE_WITH_OK_DATA","REGISTER_FILE",&Impulse6);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse6);
  AddImpulseModelDependency("L1_CACHE",&Impulse6);
  AddImpulseModelDependency("DRAM",&Impulse6);
  AddImpulseModelDependency("L2_CACHE",&Impulse6);
  AddImpulseModelDependency("WARP",&Impulse6);
  AddImpulse("READ_FROM_case1","REGISTER_FILE",&Impulse7);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse7);
  AddImpulseModelDependency("L1_CACHE",&Impulse7);
  AddImpulseModelDependency("DRAM",&Impulse7);
  AddImpulseModelDependency("L2_CACHE",&Impulse7);
  AddImpulseModelDependency("WARP",&Impulse7);
  AddImpulse("READ_FROM_case2","REGISTER_FILE",&Impulse8);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse8);
  AddImpulseModelDependency("L1_CACHE",&Impulse8);
  AddImpulseModelDependency("DRAM",&Impulse8);
  AddImpulseModelDependency("L2_CACHE",&Impulse8);
  AddImpulseModelDependency("WARP",&Impulse8);
  AddImpulse("WRITE_WITH_KO_DATA","L1_CACHE",&Impulse9);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse9);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse9);
  AddImpulseModelDependency("DRAM",&Impulse9);
  AddImpulseModelDependency("L2_CACHE",&Impulse9);
  AddImpulseModelDependency("WARP",&Impulse9);
  AddImpulse("WRITE_WITH_OK_DATA","L1_CACHE",&Impulse10);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse10);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse10);
  AddImpulseModelDependency("DRAM",&Impulse10);
  AddImpulseModelDependency("L2_CACHE",&Impulse10);
  AddImpulseModelDependency("WARP",&Impulse10);
  AddImpulse("READ_FROM_case1","L1_CACHE",&Impulse11);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse11);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse11);
  AddImpulseModelDependency("DRAM",&Impulse11);
  AddImpulseModelDependency("L2_CACHE",&Impulse11);
  AddImpulseModelDependency("WARP",&Impulse11);
  AddImpulse("READ_FROM_case2","L1_CACHE",&Impulse12);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse12);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse12);
  AddImpulseModelDependency("DRAM",&Impulse12);
  AddImpulseModelDependency("L2_CACHE",&Impulse12);
  AddImpulseModelDependency("WARP",&Impulse12);
  AddImpulse("WRITE_WITH_KO_DATA","DRAM",&Impulse13);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse13);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse13);
  AddImpulseModelDependency("L1_CACHE",&Impulse13);
  AddImpulseModelDependency("L2_CACHE",&Impulse13);
  AddImpulseModelDependency("WARP",&Impulse13);
  AddImpulse("WRITE_WITH_OK_DATA","DRAM",&Impulse14);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse14);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse14);
  AddImpulseModelDependency("L1_CACHE",&Impulse14);
  AddImpulseModelDependency("L2_CACHE",&Impulse14);
  AddImpulseModelDependency("WARP",&Impulse14);
  AddImpulse("READ_FROM_case1","DRAM",&Impulse15);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse15);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse15);
  AddImpulseModelDependency("L1_CACHE",&Impulse15);
  AddImpulseModelDependency("L2_CACHE",&Impulse15);
  AddImpulseModelDependency("WARP",&Impulse15);
  AddImpulse("READ_FROM_case2","DRAM",&Impulse16);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse16);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse16);
  AddImpulseModelDependency("L1_CACHE",&Impulse16);
  AddImpulseModelDependency("L2_CACHE",&Impulse16);
  AddImpulseModelDependency("WARP",&Impulse16);
  AddImpulse("WRITE_WITH_KO_DATA","L2_CACHE",&Impulse17);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse17);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse17);
  AddImpulseModelDependency("L1_CACHE",&Impulse17);
  AddImpulseModelDependency("DRAM",&Impulse17);
  AddImpulseModelDependency("WARP",&Impulse17);
  AddImpulse("WRITE_WITH_OK_DATA","L2_CACHE",&Impulse18);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse18);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse18);
  AddImpulseModelDependency("L1_CACHE",&Impulse18);
  AddImpulseModelDependency("DRAM",&Impulse18);
  AddImpulseModelDependency("WARP",&Impulse18);
  AddImpulse("READ_FROM_case1","L2_CACHE",&Impulse19);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse19);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse19);
  AddImpulseModelDependency("L1_CACHE",&Impulse19);
  AddImpulseModelDependency("DRAM",&Impulse19);
  AddImpulseModelDependency("WARP",&Impulse19);
  AddImpulse("READ_FROM_case2","L2_CACHE",&Impulse20);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse20);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse20);
  AddImpulseModelDependency("L1_CACHE",&Impulse20);
  AddImpulseModelDependency("DRAM",&Impulse20);
  AddImpulseModelDependency("WARP",&Impulse20);
}

GPU4.BKPPV7::~GPU4.BKPPV7() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU4.BKPPV7::CreateWorkerList(void) {
}
