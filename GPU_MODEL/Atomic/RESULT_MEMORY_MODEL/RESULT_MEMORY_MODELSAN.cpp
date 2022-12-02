

// This C++ file was created by SanEditor

#include "Atomic/RESULT_MEMORY_MODEL/RESULT_MEMORY_MODELSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         RESULT_MEMORY_MODELSAN Constructor             
******************************************************************/


RESULT_MEMORY_MODELSAN::RESULT_MEMORY_MODELSAN(){


  READ_FROMGroup.initialize(3, "READ_FROMGroup");
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case1);
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case2);
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case3);

  WRITE_TOGroup.initialize(3, "WRITE_TOGroup");
  WRITE_TOGroup.appendGroup((BaseGroupClass*) &WRITE_TO_case1);
  WRITE_TOGroup.appendGroup((BaseGroupClass*) &WRITE_TO_case2);
  WRITE_TOGroup.appendGroup((BaseGroupClass*) &WRITE_TO_case3);

  Activity* InitialActionList[6]={
    &READ_FROM_case1, //0
    &READ_FROM_case2, //1
    &READ_FROM_case3, //2
    &WRITE_TO_case1, //3
    &WRITE_TO_case2, //4
    &WRITE_TO_case3  // 5
  };

  BaseGroupClass* InitialGroupList[2]={
    (BaseGroupClass*) &(READ_FROMGroup), 
    (BaseGroupClass*) &(WRITE_TOGroup)
  };

  READ_L1 = new Place("READ_L1" ,0);
  READ_L2 = new Place("READ_L2" ,0);
  READ_DRAM = new Place("READ_DRAM" ,0);
  WRITE_L1 = new Place("WRITE_L1" ,0);
  WRITE_L2 = new Place("WRITE_L2" ,0);
  READ_RESULT_MEMORY = new Place("READ_RESULT_MEMORY" ,0);
  WRITE_DRAM = new Place("WRITE_DRAM" ,0);
  WRITE_RESULT_MEMORY = new Place("WRITE_RESULT_MEMORY" ,0);
  BaseStateVariableClass* InitialPlaces[8]={
    READ_L1,  // 0
    READ_L2,  // 1
    READ_DRAM,  // 2
    WRITE_L1,  // 3
    WRITE_L2,  // 4
    READ_RESULT_MEMORY,  // 5
    WRITE_DRAM,  // 6
    WRITE_RESULT_MEMORY   // 7
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("RESULT_MEMORY_MODEL", 8, InitialPlaces, 
                        0, InitialROPlaces, 
                        6, InitialActionList, 2, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[12][2]={ 
    {5,0}, {2,0}, {5,1}, {1,1}, {5,2}, {0,2}, {7,3}, {6,3}, {7,4}, 
    {4,4}, {7,5}, {3,5}
  };
  for(int n=0;n<12;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[6][2]={ 
    {5,0}, {5,1}, {5,2}, {7,3}, {7,4}, {7,5}
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

void RESULT_MEMORY_MODELSAN::CustomInitialization() {

}
RESULT_MEMORY_MODELSAN::~RESULT_MEMORY_MODELSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void RESULT_MEMORY_MODELSAN::assignPlacesToActivitiesInst(){
  READ_FROM_case1.READ_RESULT_MEMORY = (Place*) LocalStateVariables[5];
  READ_FROM_case1.READ_DRAM = (Place*) LocalStateVariables[2];
  READ_FROM_case2.READ_RESULT_MEMORY = (Place*) LocalStateVariables[5];
  READ_FROM_case2.READ_L2 = (Place*) LocalStateVariables[1];
  READ_FROM_case3.READ_RESULT_MEMORY = (Place*) LocalStateVariables[5];
  READ_FROM_case3.READ_L1 = (Place*) LocalStateVariables[0];
  WRITE_TO_case1.WRITE_RESULT_MEMORY = (Place*) LocalStateVariables[7];
  WRITE_TO_case1.WRITE_DRAM = (Place*) LocalStateVariables[6];
  WRITE_TO_case2.WRITE_RESULT_MEMORY = (Place*) LocalStateVariables[7];
  WRITE_TO_case2.WRITE_L2 = (Place*) LocalStateVariables[4];
  WRITE_TO_case3.WRITE_RESULT_MEMORY = (Place*) LocalStateVariables[7];
  WRITE_TO_case3.WRITE_L1 = (Place*) LocalStateVariables[3];
}
void RESULT_MEMORY_MODELSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================READ_FROMActivity_case1========================*/


RESULT_MEMORY_MODELSAN::READ_FROMActivity_case1::READ_FROMActivity_case1(){
  ActivityInitialize("READ_FROM_case1",0,Instantaneous , RaceEnabled, 2,1, false);
}

void RESULT_MEMORY_MODELSAN::READ_FROMActivity_case1::LinkVariables(){
  READ_RESULT_MEMORY->Register(&READ_RESULT_MEMORY_Mobius_Mark);
  READ_DRAM->Register(&READ_DRAM_Mobius_Mark);
}

bool RESULT_MEMORY_MODELSAN::READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double RESULT_MEMORY_MODELSAN::READ_FROMActivity_case1::Weight(){ 
  return dram_result_read_prob;
}

bool RESULT_MEMORY_MODELSAN::READ_FROMActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool RESULT_MEMORY_MODELSAN::READ_FROMActivity_case1::ReactivationFunction(){ 
  return false;
}

double RESULT_MEMORY_MODELSAN::READ_FROMActivity_case1::SampleDistribution(){
  return 0;
}

double* RESULT_MEMORY_MODELSAN::READ_FROMActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int RESULT_MEMORY_MODELSAN::READ_FROMActivity_case1::Rank(){
  return 1;
}

BaseActionClass* RESULT_MEMORY_MODELSAN::READ_FROMActivity_case1::Fire(){
  (*(READ_RESULT_MEMORY_Mobius_Mark))--;
  (*(READ_DRAM_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case2========================*/


RESULT_MEMORY_MODELSAN::READ_FROMActivity_case2::READ_FROMActivity_case2(){
  ActivityInitialize("READ_FROM_case2",0,Instantaneous , RaceEnabled, 2,1, false);
}

void RESULT_MEMORY_MODELSAN::READ_FROMActivity_case2::LinkVariables(){
  READ_RESULT_MEMORY->Register(&READ_RESULT_MEMORY_Mobius_Mark);
  READ_L2->Register(&READ_L2_Mobius_Mark);
}

bool RESULT_MEMORY_MODELSAN::READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double RESULT_MEMORY_MODELSAN::READ_FROMActivity_case2::Weight(){ 
  return l2_result_read_prob;
}

bool RESULT_MEMORY_MODELSAN::READ_FROMActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool RESULT_MEMORY_MODELSAN::READ_FROMActivity_case2::ReactivationFunction(){ 
  return false;
}

double RESULT_MEMORY_MODELSAN::READ_FROMActivity_case2::SampleDistribution(){
  return 0;
}

double* RESULT_MEMORY_MODELSAN::READ_FROMActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int RESULT_MEMORY_MODELSAN::READ_FROMActivity_case2::Rank(){
  return 1;
}

BaseActionClass* RESULT_MEMORY_MODELSAN::READ_FROMActivity_case2::Fire(){
  (*(READ_RESULT_MEMORY_Mobius_Mark))--;
  (*(READ_L2_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case3========================*/


RESULT_MEMORY_MODELSAN::READ_FROMActivity_case3::READ_FROMActivity_case3(){
  ActivityInitialize("READ_FROM_case3",0,Instantaneous , RaceEnabled, 2,1, false);
}

void RESULT_MEMORY_MODELSAN::READ_FROMActivity_case3::LinkVariables(){
  READ_RESULT_MEMORY->Register(&READ_RESULT_MEMORY_Mobius_Mark);
  READ_L1->Register(&READ_L1_Mobius_Mark);
}

bool RESULT_MEMORY_MODELSAN::READ_FROMActivity_case3::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double RESULT_MEMORY_MODELSAN::READ_FROMActivity_case3::Weight(){ 
  return l1_result_read_prob;
}

bool RESULT_MEMORY_MODELSAN::READ_FROMActivity_case3::ReactivationPredicate(){ 
  return false;
}

bool RESULT_MEMORY_MODELSAN::READ_FROMActivity_case3::ReactivationFunction(){ 
  return false;
}

double RESULT_MEMORY_MODELSAN::READ_FROMActivity_case3::SampleDistribution(){
  return 0;
}

double* RESULT_MEMORY_MODELSAN::READ_FROMActivity_case3::ReturnDistributionParameters(){
    return NULL;
}

int RESULT_MEMORY_MODELSAN::READ_FROMActivity_case3::Rank(){
  return 1;
}

BaseActionClass* RESULT_MEMORY_MODELSAN::READ_FROMActivity_case3::Fire(){
  (*(READ_RESULT_MEMORY_Mobius_Mark))--;
  (*(READ_L1_Mobius_Mark))++;
  return this;
}

/*======================WRITE_TOActivity_case1========================*/


RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case1::WRITE_TOActivity_case1(){
  ActivityInitialize("WRITE_TO_case1",1,Instantaneous , RaceEnabled, 2,1, false);
}

void RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case1::LinkVariables(){
  WRITE_RESULT_MEMORY->Register(&WRITE_RESULT_MEMORY_Mobius_Mark);
  WRITE_DRAM->Register(&WRITE_DRAM_Mobius_Mark);
}

bool RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case1::Weight(){ 
  return dram_result_write_prob;
}

bool RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case1::ReactivationFunction(){ 
  return false;
}

double RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case1::SampleDistribution(){
  return 0;
}

double* RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case1::Rank(){
  return 1;
}

BaseActionClass* RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case1::Fire(){
  (*(WRITE_RESULT_MEMORY_Mobius_Mark))--;
  (*(WRITE_DRAM_Mobius_Mark))++;
  return this;
}

/*======================WRITE_TOActivity_case2========================*/


RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case2::WRITE_TOActivity_case2(){
  ActivityInitialize("WRITE_TO_case2",1,Instantaneous , RaceEnabled, 2,1, false);
}

void RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case2::LinkVariables(){
  WRITE_RESULT_MEMORY->Register(&WRITE_RESULT_MEMORY_Mobius_Mark);
  WRITE_L2->Register(&WRITE_L2_Mobius_Mark);
}

bool RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case2::Weight(){ 
  return l2_result_write_prob;
}

bool RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case2::ReactivationFunction(){ 
  return false;
}

double RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case2::SampleDistribution(){
  return 0;
}

double* RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case2::Rank(){
  return 1;
}

BaseActionClass* RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case2::Fire(){
  (*(WRITE_RESULT_MEMORY_Mobius_Mark))--;
  (*(WRITE_L2_Mobius_Mark))++;
  return this;
}

/*======================WRITE_TOActivity_case3========================*/


RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case3::WRITE_TOActivity_case3(){
  ActivityInitialize("WRITE_TO_case3",1,Instantaneous , RaceEnabled, 2,1, false);
}

void RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case3::LinkVariables(){
  WRITE_RESULT_MEMORY->Register(&WRITE_RESULT_MEMORY_Mobius_Mark);
  WRITE_L1->Register(&WRITE_L1_Mobius_Mark);
}

bool RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case3::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case3::Weight(){ 
  return l1_result_write_prob;
}

bool RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case3::ReactivationPredicate(){ 
  return false;
}

bool RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case3::ReactivationFunction(){ 
  return false;
}

double RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case3::SampleDistribution(){
  return 0;
}

double* RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case3::ReturnDistributionParameters(){
    return NULL;
}

int RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case3::Rank(){
  return 1;
}

BaseActionClass* RESULT_MEMORY_MODELSAN::WRITE_TOActivity_case3::Fire(){
  (*(WRITE_RESULT_MEMORY_Mobius_Mark))--;
  (*(WRITE_L1_Mobius_Mark))++;
  return this;
}

