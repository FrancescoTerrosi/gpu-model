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
  NumberOfModelDependencies = 2;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[1] = (BaseModelClass**)(&INITIAL_MEMORY_MODEL);
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
  NumberOfModelDependencies = 2;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[1] = (BaseModelClass**)(&INITIAL_MEMORY_MODEL);
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

GPU_REWARDPV1Impulse2::GPU_REWARDPV1Impulse2()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&INITIAL_MEMORY_MODEL);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV1Impulse2::~GPU_REWARDPV1Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV1Impulse2::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV1Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV1Impulse2;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV1Impulse3::GPU_REWARDPV1Impulse3()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&INITIAL_MEMORY_MODEL);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV1Impulse3::~GPU_REWARDPV1Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV1Impulse3::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV1Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV1Impulse3;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV1::GPU_REWARDPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0};
  double stoppts[1]={end};
  Initialize("initial_memory_read",(RewardType)1,1, startpts, stoppts, timeindex, 4,0, 0);
  AddImpulse("READ_FROM_case2","TOTAL_MEMORY_MODEL",&Impulse0);
  AddImpulseModelDependency("INITIAL_MEMORY_MODEL",&Impulse0);
  AddImpulse("READ_FROM_case1","TOTAL_MEMORY_MODEL",&Impulse1);
  AddImpulseModelDependency("INITIAL_MEMORY_MODEL",&Impulse1);
  AddImpulse("READ_FROM_case1","INITIAL_MEMORY_MODEL",&Impulse2);
  AddImpulse("READ_FROM_case2","INITIAL_MEMORY_MODEL",&Impulse3);
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
  NumberOfModelDependencies = 2;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[1] = (BaseModelClass**)(&INTERMEDIATE_MEMORY_MODEL);
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
  NumberOfModelDependencies = 2;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[1] = (BaseModelClass**)(&INTERMEDIATE_MEMORY_MODEL);
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

GPU_REWARDPV2Impulse2::GPU_REWARDPV2Impulse2()
{
  NumberOfModelDependencies = 2;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[1] = (BaseModelClass**)(&INTERMEDIATE_MEMORY_MODEL);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV2Impulse2::~GPU_REWARDPV2Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV2Impulse2::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV2Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV2Impulse2;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV2Impulse3::GPU_REWARDPV2Impulse3()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&INTERMEDIATE_MEMORY_MODEL);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV2Impulse3::~GPU_REWARDPV2Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV2Impulse3::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV2Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV2Impulse3;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV2Impulse4::GPU_REWARDPV2Impulse4()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&INTERMEDIATE_MEMORY_MODEL);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV2Impulse4::~GPU_REWARDPV2Impulse4() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV2Impulse4::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV2Impulse4::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV2Impulse4;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV2Impulse5::GPU_REWARDPV2Impulse5()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&INTERMEDIATE_MEMORY_MODEL);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV2Impulse5::~GPU_REWARDPV2Impulse5() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV2Impulse5::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV2Impulse5::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV2Impulse5;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV2::GPU_REWARDPV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0};
  double stoppts[1]={end};
  Initialize("intermediate_memory_read",(RewardType)1,1, startpts, stoppts, timeindex, 6,0, 0);
  AddImpulse("READ_FROM_case1","RESULT_MEMORY_MODEL",&Impulse0);
  AddImpulseModelDependency("INTERMEDIATE_MEMORY_MODEL",&Impulse0);
  AddImpulse("READ_FROM_case2","RESULT_MEMORY_MODEL",&Impulse1);
  AddImpulseModelDependency("INTERMEDIATE_MEMORY_MODEL",&Impulse1);
  AddImpulse("READ_FROM_case3","RESULT_MEMORY_MODEL",&Impulse2);
  AddImpulseModelDependency("INTERMEDIATE_MEMORY_MODEL",&Impulse2);
  AddImpulse("READ_FROM_case1","INTERMEDIATE_MEMORY_MODEL",&Impulse3);
  AddImpulse("READ_FROM_case2","INTERMEDIATE_MEMORY_MODEL",&Impulse4);
  AddImpulse("READ_FROM_case3","INTERMEDIATE_MEMORY_MODEL",&Impulse5);
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
  NumberOfModelDependencies = 2;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[1] = (BaseModelClass**)(&INTERMEDIATE_MEMORY_MODEL);
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
  NumberOfModelDependencies = 2;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[1] = (BaseModelClass**)(&INTERMEDIATE_MEMORY_MODEL);
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

GPU_REWARDPV3Impulse2::GPU_REWARDPV3Impulse2()
{
  NumberOfModelDependencies = 2;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[1] = (BaseModelClass**)(&INTERMEDIATE_MEMORY_MODEL);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV3Impulse2::~GPU_REWARDPV3Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV3Impulse2::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV3Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV3Impulse2;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV3Impulse3::GPU_REWARDPV3Impulse3()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&INTERMEDIATE_MEMORY_MODEL);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV3Impulse3::~GPU_REWARDPV3Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV3Impulse3::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV3Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV3Impulse3;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV3Impulse4::GPU_REWARDPV3Impulse4()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&INTERMEDIATE_MEMORY_MODEL);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV3Impulse4::~GPU_REWARDPV3Impulse4() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV3Impulse4::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV3Impulse4::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV3Impulse4;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV3Impulse5::GPU_REWARDPV3Impulse5()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&INTERMEDIATE_MEMORY_MODEL);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV3Impulse5::~GPU_REWARDPV3Impulse5() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV3Impulse5::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV3Impulse5::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV3Impulse5;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV3::GPU_REWARDPV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0};
  double stoppts[1]={end};
  Initialize("intermediate_memory_write",(RewardType)1,1, startpts, stoppts, timeindex, 6,0, 0);
  AddImpulse("WRITE_TO_case1","RESULT_MEMORY_MODEL",&Impulse0);
  AddImpulseModelDependency("INTERMEDIATE_MEMORY_MODEL",&Impulse0);
  AddImpulse("WRITE_TO_case3","RESULT_MEMORY_MODEL",&Impulse1);
  AddImpulseModelDependency("INTERMEDIATE_MEMORY_MODEL",&Impulse1);
  AddImpulse("WRITE_TO_case2","RESULT_MEMORY_MODEL",&Impulse2);
  AddImpulseModelDependency("INTERMEDIATE_MEMORY_MODEL",&Impulse2);
  AddImpulse("WRITE_TO_case1","INTERMEDIATE_MEMORY_MODEL",&Impulse3);
  AddImpulse("WRITE_TO_case2","INTERMEDIATE_MEMORY_MODEL",&Impulse4);
  AddImpulse("WRITE_TO_case3","INTERMEDIATE_MEMORY_MODEL",&Impulse5);
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
  NumberOfModelDependencies = 2;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[1] = (BaseModelClass**)(&FINAL_MEMORY_MODEL);
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
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&FINAL_MEMORY_MODEL);
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

GPU_REWARDPV4::GPU_REWARDPV4(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0};
  double stoppts[1]={end};
  Initialize("final_memory_write",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("WRITE_TO","OUTPUT_MEMORY_MODEL",&Impulse0);
  AddImpulseModelDependency("FINAL_MEMORY_MODEL",&Impulse0);
  AddImpulse("WRITE_TO","FINAL_MEMORY_MODEL",&Impulse1);
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
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
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

GPU_REWARDPV5Impulse1::GPU_REWARDPV5Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV5Impulse1::~GPU_REWARDPV5Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV5Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV5Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV5Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV5::GPU_REWARDPV5(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0};
  double stoppts[1]={end};
  Initialize("alu_ops",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("COMPUTE_WITH_KO_DATA","COMPUTE_UNIT",&Impulse0);
  AddImpulse("COMPUTE_WITH_OK_DATA","COMPUTE_UNIT",&Impulse1);
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
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
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

GPU_REWARDPV6Impulse1::GPU_REWARDPV6Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU_REWARDPV6Impulse1::~GPU_REWARDPV6Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_REWARDPV6Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_REWARDPV6Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_REWARDPV6Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_REWARDPV6::GPU_REWARDPV6(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("dram_reads",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case1","DRAM",&Impulse0);
  AddImpulse("READ_FROM_case2","DRAM",&Impulse1);
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
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
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
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
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
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("l2_reads",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case1","L2_CACHE",&Impulse0);
  AddImpulse("READ_FROM_case2","L2_CACHE",&Impulse1);
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
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
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
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
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
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("l1_reads",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case1","L1_CACHE",&Impulse0);
  AddImpulse("READ_FROM_case2","L1_CACHE",&Impulse1);
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
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
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
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
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
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("consts",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("GETTING_CONST_VAL_case1","COMPUTE_UNIT",&Impulse0);
  AddImpulse("GETTING_CONST_VAL_case2","COMPUTE_UNIT",&Impulse1);
}

GPU_REWARDPV9::~GPU_REWARDPV9() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_REWARDPV9::CreateWorkerList(void) {
}
