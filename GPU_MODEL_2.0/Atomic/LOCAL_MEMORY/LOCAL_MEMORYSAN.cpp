

// This C++ file was created by SanEditor

#include "Atomic/LOCAL_MEMORY/LOCAL_MEMORYSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         LOCAL_MEMORYSAN Constructor             
******************************************************************/


LOCAL_MEMORYSAN::LOCAL_MEMORYSAN(){


  WRITE_TOGroup.initialize(3, "WRITE_TOGroup");
  WRITE_TOGroup.appendGroup((BaseGroupClass*) &WRITE_TO_case1);
  WRITE_TOGroup.appendGroup((BaseGroupClass*) &WRITE_TO_case2);
  WRITE_TOGroup.appendGroup((BaseGroupClass*) &WRITE_TO_case3);

  READ_FROMGroup.initialize(3, "READ_FROMGroup");
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case1);
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case2);
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case3);

  Activity* InitialActionList[6]={
    &WRITE_TO_case1, //0
    &WRITE_TO_case2, //1
    &WRITE_TO_case3, //2
    &READ_FROM_case1, //3
    &READ_FROM_case2, //4
    &READ_FROM_case3  // 5
  };

  BaseGroupClass* InitialGroupList[2]={
    (BaseGroupClass*) &(WRITE_TOGroup), 
    (BaseGroupClass*) &(READ_FROMGroup)
  };

  WRITE_LOCAL_MEMORY = new Place("WRITE_LOCAL_MEMORY" ,0);
  WRITE_L1 = new Place("WRITE_L1" ,0);
  WRITE_L2 = new Place("WRITE_L2" ,0);
  WRITE_DRAM = new Place("WRITE_DRAM" ,0);
  READ_DRAM = new Place("READ_DRAM" ,0);
  READ_L2 = new Place("READ_L2" ,0);
  READ_LOCAL_MEMORY = new Place("READ_LOCAL_MEMORY" ,0);
  READ_L1 = new Place("READ_L1" ,0);
  BaseStateVariableClass* InitialPlaces[8]={
    WRITE_LOCAL_MEMORY,  // 0
    WRITE_L1,  // 1
    WRITE_L2,  // 2
    WRITE_DRAM,  // 3
    READ_DRAM,  // 4
    READ_L2,  // 5
    READ_LOCAL_MEMORY,  // 6
    READ_L1   // 7
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("LOCAL_MEMORY", 8, InitialPlaces, 
                        0, InitialROPlaces, 
                        6, InitialActionList, 2, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[12][2]={ 
    {0,0}, {3,0}, {0,1}, {2,1}, {0,2}, {1,2}, {6,3}, {4,3}, {6,4}, 
    {5,4}, {6,5}, {7,5}
  };
  for(int n=0;n<12;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[6][2]={ 
    {0,0}, {0,1}, {0,2}, {6,3}, {6,4}, {6,5}
  };
  for(int n=0;n<6;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<6;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void LOCAL_MEMORYSAN::CustomInitialization() {

}
LOCAL_MEMORYSAN::~LOCAL_MEMORYSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void LOCAL_MEMORYSAN::assignPlacesToActivitiesInst(){
  WRITE_TO_case1.WRITE_LOCAL_MEMORY = (Place*) LocalStateVariables[0];
  WRITE_TO_case1.WRITE_DRAM = (Place*) LocalStateVariables[3];
  WRITE_TO_case2.WRITE_LOCAL_MEMORY = (Place*) LocalStateVariables[0];
  WRITE_TO_case2.WRITE_L2 = (Place*) LocalStateVariables[2];
  WRITE_TO_case3.WRITE_LOCAL_MEMORY = (Place*) LocalStateVariables[0];
  WRITE_TO_case3.WRITE_L1 = (Place*) LocalStateVariables[1];
  READ_FROM_case1.READ_LOCAL_MEMORY = (Place*) LocalStateVariables[6];
  READ_FROM_case1.READ_DRAM = (Place*) LocalStateVariables[4];
  READ_FROM_case2.READ_LOCAL_MEMORY = (Place*) LocalStateVariables[6];
  READ_FROM_case2.READ_L2 = (Place*) LocalStateVariables[5];
  READ_FROM_case3.READ_LOCAL_MEMORY = (Place*) LocalStateVariables[6];
  READ_FROM_case3.READ_L1 = (Place*) LocalStateVariables[7];
}
void LOCAL_MEMORYSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================WRITE_TOActivity_case1========================*/


LOCAL_MEMORYSAN::WRITE_TOActivity_case1::WRITE_TOActivity_case1(){
  ActivityInitialize("WRITE_TO_case1",0,Instantaneous , RaceEnabled, 2,1, false);
}

void LOCAL_MEMORYSAN::WRITE_TOActivity_case1::LinkVariables(){
  WRITE_LOCAL_MEMORY->Register(&WRITE_LOCAL_MEMORY_Mobius_Mark);
  WRITE_DRAM->Register(&WRITE_DRAM_Mobius_Mark);
}

bool LOCAL_MEMORYSAN::WRITE_TOActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_LOCAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double LOCAL_MEMORYSAN::WRITE_TOActivity_case1::Weight(){ 
  return dram_local_write_prob;
}

bool LOCAL_MEMORYSAN::WRITE_TOActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool LOCAL_MEMORYSAN::WRITE_TOActivity_case1::ReactivationFunction(){ 
  return false;
}

double LOCAL_MEMORYSAN::WRITE_TOActivity_case1::SampleDistribution(){
  return 0;
}

double* LOCAL_MEMORYSAN::WRITE_TOActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int LOCAL_MEMORYSAN::WRITE_TOActivity_case1::Rank(){
  return 1;
}

BaseActionClass* LOCAL_MEMORYSAN::WRITE_TOActivity_case1::Fire(){
  (*(WRITE_LOCAL_MEMORY_Mobius_Mark))--;
  (*(WRITE_DRAM_Mobius_Mark))++;
  return this;
}

/*======================WRITE_TOActivity_case2========================*/


LOCAL_MEMORYSAN::WRITE_TOActivity_case2::WRITE_TOActivity_case2(){
  ActivityInitialize("WRITE_TO_case2",0,Instantaneous , RaceEnabled, 2,1, false);
}

void LOCAL_MEMORYSAN::WRITE_TOActivity_case2::LinkVariables(){
  WRITE_LOCAL_MEMORY->Register(&WRITE_LOCAL_MEMORY_Mobius_Mark);
  WRITE_L2->Register(&WRITE_L2_Mobius_Mark);
}

bool LOCAL_MEMORYSAN::WRITE_TOActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_LOCAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double LOCAL_MEMORYSAN::WRITE_TOActivity_case2::Weight(){ 
  return l2_local_write_prob;
}

bool LOCAL_MEMORYSAN::WRITE_TOActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool LOCAL_MEMORYSAN::WRITE_TOActivity_case2::ReactivationFunction(){ 
  return false;
}

double LOCAL_MEMORYSAN::WRITE_TOActivity_case2::SampleDistribution(){
  return 0;
}

double* LOCAL_MEMORYSAN::WRITE_TOActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int LOCAL_MEMORYSAN::WRITE_TOActivity_case2::Rank(){
  return 1;
}

BaseActionClass* LOCAL_MEMORYSAN::WRITE_TOActivity_case2::Fire(){
  (*(WRITE_LOCAL_MEMORY_Mobius_Mark))--;
  (*(WRITE_L2_Mobius_Mark))++;
  return this;
}

/*======================WRITE_TOActivity_case3========================*/


LOCAL_MEMORYSAN::WRITE_TOActivity_case3::WRITE_TOActivity_case3(){
  ActivityInitialize("WRITE_TO_case3",0,Instantaneous , RaceEnabled, 2,1, false);
}

void LOCAL_MEMORYSAN::WRITE_TOActivity_case3::LinkVariables(){
  WRITE_LOCAL_MEMORY->Register(&WRITE_LOCAL_MEMORY_Mobius_Mark);
  WRITE_L1->Register(&WRITE_L1_Mobius_Mark);
}

bool LOCAL_MEMORYSAN::WRITE_TOActivity_case3::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_LOCAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double LOCAL_MEMORYSAN::WRITE_TOActivity_case3::Weight(){ 
  return l1_local_write_prob;
}

bool LOCAL_MEMORYSAN::WRITE_TOActivity_case3::ReactivationPredicate(){ 
  return false;
}

bool LOCAL_MEMORYSAN::WRITE_TOActivity_case3::ReactivationFunction(){ 
  return false;
}

double LOCAL_MEMORYSAN::WRITE_TOActivity_case3::SampleDistribution(){
  return 0;
}

double* LOCAL_MEMORYSAN::WRITE_TOActivity_case3::ReturnDistributionParameters(){
    return NULL;
}

int LOCAL_MEMORYSAN::WRITE_TOActivity_case3::Rank(){
  return 1;
}

BaseActionClass* LOCAL_MEMORYSAN::WRITE_TOActivity_case3::Fire(){
  (*(WRITE_LOCAL_MEMORY_Mobius_Mark))--;
  (*(WRITE_L1_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case1========================*/


LOCAL_MEMORYSAN::READ_FROMActivity_case1::READ_FROMActivity_case1(){
  ActivityInitialize("READ_FROM_case1",1,Instantaneous , RaceEnabled, 2,1, false);
}

void LOCAL_MEMORYSAN::READ_FROMActivity_case1::LinkVariables(){
  READ_LOCAL_MEMORY->Register(&READ_LOCAL_MEMORY_Mobius_Mark);
  READ_DRAM->Register(&READ_DRAM_Mobius_Mark);
}

bool LOCAL_MEMORYSAN::READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_LOCAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double LOCAL_MEMORYSAN::READ_FROMActivity_case1::Weight(){ 
  return dram_local_read_prob;
}

bool LOCAL_MEMORYSAN::READ_FROMActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool LOCAL_MEMORYSAN::READ_FROMActivity_case1::ReactivationFunction(){ 
  return false;
}

double LOCAL_MEMORYSAN::READ_FROMActivity_case1::SampleDistribution(){
  return 0;
}

double* LOCAL_MEMORYSAN::READ_FROMActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int LOCAL_MEMORYSAN::READ_FROMActivity_case1::Rank(){
  return 1;
}

BaseActionClass* LOCAL_MEMORYSAN::READ_FROMActivity_case1::Fire(){
  (*(READ_LOCAL_MEMORY_Mobius_Mark))--;
  (*(READ_DRAM_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case2========================*/


LOCAL_MEMORYSAN::READ_FROMActivity_case2::READ_FROMActivity_case2(){
  ActivityInitialize("READ_FROM_case2",1,Instantaneous , RaceEnabled, 2,1, false);
}

void LOCAL_MEMORYSAN::READ_FROMActivity_case2::LinkVariables(){
  READ_LOCAL_MEMORY->Register(&READ_LOCAL_MEMORY_Mobius_Mark);
  READ_L2->Register(&READ_L2_Mobius_Mark);
}

bool LOCAL_MEMORYSAN::READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_LOCAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double LOCAL_MEMORYSAN::READ_FROMActivity_case2::Weight(){ 
  return l2_local_read_prob;
}

bool LOCAL_MEMORYSAN::READ_FROMActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool LOCAL_MEMORYSAN::READ_FROMActivity_case2::ReactivationFunction(){ 
  return false;
}

double LOCAL_MEMORYSAN::READ_FROMActivity_case2::SampleDistribution(){
  return 0;
}

double* LOCAL_MEMORYSAN::READ_FROMActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int LOCAL_MEMORYSAN::READ_FROMActivity_case2::Rank(){
  return 1;
}

BaseActionClass* LOCAL_MEMORYSAN::READ_FROMActivity_case2::Fire(){
  (*(READ_LOCAL_MEMORY_Mobius_Mark))--;
  (*(READ_L2_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case3========================*/


LOCAL_MEMORYSAN::READ_FROMActivity_case3::READ_FROMActivity_case3(){
  ActivityInitialize("READ_FROM_case3",1,Instantaneous , RaceEnabled, 2,1, false);
}

void LOCAL_MEMORYSAN::READ_FROMActivity_case3::LinkVariables(){
  READ_LOCAL_MEMORY->Register(&READ_LOCAL_MEMORY_Mobius_Mark);
  READ_L1->Register(&READ_L1_Mobius_Mark);
}

bool LOCAL_MEMORYSAN::READ_FROMActivity_case3::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_LOCAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double LOCAL_MEMORYSAN::READ_FROMActivity_case3::Weight(){ 
  return l1_local_read_prob;
}

bool LOCAL_MEMORYSAN::READ_FROMActivity_case3::ReactivationPredicate(){ 
  return false;
}

bool LOCAL_MEMORYSAN::READ_FROMActivity_case3::ReactivationFunction(){ 
  return false;
}

double LOCAL_MEMORYSAN::READ_FROMActivity_case3::SampleDistribution(){
  return 0;
}

double* LOCAL_MEMORYSAN::READ_FROMActivity_case3::ReturnDistributionParameters(){
    return NULL;
}

int LOCAL_MEMORYSAN::READ_FROMActivity_case3::Rank(){
  return 1;
}

BaseActionClass* LOCAL_MEMORYSAN::READ_FROMActivity_case3::Fire(){
  (*(READ_LOCAL_MEMORY_Mobius_Mark))--;
  (*(READ_L1_Mobius_Mark))++;
  return this;
}

