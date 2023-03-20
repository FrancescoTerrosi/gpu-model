

// This C++ file was created by SanEditor

#include "Atomic/MEMORY/MEMORYSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         MEMORYSAN Constructor             
******************************************************************/


MEMORYSAN::MEMORYSAN(){


  LOCAL_READ_FROMGroup.initialize(3, "LOCAL_READ_FROMGroup");
  LOCAL_READ_FROMGroup.appendGroup((BaseGroupClass*) &LOCAL_READ_FROM_case1);
  LOCAL_READ_FROMGroup.appendGroup((BaseGroupClass*) &LOCAL_READ_FROM_case2);
  LOCAL_READ_FROMGroup.appendGroup((BaseGroupClass*) &LOCAL_READ_FROM_case3);

  GLOBAL_READ_FROMGroup.initialize(3, "GLOBAL_READ_FROMGroup");
  GLOBAL_READ_FROMGroup.appendGroup((BaseGroupClass*) &GLOBAL_READ_FROM_case1);
  GLOBAL_READ_FROMGroup.appendGroup((BaseGroupClass*) &GLOBAL_READ_FROM_case2);
  GLOBAL_READ_FROMGroup.appendGroup((BaseGroupClass*) &GLOBAL_READ_FROM_case3);

  LOCAL_WRITE_TOGroup.initialize(3, "LOCAL_WRITE_TOGroup");
  LOCAL_WRITE_TOGroup.appendGroup((BaseGroupClass*) &LOCAL_WRITE_TO_case1);
  LOCAL_WRITE_TOGroup.appendGroup((BaseGroupClass*) &LOCAL_WRITE_TO_case2);
  LOCAL_WRITE_TOGroup.appendGroup((BaseGroupClass*) &LOCAL_WRITE_TO_case3);

  GLOBAL_WRITE_TOGroup.initialize(3, "GLOBAL_WRITE_TOGroup");
  GLOBAL_WRITE_TOGroup.appendGroup((BaseGroupClass*) &GLOBAL_WRITE_TO_case1);
  GLOBAL_WRITE_TOGroup.appendGroup((BaseGroupClass*) &GLOBAL_WRITE_TO_case2);
  GLOBAL_WRITE_TOGroup.appendGroup((BaseGroupClass*) &GLOBAL_WRITE_TO_case3);

  Activity* InitialActionList[16]={
    &PERFORM_READ, //0
    &LOCAL_READ_FROM_case1, //1
    &LOCAL_READ_FROM_case2, //2
    &LOCAL_READ_FROM_case3, //3
    &GLOBAL_READ_FROM_case1, //4
    &GLOBAL_READ_FROM_case2, //5
    &GLOBAL_READ_FROM_case3, //6
    &PERFORM_WRITE, //7
    &LOCAL_WRITE_TO_case1, //8
    &LOCAL_WRITE_TO_case2, //9
    &LOCAL_WRITE_TO_case3, //10
    &GLOBAL_WRITE_TO_case1, //11
    &GLOBAL_WRITE_TO_case2, //12
    &GLOBAL_WRITE_TO_case3, //13
    &inst1, //14
    &inst2  // 15
  };

  BaseGroupClass* InitialGroupList[8]={
    (BaseGroupClass*) &(PERFORM_READ), 
    (BaseGroupClass*) &(LOCAL_READ_FROMGroup), 
    (BaseGroupClass*) &(GLOBAL_READ_FROMGroup), 
    (BaseGroupClass*) &(PERFORM_WRITE), 
    (BaseGroupClass*) &(LOCAL_WRITE_TOGroup), 
    (BaseGroupClass*) &(GLOBAL_WRITE_TOGroup), 
    (BaseGroupClass*) &(inst1), 
    (BaseGroupClass*) &(inst2)
  };

  READ_L1 = new Place("READ_L1" ,0);
  READ_L2 = new Place("READ_L2" ,0);
  READ_DRAM = new Place("READ_DRAM" ,0);
  READ_LOCAL = new Place("READ_LOCAL" ,0);
  READ_GLOBAL = new Place("READ_GLOBAL" ,0);
  WRITE_LOCAL = new Place("WRITE_LOCAL" ,0);
  WRITE_GLOBAL = new Place("WRITE_GLOBAL" ,0);
  WRITE_L1 = new Place("WRITE_L1" ,0);
  WRITE_L2 = new Place("WRITE_L2" ,0);
  WRITE_DRAM = new Place("WRITE_DRAM" ,0);
  READ_REGISTER_FILE = new Place("READ_REGISTER_FILE" ,0);
  WRITE_REGISTER_FILE = new Place("WRITE_REGISTER_FILE" ,0);
  OK_READ = new Place("OK_READ" ,0);
  KO_READ = new Place("KO_READ" ,0);
  RESULT_OK = new Place("RESULT_OK" ,0);
  RESULT_KO = new Place("RESULT_KO" ,0);
  short temp_READshort = -1;
  READ = new ExtendedPlace<short>("READ",temp_READshort);
  short temp_WRITEshort = -1;
  WRITE = new ExtendedPlace<short>("WRITE",temp_WRITEshort);
  BaseStateVariableClass* InitialPlaces[18]={
    READ_L1,  // 0
    READ_L2,  // 1
    READ_DRAM,  // 2
    READ_LOCAL,  // 3
    READ_GLOBAL,  // 4
    WRITE_LOCAL,  // 5
    WRITE_GLOBAL,  // 6
    WRITE_L1,  // 7
    WRITE_L2,  // 8
    WRITE_DRAM,  // 9
    READ_REGISTER_FILE,  // 10
    WRITE_REGISTER_FILE,  // 11
    OK_READ,  // 12
    KO_READ,  // 13
    RESULT_OK,  // 14
    RESULT_KO,  // 15
    READ,  // 16
    WRITE   // 17
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("MEMORY", 18, InitialPlaces, 
                        0, InitialROPlaces, 
                        16, InitialActionList, 8, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[39][2]={ 
    {5,0}, {16,0}, {3,0}, {4,0}, {10,0}, {3,1}, {0,1}, {3,2}, 
    {1,2}, {3,3}, {2,3}, {4,4}, {0,4}, {4,5}, {1,5}, {4,6}, {2,6}, 
    {6,7}, {17,7}, {5,7}, {11,7}, {5,8}, {7,8}, {5,9}, {8,9}, 
    {5,10}, {9,10}, {6,11}, {7,11}, {6,12}, {8,12}, {6,13}, {9,13}, 
    {12,14}, {14,14}, {11,14}, {13,15}, {15,15}, {11,15}
  };
  for(int n=0;n<39;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[16][2]={ 
    {16,0}, {3,1}, {3,2}, {3,3}, {4,4}, {4,5}, {4,6}, {17,7}, 
    {5,8}, {5,9}, {5,10}, {6,11}, {6,12}, {6,13}, {12,14}, {13,15}
  };
  for(int n=0;n<16;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<16;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void MEMORYSAN::CustomInitialization() {

}
MEMORYSAN::~MEMORYSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void MEMORYSAN::assignPlacesToActivitiesInst(){
  PERFORM_READ.READ = (ExtendedPlace<short>*) LocalStateVariables[16];
  PERFORM_READ.WRITE_LOCAL = (Place*) LocalStateVariables[5];
  PERFORM_READ.READ_LOCAL = (Place*) LocalStateVariables[3];
  PERFORM_READ.READ_GLOBAL = (Place*) LocalStateVariables[4];
  PERFORM_READ.READ_REGISTER_FILE = (Place*) LocalStateVariables[10];
  LOCAL_READ_FROM_case1.READ_LOCAL = (Place*) LocalStateVariables[3];
  LOCAL_READ_FROM_case1.READ_L1 = (Place*) LocalStateVariables[0];
  LOCAL_READ_FROM_case2.READ_LOCAL = (Place*) LocalStateVariables[3];
  LOCAL_READ_FROM_case2.READ_L2 = (Place*) LocalStateVariables[1];
  LOCAL_READ_FROM_case3.READ_LOCAL = (Place*) LocalStateVariables[3];
  LOCAL_READ_FROM_case3.READ_DRAM = (Place*) LocalStateVariables[2];
  GLOBAL_READ_FROM_case1.READ_GLOBAL = (Place*) LocalStateVariables[4];
  GLOBAL_READ_FROM_case1.READ_L1 = (Place*) LocalStateVariables[0];
  GLOBAL_READ_FROM_case2.READ_GLOBAL = (Place*) LocalStateVariables[4];
  GLOBAL_READ_FROM_case2.READ_L2 = (Place*) LocalStateVariables[1];
  GLOBAL_READ_FROM_case3.READ_GLOBAL = (Place*) LocalStateVariables[4];
  GLOBAL_READ_FROM_case3.READ_DRAM = (Place*) LocalStateVariables[2];
  PERFORM_WRITE.WRITE = (ExtendedPlace<short>*) LocalStateVariables[17];
  PERFORM_WRITE.WRITE_GLOBAL = (Place*) LocalStateVariables[6];
  PERFORM_WRITE.WRITE_LOCAL = (Place*) LocalStateVariables[5];
  PERFORM_WRITE.WRITE_REGISTER_FILE = (Place*) LocalStateVariables[11];
  LOCAL_WRITE_TO_case1.WRITE_LOCAL = (Place*) LocalStateVariables[5];
  LOCAL_WRITE_TO_case1.WRITE_L1 = (Place*) LocalStateVariables[7];
  LOCAL_WRITE_TO_case2.WRITE_LOCAL = (Place*) LocalStateVariables[5];
  LOCAL_WRITE_TO_case2.WRITE_L2 = (Place*) LocalStateVariables[8];
  LOCAL_WRITE_TO_case3.WRITE_LOCAL = (Place*) LocalStateVariables[5];
  LOCAL_WRITE_TO_case3.WRITE_DRAM = (Place*) LocalStateVariables[9];
  GLOBAL_WRITE_TO_case1.WRITE_GLOBAL = (Place*) LocalStateVariables[6];
  GLOBAL_WRITE_TO_case1.WRITE_L1 = (Place*) LocalStateVariables[7];
  GLOBAL_WRITE_TO_case2.WRITE_GLOBAL = (Place*) LocalStateVariables[6];
  GLOBAL_WRITE_TO_case2.WRITE_L2 = (Place*) LocalStateVariables[8];
  GLOBAL_WRITE_TO_case3.WRITE_GLOBAL = (Place*) LocalStateVariables[6];
  GLOBAL_WRITE_TO_case3.WRITE_DRAM = (Place*) LocalStateVariables[9];
  inst1.OK_READ = (Place*) LocalStateVariables[12];
  inst1.RESULT_OK = (Place*) LocalStateVariables[14];
  inst1.WRITE_REGISTER_FILE = (Place*) LocalStateVariables[11];
  inst2.KO_READ = (Place*) LocalStateVariables[13];
  inst2.RESULT_KO = (Place*) LocalStateVariables[15];
  inst2.WRITE_REGISTER_FILE = (Place*) LocalStateVariables[11];
}
void MEMORYSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================PERFORM_READActivity========================*/


MEMORYSAN::PERFORM_READActivity::PERFORM_READActivity(){
  ActivityInitialize("PERFORM_READ",0,Instantaneous , RaceEnabled, 5,1, false);
}

void MEMORYSAN::PERFORM_READActivity::LinkVariables(){

  WRITE_LOCAL->Register(&WRITE_LOCAL_Mobius_Mark);
  READ_LOCAL->Register(&READ_LOCAL_Mobius_Mark);
  READ_GLOBAL->Register(&READ_GLOBAL_Mobius_Mark);
  READ_REGISTER_FILE->Register(&READ_REGISTER_FILE_Mobius_Mark);
}

bool MEMORYSAN::PERFORM_READActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((READ->Mark() > -1));
  return NewEnabled;
}

double MEMORYSAN::PERFORM_READActivity::Weight(){ 
  return 1;
}

bool MEMORYSAN::PERFORM_READActivity::ReactivationPredicate(){ 
  return false;
}

bool MEMORYSAN::PERFORM_READActivity::ReactivationFunction(){ 
  return false;
}

double MEMORYSAN::PERFORM_READActivity::SampleDistribution(){
  return 0;
}

double* MEMORYSAN::PERFORM_READActivity::ReturnDistributionParameters(){
    return NULL;
}

int MEMORYSAN::PERFORM_READActivity::Rank(){
  return 1;
}

BaseActionClass* MEMORYSAN::PERFORM_READActivity::Fire(){
  WRITE_LOCAL->Mark()--;
WRITE_LOCAL->Mark()++;
  switch (READ->Mark()) {

	case 0:
		READ_LOCAL->Mark()++;
	break;

	case 2:
		READ_GLOBAL->Mark()++;
	break;

	case 4:
		READ_REGISTER_FILE->Mark()++;
	break;

	default:
	break;

}

READ->Mark() = -1;
  return this;
}

/*======================LOCAL_READ_FROMActivity_case1========================*/


MEMORYSAN::LOCAL_READ_FROMActivity_case1::LOCAL_READ_FROMActivity_case1(){
  ActivityInitialize("LOCAL_READ_FROM_case1",1,Instantaneous , RaceEnabled, 2,1, false);
}

void MEMORYSAN::LOCAL_READ_FROMActivity_case1::LinkVariables(){
  READ_LOCAL->Register(&READ_LOCAL_Mobius_Mark);
  READ_L1->Register(&READ_L1_Mobius_Mark);
}

bool MEMORYSAN::LOCAL_READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_LOCAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::LOCAL_READ_FROMActivity_case1::Weight(){ 
  return 1;
}

bool MEMORYSAN::LOCAL_READ_FROMActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool MEMORYSAN::LOCAL_READ_FROMActivity_case1::ReactivationFunction(){ 
  return false;
}

double MEMORYSAN::LOCAL_READ_FROMActivity_case1::SampleDistribution(){
  return 0;
}

double* MEMORYSAN::LOCAL_READ_FROMActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int MEMORYSAN::LOCAL_READ_FROMActivity_case1::Rank(){
  return 1;
}

BaseActionClass* MEMORYSAN::LOCAL_READ_FROMActivity_case1::Fire(){
  (*(READ_LOCAL_Mobius_Mark))--;
  (*(READ_L1_Mobius_Mark))++;
  return this;
}

/*======================LOCAL_READ_FROMActivity_case2========================*/


MEMORYSAN::LOCAL_READ_FROMActivity_case2::LOCAL_READ_FROMActivity_case2(){
  ActivityInitialize("LOCAL_READ_FROM_case2",1,Instantaneous , RaceEnabled, 2,1, false);
}

void MEMORYSAN::LOCAL_READ_FROMActivity_case2::LinkVariables(){
  READ_LOCAL->Register(&READ_LOCAL_Mobius_Mark);
  READ_L2->Register(&READ_L2_Mobius_Mark);
}

bool MEMORYSAN::LOCAL_READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_LOCAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::LOCAL_READ_FROMActivity_case2::Weight(){ 
  return 0;
}

bool MEMORYSAN::LOCAL_READ_FROMActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool MEMORYSAN::LOCAL_READ_FROMActivity_case2::ReactivationFunction(){ 
  return false;
}

double MEMORYSAN::LOCAL_READ_FROMActivity_case2::SampleDistribution(){
  return 0;
}

double* MEMORYSAN::LOCAL_READ_FROMActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int MEMORYSAN::LOCAL_READ_FROMActivity_case2::Rank(){
  return 1;
}

BaseActionClass* MEMORYSAN::LOCAL_READ_FROMActivity_case2::Fire(){
  (*(READ_LOCAL_Mobius_Mark))--;
  (*(READ_L2_Mobius_Mark))++;
  return this;
}

/*======================LOCAL_READ_FROMActivity_case3========================*/


MEMORYSAN::LOCAL_READ_FROMActivity_case3::LOCAL_READ_FROMActivity_case3(){
  ActivityInitialize("LOCAL_READ_FROM_case3",1,Instantaneous , RaceEnabled, 2,1, false);
}

void MEMORYSAN::LOCAL_READ_FROMActivity_case3::LinkVariables(){
  READ_LOCAL->Register(&READ_LOCAL_Mobius_Mark);
  READ_DRAM->Register(&READ_DRAM_Mobius_Mark);
}

bool MEMORYSAN::LOCAL_READ_FROMActivity_case3::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_LOCAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::LOCAL_READ_FROMActivity_case3::Weight(){ 
  return 0;
}

bool MEMORYSAN::LOCAL_READ_FROMActivity_case3::ReactivationPredicate(){ 
  return false;
}

bool MEMORYSAN::LOCAL_READ_FROMActivity_case3::ReactivationFunction(){ 
  return false;
}

double MEMORYSAN::LOCAL_READ_FROMActivity_case3::SampleDistribution(){
  return 0;
}

double* MEMORYSAN::LOCAL_READ_FROMActivity_case3::ReturnDistributionParameters(){
    return NULL;
}

int MEMORYSAN::LOCAL_READ_FROMActivity_case3::Rank(){
  return 1;
}

BaseActionClass* MEMORYSAN::LOCAL_READ_FROMActivity_case3::Fire(){
  (*(READ_LOCAL_Mobius_Mark))--;
  (*(READ_DRAM_Mobius_Mark))++;
  return this;
}

/*======================GLOBAL_READ_FROMActivity_case1========================*/


MEMORYSAN::GLOBAL_READ_FROMActivity_case1::GLOBAL_READ_FROMActivity_case1(){
  ActivityInitialize("GLOBAL_READ_FROM_case1",2,Instantaneous , RaceEnabled, 2,1, false);
}

void MEMORYSAN::GLOBAL_READ_FROMActivity_case1::LinkVariables(){
  READ_GLOBAL->Register(&READ_GLOBAL_Mobius_Mark);
  READ_L1->Register(&READ_L1_Mobius_Mark);
}

bool MEMORYSAN::GLOBAL_READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_GLOBAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::GLOBAL_READ_FROMActivity_case1::Weight(){ 
  return 1/3;
}

bool MEMORYSAN::GLOBAL_READ_FROMActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool MEMORYSAN::GLOBAL_READ_FROMActivity_case1::ReactivationFunction(){ 
  return false;
}

double MEMORYSAN::GLOBAL_READ_FROMActivity_case1::SampleDistribution(){
  return 0;
}

double* MEMORYSAN::GLOBAL_READ_FROMActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int MEMORYSAN::GLOBAL_READ_FROMActivity_case1::Rank(){
  return 1;
}

BaseActionClass* MEMORYSAN::GLOBAL_READ_FROMActivity_case1::Fire(){
  (*(READ_GLOBAL_Mobius_Mark))--;
  (*(READ_L1_Mobius_Mark))++;
  return this;
}

/*======================GLOBAL_READ_FROMActivity_case2========================*/


MEMORYSAN::GLOBAL_READ_FROMActivity_case2::GLOBAL_READ_FROMActivity_case2(){
  ActivityInitialize("GLOBAL_READ_FROM_case2",2,Instantaneous , RaceEnabled, 2,1, false);
}

void MEMORYSAN::GLOBAL_READ_FROMActivity_case2::LinkVariables(){
  READ_GLOBAL->Register(&READ_GLOBAL_Mobius_Mark);
  READ_L2->Register(&READ_L2_Mobius_Mark);
}

bool MEMORYSAN::GLOBAL_READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_GLOBAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::GLOBAL_READ_FROMActivity_case2::Weight(){ 
  return 1/3;
}

bool MEMORYSAN::GLOBAL_READ_FROMActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool MEMORYSAN::GLOBAL_READ_FROMActivity_case2::ReactivationFunction(){ 
  return false;
}

double MEMORYSAN::GLOBAL_READ_FROMActivity_case2::SampleDistribution(){
  return 0;
}

double* MEMORYSAN::GLOBAL_READ_FROMActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int MEMORYSAN::GLOBAL_READ_FROMActivity_case2::Rank(){
  return 1;
}

BaseActionClass* MEMORYSAN::GLOBAL_READ_FROMActivity_case2::Fire(){
  (*(READ_GLOBAL_Mobius_Mark))--;
  (*(READ_L2_Mobius_Mark))++;
  return this;
}

/*======================GLOBAL_READ_FROMActivity_case3========================*/


MEMORYSAN::GLOBAL_READ_FROMActivity_case3::GLOBAL_READ_FROMActivity_case3(){
  ActivityInitialize("GLOBAL_READ_FROM_case3",2,Instantaneous , RaceEnabled, 2,1, false);
}

void MEMORYSAN::GLOBAL_READ_FROMActivity_case3::LinkVariables(){
  READ_GLOBAL->Register(&READ_GLOBAL_Mobius_Mark);
  READ_DRAM->Register(&READ_DRAM_Mobius_Mark);
}

bool MEMORYSAN::GLOBAL_READ_FROMActivity_case3::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_GLOBAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::GLOBAL_READ_FROMActivity_case3::Weight(){ 
  return 1/3;
}

bool MEMORYSAN::GLOBAL_READ_FROMActivity_case3::ReactivationPredicate(){ 
  return false;
}

bool MEMORYSAN::GLOBAL_READ_FROMActivity_case3::ReactivationFunction(){ 
  return false;
}

double MEMORYSAN::GLOBAL_READ_FROMActivity_case3::SampleDistribution(){
  return 0;
}

double* MEMORYSAN::GLOBAL_READ_FROMActivity_case3::ReturnDistributionParameters(){
    return NULL;
}

int MEMORYSAN::GLOBAL_READ_FROMActivity_case3::Rank(){
  return 1;
}

BaseActionClass* MEMORYSAN::GLOBAL_READ_FROMActivity_case3::Fire(){
  (*(READ_GLOBAL_Mobius_Mark))--;
  (*(READ_DRAM_Mobius_Mark))++;
  return this;
}

/*======================PERFORM_WRITEActivity========================*/


MEMORYSAN::PERFORM_WRITEActivity::PERFORM_WRITEActivity(){
  ActivityInitialize("PERFORM_WRITE",3,Instantaneous , RaceEnabled, 4,1, false);
}

void MEMORYSAN::PERFORM_WRITEActivity::LinkVariables(){

  WRITE_GLOBAL->Register(&WRITE_GLOBAL_Mobius_Mark);
  WRITE_LOCAL->Register(&WRITE_LOCAL_Mobius_Mark);
  WRITE_REGISTER_FILE->Register(&WRITE_REGISTER_FILE_Mobius_Mark);
}

bool MEMORYSAN::PERFORM_WRITEActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((WRITE->Mark() > -1));
  return NewEnabled;
}

double MEMORYSAN::PERFORM_WRITEActivity::Weight(){ 
  return 1;
}

bool MEMORYSAN::PERFORM_WRITEActivity::ReactivationPredicate(){ 
  return false;
}

bool MEMORYSAN::PERFORM_WRITEActivity::ReactivationFunction(){ 
  return false;
}

double MEMORYSAN::PERFORM_WRITEActivity::SampleDistribution(){
  return 0;
}

double* MEMORYSAN::PERFORM_WRITEActivity::ReturnDistributionParameters(){
    return NULL;
}

int MEMORYSAN::PERFORM_WRITEActivity::Rank(){
  return 1;
}

BaseActionClass* MEMORYSAN::PERFORM_WRITEActivity::Fire(){
  WRITE_GLOBAL->Mark()++;
WRITE_GLOBAL->Mark()--;
  switch (WRITE->Mark()) {

	case 1:
		WRITE_LOCAL->Mark()++;
	break;

	case 3:
		WRITE_GLOBAL->Mark()++;
	break;

	case 5:
		WRITE_REGISTER_FILE->Mark()++;
	break;

	deafult:
	break;
}

WRITE->Mark() = -1;
  return this;
}

/*======================LOCAL_WRITE_TOActivity_case1========================*/


MEMORYSAN::LOCAL_WRITE_TOActivity_case1::LOCAL_WRITE_TOActivity_case1(){
  ActivityInitialize("LOCAL_WRITE_TO_case1",4,Instantaneous , RaceEnabled, 2,1, false);
}

void MEMORYSAN::LOCAL_WRITE_TOActivity_case1::LinkVariables(){
  WRITE_LOCAL->Register(&WRITE_LOCAL_Mobius_Mark);
  WRITE_L1->Register(&WRITE_L1_Mobius_Mark);
}

bool MEMORYSAN::LOCAL_WRITE_TOActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_LOCAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::LOCAL_WRITE_TOActivity_case1::Weight(){ 
  return 1/3;
}

bool MEMORYSAN::LOCAL_WRITE_TOActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool MEMORYSAN::LOCAL_WRITE_TOActivity_case1::ReactivationFunction(){ 
  return false;
}

double MEMORYSAN::LOCAL_WRITE_TOActivity_case1::SampleDistribution(){
  return 0;
}

double* MEMORYSAN::LOCAL_WRITE_TOActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int MEMORYSAN::LOCAL_WRITE_TOActivity_case1::Rank(){
  return 1;
}

BaseActionClass* MEMORYSAN::LOCAL_WRITE_TOActivity_case1::Fire(){
  (*(WRITE_LOCAL_Mobius_Mark))--;
  (*(WRITE_L1_Mobius_Mark))++;
  return this;
}

/*======================LOCAL_WRITE_TOActivity_case2========================*/


MEMORYSAN::LOCAL_WRITE_TOActivity_case2::LOCAL_WRITE_TOActivity_case2(){
  ActivityInitialize("LOCAL_WRITE_TO_case2",4,Instantaneous , RaceEnabled, 2,1, false);
}

void MEMORYSAN::LOCAL_WRITE_TOActivity_case2::LinkVariables(){
  WRITE_LOCAL->Register(&WRITE_LOCAL_Mobius_Mark);
  WRITE_L2->Register(&WRITE_L2_Mobius_Mark);
}

bool MEMORYSAN::LOCAL_WRITE_TOActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_LOCAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::LOCAL_WRITE_TOActivity_case2::Weight(){ 
  return 1/3;
}

bool MEMORYSAN::LOCAL_WRITE_TOActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool MEMORYSAN::LOCAL_WRITE_TOActivity_case2::ReactivationFunction(){ 
  return false;
}

double MEMORYSAN::LOCAL_WRITE_TOActivity_case2::SampleDistribution(){
  return 0;
}

double* MEMORYSAN::LOCAL_WRITE_TOActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int MEMORYSAN::LOCAL_WRITE_TOActivity_case2::Rank(){
  return 1;
}

BaseActionClass* MEMORYSAN::LOCAL_WRITE_TOActivity_case2::Fire(){
  (*(WRITE_LOCAL_Mobius_Mark))--;
  (*(WRITE_L2_Mobius_Mark))++;
  return this;
}

/*======================LOCAL_WRITE_TOActivity_case3========================*/


MEMORYSAN::LOCAL_WRITE_TOActivity_case3::LOCAL_WRITE_TOActivity_case3(){
  ActivityInitialize("LOCAL_WRITE_TO_case3",4,Instantaneous , RaceEnabled, 2,1, false);
}

void MEMORYSAN::LOCAL_WRITE_TOActivity_case3::LinkVariables(){
  WRITE_LOCAL->Register(&WRITE_LOCAL_Mobius_Mark);
  WRITE_DRAM->Register(&WRITE_DRAM_Mobius_Mark);
}

bool MEMORYSAN::LOCAL_WRITE_TOActivity_case3::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_LOCAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::LOCAL_WRITE_TOActivity_case3::Weight(){ 
  return 1/3;
}

bool MEMORYSAN::LOCAL_WRITE_TOActivity_case3::ReactivationPredicate(){ 
  return false;
}

bool MEMORYSAN::LOCAL_WRITE_TOActivity_case3::ReactivationFunction(){ 
  return false;
}

double MEMORYSAN::LOCAL_WRITE_TOActivity_case3::SampleDistribution(){
  return 0;
}

double* MEMORYSAN::LOCAL_WRITE_TOActivity_case3::ReturnDistributionParameters(){
    return NULL;
}

int MEMORYSAN::LOCAL_WRITE_TOActivity_case3::Rank(){
  return 1;
}

BaseActionClass* MEMORYSAN::LOCAL_WRITE_TOActivity_case3::Fire(){
  (*(WRITE_LOCAL_Mobius_Mark))--;
  (*(WRITE_DRAM_Mobius_Mark))++;
  return this;
}

/*======================GLOBAL_WRITE_TOActivity_case1========================*/


MEMORYSAN::GLOBAL_WRITE_TOActivity_case1::GLOBAL_WRITE_TOActivity_case1(){
  ActivityInitialize("GLOBAL_WRITE_TO_case1",5,Instantaneous , RaceEnabled, 2,1, false);
}

void MEMORYSAN::GLOBAL_WRITE_TOActivity_case1::LinkVariables(){
  WRITE_GLOBAL->Register(&WRITE_GLOBAL_Mobius_Mark);
  WRITE_L1->Register(&WRITE_L1_Mobius_Mark);
}

bool MEMORYSAN::GLOBAL_WRITE_TOActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_GLOBAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::GLOBAL_WRITE_TOActivity_case1::Weight(){ 
  return 1/3;
}

bool MEMORYSAN::GLOBAL_WRITE_TOActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool MEMORYSAN::GLOBAL_WRITE_TOActivity_case1::ReactivationFunction(){ 
  return false;
}

double MEMORYSAN::GLOBAL_WRITE_TOActivity_case1::SampleDistribution(){
  return 0;
}

double* MEMORYSAN::GLOBAL_WRITE_TOActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int MEMORYSAN::GLOBAL_WRITE_TOActivity_case1::Rank(){
  return 1;
}

BaseActionClass* MEMORYSAN::GLOBAL_WRITE_TOActivity_case1::Fire(){
  (*(WRITE_GLOBAL_Mobius_Mark))--;
  (*(WRITE_L1_Mobius_Mark))++;
  return this;
}

/*======================GLOBAL_WRITE_TOActivity_case2========================*/


MEMORYSAN::GLOBAL_WRITE_TOActivity_case2::GLOBAL_WRITE_TOActivity_case2(){
  ActivityInitialize("GLOBAL_WRITE_TO_case2",5,Instantaneous , RaceEnabled, 2,1, false);
}

void MEMORYSAN::GLOBAL_WRITE_TOActivity_case2::LinkVariables(){
  WRITE_GLOBAL->Register(&WRITE_GLOBAL_Mobius_Mark);
  WRITE_L2->Register(&WRITE_L2_Mobius_Mark);
}

bool MEMORYSAN::GLOBAL_WRITE_TOActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_GLOBAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::GLOBAL_WRITE_TOActivity_case2::Weight(){ 
  return 1/3;
}

bool MEMORYSAN::GLOBAL_WRITE_TOActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool MEMORYSAN::GLOBAL_WRITE_TOActivity_case2::ReactivationFunction(){ 
  return false;
}

double MEMORYSAN::GLOBAL_WRITE_TOActivity_case2::SampleDistribution(){
  return 0;
}

double* MEMORYSAN::GLOBAL_WRITE_TOActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int MEMORYSAN::GLOBAL_WRITE_TOActivity_case2::Rank(){
  return 1;
}

BaseActionClass* MEMORYSAN::GLOBAL_WRITE_TOActivity_case2::Fire(){
  (*(WRITE_GLOBAL_Mobius_Mark))--;
  (*(WRITE_L2_Mobius_Mark))++;
  return this;
}

/*======================GLOBAL_WRITE_TOActivity_case3========================*/


MEMORYSAN::GLOBAL_WRITE_TOActivity_case3::GLOBAL_WRITE_TOActivity_case3(){
  ActivityInitialize("GLOBAL_WRITE_TO_case3",5,Instantaneous , RaceEnabled, 2,1, false);
}

void MEMORYSAN::GLOBAL_WRITE_TOActivity_case3::LinkVariables(){
  WRITE_GLOBAL->Register(&WRITE_GLOBAL_Mobius_Mark);
  WRITE_DRAM->Register(&WRITE_DRAM_Mobius_Mark);
}

bool MEMORYSAN::GLOBAL_WRITE_TOActivity_case3::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_GLOBAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::GLOBAL_WRITE_TOActivity_case3::Weight(){ 
  return 1/3;
}

bool MEMORYSAN::GLOBAL_WRITE_TOActivity_case3::ReactivationPredicate(){ 
  return false;
}

bool MEMORYSAN::GLOBAL_WRITE_TOActivity_case3::ReactivationFunction(){ 
  return false;
}

double MEMORYSAN::GLOBAL_WRITE_TOActivity_case3::SampleDistribution(){
  return 0;
}

double* MEMORYSAN::GLOBAL_WRITE_TOActivity_case3::ReturnDistributionParameters(){
    return NULL;
}

int MEMORYSAN::GLOBAL_WRITE_TOActivity_case3::Rank(){
  return 1;
}

BaseActionClass* MEMORYSAN::GLOBAL_WRITE_TOActivity_case3::Fire(){
  (*(WRITE_GLOBAL_Mobius_Mark))--;
  (*(WRITE_DRAM_Mobius_Mark))++;
  return this;
}

/*======================inst1Activity========================*/


MEMORYSAN::inst1Activity::inst1Activity(){
  ActivityInitialize("inst1",6,Instantaneous , RaceEnabled, 3,1, false);
}

void MEMORYSAN::inst1Activity::LinkVariables(){
  OK_READ->Register(&OK_READ_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
  WRITE_REGISTER_FILE->Register(&WRITE_REGISTER_FILE_Mobius_Mark);
}

bool MEMORYSAN::inst1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(OK_READ_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::inst1Activity::Weight(){ 
  return 1;
}

bool MEMORYSAN::inst1Activity::ReactivationPredicate(){ 
  return false;
}

bool MEMORYSAN::inst1Activity::ReactivationFunction(){ 
  return false;
}

double MEMORYSAN::inst1Activity::SampleDistribution(){
  return 0;
}

double* MEMORYSAN::inst1Activity::ReturnDistributionParameters(){
    return NULL;
}

int MEMORYSAN::inst1Activity::Rank(){
  return 1;
}

BaseActionClass* MEMORYSAN::inst1Activity::Fire(){
  (*(OK_READ_Mobius_Mark))--;
  (*(RESULT_OK_Mobius_Mark))++;
  (*(WRITE_REGISTER_FILE_Mobius_Mark))++;
  return this;
}

/*======================inst2Activity========================*/


MEMORYSAN::inst2Activity::inst2Activity(){
  ActivityInitialize("inst2",7,Instantaneous , RaceEnabled, 3,1, false);
}

void MEMORYSAN::inst2Activity::LinkVariables(){
  KO_READ->Register(&KO_READ_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
  WRITE_REGISTER_FILE->Register(&WRITE_REGISTER_FILE_Mobius_Mark);
}

bool MEMORYSAN::inst2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(KO_READ_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::inst2Activity::Weight(){ 
  return 1;
}

bool MEMORYSAN::inst2Activity::ReactivationPredicate(){ 
  return false;
}

bool MEMORYSAN::inst2Activity::ReactivationFunction(){ 
  return false;
}

double MEMORYSAN::inst2Activity::SampleDistribution(){
  return 0;
}

double* MEMORYSAN::inst2Activity::ReturnDistributionParameters(){
    return NULL;
}

int MEMORYSAN::inst2Activity::Rank(){
  return 1;
}

BaseActionClass* MEMORYSAN::inst2Activity::Fire(){
  (*(KO_READ_Mobius_Mark))--;
  (*(RESULT_KO_Mobius_Mark))++;
  (*(WRITE_REGISTER_FILE_Mobius_Mark))++;
  return this;
}

