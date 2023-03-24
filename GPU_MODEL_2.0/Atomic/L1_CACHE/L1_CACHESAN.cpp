

// This C++ file was created by SanEditor

#include "Atomic/L1_CACHE/L1_CACHESAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         L1_CACHESAN Constructor             
******************************************************************/


L1_CACHESAN::L1_CACHESAN(){


  READ_FROMGroup.initialize(2, "READ_FROMGroup");
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case1);
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case2);

  REPLACEGroup.initialize(2, "REPLACEGroup");
  REPLACEGroup.appendGroup((BaseGroupClass*) &REPLACE_case1);
  REPLACEGroup.appendGroup((BaseGroupClass*) &REPLACE_case2);

  Instantaneous_Activity3Group.initialize(2, "Instantaneous_Activity3Group");
  Instantaneous_Activity3Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity3_case1);
  Instantaneous_Activity3Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity3_case2);

  Instantaneous_Activity4Group.initialize(2, "Instantaneous_Activity4Group");
  Instantaneous_Activity4Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity4_case1);
  Instantaneous_Activity4Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity4_case2);

  Activity* InitialActionList[12]={
    &Instantaneous_Activity23, //0
    &Instantaneous_Activity12, //1
    &Instantaneous_Activity2, //2
    &READ_FROM_case1, //3
    &READ_FROM_case2, //4
    &Instantaneous_Activity1, //5
    &REPLACE_case1, //6
    &REPLACE_case2, //7
    &Instantaneous_Activity3_case1, //8
    &Instantaneous_Activity3_case2, //9
    &Instantaneous_Activity4_case1, //10
    &Instantaneous_Activity4_case2  // 11
  };

  BaseGroupClass* InitialGroupList[8]={
    (BaseGroupClass*) &(Instantaneous_Activity23), 
    (BaseGroupClass*) &(Instantaneous_Activity12), 
    (BaseGroupClass*) &(Instantaneous_Activity2), 
    (BaseGroupClass*) &(READ_FROMGroup), 
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(REPLACEGroup), 
    (BaseGroupClass*) &(Instantaneous_Activity3Group), 
    (BaseGroupClass*) &(Instantaneous_Activity4Group)
  };

  KO_CONTENT_TEMP = new Place("KO_CONTENT_TEMP" ,0);
  WRITE_L1 = new Place("WRITE_L1" ,0);
  MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE" ,0);
  OK_CONTENT_TEMP = new Place("OK_CONTENT_TEMP" ,0);
  KO_READ = new Place("KO_READ" ,0);
  MEMORY_KO = new Place("MEMORY_KO" ,0);
  READ_L1 = new Place("READ_L1" ,0);
  MEMORY_OK = new Place("MEMORY_OK" ,0);
  OK_READ = new Place("OK_READ" ,0);
  OK_CONTENT = new Place("OK_CONTENT" ,0);
  KO_CONTENT = new Place("KO_CONTENT" ,0);
  REPLACE_CONTENT_OK = new Place("REPLACE_CONTENT_OK" ,0);
  MEM_FAILURE = new Place("MEM_FAILURE" ,0);
  REPLACE_CONTENT_KO = new Place("REPLACE_CONTENT_KO" ,0);
  BaseStateVariableClass* InitialPlaces[14]={
    KO_CONTENT_TEMP,  // 0
    WRITE_L1,  // 1
    MEM_OP_COMPLETE,  // 2
    OK_CONTENT_TEMP,  // 3
    KO_READ,  // 4
    MEMORY_KO,  // 5
    READ_L1,  // 6
    MEMORY_OK,  // 7
    OK_READ,  // 8
    OK_CONTENT,  // 9
    KO_CONTENT,  // 10
    REPLACE_CONTENT_OK,  // 11
    MEM_FAILURE,  // 12
    REPLACE_CONTENT_KO   // 13
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("L1_CACHE", 14, InitialPlaces, 
                        0, InitialROPlaces, 
                        12, InitialActionList, 8, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[36][2]={ 
    {0,0}, {2,0}, {3,1}, {2,1}, {5,2}, {2,2}, {4,2}, {6,3}, {7,3}, 
    {6,4}, {5,4}, {7,5}, {2,5}, {8,5}, {11,6}, {3,6}, {11,7}, 
    {3,7}, {9,7}, {10,7}, {1,8}, {9,8}, {10,8}, {3,8}, {11,8}, 
    {1,9}, {9,9}, {10,9}, {0,9}, {13,9}, {13,10}, {3,10}, {13,11}, 
    {0,11}, {10,11}, {9,11}
  };
  for(int n=0;n<36;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[12][2]={ 
    {0,0}, {3,1}, {5,2}, {6,3}, {6,4}, {7,5}, {11,6}, {11,7}, 
    {1,8}, {1,9}, {13,10}, {13,11}
  };
  for(int n=0;n<12;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<12;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void L1_CACHESAN::CustomInitialization() {

}
L1_CACHESAN::~L1_CACHESAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void L1_CACHESAN::assignPlacesToActivitiesInst(){
  Instantaneous_Activity23.KO_CONTENT_TEMP = (Place*) LocalStateVariables[0];
  Instantaneous_Activity23.MEM_OP_COMPLETE = (Place*) LocalStateVariables[2];
  Instantaneous_Activity12.OK_CONTENT_TEMP = (Place*) LocalStateVariables[3];
  Instantaneous_Activity12.MEM_OP_COMPLETE = (Place*) LocalStateVariables[2];
  Instantaneous_Activity2.MEMORY_KO = (Place*) LocalStateVariables[5];
  Instantaneous_Activity2.MEM_OP_COMPLETE = (Place*) LocalStateVariables[2];
  Instantaneous_Activity2.KO_READ = (Place*) LocalStateVariables[4];
  READ_FROM_case1.READ_L1 = (Place*) LocalStateVariables[6];
  READ_FROM_case1.MEMORY_OK = (Place*) LocalStateVariables[7];
  READ_FROM_case2.READ_L1 = (Place*) LocalStateVariables[6];
  READ_FROM_case2.MEMORY_KO = (Place*) LocalStateVariables[5];
  Instantaneous_Activity1.MEMORY_OK = (Place*) LocalStateVariables[7];
  Instantaneous_Activity1.MEM_OP_COMPLETE = (Place*) LocalStateVariables[2];
  Instantaneous_Activity1.OK_READ = (Place*) LocalStateVariables[8];
  REPLACE_case1.REPLACE_CONTENT_OK = (Place*) LocalStateVariables[11];
  REPLACE_case1.OK_CONTENT_TEMP = (Place*) LocalStateVariables[3];
  REPLACE_case1.OK_CONTENT = (Place*) LocalStateVariables[9];
  REPLACE_case2.REPLACE_CONTENT_OK = (Place*) LocalStateVariables[11];
  REPLACE_case2.OK_CONTENT_TEMP = (Place*) LocalStateVariables[3];
  REPLACE_case2.OK_CONTENT = (Place*) LocalStateVariables[9];
  REPLACE_case2.KO_CONTENT = (Place*) LocalStateVariables[10];
  Instantaneous_Activity3_case1.WRITE_L1 = (Place*) LocalStateVariables[1];
  Instantaneous_Activity3_case1.OK_CONTENT = (Place*) LocalStateVariables[9];
  Instantaneous_Activity3_case1.KO_CONTENT = (Place*) LocalStateVariables[10];
  Instantaneous_Activity3_case1.OK_CONTENT_TEMP = (Place*) LocalStateVariables[3];
  Instantaneous_Activity3_case1.REPLACE_CONTENT_OK = (Place*) LocalStateVariables[11];
  Instantaneous_Activity3_case2.WRITE_L1 = (Place*) LocalStateVariables[1];
  Instantaneous_Activity3_case2.OK_CONTENT = (Place*) LocalStateVariables[9];
  Instantaneous_Activity3_case2.KO_CONTENT = (Place*) LocalStateVariables[10];
  Instantaneous_Activity3_case2.KO_CONTENT_TEMP = (Place*) LocalStateVariables[0];
  Instantaneous_Activity3_case2.REPLACE_CONTENT_KO = (Place*) LocalStateVariables[13];
  Instantaneous_Activity4_case1.REPLACE_CONTENT_KO = (Place*) LocalStateVariables[13];
  Instantaneous_Activity4_case1.OK_CONTENT_TEMP = (Place*) LocalStateVariables[3];
  Instantaneous_Activity4_case2.REPLACE_CONTENT_KO = (Place*) LocalStateVariables[13];
  Instantaneous_Activity4_case2.KO_CONTENT_TEMP = (Place*) LocalStateVariables[0];
  Instantaneous_Activity4_case2.KO_CONTENT = (Place*) LocalStateVariables[10];
  Instantaneous_Activity4_case2.OK_CONTENT = (Place*) LocalStateVariables[9];
}
void L1_CACHESAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================Instantaneous_Activity23Activity========================*/


L1_CACHESAN::Instantaneous_Activity23Activity::Instantaneous_Activity23Activity(){
  ActivityInitialize("Instantaneous_Activity23",0,Instantaneous , RaceEnabled, 2,1, false);
}

void L1_CACHESAN::Instantaneous_Activity23Activity::LinkVariables(){
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
}

bool L1_CACHESAN::Instantaneous_Activity23Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(KO_CONTENT_TEMP_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::Instantaneous_Activity23Activity::Weight(){ 
  return 1;
}

bool L1_CACHESAN::Instantaneous_Activity23Activity::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::Instantaneous_Activity23Activity::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::Instantaneous_Activity23Activity::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::Instantaneous_Activity23Activity::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::Instantaneous_Activity23Activity::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::Instantaneous_Activity23Activity::Fire(){
  (*(KO_CONTENT_TEMP_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity12Activity========================*/


L1_CACHESAN::Instantaneous_Activity12Activity::Instantaneous_Activity12Activity(){
  ActivityInitialize("Instantaneous_Activity12",1,Instantaneous , RaceEnabled, 2,1, false);
}

void L1_CACHESAN::Instantaneous_Activity12Activity::LinkVariables(){
  OK_CONTENT_TEMP->Register(&OK_CONTENT_TEMP_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
}

bool L1_CACHESAN::Instantaneous_Activity12Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(OK_CONTENT_TEMP_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::Instantaneous_Activity12Activity::Weight(){ 
  return 1;
}

bool L1_CACHESAN::Instantaneous_Activity12Activity::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::Instantaneous_Activity12Activity::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::Instantaneous_Activity12Activity::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::Instantaneous_Activity12Activity::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::Instantaneous_Activity12Activity::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::Instantaneous_Activity12Activity::Fire(){
  (*(OK_CONTENT_TEMP_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity2Activity========================*/


L1_CACHESAN::Instantaneous_Activity2Activity::Instantaneous_Activity2Activity(){
  ActivityInitialize("Instantaneous_Activity2",2,Instantaneous , RaceEnabled, 3,1, false);
}

void L1_CACHESAN::Instantaneous_Activity2Activity::LinkVariables(){
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
  KO_READ->Register(&KO_READ_Mobius_Mark);
}

bool L1_CACHESAN::Instantaneous_Activity2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEMORY_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::Instantaneous_Activity2Activity::Weight(){ 
  return 1;
}

bool L1_CACHESAN::Instantaneous_Activity2Activity::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::Instantaneous_Activity2Activity::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::Instantaneous_Activity2Activity::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::Instantaneous_Activity2Activity::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::Instantaneous_Activity2Activity::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::Instantaneous_Activity2Activity::Fire(){
  (*(MEMORY_KO_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  (*(KO_READ_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case1========================*/


L1_CACHESAN::READ_FROMActivity_case1::READ_FROMActivity_case1(){
  ActivityInitialize("READ_FROM_case1",3,Instantaneous , RaceEnabled, 2,1, false);
}

void L1_CACHESAN::READ_FROMActivity_case1::LinkVariables(){
  READ_L1->Register(&READ_L1_Mobius_Mark);
  MEMORY_OK->Register(&MEMORY_OK_Mobius_Mark);
}

bool L1_CACHESAN::READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_L1_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::READ_FROMActivity_case1::Weight(){ 
  return 0.5;
}

bool L1_CACHESAN::READ_FROMActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::READ_FROMActivity_case1::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::READ_FROMActivity_case1::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::READ_FROMActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::READ_FROMActivity_case1::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::READ_FROMActivity_case1::Fire(){
  (*(READ_L1_Mobius_Mark))--;
  (*(MEMORY_OK_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case2========================*/


L1_CACHESAN::READ_FROMActivity_case2::READ_FROMActivity_case2(){
  ActivityInitialize("READ_FROM_case2",3,Instantaneous , RaceEnabled, 2,1, false);
}

void L1_CACHESAN::READ_FROMActivity_case2::LinkVariables(){
  READ_L1->Register(&READ_L1_Mobius_Mark);
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
}

bool L1_CACHESAN::READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_L1_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::READ_FROMActivity_case2::Weight(){ 
  return 0.5;
}

bool L1_CACHESAN::READ_FROMActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::READ_FROMActivity_case2::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::READ_FROMActivity_case2::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::READ_FROMActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::READ_FROMActivity_case2::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::READ_FROMActivity_case2::Fire(){
  (*(READ_L1_Mobius_Mark))--;
  (*(MEMORY_KO_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity1Activity========================*/


L1_CACHESAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",4,Instantaneous , RaceEnabled, 3,1, false);
}

void L1_CACHESAN::Instantaneous_Activity1Activity::LinkVariables(){
  MEMORY_OK->Register(&MEMORY_OK_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
  OK_READ->Register(&OK_READ_Mobius_Mark);
}

bool L1_CACHESAN::Instantaneous_Activity1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEMORY_OK_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::Instantaneous_Activity1Activity::Weight(){ 
  return 1;
}

bool L1_CACHESAN::Instantaneous_Activity1Activity::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::Instantaneous_Activity1Activity::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::Instantaneous_Activity1Activity::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::Instantaneous_Activity1Activity::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::Instantaneous_Activity1Activity::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::Instantaneous_Activity1Activity::Fire(){
  (*(MEMORY_OK_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  (*(OK_READ_Mobius_Mark))++;
  return this;
}

/*======================REPLACEActivity_case1========================*/


L1_CACHESAN::REPLACEActivity_case1::REPLACEActivity_case1(){
  ActivityInitialize("REPLACE_case1",5,Instantaneous , RaceEnabled, 2,1, false);
}

void L1_CACHESAN::REPLACEActivity_case1::LinkVariables(){
  REPLACE_CONTENT_OK->Register(&REPLACE_CONTENT_OK_Mobius_Mark);
  OK_CONTENT_TEMP->Register(&OK_CONTENT_TEMP_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
}

bool L1_CACHESAN::REPLACEActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(REPLACE_CONTENT_OK_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::REPLACEActivity_case1::Weight(){ 
  return OK_CONTENT->Mark()/l1_size;
}

bool L1_CACHESAN::REPLACEActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::REPLACEActivity_case1::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::REPLACEActivity_case1::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::REPLACEActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::REPLACEActivity_case1::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::REPLACEActivity_case1::Fire(){
  (*(REPLACE_CONTENT_OK_Mobius_Mark))--;
  OK_CONTENT_TEMP->Mark()++;
  return this;
}

/*======================REPLACEActivity_case2========================*/


L1_CACHESAN::REPLACEActivity_case2::REPLACEActivity_case2(){
  ActivityInitialize("REPLACE_case2",5,Instantaneous , RaceEnabled, 4,1, false);
}

void L1_CACHESAN::REPLACEActivity_case2::LinkVariables(){
  REPLACE_CONTENT_OK->Register(&REPLACE_CONTENT_OK_Mobius_Mark);
  OK_CONTENT_TEMP->Register(&OK_CONTENT_TEMP_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
}

bool L1_CACHESAN::REPLACEActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(REPLACE_CONTENT_OK_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::REPLACEActivity_case2::Weight(){ 
  return KO_CONTENT->Mark()/l1_size;
}

bool L1_CACHESAN::REPLACEActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::REPLACEActivity_case2::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::REPLACEActivity_case2::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::REPLACEActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::REPLACEActivity_case2::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::REPLACEActivity_case2::Fire(){
  (*(REPLACE_CONTENT_OK_Mobius_Mark))--;
  OK_CONTENT_TEMP->Mark()++;
OK_CONTENT->Mark()++;
KO_CONTENT->Mark()--;
  return this;
}

/*======================Instantaneous_Activity3Activity_case1========================*/


L1_CACHESAN::Instantaneous_Activity3Activity_case1::Instantaneous_Activity3Activity_case1(){
  ActivityInitialize("Instantaneous_Activity3_case1",6,Instantaneous , RaceEnabled, 5,1, false);
}

void L1_CACHESAN::Instantaneous_Activity3Activity_case1::LinkVariables(){
  WRITE_L1->Register(&WRITE_L1_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  OK_CONTENT_TEMP->Register(&OK_CONTENT_TEMP_Mobius_Mark);
  REPLACE_CONTENT_OK->Register(&REPLACE_CONTENT_OK_Mobius_Mark);
}

bool L1_CACHESAN::Instantaneous_Activity3Activity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_L1_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::Instantaneous_Activity3Activity_case1::Weight(){ 
  return 0.5;
}

bool L1_CACHESAN::Instantaneous_Activity3Activity_case1::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::Instantaneous_Activity3Activity_case1::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::Instantaneous_Activity3Activity_case1::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::Instantaneous_Activity3Activity_case1::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::Instantaneous_Activity3Activity_case1::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::Instantaneous_Activity3Activity_case1::Fire(){
  (*(WRITE_L1_Mobius_Mark))--;
  if (OK_CONTENT->Mark() + KO_CONTENT->Mark() < l1_size) {

	OK_CONTENT_TEMP->Mark()++;
	OK_CONTENT->Mark()++;	

} else {

	REPLACE_CONTENT_OK->Mark()++;

}
  return this;
}

/*======================Instantaneous_Activity3Activity_case2========================*/


L1_CACHESAN::Instantaneous_Activity3Activity_case2::Instantaneous_Activity3Activity_case2(){
  ActivityInitialize("Instantaneous_Activity3_case2",6,Instantaneous , RaceEnabled, 5,1, false);
}

void L1_CACHESAN::Instantaneous_Activity3Activity_case2::LinkVariables(){
  WRITE_L1->Register(&WRITE_L1_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  REPLACE_CONTENT_KO->Register(&REPLACE_CONTENT_KO_Mobius_Mark);
}

bool L1_CACHESAN::Instantaneous_Activity3Activity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_L1_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::Instantaneous_Activity3Activity_case2::Weight(){ 
  return 0.5;
}

bool L1_CACHESAN::Instantaneous_Activity3Activity_case2::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::Instantaneous_Activity3Activity_case2::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::Instantaneous_Activity3Activity_case2::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::Instantaneous_Activity3Activity_case2::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::Instantaneous_Activity3Activity_case2::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::Instantaneous_Activity3Activity_case2::Fire(){
  (*(WRITE_L1_Mobius_Mark))--;
  if (OK_CONTENT->Mark() + KO_CONTENT->Mark() < l1_size) {

	KO_CONTENT_TEMP->Mark()++;
	KO_CONTENT->Mark()++;

} else {

	REPLACE_CONTENT_KO->Mark()++;

}
  return this;
}

/*======================Instantaneous_Activity4Activity_case1========================*/


L1_CACHESAN::Instantaneous_Activity4Activity_case1::Instantaneous_Activity4Activity_case1(){
  ActivityInitialize("Instantaneous_Activity4_case1",7,Instantaneous , RaceEnabled, 2,1, false);
}

void L1_CACHESAN::Instantaneous_Activity4Activity_case1::LinkVariables(){
  REPLACE_CONTENT_KO->Register(&REPLACE_CONTENT_KO_Mobius_Mark);
  OK_CONTENT_TEMP->Register(&OK_CONTENT_TEMP_Mobius_Mark);
}

bool L1_CACHESAN::Instantaneous_Activity4Activity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(REPLACE_CONTENT_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::Instantaneous_Activity4Activity_case1::Weight(){ 
  return 0.5;
}

bool L1_CACHESAN::Instantaneous_Activity4Activity_case1::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::Instantaneous_Activity4Activity_case1::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::Instantaneous_Activity4Activity_case1::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::Instantaneous_Activity4Activity_case1::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::Instantaneous_Activity4Activity_case1::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::Instantaneous_Activity4Activity_case1::Fire(){
  (*(REPLACE_CONTENT_KO_Mobius_Mark))--;
  OK_CONTENT_TEMP->Mark()++;
  return this;
}

/*======================Instantaneous_Activity4Activity_case2========================*/


L1_CACHESAN::Instantaneous_Activity4Activity_case2::Instantaneous_Activity4Activity_case2(){
  ActivityInitialize("Instantaneous_Activity4_case2",7,Instantaneous , RaceEnabled, 4,1, false);
}

void L1_CACHESAN::Instantaneous_Activity4Activity_case2::LinkVariables(){
  REPLACE_CONTENT_KO->Register(&REPLACE_CONTENT_KO_Mobius_Mark);
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
}

bool L1_CACHESAN::Instantaneous_Activity4Activity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(REPLACE_CONTENT_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::Instantaneous_Activity4Activity_case2::Weight(){ 
  return 0.5;
}

bool L1_CACHESAN::Instantaneous_Activity4Activity_case2::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::Instantaneous_Activity4Activity_case2::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::Instantaneous_Activity4Activity_case2::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::Instantaneous_Activity4Activity_case2::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::Instantaneous_Activity4Activity_case2::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::Instantaneous_Activity4Activity_case2::Fire(){
  (*(REPLACE_CONTENT_KO_Mobius_Mark))--;
  KO_CONTENT_TEMP->Mark()++;
KO_CONTENT->Mark()++;
OK_CONTENT->Mark()--;

  return this;
}

