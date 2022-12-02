

// This C++ file was created by SanEditor

#include "Atomic/PROCESSOR/PROCESSORSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         PROCESSORSAN Constructor             
******************************************************************/


PROCESSORSAN::PROCESSORSAN(){


  SCHEDULE_WARPGroup.initialize(3, "SCHEDULE_WARPGroup");
  SCHEDULE_WARPGroup.appendGroup((BaseGroupClass*) &SCHEDULE_WARP_case1);
  SCHEDULE_WARPGroup.appendGroup((BaseGroupClass*) &SCHEDULE_WARP_case2);
  SCHEDULE_WARPGroup.appendGroup((BaseGroupClass*) &SCHEDULE_WARP_case3);

  READ_FROMGroup.initialize(2, "READ_FROMGroup");
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case1);
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case2);

  WRITE_TOGroup.initialize(2, "WRITE_TOGroup");
  WRITE_TOGroup.appendGroup((BaseGroupClass*) &WRITE_TO_case1);
  WRITE_TOGroup.appendGroup((BaseGroupClass*) &WRITE_TO_case2);

  COMPUTEGroup.initialize(2, "COMPUTEGroup");
  COMPUTEGroup.appendGroup((BaseGroupClass*) &COMPUTE_case1);
  COMPUTEGroup.appendGroup((BaseGroupClass*) &COMPUTE_case2);

  REGISTER_FILE_INGroup.initialize(2, "REGISTER_FILE_INGroup");
  REGISTER_FILE_INGroup.appendGroup((BaseGroupClass*) &REGISTER_FILE_IN_case1);
  REGISTER_FILE_INGroup.appendGroup((BaseGroupClass*) &REGISTER_FILE_IN_case2);

  Activity* InitialActionList[13]={
    &SCHEDULE_WARP_case1, //0
    &SCHEDULE_WARP_case2, //1
    &SCHEDULE_WARP_case3, //2
    &READ_FROM_case1, //3
    &READ_FROM_case2, //4
    &WRITE_TO_case1, //5
    &WRITE_TO_case2, //6
    &COMPUTE_case1, //7
    &COMPUTE_case2, //8
    &REGISTER_FILE_IN_case1, //9
    &REGISTER_FILE_IN_case2, //10
    &PERFORM_READ, //11
    &PERFORM_WRITE  // 12
  };

  BaseGroupClass* InitialGroupList[7]={
    (BaseGroupClass*) &(SCHEDULE_WARPGroup), 
    (BaseGroupClass*) &(READ_FROMGroup), 
    (BaseGroupClass*) &(WRITE_TOGroup), 
    (BaseGroupClass*) &(COMPUTEGroup), 
    (BaseGroupClass*) &(REGISTER_FILE_INGroup), 
    (BaseGroupClass*) &(PERFORM_READ), 
    (BaseGroupClass*) &(PERFORM_WRITE)
  };

  INSTRUCTIONS_POOL = new Place("INSTRUCTIONS_POOL" ,0);
  READ_P = new Place("READ_P" ,0);
  WRITE_P = new Place("WRITE_P" ,0);
  ALU = new Place("ALU" ,0);
  TOTAL_MEMORY = new Place("TOTAL_MEMORY" ,0);
  RESULT_MEMORY = new Place("RESULT_MEMORY" ,0);
  OUTPUT_MEMORY = new Place("OUTPUT_MEMORY" ,0);
  RESULT_OK = new Place("RESULT_OK" ,0);
  RESULT_KO = new Place("RESULT_KO" ,0);
  READ_DATA_IS_OK = new Place("READ_DATA_IS_OK" ,0);
  READ_DATA_IS_KO = new Place("READ_DATA_IS_KO" ,0);
  READ = new Place("READ" ,0);
  WRITE = new Place("WRITE" ,0);
  BaseStateVariableClass* InitialPlaces[13]={
    INSTRUCTIONS_POOL,  // 0
    READ_P,  // 1
    WRITE_P,  // 2
    ALU,  // 3
    TOTAL_MEMORY,  // 4
    RESULT_MEMORY,  // 5
    OUTPUT_MEMORY,  // 6
    RESULT_OK,  // 7
    RESULT_KO,  // 8
    READ_DATA_IS_OK,  // 9
    READ_DATA_IS_KO,  // 10
    READ,  // 11
    WRITE   // 12
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("PROCESSOR", 13, InitialPlaces, 
                        0, InitialROPlaces, 
                        13, InitialActionList, 7, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[36][2]={ 
    {0,0}, {1,0}, {0,1}, {2,1}, {0,2}, {3,2}, {1,3}, {4,3}, {1,4}, 
    {5,4}, {2,5}, {7,5}, {8,5}, {5,5}, {2,6}, {7,6}, {8,6}, {6,6}, 
    {3,7}, {9,7}, {10,7}, {7,7}, {3,8}, {9,8}, {10,8}, {8,8}, 
    {11,9}, {9,9}, {11,10}, {10,10}, {4,11}, {5,11}, {11,11}, 
    {5,12}, {6,12}, {12,12}
  };
  for(int n=0;n<36;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[23][2]={ 
    {0,0}, {0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {7,5}, {8,5}, {2,6}, 
    {7,6}, {8,6}, {3,7}, {9,7}, {10,7}, {3,8}, {9,8}, {10,8}, 
    {11,9}, {11,10}, {4,11}, {5,11}, {5,12}, {6,12}
  };
  for(int n=0;n<23;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<13;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void PROCESSORSAN::CustomInitialization() {

}
PROCESSORSAN::~PROCESSORSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void PROCESSORSAN::assignPlacesToActivitiesInst(){
  SCHEDULE_WARP_case1.INSTRUCTIONS_POOL = (Place*) LocalStateVariables[0];
  SCHEDULE_WARP_case1.READ_P = (Place*) LocalStateVariables[1];
  SCHEDULE_WARP_case2.INSTRUCTIONS_POOL = (Place*) LocalStateVariables[0];
  SCHEDULE_WARP_case2.WRITE_P = (Place*) LocalStateVariables[2];
  SCHEDULE_WARP_case3.INSTRUCTIONS_POOL = (Place*) LocalStateVariables[0];
  SCHEDULE_WARP_case3.ALU = (Place*) LocalStateVariables[3];
  READ_FROM_case1.READ_P = (Place*) LocalStateVariables[1];
  READ_FROM_case1.TOTAL_MEMORY = (Place*) LocalStateVariables[4];
  READ_FROM_case2.READ_P = (Place*) LocalStateVariables[1];
  READ_FROM_case2.RESULT_MEMORY = (Place*) LocalStateVariables[5];
  WRITE_TO_case1.WRITE_P = (Place*) LocalStateVariables[2];
  WRITE_TO_case1.RESULT_OK = (Place*) LocalStateVariables[7];
  WRITE_TO_case1.RESULT_KO = (Place*) LocalStateVariables[8];
  WRITE_TO_case1.RESULT_MEMORY = (Place*) LocalStateVariables[5];
  WRITE_TO_case2.WRITE_P = (Place*) LocalStateVariables[2];
  WRITE_TO_case2.RESULT_OK = (Place*) LocalStateVariables[7];
  WRITE_TO_case2.RESULT_KO = (Place*) LocalStateVariables[8];
  WRITE_TO_case2.OUTPUT_MEMORY = (Place*) LocalStateVariables[6];
  COMPUTE_case1.ALU = (Place*) LocalStateVariables[3];
  COMPUTE_case1.READ_DATA_IS_OK = (Place*) LocalStateVariables[9];
  COMPUTE_case1.READ_DATA_IS_KO = (Place*) LocalStateVariables[10];
  COMPUTE_case1.RESULT_OK = (Place*) LocalStateVariables[7];
  COMPUTE_case2.ALU = (Place*) LocalStateVariables[3];
  COMPUTE_case2.READ_DATA_IS_OK = (Place*) LocalStateVariables[9];
  COMPUTE_case2.READ_DATA_IS_KO = (Place*) LocalStateVariables[10];
  COMPUTE_case2.RESULT_KO = (Place*) LocalStateVariables[8];
  REGISTER_FILE_IN_case1.READ = (Place*) LocalStateVariables[11];
  REGISTER_FILE_IN_case1.READ_DATA_IS_OK = (Place*) LocalStateVariables[9];
  REGISTER_FILE_IN_case2.READ = (Place*) LocalStateVariables[11];
  REGISTER_FILE_IN_case2.READ_DATA_IS_KO = (Place*) LocalStateVariables[10];
  PERFORM_READ.TOTAL_MEMORY = (Place*) LocalStateVariables[4];
  PERFORM_READ.RESULT_MEMORY = (Place*) LocalStateVariables[5];
  PERFORM_READ.READ = (Place*) LocalStateVariables[11];
  PERFORM_WRITE.RESULT_MEMORY = (Place*) LocalStateVariables[5];
  PERFORM_WRITE.OUTPUT_MEMORY = (Place*) LocalStateVariables[6];
  PERFORM_WRITE.WRITE = (Place*) LocalStateVariables[12];
}
void PROCESSORSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================SCHEDULE_WARPActivity_case1========================*/


PROCESSORSAN::SCHEDULE_WARPActivity_case1::SCHEDULE_WARPActivity_case1(){
  ActivityInitialize("SCHEDULE_WARP_case1",0,Instantaneous , RaceEnabled, 2,1, false);
}

void PROCESSORSAN::SCHEDULE_WARPActivity_case1::LinkVariables(){
  INSTRUCTIONS_POOL->Register(&INSTRUCTIONS_POOL_Mobius_Mark);
  READ_P->Register(&READ_P_Mobius_Mark);
}

bool PROCESSORSAN::SCHEDULE_WARPActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(INSTRUCTIONS_POOL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double PROCESSORSAN::SCHEDULE_WARPActivity_case1::Weight(){ 
  return 1/3;
}

bool PROCESSORSAN::SCHEDULE_WARPActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool PROCESSORSAN::SCHEDULE_WARPActivity_case1::ReactivationFunction(){ 
  return false;
}

double PROCESSORSAN::SCHEDULE_WARPActivity_case1::SampleDistribution(){
  return 0;
}

double* PROCESSORSAN::SCHEDULE_WARPActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int PROCESSORSAN::SCHEDULE_WARPActivity_case1::Rank(){
  return 1;
}

BaseActionClass* PROCESSORSAN::SCHEDULE_WARPActivity_case1::Fire(){
  (*(INSTRUCTIONS_POOL_Mobius_Mark))--;
  (*(READ_P_Mobius_Mark))++;
  return this;
}

/*======================SCHEDULE_WARPActivity_case2========================*/


PROCESSORSAN::SCHEDULE_WARPActivity_case2::SCHEDULE_WARPActivity_case2(){
  ActivityInitialize("SCHEDULE_WARP_case2",0,Instantaneous , RaceEnabled, 2,1, false);
}

void PROCESSORSAN::SCHEDULE_WARPActivity_case2::LinkVariables(){
  INSTRUCTIONS_POOL->Register(&INSTRUCTIONS_POOL_Mobius_Mark);
  WRITE_P->Register(&WRITE_P_Mobius_Mark);
}

bool PROCESSORSAN::SCHEDULE_WARPActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(INSTRUCTIONS_POOL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double PROCESSORSAN::SCHEDULE_WARPActivity_case2::Weight(){ 
  return 1/3;
}

bool PROCESSORSAN::SCHEDULE_WARPActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool PROCESSORSAN::SCHEDULE_WARPActivity_case2::ReactivationFunction(){ 
  return false;
}

double PROCESSORSAN::SCHEDULE_WARPActivity_case2::SampleDistribution(){
  return 0;
}

double* PROCESSORSAN::SCHEDULE_WARPActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int PROCESSORSAN::SCHEDULE_WARPActivity_case2::Rank(){
  return 1;
}

BaseActionClass* PROCESSORSAN::SCHEDULE_WARPActivity_case2::Fire(){
  (*(INSTRUCTIONS_POOL_Mobius_Mark))--;
  (*(WRITE_P_Mobius_Mark))++;
  return this;
}

/*======================SCHEDULE_WARPActivity_case3========================*/


PROCESSORSAN::SCHEDULE_WARPActivity_case3::SCHEDULE_WARPActivity_case3(){
  ActivityInitialize("SCHEDULE_WARP_case3",0,Instantaneous , RaceEnabled, 2,1, false);
}

void PROCESSORSAN::SCHEDULE_WARPActivity_case3::LinkVariables(){
  INSTRUCTIONS_POOL->Register(&INSTRUCTIONS_POOL_Mobius_Mark);
  ALU->Register(&ALU_Mobius_Mark);
}

bool PROCESSORSAN::SCHEDULE_WARPActivity_case3::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(INSTRUCTIONS_POOL_Mobius_Mark)) >=1));
  return NewEnabled;
}

double PROCESSORSAN::SCHEDULE_WARPActivity_case3::Weight(){ 
  return 1/3;
}

bool PROCESSORSAN::SCHEDULE_WARPActivity_case3::ReactivationPredicate(){ 
  return false;
}

bool PROCESSORSAN::SCHEDULE_WARPActivity_case3::ReactivationFunction(){ 
  return false;
}

double PROCESSORSAN::SCHEDULE_WARPActivity_case3::SampleDistribution(){
  return 0;
}

double* PROCESSORSAN::SCHEDULE_WARPActivity_case3::ReturnDistributionParameters(){
    return NULL;
}

int PROCESSORSAN::SCHEDULE_WARPActivity_case3::Rank(){
  return 1;
}

BaseActionClass* PROCESSORSAN::SCHEDULE_WARPActivity_case3::Fire(){
  (*(INSTRUCTIONS_POOL_Mobius_Mark))--;
  (*(ALU_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case1========================*/


PROCESSORSAN::READ_FROMActivity_case1::READ_FROMActivity_case1(){
  ActivityInitialize("READ_FROM_case1",1,Instantaneous , RaceEnabled, 2,1, false);
}

void PROCESSORSAN::READ_FROMActivity_case1::LinkVariables(){
  READ_P->Register(&READ_P_Mobius_Mark);
  TOTAL_MEMORY->Register(&TOTAL_MEMORY_Mobius_Mark);
}

bool PROCESSORSAN::READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_P_Mobius_Mark)) >=1));
  return NewEnabled;
}

double PROCESSORSAN::READ_FROMActivity_case1::Weight(){ 
  return 1/2;
}

bool PROCESSORSAN::READ_FROMActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool PROCESSORSAN::READ_FROMActivity_case1::ReactivationFunction(){ 
  return false;
}

double PROCESSORSAN::READ_FROMActivity_case1::SampleDistribution(){
  return 0;
}

double* PROCESSORSAN::READ_FROMActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int PROCESSORSAN::READ_FROMActivity_case1::Rank(){
  return 1;
}

BaseActionClass* PROCESSORSAN::READ_FROMActivity_case1::Fire(){
  (*(READ_P_Mobius_Mark))--;
  (*(TOTAL_MEMORY_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case2========================*/


PROCESSORSAN::READ_FROMActivity_case2::READ_FROMActivity_case2(){
  ActivityInitialize("READ_FROM_case2",1,Instantaneous , RaceEnabled, 2,1, false);
}

void PROCESSORSAN::READ_FROMActivity_case2::LinkVariables(){
  READ_P->Register(&READ_P_Mobius_Mark);
  RESULT_MEMORY->Register(&RESULT_MEMORY_Mobius_Mark);
}

bool PROCESSORSAN::READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_P_Mobius_Mark)) >=1));
  return NewEnabled;
}

double PROCESSORSAN::READ_FROMActivity_case2::Weight(){ 
  return 1/2;
}

bool PROCESSORSAN::READ_FROMActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool PROCESSORSAN::READ_FROMActivity_case2::ReactivationFunction(){ 
  return false;
}

double PROCESSORSAN::READ_FROMActivity_case2::SampleDistribution(){
  return 0;
}

double* PROCESSORSAN::READ_FROMActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int PROCESSORSAN::READ_FROMActivity_case2::Rank(){
  return 1;
}

BaseActionClass* PROCESSORSAN::READ_FROMActivity_case2::Fire(){
  (*(READ_P_Mobius_Mark))--;
  (*(RESULT_MEMORY_Mobius_Mark))++;
  return this;
}

/*======================WRITE_TOActivity_case1========================*/


PROCESSORSAN::WRITE_TOActivity_case1::WRITE_TOActivity_case1(){
  ActivityInitialize("WRITE_TO_case1",2,Instantaneous , RaceEnabled, 4,3, false);
}

void PROCESSORSAN::WRITE_TOActivity_case1::LinkVariables(){
  WRITE_P->Register(&WRITE_P_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
  RESULT_MEMORY->Register(&RESULT_MEMORY_Mobius_Mark);
}

bool PROCESSORSAN::WRITE_TOActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_P_Mobius_Mark)) >=1)&&((*(RESULT_OK_Mobius_Mark)) >=1)&&((*(RESULT_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double PROCESSORSAN::WRITE_TOActivity_case1::Weight(){ 
  return 1/2;
}

bool PROCESSORSAN::WRITE_TOActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool PROCESSORSAN::WRITE_TOActivity_case1::ReactivationFunction(){ 
  return false;
}

double PROCESSORSAN::WRITE_TOActivity_case1::SampleDistribution(){
  return 0;
}

double* PROCESSORSAN::WRITE_TOActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int PROCESSORSAN::WRITE_TOActivity_case1::Rank(){
  return 1;
}

BaseActionClass* PROCESSORSAN::WRITE_TOActivity_case1::Fire(){
  (*(WRITE_P_Mobius_Mark))--;
  (*(RESULT_OK_Mobius_Mark))--;
  (*(RESULT_KO_Mobius_Mark))--;
  (*(RESULT_MEMORY_Mobius_Mark))++;
  return this;
}

/*======================WRITE_TOActivity_case2========================*/


PROCESSORSAN::WRITE_TOActivity_case2::WRITE_TOActivity_case2(){
  ActivityInitialize("WRITE_TO_case2",2,Instantaneous , RaceEnabled, 4,3, false);
}

void PROCESSORSAN::WRITE_TOActivity_case2::LinkVariables(){
  WRITE_P->Register(&WRITE_P_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
  OUTPUT_MEMORY->Register(&OUTPUT_MEMORY_Mobius_Mark);
}

bool PROCESSORSAN::WRITE_TOActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_P_Mobius_Mark)) >=1)&&((*(RESULT_OK_Mobius_Mark)) >=1)&&((*(RESULT_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double PROCESSORSAN::WRITE_TOActivity_case2::Weight(){ 
  return 1/2;
}

bool PROCESSORSAN::WRITE_TOActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool PROCESSORSAN::WRITE_TOActivity_case2::ReactivationFunction(){ 
  return false;
}

double PROCESSORSAN::WRITE_TOActivity_case2::SampleDistribution(){
  return 0;
}

double* PROCESSORSAN::WRITE_TOActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int PROCESSORSAN::WRITE_TOActivity_case2::Rank(){
  return 1;
}

BaseActionClass* PROCESSORSAN::WRITE_TOActivity_case2::Fire(){
  (*(WRITE_P_Mobius_Mark))--;
  (*(RESULT_OK_Mobius_Mark))--;
  (*(RESULT_KO_Mobius_Mark))--;
  (*(OUTPUT_MEMORY_Mobius_Mark))++;
  return this;
}

/*======================COMPUTEActivity_case1========================*/


PROCESSORSAN::COMPUTEActivity_case1::COMPUTEActivity_case1(){
  ActivityInitialize("COMPUTE_case1",3,Instantaneous , RaceEnabled, 4,3, false);
}

void PROCESSORSAN::COMPUTEActivity_case1::LinkVariables(){
  ALU->Register(&ALU_Mobius_Mark);
  READ_DATA_IS_OK->Register(&READ_DATA_IS_OK_Mobius_Mark);
  READ_DATA_IS_KO->Register(&READ_DATA_IS_KO_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
}

bool PROCESSORSAN::COMPUTEActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ALU_Mobius_Mark)) >=1)&&((*(READ_DATA_IS_OK_Mobius_Mark)) >=1)&&((*(READ_DATA_IS_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double PROCESSORSAN::COMPUTEActivity_case1::Weight(){ 
  return 1/2;
}

bool PROCESSORSAN::COMPUTEActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool PROCESSORSAN::COMPUTEActivity_case1::ReactivationFunction(){ 
  return false;
}

double PROCESSORSAN::COMPUTEActivity_case1::SampleDistribution(){
  return 0;
}

double* PROCESSORSAN::COMPUTEActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int PROCESSORSAN::COMPUTEActivity_case1::Rank(){
  return 1;
}

BaseActionClass* PROCESSORSAN::COMPUTEActivity_case1::Fire(){
  (*(ALU_Mobius_Mark))--;
  (*(READ_DATA_IS_OK_Mobius_Mark))--;
  (*(READ_DATA_IS_KO_Mobius_Mark))--;
  (*(RESULT_OK_Mobius_Mark))++;
  return this;
}

/*======================COMPUTEActivity_case2========================*/


PROCESSORSAN::COMPUTEActivity_case2::COMPUTEActivity_case2(){
  ActivityInitialize("COMPUTE_case2",3,Instantaneous , RaceEnabled, 4,3, false);
}

void PROCESSORSAN::COMPUTEActivity_case2::LinkVariables(){
  ALU->Register(&ALU_Mobius_Mark);
  READ_DATA_IS_OK->Register(&READ_DATA_IS_OK_Mobius_Mark);
  READ_DATA_IS_KO->Register(&READ_DATA_IS_KO_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
}

bool PROCESSORSAN::COMPUTEActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ALU_Mobius_Mark)) >=1)&&((*(READ_DATA_IS_OK_Mobius_Mark)) >=1)&&((*(READ_DATA_IS_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double PROCESSORSAN::COMPUTEActivity_case2::Weight(){ 
  return 1/2;
}

bool PROCESSORSAN::COMPUTEActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool PROCESSORSAN::COMPUTEActivity_case2::ReactivationFunction(){ 
  return false;
}

double PROCESSORSAN::COMPUTEActivity_case2::SampleDistribution(){
  return 0;
}

double* PROCESSORSAN::COMPUTEActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int PROCESSORSAN::COMPUTEActivity_case2::Rank(){
  return 1;
}

BaseActionClass* PROCESSORSAN::COMPUTEActivity_case2::Fire(){
  (*(ALU_Mobius_Mark))--;
  (*(READ_DATA_IS_OK_Mobius_Mark))--;
  (*(READ_DATA_IS_KO_Mobius_Mark))--;
  (*(RESULT_KO_Mobius_Mark))++;
  return this;
}

/*======================REGISTER_FILE_INActivity_case1========================*/


PROCESSORSAN::REGISTER_FILE_INActivity_case1::REGISTER_FILE_INActivity_case1(){
  ActivityInitialize("REGISTER_FILE_IN_case1",4,Instantaneous , RaceEnabled, 2,1, false);
}

void PROCESSORSAN::REGISTER_FILE_INActivity_case1::LinkVariables(){
  READ->Register(&READ_Mobius_Mark);
  READ_DATA_IS_OK->Register(&READ_DATA_IS_OK_Mobius_Mark);
}

bool PROCESSORSAN::REGISTER_FILE_INActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_Mobius_Mark)) >=1));
  return NewEnabled;
}

double PROCESSORSAN::REGISTER_FILE_INActivity_case1::Weight(){ 
  return 1/2;
}

bool PROCESSORSAN::REGISTER_FILE_INActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool PROCESSORSAN::REGISTER_FILE_INActivity_case1::ReactivationFunction(){ 
  return false;
}

double PROCESSORSAN::REGISTER_FILE_INActivity_case1::SampleDistribution(){
  return 0;
}

double* PROCESSORSAN::REGISTER_FILE_INActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int PROCESSORSAN::REGISTER_FILE_INActivity_case1::Rank(){
  return 1;
}

BaseActionClass* PROCESSORSAN::REGISTER_FILE_INActivity_case1::Fire(){
  (*(READ_Mobius_Mark))--;
  (*(READ_DATA_IS_OK_Mobius_Mark))++;
  return this;
}

/*======================REGISTER_FILE_INActivity_case2========================*/


PROCESSORSAN::REGISTER_FILE_INActivity_case2::REGISTER_FILE_INActivity_case2(){
  ActivityInitialize("REGISTER_FILE_IN_case2",4,Instantaneous , RaceEnabled, 2,1, false);
}

void PROCESSORSAN::REGISTER_FILE_INActivity_case2::LinkVariables(){
  READ->Register(&READ_Mobius_Mark);
  READ_DATA_IS_KO->Register(&READ_DATA_IS_KO_Mobius_Mark);
}

bool PROCESSORSAN::REGISTER_FILE_INActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_Mobius_Mark)) >=1));
  return NewEnabled;
}

double PROCESSORSAN::REGISTER_FILE_INActivity_case2::Weight(){ 
  return 1/2;
}

bool PROCESSORSAN::REGISTER_FILE_INActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool PROCESSORSAN::REGISTER_FILE_INActivity_case2::ReactivationFunction(){ 
  return false;
}

double PROCESSORSAN::REGISTER_FILE_INActivity_case2::SampleDistribution(){
  return 0;
}

double* PROCESSORSAN::REGISTER_FILE_INActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int PROCESSORSAN::REGISTER_FILE_INActivity_case2::Rank(){
  return 1;
}

BaseActionClass* PROCESSORSAN::REGISTER_FILE_INActivity_case2::Fire(){
  (*(READ_Mobius_Mark))--;
  (*(READ_DATA_IS_KO_Mobius_Mark))++;
  return this;
}

/*======================PERFORM_READActivity========================*/


PROCESSORSAN::PERFORM_READActivity::PERFORM_READActivity(){
  ActivityInitialize("PERFORM_READ",5,Instantaneous , RaceEnabled, 3,2, false);
}

void PROCESSORSAN::PERFORM_READActivity::LinkVariables(){
  TOTAL_MEMORY->Register(&TOTAL_MEMORY_Mobius_Mark);
  RESULT_MEMORY->Register(&RESULT_MEMORY_Mobius_Mark);
  READ->Register(&READ_Mobius_Mark);
}

bool PROCESSORSAN::PERFORM_READActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(TOTAL_MEMORY_Mobius_Mark)) >=1)&&((*(RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double PROCESSORSAN::PERFORM_READActivity::Weight(){ 
  return 1;
}

bool PROCESSORSAN::PERFORM_READActivity::ReactivationPredicate(){ 
  return false;
}

bool PROCESSORSAN::PERFORM_READActivity::ReactivationFunction(){ 
  return false;
}

double PROCESSORSAN::PERFORM_READActivity::SampleDistribution(){
  return 0;
}

double* PROCESSORSAN::PERFORM_READActivity::ReturnDistributionParameters(){
    return NULL;
}

int PROCESSORSAN::PERFORM_READActivity::Rank(){
  return 1;
}

BaseActionClass* PROCESSORSAN::PERFORM_READActivity::Fire(){
  (*(TOTAL_MEMORY_Mobius_Mark))--;
  (*(RESULT_MEMORY_Mobius_Mark))--;
  (*(READ_Mobius_Mark))++;
  return this;
}

/*======================PERFORM_WRITEActivity========================*/


PROCESSORSAN::PERFORM_WRITEActivity::PERFORM_WRITEActivity(){
  ActivityInitialize("PERFORM_WRITE",6,Instantaneous , RaceEnabled, 3,2, false);
}

void PROCESSORSAN::PERFORM_WRITEActivity::LinkVariables(){
  RESULT_MEMORY->Register(&RESULT_MEMORY_Mobius_Mark);
  OUTPUT_MEMORY->Register(&OUTPUT_MEMORY_Mobius_Mark);
  WRITE->Register(&WRITE_Mobius_Mark);
}

bool PROCESSORSAN::PERFORM_WRITEActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(RESULT_MEMORY_Mobius_Mark)) >=1)&&((*(OUTPUT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double PROCESSORSAN::PERFORM_WRITEActivity::Weight(){ 
  return 1;
}

bool PROCESSORSAN::PERFORM_WRITEActivity::ReactivationPredicate(){ 
  return false;
}

bool PROCESSORSAN::PERFORM_WRITEActivity::ReactivationFunction(){ 
  return false;
}

double PROCESSORSAN::PERFORM_WRITEActivity::SampleDistribution(){
  return 0;
}

double* PROCESSORSAN::PERFORM_WRITEActivity::ReturnDistributionParameters(){
    return NULL;
}

int PROCESSORSAN::PERFORM_WRITEActivity::Rank(){
  return 1;
}

BaseActionClass* PROCESSORSAN::PERFORM_WRITEActivity::Fire(){
  (*(RESULT_MEMORY_Mobius_Mark))--;
  (*(OUTPUT_MEMORY_Mobius_Mark))--;
  (*(WRITE_Mobius_Mark))++;
  return this;
}

