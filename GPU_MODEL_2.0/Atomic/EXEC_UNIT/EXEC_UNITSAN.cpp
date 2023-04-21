

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

  Instantaneous_Activity3Group.initialize(2, "Instantaneous_Activity3Group");
  Instantaneous_Activity3Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity3_case1);
  Instantaneous_Activity3Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity3_case2);

  Activity* InitialActionList[9]={
    &handle_failure_float, //0
    &DISPATCHER, //1
    &Instantaneous_Activity2_case1, //2
    &Instantaneous_Activity2_case2, //3
    &handle_failure, //4
    &dhn, //5
    &Instantaneous_Activity3_case1, //6
    &Instantaneous_Activity3_case2, //7
    &BARRIER_SYNC  // 8
  };

  BaseGroupClass* InitialGroupList[7]={
    (BaseGroupClass*) &(handle_failure_float), 
    (BaseGroupClass*) &(DISPATCHER), 
    (BaseGroupClass*) &(Instantaneous_Activity2Group), 
    (BaseGroupClass*) &(handle_failure), 
    (BaseGroupClass*) &(dhn), 
    (BaseGroupClass*) &(Instantaneous_Activity3Group), 
    (BaseGroupClass*) &(BARRIER_SYNC)
  };

  FLOAT_ALU_FAILURE = new Place("FLOAT_ALU_FAILURE" ,0);
  ROUTE_ALU_FLOAT = new Place("ROUTE_ALU_FLOAT" ,0);
  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  FLOAT_ALU = new Place("FLOAT_ALU" ,0);
  RESULT_KO = new Place("RESULT_KO" ,0);
  RESULT_OK = new Place("RESULT_OK" ,0);
  MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE" ,0);
  INT_ALU = new Place("INT_ALU" ,0);
  REGISTERS_FILL = new Place("REGISTERS_FILL" ,0);
  OK_CONTENT = new Place("OK_CONTENT" ,0);
  KO_CONTENT = new Place("KO_CONTENT" ,0);
  INT_ALU_FAILURE = new Place("INT_ALU_FAILURE" ,0);
  ROUTE_ALU_INT = new Place("ROUTE_ALU_INT" ,0);
  Place1 = new Place("Place1" ,0);
  BARRIER = new Place("BARRIER" ,0);
  short temp_SCHEDULERshort = -1;
  SCHEDULER = new ExtendedPlace<short>("SCHEDULER",temp_SCHEDULERshort);
  short temp_READshort = -1;
  READ = new ExtendedPlace<short>("READ",temp_READshort);
  short temp_WRITEshort = -1;
  WRITE = new ExtendedPlace<short>("WRITE",temp_WRITEshort);
  BaseStateVariableClass* InitialPlaces[18]={
    FLOAT_ALU_FAILURE,  // 0
    ROUTE_ALU_FLOAT,  // 1
    INSTRUCTION_READY,  // 2
    FLOAT_ALU,  // 3
    RESULT_KO,  // 4
    RESULT_OK,  // 5
    MEM_OP_COMPLETE,  // 6
    INT_ALU,  // 7
    REGISTERS_FILL,  // 8
    OK_CONTENT,  // 9
    KO_CONTENT,  // 10
    INT_ALU_FAILURE,  // 11
    ROUTE_ALU_INT,  // 12
    Place1,  // 13
    BARRIER,  // 14
    SCHEDULER,  // 15
    READ,  // 16
    WRITE   // 17
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("EXEC_UNIT", 18, InitialPlaces, 
                        0, InitialROPlaces, 
                        9, InitialActionList, 7, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[32][2]={ 
    {3,0}, {0,0}, {4,0}, {2,0}, {1,0}, {2,1}, {15,1}, {16,1}, 
    {17,1}, {7,1}, {14,1}, {12,2}, {2,2}, {4,2}, {12,3}, {2,3}, 
    {5,3}, {7,4}, {11,4}, {4,4}, {2,4}, {12,4}, {4,5}, {13,5}, 
    {1,6}, {2,6}, {4,6}, {1,7}, {2,7}, {5,7}, {14,8}, {2,8}
  };
  for(int n=0;n<32;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[10][2]={ 
    {3,0}, {15,1}, {8,1}, {12,2}, {12,3}, {7,4}, {4,5}, {1,6}, 
    {1,7}, {14,8}
  };
  for(int n=0;n<10;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<9;n++) {
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
  handle_failure_float.FLOAT_ALU = (Place*) LocalStateVariables[3];
  handle_failure_float.FLOAT_ALU_FAILURE = (Place*) LocalStateVariables[0];
  handle_failure_float.RESULT_KO = (Place*) LocalStateVariables[4];
  handle_failure_float.INSTRUCTION_READY = (Place*) LocalStateVariables[2];
  handle_failure_float.ROUTE_ALU_FLOAT = (Place*) LocalStateVariables[1];
  DISPATCHER.SCHEDULER = (ExtendedPlace<short>*) LocalStateVariables[15];
  DISPATCHER.REGISTERS_FILL = (Place*) LocalStateVariables[8];
  DISPATCHER.INSTRUCTION_READY = (Place*) LocalStateVariables[2];
  DISPATCHER.READ = (ExtendedPlace<short>*) LocalStateVariables[16];
  DISPATCHER.WRITE = (ExtendedPlace<short>*) LocalStateVariables[17];
  DISPATCHER.INT_ALU = (Place*) LocalStateVariables[7];
  DISPATCHER.BARRIER = (Place*) LocalStateVariables[14];
  Instantaneous_Activity2_case1.ROUTE_ALU_INT = (Place*) LocalStateVariables[12];
  Instantaneous_Activity2_case1.INSTRUCTION_READY = (Place*) LocalStateVariables[2];
  Instantaneous_Activity2_case1.RESULT_KO = (Place*) LocalStateVariables[4];
  Instantaneous_Activity2_case2.ROUTE_ALU_INT = (Place*) LocalStateVariables[12];
  Instantaneous_Activity2_case2.INSTRUCTION_READY = (Place*) LocalStateVariables[2];
  Instantaneous_Activity2_case2.RESULT_OK = (Place*) LocalStateVariables[5];
  handle_failure.INT_ALU = (Place*) LocalStateVariables[7];
  handle_failure.INT_ALU_FAILURE = (Place*) LocalStateVariables[11];
  handle_failure.RESULT_KO = (Place*) LocalStateVariables[4];
  handle_failure.INSTRUCTION_READY = (Place*) LocalStateVariables[2];
  handle_failure.ROUTE_ALU_INT = (Place*) LocalStateVariables[12];
  dhn.RESULT_KO = (Place*) LocalStateVariables[4];
  dhn.Place1 = (Place*) LocalStateVariables[13];
  Instantaneous_Activity3_case1.ROUTE_ALU_FLOAT = (Place*) LocalStateVariables[1];
  Instantaneous_Activity3_case1.INSTRUCTION_READY = (Place*) LocalStateVariables[2];
  Instantaneous_Activity3_case1.RESULT_KO = (Place*) LocalStateVariables[4];
  Instantaneous_Activity3_case2.ROUTE_ALU_FLOAT = (Place*) LocalStateVariables[1];
  Instantaneous_Activity3_case2.INSTRUCTION_READY = (Place*) LocalStateVariables[2];
  Instantaneous_Activity3_case2.RESULT_OK = (Place*) LocalStateVariables[5];
  BARRIER_SYNC.BARRIER = (Place*) LocalStateVariables[14];
  BARRIER_SYNC.INSTRUCTION_READY = (Place*) LocalStateVariables[2];
}
void EXEC_UNITSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================handle_failure_floatActivity========================*/


EXEC_UNITSAN::handle_failure_floatActivity::handle_failure_floatActivity(){
  ActivityInitialize("handle_failure_float",0,Instantaneous , RaceEnabled, 5,1, false);
}

void EXEC_UNITSAN::handle_failure_floatActivity::LinkVariables(){
  FLOAT_ALU->Register(&FLOAT_ALU_Mobius_Mark);
  FLOAT_ALU_FAILURE->Register(&FLOAT_ALU_FAILURE_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  ROUTE_ALU_FLOAT->Register(&ROUTE_ALU_FLOAT_Mobius_Mark);
}

bool EXEC_UNITSAN::handle_failure_floatActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(FLOAT_ALU_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNITSAN::handle_failure_floatActivity::Weight(){ 
  return 1;
}

bool EXEC_UNITSAN::handle_failure_floatActivity::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNITSAN::handle_failure_floatActivity::ReactivationFunction(){ 
  return false;
}

double EXEC_UNITSAN::handle_failure_floatActivity::SampleDistribution(){
  return 0;
}

double* EXEC_UNITSAN::handle_failure_floatActivity::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNITSAN::handle_failure_floatActivity::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNITSAN::handle_failure_floatActivity::Fire(){
  (*(FLOAT_ALU_Mobius_Mark))--;
  if (FLOAT_ALU_FAILURE->Mark() > 0) {

	RESULT_KO->Mark()++;
	FLOAT_ALU_FAILURE->Mark()--;
	INSTRUCTION_READY->Mark()++;

} else {

	ROUTE_ALU_FLOAT->Mark()++;

}
  return this;
}

/*======================DISPATCHERActivity========================*/


EXEC_UNITSAN::DISPATCHERActivity::DISPATCHERActivity(){
  ActivityInitialize("DISPATCHER",1,Instantaneous , RaceEnabled, 6,2, false);
}

void EXEC_UNITSAN::DISPATCHERActivity::LinkVariables(){

  REGISTERS_FILL->Register(&REGISTERS_FILL_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);


  INT_ALU->Register(&INT_ALU_Mobius_Mark);
  BARRIER->Register(&BARRIER_Mobius_Mark);
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
  INSTRUCTION_READY->Mark() = 0;
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
        INT_ALU->Mark()++;
    break;

    case 5:
        INT_ALU->Mark()++;
    break;

    case 6:
        INT_ALU->Mark()++;
    break;

    case 7:
        INT_ALU->Mark()++;
    break;

    case 8:
        BARRIER->Mark()++;
    break;

    default:
    break;
}
SCHEDULER->Mark() = -1;
  return this;
}

/*======================Instantaneous_Activity2Activity_case1========================*/


EXEC_UNITSAN::Instantaneous_Activity2Activity_case1::Instantaneous_Activity2Activity_case1(){
  ActivityInitialize("Instantaneous_Activity2_case1",2,Instantaneous , RaceEnabled, 3,1, false);
}

void EXEC_UNITSAN::Instantaneous_Activity2Activity_case1::LinkVariables(){
  ROUTE_ALU_INT->Register(&ROUTE_ALU_INT_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
}

bool EXEC_UNITSAN::Instantaneous_Activity2Activity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ROUTE_ALU_INT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNITSAN::Instantaneous_Activity2Activity_case1::Weight(){ 
  return 0;
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
  (*(ROUTE_ALU_INT_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  (*(RESULT_KO_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity2Activity_case2========================*/


EXEC_UNITSAN::Instantaneous_Activity2Activity_case2::Instantaneous_Activity2Activity_case2(){
  ActivityInitialize("Instantaneous_Activity2_case2",2,Instantaneous , RaceEnabled, 3,1, false);
}

void EXEC_UNITSAN::Instantaneous_Activity2Activity_case2::LinkVariables(){
  ROUTE_ALU_INT->Register(&ROUTE_ALU_INT_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
}

bool EXEC_UNITSAN::Instantaneous_Activity2Activity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ROUTE_ALU_INT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNITSAN::Instantaneous_Activity2Activity_case2::Weight(){ 
  return 1;
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
  (*(ROUTE_ALU_INT_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  (*(RESULT_OK_Mobius_Mark))++;
  return this;
}

/*======================handle_failureActivity========================*/


EXEC_UNITSAN::handle_failureActivity::handle_failureActivity(){
  ActivityInitialize("handle_failure",3,Instantaneous , RaceEnabled, 5,1, false);
}

void EXEC_UNITSAN::handle_failureActivity::LinkVariables(){
  INT_ALU->Register(&INT_ALU_Mobius_Mark);
  INT_ALU_FAILURE->Register(&INT_ALU_FAILURE_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  ROUTE_ALU_INT->Register(&ROUTE_ALU_INT_Mobius_Mark);
}

bool EXEC_UNITSAN::handle_failureActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(INT_ALU_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNITSAN::handle_failureActivity::Weight(){ 
  return 1;
}

bool EXEC_UNITSAN::handle_failureActivity::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNITSAN::handle_failureActivity::ReactivationFunction(){ 
  return false;
}

double EXEC_UNITSAN::handle_failureActivity::SampleDistribution(){
  return 0;
}

double* EXEC_UNITSAN::handle_failureActivity::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNITSAN::handle_failureActivity::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNITSAN::handle_failureActivity::Fire(){
  (*(INT_ALU_Mobius_Mark))--;
  if (INT_ALU_FAILURE->Mark() > 0) {

	RESULT_KO->Mark()++;
	INT_ALU_FAILURE->Mark()--;
	INSTRUCTION_READY->Mark()++;

} else {

	ROUTE_ALU_INT->Mark()++;

}
  return this;
}

/*======================dhnActivity========================*/


EXEC_UNITSAN::dhnActivity::dhnActivity(){
  ActivityInitialize("dhn",4,Instantaneous , RaceEnabled, 2,1, false);
}

void EXEC_UNITSAN::dhnActivity::LinkVariables(){
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
  Place1->Register(&Place1_Mobius_Mark);
}

bool EXEC_UNITSAN::dhnActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(RESULT_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNITSAN::dhnActivity::Weight(){ 
  return 1;
}

bool EXEC_UNITSAN::dhnActivity::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNITSAN::dhnActivity::ReactivationFunction(){ 
  return false;
}

double EXEC_UNITSAN::dhnActivity::SampleDistribution(){
  return 0;
}

double* EXEC_UNITSAN::dhnActivity::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNITSAN::dhnActivity::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNITSAN::dhnActivity::Fire(){
  (*(RESULT_KO_Mobius_Mark))--;
  (*(Place1_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity3Activity_case1========================*/


EXEC_UNITSAN::Instantaneous_Activity3Activity_case1::Instantaneous_Activity3Activity_case1(){
  ActivityInitialize("Instantaneous_Activity3_case1",5,Instantaneous , RaceEnabled, 3,1, false);
}

void EXEC_UNITSAN::Instantaneous_Activity3Activity_case1::LinkVariables(){
  ROUTE_ALU_FLOAT->Register(&ROUTE_ALU_FLOAT_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
}

bool EXEC_UNITSAN::Instantaneous_Activity3Activity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ROUTE_ALU_FLOAT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNITSAN::Instantaneous_Activity3Activity_case1::Weight(){ 
  return 0.5;
}

bool EXEC_UNITSAN::Instantaneous_Activity3Activity_case1::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNITSAN::Instantaneous_Activity3Activity_case1::ReactivationFunction(){ 
  return false;
}

double EXEC_UNITSAN::Instantaneous_Activity3Activity_case1::SampleDistribution(){
  return 0;
}

double* EXEC_UNITSAN::Instantaneous_Activity3Activity_case1::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNITSAN::Instantaneous_Activity3Activity_case1::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNITSAN::Instantaneous_Activity3Activity_case1::Fire(){
  (*(ROUTE_ALU_FLOAT_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  (*(RESULT_KO_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity3Activity_case2========================*/


EXEC_UNITSAN::Instantaneous_Activity3Activity_case2::Instantaneous_Activity3Activity_case2(){
  ActivityInitialize("Instantaneous_Activity3_case2",5,Instantaneous , RaceEnabled, 3,1, false);
}

void EXEC_UNITSAN::Instantaneous_Activity3Activity_case2::LinkVariables(){
  ROUTE_ALU_FLOAT->Register(&ROUTE_ALU_FLOAT_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
}

bool EXEC_UNITSAN::Instantaneous_Activity3Activity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ROUTE_ALU_FLOAT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNITSAN::Instantaneous_Activity3Activity_case2::Weight(){ 
  return 0.5;
}

bool EXEC_UNITSAN::Instantaneous_Activity3Activity_case2::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNITSAN::Instantaneous_Activity3Activity_case2::ReactivationFunction(){ 
  return false;
}

double EXEC_UNITSAN::Instantaneous_Activity3Activity_case2::SampleDistribution(){
  return 0;
}

double* EXEC_UNITSAN::Instantaneous_Activity3Activity_case2::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNITSAN::Instantaneous_Activity3Activity_case2::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNITSAN::Instantaneous_Activity3Activity_case2::Fire(){
  (*(ROUTE_ALU_FLOAT_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  (*(RESULT_OK_Mobius_Mark))++;
  return this;
}

/*======================BARRIER_SYNCActivity========================*/


EXEC_UNITSAN::BARRIER_SYNCActivity::BARRIER_SYNCActivity(){
  ActivityInitialize("BARRIER_SYNC",6,Instantaneous , RaceEnabled, 2,1, false);
}

void EXEC_UNITSAN::BARRIER_SYNCActivity::LinkVariables(){
  BARRIER->Register(&BARRIER_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool EXEC_UNITSAN::BARRIER_SYNCActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(BARRIER_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNITSAN::BARRIER_SYNCActivity::Weight(){ 
  return 1;
}

bool EXEC_UNITSAN::BARRIER_SYNCActivity::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNITSAN::BARRIER_SYNCActivity::ReactivationFunction(){ 
  return false;
}

double EXEC_UNITSAN::BARRIER_SYNCActivity::SampleDistribution(){
  return 0;
}

double* EXEC_UNITSAN::BARRIER_SYNCActivity::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNITSAN::BARRIER_SYNCActivity::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNITSAN::BARRIER_SYNCActivity::Fire(){
  (*(BARRIER_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

