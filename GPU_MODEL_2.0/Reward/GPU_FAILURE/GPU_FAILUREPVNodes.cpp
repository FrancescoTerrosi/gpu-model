#include "GPU_FAILUREPVNodes.h"

GPU_FAILUREPV0Impulse0::GPU_FAILUREPV0Impulse0()
{
  NumberOfModelDependencies = 2;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  TheModelPtr[1] = (BaseModelClass**)(&WARP_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV0Impulse0::~GPU_FAILUREPV0Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV0Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV0Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV0Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV0Impulse1::GPU_FAILUREPV0Impulse1()
{
  NumberOfModelDependencies = 2;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV0Impulse1::~GPU_FAILUREPV0Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV0Impulse1::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV0Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV0Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV0::GPU_FAILUREPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_FAILURERJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("warp",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("DISPATCHER_Copy","WARP",&Impulse0);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse0);
  AddImpulse("DISPATCHER_Copy","WARP_FAILURE",&Impulse1);
  AddImpulseModelDependency("WARP",&Impulse1);
}

GPU_FAILUREPV0::~GPU_FAILUREPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_FAILUREPV0::CreateWorkerList(void) {
}
GPU_FAILUREPV1Impulse0::GPU_FAILUREPV1Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&EXEC_UNIT);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV1Impulse0::~GPU_FAILUREPV1Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV1Impulse0::Impulse_Function(double FiringTime)
{
return 1;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV1Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV1Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV1::GPU_FAILUREPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_FAILURERJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("exec",(RewardType)1,1, startpts, stoppts, timeindex, 1,0, 0);
  AddImpulse("DISPATCHER","EXEC_UNIT",&Impulse0);
}

GPU_FAILUREPV1::~GPU_FAILUREPV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_FAILUREPV1::CreateWorkerList(void) {
}
GPU_FAILUREPV2Impulse0::GPU_FAILUREPV2Impulse0()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP);
  TheModelPtr[1] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[2] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[4] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse0::~GPU_FAILUREPV2Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse0::Impulse_Function(double FiringTime)
{
return 2;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse0;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse1::GPU_FAILUREPV2Impulse1()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[4] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse1::~GPU_FAILUREPV2Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse1::Impulse_Function(double FiringTime)
{
return 2;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse1;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse2::GPU_FAILUREPV2Impulse2()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[3] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[4] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse2::~GPU_FAILUREPV2Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse2::Impulse_Function(double FiringTime)
{
return 2;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse2;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse3::GPU_FAILUREPV2Impulse3()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[4] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse3::~GPU_FAILUREPV2Impulse3() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse3::Impulse_Function(double FiringTime)
{
return 2;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse3::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse3;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse4::GPU_FAILUREPV2Impulse4()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[4] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse4::~GPU_FAILUREPV2Impulse4() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse4::Impulse_Function(double FiringTime)
{
return 30;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse4::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse4;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse5::GPU_FAILUREPV2Impulse5()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[4] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse5::~GPU_FAILUREPV2Impulse5() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse5::Impulse_Function(double FiringTime)
{
return 400;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse5::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse5;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse6::GPU_FAILUREPV2Impulse6()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[4] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse6::~GPU_FAILUREPV2Impulse6() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse6::Impulse_Function(double FiringTime)
{
return 600;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse6::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse6;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse7::GPU_FAILUREPV2Impulse7()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[4] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse7::~GPU_FAILUREPV2Impulse7() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse7::Impulse_Function(double FiringTime)
{
return 30;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse7::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse7;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse8::GPU_FAILUREPV2Impulse8()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[4] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse8::~GPU_FAILUREPV2Impulse8() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse8::Impulse_Function(double FiringTime)
{
return 400;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse8::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse8;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse9::GPU_FAILUREPV2Impulse9()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[4] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse9::~GPU_FAILUREPV2Impulse9() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse9::Impulse_Function(double FiringTime)
{
return 600;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse9::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse9;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse10::GPU_FAILUREPV2Impulse10()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[4] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse10::~GPU_FAILUREPV2Impulse10() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse10::Impulse_Function(double FiringTime)
{
return 30;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse10::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse10;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse11::GPU_FAILUREPV2Impulse11()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[4] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse11::~GPU_FAILUREPV2Impulse11() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse11::Impulse_Function(double FiringTime)
{
return 400;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse11::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse11;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse12::GPU_FAILUREPV2Impulse12()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[4] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse12::~GPU_FAILUREPV2Impulse12() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse12::Impulse_Function(double FiringTime)
{
return 600;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse12::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse12;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse13::GPU_FAILUREPV2Impulse13()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[4] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse13::~GPU_FAILUREPV2Impulse13() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse13::Impulse_Function(double FiringTime)
{
return 30;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse13::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse13;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse14::GPU_FAILUREPV2Impulse14()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[4] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse14::~GPU_FAILUREPV2Impulse14() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse14::Impulse_Function(double FiringTime)
{
return 400;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse14::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse14;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse15::GPU_FAILUREPV2Impulse15()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[4] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse15::~GPU_FAILUREPV2Impulse15() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse15::Impulse_Function(double FiringTime)
{
return 600;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse15::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse15;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse16::GPU_FAILUREPV2Impulse16()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY_FAILURE);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[4] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse16::~GPU_FAILUREPV2Impulse16() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse16::Impulse_Function(double FiringTime)
{
return 600;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse16::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse16;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse17::GPU_FAILUREPV2Impulse17()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY_FAILURE);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[4] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse17::~GPU_FAILUREPV2Impulse17() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse17::Impulse_Function(double FiringTime)
{
return 600;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse17::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse17;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse18::GPU_FAILUREPV2Impulse18()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY_FAILURE);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[4] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse18::~GPU_FAILUREPV2Impulse18() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse18::Impulse_Function(double FiringTime)
{
return 30;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse18::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse18;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse19::GPU_FAILUREPV2Impulse19()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY_FAILURE);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[4] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse19::~GPU_FAILUREPV2Impulse19() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse19::Impulse_Function(double FiringTime)
{
return 400;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse19::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse19;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse20::GPU_FAILUREPV2Impulse20()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY_FAILURE);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[4] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse20::~GPU_FAILUREPV2Impulse20() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse20::Impulse_Function(double FiringTime)
{
return 400;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse20::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse20;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse21::GPU_FAILUREPV2Impulse21()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY_FAILURE);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[4] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse21::~GPU_FAILUREPV2Impulse21() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse21::Impulse_Function(double FiringTime)
{
return 30;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse21::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse21;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse22::GPU_FAILUREPV2Impulse22()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY_FAILURE);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[4] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse22::~GPU_FAILUREPV2Impulse22() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse22::Impulse_Function(double FiringTime)
{
return 600;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse22::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse22;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse23::GPU_FAILUREPV2Impulse23()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY_FAILURE);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[4] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse23::~GPU_FAILUREPV2Impulse23() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse23::Impulse_Function(double FiringTime)
{
return 30;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse23::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse23;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse24::GPU_FAILUREPV2Impulse24()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY_FAILURE);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[4] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse24::~GPU_FAILUREPV2Impulse24() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse24::Impulse_Function(double FiringTime)
{
return 400;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse24::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse24;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse25::GPU_FAILUREPV2Impulse25()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY_FAILURE);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[4] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse25::~GPU_FAILUREPV2Impulse25() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse25::Impulse_Function(double FiringTime)
{
return 600;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse25::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse25;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse26::GPU_FAILUREPV2Impulse26()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY_FAILURE);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[4] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse26::~GPU_FAILUREPV2Impulse26() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse26::Impulse_Function(double FiringTime)
{
return 400;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse26::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse26;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse27::GPU_FAILUREPV2Impulse27()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&MEMORY_FAILURE);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[4] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse27::~GPU_FAILUREPV2Impulse27() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse27::Impulse_Function(double FiringTime)
{
return 30;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse27::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse27;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse28::GPU_FAILUREPV2Impulse28()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[4] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse28::~GPU_FAILUREPV2Impulse28() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse28::Impulse_Function(double FiringTime)
{
return 2;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse28::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse28;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2Impulse29::GPU_FAILUREPV2Impulse29()
{
  NumberOfModelDependencies = 6;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&EXEC_UNIT_FAILURE);
  TheModelPtr[1] = (BaseModelClass**)(&WARP);
  TheModelPtr[2] = (BaseModelClass**)(&EXEC_UNIT);
  TheModelPtr[3] = (BaseModelClass**)(&MEMORY);
  TheModelPtr[4] = (BaseModelClass**)(&WARP_FAILURE);
  TheModelPtr[5] = (BaseModelClass**)(&MEMORY_FAILURE);
  ImpulseWorkerListLength = 0;
}

GPU_FAILUREPV2Impulse29::~GPU_FAILUREPV2Impulse29() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double GPU_FAILUREPV2Impulse29::Impulse_Function(double FiringTime)
{
return 2;

return(0);
}

ImpulseNodeClass** GPU_FAILUREPV2Impulse29::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new GPU_FAILUREPV2Impulse29;
  }

  return ImpulseWorkerList;
}

GPU_FAILUREPV2::GPU_FAILUREPV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheGPU_FAILURERJ);
  double startpts[1]={0.0};
  double stoppts[1]={end};
  Initialize("clock",(RewardType)1,1, startpts, stoppts, timeindex, 30,0, 0);
  AddImpulse("DISPATCHER_Copy","WARP",&Impulse0);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse0);
  AddImpulseModelDependency("MEMORY",&Impulse0);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse0);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse0);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse0);
  AddImpulse("DISPATCHER","EXEC_UNIT",&Impulse1);
  AddImpulseModelDependency("WARP",&Impulse1);
  AddImpulseModelDependency("MEMORY",&Impulse1);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse1);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse1);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse1);
  AddImpulse("handle_failure","EXEC_UNIT",&Impulse2);
  AddImpulseModelDependency("WARP",&Impulse2);
  AddImpulseModelDependency("MEMORY",&Impulse2);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse2);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse2);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse2);
  AddImpulse("DISPATCHER_Copy","WARP_FAILURE",&Impulse3);
  AddImpulseModelDependency("WARP",&Impulse3);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse3);
  AddImpulseModelDependency("MEMORY",&Impulse3);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse3);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse3);
  AddImpulse("LOCAL_READ_FROM_case1","MEMORY",&Impulse4);
  AddImpulseModelDependency("WARP",&Impulse4);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse4);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse4);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse4);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse4);
  AddImpulse("LOCAL_READ_FROM_case2","MEMORY",&Impulse5);
  AddImpulseModelDependency("WARP",&Impulse5);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse5);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse5);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse5);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse5);
  AddImpulse("LOCAL_READ_FROM_case3","MEMORY",&Impulse6);
  AddImpulseModelDependency("WARP",&Impulse6);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse6);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse6);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse6);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse6);
  AddImpulse("GLOBAL_READ_FROM_case1","MEMORY",&Impulse7);
  AddImpulseModelDependency("WARP",&Impulse7);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse7);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse7);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse7);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse7);
  AddImpulse("GLOBAL_READ_FROM_case2","MEMORY",&Impulse8);
  AddImpulseModelDependency("WARP",&Impulse8);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse8);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse8);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse8);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse8);
  AddImpulse("GLOBAL_READ_FROM_case3","MEMORY",&Impulse9);
  AddImpulseModelDependency("WARP",&Impulse9);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse9);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse9);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse9);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse9);
  AddImpulse("LOCAL_WRITE_TO_case1","MEMORY",&Impulse10);
  AddImpulseModelDependency("WARP",&Impulse10);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse10);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse10);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse10);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse10);
  AddImpulse("LOCAL_WRITE_TO_case2","MEMORY",&Impulse11);
  AddImpulseModelDependency("WARP",&Impulse11);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse11);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse11);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse11);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse11);
  AddImpulse("LOCAL_WRITE_TO_case3","MEMORY",&Impulse12);
  AddImpulseModelDependency("WARP",&Impulse12);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse12);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse12);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse12);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse12);
  AddImpulse("GLOBAL_WRITE_TO_case1","MEMORY",&Impulse13);
  AddImpulseModelDependency("WARP",&Impulse13);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse13);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse13);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse13);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse13);
  AddImpulse("GLOBAL_WRITE_TO_case2","MEMORY",&Impulse14);
  AddImpulseModelDependency("WARP",&Impulse14);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse14);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse14);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse14);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse14);
  AddImpulse("GLOBAL_WRITE_TO_case3","MEMORY",&Impulse15);
  AddImpulseModelDependency("WARP",&Impulse15);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse15);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse15);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse15);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse15);
  AddImpulse("LOCAL_WRITE_TO_case3","MEMORY_FAILURE",&Impulse16);
  AddImpulseModelDependency("WARP",&Impulse16);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse16);
  AddImpulseModelDependency("MEMORY",&Impulse16);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse16);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse16);
  AddImpulse("GLOBAL_WRITE_TO_case3","MEMORY_FAILURE",&Impulse17);
  AddImpulseModelDependency("WARP",&Impulse17);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse17);
  AddImpulseModelDependency("MEMORY",&Impulse17);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse17);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse17);
  AddImpulse("GLOBAL_WRITE_TO_case1","MEMORY_FAILURE",&Impulse18);
  AddImpulseModelDependency("WARP",&Impulse18);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse18);
  AddImpulseModelDependency("MEMORY",&Impulse18);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse18);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse18);
  AddImpulse("GLOBAL_WRITE_TO_case2","MEMORY_FAILURE",&Impulse19);
  AddImpulseModelDependency("WARP",&Impulse19);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse19);
  AddImpulseModelDependency("MEMORY",&Impulse19);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse19);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse19);
  AddImpulse("LOCAL_WRITE_TO_case2","MEMORY_FAILURE",&Impulse20);
  AddImpulseModelDependency("WARP",&Impulse20);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse20);
  AddImpulseModelDependency("MEMORY",&Impulse20);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse20);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse20);
  AddImpulse("LOCAL_WRITE_TO_case1","MEMORY_FAILURE",&Impulse21);
  AddImpulseModelDependency("WARP",&Impulse21);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse21);
  AddImpulseModelDependency("MEMORY",&Impulse21);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse21);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse21);
  AddImpulse("GLOBAL_READ_FROM_case3","MEMORY_FAILURE",&Impulse22);
  AddImpulseModelDependency("WARP",&Impulse22);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse22);
  AddImpulseModelDependency("MEMORY",&Impulse22);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse22);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse22);
  AddImpulse("GLOBAL_READ_FROM_case1","MEMORY_FAILURE",&Impulse23);
  AddImpulseModelDependency("WARP",&Impulse23);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse23);
  AddImpulseModelDependency("MEMORY",&Impulse23);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse23);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse23);
  AddImpulse("GLOBAL_READ_FROM_case2","MEMORY_FAILURE",&Impulse24);
  AddImpulseModelDependency("WARP",&Impulse24);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse24);
  AddImpulseModelDependency("MEMORY",&Impulse24);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse24);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse24);
  AddImpulse("LOCAL_READ_FROM_case3","MEMORY_FAILURE",&Impulse25);
  AddImpulseModelDependency("WARP",&Impulse25);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse25);
  AddImpulseModelDependency("MEMORY",&Impulse25);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse25);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse25);
  AddImpulse("LOCAL_READ_FROM_case2","MEMORY_FAILURE",&Impulse26);
  AddImpulseModelDependency("WARP",&Impulse26);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse26);
  AddImpulseModelDependency("MEMORY",&Impulse26);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse26);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse26);
  AddImpulse("LOCAL_READ_FROM_case1","MEMORY_FAILURE",&Impulse27);
  AddImpulseModelDependency("WARP",&Impulse27);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse27);
  AddImpulseModelDependency("MEMORY",&Impulse27);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse27);
  AddImpulseModelDependency("EXEC_UNIT_FAILURE",&Impulse27);
  AddImpulse("handle_failure","EXEC_UNIT_FAILURE",&Impulse28);
  AddImpulseModelDependency("WARP",&Impulse28);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse28);
  AddImpulseModelDependency("MEMORY",&Impulse28);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse28);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse28);
  AddImpulse("DISPATCHER","EXEC_UNIT_FAILURE",&Impulse29);
  AddImpulseModelDependency("WARP",&Impulse29);
  AddImpulseModelDependency("EXEC_UNIT",&Impulse29);
  AddImpulseModelDependency("MEMORY",&Impulse29);
  AddImpulseModelDependency("WARP_FAILURE",&Impulse29);
  AddImpulseModelDependency("MEMORY_FAILURE",&Impulse29);
}

GPU_FAILUREPV2::~GPU_FAILUREPV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void GPU_FAILUREPV2::CreateWorkerList(void) {
}
