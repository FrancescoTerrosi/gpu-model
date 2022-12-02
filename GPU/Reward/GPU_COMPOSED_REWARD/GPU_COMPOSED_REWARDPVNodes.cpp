#include "GPU_COMPOSED_REWARDPVNodes.h"

GPU_COMPOSED_REWARDPV0Impulse0::GPU_COMPOSED_REWARDPV0Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_REWARDPV0Impulse0::~GPU_COMPOSED_REWARDPV0Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_REWARDPV0Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_REWARDPV0Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_REWARDPV0Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_REWARDPV0::GPU_COMPOSED_REWARDPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("scheduling",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("DISPATCHER","COMPUTE_UNIT",&Impulse0);
}

GPU_COMPOSED_REWARDPV0::~GPU_COMPOSED_REWARDPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_REWARDPV0::CreateWorkerList(void) {
}
GPU_COMPOSED_REWARDPV1Impulse0::GPU_COMPOSED_REWARDPV1Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&RESULT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_REWARDPV1Impulse0::~GPU_COMPOSED_REWARDPV1Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_REWARDPV1Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_REWARDPV1Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_REWARDPV1Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_REWARDPV1::GPU_COMPOSED_REWARDPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("write_ok",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("WRITE_OK","RESULT_MEMORY",&Impulse0);
}

GPU_COMPOSED_REWARDPV1::~GPU_COMPOSED_REWARDPV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_REWARDPV1::CreateWorkerList(void) {
}
GPU_COMPOSED_REWARDPV2Impulse0::GPU_COMPOSED_REWARDPV2Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&RESULT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_REWARDPV2Impulse0::~GPU_COMPOSED_REWARDPV2Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_REWARDPV2Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_REWARDPV2Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_REWARDPV2Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_REWARDPV2::GPU_COMPOSED_REWARDPV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("write_ko",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("WRITE_KO","RESULT_MEMORY",&Impulse0);
}

GPU_COMPOSED_REWARDPV2::~GPU_COMPOSED_REWARDPV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_REWARDPV2::CreateWorkerList(void) {
}
GPU_COMPOSED_REWARDPV3Impulse0::GPU_COMPOSED_REWARDPV3Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_REWARDPV3Impulse0::~GPU_COMPOSED_REWARDPV3Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_REWARDPV3Impulse0::Impulse_Function(double FiringTime)
{
return 2;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_REWARDPV3Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_REWARDPV3Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_REWARDPV3::GPU_COMPOSED_REWARDPV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("compute_ok",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("COMPUTE_WITH_OK_DATA","COMPUTE_UNIT",&Impulse0);
}

GPU_COMPOSED_REWARDPV3::~GPU_COMPOSED_REWARDPV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_REWARDPV3::CreateWorkerList(void) {
}
GPU_COMPOSED_REWARDPV4Impulse0::GPU_COMPOSED_REWARDPV4Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_REWARDPV4Impulse0::~GPU_COMPOSED_REWARDPV4Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_REWARDPV4Impulse0::Impulse_Function(double FiringTime)
{


return(0);
}

ImpulseNodeClass** GPU_COMPOSED_REWARDPV4Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_REWARDPV4Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_REWARDPV4::GPU_COMPOSED_REWARDPV4(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("compute_ko",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("COMPUTE_WITH_KO_DATA","COMPUTE_UNIT",&Impulse0);
}

GPU_COMPOSED_REWARDPV4::~GPU_COMPOSED_REWARDPV4() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_REWARDPV4::CreateWorkerList(void) {
}
GPU_COMPOSED_REWARDPV5Impulse0::GPU_COMPOSED_REWARDPV5Impulse0()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[1] = (BaseModelClass**)(&TOTAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&OUTPUT_MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&RESULT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_REWARDPV5Impulse0::~GPU_COMPOSED_REWARDPV5Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_REWARDPV5Impulse0::Impulse_Function(double FiringTime)
{
return 2;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_REWARDPV5Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_REWARDPV5Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_REWARDPV5Impulse1::GPU_COMPOSED_REWARDPV5Impulse1()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&RESULT_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&TOTAL_MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&OUTPUT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_REWARDPV5Impulse1::~GPU_COMPOSED_REWARDPV5Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_REWARDPV5Impulse1::Impulse_Function(double FiringTime)
{
return 32;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_REWARDPV5Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_REWARDPV5Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_REWARDPV5Impulse2::GPU_COMPOSED_REWARDPV5Impulse2()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&OUTPUT_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&TOTAL_MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&RESULT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_REWARDPV5Impulse2::~GPU_COMPOSED_REWARDPV5Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_REWARDPV5Impulse2::Impulse_Function(double FiringTime)
{
return 360;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_REWARDPV5Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_REWARDPV5Impulse2;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_REWARDPV5Impulse3::GPU_COMPOSED_REWARDPV5Impulse3()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&TOTAL_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&OUTPUT_MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&RESULT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_REWARDPV5Impulse3::~GPU_COMPOSED_REWARDPV5Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_REWARDPV5Impulse3::Impulse_Function(double FiringTime)
{
return 64;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_REWARDPV5Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_REWARDPV5Impulse3;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_REWARDPV5Impulse4::GPU_COMPOSED_REWARDPV5Impulse4()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&RESULT_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&TOTAL_MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&OUTPUT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_REWARDPV5Impulse4::~GPU_COMPOSED_REWARDPV5Impulse4() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_REWARDPV5Impulse4::Impulse_Function(double FiringTime)
{
return 32;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_REWARDPV5Impulse4::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_REWARDPV5Impulse4;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_REWARDPV5Impulse5::GPU_COMPOSED_REWARDPV5Impulse5()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&RESULT_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&TOTAL_MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&OUTPUT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_REWARDPV5Impulse5::~GPU_COMPOSED_REWARDPV5Impulse5() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_REWARDPV5Impulse5::Impulse_Function(double FiringTime)
{
return 32;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_REWARDPV5Impulse5::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_REWARDPV5Impulse5;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_REWARDPV5Impulse6::GPU_COMPOSED_REWARDPV5Impulse6()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&TOTAL_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&OUTPUT_MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&RESULT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_REWARDPV5Impulse6::~GPU_COMPOSED_REWARDPV5Impulse6() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_REWARDPV5Impulse6::Impulse_Function(double FiringTime)
{
return 64;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_REWARDPV5Impulse6::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_REWARDPV5Impulse6;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_REWARDPV5Impulse7::GPU_COMPOSED_REWARDPV5Impulse7()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&OUTPUT_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&TOTAL_MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&RESULT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_REWARDPV5Impulse7::~GPU_COMPOSED_REWARDPV5Impulse7() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_REWARDPV5Impulse7::Impulse_Function(double FiringTime)
{
return 360;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_REWARDPV5Impulse7::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_REWARDPV5Impulse7;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_REWARDPV5Impulse8::GPU_COMPOSED_REWARDPV5Impulse8()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[1] = (BaseModelClass**)(&TOTAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&OUTPUT_MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&RESULT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_REWARDPV5Impulse8::~GPU_COMPOSED_REWARDPV5Impulse8() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_REWARDPV5Impulse8::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_REWARDPV5Impulse8::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_REWARDPV5Impulse8;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_REWARDPV5Impulse9::GPU_COMPOSED_REWARDPV5Impulse9()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[1] = (BaseModelClass**)(&TOTAL_MEMORY);
  TheModelPtr[2] = (BaseModelClass**)(&OUTPUT_MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&RESULT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_REWARDPV5Impulse9::~GPU_COMPOSED_REWARDPV5Impulse9() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_REWARDPV5Impulse9::Impulse_Function(double FiringTime)
{
return 2;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_REWARDPV5Impulse9::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_REWARDPV5Impulse9;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_REWARDPV5Impulse10::GPU_COMPOSED_REWARDPV5Impulse10()
{
  NumberOfModelDependencies = 4;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&RESULT_MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&COMPUTE_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&TOTAL_MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&OUTPUT_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_COMPOSED_REWARDPV5Impulse10::~GPU_COMPOSED_REWARDPV5Impulse10() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_COMPOSED_REWARDPV5Impulse10::Impulse_Function(double FiringTime)
{
return 32;

return(0);
}

ImpulseNodeClass** GPU_COMPOSED_REWARDPV5Impulse10::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_COMPOSED_REWARDPV5Impulse10;
  }

  return ImpulseWorkerList;
}

GPU_COMPOSED_REWARDPV5::GPU_COMPOSED_REWARDPV5(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPURJ);
  double startpts[1]={0.0};
  double stoppts[1]={1.0};
  Initialize("clock_steps",(RewardType)1,1, startpts, stoppts, timeindex, 11,0, 0);
  AddImpulse("COMPUTE_WITH_OK_DATA","COMPUTE_UNIT",&Impulse0);
  AddImpulseModelDependency("TOTAL_MEMORY",&Impulse0);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse0);
  AddImpulseModelDependency("RESULT_MEMORY",&Impulse0);
  AddImpulse("READ_FROM_case2","RESULT_MEMORY",&Impulse1);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse1);
  AddImpulseModelDependency("TOTAL_MEMORY",&Impulse1);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse1);
  AddImpulse("WRITE_TO_case2","OUTPUT_MEMORY",&Impulse2);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse2);
  AddImpulseModelDependency("TOTAL_MEMORY",&Impulse2);
  AddImpulseModelDependency("RESULT_MEMORY",&Impulse2);
  AddImpulse("READ_FROM_case2","TOTAL_MEMORY",&Impulse3);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse3);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse3);
  AddImpulseModelDependency("RESULT_MEMORY",&Impulse3);
  AddImpulse("READ_FROM_case1","RESULT_MEMORY",&Impulse4);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse4);
  AddImpulseModelDependency("TOTAL_MEMORY",&Impulse4);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse4);
  AddImpulse("WRITE_OK","RESULT_MEMORY",&Impulse5);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse5);
  AddImpulseModelDependency("TOTAL_MEMORY",&Impulse5);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse5);
  AddImpulse("READ_FROM_case1","TOTAL_MEMORY",&Impulse6);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse6);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse6);
  AddImpulseModelDependency("RESULT_MEMORY",&Impulse6);
  AddImpulse("WRITE_TO_case1","OUTPUT_MEMORY",&Impulse7);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse7);
  AddImpulseModelDependency("TOTAL_MEMORY",&Impulse7);
  AddImpulseModelDependency("RESULT_MEMORY",&Impulse7);
  AddImpulse("DISPATCHER","COMPUTE_UNIT",&Impulse8);
  AddImpulseModelDependency("TOTAL_MEMORY",&Impulse8);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse8);
  AddImpulseModelDependency("RESULT_MEMORY",&Impulse8);
  AddImpulse("COMPUTE_WITH_KO_DATA","COMPUTE_UNIT",&Impulse9);
  AddImpulseModelDependency("TOTAL_MEMORY",&Impulse9);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse9);
  AddImpulseModelDependency("RESULT_MEMORY",&Impulse9);
  AddImpulse("WRITE_KO","RESULT_MEMORY",&Impulse10);
  AddImpulseModelDependency("COMPUTE_UNIT",&Impulse10);
  AddImpulseModelDependency("TOTAL_MEMORY",&Impulse10);
  AddImpulseModelDependency("OUTPUT_MEMORY",&Impulse10);
}

GPU_COMPOSED_REWARDPV5::~GPU_COMPOSED_REWARDPV5() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_COMPOSED_REWARDPV5::CreateWorkerList(void) {
}
