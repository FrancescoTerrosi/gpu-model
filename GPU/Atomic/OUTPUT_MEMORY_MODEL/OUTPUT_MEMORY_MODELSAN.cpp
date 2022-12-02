

// This C++ file was created by SanEditor

#include "Atomic/OUTPUT_MEMORY_MODEL/OUTPUT_MEMORY_MODELSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         OUTPUT_MEMORY_MODELSAN Constructor             
******************************************************************/


OUTPUT_MEMORY_MODELSAN::OUTPUT_MEMORY_MODELSAN(){


  Activity* InitialActionList[4]={
    &Instantaneous_Activity1, //0
    &Instantaneous_Activity2, //1
    &Instantaneous_Activity12, //2
    &Instantaneous_Activity3  // 3
  };

  BaseGroupClass* InitialGroupList[4]={
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(Instantaneous_Activity2), 
    (BaseGroupClass*) &(Instantaneous_Activity12), 
    (BaseGroupClass*) &(Instantaneous_Activity3)
  };

  WRITE_OUTPUT_MEMORY = new Place("WRITE_OUTPUT_MEMORY" ,0);
  OK_CONTENT = new Place("OK_CONTENT" ,0);
  KO_CONTENT = new Place("KO_CONTENT" ,0);
  MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE" ,0);
  RESULT_OK = new Place("RESULT_OK" ,0);
  RESULT_KO = new Place("RESULT_KO" ,0);
  BaseStateVariableClass* InitialPlaces[6]={
    WRITE_OUTPUT_MEMORY,  // 0
    OK_CONTENT,  // 1
    KO_CONTENT,  // 2
    MEM_OP_COMPLETE,  // 3
    RESULT_OK,  // 4
    RESULT_KO   // 5
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("OUTPUT_MEMORY_MODEL", 6, InitialPlaces, 
                        0, InitialROPlaces, 
                        4, InitialActionList, 4, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[10][2]={ 
    {1,0}, {3,0}, {2,1}, {3,1}, {4,2}, {0,2}, {1,2}, {0,3}, {5,3}, 
    {2,3}
  };
  for(int n=0;n<10;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[6][2]={ 
    {1,0}, {2,1}, {4,2}, {0,2}, {0,3}, {5,3}
  };
  for(int n=0;n<6;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<4;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void OUTPUT_MEMORY_MODELSAN::CustomInitialization() {

}
OUTPUT_MEMORY_MODELSAN::~OUTPUT_MEMORY_MODELSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void OUTPUT_MEMORY_MODELSAN::assignPlacesToActivitiesInst(){
  Instantaneous_Activity1.OK_CONTENT = (Place*) LocalStateVariables[1];
  Instantaneous_Activity1.MEM_OP_COMPLETE = (Place*) LocalStateVariables[3];
  Instantaneous_Activity2.KO_CONTENT = (Place*) LocalStateVariables[2];
  Instantaneous_Activity2.MEM_OP_COMPLETE = (Place*) LocalStateVariables[3];
  Instantaneous_Activity12.RESULT_OK = (Place*) LocalStateVariables[4];
  Instantaneous_Activity12.WRITE_OUTPUT_MEMORY = (Place*) LocalStateVariables[0];
  Instantaneous_Activity12.OK_CONTENT = (Place*) LocalStateVariables[1];
  Instantaneous_Activity3.WRITE_OUTPUT_MEMORY = (Place*) LocalStateVariables[0];
  Instantaneous_Activity3.RESULT_KO = (Place*) LocalStateVariables[5];
  Instantaneous_Activity3.KO_CONTENT = (Place*) LocalStateVariables[2];
}
void OUTPUT_MEMORY_MODELSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================Instantaneous_Activity1Activity========================*/


OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",0,Instantaneous , RaceEnabled, 2,1, false);
}

void OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::LinkVariables(){
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
}

bool OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(OK_CONTENT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::Weight(){ 
  return 1;
}

bool OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::ReactivationPredicate(){ 
  return false;
}

bool OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::ReactivationFunction(){ 
  return false;
}

double OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::SampleDistribution(){
  return 0;
}

double* OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::ReturnDistributionParameters(){
    return NULL;
}

int OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::Rank(){
  return 1;
}

BaseActionClass* OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::Fire(){
  (*(OK_CONTENT_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity2Activity========================*/


OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::Instantaneous_Activity2Activity(){
  ActivityInitialize("Instantaneous_Activity2",1,Instantaneous , RaceEnabled, 2,1, false);
}

void OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::LinkVariables(){
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
}

bool OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(KO_CONTENT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::Weight(){ 
  return 1;
}

bool OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::ReactivationPredicate(){ 
  return false;
}

bool OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::ReactivationFunction(){ 
  return false;
}

double OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::SampleDistribution(){
  return 0;
}

double* OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::ReturnDistributionParameters(){
    return NULL;
}

int OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::Rank(){
  return 1;
}

BaseActionClass* OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::Fire(){
  (*(KO_CONTENT_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity12Activity========================*/


OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity12Activity::Instantaneous_Activity12Activity(){
  ActivityInitialize("Instantaneous_Activity12",2,Instantaneous , RaceEnabled, 3,2, false);
}

void OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity12Activity::LinkVariables(){
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
  WRITE_OUTPUT_MEMORY->Register(&WRITE_OUTPUT_MEMORY_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
}

bool OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity12Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(RESULT_OK_Mobius_Mark)) >=1)&&((*(WRITE_OUTPUT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity12Activity::Weight(){ 
  return 1;
}

bool OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity12Activity::ReactivationPredicate(){ 
  return false;
}

bool OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity12Activity::ReactivationFunction(){ 
  return false;
}

double OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity12Activity::SampleDistribution(){
  return 0;
}

double* OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity12Activity::ReturnDistributionParameters(){
    return NULL;
}

int OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity12Activity::Rank(){
  return 1;
}

BaseActionClass* OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity12Activity::Fire(){
  (*(RESULT_OK_Mobius_Mark))--;
  (*(WRITE_OUTPUT_MEMORY_Mobius_Mark))--;
  (*(OK_CONTENT_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity3Activity========================*/


OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::Instantaneous_Activity3Activity(){
  ActivityInitialize("Instantaneous_Activity3",3,Instantaneous , RaceEnabled, 3,2, false);
}

void OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::LinkVariables(){
  WRITE_OUTPUT_MEMORY->Register(&WRITE_OUTPUT_MEMORY_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
}

bool OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_OUTPUT_MEMORY_Mobius_Mark)) >=1)&&((*(RESULT_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::Weight(){ 
  return 1;
}

bool OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::ReactivationPredicate(){ 
  return false;
}

bool OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::ReactivationFunction(){ 
  return false;
}

double OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::SampleDistribution(){
  return 0;
}

double* OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::ReturnDistributionParameters(){
    return NULL;
}

int OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::Rank(){
  return 1;
}

BaseActionClass* OUTPUT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::Fire(){
  (*(WRITE_OUTPUT_MEMORY_Mobius_Mark))--;
  (*(RESULT_KO_Mobius_Mark))--;
  (*(KO_CONTENT_Mobius_Mark))++;
  return this;
}

