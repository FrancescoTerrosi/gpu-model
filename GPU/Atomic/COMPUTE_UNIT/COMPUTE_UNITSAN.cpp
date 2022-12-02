

// This C++ file was created by SanEditor

#include "Atomic/COMPUTE_UNIT/COMPUTE_UNITSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         COMPUTE_UNITSAN Constructor             
******************************************************************/


COMPUTE_UNITSAN::COMPUTE_UNITSAN(){


  Activity* InitialActionList[4]={
    &DISPATCHER, //0
    &COMPUTE_WITH_OK_DATA, //1
    &COMPUTE_WITH_KO_DATA, //2
    &Instantaneous_Activity1  // 3
  };

  BaseGroupClass* InitialGroupList[4]={
    (BaseGroupClass*) &(DISPATCHER), 
    (BaseGroupClass*) &(COMPUTE_WITH_OK_DATA), 
    (BaseGroupClass*) &(COMPUTE_WITH_KO_DATA), 
    (BaseGroupClass*) &(Instantaneous_Activity1)
  };

  READ_TOTAL_MEMORY = new Place("READ_TOTAL_MEMORY" ,0);
  READ_RESULT_MEMORY = new Place("READ_RESULT_MEMORY" ,0);
  INST_COUNTER = new Place("INST_COUNTER" ,0);
  ALU_INSTRUCTION = new Place("ALU_INSTRUCTION" ,0);
  WRITE_OUTPUT_MEMORY = new Place("WRITE_OUTPUT_MEMORY" ,0);
  WRITE_RESULT_MEMORY = new Place("WRITE_RESULT_MEMORY" ,0);
  OK_READ = new Place("OK_READ" ,0);
  KO_READ = new Place("KO_READ" ,0);
  RESULT_KO = new Place("RESULT_KO" ,0);
  RESULT_OK = new Place("RESULT_OK" ,0);
  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE" ,0);
  short temp_SCHEDULERInstructionsvalue = -1;
  SCHEDULER = new Instructions("SCHEDULER",temp_SCHEDULERInstructionsvalue);
  BaseStateVariableClass* InitialPlaces[13]={
    READ_TOTAL_MEMORY,  // 0
    READ_RESULT_MEMORY,  // 1
    INST_COUNTER,  // 2
    ALU_INSTRUCTION,  // 3
    WRITE_OUTPUT_MEMORY,  // 4
    WRITE_RESULT_MEMORY,  // 5
    OK_READ,  // 6
    KO_READ,  // 7
    RESULT_KO,  // 8
    RESULT_OK,  // 9
    INSTRUCTION_READY,  // 10
    MEM_OP_COMPLETE,  // 11
    SCHEDULER   // 12
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("COMPUTE_UNIT", 13, InitialPlaces, 
                        0, InitialROPlaces, 
                        4, InitialActionList, 4, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[18][2]={ 
    {10,0}, {2,0}, {0,0}, {1,0}, {5,0}, {4,0}, {3,0}, {12,0}, 
    {3,1}, {6,1}, {9,1}, {10,1}, {3,2}, {7,2}, {8,2}, {10,2}, 
    {11,3}, {10,3}
  };
  for(int n=0;n<18;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[7][2]={ 
    {2,0}, {10,0}, {3,1}, {6,1}, {3,2}, {7,2}, {11,3}
  };
  for(int n=0;n<7;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<4;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void COMPUTE_UNITSAN::CustomInitialization() {
SCHEDULER->Index(0)->Mark() = 1;
SCHEDULER->Index(1)->Mark() = 1;
SCHEDULER->Index(2)->Mark() = 5;
SCHEDULER->Index(3)->Mark() = 3;
SCHEDULER->Index(4)->Mark() = 1;
SCHEDULER->Index(5)->Mark() = 2;
SCHEDULER->Index(6)->Mark() = 5;
SCHEDULER->Index(7)->Mark() = 3;
SCHEDULER->Index(8)->Mark() = 2;
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
  DISPATCHER.INST_COUNTER = (Place*) LocalStateVariables[2];
  DISPATCHER.INSTRUCTION_READY = (Place*) LocalStateVariables[10];
  DISPATCHER.READ_TOTAL_MEMORY = (Place*) LocalStateVariables[0];
  DISPATCHER.READ_RESULT_MEMORY = (Place*) LocalStateVariables[1];
  DISPATCHER.WRITE_RESULT_MEMORY = (Place*) LocalStateVariables[5];
  DISPATCHER.WRITE_OUTPUT_MEMORY = (Place*) LocalStateVariables[4];
  DISPATCHER.ALU_INSTRUCTION = (Place*) LocalStateVariables[3];
  DISPATCHER.SCHEDULER = (Instructions*) LocalStateVariables[12];
  COMPUTE_WITH_OK_DATA.ALU_INSTRUCTION = (Place*) LocalStateVariables[3];
  COMPUTE_WITH_OK_DATA.OK_READ = (Place*) LocalStateVariables[6];
  COMPUTE_WITH_OK_DATA.RESULT_OK = (Place*) LocalStateVariables[9];
  COMPUTE_WITH_OK_DATA.INSTRUCTION_READY = (Place*) LocalStateVariables[10];
  COMPUTE_WITH_KO_DATA.ALU_INSTRUCTION = (Place*) LocalStateVariables[3];
  COMPUTE_WITH_KO_DATA.KO_READ = (Place*) LocalStateVariables[7];
  COMPUTE_WITH_KO_DATA.RESULT_KO = (Place*) LocalStateVariables[8];
  COMPUTE_WITH_KO_DATA.INSTRUCTION_READY = (Place*) LocalStateVariables[10];
  Instantaneous_Activity1.MEM_OP_COMPLETE = (Place*) LocalStateVariables[11];
  Instantaneous_Activity1.INSTRUCTION_READY = (Place*) LocalStateVariables[10];
}
void COMPUTE_UNITSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================DISPATCHERActivity========================*/


COMPUTE_UNITSAN::DISPATCHERActivity::DISPATCHERActivity(){
  ActivityInitialize("DISPATCHER",0,Instantaneous , RaceEnabled, 8,2, false);
}

void COMPUTE_UNITSAN::DISPATCHERActivity::LinkVariables(){
  INST_COUNTER->Register(&INST_COUNTER_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  READ_TOTAL_MEMORY->Register(&READ_TOTAL_MEMORY_Mobius_Mark);
  READ_RESULT_MEMORY->Register(&READ_RESULT_MEMORY_Mobius_Mark);
  WRITE_RESULT_MEMORY->Register(&WRITE_RESULT_MEMORY_Mobius_Mark);
  WRITE_OUTPUT_MEMORY->Register(&WRITE_OUTPUT_MEMORY_Mobius_Mark);
  ALU_INSTRUCTION->Register(&ALU_INSTRUCTION_Mobius_Mark);

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
  if ( SCHEDULER->Index(INST_COUNTER->Mark())->Mark() == 1 ) {
        READ_TOTAL_MEMORY->Mark()++;
	INST_COUNTER->Mark()++;

} else if ( SCHEDULER->Index(INST_COUNTER->Mark())->Mark() ==  2 ) {
        READ_RESULT_MEMORY->Mark()++;
	INST_COUNTER->Mark()++;

} else if ( SCHEDULER->Index(INST_COUNTER->Mark())->Mark() == 3 ) {
        WRITE_RESULT_MEMORY->Mark()++;
	INST_COUNTER->Mark()++;

} else if ( SCHEDULER->Index(INST_COUNTER->Mark())->Mark() == 4 ) {
        WRITE_OUTPUT_MEMORY->Mark()++;
	INST_COUNTER->Mark()++;

} else if ( SCHEDULER->Index(INST_COUNTER->Mark())->Mark() == 5 ) {
        ALU_INSTRUCTION->Mark()++;
	INST_COUNTER->Mark()++;

}

  return this;
}

/*======================COMPUTE_WITH_OK_DATAActivity========================*/


COMPUTE_UNITSAN::COMPUTE_WITH_OK_DATAActivity::COMPUTE_WITH_OK_DATAActivity(){
  ActivityInitialize("COMPUTE_WITH_OK_DATA",1,Instantaneous , RaceEnabled, 4,2, false);
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

/*======================Instantaneous_Activity1Activity========================*/


COMPUTE_UNITSAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",3,Instantaneous , RaceEnabled, 2,1, false);
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

