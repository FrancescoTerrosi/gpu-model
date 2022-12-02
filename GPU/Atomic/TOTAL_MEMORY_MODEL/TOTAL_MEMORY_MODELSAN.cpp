

// This C++ file was created by SanEditor

#include "Atomic/TOTAL_MEMORY_MODEL/TOTAL_MEMORY_MODELSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         TOTAL_MEMORY_MODELSAN Constructor             
******************************************************************/


TOTAL_MEMORY_MODELSAN::TOTAL_MEMORY_MODELSAN(){


  READ_FROMGroup.initialize(2, "READ_FROMGroup");
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case1);
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case2);

  Activity* InitialActionList[4]={
    &READ_FROM_case1, //0
    &READ_FROM_case2, //1
    &Instantaneous_Activity1, //2
    &Instantaneous_Activity2  // 3
  };

  BaseGroupClass* InitialGroupList[3]={
    (BaseGroupClass*) &(READ_FROMGroup), 
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(Instantaneous_Activity2)
  };

  READ_TOTAL_MEMORY = new Place("READ_TOTAL_MEMORY" ,0);
  MEMORY_OK = new Place("MEMORY_OK" ,0);
  MEMORY_KO = new Place("MEMORY_KO" ,0);
  MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE" ,0);
  OK_READ = new Place("OK_READ" ,0);
  KO_READ = new Place("KO_READ" ,0);
  BaseStateVariableClass* InitialPlaces[6]={
    READ_TOTAL_MEMORY,  // 0
    MEMORY_OK,  // 1
    MEMORY_KO,  // 2
    MEM_OP_COMPLETE,  // 3
    OK_READ,  // 4
    KO_READ   // 5
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("TOTAL_MEMORY_MODEL", 6, InitialPlaces, 
                        0, InitialROPlaces, 
                        4, InitialActionList, 3, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[10][2]={ 
    {0,0}, {1,0}, {0,1}, {2,1}, {1,2}, {3,2}, {4,2}, {2,3}, {3,3}, 
    {5,3}
  };
  for(int n=0;n<10;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[4][2]={ 
    {0,0}, {0,1}, {1,2}, {2,3}
  };
  for(int n=0;n<4;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<4;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void TOTAL_MEMORY_MODELSAN::CustomInitialization() {

}
TOTAL_MEMORY_MODELSAN::~TOTAL_MEMORY_MODELSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void TOTAL_MEMORY_MODELSAN::assignPlacesToActivitiesInst(){
  READ_FROM_case1.READ_TOTAL_MEMORY = (Place*) LocalStateVariables[0];
  READ_FROM_case1.MEMORY_OK = (Place*) LocalStateVariables[1];
  READ_FROM_case2.READ_TOTAL_MEMORY = (Place*) LocalStateVariables[0];
  READ_FROM_case2.MEMORY_KO = (Place*) LocalStateVariables[2];
  Instantaneous_Activity1.MEMORY_OK = (Place*) LocalStateVariables[1];
  Instantaneous_Activity1.MEM_OP_COMPLETE = (Place*) LocalStateVariables[3];
  Instantaneous_Activity1.OK_READ = (Place*) LocalStateVariables[4];
  Instantaneous_Activity2.MEMORY_KO = (Place*) LocalStateVariables[2];
  Instantaneous_Activity2.MEM_OP_COMPLETE = (Place*) LocalStateVariables[3];
  Instantaneous_Activity2.KO_READ = (Place*) LocalStateVariables[5];
}
void TOTAL_MEMORY_MODELSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================READ_FROMActivity_case1========================*/


TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case1::READ_FROMActivity_case1(){
  ActivityInitialize("READ_FROM_case1",0,Instantaneous , RaceEnabled, 2,1, false);
}

void TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case1::LinkVariables(){
  READ_TOTAL_MEMORY->Register(&READ_TOTAL_MEMORY_Mobius_Mark);
  MEMORY_OK->Register(&MEMORY_OK_Mobius_Mark);
}

bool TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_TOTAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case1::Weight(){ 
  return 0.5;
}

bool TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case1::ReactivationFunction(){ 
  return false;
}

double TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case1::SampleDistribution(){
  return 0;
}

double* TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case1::Rank(){
  return 1;
}

BaseActionClass* TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case1::Fire(){
  (*(READ_TOTAL_MEMORY_Mobius_Mark))--;
  (*(MEMORY_OK_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case2========================*/


TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case2::READ_FROMActivity_case2(){
  ActivityInitialize("READ_FROM_case2",0,Instantaneous , RaceEnabled, 2,1, false);
}

void TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case2::LinkVariables(){
  READ_TOTAL_MEMORY->Register(&READ_TOTAL_MEMORY_Mobius_Mark);
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
}

bool TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_TOTAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case2::Weight(){ 
  return 0.5;
}

bool TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case2::ReactivationFunction(){ 
  return false;
}

double TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case2::SampleDistribution(){
  return 0;
}

double* TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case2::Rank(){
  return 1;
}

BaseActionClass* TOTAL_MEMORY_MODELSAN::READ_FROMActivity_case2::Fire(){
  (*(READ_TOTAL_MEMORY_Mobius_Mark))--;
  (*(MEMORY_KO_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity1Activity========================*/


TOTAL_MEMORY_MODELSAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",1,Instantaneous , RaceEnabled, 3,1, false);
}

void TOTAL_MEMORY_MODELSAN::Instantaneous_Activity1Activity::LinkVariables(){
  MEMORY_OK->Register(&MEMORY_OK_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
  OK_READ->Register(&OK_READ_Mobius_Mark);
}

bool TOTAL_MEMORY_MODELSAN::Instantaneous_Activity1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEMORY_OK_Mobius_Mark)) >=1));
  return NewEnabled;
}

double TOTAL_MEMORY_MODELSAN::Instantaneous_Activity1Activity::Weight(){ 
  return 1;
}

bool TOTAL_MEMORY_MODELSAN::Instantaneous_Activity1Activity::ReactivationPredicate(){ 
  return false;
}

bool TOTAL_MEMORY_MODELSAN::Instantaneous_Activity1Activity::ReactivationFunction(){ 
  return false;
}

double TOTAL_MEMORY_MODELSAN::Instantaneous_Activity1Activity::SampleDistribution(){
  return 0;
}

double* TOTAL_MEMORY_MODELSAN::Instantaneous_Activity1Activity::ReturnDistributionParameters(){
    return NULL;
}

int TOTAL_MEMORY_MODELSAN::Instantaneous_Activity1Activity::Rank(){
  return 1;
}

BaseActionClass* TOTAL_MEMORY_MODELSAN::Instantaneous_Activity1Activity::Fire(){
  (*(MEMORY_OK_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  (*(OK_READ_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity2Activity========================*/


TOTAL_MEMORY_MODELSAN::Instantaneous_Activity2Activity::Instantaneous_Activity2Activity(){
  ActivityInitialize("Instantaneous_Activity2",2,Instantaneous , RaceEnabled, 3,1, false);
}

void TOTAL_MEMORY_MODELSAN::Instantaneous_Activity2Activity::LinkVariables(){
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
  KO_READ->Register(&KO_READ_Mobius_Mark);
}

bool TOTAL_MEMORY_MODELSAN::Instantaneous_Activity2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEMORY_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double TOTAL_MEMORY_MODELSAN::Instantaneous_Activity2Activity::Weight(){ 
  return 1;
}

bool TOTAL_MEMORY_MODELSAN::Instantaneous_Activity2Activity::ReactivationPredicate(){ 
  return false;
}

bool TOTAL_MEMORY_MODELSAN::Instantaneous_Activity2Activity::ReactivationFunction(){ 
  return false;
}

double TOTAL_MEMORY_MODELSAN::Instantaneous_Activity2Activity::SampleDistribution(){
  return 0;
}

double* TOTAL_MEMORY_MODELSAN::Instantaneous_Activity2Activity::ReturnDistributionParameters(){
    return NULL;
}

int TOTAL_MEMORY_MODELSAN::Instantaneous_Activity2Activity::Rank(){
  return 1;
}

BaseActionClass* TOTAL_MEMORY_MODELSAN::Instantaneous_Activity2Activity::Fire(){
  (*(MEMORY_KO_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  (*(KO_READ_Mobius_Mark))++;
  return this;
}

