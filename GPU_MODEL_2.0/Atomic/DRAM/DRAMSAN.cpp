

// This C++ file was created by SanEditor

#include "Atomic/DRAM/DRAMSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         DRAMSAN Constructor             
******************************************************************/


DRAMSAN::DRAMSAN(){


  READ_FROMGroup.initialize(2, "READ_FROMGroup");
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case1);
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case2);

  Instantaneous_Activity3Group.initialize(2, "Instantaneous_Activity3Group");
  Instantaneous_Activity3Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity3_case1);
  Instantaneous_Activity3Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity3_case2);

  Activity* InitialActionList[10]={
    &Instantaneous_Activity23, //0
    &WRITE_WITH_KO_DATA, //1
    &Instantaneous_Activity12, //2
    &WRITE_WITH_OK_DATA, //3
    &Instantaneous_Activity2, //4
    &READ_FROM_case1, //5
    &READ_FROM_case2, //6
    &Instantaneous_Activity1, //7
    &Instantaneous_Activity3_case1, //8
    &Instantaneous_Activity3_case2  // 9
  };

  BaseGroupClass* InitialGroupList[8]={
    (BaseGroupClass*) &(Instantaneous_Activity23), 
    (BaseGroupClass*) &(WRITE_WITH_KO_DATA), 
    (BaseGroupClass*) &(Instantaneous_Activity12), 
    (BaseGroupClass*) &(WRITE_WITH_OK_DATA), 
    (BaseGroupClass*) &(Instantaneous_Activity2), 
    (BaseGroupClass*) &(READ_FROMGroup), 
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(Instantaneous_Activity3Group)
  };

  KO_CONTENT_TEMP = new Place("KO_CONTENT_TEMP" ,0);
  MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE" ,0);
  OK_CONTENT_TEMP = new Place("OK_CONTENT_TEMP" ,0);
  WRITE_DRAM = new Place("WRITE_DRAM" ,0);
  RESULT_OK = new Place("RESULT_OK" ,10000);
  RESULT_KO = new Place("RESULT_KO" ,10000);
  KO_READ = new Place("KO_READ" ,0);
  MEMORY_KO = new Place("MEMORY_KO" ,0);
  READ_DRAM = new Place("READ_DRAM" ,0);
  OK_READ = new Place("OK_READ" ,0);
  MEMORY_OK = new Place("MEMORY_OK" ,0);
  OK_CONTENT = new Place("OK_CONTENT" ,0);
  KO_CONTENT = new Place("KO_CONTENT" ,0);
  REPLACE_CONTENT = new Place("REPLACE_CONTENT" ,0);
  BaseStateVariableClass* InitialPlaces[14]={
    KO_CONTENT_TEMP,  // 0
    MEM_OP_COMPLETE,  // 1
    OK_CONTENT_TEMP,  // 2
    WRITE_DRAM,  // 3
    RESULT_OK,  // 4
    RESULT_KO,  // 5
    KO_READ,  // 6
    MEMORY_KO,  // 7
    READ_DRAM,  // 8
    OK_READ,  // 9
    MEMORY_OK,  // 10
    OK_CONTENT,  // 11
    KO_CONTENT,  // 12
    REPLACE_CONTENT   // 13
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("DRAM", 14, InitialPlaces, 
                        0, InitialROPlaces, 
                        10, InitialActionList, 8, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[30][2]={ 
    {0,0}, {1,0}, {3,1}, {5,1}, {0,1}, {12,1}, {2,2}, {1,2}, 
    {3,3}, {4,3}, {2,3}, {11,3}, {7,4}, {1,4}, {6,4}, {8,5}, 
    {10,5}, {8,6}, {7,6}, {10,7}, {1,7}, {9,7}, {13,8}, {11,8}, 
    {2,8}, {12,8}, {13,9}, {12,9}, {0,9}, {11,9}
  };
  for(int n=0;n<30;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[12][2]={ 
    {0,0}, {3,1}, {5,1}, {2,2}, {3,3}, {4,3}, {7,4}, {8,5}, {8,6}, 
    {10,7}, {13,8}, {13,9}
  };
  for(int n=0;n<12;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<10;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void DRAMSAN::CustomInitialization() {

}
DRAMSAN::~DRAMSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void DRAMSAN::assignPlacesToActivitiesInst(){
  Instantaneous_Activity23.KO_CONTENT_TEMP = (Place*) LocalStateVariables[0];
  Instantaneous_Activity23.MEM_OP_COMPLETE = (Place*) LocalStateVariables[1];
  WRITE_WITH_KO_DATA.WRITE_DRAM = (Place*) LocalStateVariables[3];
  WRITE_WITH_KO_DATA.RESULT_KO = (Place*) LocalStateVariables[5];
  WRITE_WITH_KO_DATA.KO_CONTENT_TEMP = (Place*) LocalStateVariables[0];
  WRITE_WITH_KO_DATA.KO_CONTENT = (Place*) LocalStateVariables[12];
  Instantaneous_Activity12.OK_CONTENT_TEMP = (Place*) LocalStateVariables[2];
  Instantaneous_Activity12.MEM_OP_COMPLETE = (Place*) LocalStateVariables[1];
  WRITE_WITH_OK_DATA.WRITE_DRAM = (Place*) LocalStateVariables[3];
  WRITE_WITH_OK_DATA.RESULT_OK = (Place*) LocalStateVariables[4];
  WRITE_WITH_OK_DATA.OK_CONTENT_TEMP = (Place*) LocalStateVariables[2];
  WRITE_WITH_OK_DATA.OK_CONTENT = (Place*) LocalStateVariables[11];
  Instantaneous_Activity2.MEMORY_KO = (Place*) LocalStateVariables[7];
  Instantaneous_Activity2.MEM_OP_COMPLETE = (Place*) LocalStateVariables[1];
  Instantaneous_Activity2.KO_READ = (Place*) LocalStateVariables[6];
  READ_FROM_case1.READ_DRAM = (Place*) LocalStateVariables[8];
  READ_FROM_case1.MEMORY_OK = (Place*) LocalStateVariables[10];
  READ_FROM_case2.READ_DRAM = (Place*) LocalStateVariables[8];
  READ_FROM_case2.MEMORY_KO = (Place*) LocalStateVariables[7];
  Instantaneous_Activity1.MEMORY_OK = (Place*) LocalStateVariables[10];
  Instantaneous_Activity1.MEM_OP_COMPLETE = (Place*) LocalStateVariables[1];
  Instantaneous_Activity1.OK_READ = (Place*) LocalStateVariables[9];
  Instantaneous_Activity3_case1.REPLACE_CONTENT = (Place*) LocalStateVariables[13];
  Instantaneous_Activity3_case1.OK_CONTENT = (Place*) LocalStateVariables[11];
  Instantaneous_Activity3_case1.OK_CONTENT_TEMP = (Place*) LocalStateVariables[2];
  Instantaneous_Activity3_case1.KO_CONTENT = (Place*) LocalStateVariables[12];
  Instantaneous_Activity3_case2.REPLACE_CONTENT = (Place*) LocalStateVariables[13];
  Instantaneous_Activity3_case2.KO_CONTENT = (Place*) LocalStateVariables[12];
  Instantaneous_Activity3_case2.KO_CONTENT_TEMP = (Place*) LocalStateVariables[0];
  Instantaneous_Activity3_case2.OK_CONTENT = (Place*) LocalStateVariables[11];
}
void DRAMSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================Instantaneous_Activity23Activity========================*/


DRAMSAN::Instantaneous_Activity23Activity::Instantaneous_Activity23Activity(){
  ActivityInitialize("Instantaneous_Activity23",0,Instantaneous , RaceEnabled, 2,1, false);
}

void DRAMSAN::Instantaneous_Activity23Activity::LinkVariables(){
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
}

bool DRAMSAN::Instantaneous_Activity23Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(KO_CONTENT_TEMP_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::Instantaneous_Activity23Activity::Weight(){ 
  return 1;
}

bool DRAMSAN::Instantaneous_Activity23Activity::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::Instantaneous_Activity23Activity::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::Instantaneous_Activity23Activity::SampleDistribution(){
  return 0;
}

double* DRAMSAN::Instantaneous_Activity23Activity::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::Instantaneous_Activity23Activity::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::Instantaneous_Activity23Activity::Fire(){
  (*(KO_CONTENT_TEMP_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  return this;
}

/*======================WRITE_WITH_KO_DATAActivity========================*/


DRAMSAN::WRITE_WITH_KO_DATAActivity::WRITE_WITH_KO_DATAActivity(){
  ActivityInitialize("WRITE_WITH_KO_DATA",1,Instantaneous , RaceEnabled, 4,2, false);
}

void DRAMSAN::WRITE_WITH_KO_DATAActivity::LinkVariables(){
  WRITE_DRAM->Register(&WRITE_DRAM_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
}

bool DRAMSAN::WRITE_WITH_KO_DATAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_DRAM_Mobius_Mark)) >=1)&&((*(RESULT_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::WRITE_WITH_KO_DATAActivity::Weight(){ 
  return 1;
}

bool DRAMSAN::WRITE_WITH_KO_DATAActivity::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::WRITE_WITH_KO_DATAActivity::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::WRITE_WITH_KO_DATAActivity::SampleDistribution(){
  return 0;
}

double* DRAMSAN::WRITE_WITH_KO_DATAActivity::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::WRITE_WITH_KO_DATAActivity::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::WRITE_WITH_KO_DATAActivity::Fire(){
  (*(WRITE_DRAM_Mobius_Mark))--;
  (*(RESULT_KO_Mobius_Mark))--;
  KO_CONTENT_TEMP->Mark()++;
KO_CONTENT->Mark()++;
  return this;
}

/*======================Instantaneous_Activity12Activity========================*/


DRAMSAN::Instantaneous_Activity12Activity::Instantaneous_Activity12Activity(){
  ActivityInitialize("Instantaneous_Activity12",2,Instantaneous , RaceEnabled, 2,1, false);
}

void DRAMSAN::Instantaneous_Activity12Activity::LinkVariables(){
  OK_CONTENT_TEMP->Register(&OK_CONTENT_TEMP_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
}

bool DRAMSAN::Instantaneous_Activity12Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(OK_CONTENT_TEMP_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::Instantaneous_Activity12Activity::Weight(){ 
  return 1;
}

bool DRAMSAN::Instantaneous_Activity12Activity::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::Instantaneous_Activity12Activity::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::Instantaneous_Activity12Activity::SampleDistribution(){
  return 0;
}

double* DRAMSAN::Instantaneous_Activity12Activity::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::Instantaneous_Activity12Activity::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::Instantaneous_Activity12Activity::Fire(){
  (*(OK_CONTENT_TEMP_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  return this;
}

/*======================WRITE_WITH_OK_DATAActivity========================*/


DRAMSAN::WRITE_WITH_OK_DATAActivity::WRITE_WITH_OK_DATAActivity(){
  ActivityInitialize("WRITE_WITH_OK_DATA",3,Instantaneous , RaceEnabled, 4,2, false);
}

void DRAMSAN::WRITE_WITH_OK_DATAActivity::LinkVariables(){
  WRITE_DRAM->Register(&WRITE_DRAM_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
  OK_CONTENT_TEMP->Register(&OK_CONTENT_TEMP_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
}

bool DRAMSAN::WRITE_WITH_OK_DATAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_DRAM_Mobius_Mark)) >=1)&&((*(RESULT_OK_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::WRITE_WITH_OK_DATAActivity::Weight(){ 
  return 1;
}

bool DRAMSAN::WRITE_WITH_OK_DATAActivity::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::WRITE_WITH_OK_DATAActivity::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::WRITE_WITH_OK_DATAActivity::SampleDistribution(){
  return 0;
}

double* DRAMSAN::WRITE_WITH_OK_DATAActivity::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::WRITE_WITH_OK_DATAActivity::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::WRITE_WITH_OK_DATAActivity::Fire(){
  (*(WRITE_DRAM_Mobius_Mark))--;
  (*(RESULT_OK_Mobius_Mark))--;
  OK_CONTENT_TEMP->Mark()++;
OK_CONTENT->Mark()++;
  return this;
}

/*======================Instantaneous_Activity2Activity========================*/


DRAMSAN::Instantaneous_Activity2Activity::Instantaneous_Activity2Activity(){
  ActivityInitialize("Instantaneous_Activity2",4,Instantaneous , RaceEnabled, 3,1, false);
}

void DRAMSAN::Instantaneous_Activity2Activity::LinkVariables(){
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
  KO_READ->Register(&KO_READ_Mobius_Mark);
}

bool DRAMSAN::Instantaneous_Activity2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEMORY_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::Instantaneous_Activity2Activity::Weight(){ 
  return 1;
}

bool DRAMSAN::Instantaneous_Activity2Activity::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::Instantaneous_Activity2Activity::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::Instantaneous_Activity2Activity::SampleDistribution(){
  return 0;
}

double* DRAMSAN::Instantaneous_Activity2Activity::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::Instantaneous_Activity2Activity::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::Instantaneous_Activity2Activity::Fire(){
  (*(MEMORY_KO_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  (*(KO_READ_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case1========================*/


DRAMSAN::READ_FROMActivity_case1::READ_FROMActivity_case1(){
  ActivityInitialize("READ_FROM_case1",5,Instantaneous , RaceEnabled, 2,1, false);
}

void DRAMSAN::READ_FROMActivity_case1::LinkVariables(){
  READ_DRAM->Register(&READ_DRAM_Mobius_Mark);
  MEMORY_OK->Register(&MEMORY_OK_Mobius_Mark);
}

bool DRAMSAN::READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_DRAM_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::READ_FROMActivity_case1::Weight(){ 
  return 0.5;
}

bool DRAMSAN::READ_FROMActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::READ_FROMActivity_case1::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::READ_FROMActivity_case1::SampleDistribution(){
  return 0;
}

double* DRAMSAN::READ_FROMActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::READ_FROMActivity_case1::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::READ_FROMActivity_case1::Fire(){
  (*(READ_DRAM_Mobius_Mark))--;
  (*(MEMORY_OK_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case2========================*/


DRAMSAN::READ_FROMActivity_case2::READ_FROMActivity_case2(){
  ActivityInitialize("READ_FROM_case2",5,Instantaneous , RaceEnabled, 2,1, false);
}

void DRAMSAN::READ_FROMActivity_case2::LinkVariables(){
  READ_DRAM->Register(&READ_DRAM_Mobius_Mark);
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
}

bool DRAMSAN::READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_DRAM_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::READ_FROMActivity_case2::Weight(){ 
  return 0.5;
}

bool DRAMSAN::READ_FROMActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::READ_FROMActivity_case2::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::READ_FROMActivity_case2::SampleDistribution(){
  return 0;
}

double* DRAMSAN::READ_FROMActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::READ_FROMActivity_case2::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::READ_FROMActivity_case2::Fire(){
  (*(READ_DRAM_Mobius_Mark))--;
  (*(MEMORY_KO_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity1Activity========================*/


DRAMSAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",6,Instantaneous , RaceEnabled, 3,1, false);
}

void DRAMSAN::Instantaneous_Activity1Activity::LinkVariables(){
  MEMORY_OK->Register(&MEMORY_OK_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
  OK_READ->Register(&OK_READ_Mobius_Mark);
}

bool DRAMSAN::Instantaneous_Activity1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEMORY_OK_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::Instantaneous_Activity1Activity::Weight(){ 
  return 1;
}

bool DRAMSAN::Instantaneous_Activity1Activity::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::Instantaneous_Activity1Activity::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::Instantaneous_Activity1Activity::SampleDistribution(){
  return 0;
}

double* DRAMSAN::Instantaneous_Activity1Activity::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::Instantaneous_Activity1Activity::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::Instantaneous_Activity1Activity::Fire(){
  (*(MEMORY_OK_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  (*(OK_READ_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity3Activity_case1========================*/


DRAMSAN::Instantaneous_Activity3Activity_case1::Instantaneous_Activity3Activity_case1(){
  ActivityInitialize("Instantaneous_Activity3_case1",7,Instantaneous , RaceEnabled, 4,1, false);
}

void DRAMSAN::Instantaneous_Activity3Activity_case1::LinkVariables(){
  REPLACE_CONTENT->Register(&REPLACE_CONTENT_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  OK_CONTENT_TEMP->Register(&OK_CONTENT_TEMP_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
}

bool DRAMSAN::Instantaneous_Activity3Activity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(REPLACE_CONTENT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::Instantaneous_Activity3Activity_case1::Weight(){ 
  return 1;
}

bool DRAMSAN::Instantaneous_Activity3Activity_case1::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::Instantaneous_Activity3Activity_case1::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::Instantaneous_Activity3Activity_case1::SampleDistribution(){
  return 0;
}

double* DRAMSAN::Instantaneous_Activity3Activity_case1::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::Instantaneous_Activity3Activity_case1::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::Instantaneous_Activity3Activity_case1::Fire(){
  (*(REPLACE_CONTENT_Mobius_Mark))--;
  OK_CONTENT->Mark()++;
OK_CONTENT_TEMP->Mark()++;
if (KO_CONTENT->Mark() > 0) {
	KO_CONTENT->Mark()--;
}
  return this;
}

/*======================Instantaneous_Activity3Activity_case2========================*/


DRAMSAN::Instantaneous_Activity3Activity_case2::Instantaneous_Activity3Activity_case2(){
  ActivityInitialize("Instantaneous_Activity3_case2",7,Instantaneous , RaceEnabled, 4,1, false);
}

void DRAMSAN::Instantaneous_Activity3Activity_case2::LinkVariables(){
  REPLACE_CONTENT->Register(&REPLACE_CONTENT_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
}

bool DRAMSAN::Instantaneous_Activity3Activity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(REPLACE_CONTENT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::Instantaneous_Activity3Activity_case2::Weight(){ 
  return 1;
}

bool DRAMSAN::Instantaneous_Activity3Activity_case2::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::Instantaneous_Activity3Activity_case2::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::Instantaneous_Activity3Activity_case2::SampleDistribution(){
  return 0;
}

double* DRAMSAN::Instantaneous_Activity3Activity_case2::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::Instantaneous_Activity3Activity_case2::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::Instantaneous_Activity3Activity_case2::Fire(){
  (*(REPLACE_CONTENT_Mobius_Mark))--;
  KO_CONTENT->Mark()++;
KO_CONTENT_TEMP->Mark()++;
if (OK_CONTENT->Mark() > 0) {
	OK_CONTENT->Mark()--;
}
  return this;
}

