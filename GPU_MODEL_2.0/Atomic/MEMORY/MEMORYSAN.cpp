

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

  Activity* InitialActionList[14]={
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
    &GLOBAL_WRITE_TO_case3  // 13
  };

  BaseGroupClass* InitialGroupList[6]={
    (BaseGroupClass*) &(PERFORM_READ), 
    (BaseGroupClass*) &(LOCAL_READ_FROMGroup), 
    (BaseGroupClass*) &(GLOBAL_READ_FROMGroup), 
    (BaseGroupClass*) &(PERFORM_WRITE), 
    (BaseGroupClass*) &(LOCAL_WRITE_TOGroup), 
    (BaseGroupClass*) &(GLOBAL_WRITE_TOGroup)
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
  WARP_ACCESS_L1 = new Place("WARP_ACCESS_L1" ,0);
  WARP_ACCESS_L2 = new Place("WARP_ACCESS_L2" ,0);
  WARP_ACCESS_DRAM = new Place("WARP_ACCESS_DRAM" ,0);
  short temp_READshort = -1;
  READ = new ExtendedPlace<short>("READ",temp_READshort);
  short temp_WRITEshort = -1;
  WRITE = new ExtendedPlace<short>("WRITE",temp_WRITEshort);
  BaseStateVariableClass* InitialPlaces[17]={
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
    WARP_ACCESS_L1,  // 12
    WARP_ACCESS_L2,  // 13
    WARP_ACCESS_DRAM,  // 14
    READ,  // 15
    WRITE   // 16
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("MEMORY", 17, InitialPlaces, 
                        0, InitialROPlaces, 
                        14, InitialActionList, 6, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[45][2]={ 
    {5,0}, {15,0}, {3,0}, {4,0}, {10,0}, {3,1}, {0,1}, {12,1}, 
    {3,2}, {1,2}, {13,2}, {3,3}, {2,3}, {14,3}, {4,4}, {0,4}, 
    {12,4}, {4,5}, {1,5}, {13,5}, {4,6}, {2,6}, {14,6}, {6,7}, 
    {16,7}, {5,7}, {11,7}, {5,8}, {7,8}, {12,8}, {5,9}, {8,9}, 
    {13,9}, {5,10}, {9,10}, {14,10}, {6,11}, {7,11}, {12,11}, 
    {6,12}, {8,12}, {13,12}, {6,13}, {9,13}, {14,13}
  };
  for(int n=0;n<45;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[14][2]={ 
    {15,0}, {3,1}, {3,2}, {3,3}, {4,4}, {4,5}, {4,6}, {16,7}, 
    {5,8}, {5,9}, {5,10}, {6,11}, {6,12}, {6,13}
  };
  for(int n=0;n<14;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<14;n++) {
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
  PERFORM_READ.READ = (ExtendedPlace<short>*) LocalStateVariables[15];
  PERFORM_READ.WRITE_LOCAL = (Place*) LocalStateVariables[5];
  PERFORM_READ.READ_LOCAL = (Place*) LocalStateVariables[3];
  PERFORM_READ.READ_GLOBAL = (Place*) LocalStateVariables[4];
  PERFORM_READ.READ_REGISTER_FILE = (Place*) LocalStateVariables[10];
  LOCAL_READ_FROM_case1.READ_LOCAL = (Place*) LocalStateVariables[3];
  LOCAL_READ_FROM_case1.READ_L1 = (Place*) LocalStateVariables[0];
  LOCAL_READ_FROM_case1.WARP_ACCESS_L1 = (Place*) LocalStateVariables[12];
  LOCAL_READ_FROM_case2.READ_LOCAL = (Place*) LocalStateVariables[3];
  LOCAL_READ_FROM_case2.READ_L2 = (Place*) LocalStateVariables[1];
  LOCAL_READ_FROM_case2.WARP_ACCESS_L2 = (Place*) LocalStateVariables[13];
  LOCAL_READ_FROM_case3.READ_LOCAL = (Place*) LocalStateVariables[3];
  LOCAL_READ_FROM_case3.READ_DRAM = (Place*) LocalStateVariables[2];
  LOCAL_READ_FROM_case3.WARP_ACCESS_DRAM = (Place*) LocalStateVariables[14];
  GLOBAL_READ_FROM_case1.READ_GLOBAL = (Place*) LocalStateVariables[4];
  GLOBAL_READ_FROM_case1.READ_L1 = (Place*) LocalStateVariables[0];
  GLOBAL_READ_FROM_case1.WARP_ACCESS_L1 = (Place*) LocalStateVariables[12];
  GLOBAL_READ_FROM_case2.READ_GLOBAL = (Place*) LocalStateVariables[4];
  GLOBAL_READ_FROM_case2.READ_L2 = (Place*) LocalStateVariables[1];
  GLOBAL_READ_FROM_case2.WARP_ACCESS_L2 = (Place*) LocalStateVariables[13];
  GLOBAL_READ_FROM_case3.READ_GLOBAL = (Place*) LocalStateVariables[4];
  GLOBAL_READ_FROM_case3.READ_DRAM = (Place*) LocalStateVariables[2];
  GLOBAL_READ_FROM_case3.WARP_ACCESS_DRAM = (Place*) LocalStateVariables[14];
  PERFORM_WRITE.WRITE = (ExtendedPlace<short>*) LocalStateVariables[16];
  PERFORM_WRITE.WRITE_GLOBAL = (Place*) LocalStateVariables[6];
  PERFORM_WRITE.WRITE_LOCAL = (Place*) LocalStateVariables[5];
  PERFORM_WRITE.WRITE_REGISTER_FILE = (Place*) LocalStateVariables[11];
  LOCAL_WRITE_TO_case1.WRITE_LOCAL = (Place*) LocalStateVariables[5];
  LOCAL_WRITE_TO_case1.WRITE_L1 = (Place*) LocalStateVariables[7];
  LOCAL_WRITE_TO_case1.WARP_ACCESS_L1 = (Place*) LocalStateVariables[12];
  LOCAL_WRITE_TO_case2.WRITE_LOCAL = (Place*) LocalStateVariables[5];
  LOCAL_WRITE_TO_case2.WRITE_L2 = (Place*) LocalStateVariables[8];
  LOCAL_WRITE_TO_case2.WARP_ACCESS_L2 = (Place*) LocalStateVariables[13];
  LOCAL_WRITE_TO_case3.WRITE_LOCAL = (Place*) LocalStateVariables[5];
  LOCAL_WRITE_TO_case3.WRITE_DRAM = (Place*) LocalStateVariables[9];
  LOCAL_WRITE_TO_case3.WARP_ACCESS_DRAM = (Place*) LocalStateVariables[14];
  GLOBAL_WRITE_TO_case1.WRITE_GLOBAL = (Place*) LocalStateVariables[6];
  GLOBAL_WRITE_TO_case1.WRITE_L1 = (Place*) LocalStateVariables[7];
  GLOBAL_WRITE_TO_case1.WARP_ACCESS_L1 = (Place*) LocalStateVariables[12];
  GLOBAL_WRITE_TO_case2.WRITE_GLOBAL = (Place*) LocalStateVariables[6];
  GLOBAL_WRITE_TO_case2.WRITE_L2 = (Place*) LocalStateVariables[8];
  GLOBAL_WRITE_TO_case2.WARP_ACCESS_L2 = (Place*) LocalStateVariables[13];
  GLOBAL_WRITE_TO_case3.WRITE_GLOBAL = (Place*) LocalStateVariables[6];
  GLOBAL_WRITE_TO_case3.WRITE_DRAM = (Place*) LocalStateVariables[9];
  GLOBAL_WRITE_TO_case3.WARP_ACCESS_DRAM = (Place*) LocalStateVariables[14];
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
  ActivityInitialize("LOCAL_READ_FROM_case1",1,Instantaneous , RaceEnabled, 3,1, false);
}

void MEMORYSAN::LOCAL_READ_FROMActivity_case1::LinkVariables(){
  READ_LOCAL->Register(&READ_LOCAL_Mobius_Mark);
  READ_L1->Register(&READ_L1_Mobius_Mark);
  WARP_ACCESS_L1->Register(&WARP_ACCESS_L1_Mobius_Mark);
}

bool MEMORYSAN::LOCAL_READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_LOCAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::LOCAL_READ_FROMActivity_case1::Weight(){ 
  return 0;
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
  WARP_ACCESS_L1->Mark() += nwarps;
  (*(READ_L1_Mobius_Mark))++;
  return this;
}

/*======================LOCAL_READ_FROMActivity_case2========================*/


MEMORYSAN::LOCAL_READ_FROMActivity_case2::LOCAL_READ_FROMActivity_case2(){
  ActivityInitialize("LOCAL_READ_FROM_case2",1,Instantaneous , RaceEnabled, 3,1, false);
}

void MEMORYSAN::LOCAL_READ_FROMActivity_case2::LinkVariables(){
  READ_LOCAL->Register(&READ_LOCAL_Mobius_Mark);
  READ_L2->Register(&READ_L2_Mobius_Mark);
  WARP_ACCESS_L2->Register(&WARP_ACCESS_L2_Mobius_Mark);
}

bool MEMORYSAN::LOCAL_READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_LOCAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::LOCAL_READ_FROMActivity_case2::Weight(){ 
  return 1;
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
  WARP_ACCESS_L2->Mark() += nwarps;
  (*(READ_L2_Mobius_Mark))++;
  return this;
}

/*======================LOCAL_READ_FROMActivity_case3========================*/


MEMORYSAN::LOCAL_READ_FROMActivity_case3::LOCAL_READ_FROMActivity_case3(){
  ActivityInitialize("LOCAL_READ_FROM_case3",1,Instantaneous , RaceEnabled, 3,1, false);
}

void MEMORYSAN::LOCAL_READ_FROMActivity_case3::LinkVariables(){
  READ_LOCAL->Register(&READ_LOCAL_Mobius_Mark);
  READ_DRAM->Register(&READ_DRAM_Mobius_Mark);
  WARP_ACCESS_DRAM->Register(&WARP_ACCESS_DRAM_Mobius_Mark);
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
  WARP_ACCESS_DRAM->Mark() += nwarps;
  (*(READ_DRAM_Mobius_Mark))++;
  return this;
}

/*======================GLOBAL_READ_FROMActivity_case1========================*/


MEMORYSAN::GLOBAL_READ_FROMActivity_case1::GLOBAL_READ_FROMActivity_case1(){
  ActivityInitialize("GLOBAL_READ_FROM_case1",2,Instantaneous , RaceEnabled, 3,1, false);
}

void MEMORYSAN::GLOBAL_READ_FROMActivity_case1::LinkVariables(){
  READ_GLOBAL->Register(&READ_GLOBAL_Mobius_Mark);
  READ_L1->Register(&READ_L1_Mobius_Mark);
  WARP_ACCESS_L1->Register(&WARP_ACCESS_L1_Mobius_Mark);
}

bool MEMORYSAN::GLOBAL_READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_GLOBAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::GLOBAL_READ_FROMActivity_case1::Weight(){ 
  return 0.9;
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
  WARP_ACCESS_L1->Mark() += nwarps;
  (*(READ_L1_Mobius_Mark))++;
  return this;
}

/*======================GLOBAL_READ_FROMActivity_case2========================*/


MEMORYSAN::GLOBAL_READ_FROMActivity_case2::GLOBAL_READ_FROMActivity_case2(){
  ActivityInitialize("GLOBAL_READ_FROM_case2",2,Instantaneous , RaceEnabled, 3,1, false);
}

void MEMORYSAN::GLOBAL_READ_FROMActivity_case2::LinkVariables(){
  READ_GLOBAL->Register(&READ_GLOBAL_Mobius_Mark);
  READ_L2->Register(&READ_L2_Mobius_Mark);
  WARP_ACCESS_L2->Register(&WARP_ACCESS_L2_Mobius_Mark);
}

bool MEMORYSAN::GLOBAL_READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_GLOBAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::GLOBAL_READ_FROMActivity_case2::Weight(){ 
  return 0.1;
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
  WARP_ACCESS_L2->Mark() += nwarps;
  (*(READ_L2_Mobius_Mark))++;
  return this;
}

/*======================GLOBAL_READ_FROMActivity_case3========================*/


MEMORYSAN::GLOBAL_READ_FROMActivity_case3::GLOBAL_READ_FROMActivity_case3(){
  ActivityInitialize("GLOBAL_READ_FROM_case3",2,Instantaneous , RaceEnabled, 3,1, false);
}

void MEMORYSAN::GLOBAL_READ_FROMActivity_case3::LinkVariables(){
  READ_GLOBAL->Register(&READ_GLOBAL_Mobius_Mark);
  READ_DRAM->Register(&READ_DRAM_Mobius_Mark);
  WARP_ACCESS_DRAM->Register(&WARP_ACCESS_DRAM_Mobius_Mark);
}

bool MEMORYSAN::GLOBAL_READ_FROMActivity_case3::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_GLOBAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::GLOBAL_READ_FROMActivity_case3::Weight(){ 
  return 0;
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
  WARP_ACCESS_DRAM->Mark() += nwarps;
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
  ActivityInitialize("LOCAL_WRITE_TO_case1",4,Instantaneous , RaceEnabled, 3,1, false);
}

void MEMORYSAN::LOCAL_WRITE_TOActivity_case1::LinkVariables(){
  WRITE_LOCAL->Register(&WRITE_LOCAL_Mobius_Mark);
  WRITE_L1->Register(&WRITE_L1_Mobius_Mark);
  WARP_ACCESS_L1->Register(&WARP_ACCESS_L1_Mobius_Mark);
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
  WARP_ACCESS_L1->Mark() += nwarps;
  (*(WRITE_L1_Mobius_Mark))++;
  return this;
}

/*======================LOCAL_WRITE_TOActivity_case2========================*/


MEMORYSAN::LOCAL_WRITE_TOActivity_case2::LOCAL_WRITE_TOActivity_case2(){
  ActivityInitialize("LOCAL_WRITE_TO_case2",4,Instantaneous , RaceEnabled, 3,1, false);
}

void MEMORYSAN::LOCAL_WRITE_TOActivity_case2::LinkVariables(){
  WRITE_LOCAL->Register(&WRITE_LOCAL_Mobius_Mark);
  WRITE_L2->Register(&WRITE_L2_Mobius_Mark);
  WARP_ACCESS_L2->Register(&WARP_ACCESS_L2_Mobius_Mark);
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
  WARP_ACCESS_L2->Mark() += nwarps;
  (*(WRITE_L2_Mobius_Mark))++;
  return this;
}

/*======================LOCAL_WRITE_TOActivity_case3========================*/


MEMORYSAN::LOCAL_WRITE_TOActivity_case3::LOCAL_WRITE_TOActivity_case3(){
  ActivityInitialize("LOCAL_WRITE_TO_case3",4,Instantaneous , RaceEnabled, 3,1, false);
}

void MEMORYSAN::LOCAL_WRITE_TOActivity_case3::LinkVariables(){
  WRITE_LOCAL->Register(&WRITE_LOCAL_Mobius_Mark);
  WRITE_DRAM->Register(&WRITE_DRAM_Mobius_Mark);
  WARP_ACCESS_DRAM->Register(&WARP_ACCESS_DRAM_Mobius_Mark);
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
  WARP_ACCESS_DRAM->Mark() += nwarps;
  (*(WRITE_DRAM_Mobius_Mark))++;
  return this;
}

/*======================GLOBAL_WRITE_TOActivity_case1========================*/


MEMORYSAN::GLOBAL_WRITE_TOActivity_case1::GLOBAL_WRITE_TOActivity_case1(){
  ActivityInitialize("GLOBAL_WRITE_TO_case1",5,Instantaneous , RaceEnabled, 3,1, false);
}

void MEMORYSAN::GLOBAL_WRITE_TOActivity_case1::LinkVariables(){
  WRITE_GLOBAL->Register(&WRITE_GLOBAL_Mobius_Mark);
  WRITE_L1->Register(&WRITE_L1_Mobius_Mark);
  WARP_ACCESS_L1->Register(&WARP_ACCESS_L1_Mobius_Mark);
}

bool MEMORYSAN::GLOBAL_WRITE_TOActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_GLOBAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::GLOBAL_WRITE_TOActivity_case1::Weight(){ 
  return 0;
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
  WARP_ACCESS_L1->Mark() += nwarps;
  (*(WRITE_L1_Mobius_Mark))++;
  return this;
}

/*======================GLOBAL_WRITE_TOActivity_case2========================*/


MEMORYSAN::GLOBAL_WRITE_TOActivity_case2::GLOBAL_WRITE_TOActivity_case2(){
  ActivityInitialize("GLOBAL_WRITE_TO_case2",5,Instantaneous , RaceEnabled, 3,1, false);
}

void MEMORYSAN::GLOBAL_WRITE_TOActivity_case2::LinkVariables(){
  WRITE_GLOBAL->Register(&WRITE_GLOBAL_Mobius_Mark);
  WRITE_L2->Register(&WRITE_L2_Mobius_Mark);
  WARP_ACCESS_L2->Register(&WARP_ACCESS_L2_Mobius_Mark);
}

bool MEMORYSAN::GLOBAL_WRITE_TOActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_GLOBAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::GLOBAL_WRITE_TOActivity_case2::Weight(){ 
  return 1;
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
  WARP_ACCESS_L2->Mark() += nwarps;
  (*(WRITE_L2_Mobius_Mark))++;
  return this;
}

/*======================GLOBAL_WRITE_TOActivity_case3========================*/


MEMORYSAN::GLOBAL_WRITE_TOActivity_case3::GLOBAL_WRITE_TOActivity_case3(){
  ActivityInitialize("GLOBAL_WRITE_TO_case3",5,Instantaneous , RaceEnabled, 3,1, false);
}

void MEMORYSAN::GLOBAL_WRITE_TOActivity_case3::LinkVariables(){
  WRITE_GLOBAL->Register(&WRITE_GLOBAL_Mobius_Mark);
  WRITE_DRAM->Register(&WRITE_DRAM_Mobius_Mark);
  WARP_ACCESS_DRAM->Register(&WARP_ACCESS_DRAM_Mobius_Mark);
}

bool MEMORYSAN::GLOBAL_WRITE_TOActivity_case3::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_GLOBAL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORYSAN::GLOBAL_WRITE_TOActivity_case3::Weight(){ 
  return 0;
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
  WARP_ACCESS_DRAM->Mark() += nwarps;
  (*(WRITE_DRAM_Mobius_Mark))++;
  return this;
}

