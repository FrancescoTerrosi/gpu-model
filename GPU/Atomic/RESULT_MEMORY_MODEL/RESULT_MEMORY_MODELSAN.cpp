

// This C++ file was created by SanEditor

#include "Atomic/RESULT_MEMORY_MODEL/RESULT_MEMORY_MODELSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         RESULT_MEMORY_MODELSAN Constructor             
******************************************************************/


RESULT_MEMORY_MODELSAN::RESULT_MEMORY_MODELSAN(){


  READ_FROMGroup.initialize(2, "READ_FROMGroup");
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case1);
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case2);

  Activity* InitialActionList[8]={
    &READ_FROM_case1, //0
    &READ_FROM_case2, //1
    &WRITE_OK, //2
    &WRITE_KO, //3
    &Instantaneous_Activity1, //4
    &Instantaneous_Activity2, //5
    &Instantaneous_Activity3, //6
    &Instantaneous_Activity4  // 7
  };

  BaseGroupClass* InitialGroupList[7]={
    (BaseGroupClass*) &(READ_FROMGroup), 
    (BaseGroupClass*) &(WRITE_OK), 
    (BaseGroupClass*) &(WRITE_KO), 
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(Instantaneous_Activity2), 
    (BaseGroupClass*) &(Instantaneous_Activity3), 
    (BaseGroupClass*) &(Instantaneous_Activity4)
  };

  WRITE_RESULT_MEMORY = new Place("WRITE_RESULT_MEMORY" ,0);
  OK_CONTENT = new Place("OK_CONTENT" ,0);
  KO_CONTENT = new Place("KO_CONTENT" ,0);
  READ_RESULT_MEMORY = new Place("READ_RESULT_MEMORY" ,0);
  MEMORY_OK = new Place("MEMORY_OK" ,0);
  MEMORY_KO = new Place("MEMORY_KO" ,0);
  RESULT_OK = new Place("RESULT_OK" ,0);
  RESULT_KO = new Place("RESULT_KO" ,0);
  MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE" ,0);
  OK_READ = new Place("OK_READ" ,0);
  KO_READ = new Place("KO_READ" ,0);
  BaseStateVariableClass* InitialPlaces[11]={
    WRITE_RESULT_MEMORY,  // 0
    OK_CONTENT,  // 1
    KO_CONTENT,  // 2
    READ_RESULT_MEMORY,  // 3
    MEMORY_OK,  // 4
    MEMORY_KO,  // 5
    RESULT_OK,  // 6
    RESULT_KO,  // 7
    MEM_OP_COMPLETE,  // 8
    OK_READ,  // 9
    KO_READ   // 10
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("RESULT_MEMORY_MODEL", 11, InitialPlaces, 
                        0, InitialROPlaces, 
                        8, InitialActionList, 7, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[20][2]={ 
    {3,0}, {4,0}, {3,1}, {5,1}, {0,2}, {6,2}, {1,2}, {0,3}, {7,3}, 
    {2,3}, {1,4}, {8,4}, {2,5}, {8,5}, {4,6}, {8,6}, {9,6}, {5,7}, 
    {8,7}, {10,7}
  };
  for(int n=0;n<20;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[10][2]={ 
    {3,0}, {3,1}, {0,2}, {6,2}, {0,3}, {7,3}, {1,4}, {2,5}, {4,6}, 
    {5,7}
  };
  for(int n=0;n<10;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<8;n++) {
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
  READ_FROM_case1.READ_RESULT_MEMORY = (Place*) LocalStateVariables[3];
  READ_FROM_case1.MEMORY_OK = (Place*) LocalStateVariables[4];
  READ_FROM_case2.READ_RESULT_MEMORY = (Place*) LocalStateVariables[3];
  READ_FROM_case2.MEMORY_KO = (Place*) LocalStateVariables[5];
  WRITE_OK.WRITE_RESULT_MEMORY = (Place*) LocalStateVariables[0];
  WRITE_OK.RESULT_OK = (Place*) LocalStateVariables[6];
  WRITE_OK.OK_CONTENT = (Place*) LocalStateVariables[1];
  WRITE_KO.WRITE_RESULT_MEMORY = (Place*) LocalStateVariables[0];
  WRITE_KO.RESULT_KO = (Place*) LocalStateVariables[7];
  WRITE_KO.KO_CONTENT = (Place*) LocalStateVariables[2];
  Instantaneous_Activity1.OK_CONTENT = (Place*) LocalStateVariables[1];
  Instantaneous_Activity1.MEM_OP_COMPLETE = (Place*) LocalStateVariables[8];
  Instantaneous_Activity2.KO_CONTENT = (Place*) LocalStateVariables[2];
  Instantaneous_Activity2.MEM_OP_COMPLETE = (Place*) LocalStateVariables[8];
  Instantaneous_Activity3.MEMORY_OK = (Place*) LocalStateVariables[4];
  Instantaneous_Activity3.MEM_OP_COMPLETE = (Place*) LocalStateVariables[8];
  Instantaneous_Activity3.OK_READ = (Place*) LocalStateVariables[9];
  Instantaneous_Activity4.MEMORY_KO = (Place*) LocalStateVariables[5];
  Instantaneous_Activity4.MEM_OP_COMPLETE = (Place*) LocalStateVariables[8];
  Instantaneous_Activity4.KO_READ = (Place*) LocalStateVariables[10];
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
  MEMORY_OK->Register(&MEMORY_OK_Mobius_Mark);
}

bool RESULT_MEMORY_MODELSAN::READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double RESULT_MEMORY_MODELSAN::READ_FROMActivity_case1::Weight(){ 
  return 0.5;
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
  (*(MEMORY_OK_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case2========================*/


RESULT_MEMORY_MODELSAN::READ_FROMActivity_case2::READ_FROMActivity_case2(){
  ActivityInitialize("READ_FROM_case2",0,Instantaneous , RaceEnabled, 2,1, false);
}

void RESULT_MEMORY_MODELSAN::READ_FROMActivity_case2::LinkVariables(){
  READ_RESULT_MEMORY->Register(&READ_RESULT_MEMORY_Mobius_Mark);
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
}

bool RESULT_MEMORY_MODELSAN::READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double RESULT_MEMORY_MODELSAN::READ_FROMActivity_case2::Weight(){ 
  return 0.5;
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
  (*(MEMORY_KO_Mobius_Mark))++;
  return this;
}

/*======================WRITE_OKActivity========================*/


RESULT_MEMORY_MODELSAN::WRITE_OKActivity::WRITE_OKActivity(){
  ActivityInitialize("WRITE_OK",1,Instantaneous , RaceEnabled, 3,2, false);
}

void RESULT_MEMORY_MODELSAN::WRITE_OKActivity::LinkVariables(){
  WRITE_RESULT_MEMORY->Register(&WRITE_RESULT_MEMORY_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
}

bool RESULT_MEMORY_MODELSAN::WRITE_OKActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_RESULT_MEMORY_Mobius_Mark)) >=1)&&((*(RESULT_OK_Mobius_Mark)) >=1));
  return NewEnabled;
}

double RESULT_MEMORY_MODELSAN::WRITE_OKActivity::Weight(){ 
  return 1;
}

bool RESULT_MEMORY_MODELSAN::WRITE_OKActivity::ReactivationPredicate(){ 
  return false;
}

bool RESULT_MEMORY_MODELSAN::WRITE_OKActivity::ReactivationFunction(){ 
  return false;
}

double RESULT_MEMORY_MODELSAN::WRITE_OKActivity::SampleDistribution(){
  return 0;
}

double* RESULT_MEMORY_MODELSAN::WRITE_OKActivity::ReturnDistributionParameters(){
    return NULL;
}

int RESULT_MEMORY_MODELSAN::WRITE_OKActivity::Rank(){
  return 1;
}

BaseActionClass* RESULT_MEMORY_MODELSAN::WRITE_OKActivity::Fire(){
  (*(WRITE_RESULT_MEMORY_Mobius_Mark))--;
  (*(RESULT_OK_Mobius_Mark))--;
  (*(OK_CONTENT_Mobius_Mark))++;
  return this;
}

/*======================WRITE_KOActivity========================*/


RESULT_MEMORY_MODELSAN::WRITE_KOActivity::WRITE_KOActivity(){
  ActivityInitialize("WRITE_KO",2,Instantaneous , RaceEnabled, 3,2, false);
}

void RESULT_MEMORY_MODELSAN::WRITE_KOActivity::LinkVariables(){
  WRITE_RESULT_MEMORY->Register(&WRITE_RESULT_MEMORY_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
}

bool RESULT_MEMORY_MODELSAN::WRITE_KOActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_RESULT_MEMORY_Mobius_Mark)) >=1)&&((*(RESULT_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double RESULT_MEMORY_MODELSAN::WRITE_KOActivity::Weight(){ 
  return 1;
}

bool RESULT_MEMORY_MODELSAN::WRITE_KOActivity::ReactivationPredicate(){ 
  return false;
}

bool RESULT_MEMORY_MODELSAN::WRITE_KOActivity::ReactivationFunction(){ 
  return false;
}

double RESULT_MEMORY_MODELSAN::WRITE_KOActivity::SampleDistribution(){
  return 0;
}

double* RESULT_MEMORY_MODELSAN::WRITE_KOActivity::ReturnDistributionParameters(){
    return NULL;
}

int RESULT_MEMORY_MODELSAN::WRITE_KOActivity::Rank(){
  return 1;
}

BaseActionClass* RESULT_MEMORY_MODELSAN::WRITE_KOActivity::Fire(){
  (*(WRITE_RESULT_MEMORY_Mobius_Mark))--;
  (*(RESULT_KO_Mobius_Mark))--;
  (*(KO_CONTENT_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity1Activity========================*/


RESULT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",3,Instantaneous , RaceEnabled, 2,1, false);
}

void RESULT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::LinkVariables(){
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
}

bool RESULT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(OK_CONTENT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double RESULT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::Weight(){ 
  return 1;
}

bool RESULT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::ReactivationPredicate(){ 
  return false;
}

bool RESULT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::ReactivationFunction(){ 
  return false;
}

double RESULT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::SampleDistribution(){
  return 0;
}

double* RESULT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::ReturnDistributionParameters(){
    return NULL;
}

int RESULT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::Rank(){
  return 1;
}

BaseActionClass* RESULT_MEMORY_MODELSAN::Instantaneous_Activity1Activity::Fire(){
  (*(OK_CONTENT_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity2Activity========================*/


RESULT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::Instantaneous_Activity2Activity(){
  ActivityInitialize("Instantaneous_Activity2",4,Instantaneous , RaceEnabled, 2,1, false);
}

void RESULT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::LinkVariables(){
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
}

bool RESULT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(KO_CONTENT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double RESULT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::Weight(){ 
  return 1;
}

bool RESULT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::ReactivationPredicate(){ 
  return false;
}

bool RESULT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::ReactivationFunction(){ 
  return false;
}

double RESULT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::SampleDistribution(){
  return 0;
}

double* RESULT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::ReturnDistributionParameters(){
    return NULL;
}

int RESULT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::Rank(){
  return 1;
}

BaseActionClass* RESULT_MEMORY_MODELSAN::Instantaneous_Activity2Activity::Fire(){
  (*(KO_CONTENT_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity3Activity========================*/


RESULT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::Instantaneous_Activity3Activity(){
  ActivityInitialize("Instantaneous_Activity3",5,Instantaneous , RaceEnabled, 3,1, false);
}

void RESULT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::LinkVariables(){
  MEMORY_OK->Register(&MEMORY_OK_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
  OK_READ->Register(&OK_READ_Mobius_Mark);
}

bool RESULT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEMORY_OK_Mobius_Mark)) >=1));
  return NewEnabled;
}

double RESULT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::Weight(){ 
  return 1;
}

bool RESULT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::ReactivationPredicate(){ 
  return false;
}

bool RESULT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::ReactivationFunction(){ 
  return false;
}

double RESULT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::SampleDistribution(){
  return 0;
}

double* RESULT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::ReturnDistributionParameters(){
    return NULL;
}

int RESULT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::Rank(){
  return 1;
}

BaseActionClass* RESULT_MEMORY_MODELSAN::Instantaneous_Activity3Activity::Fire(){
  (*(MEMORY_OK_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  (*(OK_READ_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity4Activity========================*/


RESULT_MEMORY_MODELSAN::Instantaneous_Activity4Activity::Instantaneous_Activity4Activity(){
  ActivityInitialize("Instantaneous_Activity4",6,Instantaneous , RaceEnabled, 3,1, false);
}

void RESULT_MEMORY_MODELSAN::Instantaneous_Activity4Activity::LinkVariables(){
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
  KO_READ->Register(&KO_READ_Mobius_Mark);
}

bool RESULT_MEMORY_MODELSAN::Instantaneous_Activity4Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEMORY_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double RESULT_MEMORY_MODELSAN::Instantaneous_Activity4Activity::Weight(){ 
  return 1;
}

bool RESULT_MEMORY_MODELSAN::Instantaneous_Activity4Activity::ReactivationPredicate(){ 
  return false;
}

bool RESULT_MEMORY_MODELSAN::Instantaneous_Activity4Activity::ReactivationFunction(){ 
  return false;
}

double RESULT_MEMORY_MODELSAN::Instantaneous_Activity4Activity::SampleDistribution(){
  return 0;
}

double* RESULT_MEMORY_MODELSAN::Instantaneous_Activity4Activity::ReturnDistributionParameters(){
    return NULL;
}

int RESULT_MEMORY_MODELSAN::Instantaneous_Activity4Activity::Rank(){
  return 1;
}

BaseActionClass* RESULT_MEMORY_MODELSAN::Instantaneous_Activity4Activity::Fire(){
  (*(MEMORY_KO_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  (*(KO_READ_Mobius_Mark))++;
  return this;
}

