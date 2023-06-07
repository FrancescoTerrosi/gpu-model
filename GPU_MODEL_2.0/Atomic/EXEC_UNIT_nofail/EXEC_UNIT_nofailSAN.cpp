

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
    &Instantaneous_Activity1, //2
    &Instantaneous_Activity2  // 3
  };

  BaseGroupClass* InitialGroupList[4]={
    (BaseGroupClass*) &(DISPATCHER), 
    (BaseGroupClass*) &(BARRIER_SYNC), 
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(Instantaneous_Activity2)
  };

  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  FLOAT_ALU = new Place("FLOAT_ALU" ,0);
  MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE" ,0);
  INT_ALU = new Place("INT_ALU" ,0);
  REGISTERS_FILL = new Place("REGISTERS_FILL" ,0);
  BARRIER = new Place("BARRIER" ,0);
  short temp_SCHEDULERshort = -1;
  SCHEDULER = new ExtendedPlace<short>("SCHEDULER",temp_SCHEDULERshort);
  short temp_READshort = -1;
  READ = new ExtendedPlace<short>("READ",temp_READshort);
  short temp_WRITEshort = -1;
  WRITE = new ExtendedPlace<short>("WRITE",temp_WRITEshort);
  BaseStateVariableClass* InitialPlaces[9]={
    INSTRUCTION_READY,  // 0
    FLOAT_ALU,  // 1
    MEM_OP_COMPLETE,  // 2
    INT_ALU,  // 3
    REGISTERS_FILL,  // 4
    BARRIER,  // 5
    SCHEDULER,  // 6
    READ,  // 7
    WRITE   // 8
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("EXEC_UNIT_nofail", 9, InitialPlaces, 
                        0, InitialROPlaces, 
                        4, InitialActionList, 4, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[12][2]={ 
    {0,0}, {6,0}, {7,0}, {8,0}, {3,0}, {5,0}, {5,1}, {0,1}, {1,2}, 
    {0,2}, {3,3}, {0,3}
  };
  for(int n=0;n<12;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[5][2]={ 
    {6,0}, {4,0}, {5,1}, {1,2}, {3,3}
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
  DISPATCHER.SCHEDULER = (ExtendedPlace<short>*) LocalStateVariables[6];
  DISPATCHER.REGISTERS_FILL = (Place*) LocalStateVariables[4];
  DISPATCHER.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  DISPATCHER.READ = (ExtendedPlace<short>*) LocalStateVariables[7];
  DISPATCHER.WRITE = (ExtendedPlace<short>*) LocalStateVariables[8];
  DISPATCHER.INT_ALU = (Place*) LocalStateVariables[3];
  DISPATCHER.BARRIER = (Place*) LocalStateVariables[5];
  BARRIER_SYNC.BARRIER = (Place*) LocalStateVariables[5];
  BARRIER_SYNC.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  Instantaneous_Activity1.FLOAT_ALU = (Place*) LocalStateVariables[1];
  Instantaneous_Activity1.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  Instantaneous_Activity2.INT_ALU = (Place*) LocalStateVariables[3];
  Instantaneous_Activity2.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
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

/*======================Instantaneous_Activity1Activity========================*/


EXEC_UNIT_nofailSAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",2,Instantaneous , RaceEnabled, 2,1, false);
}

void EXEC_UNIT_nofailSAN::Instantaneous_Activity1Activity::LinkVariables(){
  FLOAT_ALU->Register(&FLOAT_ALU_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool EXEC_UNIT_nofailSAN::Instantaneous_Activity1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(FLOAT_ALU_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNIT_nofailSAN::Instantaneous_Activity1Activity::Weight(){ 
  return 1;
}

bool EXEC_UNIT_nofailSAN::Instantaneous_Activity1Activity::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNIT_nofailSAN::Instantaneous_Activity1Activity::ReactivationFunction(){ 
  return false;
}

double EXEC_UNIT_nofailSAN::Instantaneous_Activity1Activity::SampleDistribution(){
  return 0;
}

double* EXEC_UNIT_nofailSAN::Instantaneous_Activity1Activity::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNIT_nofailSAN::Instantaneous_Activity1Activity::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNIT_nofailSAN::Instantaneous_Activity1Activity::Fire(){
  (*(FLOAT_ALU_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity2Activity========================*/


EXEC_UNIT_nofailSAN::Instantaneous_Activity2Activity::Instantaneous_Activity2Activity(){
  ActivityInitialize("Instantaneous_Activity2",3,Instantaneous , RaceEnabled, 2,1, false);
}

void EXEC_UNIT_nofailSAN::Instantaneous_Activity2Activity::LinkVariables(){
  INT_ALU->Register(&INT_ALU_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool EXEC_UNIT_nofailSAN::Instantaneous_Activity2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(INT_ALU_Mobius_Mark)) >=1));
  return NewEnabled;
}

double EXEC_UNIT_nofailSAN::Instantaneous_Activity2Activity::Weight(){ 
  return 1;
}

bool EXEC_UNIT_nofailSAN::Instantaneous_Activity2Activity::ReactivationPredicate(){ 
  return false;
}

bool EXEC_UNIT_nofailSAN::Instantaneous_Activity2Activity::ReactivationFunction(){ 
  return false;
}

double EXEC_UNIT_nofailSAN::Instantaneous_Activity2Activity::SampleDistribution(){
  return 0;
}

double* EXEC_UNIT_nofailSAN::Instantaneous_Activity2Activity::ReturnDistributionParameters(){
    return NULL;
}

int EXEC_UNIT_nofailSAN::Instantaneous_Activity2Activity::Rank(){
  return 1;
}

BaseActionClass* EXEC_UNIT_nofailSAN::Instantaneous_Activity2Activity::Fire(){
  (*(INT_ALU_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

