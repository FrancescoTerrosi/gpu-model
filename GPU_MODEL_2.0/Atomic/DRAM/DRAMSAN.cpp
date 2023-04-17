

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

  REPLACEGroup.initialize(2, "REPLACEGroup");
  REPLACEGroup.appendGroup((BaseGroupClass*) &REPLACE_case1);
  REPLACEGroup.appendGroup((BaseGroupClass*) &REPLACE_case2);

  REPLACE_KOGroup.initialize(2, "REPLACE_KOGroup");
  REPLACE_KOGroup.appendGroup((BaseGroupClass*) &REPLACE_KO_case1);
  REPLACE_KOGroup.appendGroup((BaseGroupClass*) &REPLACE_KO_case2);

  Activity* InitialActionList[15]={
    &Instantaneous_Activity2, //0
    &READ_FROM_case1, //1
    &READ_FROM_case2, //2
    &Instantaneous_Activity1, //3
    &Instantaneous_Activity4, //4
    &dhn, //5
    &Instantaneous_Activity3_case1, //6
    &Instantaneous_Activity3_case2, //7
    &Instantaneous_Activity5, //8
    &REPLACE_case1, //9
    &REPLACE_case2, //10
    &REPLACE_KO_case1, //11
    &REPLACE_KO_case2, //12
    &Instantaneous_Activity23, //13
    &Instantaneous_Activity12  // 14
  };

  BaseGroupClass* InitialGroupList[11]={
    (BaseGroupClass*) &(Instantaneous_Activity2), 
    (BaseGroupClass*) &(READ_FROMGroup), 
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(Instantaneous_Activity4), 
    (BaseGroupClass*) &(dhn), 
    (BaseGroupClass*) &(Instantaneous_Activity3Group), 
    (BaseGroupClass*) &(Instantaneous_Activity5), 
    (BaseGroupClass*) &(REPLACEGroup), 
    (BaseGroupClass*) &(REPLACE_KOGroup), 
    (BaseGroupClass*) &(Instantaneous_Activity23), 
    (BaseGroupClass*) &(Instantaneous_Activity12)
  };

  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  KO_READ = new Place("KO_READ" ,0);
  MEMORY_KO = new Place("MEMORY_KO" ,0);
  READ_DRAM = new Place("READ_DRAM" ,0);
  OK_READ = new Place("OK_READ" ,0);
  MEMORY_OK = new Place("MEMORY_OK" ,0);
  MEM_FAILURE = new Place("MEM_FAILURE" ,0);
  ROUTE_READ = new Place("ROUTE_READ" ,0);
  MEM_FAILURE_COUNT = new Place("MEM_FAILURE_COUNT" ,0);
  Place1 = new Place("Place1" ,0);
  WRITE_DRAM = new Place("WRITE_DRAM" ,0);
  ROUTE_WRITE = new Place("ROUTE_WRITE" ,0);
  REPLACE_CONTENT_OK = new Place("REPLACE_CONTENT_OK" ,0);
  REPLACE_CONTENT_KO = new Place("REPLACE_CONTENT_KO" ,0);
  KO_CONTENT_TEMP = new Place("KO_CONTENT_TEMP" ,0);
  OK_CONTENT_TEMP = new Place("OK_CONTENT_TEMP" ,0);
  OK_CONTENT = new Place("OK_CONTENT" ,0);
  KO_CONTENT = new Place("KO_CONTENT" ,0);
  BaseStateVariableClass* InitialPlaces[18]={
    INSTRUCTION_READY,  // 0
    KO_READ,  // 1
    MEMORY_KO,  // 2
    READ_DRAM,  // 3
    OK_READ,  // 4
    MEMORY_OK,  // 5
    MEM_FAILURE,  // 6
    ROUTE_READ,  // 7
    MEM_FAILURE_COUNT,  // 8
    Place1,  // 9
    WRITE_DRAM,  // 10
    ROUTE_WRITE,  // 11
    REPLACE_CONTENT_OK,  // 12
    REPLACE_CONTENT_KO,  // 13
    KO_CONTENT_TEMP,  // 14
    OK_CONTENT_TEMP,  // 15
    OK_CONTENT,  // 16
    KO_CONTENT   // 17
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("DRAM", 18, InitialPlaces, 
                        0, InitialROPlaces, 
                        15, InitialActionList, 11, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[51][2]={ 
    {2,0}, {0,0}, {1,0}, {7,1}, {5,1}, {7,2}, {2,2}, {5,3}, {0,3}, 
    {4,3}, {3,4}, {6,4}, {2,4}, {8,4}, {7,4}, {8,5}, {9,5}, {11,6}, 
    {16,6}, {17,6}, {15,6}, {12,6}, {11,7}, {16,7}, {17,7}, {14,7}, 
    {13,7}, {10,8}, {6,8}, {16,8}, {17,8}, {14,8}, {13,8}, {8,8}, 
    {11,8}, {12,9}, {15,9}, {12,10}, {14,10}, {16,10}, {17,10}, 
    {13,11}, {14,11}, {13,12}, {14,12}, {17,12}, {16,12}, {14,13}, 
    {0,13}, {15,14}, {0,14}
  };
  for(int n=0;n<51;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[15][2]={ 
    {2,0}, {7,1}, {7,2}, {5,3}, {3,4}, {8,5}, {11,6}, {11,7}, 
    {10,8}, {12,9}, {12,10}, {13,11}, {13,12}, {14,13}, {15,14}
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

void DRAMSAN::CustomInitialization() {

}
DRAMSAN::~DRAMSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void DRAMSAN::assignPlacesToActivitiesInst(){
  Instantaneous_Activity2.MEMORY_KO = (Place*) LocalStateVariables[2];
  Instantaneous_Activity2.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  Instantaneous_Activity2.KO_READ = (Place*) LocalStateVariables[1];
  READ_FROM_case1.ROUTE_READ = (Place*) LocalStateVariables[7];
  READ_FROM_case1.MEMORY_OK = (Place*) LocalStateVariables[5];
  READ_FROM_case2.ROUTE_READ = (Place*) LocalStateVariables[7];
  READ_FROM_case2.MEMORY_KO = (Place*) LocalStateVariables[2];
  Instantaneous_Activity1.MEMORY_OK = (Place*) LocalStateVariables[5];
  Instantaneous_Activity1.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  Instantaneous_Activity1.OK_READ = (Place*) LocalStateVariables[4];
  Instantaneous_Activity4.READ_DRAM = (Place*) LocalStateVariables[3];
  Instantaneous_Activity4.MEM_FAILURE = (Place*) LocalStateVariables[6];
  Instantaneous_Activity4.MEMORY_KO = (Place*) LocalStateVariables[2];
  Instantaneous_Activity4.MEM_FAILURE_COUNT = (Place*) LocalStateVariables[8];
  Instantaneous_Activity4.ROUTE_READ = (Place*) LocalStateVariables[7];
  dhn.MEM_FAILURE_COUNT = (Place*) LocalStateVariables[8];
  dhn.Place1 = (Place*) LocalStateVariables[9];
  Instantaneous_Activity3_case1.ROUTE_WRITE = (Place*) LocalStateVariables[11];
  Instantaneous_Activity3_case1.OK_CONTENT = (Place*) LocalStateVariables[16];
  Instantaneous_Activity3_case1.KO_CONTENT = (Place*) LocalStateVariables[17];
  Instantaneous_Activity3_case1.OK_CONTENT_TEMP = (Place*) LocalStateVariables[15];
  Instantaneous_Activity3_case1.REPLACE_CONTENT_OK = (Place*) LocalStateVariables[12];
  Instantaneous_Activity3_case2.ROUTE_WRITE = (Place*) LocalStateVariables[11];
  Instantaneous_Activity3_case2.OK_CONTENT = (Place*) LocalStateVariables[16];
  Instantaneous_Activity3_case2.KO_CONTENT = (Place*) LocalStateVariables[17];
  Instantaneous_Activity3_case2.KO_CONTENT_TEMP = (Place*) LocalStateVariables[14];
  Instantaneous_Activity3_case2.REPLACE_CONTENT_KO = (Place*) LocalStateVariables[13];
  Instantaneous_Activity5.WRITE_DRAM = (Place*) LocalStateVariables[10];
  Instantaneous_Activity5.MEM_FAILURE = (Place*) LocalStateVariables[6];
  Instantaneous_Activity5.OK_CONTENT = (Place*) LocalStateVariables[16];
  Instantaneous_Activity5.KO_CONTENT = (Place*) LocalStateVariables[17];
  Instantaneous_Activity5.KO_CONTENT_TEMP = (Place*) LocalStateVariables[14];
  Instantaneous_Activity5.REPLACE_CONTENT_KO = (Place*) LocalStateVariables[13];
  Instantaneous_Activity5.MEM_FAILURE_COUNT = (Place*) LocalStateVariables[8];
  Instantaneous_Activity5.ROUTE_WRITE = (Place*) LocalStateVariables[11];
  REPLACE_case1.REPLACE_CONTENT_OK = (Place*) LocalStateVariables[12];
  REPLACE_case1.OK_CONTENT_TEMP = (Place*) LocalStateVariables[15];
  REPLACE_case1.OK_CONTENT = (Place*) LocalStateVariables[16];
  REPLACE_case2.REPLACE_CONTENT_OK = (Place*) LocalStateVariables[12];
  REPLACE_case2.KO_CONTENT_TEMP = (Place*) LocalStateVariables[14];
  REPLACE_case2.OK_CONTENT = (Place*) LocalStateVariables[16];
  REPLACE_case2.KO_CONTENT = (Place*) LocalStateVariables[17];
  REPLACE_KO_case1.REPLACE_CONTENT_KO = (Place*) LocalStateVariables[13];
  REPLACE_KO_case1.KO_CONTENT_TEMP = (Place*) LocalStateVariables[14];
  REPLACE_KO_case2.REPLACE_CONTENT_KO = (Place*) LocalStateVariables[13];
  REPLACE_KO_case2.KO_CONTENT_TEMP = (Place*) LocalStateVariables[14];
  REPLACE_KO_case2.KO_CONTENT = (Place*) LocalStateVariables[17];
  REPLACE_KO_case2.OK_CONTENT = (Place*) LocalStateVariables[16];
  Instantaneous_Activity23.KO_CONTENT_TEMP = (Place*) LocalStateVariables[14];
  Instantaneous_Activity23.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  Instantaneous_Activity12.OK_CONTENT_TEMP = (Place*) LocalStateVariables[15];
  Instantaneous_Activity12.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
}
void DRAMSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================Instantaneous_Activity2Activity========================*/


DRAMSAN::Instantaneous_Activity2Activity::Instantaneous_Activity2Activity(){
  ActivityInitialize("Instantaneous_Activity2",0,Instantaneous , RaceEnabled, 3,1, false);
}

void DRAMSAN::Instantaneous_Activity2Activity::LinkVariables(){
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
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
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  (*(KO_READ_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case1========================*/


DRAMSAN::READ_FROMActivity_case1::READ_FROMActivity_case1(){
  ActivityInitialize("READ_FROM_case1",1,Instantaneous , RaceEnabled, 2,1, false);
}

void DRAMSAN::READ_FROMActivity_case1::LinkVariables(){
  ROUTE_READ->Register(&ROUTE_READ_Mobius_Mark);
  MEMORY_OK->Register(&MEMORY_OK_Mobius_Mark);
}

bool DRAMSAN::READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ROUTE_READ_Mobius_Mark)) >=1));
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
  (*(ROUTE_READ_Mobius_Mark))--;
  (*(MEMORY_OK_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case2========================*/


DRAMSAN::READ_FROMActivity_case2::READ_FROMActivity_case2(){
  ActivityInitialize("READ_FROM_case2",1,Instantaneous , RaceEnabled, 2,1, false);
}

void DRAMSAN::READ_FROMActivity_case2::LinkVariables(){
  ROUTE_READ->Register(&ROUTE_READ_Mobius_Mark);
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
}

bool DRAMSAN::READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ROUTE_READ_Mobius_Mark)) >=1));
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
  (*(ROUTE_READ_Mobius_Mark))--;
  (*(MEMORY_KO_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity1Activity========================*/


DRAMSAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",2,Instantaneous , RaceEnabled, 3,1, false);
}

void DRAMSAN::Instantaneous_Activity1Activity::LinkVariables(){
  MEMORY_OK->Register(&MEMORY_OK_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
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
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  (*(OK_READ_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity4Activity========================*/


DRAMSAN::Instantaneous_Activity4Activity::Instantaneous_Activity4Activity(){
  ActivityInitialize("Instantaneous_Activity4",3,Instantaneous , RaceEnabled, 5,1, false);
}

void DRAMSAN::Instantaneous_Activity4Activity::LinkVariables(){
  READ_DRAM->Register(&READ_DRAM_Mobius_Mark);
  MEM_FAILURE->Register(&MEM_FAILURE_Mobius_Mark);
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
  MEM_FAILURE_COUNT->Register(&MEM_FAILURE_COUNT_Mobius_Mark);
  ROUTE_READ->Register(&ROUTE_READ_Mobius_Mark);
}

bool DRAMSAN::Instantaneous_Activity4Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_DRAM_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::Instantaneous_Activity4Activity::Weight(){ 
  return 1;
}

bool DRAMSAN::Instantaneous_Activity4Activity::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::Instantaneous_Activity4Activity::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::Instantaneous_Activity4Activity::SampleDistribution(){
  return 0;
}

double* DRAMSAN::Instantaneous_Activity4Activity::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::Instantaneous_Activity4Activity::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::Instantaneous_Activity4Activity::Fire(){
  (*(READ_DRAM_Mobius_Mark))--;
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


DRAMSAN::dhnActivity::dhnActivity(){
  ActivityInitialize("dhn",4,Instantaneous , RaceEnabled, 2,1, false);
}

void DRAMSAN::dhnActivity::LinkVariables(){
  MEM_FAILURE_COUNT->Register(&MEM_FAILURE_COUNT_Mobius_Mark);
  Place1->Register(&Place1_Mobius_Mark);
}

bool DRAMSAN::dhnActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEM_FAILURE_COUNT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::dhnActivity::Weight(){ 
  return 1;
}

bool DRAMSAN::dhnActivity::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::dhnActivity::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::dhnActivity::SampleDistribution(){
  return 0;
}

double* DRAMSAN::dhnActivity::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::dhnActivity::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::dhnActivity::Fire(){
  (*(MEM_FAILURE_COUNT_Mobius_Mark))--;
  (*(Place1_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity3Activity_case1========================*/


DRAMSAN::Instantaneous_Activity3Activity_case1::Instantaneous_Activity3Activity_case1(){
  ActivityInitialize("Instantaneous_Activity3_case1",5,Instantaneous , RaceEnabled, 5,1, false);
}

void DRAMSAN::Instantaneous_Activity3Activity_case1::LinkVariables(){
  ROUTE_WRITE->Register(&ROUTE_WRITE_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  OK_CONTENT_TEMP->Register(&OK_CONTENT_TEMP_Mobius_Mark);
  REPLACE_CONTENT_OK->Register(&REPLACE_CONTENT_OK_Mobius_Mark);
}

bool DRAMSAN::Instantaneous_Activity3Activity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ROUTE_WRITE_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::Instantaneous_Activity3Activity_case1::Weight(){ 
  return 0.5;
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
  (*(ROUTE_WRITE_Mobius_Mark))--;
  if (OK_CONTENT->Mark() + KO_CONTENT->Mark() < dram_size) {

	OK_CONTENT_TEMP->Mark()++;
	OK_CONTENT->Mark()++;	

} else {

	REPLACE_CONTENT_OK->Mark()++;

}
  return this;
}

/*======================Instantaneous_Activity3Activity_case2========================*/


DRAMSAN::Instantaneous_Activity3Activity_case2::Instantaneous_Activity3Activity_case2(){
  ActivityInitialize("Instantaneous_Activity3_case2",5,Instantaneous , RaceEnabled, 5,1, false);
}

void DRAMSAN::Instantaneous_Activity3Activity_case2::LinkVariables(){
  ROUTE_WRITE->Register(&ROUTE_WRITE_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  REPLACE_CONTENT_KO->Register(&REPLACE_CONTENT_KO_Mobius_Mark);
}

bool DRAMSAN::Instantaneous_Activity3Activity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ROUTE_WRITE_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::Instantaneous_Activity3Activity_case2::Weight(){ 
  return 0.5;
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
  (*(ROUTE_WRITE_Mobius_Mark))--;
  if (OK_CONTENT->Mark() + KO_CONTENT->Mark() < dram_size) {

	KO_CONTENT_TEMP->Mark()++;
	KO_CONTENT->Mark()++;

} else {

	REPLACE_CONTENT_KO->Mark()++;

}
  return this;
}

/*======================Instantaneous_Activity5Activity========================*/


DRAMSAN::Instantaneous_Activity5Activity::Instantaneous_Activity5Activity(){
  ActivityInitialize("Instantaneous_Activity5",6,Instantaneous , RaceEnabled, 8,1, false);
}

void DRAMSAN::Instantaneous_Activity5Activity::LinkVariables(){
  WRITE_DRAM->Register(&WRITE_DRAM_Mobius_Mark);
  MEM_FAILURE->Register(&MEM_FAILURE_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  REPLACE_CONTENT_KO->Register(&REPLACE_CONTENT_KO_Mobius_Mark);
  MEM_FAILURE_COUNT->Register(&MEM_FAILURE_COUNT_Mobius_Mark);
  ROUTE_WRITE->Register(&ROUTE_WRITE_Mobius_Mark);
}

bool DRAMSAN::Instantaneous_Activity5Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_DRAM_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::Instantaneous_Activity5Activity::Weight(){ 
  return 1;
}

bool DRAMSAN::Instantaneous_Activity5Activity::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::Instantaneous_Activity5Activity::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::Instantaneous_Activity5Activity::SampleDistribution(){
  return 0;
}

double* DRAMSAN::Instantaneous_Activity5Activity::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::Instantaneous_Activity5Activity::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::Instantaneous_Activity5Activity::Fire(){
  (*(WRITE_DRAM_Mobius_Mark))--;
  if (MEM_FAILURE->Mark() > 0) {

	if (OK_CONTENT->Mark() + KO_CONTENT->Mark() < dram_size) {

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

/*======================REPLACEActivity_case1========================*/


DRAMSAN::REPLACEActivity_case1::REPLACEActivity_case1(){
  ActivityInitialize("REPLACE_case1",7,Instantaneous , RaceEnabled, 2,1, false);
}

void DRAMSAN::REPLACEActivity_case1::LinkVariables(){
  REPLACE_CONTENT_OK->Register(&REPLACE_CONTENT_OK_Mobius_Mark);
  OK_CONTENT_TEMP->Register(&OK_CONTENT_TEMP_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
}

bool DRAMSAN::REPLACEActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(REPLACE_CONTENT_OK_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::REPLACEActivity_case1::Weight(){ 
  return OK_CONTENT->Mark()/dram_size;
}

bool DRAMSAN::REPLACEActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::REPLACEActivity_case1::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::REPLACEActivity_case1::SampleDistribution(){
  return 0;
}

double* DRAMSAN::REPLACEActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::REPLACEActivity_case1::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::REPLACEActivity_case1::Fire(){
  (*(REPLACE_CONTENT_OK_Mobius_Mark))--;
  OK_CONTENT_TEMP->Mark()++;
  return this;
}

/*======================REPLACEActivity_case2========================*/


DRAMSAN::REPLACEActivity_case2::REPLACEActivity_case2(){
  ActivityInitialize("REPLACE_case2",7,Instantaneous , RaceEnabled, 4,1, false);
}

void DRAMSAN::REPLACEActivity_case2::LinkVariables(){
  REPLACE_CONTENT_OK->Register(&REPLACE_CONTENT_OK_Mobius_Mark);
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
}

bool DRAMSAN::REPLACEActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(REPLACE_CONTENT_OK_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::REPLACEActivity_case2::Weight(){ 
  return KO_CONTENT->Mark()/dram_size;
}

bool DRAMSAN::REPLACEActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::REPLACEActivity_case2::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::REPLACEActivity_case2::SampleDistribution(){
  return 0;
}

double* DRAMSAN::REPLACEActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::REPLACEActivity_case2::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::REPLACEActivity_case2::Fire(){
  (*(REPLACE_CONTENT_OK_Mobius_Mark))--;
  KO_CONTENT_TEMP->Mark()++;
OK_CONTENT->Mark()++;
if (KO_CONTENT->Mark() > 0) {
	KO_CONTENT->Mark()--;
}
  return this;
}

/*======================REPLACE_KOActivity_case1========================*/


DRAMSAN::REPLACE_KOActivity_case1::REPLACE_KOActivity_case1(){
  ActivityInitialize("REPLACE_KO_case1",8,Instantaneous , RaceEnabled, 2,1, false);
}

void DRAMSAN::REPLACE_KOActivity_case1::LinkVariables(){
  REPLACE_CONTENT_KO->Register(&REPLACE_CONTENT_KO_Mobius_Mark);
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
}

bool DRAMSAN::REPLACE_KOActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(REPLACE_CONTENT_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::REPLACE_KOActivity_case1::Weight(){ 
  return 0.5;
}

bool DRAMSAN::REPLACE_KOActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::REPLACE_KOActivity_case1::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::REPLACE_KOActivity_case1::SampleDistribution(){
  return 0;
}

double* DRAMSAN::REPLACE_KOActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::REPLACE_KOActivity_case1::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::REPLACE_KOActivity_case1::Fire(){
  (*(REPLACE_CONTENT_KO_Mobius_Mark))--;
  KO_CONTENT_TEMP->Mark()++;
  return this;
}

/*======================REPLACE_KOActivity_case2========================*/


DRAMSAN::REPLACE_KOActivity_case2::REPLACE_KOActivity_case2(){
  ActivityInitialize("REPLACE_KO_case2",8,Instantaneous , RaceEnabled, 4,1, false);
}

void DRAMSAN::REPLACE_KOActivity_case2::LinkVariables(){
  REPLACE_CONTENT_KO->Register(&REPLACE_CONTENT_KO_Mobius_Mark);
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
}

bool DRAMSAN::REPLACE_KOActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(REPLACE_CONTENT_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAMSAN::REPLACE_KOActivity_case2::Weight(){ 
  return 0.5;
}

bool DRAMSAN::REPLACE_KOActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool DRAMSAN::REPLACE_KOActivity_case2::ReactivationFunction(){ 
  return false;
}

double DRAMSAN::REPLACE_KOActivity_case2::SampleDistribution(){
  return 0;
}

double* DRAMSAN::REPLACE_KOActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int DRAMSAN::REPLACE_KOActivity_case2::Rank(){
  return 1;
}

BaseActionClass* DRAMSAN::REPLACE_KOActivity_case2::Fire(){
  (*(REPLACE_CONTENT_KO_Mobius_Mark))--;
  KO_CONTENT_TEMP->Mark()++;
KO_CONTENT->Mark()++;
if (OK_CONTENT->Mark() > 0) {
	OK_CONTENT->Mark()--;
}
  return this;
}

/*======================Instantaneous_Activity23Activity========================*/


DRAMSAN::Instantaneous_Activity23Activity::Instantaneous_Activity23Activity(){
  ActivityInitialize("Instantaneous_Activity23",9,Instantaneous , RaceEnabled, 2,1, false);
}

void DRAMSAN::Instantaneous_Activity23Activity::LinkVariables(){
  KO_CONTENT_TEMP->Register(&KO_CONTENT_TEMP_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
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
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity12Activity========================*/


DRAMSAN::Instantaneous_Activity12Activity::Instantaneous_Activity12Activity(){
  ActivityInitialize("Instantaneous_Activity12",10,Instantaneous , RaceEnabled, 2,1, false);
}

void DRAMSAN::Instantaneous_Activity12Activity::LinkVariables(){
  OK_CONTENT_TEMP->Register(&OK_CONTENT_TEMP_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
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
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

