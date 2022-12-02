

// This C++ file was created by SanEditor

#include "Atomic/INITIAL_MEMORY_MODEL/INITIAL_MEMORY_MODELSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         INITIAL_MEMORY_MODELSAN Constructor             
******************************************************************/


INITIAL_MEMORY_MODELSAN::INITIAL_MEMORY_MODELSAN(){


  READ_FROMGroup.initialize(2, "READ_FROMGroup");
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case1);
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case2);

  Activity* InitialActionList[2]={
    &READ_FROM_case1, //0
    &READ_FROM_case2  // 1
  };

  BaseGroupClass* InitialGroupList[1]={
    (BaseGroupClass*) &(READ_FROMGroup)
  };

  READ_L2 = new Place("READ_L2" ,0);
  READ_INITIAL_MEMORY = new Place("READ_INITIAL_MEMORY" ,0);
  READ_DRAM = new Place("READ_DRAM" ,0);
  BaseStateVariableClass* InitialPlaces[3]={
    READ_L2,  // 0
    READ_INITIAL_MEMORY,  // 1
    READ_DRAM   // 2
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("INITIAL_MEMORY_MODEL", 3, InitialPlaces, 
                        0, InitialROPlaces, 
                        2, InitialActionList, 1, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[4][2]={ 
    {1,0}, {2,0}, {1,1}, {0,1}
  };
  for(int n=0;n<4;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[2][2]={ 
    {1,0}, {1,1}
  };
  for(int n=0;n<2;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<2;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void INITIAL_MEMORY_MODELSAN::CustomInitialization() {

}
INITIAL_MEMORY_MODELSAN::~INITIAL_MEMORY_MODELSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void INITIAL_MEMORY_MODELSAN::assignPlacesToActivitiesInst(){
  READ_FROM_case1.READ_INITIAL_MEMORY = (Place*) LocalStateVariables[1];
  READ_FROM_case1.READ_DRAM = (Place*) LocalStateVariables[2];
  READ_FROM_case2.READ_INITIAL_MEMORY = (Place*) LocalStateVariables[1];
  READ_FROM_case2.READ_L2 = (Place*) LocalStateVariables[0];
}
void INITIAL_MEMORY_MODELSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================READ_FROMActivity_case1========================*/


INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case1::READ_FROMActivity_case1(){
  ActivityInitialize("READ_FROM_case1",0,Instantaneous , RaceEnabled, 2,1, false);
}

void INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case1::LinkVariables(){
  READ_INITIAL_MEMORY->Register(&READ_INITIAL_MEMORY_Mobius_Mark);
  READ_DRAM->Register(&READ_DRAM_Mobius_Mark);
}

bool INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_INITIAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case1::Weight(){ 
  return dram_total_read_prob;
}

bool INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case1::ReactivationFunction(){ 
  return false;
}

double INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case1::SampleDistribution(){
  return 0;
}

double* INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case1::Rank(){
  return 1;
}

BaseActionClass* INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case1::Fire(){
  (*(READ_INITIAL_MEMORY_Mobius_Mark))--;
  (*(READ_DRAM_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case2========================*/


INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case2::READ_FROMActivity_case2(){
  ActivityInitialize("READ_FROM_case2",0,Instantaneous , RaceEnabled, 2,1, false);
}

void INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case2::LinkVariables(){
  READ_INITIAL_MEMORY->Register(&READ_INITIAL_MEMORY_Mobius_Mark);
  READ_L2->Register(&READ_L2_Mobius_Mark);
}

bool INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_INITIAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case2::Weight(){ 
  return l2_total_read_prob;
}

bool INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case2::ReactivationFunction(){ 
  return false;
}

double INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case2::SampleDistribution(){
  return 0;
}

double* INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case2::Rank(){
  return 1;
}

BaseActionClass* INITIAL_MEMORY_MODELSAN::READ_FROMActivity_case2::Fire(){
  (*(READ_INITIAL_MEMORY_Mobius_Mark))--;
  (*(READ_L2_Mobius_Mark))++;
  return this;
}

