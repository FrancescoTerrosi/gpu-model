

// This C++ file was created by SanEditor

#include "Atomic/COMPUTE_UNIT/COMPUTE_UNITSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         COMPUTE_UNITSAN Constructor             
******************************************************************/


COMPUTE_UNITSAN::COMPUTE_UNITSAN(){


  Instantaneous_Activity2Group.initialize(2, "Instantaneous_Activity2Group");
  Instantaneous_Activity2Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity2_case1);
  Instantaneous_Activity2Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity2_case2);

  Instantaneous_Activity3Group.initialize(2, "Instantaneous_Activity3Group");
  Instantaneous_Activity3Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity3_case1);
  Instantaneous_Activity3Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity3_case2);

  Instantaneous_Activity4Group.initialize(2, "Instantaneous_Activity4Group");
  Instantaneous_Activity4Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity4_case1);
  Instantaneous_Activity4Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity4_case2);

  Activity* InitialActionList[10]={
    &Instantaneous_Activity1, //0
    &DISPATCHER, //1
    &COMPUTE_WITH_KO_DATA, //2
    &COMPUTE_WITH_OK_DATA, //3
    &Instantaneous_Activity2_case1, //4
    &Instantaneous_Activity2_case2, //5
    &Instantaneous_Activity3_case1, //6
    &Instantaneous_Activity3_case2, //7
    &Instantaneous_Activity4_case1, //8
    &Instantaneous_Activity4_case2  // 9
  };

  BaseGroupClass* InitialGroupList[7]={
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(DISPATCHER), 
    (BaseGroupClass*) &(COMPUTE_WITH_KO_DATA), 
    (BaseGroupClass*) &(COMPUTE_WITH_OK_DATA), 
    (BaseGroupClass*) &(Instantaneous_Activity2Group), 
    (BaseGroupClass*) &(Instantaneous_Activity3Group), 
    (BaseGroupClass*) &(Instantaneous_Activity4Group)
  };

  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  ALU_INSTRUCTION = new Place("ALU_INSTRUCTION" ,0);
  KO_READ = new Place("KO_READ" ,0);
  READ_GLOBAL_MEMORY = new Place("READ_GLOBAL_MEMORY" ,0);
  WRITE_GLOBAL_MEMORY = new Place("WRITE_GLOBAL_MEMORY" ,0);
  WRITE_LOCAL_MEMORY = new Place("WRITE_LOCAL_MEMORY" ,0);
  READ_LOCAL_MEMORY = new Place("READ_LOCAL_MEMORY" ,0);
  RESULT_KO = new Place("RESULT_KO" ,10000);
  OK_READ = new Place("OK_READ" ,0);
  RESULT_OK = new Place("RESULT_OK" ,10000);
  READ_REGISTER_FILE = new Place("READ_REGISTER_FILE" ,0);
  WRITE_OUTPUT_MEMORY = new Place("WRITE_OUTPUT_MEMORY" ,0);
  WRITE_REGISTER_FILE = new Place("WRITE_REGISTER_FILE" ,0);
  MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE" ,0);
  ALU_INSTRUCTION_NO_DATA = new Place("ALU_INSTRUCTION_NO_DATA" ,0);
  REGISTERS_FILL = new Place("REGISTERS_FILL" ,0);
  OK_CONTENT = new Place("OK_CONTENT" ,0);
  READ_GLOBAL_WITH_PROBABILITY = new Place("READ_GLOBAL_WITH_PROBABILITY" ,0);
  READ_LOCAL_WITH_PROBABILITY = new Place("READ_LOCAL_WITH_PROBABILITY" ,0);
  short temp_SCHEDULERshort = -1;
  SCHEDULER = new ExtendedPlace<short>("SCHEDULER",temp_SCHEDULERshort);
  BaseStateVariableClass* InitialPlaces[20]={
    INSTRUCTION_READY,  // 0
    ALU_INSTRUCTION,  // 1
    KO_READ,  // 2
    READ_GLOBAL_MEMORY,  // 3
    WRITE_GLOBAL_MEMORY,  // 4
    WRITE_LOCAL_MEMORY,  // 5
    READ_LOCAL_MEMORY,  // 6
    RESULT_KO,  // 7
    OK_READ,  // 8
    RESULT_OK,  // 9
    READ_REGISTER_FILE,  // 10
    WRITE_OUTPUT_MEMORY,  // 11
    WRITE_REGISTER_FILE,  // 12
    MEM_OP_COMPLETE,  // 13
    ALU_INSTRUCTION_NO_DATA,  // 14
    REGISTERS_FILL,  // 15
    OK_CONTENT,  // 16
    READ_GLOBAL_WITH_PROBABILITY,  // 17
    READ_LOCAL_WITH_PROBABILITY,  // 18
    SCHEDULER   // 19
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("COMPUTE_UNIT", 20, InitialPlaces, 
                        0, InitialROPlaces, 
                        10, InitialActionList, 7, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[35][2]={ 
    {13,0}, {0,0}, {0,1}, {19,1}, {17,1}, {4,1}, {18,1}, {5,1}, 
    {10,1}, {12,1}, {11,1}, {14,1}, {1,1}, {1,2}, {2,2}, {0,2}, 
    {7,2}, {1,3}, {8,3}, {0,3}, {9,3}, {14,4}, {0,4}, {7,4}, 
    {14,5}, {0,5}, {9,5}, {17,6}, {10,6}, {17,7}, {3,7}, {18,8}, 
    {10,8}, {18,9}, {6,9}
  };
  for(int n=0;n<35;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[13][2]={ 
    {13,0}, {19,1}, {15,1}, {1,2}, {2,2}, {1,3}, {8,3}, {14,4}, 
    {14,5}, {17,6}, {17,7}, {18,8}, {18,9}
  };
  for(int n=0;n<13;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<10;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void COMPUTE_UNITSAN::CustomInitialization() {

}
COMPUTE_UNITSAN::~COMPUTE_UNITSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void COMPUTE_UNITSAN::assignPlacesToActivitiesInst(){
  Instantaneous_Activity1.MEM_OP_COMPLETE = (Place*) LocalStateVariables[13];
  Instantaneous_Activity1.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  DISPATCHER.SCHEDULER = (ExtendedPlace<short>*) LocalStateVariables[19];
  DISPATCHER.REGISTERS_FILL = (Place*) LocalStateVariables[15];
  DISPATCHER.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  DISPATCHER.READ_GLOBAL_WITH_PROBABILITY = (Place*) LocalStateVariables[17];
  DISPATCHER.WRITE_GLOBAL_MEMORY = (Place*) LocalStateVariables[4];
  DISPATCHER.READ_LOCAL_WITH_PROBABILITY = (Place*) LocalStateVariables[18];
  DISPATCHER.WRITE_LOCAL_MEMORY = (Place*) LocalStateVariables[5];
  DISPATCHER.READ_REGISTER_FILE = (Place*) LocalStateVariables[10];
  DISPATCHER.WRITE_REGISTER_FILE = (Place*) LocalStateVariables[12];
  DISPATCHER.WRITE_OUTPUT_MEMORY = (Place*) LocalStateVariables[11];
  DISPATCHER.ALU_INSTRUCTION_NO_DATA = (Place*) LocalStateVariables[14];
  DISPATCHER.ALU_INSTRUCTION = (Place*) LocalStateVariables[1];
  COMPUTE_WITH_KO_DATA.ALU_INSTRUCTION = (Place*) LocalStateVariables[1];
  COMPUTE_WITH_KO_DATA.KO_READ = (Place*) LocalStateVariables[2];
  COMPUTE_WITH_KO_DATA.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  COMPUTE_WITH_KO_DATA.RESULT_KO = (Place*) LocalStateVariables[7];
  COMPUTE_WITH_OK_DATA.ALU_INSTRUCTION = (Place*) LocalStateVariables[1];
  COMPUTE_WITH_OK_DATA.OK_READ = (Place*) LocalStateVariables[8];
  COMPUTE_WITH_OK_DATA.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  COMPUTE_WITH_OK_DATA.RESULT_OK = (Place*) LocalStateVariables[9];
  Instantaneous_Activity2_case1.ALU_INSTRUCTION_NO_DATA = (Place*) LocalStateVariables[14];
  Instantaneous_Activity2_case1.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  Instantaneous_Activity2_case1.RESULT_KO = (Place*) LocalStateVariables[7];
  Instantaneous_Activity2_case2.ALU_INSTRUCTION_NO_DATA = (Place*) LocalStateVariables[14];
  Instantaneous_Activity2_case2.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  Instantaneous_Activity2_case2.RESULT_OK = (Place*) LocalStateVariables[9];
  Instantaneous_Activity3_case1.READ_GLOBAL_WITH_PROBABILITY = (Place*) LocalStateVariables[17];
  Instantaneous_Activity3_case1.READ_REGISTER_FILE = (Place*) LocalStateVariables[10];
  Instantaneous_Activity3_case1.OK_CONTENT = (Place*) LocalStateVariables[16];
  Instantaneous_Activity3_case2.READ_GLOBAL_WITH_PROBABILITY = (Place*) LocalStateVariables[17];
  Instantaneous_Activity3_case2.READ_GLOBAL_MEMORY = (Place*) LocalStateVariables[3];
  Instantaneous_Activity3_case2.OK_CONTENT = (Place*) LocalStateVariables[16];
  Instantaneous_Activity4_case1.READ_LOCAL_WITH_PROBABILITY = (Place*) LocalStateVariables[18];
  Instantaneous_Activity4_case1.READ_REGISTER_FILE = (Place*) LocalStateVariables[10];
  Instantaneous_Activity4_case1.OK_CONTENT = (Place*) LocalStateVariables[16];
  Instantaneous_Activity4_case2.READ_LOCAL_WITH_PROBABILITY = (Place*) LocalStateVariables[18];
  Instantaneous_Activity4_case2.READ_LOCAL_MEMORY = (Place*) LocalStateVariables[6];
  Instantaneous_Activity4_case2.OK_CONTENT = (Place*) LocalStateVariables[16];
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
  ActivityInitialize("DISPATCHER",1,Instantaneous , RaceEnabled, 11,2, false);
}

void COMPUTE_UNITSAN::DISPATCHERActivity::LinkVariables(){

  REGISTERS_FILL->Register(&REGISTERS_FILL_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  READ_GLOBAL_WITH_PROBABILITY->Register(&READ_GLOBAL_WITH_PROBABILITY_Mobius_Mark);
  WRITE_GLOBAL_MEMORY->Register(&WRITE_GLOBAL_MEMORY_Mobius_Mark);
  READ_LOCAL_WITH_PROBABILITY->Register(&READ_LOCAL_WITH_PROBABILITY_Mobius_Mark);
  WRITE_LOCAL_MEMORY->Register(&WRITE_LOCAL_MEMORY_Mobius_Mark);
  READ_REGISTER_FILE->Register(&READ_REGISTER_FILE_Mobius_Mark);
  WRITE_REGISTER_FILE->Register(&WRITE_REGISTER_FILE_Mobius_Mark);
  WRITE_OUTPUT_MEMORY->Register(&WRITE_OUTPUT_MEMORY_Mobius_Mark);
  ALU_INSTRUCTION_NO_DATA->Register(&ALU_INSTRUCTION_NO_DATA_Mobius_Mark);
  ALU_INSTRUCTION->Register(&ALU_INSTRUCTION_Mobius_Mark);
}

bool COMPUTE_UNITSAN::DISPATCHERActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((SCHEDULER->Mark() > -1 && REGISTERS_FILL->Mark() == 0));
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
INSTRUCTION_READY->Mark()++;
  switch( SCHEDULER->Mark() ) {

    case 0:
	READ_GLOBAL_WITH_PROBABILITY->Mark()++;
    break;

    case 1:
        WRITE_GLOBAL_MEMORY->Mark()++;
    break;

    case 2:
	READ_LOCAL_WITH_PROBABILITY->Mark()++;
    break;

    case 3:
        WRITE_LOCAL_MEMORY->Mark()++;
    break;

    case 4:
        READ_REGISTER_FILE->Mark()++;
    break;

    case 5:
        WRITE_REGISTER_FILE->Mark()++;
    break;

    case 6:
        WRITE_OUTPUT_MEMORY->Mark()++;
    break;

    case 7:
        ALU_INSTRUCTION_NO_DATA->Mark()++;
    break;

    case 8:
        ALU_INSTRUCTION->Mark()++;
    break;

    default:
    break;
}
SCHEDULER->Mark() = -1;
  return this;
}

/*======================COMPUTE_WITH_KO_DATAActivity========================*/


COMPUTE_UNITSAN::COMPUTE_WITH_KO_DATAActivity::COMPUTE_WITH_KO_DATAActivity(){
  ActivityInitialize("COMPUTE_WITH_KO_DATA",2,Instantaneous , RaceEnabled, 4,2, false);
}

void COMPUTE_UNITSAN::COMPUTE_WITH_KO_DATAActivity::LinkVariables(){
  ALU_INSTRUCTION->Register(&ALU_INSTRUCTION_Mobius_Mark);
  KO_READ->Register(&KO_READ_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
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
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  (*(RESULT_KO_Mobius_Mark))++;
  return this;
}

/*======================COMPUTE_WITH_OK_DATAActivity========================*/


COMPUTE_UNITSAN::COMPUTE_WITH_OK_DATAActivity::COMPUTE_WITH_OK_DATAActivity(){
  ActivityInitialize("COMPUTE_WITH_OK_DATA",3,Instantaneous , RaceEnabled, 4,2, false);
}

void COMPUTE_UNITSAN::COMPUTE_WITH_OK_DATAActivity::LinkVariables(){
  ALU_INSTRUCTION->Register(&ALU_INSTRUCTION_Mobius_Mark);
  OK_READ->Register(&OK_READ_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
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
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  (*(RESULT_OK_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity2Activity_case1========================*/


COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case1::Instantaneous_Activity2Activity_case1(){
  ActivityInitialize("Instantaneous_Activity2_case1",4,Instantaneous , RaceEnabled, 3,1, false);
}

void COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case1::LinkVariables(){
  ALU_INSTRUCTION_NO_DATA->Register(&ALU_INSTRUCTION_NO_DATA_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
}

bool COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ALU_INSTRUCTION_NO_DATA_Mobius_Mark)) >=1));
  return NewEnabled;
}

double COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case1::Weight(){ 
  return 0.5;
}

bool COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case1::ReactivationPredicate(){ 
  return false;
}

bool COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case1::ReactivationFunction(){ 
  return false;
}

double COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case1::SampleDistribution(){
  return 0;
}

double* COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case1::ReturnDistributionParameters(){
    return NULL;
}

int COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case1::Rank(){
  return 1;
}

BaseActionClass* COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case1::Fire(){
  (*(ALU_INSTRUCTION_NO_DATA_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  (*(RESULT_KO_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity2Activity_case2========================*/


COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case2::Instantaneous_Activity2Activity_case2(){
  ActivityInitialize("Instantaneous_Activity2_case2",4,Instantaneous , RaceEnabled, 3,1, false);
}

void COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case2::LinkVariables(){
  ALU_INSTRUCTION_NO_DATA->Register(&ALU_INSTRUCTION_NO_DATA_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
}

bool COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ALU_INSTRUCTION_NO_DATA_Mobius_Mark)) >=1));
  return NewEnabled;
}

double COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case2::Weight(){ 
  return 0.5;
}

bool COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case2::ReactivationPredicate(){ 
  return false;
}

bool COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case2::ReactivationFunction(){ 
  return false;
}

double COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case2::SampleDistribution(){
  return 0;
}

double* COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case2::ReturnDistributionParameters(){
    return NULL;
}

int COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case2::Rank(){
  return 1;
}

BaseActionClass* COMPUTE_UNITSAN::Instantaneous_Activity2Activity_case2::Fire(){
  (*(ALU_INSTRUCTION_NO_DATA_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  (*(RESULT_OK_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity3Activity_case1========================*/


COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case1::Instantaneous_Activity3Activity_case1(){
  ActivityInitialize("Instantaneous_Activity3_case1",5,Instantaneous , RaceEnabled, 2,1, false);
}

void COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case1::LinkVariables(){
  READ_GLOBAL_WITH_PROBABILITY->Register(&READ_GLOBAL_WITH_PROBABILITY_Mobius_Mark);
  READ_REGISTER_FILE->Register(&READ_REGISTER_FILE_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
}

bool COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_GLOBAL_WITH_PROBABILITY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case1::Weight(){ 
  return 1.0/OK_CONTENT->Mark();
}

bool COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case1::ReactivationPredicate(){ 
  return false;
}

bool COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case1::ReactivationFunction(){ 
  return false;
}

double COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case1::SampleDistribution(){
  return 0;
}

double* COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case1::ReturnDistributionParameters(){
    return NULL;
}

int COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case1::Rank(){
  return 1;
}

BaseActionClass* COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case1::Fire(){
  (*(READ_GLOBAL_WITH_PROBABILITY_Mobius_Mark))--;
  (*(READ_REGISTER_FILE_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity3Activity_case2========================*/


COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case2::Instantaneous_Activity3Activity_case2(){
  ActivityInitialize("Instantaneous_Activity3_case2",5,Instantaneous , RaceEnabled, 2,1, false);
}

void COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case2::LinkVariables(){
  READ_GLOBAL_WITH_PROBABILITY->Register(&READ_GLOBAL_WITH_PROBABILITY_Mobius_Mark);
  READ_GLOBAL_MEMORY->Register(&READ_GLOBAL_MEMORY_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
}

bool COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_GLOBAL_WITH_PROBABILITY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case2::Weight(){ 
  return 1.0-(1.0/OK_CONTENT->Mark());
}

bool COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case2::ReactivationPredicate(){ 
  return false;
}

bool COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case2::ReactivationFunction(){ 
  return false;
}

double COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case2::SampleDistribution(){
  return 0;
}

double* COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case2::ReturnDistributionParameters(){
    return NULL;
}

int COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case2::Rank(){
  return 1;
}

BaseActionClass* COMPUTE_UNITSAN::Instantaneous_Activity3Activity_case2::Fire(){
  (*(READ_GLOBAL_WITH_PROBABILITY_Mobius_Mark))--;
  (*(READ_GLOBAL_MEMORY_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity4Activity_case1========================*/


COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case1::Instantaneous_Activity4Activity_case1(){
  ActivityInitialize("Instantaneous_Activity4_case1",6,Instantaneous , RaceEnabled, 2,1, false);
}

void COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case1::LinkVariables(){
  READ_LOCAL_WITH_PROBABILITY->Register(&READ_LOCAL_WITH_PROBABILITY_Mobius_Mark);
  READ_REGISTER_FILE->Register(&READ_REGISTER_FILE_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
}

bool COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_LOCAL_WITH_PROBABILITY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case1::Weight(){ 
  return 1.0/OK_CONTENT->Mark();
}

bool COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case1::ReactivationPredicate(){ 
  return false;
}

bool COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case1::ReactivationFunction(){ 
  return false;
}

double COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case1::SampleDistribution(){
  return 0;
}

double* COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case1::ReturnDistributionParameters(){
    return NULL;
}

int COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case1::Rank(){
  return 1;
}

BaseActionClass* COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case1::Fire(){
  (*(READ_LOCAL_WITH_PROBABILITY_Mobius_Mark))--;
  (*(READ_REGISTER_FILE_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity4Activity_case2========================*/


COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case2::Instantaneous_Activity4Activity_case2(){
  ActivityInitialize("Instantaneous_Activity4_case2",6,Instantaneous , RaceEnabled, 2,1, false);
}

void COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case2::LinkVariables(){
  READ_LOCAL_WITH_PROBABILITY->Register(&READ_LOCAL_WITH_PROBABILITY_Mobius_Mark);
  READ_LOCAL_MEMORY->Register(&READ_LOCAL_MEMORY_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
}

bool COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_LOCAL_WITH_PROBABILITY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case2::Weight(){ 
  return 1.0-(1.0/OK_CONTENT->Mark());
}

bool COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case2::ReactivationPredicate(){ 
  return false;
}

bool COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case2::ReactivationFunction(){ 
  return false;
}

double COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case2::SampleDistribution(){
  return 0;
}

double* COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case2::ReturnDistributionParameters(){
    return NULL;
}

int COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case2::Rank(){
  return 1;
}

BaseActionClass* COMPUTE_UNITSAN::Instantaneous_Activity4Activity_case2::Fire(){
  (*(READ_LOCAL_WITH_PROBABILITY_Mobius_Mark))--;
  (*(READ_LOCAL_MEMORY_Mobius_Mark))++;
  return this;
}

