#include "GPU_REWARDPVNodes.h"

GPU_REWARDPV0Impulse0::GPU_REWARDPV0Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
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
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("dispatcher",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("DISPATCHER","COMPUTE_UNIT",&Impulse0);
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
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
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

GPU_REWARDPV1Impulse1::GPU_REWARDPV1Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV1Impulse1::~GPU_REWARDPV1Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV1Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV1Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV1Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV1::GPU_REWARDPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("dram_reads",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case1","DRAM",&Impulse0);
  AddImpulse("READ_FROM_case2","DRAM",&Impulse1);
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
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
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

GPU_REWARDPV2Impulse1::GPU_REWARDPV2Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV2Impulse1::~GPU_REWARDPV2Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV2Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV2Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV2Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV2::GPU_REWARDPV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("l2_reads",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case2","L2_CACHE",&Impulse0);
  AddImpulse("READ_FROM_case1","L2_CACHE",&Impulse1);
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
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
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

GPU_REWARDPV3Impulse1::GPU_REWARDPV3Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV3Impulse1::~GPU_REWARDPV3Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV3Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV3Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV3Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV3::GPU_REWARDPV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("l1_reads",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case1","L1_CACHE",&Impulse0);
  AddImpulse("READ_FROM_case2","L1_CACHE",&Impulse1);
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
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&DRAM);
  TheModelPtr[3] = (BaseModelClass**)(&REGISTER_FILE);
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

GPU_REWARDPV4Impulse1::GPU_REWARDPV4Impulse1()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&DRAM);
  TheModelPtr[3] = (BaseModelClass**)(&REGISTER_FILE);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV4Impulse1::~GPU_REWARDPV4Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV4Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV4Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV4Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV4Impulse2::GPU_REWARDPV4Impulse2()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&DRAM);
  TheModelPtr[3] = (BaseModelClass**)(&REGISTER_FILE);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV4Impulse2::~GPU_REWARDPV4Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV4Impulse2::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV4Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV4Impulse2;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV4Impulse3::GPU_REWARDPV4Impulse3()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&DRAM);
  TheModelPtr[3] = (BaseModelClass**)(&REGISTER_FILE);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV4Impulse3::~GPU_REWARDPV4Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV4Impulse3::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV4Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV4Impulse3;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV4Impulse4::GPU_REWARDPV4Impulse4()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  TheModelPtr[1] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[3] = (BaseModelClass**)(&REGISTER_FILE);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV4Impulse4::~GPU_REWARDPV4Impulse4() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV4Impulse4::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV4Impulse4::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV4Impulse4;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV4Impulse5::GPU_REWARDPV4Impulse5()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  TheModelPtr[1] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[3] = (BaseModelClass**)(&REGISTER_FILE);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV4Impulse5::~GPU_REWARDPV4Impulse5() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV4Impulse5::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV4Impulse5::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV4Impulse5;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV4Impulse6::GPU_REWARDPV4Impulse6()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[1] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[3] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV4Impulse6::~GPU_REWARDPV4Impulse6() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV4Impulse6::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV4Impulse6::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV4Impulse6;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV4Impulse7::GPU_REWARDPV4Impulse7()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[1] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[3] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV4Impulse7::~GPU_REWARDPV4Impulse7() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV4Impulse7::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV4Impulse7::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV4Impulse7;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV4::GPU_REWARDPV4(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("reads",(RewardType)1,1, startpts, stoppts, timeindex, 8,0, 0);
  AddImpulse("READ_FROM_case1","L1_CACHE",&Impulse0);
  AddImpulseModelDependency("L2_CACHE",&Impulse0);
  AddImpulseModelDependency("DRAM",&Impulse0);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse0);
  AddImpulse("READ_FROM_case2","L1_CACHE",&Impulse1);
  AddImpulseModelDependency("L2_CACHE",&Impulse1);
  AddImpulseModelDependency("DRAM",&Impulse1);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse1);
  AddImpulse("READ_FROM_case2","L2_CACHE",&Impulse2);
  AddImpulseModelDependency("L1_CACHE",&Impulse2);
  AddImpulseModelDependency("DRAM",&Impulse2);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse2);
  AddImpulse("READ_FROM_case1","L2_CACHE",&Impulse3);
  AddImpulseModelDependency("L1_CACHE",&Impulse3);
  AddImpulseModelDependency("DRAM",&Impulse3);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse3);
  AddImpulse("READ_FROM_case1","DRAM",&Impulse4);
  AddImpulseModelDependency("L1_CACHE",&Impulse4);
  AddImpulseModelDependency("L2_CACHE",&Impulse4);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse4);
  AddImpulse("READ_FROM_case2","DRAM",&Impulse5);
  AddImpulseModelDependency("L1_CACHE",&Impulse5);
  AddImpulseModelDependency("L2_CACHE",&Impulse5);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse5);
  AddImpulse("READ_FROM_case1","REGISTER_FILE",&Impulse6);
  AddImpulseModelDependency("L1_CACHE",&Impulse6);
  AddImpulseModelDependency("L2_CACHE",&Impulse6);
  AddImpulseModelDependency("DRAM",&Impulse6);
  AddImpulse("READ_FROM_case2","REGISTER_FILE",&Impulse7);
  AddImpulseModelDependency("L1_CACHE",&Impulse7);
  AddImpulseModelDependency("L2_CACHE",&Impulse7);
  AddImpulseModelDependency("DRAM",&Impulse7);
}

GPU_REWARDPV4::~GPU_REWARDPV4() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_REWARDPV4::CreateWorkerList(void) {
}
