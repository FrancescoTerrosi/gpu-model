

// This C++ file was created by SanEditor

#include "Atomic/EXEC_UNIT/EXEC_UNITSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         EXEC_UNITSAN Constructor             
******************************************************************/


EXEC_UNITSAN::EXEC_UNITSAN(){


  Instantaneous_Activity2Group.initialize(2, "Instantaneous_Activity2Group");
  Instantaneous_Activity2Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity2_case1);
  Instantaneous_Activity2Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity2_case2);

  Activity* InitialActionList[6]={
    &Instantaneous_Activity1, //0
    &DISPATCHER, //1
    &COMPUTE_WITH_KO_DATA, //2
    &COMPUTE_WITH_OK_DATA, //3
    &Instantaneous_Activity2_case1, //4
    &Instantaneous_Activity2_case2  // 5
  };

  BaseGroupClass* InitialGroupList[5]={
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(DISPATCHER), 
    (BaseGroupClass*) &(COMPUTE_WITH_KO_DATA), 
    (BaseGroupClass*) &(COMPUTE_WITH_OK_DATA), 
    (BaseGroupClass*) &(Instantaneous_Activity2Group)
  };

  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  ALU_INSTRUCTION = new Place("ALU_INSTRUCTION" ,0);
  RESULT_KO = new Place("RESULT_KO" ,10000);
  RESULT_OK = new Place("RESULT_OK" ,10000);
  MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE" ,0);
  ALU_INSTRUCTION_NO_DATA = new Place("ALU_INSTRUCTION_NO_DATA" ,0);
  REGISTERS_FILL = new Place("REGISTERS_FILL" ,0);
  OK_CONTENT = new Place("OK_CONTENT" ,0);
  KO_CONTENT = new Place("KO_CONTENT" ,0);
  short temp_SCHEDULERshort = -1;
  SCHEDULER = new ExtendedPlace<short>("SCHEDULER",temp_SCHEDULERshort);
  short temp_READshort = -1;
  READ = new ExtendedPlace<short>("READ",temp_READshort);
  short temp_WRITEshort = -1;
  WRITE = new ExtendedPlace<short>("WRITE",temp_WRITEshort);
  BaseStateVariableClass* InitialPlaces[12]={
    INSTRUCTION_READY,  // 0
    ALU_INSTRUCTION,  // 1
    RESULT_KO,  // 2
    RESULT_OK,  // 3
    MEM_OP_COMPLETE,  // 4
    ALU_INSTRUCTION_NO_DATA,  // 5
    REGISTERS_FILL,  // 6
    OK_CONTENT,  // 7
    KO_CONTENT,  // 8
    SCHEDULER,  // 9
    READ,  // 10
    WRITE   // 11
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("EXEC_UNIT", 12, InitialPlaces, 
                        0, InitialROPlaces, 
                        6, InitialActionList, 5, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[19][2]={ 
    {4,0}, {0,0}, {0,1}, {9,1}, {10,1}, {11,1}, {5,1}, {1,2}, 
    {0,2}, {2,2}, {1,3}, {0,3}, {3,3}, {5,4}, {0,4}, {2,4}, {5,5}, 
    {0,5}, {3,5}
  };
  for(int n=0;n<19;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[7][2]={ 
    {4,0}, {9,1}, {6,1}, {1,2}, {1,3}, {5,4}, {5,5}
  };
  for(int n=0;n<7;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<6;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void EXEC_UNITSAN::CustomInitialization() {

}
EXEC_UNITSAN::~EXEC_UNITSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void EXEC_UNITSAN::assignPlacesToActivitiesInst(){
  Instantaneous_Activity1.MEM_OP_COMPLETE = (Place*) LocalStateVariables[4];
  Instantaneous_Activity1.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  DISPATCHER.SCHEDULER = (ExtendedPlace<short>*) LocalStateVariables[9];
  DISPATCHER.REGISTERS_FILL = (Place*) LocalStateVariables[6];
  DISPATCHER.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  DISPATCHER.READ = (ExtendedPlace<short>*) LocalStateVariables[10];
  DISPATCHER.WRITE = (ExtendedPlace<short>*) LocalStateVariables[11];
  DISPATCHER.ALU_INSTRUCTION_NO_DATA = (Place*) LocalStateVariables[5];
  COMPUTE_WITH_KO_DATA.ALU_INSTRUCTION = (Place*) LocalStateVariables[1];
  COMPUTE_WITH_KO_DATA.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  COMPUTE_WITH_KO_DATA.RESULT_KO = (Place*) LocalStateVariables[2];
  COMPUTE_WITH_OK_DATA.ALU_INSTRUCTION = (Place*) LocalStateVariables[1];
  COMPUTE_WITH_OK_DATA.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  COMPUTE_WITH_OK_DATA.RESULT_OK = (Place*) LocalStateVariables[3];
  Instantaneous_Activity2_case1.ALU_INSTRUCTION_NO_DATA = (Place*) LocalStateVariables[5];
  Instantaneous_Activity2_case1.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  Instantaneous_Activity2_case1.RESULT_KO = (Place*) LocalStateVariables[2];
  Instantaneous_Activity2_case2.ALU_INSTRUCTION_NO_DATA = (Place*) LocalStateVariables[5];
  Instantaneous_Activity2_case2.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  Instantaneous_Activity2_case2.RESULT_OK = (Place*) LocalStateVariables[3];
}
void EXEC_UNITSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================Instantaneous_Activity1Activity========================*/


EXEC_UNITSAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",0,Instantaneous , RaceEnabled, 2,1, false);
}

void EXEC_UNITSAN::Instantaneous_Activity1Activity::LinkVariables(){
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool EXEC_UNITSAN::Instantaneous_Activity1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEM_OP_COMPLETE_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNITSAN::Instantaneous_Activity1Activity::Weight(){ 
  return 1;
}

bool EXEC_UNITSAN::Instantaneous_Activity1Activity::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNITSAN::Instantaneous_Activity1Activity::ReactivationFunction(){ 
  return false;
}

double EXEC_UNITSAN::Instantaneous_Activity1Activity::SampleDistribution(){
  return 0;
}

double* EXEC_UNITSAN::Instantaneous_Activity1Activity::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNITSAN::Instantaneous_Activity1Activity::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNITSAN::Instantaneous_Activity1Activity::Fire(){
  (*(MEM_OP_COMPLETE_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

/*======================DISPATCHERActivity========================*/


EXEC_UNITSAN::DISPATCHERActivity::DISPATCHERActivity(){
  ActivityInitialize("DISPATCHER",1,Instantaneous , RaceEnabled, 5,2, false);
}

void EXEC_UNITSAN::DISPATCHERActivity::LinkVariables(){

  REGISTERS_FILL->Register(&REGISTERS_FILL_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);


  ALU_INSTRUCTION_NO_DATA->Register(&ALU_INSTRUCTION_NO_DATA_Mobius_Mark);
}

bool EXEC_UNITSAN::DISPATCHERActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((SCHEDULER->Mark() > -1 && REGISTERS_FILL->Mark() == 0));
  return NewEnabled;
}

double EXEC_UNITSAN::DISPATCHERActivity::Weight(){ 
  return 1;
}

bool EXEC_UNITSAN::DISPATCHERActivity::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNITSAN::DISPATCHERActivity::ReactivationFunction(){ 
  return false;
}

double EXEC_UNITSAN::DISPATCHERActivity::SampleDistribution(){
  return 0;
}

double* EXEC_UNITSAN::DISPATCHERActivity::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNITSAN::DISPATCHERActivity::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNITSAN::DISPATCHERActivity::Fire(){
  INSTRUCTION_READY->Mark()--;
INSTRUCTION_READY->Mark()++;
  switch( SCHEDULER->Mark() ) {

    case 0:
	READ->Mark() = SCHEDULER->Mark();
    break;

    case 1:
        WRITE->Mark() = SCHEDULER->Mark();
    break;

    case 2:
        READ->Mark() = SCHEDULER->Mark();
    break;

    case 3:
        WRITE->Mark() = SCHEDULER->Mark();
    break;

    case 4:
	READ->Mark() = SCHEDULER->Mark();
    break;

    case 5:
        WRITE->Mark() = SCHEDULER->Mark();
    break;

    case 6:
        ALU_INSTRUCTION_NO_DATA->Mark()++;
    break;

    case 7:
        ALU_INSTRUCTION_NO_DATA->Mark()++;
    break;

    default:
    break;
}
SCHEDULER->Mark() = -1;
  return this;
}

/*======================COMPUTE_WITH_KO_DATAActivity========================*/


EXEC_UNITSAN::COMPUTE_WITH_KO_DATAActivity::COMPUTE_WITH_KO_DATAActivity(){
  ActivityInitialize("COMPUTE_WITH_KO_DATA",2,Instantaneous , RaceEnabled, 3,1, false);
}

void EXEC_UNITSAN::COMPUTE_WITH_KO_DATAActivity::LinkVariables(){
  ALU_INSTRUCTION->Register(&ALU_INSTRUCTION_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
}

bool EXEC_UNITSAN::COMPUTE_WITH_KO_DATAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ALU_INSTRUCTION_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNITSAN::COMPUTE_WITH_KO_DATAActivity::Weight(){ 
  return 1;
}

bool EXEC_UNITSAN::COMPUTE_WITH_KO_DATAActivity::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNITSAN::COMPUTE_WITH_KO_DATAActivity::ReactivationFunction(){ 
  return false;
}

double EXEC_UNITSAN::COMPUTE_WITH_KO_DATAActivity::SampleDistribution(){
  return 0;
}

double* EXEC_UNITSAN::COMPUTE_WITH_KO_DATAActivity::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNITSAN::COMPUTE_WITH_KO_DATAActivity::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNITSAN::COMPUTE_WITH_KO_DATAActivity::Fire(){
  (*(ALU_INSTRUCTION_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  (*(RESULT_KO_Mobius_Mark))++;
  return this;
}

/*======================COMPUTE_WITH_OK_DATAActivity========================*/


EXEC_UNITSAN::COMPUTE_WITH_OK_DATAActivity::COMPUTE_WITH_OK_DATAActivity(){
  ActivityInitialize("COMPUTE_WITH_OK_DATA",3,Instantaneous , RaceEnabled, 3,1, false);
}

void EXEC_UNITSAN::COMPUTE_WITH_OK_DATAActivity::LinkVariables(){
  ALU_INSTRUCTION->Register(&ALU_INSTRUCTION_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
}

bool EXEC_UNITSAN::COMPUTE_WITH_OK_DATAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ALU_INSTRUCTION_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNITSAN::COMPUTE_WITH_OK_DATAActivity::Weight(){ 
  return 1;
}

bool EXEC_UNITSAN::COMPUTE_WITH_OK_DATAActivity::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNITSAN::COMPUTE_WITH_OK_DATAActivity::ReactivationFunction(){ 
  return false;
}

double EXEC_UNITSAN::COMPUTE_WITH_OK_DATAActivity::SampleDistribution(){
  return 0;
}

double* EXEC_UNITSAN::COMPUTE_WITH_OK_DATAActivity::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNITSAN::COMPUTE_WITH_OK_DATAActivity::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNITSAN::COMPUTE_WITH_OK_DATAActivity::Fire(){
  (*(ALU_INSTRUCTION_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  (*(RESULT_OK_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity2Activity_case1========================*/


EXEC_UNITSAN::Instantaneous_Activity2Activity_case1::Instantaneous_Activity2Activity_case1(){
  ActivityInitialize("Instantaneous_Activity2_case1",4,Instantaneous , RaceEnabled, 3,1, false);
}

void EXEC_UNITSAN::Instantaneous_Activity2Activity_case1::LinkVariables(){
  ALU_INSTRUCTION_NO_DATA->Register(&ALU_INSTRUCTION_NO_DATA_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
}

bool EXEC_UNITSAN::Instantaneous_Activity2Activity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ALU_INSTRUCTION_NO_DATA_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNITSAN::Instantaneous_Activity2Activity_case1::Weight(){ 
  return 1;
}

bool EXEC_UNITSAN::Instantaneous_Activity2Activity_case1::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNITSAN::Instantaneous_Activity2Activity_case1::ReactivationFunction(){ 
  return false;
}

double EXEC_UNITSAN::Instantaneous_Activity2Activity_case1::SampleDistribution(){
  return 0;
}

double* EXEC_UNITSAN::Instantaneous_Activity2Activity_case1::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNITSAN::Instantaneous_Activity2Activity_case1::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNITSAN::Instantaneous_Activity2Activity_case1::Fire(){
  (*(ALU_INSTRUCTION_NO_DATA_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  (*(RESULT_KO_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity2Activity_case2========================*/


EXEC_UNITSAN::Instantaneous_Activity2Activity_case2::Instantaneous_Activity2Activity_case2(){
  ActivityInitialize("Instantaneous_Activity2_case2",4,Instantaneous , RaceEnabled, 3,1, false);
}

void EXEC_UNITSAN::Instantaneous_Activity2Activity_case2::LinkVariables(){
  ALU_INSTRUCTION_NO_DATA->Register(&ALU_INSTRUCTION_NO_DATA_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
}

bool EXEC_UNITSAN::Instantaneous_Activity2Activity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ALU_INSTRUCTION_NO_DATA_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNITSAN::Instantaneous_Activity2Activity_case2::Weight(){ 
  return 0;
}

bool EXEC_UNITSAN::Instantaneous_Activity2Activity_case2::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNITSAN::Instantaneous_Activity2Activity_case2::ReactivationFunction(){ 
  return false;
}

double EXEC_UNITSAN::Instantaneous_Activity2Activity_case2::SampleDistribution(){
  return 0;
}

double* EXEC_UNITSAN::Instantaneous_Activity2Activity_case2::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNITSAN::Instantaneous_Activity2Activity_case2::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNITSAN::Instantaneous_Activity2Activity_case2::Fire(){
  (*(ALU_INSTRUCTION_NO_DATA_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  (*(RESULT_OK_Mobius_Mark))++;
  return this;
}

