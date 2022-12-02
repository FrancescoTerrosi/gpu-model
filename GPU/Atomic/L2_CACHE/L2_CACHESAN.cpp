

// This C++ file was created by SanEditor

#include "Atomic/L2_CACHE/L2_CACHESAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         L2_CACHESAN Constructor             
******************************************************************/


L2_CACHESAN::L2_CACHESAN(){


  READ_FROMGroup.initialize(2, "READ_FROMGroup");
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case1);
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case2);

  Activity* InitialActionList[8]={
    &Instantaneous_Activity23, //0
    &Instantaneous_Activity12, //1
    &WRITE_WITH_OK_DATA, //2
    &WRITE_WITH_KO_DATA, //3
    &Instantaneous_Activity2, //4
    &READ_FROM_case1, //5
    &READ_FROM_case2, //6
    &Instantaneous_Activity1  // 7
  };

  BaseGroupClass* InitialGroupList[7]={
    (BaseGroupClass*) &(Instantaneous_Activity23), 
    (BaseGroupClass*) &(Instantaneous_Activity12), 
    (BaseGroupClass*) &(WRITE_WITH_OK_DATA), 
    (BaseGroupClass*) &(WRITE_WITH_KO_DATA), 
    (BaseGroupClass*) &(Instantaneous_Activity2), 
    (BaseGroupClass*) &(READ_FROMGroup), 
    (BaseGroupClass*) &(Instantaneous_Activity1)
  };

  KO_CONTENT = new Place("KO_CONTENT" ,0);
  MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE" ,0);
  OK_CONTENT = new Place("OK_CONTENT" ,0);
  WRITE_L2 = new Place("WRITE_L2" ,0);
  KO_READ = new Place("KO_READ" ,0);
  MEMORY_KO = new Place("MEMORY_KO" ,0);
  RESULT_KO = new Place("RESULT_KO" ,0);
  READ_L2 = new Place("READ_L2" ,0);
  RESULT_OK = new Place("RESULT_OK" ,0);
  MEMORY_OK = new Place("MEMORY_OK" ,0);
  OK_READ = new Place("OK_READ" ,0);
  BaseStateVariableClass* InitialPlaces[11]={
    KO_CONTENT,  // 0
    MEM_OP_COMPLETE,  // 1
    OK_CONTENT,  // 2
    WRITE_L2,  // 3
    KO_READ,  // 4
    MEMORY_KO,  // 5
    RESULT_KO,  // 6
    READ_L2,  // 7
    RESULT_OK,  // 8
    MEMORY_OK,  // 9
    OK_READ   // 10
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("L2_CACHE", 11, InitialPlaces, 
                        0, InitialROPlaces, 
                        8, InitialActionList, 7, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[20][2]={ 
    {0,0}, {1,0}, {2,1}, {1,1}, {8,2}, {3,2}, {2,2}, {3,3}, {6,3}, 
    {0,3}, {5,4}, {1,4}, {4,4}, {7,5}, {9,5}, {7,6}, {5,6}, {9,7}, 
    {1,7}, {10,7}
  };
  for(int n=0;n<20;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[10][2]={ 
    {0,0}, {2,1}, {8,2}, {3,2}, {3,3}, {6,3}, {5,4}, {7,5}, {7,6}, 
    {9,7}
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

void L2_CACHESAN::CustomInitialization() {

}
L2_CACHESAN::~L2_CACHESAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void L2_CACHESAN::assignPlacesToActivitiesInst(){
  Instantaneous_Activity23.KO_CONTENT = (Place*) LocalStateVariables[0];
  Instantaneous_Activity23.MEM_OP_COMPLETE = (Place*) LocalStateVariables[1];
  Instantaneous_Activity12.OK_CONTENT = (Place*) LocalStateVariables[2];
  Instantaneous_Activity12.MEM_OP_COMPLETE = (Place*) LocalStateVariables[1];
  WRITE_WITH_OK_DATA.RESULT_OK = (Place*) LocalStateVariables[8];
  WRITE_WITH_OK_DATA.WRITE_L2 = (Place*) LocalStateVariables[3];
  WRITE_WITH_OK_DATA.OK_CONTENT = (Place*) LocalStateVariables[2];
  WRITE_WITH_KO_DATA.WRITE_L2 = (Place*) LocalStateVariables[3];
  WRITE_WITH_KO_DATA.RESULT_KO = (Place*) LocalStateVariables[6];
  WRITE_WITH_KO_DATA.KO_CONTENT = (Place*) LocalStateVariables[0];
  Instantaneous_Activity2.MEMORY_KO = (Place*) LocalStateVariables[5];
  Instantaneous_Activity2.MEM_OP_COMPLETE = (Place*) LocalStateVariables[1];
  Instantaneous_Activity2.KO_READ = (Place*) LocalStateVariables[4];
  READ_FROM_case1.READ_L2 = (Place*) LocalStateVariables[7];
  READ_FROM_case1.MEMORY_OK = (Place*) LocalStateVariables[9];
  READ_FROM_case2.READ_L2 = (Place*) LocalStateVariables[7];
  READ_FROM_case2.MEMORY_KO = (Place*) LocalStateVariables[5];
  Instantaneous_Activity1.MEMORY_OK = (Place*) LocalStateVariables[9];
  Instantaneous_Activity1.MEM_OP_COMPLETE = (Place*) LocalStateVariables[1];
  Instantaneous_Activity1.OK_READ = (Place*) LocalStateVariables[10];
}
void L2_CACHESAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================Instantaneous_Activity23Activity========================*/


L2_CACHESAN::Instantaneous_Activity23Activity::Instantaneous_Activity23Activity(){
  ActivityInitialize("Instantaneous_Activity23",0,Instantaneous , RaceEnabled, 2,1, false);
}

void L2_CACHESAN::Instantaneous_Activity23Activity::LinkVariables(){
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
}

bool L2_CACHESAN::Instantaneous_Activity23Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(KO_CONTENT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L2_CACHESAN::Instantaneous_Activity23Activity::Weight(){ 
  return 1;
}

bool L2_CACHESAN::Instantaneous_Activity23Activity::ReactivationPredicate(){ 
  return false;
}

bool L2_CACHESAN::Instantaneous_Activity23Activity::ReactivationFunction(){ 
  return false;
}

double L2_CACHESAN::Instantaneous_Activity23Activity::SampleDistribution(){
  return 0;
}

double* L2_CACHESAN::Instantaneous_Activity23Activity::ReturnDistributionParameters(){
    return NULL;
}

int L2_CACHESAN::Instantaneous_Activity23Activity::Rank(){
  return 1;
}

BaseActionClass* L2_CACHESAN::Instantaneous_Activity23Activity::Fire(){
  (*(KO_CONTENT_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity12Activity========================*/


L2_CACHESAN::Instantaneous_Activity12Activity::Instantaneous_Activity12Activity(){
  ActivityInitialize("Instantaneous_Activity12",1,Instantaneous , RaceEnabled, 2,1, false);
}

void L2_CACHESAN::Instantaneous_Activity12Activity::LinkVariables(){
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
}

bool L2_CACHESAN::Instantaneous_Activity12Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(OK_CONTENT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L2_CACHESAN::Instantaneous_Activity12Activity::Weight(){ 
  return 1;
}

bool L2_CACHESAN::Instantaneous_Activity12Activity::ReactivationPredicate(){ 
  return false;
}

bool L2_CACHESAN::Instantaneous_Activity12Activity::ReactivationFunction(){ 
  return false;
}

double L2_CACHESAN::Instantaneous_Activity12Activity::SampleDistribution(){
  return 0;
}

double* L2_CACHESAN::Instantaneous_Activity12Activity::ReturnDistributionParameters(){
    return NULL;
}

int L2_CACHESAN::Instantaneous_Activity12Activity::Rank(){
  return 1;
}

BaseActionClass* L2_CACHESAN::Instantaneous_Activity12Activity::Fire(){
  (*(OK_CONTENT_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  return this;
}

/*======================WRITE_WITH_OK_DATAActivity========================*/


L2_CACHESAN::WRITE_WITH_OK_DATAActivity::WRITE_WITH_OK_DATAActivity(){
  ActivityInitialize("WRITE_WITH_OK_DATA",2,Instantaneous , RaceEnabled, 3,2, false);
}

void L2_CACHESAN::WRITE_WITH_OK_DATAActivity::LinkVariables(){
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
  WRITE_L2->Register(&WRITE_L2_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
}

bool L2_CACHESAN::WRITE_WITH_OK_DATAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(RESULT_OK_Mobius_Mark)) >=1)&&((*(WRITE_L2_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L2_CACHESAN::WRITE_WITH_OK_DATAActivity::Weight(){ 
  return 1;
}

bool L2_CACHESAN::WRITE_WITH_OK_DATAActivity::ReactivationPredicate(){ 
  return false;
}

bool L2_CACHESAN::WRITE_WITH_OK_DATAActivity::ReactivationFunction(){ 
  return false;
}

double L2_CACHESAN::WRITE_WITH_OK_DATAActivity::SampleDistribution(){
  return 0;
}

double* L2_CACHESAN::WRITE_WITH_OK_DATAActivity::ReturnDistributionParameters(){
    return NULL;
}

int L2_CACHESAN::WRITE_WITH_OK_DATAActivity::Rank(){
  return 1;
}

BaseActionClass* L2_CACHESAN::WRITE_WITH_OK_DATAActivity::Fire(){
  (*(RESULT_OK_Mobius_Mark))--;
  (*(WRITE_L2_Mobius_Mark))--;
  (*(OK_CONTENT_Mobius_Mark))++;
  return this;
}

/*======================WRITE_WITH_KO_DATAActivity========================*/


L2_CACHESAN::WRITE_WITH_KO_DATAActivity::WRITE_WITH_KO_DATAActivity(){
  ActivityInitialize("WRITE_WITH_KO_DATA",3,Instantaneous , RaceEnabled, 3,2, false);
}

void L2_CACHESAN::WRITE_WITH_KO_DATAActivity::LinkVariables(){
  WRITE_L2->Register(&WRITE_L2_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
}

bool L2_CACHESAN::WRITE_WITH_KO_DATAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_L2_Mobius_Mark)) >=1)&&((*(RESULT_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L2_CACHESAN::WRITE_WITH_KO_DATAActivity::Weight(){ 
  return 1;
}

bool L2_CACHESAN::WRITE_WITH_KO_DATAActivity::ReactivationPredicate(){ 
  return false;
}

bool L2_CACHESAN::WRITE_WITH_KO_DATAActivity::ReactivationFunction(){ 
  return false;
}

double L2_CACHESAN::WRITE_WITH_KO_DATAActivity::SampleDistribution(){
  return 0;
}

double* L2_CACHESAN::WRITE_WITH_KO_DATAActivity::ReturnDistributionParameters(){
    return NULL;
}

int L2_CACHESAN::WRITE_WITH_KO_DATAActivity::Rank(){
  return 1;
}

BaseActionClass* L2_CACHESAN::WRITE_WITH_KO_DATAActivity::Fire(){
  (*(WRITE_L2_Mobius_Mark))--;
  (*(RESULT_KO_Mobius_Mark))--;
  (*(KO_CONTENT_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity2Activity========================*/


L2_CACHESAN::Instantaneous_Activity2Activity::Instantaneous_Activity2Activity(){
  ActivityInitialize("Instantaneous_Activity2",4,Instantaneous , RaceEnabled, 3,1, false);
}

void L2_CACHESAN::Instantaneous_Activity2Activity::LinkVariables(){
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
  KO_READ->Register(&KO_READ_Mobius_Mark);
}

bool L2_CACHESAN::Instantaneous_Activity2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEMORY_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L2_CACHESAN::Instantaneous_Activity2Activity::Weight(){ 
  return 1;
}

bool L2_CACHESAN::Instantaneous_Activity2Activity::ReactivationPredicate(){ 
  return false;
}

bool L2_CACHESAN::Instantaneous_Activity2Activity::ReactivationFunction(){ 
  return false;
}

double L2_CACHESAN::Instantaneous_Activity2Activity::SampleDistribution(){
  return 0;
}

double* L2_CACHESAN::Instantaneous_Activity2Activity::ReturnDistributionParameters(){
    return NULL;
}

int L2_CACHESAN::Instantaneous_Activity2Activity::Rank(){
  return 1;
}

BaseActionClass* L2_CACHESAN::Instantaneous_Activity2Activity::Fire(){
  (*(MEMORY_KO_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  (*(KO_READ_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case1========================*/


L2_CACHESAN::READ_FROMActivity_case1::READ_FROMActivity_case1(){
  ActivityInitialize("READ_FROM_case1",5,Instantaneous , RaceEnabled, 2,1, false);
}

void L2_CACHESAN::READ_FROMActivity_case1::LinkVariables(){
  READ_L2->Register(&READ_L2_Mobius_Mark);
  MEMORY_OK->Register(&MEMORY_OK_Mobius_Mark);
}

bool L2_CACHESAN::READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_L2_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L2_CACHESAN::READ_FROMActivity_case1::Weight(){ 
  return 0.5;
}

bool L2_CACHESAN::READ_FROMActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool L2_CACHESAN::READ_FROMActivity_case1::ReactivationFunction(){ 
  return false;
}

double L2_CACHESAN::READ_FROMActivity_case1::SampleDistribution(){
  return 0;
}

double* L2_CACHESAN::READ_FROMActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int L2_CACHESAN::READ_FROMActivity_case1::Rank(){
  return 1;
}

BaseActionClass* L2_CACHESAN::READ_FROMActivity_case1::Fire(){
  (*(READ_L2_Mobius_Mark))--;
  (*(MEMORY_OK_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case2========================*/


L2_CACHESAN::READ_FROMActivity_case2::READ_FROMActivity_case2(){
  ActivityInitialize("READ_FROM_case2",5,Instantaneous , RaceEnabled, 2,1, false);
}

void L2_CACHESAN::READ_FROMActivity_case2::LinkVariables(){
  READ_L2->Register(&READ_L2_Mobius_Mark);
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
}

bool L2_CACHESAN::READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_L2_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L2_CACHESAN::READ_FROMActivity_case2::Weight(){ 
  return 0.5;
}

bool L2_CACHESAN::READ_FROMActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool L2_CACHESAN::READ_FROMActivity_case2::ReactivationFunction(){ 
  return false;
}

double L2_CACHESAN::READ_FROMActivity_case2::SampleDistribution(){
  return 0;
}

double* L2_CACHESAN::READ_FROMActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int L2_CACHESAN::READ_FROMActivity_case2::Rank(){
  return 1;
}

BaseActionClass* L2_CACHESAN::READ_FROMActivity_case2::Fire(){
  (*(READ_L2_Mobius_Mark))--;
  (*(MEMORY_KO_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity1Activity========================*/


L2_CACHESAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",6,Instantaneous , RaceEnabled, 3,1, false);
}

void L2_CACHESAN::Instantaneous_Activity1Activity::LinkVariables(){
  MEMORY_OK->Register(&MEMORY_OK_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
  OK_READ->Register(&OK_READ_Mobius_Mark);
}

bool L2_CACHESAN::Instantaneous_Activity1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEMORY_OK_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L2_CACHESAN::Instantaneous_Activity1Activity::Weight(){ 
  return 1;
}

bool L2_CACHESAN::Instantaneous_Activity1Activity::ReactivationPredicate(){ 
  return false;
}

bool L2_CACHESAN::Instantaneous_Activity1Activity::ReactivationFunction(){ 
  return false;
}

double L2_CACHESAN::Instantaneous_Activity1Activity::SampleDistribution(){
  return 0;
}

double* L2_CACHESAN::Instantaneous_Activity1Activity::ReturnDistributionParameters(){
    return NULL;
}

int L2_CACHESAN::Instantaneous_Activity1Activity::Rank(){
  return 1;
}

BaseActionClass* L2_CACHESAN::Instantaneous_Activity1Activity::Fire(){
  (*(MEMORY_OK_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  (*(OK_READ_Mobius_Mark))++;
  return this;
}

