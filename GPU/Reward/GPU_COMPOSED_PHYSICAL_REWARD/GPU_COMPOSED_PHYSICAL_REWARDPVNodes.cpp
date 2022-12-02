#include "GPU_COMPOSED_PHYSICAL_REWARDPVNodes.h"

GPU_COMPOSED_PHYSICAL_REWARDPV0Impulse0::GPU_COMPOSED_PHYSICAL_REWARDPV0Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV0Impulse0::~GPU_COMPOSED_PHYSICAL_REWARDPV0Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV0Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV0Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV0Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV0::GPU_COMPOSED_PHYSICAL_REWARDPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_PHYSICALRJ);
  double startpts[1]={0.0};
  double stoppts[1]={10000};
  Initialize("token_game",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("DISPATCHER","COMPUTE_UNIT",&Impulse0);
}

GPU_COMPOSED_PHYSICAL_REWARDPV0::~GPU_COMPOSED_PHYSICAL_REWARDPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_PHYSICAL_REWARDPV0::CreateWorkerList(void) {
}
GPU_COMPOSED_PHYSICAL_REWARDPV1Impulse0::GPU_COMPOSED_PHYSICAL_REWARDPV1Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&OUTPUT_MEMORY_PHYSICAL);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV1Impulse0::~GPU_COMPOSED_PHYSICAL_REWARDPV1Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV1Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV1Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV1Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV1::GPU_COMPOSED_PHYSICAL_REWARDPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_PHYSICALRJ);
  double startpts[1]={0.0};
  double stoppts[1]={10000};
  Initialize("output_writes",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("WRITE_TO","OUTPUT_MEMORY_PHYSICAL",&Impulse0);
}

GPU_COMPOSED_PHYSICAL_REWARDPV1::~GPU_COMPOSED_PHYSICAL_REWARDPV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_PHYSICAL_REWARDPV1::CreateWorkerList(void) {
}
GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse0::GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&RESULT_MEMORY_MODEL_PHYSICAL);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse0::~GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse1::GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&RESULT_MEMORY_MODEL_PHYSICAL);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse1::~GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse2::GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse2()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&RESULT_MEMORY_MODEL_PHYSICAL);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse2::~GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse2::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV2Impulse2;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV2::GPU_COMPOSED_PHYSICAL_REWARDPV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_PHYSICALRJ);
  double startpts[1]={0.0};
  double stoppts[1]={10000};
  Initialize("result_writes",(RewardType)1,1, startpts, stoppts, timeindex, 3,0, 0);
  AddImpulse("WRITE_TO_case1","RESULT_MEMORY_MODEL_PHYSICAL",&Impulse0);
  AddImpulse("WRITE_TO_case2","RESULT_MEMORY_MODEL_PHYSICAL",&Impulse1);
  AddImpulse("WRITE_TO_case3","RESULT_MEMORY_MODEL_PHYSICAL",&Impulse2);
}

GPU_COMPOSED_PHYSICAL_REWARDPV2::~GPU_COMPOSED_PHYSICAL_REWARDPV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_PHYSICAL_REWARDPV2::CreateWorkerList(void) {
}
GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse0::GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&RESULT_MEMORY_MODEL_PHYSICAL);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse0::~GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse1::GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&RESULT_MEMORY_MODEL_PHYSICAL);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse1::~GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse2::GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse2()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&RESULT_MEMORY_MODEL_PHYSICAL);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse2::~GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse2::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV3Impulse2;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV3::GPU_COMPOSED_PHYSICAL_REWARDPV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_PHYSICALRJ);
  double startpts[1]={0.0};
  double stoppts[1]={10000};
  Initialize("result_reads",(RewardType)1,1, startpts, stoppts, timeindex, 3,0, 0);
  AddImpulse("READ_FROM_case1","RESULT_MEMORY_MODEL_PHYSICAL",&Impulse0);
  AddImpulse("READ_FROM_case2","RESULT_MEMORY_MODEL_PHYSICAL",&Impulse1);
  AddImpulse("READ_FROM_case3","RESULT_MEMORY_MODEL_PHYSICAL",&Impulse2);
}

GPU_COMPOSED_PHYSICAL_REWARDPV3::~GPU_COMPOSED_PHYSICAL_REWARDPV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_PHYSICAL_REWARDPV3::CreateWorkerList(void) {
}
GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse0::GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&TOTAL_MEMORY_MODEL_PHYSICAL);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse0::~GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse1::GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&TOTAL_MEMORY_MODEL_PHYSICAL);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse1::~GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse2::GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse2()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&TOTAL_MEMORY_MODEL_PHYSICAL);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse2::~GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse2::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV4Impulse2;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV4::GPU_COMPOSED_PHYSICAL_REWARDPV4(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_PHYSICALRJ);
  double startpts[1]={0.0};
  double stoppts[1]={10000};
  Initialize("total_reads",(RewardType)1,1, startpts, stoppts, timeindex, 3,0, 0);
  AddImpulse("READ_FROM_case3","TOTAL_MEMORY_MODEL_PHYSICAL",&Impulse0);
  AddImpulse("READ_FROM_case1","TOTAL_MEMORY_MODEL_PHYSICAL",&Impulse1);
  AddImpulse("READ_FROM_case2","TOTAL_MEMORY_MODEL_PHYSICAL",&Impulse2);
}

GPU_COMPOSED_PHYSICAL_REWARDPV4::~GPU_COMPOSED_PHYSICAL_REWARDPV4() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_PHYSICAL_REWARDPV4::CreateWorkerList(void) {
}
GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse0::GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse0::~GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse1::GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse1::~GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV5Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV5::GPU_COMPOSED_PHYSICAL_REWARDPV5(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_PHYSICALRJ);
  double startpts[1]={0.0};
  double stoppts[1]={10000};
  Initialize("compute",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("COMPUTE_WITH_OK_DATA","COMPUTE_UNIT",&Impulse0);
  AddImpulse("COMPUTE_WITH_KO_DATA","COMPUTE_UNIT",&Impulse1);
}

GPU_COMPOSED_PHYSICAL_REWARDPV5::~GPU_COMPOSED_PHYSICAL_REWARDPV5() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_PHYSICAL_REWARDPV5::CreateWorkerList(void) {
}
GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse0::GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse0::~GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse0::Impulse_Function(double FiringTime)
{


return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse1::GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse1::~GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV6Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV6::GPU_COMPOSED_PHYSICAL_REWARDPV6(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_PHYSICALRJ);
  double startpts[1]={0.0};
  double stoppts[1]={10000};
  Initialize("dram_reads",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case1","DRAM",&Impulse0);
  AddImpulse("READ_FROM_case2","DRAM",&Impulse1);
}

GPU_COMPOSED_PHYSICAL_REWARDPV6::~GPU_COMPOSED_PHYSICAL_REWARDPV6() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_PHYSICAL_REWARDPV6::CreateWorkerList(void) {
}
GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse0::GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse0::~GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse0::Impulse_Function(double FiringTime)
{


return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse1::GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse1::~GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV7Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV7::GPU_COMPOSED_PHYSICAL_REWARDPV7(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_PHYSICALRJ);
  double startpts[1]={0.0};
  double stoppts[1]={10000};
  Initialize("l2_reads",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case1","L2_CACHE",&Impulse0);
  AddImpulse("READ_FROM_case2","L2_CACHE",&Impulse1);
}

GPU_COMPOSED_PHYSICAL_REWARDPV7::~GPU_COMPOSED_PHYSICAL_REWARDPV7() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_PHYSICAL_REWARDPV7::CreateWorkerList(void) {
}
GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse0::GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse0::~GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse1::GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse1::~GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV8Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV8::GPU_COMPOSED_PHYSICAL_REWARDPV8(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_PHYSICALRJ);
  double startpts[1]={0.0};
  double stoppts[1]={10000};
  Initialize("l1_reads",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case1","L1_CACHE",&Impulse0);
  AddImpulse("READ_FROM_case2","L1_CACHE",&Impulse1);
}

GPU_COMPOSED_PHYSICAL_REWARDPV8::~GPU_COMPOSED_PHYSICAL_REWARDPV8() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_PHYSICAL_REWARDPV8::CreateWorkerList(void) {
}
GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse0::GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse0::~GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse1::GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse1::~GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV9Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV9::GPU_COMPOSED_PHYSICAL_REWARDPV9(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_PHYSICALRJ);
  double startpts[1]={0.0};
  double stoppts[1]={10000};
  Initialize("dram_writes",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("WRITE_WITH_OK_DATA","DRAM",&Impulse0);
  AddImpulse("WRITE_WITH_KO_DATA","DRAM",&Impulse1);
}

GPU_COMPOSED_PHYSICAL_REWARDPV9::~GPU_COMPOSED_PHYSICAL_REWARDPV9() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_PHYSICAL_REWARDPV9::CreateWorkerList(void) {
}
GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse0::GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse0::~GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse1::GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse1::~GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV10Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV10::GPU_COMPOSED_PHYSICAL_REWARDPV10(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_PHYSICALRJ);
  double startpts[1]={0.0};
  double stoppts[1]={10000};
  Initialize("l2_writes",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("WRITE_WITH_OK_DATA","L2_CACHE",&Impulse0);
  AddImpulse("WRITE_WITH_KO_DATA","L2_CACHE",&Impulse1);
}

GPU_COMPOSED_PHYSICAL_REWARDPV10::~GPU_COMPOSED_PHYSICAL_REWARDPV10() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_PHYSICAL_REWARDPV10::CreateWorkerList(void) {
}
GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse0::GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse0::~GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse1::GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse1::~GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_PHYSICAL_REWARDPV11Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_PHYSICAL_REWARDPV11::GPU_COMPOSED_PHYSICAL_REWARDPV11(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_PHYSICALRJ);
  double startpts[1]={0.0};
  double stoppts[1]={10000};
  Initialize("l1_writes",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("WRITE_WITH_KO_DATA","L1_CACHE",&Impulse0);
  AddImpulse("WRITE_WITH_OK_DATA","L1_CACHE",&Impulse1);
}

GPU_COMPOSED_PHYSICAL_REWARDPV11::~GPU_COMPOSED_PHYSICAL_REWARDPV11() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_PHYSICAL_REWARDPV11::CreateWorkerList(void) {
}
