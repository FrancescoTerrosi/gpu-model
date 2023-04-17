

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

  REPLACE_KOGroup.initialize(2, "REPLACE_KOGroup");
  REPLACE_KOGroup.appendGroup((BaseGroupClass*) &REPLACE_KO_case1);
  REPLACE_KOGroup.appendGroup((BaseGroupClass*) &REPLACE_KO_case2);

  Activity* InitialActionList[15]={
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
    &REPLACE_KO_case1, //10
    &REPLACE_KO_case2, //11
    &Instantaneous_Activity4, //12
    &dhn, //13
    &Instantaneous_Activity5  // 14
  };

  BaseGroupClass* InitialGroupList[11]={
    (BaseGroupClass*) &(Instantaneous_Activity23), 
    (BaseGroupClass*) &(Instantaneous_Activity12), 
    (BaseGroupClass*) &(Instantaneous_Activity2), 
    (BaseGroupClass*) &(READ_FROMGroup), 
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(REPLACEGroup), 
    (BaseGroupClass*) &(Instantaneous_Activity3Group), 
    (BaseGroupClass*) &(REPLACE_KOGroup), 
    (BaseGroupClass*) &(Instantaneous_Activity4), 
    (BaseGroupClass*) &(dhn), 
    (BaseGroupClass*) &(Instantaneous_Activity5)
  };

  MEM_FAILURE = new Place("MEM_FAILURE" ,0);
  ROUTE_READ = new Place("ROUTE_READ" ,0);
  KO_CONTENT_TEMP = new Place("KO_CONTENT_TEMP" ,0);
  WRITE_L1 = new Place("WRITE_L1" ,0);
  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  OK_CONTENT_TEMP = new Place("OK_CONTENT_TEMP" ,0);
  KO_READ = new Place("KO_READ" ,0);
  MEMORY_KO = new Place("MEMORY_KO" ,0);
  READ_L1 = new Place("READ_L1" ,0);
  MEMORY_OK = new Place("MEMORY_OK" ,0);
  OK_READ = new Place("OK_READ" ,0);
  OK_CONTENT = new Place("OK_CONTENT" ,0);
  KO_CONTENT = new Place("KO_CONTENT" ,0);
  REPLACE_CONTENT_OK = new Place("REPLACE_CONTENT_OK" ,0);
  REPLACE_CONTENT_KO = new Place("REPLACE_CONTENT_KO" ,0);
  MEM_FAILURE_COUNT = new Place("MEM_FAILURE_COUNT" ,0);
  Place1 = new Place("Place1" ,0);
  ROUTE_WRITE = new Place("ROUTE_WRITE" ,0);
  BaseStateVariableClass* InitialPlaces[18]={
    MEM_FAILURE,  // 0
    ROUTE_READ,  // 1
    KO_CONTENT_TEMP,  // 2
    WRITE_L1,  // 3
    INSTRUCTION_READY,  // 4
    OK_CONTENT_TEMP,  // 5
    KO_READ,  // 6
    MEMORY_KO,  // 7
    READ_L1,  // 8
    MEMORY_OK,  // 9
    OK_READ,  // 10
    OK_CONTENT,  // 11
    KO_CONTENT,  // 12
    REPLACE_CONTENT_OK,  // 13
    REPLACE_CONTENT_KO,  // 14
    MEM_FAILURE_COUNT,  // 15
    Place1,  // 16
    ROUTE_WRITE   // 17
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("L1_CACHE", 18, InitialPlaces, 
                        0, InitialROPlaces, 
                        15, InitialActionList, 11, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[51][2]={ 
    {2,0}, {4,0}, {5,1}, {4,1}, {7,2}, {4,2}, {6,2}, {1,3}, {9,3}, 
    {1,4}, {7,4}, {9,5}, {4,5}, {10,5}, {13,6}, {5,6}, {13,7}, 
    {2,7}, {11,7}, {12,7}, {17,8}, {11,8}, {12,8}, {5,8}, {13,8}, 
    {17,9}, {11,9}, {12,9}, {2,9}, {14,9}, {14,10}, {2,10}, {14,11}, 
    {2,11}, {12,11}, {11,11}, {8,12}, {0,12}, {7,12}, {15,12}, 
    {1,12}, {15,13}, {16,13}, {3,14}, {0,14}, {11,14}, {12,14}, 
    {2,14}, {14,14}, {15,14}, {17,14}
  };
  for(int n=0;n<51;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[15][2]={ 
    {2,0}, {5,1}, {7,2}, {1,3}, {1,4}, {9,5}, {13,6}, {13,7}, 
    {17,8}, {17,9}, {14,10}, {14,11}, {8,12}, {15,13}, {3,14}
  };
  for(int n=0;n<15;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<15;n++) {
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
  Instantaneous_Activity23.KO_CONTENT_TEMP = (Place*) LocalStateVariables[2];
  Instantaneous_Activity23.INSTRUCTION_READY = (Place*) LocalStateVariables[4];
  Instantaneous_Activity12.OK_CONTENT_TEMP = (Place*) LocalStateVariables[5];
  Instantaneous_Activity12.INSTRUCTION_READY = (Place*) LocalStateVariables[4];
  Instantaneous_Activity2.MEMORY_KO = (Place*) LocalStateVariables[7];
  Instantaneous_Activity2.INSTRUCTION_READY = (Place*) LocalStateVariables[4];
  Instantaneous_Activity2.KO_READ = (Place*) LocalStateVariables[6];
  READ_FROM_case1.ROUTE_READ = (Place*) LocalStateVariables[1];
  READ_FROM_case1.MEMORY_OK = (Place*) LocalStateVariables[9];
  READ_FROM_case2.ROUTE_READ = (Place*) LocalStateVariables[1];
  READ_FROM_case2.MEMORY_KO = (Place*) LocalStateVariables[7];
  Instantaneous_Activity1.MEMORY_OK = (Place*) LocalStateVariables[9];
  Instantaneous_Activity1.INSTRUCTION_READY = (Place*) LocalStateVariables[4];
  Instantaneous_Activity1.OK_READ = (Place*) LocalStateVariables[10];
  REPLACE_case1.REPLACE_CONTENT_OK = (Place*) LocalStateVariables[13];
  REPLACE_case1.OK_CONTENT_TEMP = (Place*) LocalStateVariables[5];
  REPLACE_case1.OK_CONTENT = (Place*) LocalStateVariables[11];
  REPLACE_case2.REPLACE_CONTENT_OK = (Place*) LocalStateVariables[13];
  REPLACE_case2.KO_CONTENT_TEMP = (Place*) LocalStateVariables[2];
  REPLACE_case2.OK_CONTENT = (Place*) LocalStateVariables[11];
  REPLACE_case2.KO_CONTENT = (Place*) LocalStateVariables[12];
  Instantaneous_Activity3_case1.ROUTE_WRITE = (Place*) LocalStateVariables[17];
  Instantaneous_Activity3_case1.OK_CONTENT = (Place*) LocalStateVariables[11];
  Instantaneous_Activity3_case1.KO_CONTENT = (Place*) LocalStateVariables[12];
  Instantaneous_Activity3_case1.OK_CONTENT_TEMP = (Place*) LocalStateVariables[5];
  Instantaneous_Activity3_case1.REPLACE_CONTENT_OK = (Place*) LocalStateVariables[13];
  Instantaneous_Activity3_case2.ROUTE_WRITE = (Place*) LocalStateVariables[17];
  Instantaneous_Activity3_case2.OK_CONTENT = (Place*) LocalStateVariables[11];
  Instantaneous_Activity3_case2.KO_CONTENT = (Place*) LocalStateVariables[12];
  Instantaneous_Activity3_case2.KO_CONTENT_TEMP = (Place*) LocalStateVariables[2];
  Instantaneous_Activity3_case2.REPLACE_CONTENT_KO = (Place*) LocalStateVariables[14];
  REPLACE_KO_case1.REPLACE_CONTENT_KO = (Place*) LocalStateVariables[14];
  REPLACE_KO_case1.KO_CONTENT_TEMP = (Place*) LocalStateVariables[2];
  REPLACE_KO_case2.REPLACE_CONTENT_KO = (Place*) LocalStateVariables[14];
  REPLACE_KO_case2.KO_CONTENT_TEMP = (Place*) LocalStateVariables[2];
  REPLACE_KO_case2.KO_CONTENT = (Place*) LocalStateVariables[12];
  REPLACE_KO_case2.OK_CONTENT = (Place*) LocalStateVariables[11];
  Instantaneous_Activity4.READ_L1 = (Place*) LocalStateVariables[8];
  Instantaneous_Activity4.MEM_FAILURE = (Place*) LocalStateVariables[0];
  Instantaneous_Activity4.MEMORY_KO = (Place*) LocalStateVariables[7];
  Instantaneous_Activity4.MEM_FAILURE_COUNT = (Place*) LocalStateVariables[15];
  Instantaneous_Activity4.ROUTE_READ = (Place*) LocalStateVariables[1];
  dhn.MEM_FAILURE_COUNT = (Place*) LocalStateVariables[15];
  dhn.Place1 = (Place*) LocalStateVariables[16];
  Instantaneous_Activity5.WRITE_L1 = (Place*) LocalStateVariables[3];
  Instantaneous_Activity5.MEM_FAILURE = (Place*) LocalStateVariables[0];
  Instantaneous_Activity5.OK_CONTENT = (Place*) LocalStateVariables[11];
  Instantaneous_Activity5.KO_CONTENT = (Place*) LocalStateVariables[12];
  Instantaneous_Activity5.KO_CONTENT_TEMP = (Place*) LocalStateVariables[2];
  Instantaneous_Activity5.REPLACE_CONTENT_KO = (Place*) LocalStateVariables[14];
  Instantaneous_Activity5.MEM_FAILURE_COUNT = (Place*) LocalStateVariables[15];
  Instantaneous_Activity5.ROUTE_WRITE = (Place*) LocalStateVariables[17];
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
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
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
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity12Activity========================*/


L1_CACHESAN::Instantaneous_Activity12Activity::Instantaneous_Activity12Activity(){
  ActivityInitialize("Instantaneous_Activity12",1,Instantaneous , RaceEnabled, 2,1, false);
}

void L1_CACHESAN::Instantaneous_Activity12Activity::LinkVariables(){
  OK_CONTENT_TEMP->Register(&OK_CONTENT_TEMP_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
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
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity2Activity========================*/


L1_CACHESAN::Instantaneous_Activity2Activity::Instantaneous_Activity2Activity(){
  ActivityInitialize("Instantaneous_Activity2",2,Instantaneous , RaceEnabled, 3,1, false);
}

void L1_CACHESAN::Instantaneous_Activity2Activity::LinkVariables(){
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
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
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  (*(KO_READ_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case1========================*/


L1_CACHESAN::READ_FROMActivity_case1::READ_FROMActivity_case1(){
  ActivityInitialize("READ_FROM_case1",3,Instantaneous , RaceEnabled, 2,1, false);
}

void L1_CACHESAN::READ_FROMActivity_case1::LinkVariables(){
  ROUTE_READ->Register(&ROUTE_READ_Mobius_Mark);
  MEMORY_OK->Register(&MEMORY_OK_Mobius_Mark);
}

bool L1_CACHESAN::READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ROUTE_READ_Mobius_Mark)) >=1));
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
  (*(ROUTE_READ_Mobius_Mark))--;
  (*(MEMORY_OK_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case2========================*/


L1_CACHESAN::READ_FROMActivity_case2::READ_FROMActivity_case2(){
  ActivityInitialize("READ_FROM_case2",3,Instantaneous , RaceEnabled, 2,1, false);
}

void L1_CACHESAN::READ_FROMActivity_case2::LinkVariables(){
  ROUTE_READ->Register(&ROUTE_READ_Mobius_Mark);
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
}

bool L1_CACHESAN::READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ROUTE_READ_Mobius_Mark)) >=1));
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
  (*(ROUTE_READ_Mobius_Mark))--;
  (*(MEMORY_KO_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity1Activity========================*/


L1_CACHESAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",4,Instantaneous , RaceEnabled, 3,1, false);
}

void L1_CACHESAN::Instantaneous_Activity1Activity::LinkVariables(){
  MEMORY_OK->Register(&MEMORY_OK_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
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
  (*(INSTRUCTION_READY_Mobius_Mark))++;
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
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
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
  KO_CONTENT_TEMP->Mark()++;
OK_CONTENT->Mark()++;
if (KO_CONTENT->Mark() > 0) {
	KO_CONTENT->Mark()--;
}
  return this;
}

/*======================Instantaneous_Activity3Activity_case1========================*/


L1_CACHESAN::Instantaneous_Activity3Activity_case1::Instantaneous_Activity3Activity_case1(){
  ActivityInitialize("Instantaneous_Activity3_case1",6,Instantaneous , RaceEnabled, 5,1, false);
}

void L1_CACHESAN::Instantaneous_Activity3Activity_case1::LinkVariables(){
  ROUTE_WRITE->Register(&ROUTE_WRITE_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  OK_CONTENT_TEMP->Register(&OK_CONTENT_TEMP_Mobius_Mark);
  REPLACE_CONTENT_OK->Register(&REPLACE_CONTENT_OK_Mobius_Mark);
}

bool L1_CACHESAN::Instantaneous_Activity3Activity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ROUTE_WRITE_Mobius_Mark)) >=1));
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
  (*(ROUTE_WRITE_Mobius_Mark))--;
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
  ROUTE_WRITE->Register(&ROUTE_WRITE_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  REPLACE_CONTENT_KO->Register(&REPLACE_CONTENT_KO_Mobius_Mark);
}

bool L1_CACHESAN::Instantaneous_Activity3Activity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ROUTE_WRITE_Mobius_Mark)) >=1));
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
  (*(ROUTE_WRITE_Mobius_Mark))--;
  if (OK_CONTENT->Mark() + KO_CONTENT->Mark() < l1_size) {

	KO_CONTENT_TEMP->Mark()++;
	KO_CONTENT->Mark()++;

} else {

	REPLACE_CONTENT_KO->Mark()++;

}
  return this;
}

/*======================REPLACE_KOActivity_case1========================*/


L1_CACHESAN::REPLACE_KOActivity_case1::REPLACE_KOActivity_case1(){
  ActivityInitialize("REPLACE_KO_case1",7,Instantaneous , RaceEnabled, 2,1, false);
}

void L1_CACHESAN::REPLACE_KOActivity_case1::LinkVariables(){
  REPLACE_CONTENT_KO->Register(&REPLACE_CONTENT_KO_Mobius_Mark);
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
}

bool L1_CACHESAN::REPLACE_KOActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(REPLACE_CONTENT_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::REPLACE_KOActivity_case1::Weight(){ 
  return 0.5;
}

bool L1_CACHESAN::REPLACE_KOActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::REPLACE_KOActivity_case1::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::REPLACE_KOActivity_case1::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::REPLACE_KOActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::REPLACE_KOActivity_case1::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::REPLACE_KOActivity_case1::Fire(){
  (*(REPLACE_CONTENT_KO_Mobius_Mark))--;
  KO_CONTENT_TEMP->Mark()++;
  return this;
}

/*======================REPLACE_KOActivity_case2========================*/


L1_CACHESAN::REPLACE_KOActivity_case2::REPLACE_KOActivity_case2(){
  ActivityInitialize("REPLACE_KO_case2",7,Instantaneous , RaceEnabled, 4,1, false);
}

void L1_CACHESAN::REPLACE_KOActivity_case2::LinkVariables(){
  REPLACE_CONTENT_KO->Register(&REPLACE_CONTENT_KO_Mobius_Mark);
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
}

bool L1_CACHESAN::REPLACE_KOActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(REPLACE_CONTENT_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::REPLACE_KOActivity_case2::Weight(){ 
  return 0.5;
}

bool L1_CACHESAN::REPLACE_KOActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::REPLACE_KOActivity_case2::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::REPLACE_KOActivity_case2::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::REPLACE_KOActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::REPLACE_KOActivity_case2::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::REPLACE_KOActivity_case2::Fire(){
  (*(REPLACE_CONTENT_KO_Mobius_Mark))--;
  KO_CONTENT_TEMP->Mark()++;
KO_CONTENT->Mark()++;
if (OK_CONTENT->Mark() > 0) {
	OK_CONTENT->Mark()--;
}
  return this;
}

/*======================Instantaneous_Activity4Activity========================*/


L1_CACHESAN::Instantaneous_Activity4Activity::Instantaneous_Activity4Activity(){
  ActivityInitialize("Instantaneous_Activity4",8,Instantaneous , RaceEnabled, 5,1, false);
}

void L1_CACHESAN::Instantaneous_Activity4Activity::LinkVariables(){
  READ_L1->Register(&READ_L1_Mobius_Mark);
  MEM_FAILURE->Register(&MEM_FAILURE_Mobius_Mark);
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
  MEM_FAILURE_COUNT->Register(&MEM_FAILURE_COUNT_Mobius_Mark);
  ROUTE_READ->Register(&ROUTE_READ_Mobius_Mark);
}

bool L1_CACHESAN::Instantaneous_Activity4Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_L1_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::Instantaneous_Activity4Activity::Weight(){ 
  return 1;
}

bool L1_CACHESAN::Instantaneous_Activity4Activity::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::Instantaneous_Activity4Activity::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::Instantaneous_Activity4Activity::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::Instantaneous_Activity4Activity::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::Instantaneous_Activity4Activity::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::Instantaneous_Activity4Activity::Fire(){
  (*(READ_L1_Mobius_Mark))--;
  if (MEM_FAILURE->Mark() > 0) {

	MEMORY_KO->Mark()++;
	MEM_FAILURE->Mark()--;
	MEM_FAILURE_COUNT->Mark()++;

} else {

	ROUTE_READ->Mark()++;

}
  return this;
}

/*======================dhnActivity========================*/


L1_CACHESAN::dhnActivity::dhnActivity(){
  ActivityInitialize("dhn",9,Instantaneous , RaceEnabled, 2,1, false);
}

void L1_CACHESAN::dhnActivity::LinkVariables(){
  MEM_FAILURE_COUNT->Register(&MEM_FAILURE_COUNT_Mobius_Mark);
  Place1->Register(&Place1_Mobius_Mark);
}

bool L1_CACHESAN::dhnActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEM_FAILURE_COUNT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::dhnActivity::Weight(){ 
  return 1;
}

bool L1_CACHESAN::dhnActivity::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::dhnActivity::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::dhnActivity::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::dhnActivity::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::dhnActivity::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::dhnActivity::Fire(){
  (*(MEM_FAILURE_COUNT_Mobius_Mark))--;
  (*(Place1_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity5Activity========================*/


L1_CACHESAN::Instantaneous_Activity5Activity::Instantaneous_Activity5Activity(){
  ActivityInitialize("Instantaneous_Activity5",10,Instantaneous , RaceEnabled, 8,1, false);
}

void L1_CACHESAN::Instantaneous_Activity5Activity::LinkVariables(){
  WRITE_L1->Register(&WRITE_L1_Mobius_Mark);
  MEM_FAILURE->Register(&MEM_FAILURE_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  REPLACE_CONTENT_KO->Register(&REPLACE_CONTENT_KO_Mobius_Mark);
  MEM_FAILURE_COUNT->Register(&MEM_FAILURE_COUNT_Mobius_Mark);
  ROUTE_WRITE->Register(&ROUTE_WRITE_Mobius_Mark);
}

bool L1_CACHESAN::Instantaneous_Activity5Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_L1_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHESAN::Instantaneous_Activity5Activity::Weight(){ 
  return 1;
}

bool L1_CACHESAN::Instantaneous_Activity5Activity::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHESAN::Instantaneous_Activity5Activity::ReactivationFunction(){ 
  return false;
}

double L1_CACHESAN::Instantaneous_Activity5Activity::SampleDistribution(){
  return 0;
}

double* L1_CACHESAN::Instantaneous_Activity5Activity::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHESAN::Instantaneous_Activity5Activity::Rank(){
  return 1;
}

BaseActionClass* L1_CACHESAN::Instantaneous_Activity5Activity::Fire(){
  (*(WRITE_L1_Mobius_Mark))--;
  if (MEM_FAILURE->Mark() > 0) {

	if (OK_CONTENT->Mark() + KO_CONTENT->Mark() < l1_size) {

		KO_CONTENT_TEMP->Mark()++;
		KO_CONTENT->Mark()++;

	} else {
		REPLACE_CONTENT_KO->Mark()++;
	}

	MEM_FAILURE->Mark()--;
	MEM_FAILURE_COUNT->Mark()++;

} else {

	ROUTE_WRITE->Mark()++;

}
  return this;
}

