

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

  REPLACEGroup.initialize(2, "REPLACEGroup");
  REPLACEGroup.appendGroup((BaseGroupClass*) &REPLACE_case1);
  REPLACEGroup.appendGroup((BaseGroupClass*) &REPLACE_case2);

  Activity* InitialActionList[10]={
    &Instantaneous_Activity23, //0
    &WRITE_WITH_KO_DATA, //1
    &Instantaneous_Activity12, //2
    &WRITE_WITH_OK_DATA, //3
    &Instantaneous_Activity2, //4
    &READ_FROM_case1, //5
    &READ_FROM_case2, //6
    &Instantaneous_Activity1, //7
    &REPLACE_case1, //8
    &REPLACE_case2  // 9
  };

  BaseGroupClass* InitialGroupList[8]={
    (BaseGroupClass*) &(Instantaneous_Activity23), 
    (BaseGroupClass*) &(WRITE_WITH_KO_DATA), 
    (BaseGroupClass*) &(Instantaneous_Activity12), 
    (BaseGroupClass*) &(WRITE_WITH_OK_DATA), 
    (BaseGroupClass*) &(Instantaneous_Activity2), 
    (BaseGroupClass*) &(READ_FROMGroup), 
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(REPLACEGroup)
  };

  KO_CONTENT_TEMP = new Place("KO_CONTENT_TEMP" ,0);
  WRITE_L2 = new Place("WRITE_L2" ,0);
  MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE" ,0);
  OK_CONTENT_TEMP = new Place("OK_CONTENT_TEMP" ,0);
  KO_READ = new Place("KO_READ" ,0);
  MEMORY_KO = new Place("MEMORY_KO" ,0);
  READ_L2 = new Place("READ_L2" ,0);
  MEMORY_OK = new Place("MEMORY_OK" ,0);
  OK_READ = new Place("OK_READ" ,0);
  KO_CONTENT = new Place("KO_CONTENT" ,0);
  OK_CONTENT = new Place("OK_CONTENT" ,0);
  REPLACE_CONTENT = new Place("REPLACE_CONTENT" ,0);
  MEM_FAILURE = new Place("MEM_FAILURE" ,0);
  BaseStateVariableClass* InitialPlaces[13]={
    KO_CONTENT_TEMP,  // 0
    WRITE_L2,  // 1
    MEM_OP_COMPLETE,  // 2
    OK_CONTENT_TEMP,  // 3
    KO_READ,  // 4
    MEMORY_KO,  // 5
    READ_L2,  // 6
    MEMORY_OK,  // 7
    OK_READ,  // 8
    KO_CONTENT,  // 9
    OK_CONTENT,  // 10
    REPLACE_CONTENT,  // 11
    MEM_FAILURE   // 12
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("L2_CACHE", 13, InitialPlaces, 
                        0, InitialROPlaces, 
                        10, InitialActionList, 8, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[32][2]={ 
    {0,0}, {2,0}, {1,1}, {10,1}, {9,1}, {0,1}, {11,1}, {3,2}, 
    {2,2}, {1,3}, {10,3}, {9,3}, {3,3}, {11,3}, {5,4}, {2,4}, 
    {4,4}, {6,5}, {7,5}, {6,6}, {5,6}, {7,7}, {2,7}, {8,7}, {11,8}, 
    {10,8}, {3,8}, {9,8}, {11,9}, {9,9}, {0,9}, {10,9}
  };
  for(int n=0;n<32;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[10][2]={ 
    {0,0}, {1,1}, {3,2}, {1,3}, {5,4}, {6,5}, {6,6}, {7,7}, {11,8}, 
    {11,9}
  };
  for(int n=0;n<10;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<10;n++) {
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
  Instantaneous_Activity23.KO_CONTENT_TEMP = (Place*) LocalStateVariables[0];
  Instantaneous_Activity23.MEM_OP_COMPLETE = (Place*) LocalStateVariables[2];
  WRITE_WITH_KO_DATA.WRITE_L2 = (Place*) LocalStateVariables[1];
  WRITE_WITH_KO_DATA.OK_CONTENT = (Place*) LocalStateVariables[10];
  WRITE_WITH_KO_DATA.KO_CONTENT = (Place*) LocalStateVariables[9];
  WRITE_WITH_KO_DATA.KO_CONTENT_TEMP = (Place*) LocalStateVariables[0];
  WRITE_WITH_KO_DATA.REPLACE_CONTENT = (Place*) LocalStateVariables[11];
  Instantaneous_Activity12.OK_CONTENT_TEMP = (Place*) LocalStateVariables[3];
  Instantaneous_Activity12.MEM_OP_COMPLETE = (Place*) LocalStateVariables[2];
  WRITE_WITH_OK_DATA.WRITE_L2 = (Place*) LocalStateVariables[1];
  WRITE_WITH_OK_DATA.OK_CONTENT = (Place*) LocalStateVariables[10];
  WRITE_WITH_OK_DATA.KO_CONTENT = (Place*) LocalStateVariables[9];
  WRITE_WITH_OK_DATA.OK_CONTENT_TEMP = (Place*) LocalStateVariables[3];
  WRITE_WITH_OK_DATA.REPLACE_CONTENT = (Place*) LocalStateVariables[11];
  Instantaneous_Activity2.MEMORY_KO = (Place*) LocalStateVariables[5];
  Instantaneous_Activity2.MEM_OP_COMPLETE = (Place*) LocalStateVariables[2];
  Instantaneous_Activity2.KO_READ = (Place*) LocalStateVariables[4];
  READ_FROM_case1.READ_L2 = (Place*) LocalStateVariables[6];
  READ_FROM_case1.MEMORY_OK = (Place*) LocalStateVariables[7];
  READ_FROM_case2.READ_L2 = (Place*) LocalStateVariables[6];
  READ_FROM_case2.MEMORY_KO = (Place*) LocalStateVariables[5];
  Instantaneous_Activity1.MEMORY_OK = (Place*) LocalStateVariables[7];
  Instantaneous_Activity1.MEM_OP_COMPLETE = (Place*) LocalStateVariables[2];
  Instantaneous_Activity1.OK_READ = (Place*) LocalStateVariables[8];
  REPLACE_case1.REPLACE_CONTENT = (Place*) LocalStateVariables[11];
  REPLACE_case1.OK_CONTENT = (Place*) LocalStateVariables[10];
  REPLACE_case1.OK_CONTENT_TEMP = (Place*) LocalStateVariables[3];
  REPLACE_case1.KO_CONTENT = (Place*) LocalStateVariables[9];
  REPLACE_case2.REPLACE_CONTENT = (Place*) LocalStateVariables[11];
  REPLACE_case2.KO_CONTENT = (Place*) LocalStateVariables[9];
  REPLACE_case2.KO_CONTENT_TEMP = (Place*) LocalStateVariables[0];
  REPLACE_case2.OK_CONTENT = (Place*) LocalStateVariables[10];
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
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
}

bool L2_CACHESAN::Instantaneous_Activity23Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(KO_CONTENT_TEMP_Mobius_Mark)) >=1));
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
  (*(KO_CONTENT_TEMP_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  return this;
}

/*======================WRITE_WITH_KO_DATAActivity========================*/


L2_CACHESAN::WRITE_WITH_KO_DATAActivity::WRITE_WITH_KO_DATAActivity(){
  ActivityInitialize("WRITE_WITH_KO_DATA",1,Instantaneous , RaceEnabled, 5,1, false);
}

void L2_CACHESAN::WRITE_WITH_KO_DATAActivity::LinkVariables(){
  WRITE_L2->Register(&WRITE_L2_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  REPLACE_CONTENT->Register(&REPLACE_CONTENT_Mobius_Mark);
}

bool L2_CACHESAN::WRITE_WITH_KO_DATAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_L2_Mobius_Mark)) >=1));
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
  if (OK_CONTENT->Mark() + KO_CONTENT->Mark() < l2_size) {
	KO_CONTENT_TEMP->Mark()++;
	KO_CONTENT->Mark()++;
} else {
	REPLACE_CONTENT->Mark()++;
}
  return this;
}

/*======================Instantaneous_Activity12Activity========================*/


L2_CACHESAN::Instantaneous_Activity12Activity::Instantaneous_Activity12Activity(){
  ActivityInitialize("Instantaneous_Activity12",2,Instantaneous , RaceEnabled, 2,1, false);
}

void L2_CACHESAN::Instantaneous_Activity12Activity::LinkVariables(){
  OK_CONTENT_TEMP->Register(&OK_CONTENT_TEMP_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
}

bool L2_CACHESAN::Instantaneous_Activity12Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(OK_CONTENT_TEMP_Mobius_Mark)) >=1));
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
  (*(OK_CONTENT_TEMP_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  return this;
}

/*======================WRITE_WITH_OK_DATAActivity========================*/


L2_CACHESAN::WRITE_WITH_OK_DATAActivity::WRITE_WITH_OK_DATAActivity(){
  ActivityInitialize("WRITE_WITH_OK_DATA",3,Instantaneous , RaceEnabled, 5,1, false);
}

void L2_CACHESAN::WRITE_WITH_OK_DATAActivity::LinkVariables(){
  WRITE_L2->Register(&WRITE_L2_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  OK_CONTENT_TEMP->Register(&OK_CONTENT_TEMP_Mobius_Mark);
  REPLACE_CONTENT->Register(&REPLACE_CONTENT_Mobius_Mark);
}

bool L2_CACHESAN::WRITE_WITH_OK_DATAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_L2_Mobius_Mark)) >=1));
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
  (*(WRITE_L2_Mobius_Mark))--;
  if (OK_CONTENT->Mark() + KO_CONTENT->Mark() < l2_size) {
	OK_CONTENT->Mark()++;
	OK_CONTENT_TEMP->Mark()++;
} else {
	REPLACE_CONTENT->Mark()++;
}
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

/*======================REPLACEActivity_case1========================*/


L2_CACHESAN::REPLACEActivity_case1::REPLACEActivity_case1(){
  ActivityInitialize("REPLACE_case1",7,Instantaneous , RaceEnabled, 4,1, false);
}

void L2_CACHESAN::REPLACEActivity_case1::LinkVariables(){
  REPLACE_CONTENT->Register(&REPLACE_CONTENT_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  OK_CONTENT_TEMP->Register(&OK_CONTENT_TEMP_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
}

bool L2_CACHESAN::REPLACEActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(REPLACE_CONTENT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L2_CACHESAN::REPLACEActivity_case1::Weight(){ 
  return 1;
}

bool L2_CACHESAN::REPLACEActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool L2_CACHESAN::REPLACEActivity_case1::ReactivationFunction(){ 
  return false;
}

double L2_CACHESAN::REPLACEActivity_case1::SampleDistribution(){
  return 0;
}

double* L2_CACHESAN::REPLACEActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int L2_CACHESAN::REPLACEActivity_case1::Rank(){
  return 1;
}

BaseActionClass* L2_CACHESAN::REPLACEActivity_case1::Fire(){
  (*(REPLACE_CONTENT_Mobius_Mark))--;
  OK_CONTENT->Mark()++;
OK_CONTENT_TEMP->Mark()++;
if (KO_CONTENT->Mark() > 0) {
	KO_CONTENT->Mark()--;
}
  return this;
}

/*======================REPLACEActivity_case2========================*/


L2_CACHESAN::REPLACEActivity_case2::REPLACEActivity_case2(){
  ActivityInitialize("REPLACE_case2",7,Instantaneous , RaceEnabled, 4,1, false);
}

void L2_CACHESAN::REPLACEActivity_case2::LinkVariables(){
  REPLACE_CONTENT->Register(&REPLACE_CONTENT_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
}

bool L2_CACHESAN::REPLACEActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(REPLACE_CONTENT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L2_CACHESAN::REPLACEActivity_case2::Weight(){ 
  return 1;
}

bool L2_CACHESAN::REPLACEActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool L2_CACHESAN::REPLACEActivity_case2::ReactivationFunction(){ 
  return false;
}

double L2_CACHESAN::REPLACEActivity_case2::SampleDistribution(){
  return 0;
}

double* L2_CACHESAN::REPLACEActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int L2_CACHESAN::REPLACEActivity_case2::Rank(){
  return 1;
}

BaseActionClass* L2_CACHESAN::REPLACEActivity_case2::Fire(){
  (*(REPLACE_CONTENT_Mobius_Mark))--;
  KO_CONTENT->Mark()++;
KO_CONTENT_TEMP->Mark()++;
if (OK_CONTENT->Mark() > 0) {
	OK_CONTENT->Mark()--;
}
  return this;
}

