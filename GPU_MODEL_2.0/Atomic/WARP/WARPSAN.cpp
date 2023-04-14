

// This C++ file was created by SanEditor

#include "Atomic/WARP/WARPSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         WARPSAN Constructor             
******************************************************************/


WARPSAN::WARPSAN(){


  Activity* InitialActionList[6]={
    &DISPATCHER_Copy, //0
    &Instantaneous_Activity1, //1
    &L1_CLOCK, //2
    &L2_CLOCK, //3
    &DRAM_CLOCK, //4
    &Instantaneous_Activity2  // 5
  };

  BaseGroupClass* InitialGroupList[6]={
    (BaseGroupClass*) &(DISPATCHER_Copy), 
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(L1_CLOCK), 
    (BaseGroupClass*) &(L2_CLOCK), 
    (BaseGroupClass*) &(DRAM_CLOCK), 
    (BaseGroupClass*) &(Instantaneous_Activity2)
  };

  INST_COUNTER = new Place("INST_COUNTER" ,-1);
  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  REGISTERS_FILL = new Place("REGISTERS_FILL" ,0);
  INT_ALU_FAILURE = new Place("INT_ALU_FAILURE" ,0);
  FLOAT_ALU_FAILURE = new Place("FLOAT_ALU_FAILURE" ,0);
  MEM_FAILURE = new Place("MEM_FAILURE" ,0);
  REG_FAILURE = new Place("REG_FAILURE" ,0);
  WARP_ACCESS_DRAM = new Place("WARP_ACCESS_DRAM" ,0);
  WARP_ACCESS_L2 = new Place("WARP_ACCESS_L2" ,0);
  WARP_ACCESS_L1 = new Place("WARP_ACCESS_L1" ,0);
  MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE" ,0);
  short temp_WARPinstructionsvalue = -1;
  WARP = new instructions("WARP",temp_WARPinstructionsvalue);
  short temp_SCHEDULERshort = -1;
  SCHEDULER = new ExtendedPlace<short>("SCHEDULER",temp_SCHEDULERshort);
  short temp_FAILURE_INSTshort = failure_index;
  FAILURE_INST = new ExtendedPlace<short>("FAILURE_INST",temp_FAILURE_INSTshort);
  BaseStateVariableClass* InitialPlaces[14]={
    INST_COUNTER,  // 0
    INSTRUCTION_READY,  // 1
    REGISTERS_FILL,  // 2
    INT_ALU_FAILURE,  // 3
    FLOAT_ALU_FAILURE,  // 4
    MEM_FAILURE,  // 5
    REG_FAILURE,  // 6
    WARP_ACCESS_DRAM,  // 7
    WARP_ACCESS_L2,  // 8
    WARP_ACCESS_L1,  // 9
    MEM_OP_COMPLETE,  // 10
    WARP,  // 11
    SCHEDULER,  // 12
    FAILURE_INST   // 13
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("WARP", 14, InitialPlaces, 
                        0, InitialROPlaces, 
                        6, InitialActionList, 6, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[19][2]={ 
    {1,0}, {0,0}, {12,0}, {2,0}, {11,0}, {3,1}, {4,1}, {5,1}, 
    {6,1}, {1,1}, {0,1}, {12,1}, {2,1}, {11,1}, {9,2}, {8,3}, 
    {7,4}, {10,5}, {1,5}
  };
  for(int n=0;n<19;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[11][2]={ 
    {0,0}, {1,0}, {12,0}, {13,0}, {13,1}, {0,1}, {1,1}, {9,2}, 
    {8,3}, {7,4}, {10,5}
  };
  for(int n=0;n<11;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<6;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void WARPSAN::CustomInitialization() {
WARP->Index(0)->Mark() = 5;WARP->Index(1)->Mark() = 5;WARP->Index(2)->Mark() = 5;WARP->Index(3)->Mark() = 5;WARP->Index(4)->Mark() = 5;
}
WARPSAN::~WARPSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void WARPSAN::assignPlacesToActivitiesInst(){
  DISPATCHER_Copy.INST_COUNTER = (Place*) LocalStateVariables[0];
  DISPATCHER_Copy.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
  DISPATCHER_Copy.SCHEDULER = (ExtendedPlace<short>*) LocalStateVariables[12];
  DISPATCHER_Copy.FAILURE_INST = (ExtendedPlace<short>*) LocalStateVariables[13];
  DISPATCHER_Copy.REGISTERS_FILL = (Place*) LocalStateVariables[2];
  DISPATCHER_Copy.WARP = (instructions*) LocalStateVariables[11];
  Instantaneous_Activity1.FAILURE_INST = (ExtendedPlace<short>*) LocalStateVariables[13];
  Instantaneous_Activity1.INST_COUNTER = (Place*) LocalStateVariables[0];
  Instantaneous_Activity1.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
  Instantaneous_Activity1.INT_ALU_FAILURE = (Place*) LocalStateVariables[3];
  Instantaneous_Activity1.FLOAT_ALU_FAILURE = (Place*) LocalStateVariables[4];
  Instantaneous_Activity1.MEM_FAILURE = (Place*) LocalStateVariables[5];
  Instantaneous_Activity1.REG_FAILURE = (Place*) LocalStateVariables[6];
  Instantaneous_Activity1.SCHEDULER = (ExtendedPlace<short>*) LocalStateVariables[12];
  Instantaneous_Activity1.REGISTERS_FILL = (Place*) LocalStateVariables[2];
  Instantaneous_Activity1.WARP = (instructions*) LocalStateVariables[11];
  L1_CLOCK.WARP_ACCESS_L1 = (Place*) LocalStateVariables[9];
  L2_CLOCK.WARP_ACCESS_L2 = (Place*) LocalStateVariables[8];
  DRAM_CLOCK.WARP_ACCESS_DRAM = (Place*) LocalStateVariables[7];
  Instantaneous_Activity2.MEM_OP_COMPLETE = (Place*) LocalStateVariables[10];
  Instantaneous_Activity2.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
}
void WARPSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================DISPATCHER_CopyActivity========================*/


WARPSAN::DISPATCHER_CopyActivity::DISPATCHER_CopyActivity(){
  ActivityInitialize("DISPATCHER_Copy",0,Instantaneous , RaceEnabled, 5,4, false);
}

void WARPSAN::DISPATCHER_CopyActivity::LinkVariables(){
  INST_COUNTER->Register(&INST_COUNTER_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);


  REGISTERS_FILL->Register(&REGISTERS_FILL_Mobius_Mark);

}

bool WARPSAN::DISPATCHER_CopyActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((INST_COUNTER->Mark() < size-1) && (INSTRUCTION_READY->Mark() > 0) && (SCHEDULER->Mark() == -1) && (FAILURE_INST->Mark() != INST_COUNTER->Mark())));
  return NewEnabled;
}

double WARPSAN::DISPATCHER_CopyActivity::Weight(){ 
  return 1;
}

bool WARPSAN::DISPATCHER_CopyActivity::ReactivationPredicate(){ 
  return false;
}

bool WARPSAN::DISPATCHER_CopyActivity::ReactivationFunction(){ 
  return false;
}

double WARPSAN::DISPATCHER_CopyActivity::SampleDistribution(){
  return 0;
}

double* WARPSAN::DISPATCHER_CopyActivity::ReturnDistributionParameters(){
    return NULL;
}

int WARPSAN::DISPATCHER_CopyActivity::Rank(){
  return 1;
}

BaseActionClass* WARPSAN::DISPATCHER_CopyActivity::Fire(){
  INSTRUCTION_READY->Mark() = 0;
INST_COUNTER->Mark()++;
  SCHEDULER->Mark() = WARP->Index(INST_COUNTER->Mark())->Mark();
REGISTERS_FILL->Mark() = 1;
  return this;
}

/*======================Instantaneous_Activity1Activity========================*/


WARPSAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",1,Instantaneous , RaceEnabled, 9,3, false);
}

void WARPSAN::Instantaneous_Activity1Activity::LinkVariables(){

  INST_COUNTER->Register(&INST_COUNTER_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  INT_ALU_FAILURE->Register(&INT_ALU_FAILURE_Mobius_Mark);
  FLOAT_ALU_FAILURE->Register(&FLOAT_ALU_FAILURE_Mobius_Mark);
  MEM_FAILURE->Register(&MEM_FAILURE_Mobius_Mark);
  REG_FAILURE->Register(&REG_FAILURE_Mobius_Mark);

  REGISTERS_FILL->Register(&REGISTERS_FILL_Mobius_Mark);

}

bool WARPSAN::Instantaneous_Activity1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((FAILURE_INST->Mark() == INST_COUNTER->Mark()) && (INSTRUCTION_READY->Mark() == 1)));
  return NewEnabled;
}

double WARPSAN::Instantaneous_Activity1Activity::Weight(){ 
  return 1;
}

bool WARPSAN::Instantaneous_Activity1Activity::ReactivationPredicate(){ 
  return false;
}

bool WARPSAN::Instantaneous_Activity1Activity::ReactivationFunction(){ 
  return false;
}

double WARPSAN::Instantaneous_Activity1Activity::SampleDistribution(){
  return 0;
}

double* WARPSAN::Instantaneous_Activity1Activity::ReturnDistributionParameters(){
    return NULL;
}

int WARPSAN::Instantaneous_Activity1Activity::Rank(){
  return 1;
}

BaseActionClass* WARPSAN::Instantaneous_Activity1Activity::Fire(){
  INSTRUCTION_READY->Mark()--;
INST_COUNTER->Mark()++;
  SCHEDULER->Mark() = WARP->Index(INST_COUNTER->Mark())->Mark();
REGISTERS_FILL->Mark() = 1;
  (*(INT_ALU_FAILURE_Mobius_Mark))++;
  (*(FLOAT_ALU_FAILURE_Mobius_Mark))++;
  (*(MEM_FAILURE_Mobius_Mark))++;
  (*(REG_FAILURE_Mobius_Mark))++;
  return this;
}

/*======================L1_CLOCKActivity========================*/


WARPSAN::L1_CLOCKActivity::L1_CLOCKActivity(){
  ActivityInitialize("L1_CLOCK",2,Instantaneous , RaceEnabled, 1,1, false);
}

void WARPSAN::L1_CLOCKActivity::LinkVariables(){
  WARP_ACCESS_L1->Register(&WARP_ACCESS_L1_Mobius_Mark);
}

bool WARPSAN::L1_CLOCKActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WARP_ACCESS_L1_Mobius_Mark)) >=1));
  return NewEnabled;
}

double WARPSAN::L1_CLOCKActivity::Weight(){ 
  return 1;
}

bool WARPSAN::L1_CLOCKActivity::ReactivationPredicate(){ 
  return false;
}

bool WARPSAN::L1_CLOCKActivity::ReactivationFunction(){ 
  return false;
}

double WARPSAN::L1_CLOCKActivity::SampleDistribution(){
  return 0;
}

double* WARPSAN::L1_CLOCKActivity::ReturnDistributionParameters(){
    return NULL;
}

int WARPSAN::L1_CLOCKActivity::Rank(){
  return 1;
}

BaseActionClass* WARPSAN::L1_CLOCKActivity::Fire(){
  (*(WARP_ACCESS_L1_Mobius_Mark))--;
  return this;
}

/*======================L2_CLOCKActivity========================*/


WARPSAN::L2_CLOCKActivity::L2_CLOCKActivity(){
  ActivityInitialize("L2_CLOCK",3,Instantaneous , RaceEnabled, 1,1, false);
}

void WARPSAN::L2_CLOCKActivity::LinkVariables(){
  WARP_ACCESS_L2->Register(&WARP_ACCESS_L2_Mobius_Mark);
}

bool WARPSAN::L2_CLOCKActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WARP_ACCESS_L2_Mobius_Mark)) >=1));
  return NewEnabled;
}

double WARPSAN::L2_CLOCKActivity::Weight(){ 
  return 1;
}

bool WARPSAN::L2_CLOCKActivity::ReactivationPredicate(){ 
  return false;
}

bool WARPSAN::L2_CLOCKActivity::ReactivationFunction(){ 
  return false;
}

double WARPSAN::L2_CLOCKActivity::SampleDistribution(){
  return 0;
}

double* WARPSAN::L2_CLOCKActivity::ReturnDistributionParameters(){
    return NULL;
}

int WARPSAN::L2_CLOCKActivity::Rank(){
  return 1;
}

BaseActionClass* WARPSAN::L2_CLOCKActivity::Fire(){
  (*(WARP_ACCESS_L2_Mobius_Mark))--;
  return this;
}

/*======================DRAM_CLOCKActivity========================*/


WARPSAN::DRAM_CLOCKActivity::DRAM_CLOCKActivity(){
  ActivityInitialize("DRAM_CLOCK",4,Instantaneous , RaceEnabled, 1,1, false);
}

void WARPSAN::DRAM_CLOCKActivity::LinkVariables(){
  WARP_ACCESS_DRAM->Register(&WARP_ACCESS_DRAM_Mobius_Mark);
}

bool WARPSAN::DRAM_CLOCKActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WARP_ACCESS_DRAM_Mobius_Mark)) >=1));
  return NewEnabled;
}

double WARPSAN::DRAM_CLOCKActivity::Weight(){ 
  return 1;
}

bool WARPSAN::DRAM_CLOCKActivity::ReactivationPredicate(){ 
  return false;
}

bool WARPSAN::DRAM_CLOCKActivity::ReactivationFunction(){ 
  return false;
}

double WARPSAN::DRAM_CLOCKActivity::SampleDistribution(){
  return 0;
}

double* WARPSAN::DRAM_CLOCKActivity::ReturnDistributionParameters(){
    return NULL;
}

int WARPSAN::DRAM_CLOCKActivity::Rank(){
  return 1;
}

BaseActionClass* WARPSAN::DRAM_CLOCKActivity::Fire(){
  (*(WARP_ACCESS_DRAM_Mobius_Mark))--;
  return this;
}

/*======================Instantaneous_Activity2Activity========================*/


WARPSAN::Instantaneous_Activity2Activity::Instantaneous_Activity2Activity(){
  ActivityInitialize("Instantaneous_Activity2",5,Instantaneous , RaceEnabled, 2,1, false);
}

void WARPSAN::Instantaneous_Activity2Activity::LinkVariables(){
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool WARPSAN::Instantaneous_Activity2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEM_OP_COMPLETE_Mobius_Mark)) >=1));
  return NewEnabled;
}

double WARPSAN::Instantaneous_Activity2Activity::Weight(){ 
  return 1;
}

bool WARPSAN::Instantaneous_Activity2Activity::ReactivationPredicate(){ 
  return false;
}

bool WARPSAN::Instantaneous_Activity2Activity::ReactivationFunction(){ 
  return false;
}

double WARPSAN::Instantaneous_Activity2Activity::SampleDistribution(){
  return 0;
}

double* WARPSAN::Instantaneous_Activity2Activity::ReturnDistributionParameters(){
    return NULL;
}

int WARPSAN::Instantaneous_Activity2Activity::Rank(){
  return 1;
}

BaseActionClass* WARPSAN::Instantaneous_Activity2Activity::Fire(){
  (*(MEM_OP_COMPLETE_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

