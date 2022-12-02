#include "GPU_AVERAGEPVNodes.h"

GPU_AVERAGEPV0Impulse0::GPU_AVERAGEPV0Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP_AVERAGE);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV0Impulse0::~GPU_AVERAGEPV0Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV0Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV0Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV0Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV0::GPU_AVERAGEPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_AVERAGERJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("inst_act4",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("Instantaneous_Activity4","WARP_AVERAGE",&Impulse0);
}

GPU_AVERAGEPV0::~GPU_AVERAGEPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_AVERAGEPV0::CreateWorkerList(void) {
}
GPU_AVERAGEPV1Impulse0::GPU_AVERAGEPV1Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&LOCAL_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV1Impulse0::~GPU_AVERAGEPV1Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV1Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV1Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV1Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV1Impulse1::GPU_AVERAGEPV1Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&LOCAL_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV1Impulse1::~GPU_AVERAGEPV1Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV1Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV1Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV1Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV1Impulse2::GPU_AVERAGEPV1Impulse2()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&LOCAL_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV1Impulse2::~GPU_AVERAGEPV1Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV1Impulse2::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV1Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV1Impulse2;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV1Impulse3::GPU_AVERAGEPV1Impulse3()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&LOCAL_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV1Impulse3::~GPU_AVERAGEPV1Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV1Impulse3::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV1Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV1Impulse3;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV1Impulse4::GPU_AVERAGEPV1Impulse4()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&LOCAL_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV1Impulse4::~GPU_AVERAGEPV1Impulse4() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV1Impulse4::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV1Impulse4::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV1Impulse4;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV1Impulse5::GPU_AVERAGEPV1Impulse5()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&LOCAL_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV1Impulse5::~GPU_AVERAGEPV1Impulse5() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV1Impulse5::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV1Impulse5::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV1Impulse5;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV1::GPU_AVERAGEPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_AVERAGERJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("l_mem",(RewardType)1,1, startpts, stoppts, timeindex, 6,0, 0);
  AddImpulse("WRITE_TO_case1","LOCAL_MEMORY",&Impulse0);
  AddImpulse("WRITE_TO_case2","LOCAL_MEMORY",&Impulse1);
  AddImpulse("WRITE_TO_case3","LOCAL_MEMORY",&Impulse2);
  AddImpulse("READ_FROM_case1","LOCAL_MEMORY",&Impulse3);
  AddImpulse("READ_FROM_case2","LOCAL_MEMORY",&Impulse4);
  AddImpulse("READ_FROM_case3","LOCAL_MEMORY",&Impulse5);
}

GPU_AVERAGEPV1::~GPU_AVERAGEPV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_AVERAGEPV1::CreateWorkerList(void) {
}
GPU_AVERAGEPV2Impulse0::GPU_AVERAGEPV2Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GLOBAL_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV2Impulse0::~GPU_AVERAGEPV2Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV2Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV2Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV2Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV2Impulse1::GPU_AVERAGEPV2Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GLOBAL_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV2Impulse1::~GPU_AVERAGEPV2Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV2Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV2Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV2Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV2Impulse2::GPU_AVERAGEPV2Impulse2()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GLOBAL_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV2Impulse2::~GPU_AVERAGEPV2Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV2Impulse2::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV2Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV2Impulse2;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV2Impulse3::GPU_AVERAGEPV2Impulse3()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GLOBAL_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV2Impulse3::~GPU_AVERAGEPV2Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV2Impulse3::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV2Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV2Impulse3;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV2Impulse4::GPU_AVERAGEPV2Impulse4()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GLOBAL_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV2Impulse4::~GPU_AVERAGEPV2Impulse4() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV2Impulse4::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV2Impulse4::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV2Impulse4;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV2Impulse5::GPU_AVERAGEPV2Impulse5()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&GLOBAL_MEMORY);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV2Impulse5::~GPU_AVERAGEPV2Impulse5() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV2Impulse5::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV2Impulse5::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV2Impulse5;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV2::GPU_AVERAGEPV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_AVERAGERJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("g_mem",(RewardType)1,1, startpts, stoppts, timeindex, 6,0, 0);
  AddImpulse("READ_FROM_case1","GLOBAL_MEMORY",&Impulse0);
  AddImpulse("READ_FROM_case2","GLOBAL_MEMORY",&Impulse1);
  AddImpulse("READ_FROM_case3","GLOBAL_MEMORY",&Impulse2);
  AddImpulse("WRITE_TO_case3","GLOBAL_MEMORY",&Impulse3);
  AddImpulse("WRITE_TO_case2","GLOBAL_MEMORY",&Impulse4);
  AddImpulse("WRITE_TO_case1","GLOBAL_MEMORY",&Impulse5);
}

GPU_AVERAGEPV2::~GPU_AVERAGEPV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_AVERAGEPV2::CreateWorkerList(void) {
}
GPU_AVERAGEPV3Impulse0::GPU_AVERAGEPV3Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV3Impulse0::~GPU_AVERAGEPV3Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV3Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV3Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV3Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV3Impulse1::GPU_AVERAGEPV3Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV3Impulse1::~GPU_AVERAGEPV3Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV3Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV3Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV3Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV3::GPU_AVERAGEPV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_AVERAGERJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("alu",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("COMPUTE_WITH_KO_DATA","COMPUTE_UNIT",&Impulse0);
  AddImpulse("COMPUTE_WITH_OK_DATA","COMPUTE_UNIT",&Impulse1);
}

GPU_AVERAGEPV3::~GPU_AVERAGEPV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_AVERAGEPV3::CreateWorkerList(void) {
}
GPU_AVERAGEPV4Impulse0::GPU_AVERAGEPV4Impulse0()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV4Impulse0::~GPU_AVERAGEPV4Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV4Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV4Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV4Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV4Impulse1::GPU_AVERAGEPV4Impulse1()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV4Impulse1::~GPU_AVERAGEPV4Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV4Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV4Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV4Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV4Impulse2::GPU_AVERAGEPV4Impulse2()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV4Impulse2::~GPU_AVERAGEPV4Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV4Impulse2::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV4Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV4Impulse2;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV4Impulse3::GPU_AVERAGEPV4Impulse3()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV4Impulse3::~GPU_AVERAGEPV4Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV4Impulse3::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV4Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV4Impulse3;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV4Impulse4::GPU_AVERAGEPV4Impulse4()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV4Impulse4::~GPU_AVERAGEPV4Impulse4() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV4Impulse4::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV4Impulse4::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV4Impulse4;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV4Impulse5::GPU_AVERAGEPV4Impulse5()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV4Impulse5::~GPU_AVERAGEPV4Impulse5() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV4Impulse5::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV4Impulse5::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV4Impulse5;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV4Impulse6::GPU_AVERAGEPV4Impulse6()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV4Impulse6::~GPU_AVERAGEPV4Impulse6() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV4Impulse6::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV4Impulse6::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV4Impulse6;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV4Impulse7::GPU_AVERAGEPV4Impulse7()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
  TheModelPtr[1] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&DRAM);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV4Impulse7::~GPU_AVERAGEPV4Impulse7() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV4Impulse7::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV4Impulse7::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV4Impulse7;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV4Impulse8::GPU_AVERAGEPV4Impulse8()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  TheModelPtr[1] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV4Impulse8::~GPU_AVERAGEPV4Impulse8() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV4Impulse8::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV4Impulse8::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV4Impulse8;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV4Impulse9::GPU_AVERAGEPV4Impulse9()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  TheModelPtr[1] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV4Impulse9::~GPU_AVERAGEPV4Impulse9() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV4Impulse9::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV4Impulse9::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV4Impulse9;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV4Impulse10::GPU_AVERAGEPV4Impulse10()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  TheModelPtr[1] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV4Impulse10::~GPU_AVERAGEPV4Impulse10() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV4Impulse10::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV4Impulse10::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV4Impulse10;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV4Impulse11::GPU_AVERAGEPV4Impulse11()
{
  NumberOfModelDependencies = 3;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&DRAM);
  TheModelPtr[1] = (BaseModelClass**)(&L1_CACHE);
  TheModelPtr[2] = (BaseModelClass**)(&L2_CACHE);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV4Impulse11::~GPU_AVERAGEPV4Impulse11() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV4Impulse11::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV4Impulse11::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV4Impulse11;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV4::GPU_AVERAGEPV4(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_AVERAGERJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("mem_op",(RewardType)1,1, startpts, stoppts, timeindex, 12,0, 0);
  AddImpulse("WRITE_WITH_KO_DATA","L1_CACHE",&Impulse0);
  AddImpulseModelDependency("L2_CACHE",&Impulse0);
  AddImpulseModelDependency("DRAM",&Impulse0);
  AddImpulse("WRITE_WITH_OK_DATA","L1_CACHE",&Impulse1);
  AddImpulseModelDependency("L2_CACHE",&Impulse1);
  AddImpulseModelDependency("DRAM",&Impulse1);
  AddImpulse("READ_FROM_case1","L1_CACHE",&Impulse2);
  AddImpulseModelDependency("L2_CACHE",&Impulse2);
  AddImpulseModelDependency("DRAM",&Impulse2);
  AddImpulse("READ_FROM_case2","L1_CACHE",&Impulse3);
  AddImpulseModelDependency("L2_CACHE",&Impulse3);
  AddImpulseModelDependency("DRAM",&Impulse3);
  AddImpulse("WRITE_WITH_KO_DATA","L2_CACHE",&Impulse4);
  AddImpulseModelDependency("L1_CACHE",&Impulse4);
  AddImpulseModelDependency("DRAM",&Impulse4);
  AddImpulse("WRITE_WITH_OK_DATA","L2_CACHE",&Impulse5);
  AddImpulseModelDependency("L1_CACHE",&Impulse5);
  AddImpulseModelDependency("DRAM",&Impulse5);
  AddImpulse("READ_FROM_case1","L2_CACHE",&Impulse6);
  AddImpulseModelDependency("L1_CACHE",&Impulse6);
  AddImpulseModelDependency("DRAM",&Impulse6);
  AddImpulse("READ_FROM_case2","L2_CACHE",&Impulse7);
  AddImpulseModelDependency("L1_CACHE",&Impulse7);
  AddImpulseModelDependency("DRAM",&Impulse7);
  AddImpulse("WRITE_WITH_KO_DATA","DRAM",&Impulse8);
  AddImpulseModelDependency("L1_CACHE",&Impulse8);
  AddImpulseModelDependency("L2_CACHE",&Impulse8);
  AddImpulse("WRITE_WITH_OK_DATA","DRAM",&Impulse9);
  AddImpulseModelDependency("L1_CACHE",&Impulse9);
  AddImpulseModelDependency("L2_CACHE",&Impulse9);
  AddImpulse("READ_FROM_case1","DRAM",&Impulse10);
  AddImpulseModelDependency("L1_CACHE",&Impulse10);
  AddImpulseModelDependency("L2_CACHE",&Impulse10);
  AddImpulse("READ_FROM_case2","DRAM",&Impulse11);
  AddImpulseModelDependency("L1_CACHE",&Impulse11);
  AddImpulseModelDependency("L2_CACHE",&Impulse11);
}

GPU_AVERAGEPV4::~GPU_AVERAGEPV4() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_AVERAGEPV4::CreateWorkerList(void) {
}
GPU_AVERAGEPV5Impulse0::GPU_AVERAGEPV5Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP_AVERAGE);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV5Impulse0::~GPU_AVERAGEPV5Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV5Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV5Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV5Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV5::GPU_AVERAGEPV5(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_AVERAGERJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("dispatch_warp_side",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("DISPATCHER_Copy_Copy","WARP_AVERAGE",&Impulse0);
}

GPU_AVERAGEPV5::~GPU_AVERAGEPV5() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_AVERAGEPV5::CreateWorkerList(void) {
}
GPU_AVERAGEPV6Impulse0::GPU_AVERAGEPV6Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV6Impulse0::~GPU_AVERAGEPV6Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV6Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV6Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV6Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV6::GPU_AVERAGEPV6(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_AVERAGERJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("dispatch_compute_unit_side",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("DISPATCHER","COMPUTE_UNIT",&Impulse0);
}

GPU_AVERAGEPV6::~GPU_AVERAGEPV6() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_AVERAGEPV6::CreateWorkerList(void) {
}
GPU_AVERAGEPV7Impulse0::GPU_AVERAGEPV7Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV7Impulse0::~GPU_AVERAGEPV7Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV7Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV7Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV7Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV7Impulse1::GPU_AVERAGEPV7Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV7Impulse1::~GPU_AVERAGEPV7Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV7Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV7Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV7Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV7::GPU_AVERAGEPV7(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_AVERAGERJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("alu_no_data",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("Instantaneous_Activity2_case1","COMPUTE_UNIT",&Impulse0);
  AddImpulse("Instantaneous_Activity2_case2","COMPUTE_UNIT",&Impulse1);
}

GPU_AVERAGEPV7::~GPU_AVERAGEPV7() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_AVERAGEPV7::CreateWorkerList(void) {
}
GPU_AVERAGEPV8Impulse0::GPU_AVERAGEPV8Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV8Impulse0::~GPU_AVERAGEPV8Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV8Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV8Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV8Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV8::GPU_AVERAGEPV8(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_AVERAGERJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("l_mem_complete",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("Instantaneous_Activity1","COMPUTE_UNIT",&Impulse0);
}

GPU_AVERAGEPV8::~GPU_AVERAGEPV8() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_AVERAGEPV8::CreateWorkerList(void) {
}
GPU_AVERAGEPV9Impulse0::GPU_AVERAGEPV9Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV9Impulse0::~GPU_AVERAGEPV9Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV9Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV9Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV9Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV9Impulse1::GPU_AVERAGEPV9Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&COMPUTE_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU_AVERAGEPV9Impulse1::~GPU_AVERAGEPV9Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_AVERAGEPV9Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_AVERAGEPV9Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_AVERAGEPV9Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_AVERAGEPV9::GPU_AVERAGEPV9(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_AVERAGERJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("alu_complete",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("Instantaneous_Activity2_case1","COMPUTE_UNIT",&Impulse0);
  AddImpulse("Instantaneous_Activity2_case2","COMPUTE_UNIT",&Impulse1);
}

GPU_AVERAGEPV9::~GPU_AVERAGEPV9() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_AVERAGEPV9::CreateWorkerList(void) {
}
