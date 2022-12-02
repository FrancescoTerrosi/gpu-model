#include "GPU3_REWARDPVNodes.h"

GPU3_REWARDPV0Impulse0::GPU3_REWARDPV0Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV0Impulse0::~GPU3_REWARDPV0Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV0Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV0Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV0Impulse0;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV0::GPU3_REWARDPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU3RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("dispatcher",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("DISPATCHER","COMPUTE_UNIT",&Impulse0);
}

GPU3_REWARDPV0::~GPU3_REWARDPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU3_REWARDPV0::CreateWorkerList(void) {
}
GPU3_REWARDPV1Impulse0::GPU3_REWARDPV1Impulse0()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&GLOBAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV1Impulse0::~GPU3_REWARDPV1Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV1Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV1Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV1Impulse0;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV1Impulse1::GPU3_REWARDPV1Impulse1()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&GLOBAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV1Impulse1::~GPU3_REWARDPV1Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV1Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV1Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV1Impulse1;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV1Impulse2::GPU3_REWARDPV1Impulse2()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&GLOBAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV1Impulse2::~GPU3_REWARDPV1Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV1Impulse2::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV1Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV1Impulse2;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV1Impulse3::GPU3_REWARDPV1Impulse3()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GLOBAL_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV1Impulse3::~GPU3_REWARDPV1Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV1Impulse3::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV1Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV1Impulse3;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV1Impulse4::GPU3_REWARDPV1Impulse4()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GLOBAL_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV1Impulse4::~GPU3_REWARDPV1Impulse4() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV1Impulse4::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV1Impulse4::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV1Impulse4;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV1Impulse5::GPU3_REWARDPV1Impulse5()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GLOBAL_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV1Impulse5::~GPU3_REWARDPV1Impulse5() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV1Impulse5::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV1Impulse5::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV1Impulse5;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV1Impulse6::GPU3_REWARDPV1Impulse6()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[1] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&GLOBAL_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV1Impulse6::~GPU3_REWARDPV1Impulse6() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV1Impulse6::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV1Impulse6::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV1Impulse6;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV1Impulse7::GPU3_REWARDPV1Impulse7()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[1] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&GLOBAL_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV1Impulse7::~GPU3_REWARDPV1Impulse7() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV1Impulse7::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV1Impulse7::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV1Impulse7;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV1::GPU3_REWARDPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU3RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("reads",(RewardType)1,1, startpts, stoppts, timeindex, 8,0, 0);
  AddImpulse("READ_FROM_case1","LOCAL_MEMORY",&Impulse0);
  AddImpulseModelDependency("GLOBAL_MEMORY",&Impulse0);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse0);
  AddImpulse("READ_FROM_case2","LOCAL_MEMORY",&Impulse1);
  AddImpulseModelDependency("GLOBAL_MEMORY",&Impulse1);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse1);
  AddImpulse("READ_FROM_case3","LOCAL_MEMORY",&Impulse2);
  AddImpulseModelDependency("GLOBAL_MEMORY",&Impulse2);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse2);
  AddImpulse("READ_FROM_case1","GLOBAL_MEMORY",&Impulse3);
  AddImpulseModelDependency("LOCAL_MEMORY",&Impulse3);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse3);
  AddImpulse("READ_FROM_case2","GLOBAL_MEMORY",&Impulse4);
  AddImpulseModelDependency("LOCAL_MEMORY",&Impulse4);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse4);
  AddImpulse("READ_FROM_case3","GLOBAL_MEMORY",&Impulse5);
  AddImpulseModelDependency("LOCAL_MEMORY",&Impulse5);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse5);
  AddImpulse("READ_FROM_case1","REGISTER_FILE",&Impulse6);
  AddImpulseModelDependency("LOCAL_MEMORY",&Impulse6);
  AddImpulseModelDependency("GLOBAL_MEMORY",&Impulse6);
  AddImpulse("READ_FROM_case2","REGISTER_FILE",&Impulse7);
  AddImpulseModelDependency("LOCAL_MEMORY",&Impulse7);
  AddImpulseModelDependency("GLOBAL_MEMORY",&Impulse7);
}

GPU3_REWARDPV1::~GPU3_REWARDPV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU3_REWARDPV1::CreateWorkerList(void) {
}
GPU3_REWARDPV2Impulse0::GPU3_REWARDPV2Impulse0()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&GLOBAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&OUTPUT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV2Impulse0::~GPU3_REWARDPV2Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV2Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV2Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV2Impulse0;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV2Impulse1::GPU3_REWARDPV2Impulse1()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&GLOBAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&OUTPUT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV2Impulse1::~GPU3_REWARDPV2Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV2Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV2Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV2Impulse1;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV2Impulse2::GPU3_REWARDPV2Impulse2()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&GLOBAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&OUTPUT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV2Impulse2::~GPU3_REWARDPV2Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV2Impulse2::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV2Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV2Impulse2;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV2Impulse3::GPU3_REWARDPV2Impulse3()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GLOBAL_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&OUTPUT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV2Impulse3::~GPU3_REWARDPV2Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV2Impulse3::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV2Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV2Impulse3;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV2Impulse4::GPU3_REWARDPV2Impulse4()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GLOBAL_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&OUTPUT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV2Impulse4::~GPU3_REWARDPV2Impulse4() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV2Impulse4::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV2Impulse4::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV2Impulse4;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV2Impulse5::GPU3_REWARDPV2Impulse5()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GLOBAL_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[3] = (BaseModelClass**)(&OUTPUT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV2Impulse5::~GPU3_REWARDPV2Impulse5() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV2Impulse5::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV2Impulse5::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV2Impulse5;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV2Impulse6::GPU3_REWARDPV2Impulse6()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[1] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&GLOBAL_MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&OUTPUT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV2Impulse6::~GPU3_REWARDPV2Impulse6() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV2Impulse6::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV2Impulse6::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV2Impulse6;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV2Impulse7::GPU3_REWARDPV2Impulse7()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&REGISTER_FILE);
  TheModelPtr[1] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&GLOBAL_MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&OUTPUT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV2Impulse7::~GPU3_REWARDPV2Impulse7() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV2Impulse7::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV2Impulse7::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV2Impulse7;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV2Impulse8::GPU3_REWARDPV2Impulse8()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&OUTPUT_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&LOCAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&GLOBAL_MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&REGISTER_FILE);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV2Impulse8::~GPU3_REWARDPV2Impulse8() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV2Impulse8::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV2Impulse8::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV2Impulse8;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV2::GPU3_REWARDPV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU3RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("writes",(RewardType)1,1, startpts, stoppts, timeindex, 9,0, 0);
  AddImpulse("WRITE_TO_case1","LOCAL_MEMORY",&Impulse0);
  AddImpulseModelDependency("GLOBAL_MEMORY",&Impulse0);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse0);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse0);
  AddImpulse("WRITE_TO_case2","LOCAL_MEMORY",&Impulse1);
  AddImpulseModelDependency("GLOBAL_MEMORY",&Impulse1);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse1);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse1);
  AddImpulse("WRITE_TO_case3","LOCAL_MEMORY",&Impulse2);
  AddImpulseModelDependency("GLOBAL_MEMORY",&Impulse2);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse2);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse2);
  AddImpulse("WRITE_TO_case1","GLOBAL_MEMORY",&Impulse3);
  AddImpulseModelDependency("LOCAL_MEMORY",&Impulse3);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse3);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse3);
  AddImpulse("WRITE_TO_case2","GLOBAL_MEMORY",&Impulse4);
  AddImpulseModelDependency("LOCAL_MEMORY",&Impulse4);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse4);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse4);
  AddImpulse("WRITE_TO_case3","GLOBAL_MEMORY",&Impulse5);
  AddImpulseModelDependency("LOCAL_MEMORY",&Impulse5);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse5);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse5);
  AddImpulse("WRITE_WITH_KO_DATA","REGISTER_FILE",&Impulse6);
  AddImpulseModelDependency("LOCAL_MEMORY",&Impulse6);
  AddImpulseModelDependency("GLOBAL_MEMORY",&Impulse6);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse6);
  AddImpulse("WRITE_WITH_OK_DATA","REGISTER_FILE",&Impulse7);
  AddImpulseModelDependency("LOCAL_MEMORY",&Impulse7);
  AddImpulseModelDependency("GLOBAL_MEMORY",&Impulse7);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse7);
  AddImpulse("WRITE_TO","OUTPUT_MEMORY",&Impulse8);
  AddImpulseModelDependency("LOCAL_MEMORY",&Impulse8);
  AddImpulseModelDependency("GLOBAL_MEMORY",&Impulse8);
  AddImpulseModelDependency("REGISTER_FILE",&Impulse8);
}

GPU3_REWARDPV2::~GPU3_REWARDPV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU3_REWARDPV2::CreateWorkerList(void) {
}
GPU3_REWARDPV3Impulse0::GPU3_REWARDPV3Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV3Impulse0::~GPU3_REWARDPV3Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV3Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV3Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV3Impulse0;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV3Impulse1::GPU3_REWARDPV3Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV3Impulse1::~GPU3_REWARDPV3Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV3Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV3Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV3Impulse1;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV3::GPU3_REWARDPV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU3RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("l1_reads",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case1","L1_CACHE",&Impulse0);
  AddImpulse("READ_FROM_case2","L1_CACHE",&Impulse1);
}

GPU3_REWARDPV3::~GPU3_REWARDPV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU3_REWARDPV3::CreateWorkerList(void) {
}
GPU3_REWARDPV4Impulse0::GPU3_REWARDPV4Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV4Impulse0::~GPU3_REWARDPV4Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV4Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV4Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV4Impulse0;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV4Impulse1::GPU3_REWARDPV4Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV4Impulse1::~GPU3_REWARDPV4Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV4Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV4Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV4Impulse1;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV4::GPU3_REWARDPV4(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU3RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("l1_writes",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("WRITE_WITH_OK_DATA","L1_CACHE",&Impulse0);
  AddImpulse("WRITE_WITH_KO_DATA","L1_CACHE",&Impulse1);
}

GPU3_REWARDPV4::~GPU3_REWARDPV4() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU3_REWARDPV4::CreateWorkerList(void) {
}
GPU3_REWARDPV5Impulse0::GPU3_REWARDPV5Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV5Impulse0::~GPU3_REWARDPV5Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV5Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV5Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV5Impulse0;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV5Impulse1::GPU3_REWARDPV5Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV5Impulse1::~GPU3_REWARDPV5Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV5Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV5Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV5Impulse1;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV5::GPU3_REWARDPV5(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU3RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("l2_reads",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case1","L2_CACHE",&Impulse0);
  AddImpulse("READ_FROM_case2","L2_CACHE",&Impulse1);
}

GPU3_REWARDPV5::~GPU3_REWARDPV5() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU3_REWARDPV5::CreateWorkerList(void) {
}
GPU3_REWARDPV6Impulse0::GPU3_REWARDPV6Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV6Impulse0::~GPU3_REWARDPV6Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV6Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV6Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV6Impulse0;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV6Impulse1::GPU3_REWARDPV6Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV6Impulse1::~GPU3_REWARDPV6Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV6Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV6Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV6Impulse1;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV6::GPU3_REWARDPV6(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU3RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("l2_writes",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("WRITE_WITH_OK_DATA","L2_CACHE",&Impulse0);
  AddImpulse("WRITE_WITH_KO_DATA","L2_CACHE",&Impulse1);
}

GPU3_REWARDPV6::~GPU3_REWARDPV6() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU3_REWARDPV6::CreateWorkerList(void) {
}
GPU3_REWARDPV7Impulse0::GPU3_REWARDPV7Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV7Impulse0::~GPU3_REWARDPV7Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV7Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV7Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV7Impulse0;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV7Impulse1::GPU3_REWARDPV7Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV7Impulse1::~GPU3_REWARDPV7Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV7Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV7Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV7Impulse1;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV7::GPU3_REWARDPV7(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU3RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("dram_reads",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("READ_FROM_case2","DRAM",&Impulse0);
  AddImpulse("READ_FROM_case1","DRAM",&Impulse1);
}

GPU3_REWARDPV7::~GPU3_REWARDPV7() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU3_REWARDPV7::CreateWorkerList(void) {
}
GPU3_REWARDPV8Impulse0::GPU3_REWARDPV8Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV8Impulse0::~GPU3_REWARDPV8Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV8Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV8Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV8Impulse0;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV8Impulse1::GPU3_REWARDPV8Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV8Impulse1::~GPU3_REWARDPV8Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV8Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV8Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV8Impulse1;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV8::GPU3_REWARDPV8(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU3RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("dram_writes",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("WRITE_WITH_KO_DATA","DRAM",&Impulse0);
  AddImpulse("WRITE_WITH_OK_DATA","DRAM",&Impulse1);
}

GPU3_REWARDPV8::~GPU3_REWARDPV8() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU3_REWARDPV8::CreateWorkerList(void) {
}
GPU3_REWARDPV9Impulse0::GPU3_REWARDPV9Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV9Impulse0::~GPU3_REWARDPV9Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV9Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV9Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV9Impulse0;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV9::GPU3_REWARDPV9(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU3RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("alus",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("COMPUTE_WITH_OK_DATA","COMPUTE_UNIT",&Impulse0);
}

GPU3_REWARDPV9::~GPU3_REWARDPV9() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU3_REWARDPV9::CreateWorkerList(void) {
}
GPU3_REWARDPV10::GPU3_REWARDPV10(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU3RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("schduler",(RewardType)1,1, startpts, stoppts, timeindex, 0,0, 0);
}

GPU3_REWARDPV10::~GPU3_REWARDPV10() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU3_REWARDPV10::CreateWorkerList(void) {
}
GPU3_REWARDPV11Impulse0::GPU3_REWARDPV11Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP3);
  ImpulseWorkerListLength = 0;
}

GPU3_REWARDPV11Impulse0::~GPU3_REWARDPV11Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU3_REWARDPV11Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU3_REWARDPV11Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU3_REWARDPV11Impulse0;
  }

  return ImpulseWorkerList;
}

GPU3_REWARDPV11::GPU3_REWARDPV11(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU3RJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("warp",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("DISPATCHER_Copy","WARP3",&Impulse0);
}

GPU3_REWARDPV11::~GPU3_REWARDPV11() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU3_REWARDPV11::CreateWorkerList(void) {
}
