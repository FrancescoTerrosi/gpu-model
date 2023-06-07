

// This C++ file was created by SanEditor

#include "Atomic/EXEC_UNIT_nofail/EXEC_UNIT_nofailSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         EXEC_UNIT_nofailSAN Constructor             
******************************************************************/


EXEC_UNIT_nofailSAN::EXEC_UNIT_nofailSAN(){


  Activity* InitialActionList[4]={
    &DISPATCHER, //0
    &BARRIER_SYNC, //1
    &FLOAT_OP, //2
    &INT_OP  // 3
  };

  BaseGroupClass* InitialGroupList[4]={
    (BaseGroupClass*) &(DISPATCHER), 
    (BaseGroupClass*) &(BARRIER_SYNC), 
    (BaseGroupClass*) &(FLOAT_OP), 
    (BaseGroupClass*) &(INT_OP)
  };

  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  FLOAT_ALU = new Place("FLOAT_ALU" ,0);
  INT_ALU = new Place("INT_ALU" ,0);
  REGISTERS_FILL = new Place("REGISTERS_FILL" ,0);
  BARRIER = new Place("BARRIER" ,0);
  short temp_SCHEDULERshort = -1;
  SCHEDULER = new ExtendedPlace<short>("SCHEDULER",temp_SCHEDULERshort);
  short temp_READshort = -1;
  READ = new ExtendedPlace<short>("READ",temp_READshort);
  short temp_WRITEshort = -1;
  WRITE = new ExtendedPlace<short>("WRITE",temp_WRITEshort);
  BaseStateVariableClass* InitialPlaces[8]={
    INSTRUCTION_READY,  // 0
    FLOAT_ALU,  // 1
    INT_ALU,  // 2
    REGISTERS_FILL,  // 3
    BARRIER,  // 4
    SCHEDULER,  // 5
    READ,  // 6
    WRITE   // 7
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("EXEC_UNIT_nofail", 8, InitialPlaces, 
                        0, InitialROPlaces, 
                        4, InitialActionList, 4, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[12][2]={ 
    {0,0}, {5,0}, {6,0}, {7,0}, {2,0}, {4,0}, {4,1}, {0,1}, {1,2}, 
    {0,2}, {2,3}, {0,3}
  };
  for(int n=0;n<12;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[5][2]={ 
    {5,0}, {3,0}, {4,1}, {1,2}, {2,3}
  };
  for(int n=0;n<5;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<4;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void EXEC_UNIT_nofailSAN::CustomInitialization() {

}
EXEC_UNIT_nofailSAN::~EXEC_UNIT_nofailSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void EXEC_UNIT_nofailSAN::assignPlacesToActivitiesInst(){
  DISPATCHER.SCHEDULER = (ExtendedPlace<short>*) LocalStateVariables[5];
  DISPATCHER.REGISTERS_FILL = (Place*) LocalStateVariables[3];
  DISPATCHER.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  DISPATCHER.READ = (ExtendedPlace<short>*) LocalStateVariables[6];
  DISPATCHER.WRITE = (ExtendedPlace<short>*) LocalStateVariables[7];
  DISPATCHER.INT_ALU = (Place*) LocalStateVariables[2];
  DISPATCHER.BARRIER = (Place*) LocalStateVariables[4];
  BARRIER_SYNC.BARRIER = (Place*) LocalStateVariables[4];
  BARRIER_SYNC.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  FLOAT_OP.FLOAT_ALU = (Place*) LocalStateVariables[1];
  FLOAT_OP.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  INT_OP.INT_ALU = (Place*) LocalStateVariables[2];
  INT_OP.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
}
void EXEC_UNIT_nofailSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================DISPATCHERActivity========================*/


EXEC_UNIT_nofailSAN::DISPATCHERActivity::DISPATCHERActivity(){
  ActivityInitialize("DISPATCHER",0,Instantaneous , RaceEnabled, 6,2, false);
}

void EXEC_UNIT_nofailSAN::DISPATCHERActivity::LinkVariables(){

  REGISTERS_FILL->Register(&REGISTERS_FILL_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);


  INT_ALU->Register(&INT_ALU_Mobius_Mark);
  BARRIER->Register(&BARRIER_Mobius_Mark);
}

bool EXEC_UNIT_nofailSAN::DISPATCHERActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((SCHEDULER->Mark() > -1 && REGISTERS_FILL->Mark() == 0));
  return NewEnabled;
}

double EXEC_UNIT_nofailSAN::DISPATCHERActivity::Weight(){ 
  return 1;
}

bool EXEC_UNIT_nofailSAN::DISPATCHERActivity::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNIT_nofailSAN::DISPATCHERActivity::ReactivationFunction(){ 
  return false;
}

double EXEC_UNIT_nofailSAN::DISPATCHERActivity::SampleDistribution(){
  return 0;
}

double* EXEC_UNIT_nofailSAN::DISPATCHERActivity::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNIT_nofailSAN::DISPATCHERActivity::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNIT_nofailSAN::DISPATCHERActivity::Fire(){
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

/*======================BARRIER_SYNCActivity========================*/


EXEC_UNIT_nofailSAN::BARRIER_SYNCActivity::BARRIER_SYNCActivity(){
  ActivityInitialize("BARRIER_SYNC",1,Instantaneous , RaceEnabled, 2,1, false);
}

void EXEC_UNIT_nofailSAN::BARRIER_SYNCActivity::LinkVariables(){
  BARRIER->Register(&BARRIER_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool EXEC_UNIT_nofailSAN::BARRIER_SYNCActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(BARRIER_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNIT_nofailSAN::BARRIER_SYNCActivity::Weight(){ 
  return 1;
}

bool EXEC_UNIT_nofailSAN::BARRIER_SYNCActivity::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNIT_nofailSAN::BARRIER_SYNCActivity::ReactivationFunction(){ 
  return false;
}

double EXEC_UNIT_nofailSAN::BARRIER_SYNCActivity::SampleDistribution(){
  return 0;
}

double* EXEC_UNIT_nofailSAN::BARRIER_SYNCActivity::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNIT_nofailSAN::BARRIER_SYNCActivity::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNIT_nofailSAN::BARRIER_SYNCActivity::Fire(){
  (*(BARRIER_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

/*======================FLOAT_OPActivity========================*/


EXEC_UNIT_nofailSAN::FLOAT_OPActivity::FLOAT_OPActivity(){
  ActivityInitialize("FLOAT_OP",2,Instantaneous , RaceEnabled, 2,1, false);
}

void EXEC_UNIT_nofailSAN::FLOAT_OPActivity::LinkVariables(){
  FLOAT_ALU->Register(&FLOAT_ALU_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool EXEC_UNIT_nofailSAN::FLOAT_OPActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(FLOAT_ALU_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNIT_nofailSAN::FLOAT_OPActivity::Weight(){ 
  return 1;
}

bool EXEC_UNIT_nofailSAN::FLOAT_OPActivity::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNIT_nofailSAN::FLOAT_OPActivity::ReactivationFunction(){ 
  return false;
}

double EXEC_UNIT_nofailSAN::FLOAT_OPActivity::SampleDistribution(){
  return 0;
}

double* EXEC_UNIT_nofailSAN::FLOAT_OPActivity::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNIT_nofailSAN::FLOAT_OPActivity::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNIT_nofailSAN::FLOAT_OPActivity::Fire(){
  (*(FLOAT_ALU_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

/*======================INT_OPActivity========================*/


EXEC_UNIT_nofailSAN::INT_OPActivity::INT_OPActivity(){
  ActivityInitialize("INT_OP",3,Instantaneous , RaceEnabled, 2,1, false);
}

void EXEC_UNIT_nofailSAN::INT_OPActivity::LinkVariables(){
  INT_ALU->Register(&INT_ALU_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool EXEC_UNIT_nofailSAN::INT_OPActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(INT_ALU_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNIT_nofailSAN::INT_OPActivity::Weight(){ 
  return 1;
}

bool EXEC_UNIT_nofailSAN::INT_OPActivity::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNIT_nofailSAN::INT_OPActivity::ReactivationFunction(){ 
  return false;
}

double EXEC_UNIT_nofailSAN::INT_OPActivity::SampleDistribution(){
  return 0;
}

double* EXEC_UNIT_nofailSAN::INT_OPActivity::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNIT_nofailSAN::INT_OPActivity::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNIT_nofailSAN::INT_OPActivity::Fire(){
  (*(INT_ALU_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

