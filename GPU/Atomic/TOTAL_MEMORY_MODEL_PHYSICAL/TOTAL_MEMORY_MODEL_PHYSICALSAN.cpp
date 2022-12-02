

// This C++ file was created by SanEditor

#include "Atomic/TOTAL_MEMORY_MODEL_PHYSICAL/TOTAL_MEMORY_MODEL_PHYSICALSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         TOTAL_MEMORY_MODEL_PHYSICALSAN Constructor             
******************************************************************/


TOTAL_MEMORY_MODEL_PHYSICALSAN::TOTAL_MEMORY_MODEL_PHYSICALSAN(){


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

  READ_TOTAL_MEMORY = new Place("READ_TOTAL_MEMORY" ,0);
  READ_DRAM = new Place("READ_DRAM" ,0);
  READ_L2 = new Place("READ_L2" ,0);
  BaseStateVariableClass* InitialPlaces[3]={
    READ_TOTAL_MEMORY,  // 0
    READ_DRAM,  // 1
    READ_L2   // 2
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("TOTAL_MEMORY_MODEL_PHYSICAL", 3, InitialPlaces, 
                        0, InitialROPlaces, 
                        2, InitialActionList, 1, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[4][2]={ 
    {0,0}, {1,0}, {0,1}, {2,1}
  };
  for(int n=0;n<4;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[2][2]={ 
    {0,0}, {0,1}
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

void TOTAL_MEMORY_MODEL_PHYSICALSAN::CustomInitialization() {

}
TOTAL_MEMORY_MODEL_PHYSICALSAN::~TOTAL_MEMORY_MODEL_PHYSICALSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void TOTAL_MEMORY_MODEL_PHYSICALSAN::assignPlacesToActivitiesInst(){
  READ_FROM_case1.READ_TOTAL_MEMORY = (Place*) LocalStateVariables[0];
  READ_FROM_case1.READ_DRAM = (Place*) LocalStateVariables[1];
  READ_FROM_case2.READ_TOTAL_MEMORY = (Place*) LocalStateVariables[0];
  READ_FROM_case2.READ_L2 = (Place*) LocalStateVariables[2];
}
void TOTAL_MEMORY_MODEL_PHYSICALSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================READ_FROMActivity_case1========================*/


TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case1::READ_FROMActivity_case1(){
  ActivityInitialize("READ_FROM_case1",0,Instantaneous , RaceEnabled, 2,1, false);
}

void TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case1::LinkVariables(){
  READ_TOTAL_MEMORY->Register(&READ_TOTAL_MEMORY_Mobius_Mark);
  READ_DRAM->Register(&READ_DRAM_Mobius_Mark);
}

bool TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_TOTAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case1::Weight(){ 
  return dram_total_read_rate;
}

bool TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case1::ReactivationFunction(){ 
  return false;
}

double TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case1::SampleDistribution(){
  return 0;
}

double* TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case1::Rank(){
  return 1;
}

BaseActionClass* TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case1::Fire(){
  (*(READ_TOTAL_MEMORY_Mobius_Mark))--;
  (*(READ_DRAM_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case2========================*/


TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case2::READ_FROMActivity_case2(){
  ActivityInitialize("READ_FROM_case2",0,Instantaneous , RaceEnabled, 2,1, false);
}

void TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case2::LinkVariables(){
  READ_TOTAL_MEMORY->Register(&READ_TOTAL_MEMORY_Mobius_Mark);
  READ_L2->Register(&READ_L2_Mobius_Mark);
}

bool TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_TOTAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case2::Weight(){ 
  return l2_total_read_rate;
}

bool TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case2::ReactivationFunction(){ 
  return false;
}

double TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case2::SampleDistribution(){
  return 0;
}

double* TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case2::Rank(){
  return 1;
}

BaseActionClass* TOTAL_MEMORY_MODEL_PHYSICALSAN::READ_FROMActivity_case2::Fire(){
  (*(READ_TOTAL_MEMORY_Mobius_Mark))--;
  (*(READ_L2_Mobius_Mark))++;
  return this;
}

