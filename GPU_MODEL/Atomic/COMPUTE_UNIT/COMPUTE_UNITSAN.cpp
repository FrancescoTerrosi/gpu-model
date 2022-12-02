

// This C++ file was created by SanEditor

#include "Atomic/COMPUTE_UNIT/COMPUTE_UNITSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         COMPUTE_UNITSAN Constructor             
******************************************************************/


COMPUTE_UNITSAN::COMPUTE_UNITSAN(){


  GETTING_CONST_VALGroup.initialize(2, "GETTING_CONST_VALGroup");
  GETTING_CONST_VALGroup.appendGroup((BaseGroupClass*) &GETTING_CONST_VAL_case1);
  GETTING_CONST_VALGroup.appendGroup((BaseGroupClass*) &GETTING_CONST_VAL_case2);

  Activity* InitialActionList[6]={
    &Instantaneous_Activity1, //0
    &DISPATCHER, //1
    &COMPUTE_WITH_KO_DATA, //2
    &COMPUTE_WITH_OK_DATA, //3
    &GETTING_CONST_VAL_case1, //4
    &GETTING_CONST_VAL_case2  // 5
  };

  BaseGroupClass* InitialGroupList[5]={
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(DISPATCHER), 
    (BaseGroupClass*) &(COMPUTE_WITH_KO_DATA), 
    (BaseGroupClass*) &(COMPUTE_WITH_OK_DATA), 
    (BaseGroupClass*) &(GETTING_CONST_VALGroup)
  };

  MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE" ,0);
  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  ALU_INSTRUCTION = new Place("ALU_INSTRUCTION" ,0);
  INST_COUNTER = new Place("INST_COUNTER" ,0);
  KO_READ = new Place("KO_READ" ,0);
  READ_INITIAL_MEMORY = new Place("READ_INITIAL_MEMORY" ,0);
  READ_INTERMEDIATE_MEMORY = new Place("READ_INTERMEDIATE_MEMORY" ,0);
  WRITE_FINAL_MEMORY = new Place("WRITE_FINAL_MEMORY" ,0);
  WRITE_INTERMEDIATE_MEMORY = new Place("WRITE_INTERMEDIATE_MEMORY" ,0);
  RESULT_KO = new Place("RESULT_KO" ,0);
  OK_READ = new Place("OK_READ" ,0);
  RESULT_OK = new Place("RESULT_OK" ,0);
  GET_CONSTANT = new Place("GET_CONSTANT" ,0);
  short temp_SCHEDULERInstructionsvalue = -1;
  SCHEDULER = new Instructions("SCHEDULER",temp_SCHEDULERInstructionsvalue);
  BaseStateVariableClass* InitialPlaces[14]={
    MEM_OP_COMPLETE,  // 0
    INSTRUCTION_READY,  // 1
    ALU_INSTRUCTION,  // 2
    INST_COUNTER,  // 3
    KO_READ,  // 4
    READ_INITIAL_MEMORY,  // 5
    READ_INTERMEDIATE_MEMORY,  // 6
    WRITE_FINAL_MEMORY,  // 7
    WRITE_INTERMEDIATE_MEMORY,  // 8
    RESULT_KO,  // 9
    OK_READ,  // 10
    RESULT_OK,  // 11
    GET_CONSTANT,  // 12
    SCHEDULER   // 13
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("COMPUTE_UNIT", 14, InitialPlaces, 
                        0, InitialROPlaces, 
                        6, InitialActionList, 5, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[25][2]={ 
    {0,0}, {1,0}, {1,1}, {3,1}, {5,1}, {6,1}, {8,1}, {7,1}, {2,1}, 
    {12,1}, {13,1}, {2,2}, {4,2}, {9,2}, {1,2}, {2,3}, {10,3}, 
    {11,3}, {1,3}, {12,4}, {4,4}, {1,4}, {12,5}, {10,5}, {1,5}
  };
  for(int n=0;n<25;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[9][2]={ 
    {0,0}, {3,1}, {1,1}, {2,2}, {4,2}, {2,3}, {10,3}, {12,4}, 
    {12,5}
  };
  for(int n=0;n<9;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<6;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void COMPUTE_UNITSAN::CustomInitialization() {
SCHEDULER->Index(0)->Mark() = 6;
SCHEDULER->Index(1)->Mark() = 6;
SCHEDULER->Index(2)->Mark() = 5;
SCHEDULER->Index(3)->Mark() = 3;
SCHEDULER->Index(4)->Mark() = 6;
SCHEDULER->Index(5)->Mark() = 6;
SCHEDULER->Index(6)->Mark() = 5;
SCHEDULER->Index(7)->Mark() = 3;
SCHEDULER->Index(8)->Mark() = 6;
SCHEDULER->Index(9)->Mark() = 1;
SCHEDULER->Index(10)->Mark() = 1;
SCHEDULER->Index(11)->Mark() = 5;
SCHEDULER->Index(12)->Mark() = 4;

}
COMPUTE_UNITSAN::~COMPUTE_UNITSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void COMPUTE_UNITSAN::assignPlacesToActivitiesInst(){
  Instantaneous_Activity1.MEM_OP_COMPLETE = (Place*) LocalStateVariables[0];
  Instantaneous_Activity1.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
  DISPATCHER.INST_COUNTER = (Place*) LocalStateVariables[3];
  DISPATCHER.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
  DISPATCHER.READ_INITIAL_MEMORY = (Place*) LocalStateVariables[5];
  DISPATCHER.READ_INTERMEDIATE_MEMORY = (Place*) LocalStateVariables[6];
  DISPATCHER.WRITE_INTERMEDIATE_MEMORY = (Place*) LocalStateVariables[8];
  DISPATCHER.WRITE_FINAL_MEMORY = (Place*) LocalStateVariables[7];
  DISPATCHER.ALU_INSTRUCTION = (Place*) LocalStateVariables[2];
  DISPATCHER.GET_CONSTANT = (Place*) LocalStateVariables[12];
  DISPATCHER.SCHEDULER = (Instructions*) LocalStateVariables[13];
  COMPUTE_WITH_KO_DATA.ALU_INSTRUCTION = (Place*) LocalStateVariables[2];
  COMPUTE_WITH_KO_DATA.KO_READ = (Place*) LocalStateVariables[4];
  COMPUTE_WITH_KO_DATA.RESULT_KO = (Place*) LocalStateVariables[9];
  COMPUTE_WITH_KO_DATA.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
  COMPUTE_WITH_OK_DATA.ALU_INSTRUCTION = (Place*) LocalStateVariables[2];
  COMPUTE_WITH_OK_DATA.OK_READ = (Place*) LocalStateVariables[10];
  COMPUTE_WITH_OK_DATA.RESULT_OK = (Place*) LocalStateVariables[11];
  COMPUTE_WITH_OK_DATA.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
  GETTING_CONST_VAL_case1.GET_CONSTANT = (Place*) LocalStateVariables[12];
  GETTING_CONST_VAL_case1.KO_READ = (Place*) LocalStateVariables[4];
  GETTING_CONST_VAL_case1.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
  GETTING_CONST_VAL_case2.GET_CONSTANT = (Place*) LocalStateVariables[12];
  GETTING_CONST_VAL_case2.OK_READ = (Place*) LocalStateVariables[10];
  GETTING_CONST_VAL_case2.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
}
void COMPUTE_UNITSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================Instantaneous_Activity1Activity========================*/


COMPUTE_UNITSAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",0,Instantaneous , RaceEnabled, 2,1, false);
}

void COMPUTE_UNITSAN::Instantaneous_Activity1Activity::LinkVariables(){
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool COMPUTE_UNITSAN::Instantaneous_Activity1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEM_OP_COMPLETE_Mobius_Mark)) >=1));
  return NewEnabled;
}

double COMPUTE_UNITSAN::Instantaneous_Activity1Activity::Weight(){ 
  return 1;
}

bool COMPUTE_UNITSAN::Instantaneous_Activity1Activity::ReactivationPredicate(){ 
  return false;
}

bool COMPUTE_UNITSAN::Instantaneous_Activity1Activity::ReactivationFunction(){ 
  return false;
}

double COMPUTE_UNITSAN::Instantaneous_Activity1Activity::SampleDistribution(){
  return 0;
}

double* COMPUTE_UNITSAN::Instantaneous_Activity1Activity::ReturnDistributionParameters(){
    return NULL;
}

int COMPUTE_UNITSAN::Instantaneous_Activity1Activity::Rank(){
  return 1;
}

BaseActionClass* COMPUTE_UNITSAN::Instantaneous_Activity1Activity::Fire(){
  (*(MEM_OP_COMPLETE_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

/*======================DISPATCHERActivity========================*/


COMPUTE_UNITSAN::DISPATCHERActivity::DISPATCHERActivity(){
  ActivityInitialize("DISPATCHER",1,Instantaneous , RaceEnabled, 9,2, false);
}

void COMPUTE_UNITSAN::DISPATCHERActivity::LinkVariables(){
  INST_COUNTER->Register(&INST_COUNTER_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  READ_INITIAL_MEMORY->Register(&READ_INITIAL_MEMORY_Mobius_Mark);
  READ_INTERMEDIATE_MEMORY->Register(&READ_INTERMEDIATE_MEMORY_Mobius_Mark);
  WRITE_INTERMEDIATE_MEMORY->Register(&WRITE_INTERMEDIATE_MEMORY_Mobius_Mark);
  WRITE_FINAL_MEMORY->Register(&WRITE_FINAL_MEMORY_Mobius_Mark);
  ALU_INSTRUCTION->Register(&ALU_INSTRUCTION_Mobius_Mark);
  GET_CONSTANT->Register(&GET_CONSTANT_Mobius_Mark);

}

bool COMPUTE_UNITSAN::DISPATCHERActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((INST_COUNTER->Mark() < size) && (INSTRUCTION_READY->Mark() > 0)));
  return NewEnabled;
}

double COMPUTE_UNITSAN::DISPATCHERActivity::Weight(){ 
  return 1;
}

bool COMPUTE_UNITSAN::DISPATCHERActivity::ReactivationPredicate(){ 
  return false;
}

bool COMPUTE_UNITSAN::DISPATCHERActivity::ReactivationFunction(){ 
  return false;
}

double COMPUTE_UNITSAN::DISPATCHERActivity::SampleDistribution(){
  return 0;
}

double* COMPUTE_UNITSAN::DISPATCHERActivity::ReturnDistributionParameters(){
    return NULL;
}

int COMPUTE_UNITSAN::DISPATCHERActivity::Rank(){
  return 1;
}

BaseActionClass* COMPUTE_UNITSAN::DISPATCHERActivity::Fire(){
  INSTRUCTION_READY->Mark()--;
  switch( SCHEDULER->Index(INST_COUNTER->Mark())->Mark() ) {

    case 1:
        READ_INITIAL_MEMORY->Mark()++;
    break;

    case 2:
        READ_INTERMEDIATE_MEMORY->Mark()++;
    break;

    case 3:
        WRITE_INTERMEDIATE_MEMORY->Mark()++;
    break;

    case 4:
        WRITE_FINAL_MEMORY->Mark()++;
    break;

    case 5:
        ALU_INSTRUCTION->Mark()++;
    break;

    case 6:
        GET_CONSTANT->Mark()++;
    break;

    default:
    break;

}
INST_COUNTER->Mark()++;
  return this;
}

/*======================COMPUTE_WITH_KO_DATAActivity========================*/


COMPUTE_UNITSAN::COMPUTE_WITH_KO_DATAActivity::COMPUTE_WITH_KO_DATAActivity(){
  ActivityInitialize("COMPUTE_WITH_KO_DATA",2,Instantaneous , RaceEnabled, 4,2, false);
}

void COMPUTE_UNITSAN::COMPUTE_WITH_KO_DATAActivity::LinkVariables(){
  ALU_INSTRUCTION->Register(&ALU_INSTRUCTION_Mobius_Mark);
  KO_READ->Register(&KO_READ_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool COMPUTE_UNITSAN::COMPUTE_WITH_KO_DATAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ALU_INSTRUCTION_Mobius_Mark)) >=1)&&((*(KO_READ_Mobius_Mark)) >=1));
  return NewEnabled;
}

double COMPUTE_UNITSAN::COMPUTE_WITH_KO_DATAActivity::Weight(){ 
  return 1;
}

bool COMPUTE_UNITSAN::COMPUTE_WITH_KO_DATAActivity::ReactivationPredicate(){ 
  return false;
}

bool COMPUTE_UNITSAN::COMPUTE_WITH_KO_DATAActivity::ReactivationFunction(){ 
  return false;
}

double COMPUTE_UNITSAN::COMPUTE_WITH_KO_DATAActivity::SampleDistribution(){
  return 0;
}

double* COMPUTE_UNITSAN::COMPUTE_WITH_KO_DATAActivity::ReturnDistributionParameters(){
    return NULL;
}

int COMPUTE_UNITSAN::COMPUTE_WITH_KO_DATAActivity::Rank(){
  return 1;
}

BaseActionClass* COMPUTE_UNITSAN::COMPUTE_WITH_KO_DATAActivity::Fire(){
  (*(ALU_INSTRUCTION_Mobius_Mark))--;
  (*(KO_READ_Mobius_Mark))--;
  (*(RESULT_KO_Mobius_Mark))++;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

/*======================COMPUTE_WITH_OK_DATAActivity========================*/


COMPUTE_UNITSAN::COMPUTE_WITH_OK_DATAActivity::COMPUTE_WITH_OK_DATAActivity(){
  ActivityInitialize("COMPUTE_WITH_OK_DATA",3,Instantaneous , RaceEnabled, 4,2, false);
}

void COMPUTE_UNITSAN::COMPUTE_WITH_OK_DATAActivity::LinkVariables(){
  ALU_INSTRUCTION->Register(&ALU_INSTRUCTION_Mobius_Mark);
  OK_READ->Register(&OK_READ_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool COMPUTE_UNITSAN::COMPUTE_WITH_OK_DATAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ALU_INSTRUCTION_Mobius_Mark)) >=1)&&((*(OK_READ_Mobius_Mark)) >=1));
  return NewEnabled;
}

double COMPUTE_UNITSAN::COMPUTE_WITH_OK_DATAActivity::Weight(){ 
  return 1;
}

bool COMPUTE_UNITSAN::COMPUTE_WITH_OK_DATAActivity::ReactivationPredicate(){ 
  return false;
}

bool COMPUTE_UNITSAN::COMPUTE_WITH_OK_DATAActivity::ReactivationFunction(){ 
  return false;
}

double COMPUTE_UNITSAN::COMPUTE_WITH_OK_DATAActivity::SampleDistribution(){
  return 0;
}

double* COMPUTE_UNITSAN::COMPUTE_WITH_OK_DATAActivity::ReturnDistributionParameters(){
    return NULL;
}

int COMPUTE_UNITSAN::COMPUTE_WITH_OK_DATAActivity::Rank(){
  return 1;
}

BaseActionClass* COMPUTE_UNITSAN::COMPUTE_WITH_OK_DATAActivity::Fire(){
  (*(ALU_INSTRUCTION_Mobius_Mark))--;
  (*(OK_READ_Mobius_Mark))--;
  (*(RESULT_OK_Mobius_Mark))++;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

/*======================GETTING_CONST_VALActivity_case1========================*/


COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case1::GETTING_CONST_VALActivity_case1(){
  ActivityInitialize("GETTING_CONST_VAL_case1",4,Instantaneous , RaceEnabled, 3,1, false);
}

void COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case1::LinkVariables(){
  GET_CONSTANT->Register(&GET_CONSTANT_Mobius_Mark);
  KO_READ->Register(&KO_READ_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(GET_CONSTANT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case1::Weight(){ 
  return 0.5;
}

bool COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case1::ReactivationFunction(){ 
  return false;
}

double COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case1::SampleDistribution(){
  return 0;
}

double* COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case1::Rank(){
  return 1;
}

BaseActionClass* COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case1::Fire(){
  (*(GET_CONSTANT_Mobius_Mark))--;
  (*(KO_READ_Mobius_Mark))++;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

/*======================GETTING_CONST_VALActivity_case2========================*/


COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case2::GETTING_CONST_VALActivity_case2(){
  ActivityInitialize("GETTING_CONST_VAL_case2",4,Instantaneous , RaceEnabled, 3,1, false);
}

void COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case2::LinkVariables(){
  GET_CONSTANT->Register(&GET_CONSTANT_Mobius_Mark);
  OK_READ->Register(&OK_READ_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(GET_CONSTANT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case2::Weight(){ 
  return 0.5;
}

bool COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case2::ReactivationFunction(){ 
  return false;
}

double COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case2::SampleDistribution(){
  return 0;
}

double* COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case2::Rank(){
  return 1;
}

BaseActionClass* COMPUTE_UNITSAN::GETTING_CONST_VALActivity_case2::Fire(){
  (*(GET_CONSTANT_Mobius_Mark))--;
  (*(OK_READ_Mobius_Mark))++;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

