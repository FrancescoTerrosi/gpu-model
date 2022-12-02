#include "L2_REWARDPVNodes.h"

L2_REWARDPV0Worker::L2_REWARDPV0Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&L2_CACHE);
}

L2_REWARDPV0Worker::~L2_REWARDPV0Worker() {
  delete [] TheModelPtr;
}

double L2_REWARDPV0Worker::Reward_Function(void) {

L2_CACHE->L2_CONTENT->Mark();

return (0);



}

L2_REWARDPV0::L2_REWARDPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheL2_CACHESAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0};
  Initialize("L2_CONTENT",(RewardType)0,1, startpts, stoppts, timeindex, 0,1, 0);
  AddModelDependency("L2_CACHE");
}

L2_REWARDPV0::~L2_REWARDPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void L2_REWARDPV0::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new L2_REWARDPV0Worker;
}
