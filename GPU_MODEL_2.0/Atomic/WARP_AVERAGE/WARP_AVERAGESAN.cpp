

// This C++ file was created by SanEditor

#include "Atomic/WARP_AVERAGE/WARP_AVERAGESAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         WARP_AVERAGESAN Constructor             
******************************************************************/


WARP_AVERAGESAN::WARP_AVERAGESAN(){


  Activity* InitialActionList[5]={
    &DISPATCHER_Copy_Copy, //0
    &Instantaneous_Activity1, //1
    &Instantaneous_Activity2, //2
    &Instantaneous_Activity3, //3
    &Instantaneous_Activity4  // 4
  };

  BaseGroupClass* InitialGroupList[5]={
    (BaseGroupClass*) &(DISPATCHER_Copy_Copy), 
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(Instantaneous_Activity2), 
    (BaseGroupClass*) &(Instantaneous_Activity3), 
    (BaseGroupClass*) &(Instantaneous_Activity4)
  };

  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  INST_COUNTER = new Place("INST_COUNTER" ,-1);
  ALU = new Place("ALU" ,alu_ops);
  L_MEM = new Place("L_MEM" ,l_mem_ops);
  G_MEM = new Place("G_MEM" ,g_mem_ops);
  short temp_SCHEDULERshort = -1;
  SCHEDULER = new ExtendedPlace<short>("SCHEDULER",temp_SCHEDULERshort);
  short temp_WARPshort = -1;
  WARP = new ExtendedPlace<short>("WARP",temp_WARPshort);
  short temp_INST_SELshort = -1;
  INST_SEL = new ExtendedPlace<short>("INST_SEL",temp_INST_SELshort);
  BaseStateVariableClass* InitialPlaces[8]={
    INSTRUCTION_READY,  // 0
    INST_COUNTER,  // 1
    ALU,  // 2
    L_MEM,  // 3
    G_MEM,  // 4
    SCHEDULER,  // 5
    WARP,  // 6
    INST_SEL   // 7
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("WARP_AVERAGE", 8, InitialPlaces, 
                        0, InitialROPlaces, 
                        5, InitialActionList, 5, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[12][2]={ 
    {0,0}, {1,0}, {5,0}, {6,0}, {2,1}, {7,1}, {3,2}, {7,2}, {4,3}, 
    {7,3}, {6,4}, {7,4}
  };
  for(int n=0;n<12;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[14][2]={ 
    {1,0}, {6,0}, {7,1}, {2,1}, {6,1}, {7,2}, {3,2}, {6,2}, {7,3}, 
    {4,3}, {6,3}, {7,4}, {6,4}, {0,4}
  };
  for(int n=0;n<14;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<5;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void WARP_AVERAGESAN::CustomInitialization() {

}
WARP_AVERAGESAN::~WARP_AVERAGESAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void WARP_AVERAGESAN::assignPlacesToActivitiesInst(){
  DISPATCHER_Copy_Copy.INST_COUNTER = (Place*) LocalStateVariables[1];
  DISPATCHER_Copy_Copy.WARP = (ExtendedPlace<short>*) LocalStateVariables[6];
  DISPATCHER_Copy_Copy.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  DISPATCHER_Copy_Copy.SCHEDULER = (ExtendedPlace<short>*) LocalStateVariables[5];
  Instantaneous_Activity1.INST_SEL = (ExtendedPlace<short>*) LocalStateVariables[7];
  Instantaneous_Activity1.ALU = (Place*) LocalStateVariables[2];
  Instantaneous_Activity1.WARP = (ExtendedPlace<short>*) LocalStateVariables[6];
  Instantaneous_Activity2.INST_SEL = (ExtendedPlace<short>*) LocalStateVariables[7];
  Instantaneous_Activity2.L_MEM = (Place*) LocalStateVariables[3];
  Instantaneous_Activity2.WARP = (ExtendedPlace<short>*) LocalStateVariables[6];
  Instantaneous_Activity3.INST_SEL = (ExtendedPlace<short>*) LocalStateVariables[7];
  Instantaneous_Activity3.G_MEM = (Place*) LocalStateVariables[4];
  Instantaneous_Activity3.WARP = (ExtendedPlace<short>*) LocalStateVariables[6];
  Instantaneous_Activity4.INST_SEL = (ExtendedPlace<short>*) LocalStateVariables[7];
  Instantaneous_Activity4.WARP = (ExtendedPlace<short>*) LocalStateVariables[6];
  Instantaneous_Activity4.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
}
void WARP_AVERAGESAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================DISPATCHER_Copy_CopyActivity========================*/


WARP_AVERAGESAN::DISPATCHER_Copy_CopyActivity::DISPATCHER_Copy_CopyActivity(){
  ActivityInitialize("DISPATCHER_Copy_Copy",0,Instantaneous , RaceEnabled, 4,2, false);
}

void WARP_AVERAGESAN::DISPATCHER_Copy_CopyActivity::LinkVariables(){
  INST_COUNTER->Register(&INST_COUNTER_Mobius_Mark);

  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);

}

bool WARP_AVERAGESAN::DISPATCHER_Copy_CopyActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((INST_COUNTER->Mark() < size) && (WARP->Mark() != -1)));
  return NewEnabled;
}

double WARP_AVERAGESAN::DISPATCHER_Copy_CopyActivity::Weight(){ 
  return 1;
}

bool WARP_AVERAGESAN::DISPATCHER_Copy_CopyActivity::ReactivationPredicate(){ 
  return false;
}

bool WARP_AVERAGESAN::DISPATCHER_Copy_CopyActivity::ReactivationFunction(){ 
  return false;
}

double WARP_AVERAGESAN::DISPATCHER_Copy_CopyActivity::SampleDistribution(){
  return 0;
}

double* WARP_AVERAGESAN::DISPATCHER_Copy_CopyActivity::ReturnDistributionParameters(){
    return NULL;
}

int WARP_AVERAGESAN::DISPATCHER_Copy_CopyActivity::Rank(){
  return 1;
}

BaseActionClass* WARP_AVERAGESAN::DISPATCHER_Copy_CopyActivity::Fire(){
  INSTRUCTION_READY->Mark()--;
INST_COUNTER->Mark()++;
SCHEDULER->Mark() = WARP->Mark();
  WARP->Mark() = -1;
  return this;
}

/*======================Instantaneous_Activity1Activity========================*/


WARP_AVERAGESAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",1,Instantaneous , RaceEnabled, 2,3, false);
}

void WARP_AVERAGESAN::Instantaneous_Activity1Activity::LinkVariables(){

  ALU->Register(&ALU_Mobius_Mark);

}

bool WARP_AVERAGESAN::Instantaneous_Activity1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((INST_SEL->Mark() == -1 && ALU->Mark() > 0 && WARP->Mark() == -1));
  return NewEnabled;
}

double WARP_AVERAGESAN::Instantaneous_Activity1Activity::Weight(){ 
  return 1;
}

bool WARP_AVERAGESAN::Instantaneous_Activity1Activity::ReactivationPredicate(){ 
  return false;
}

bool WARP_AVERAGESAN::Instantaneous_Activity1Activity::ReactivationFunction(){ 
  return false;
}

double WARP_AVERAGESAN::Instantaneous_Activity1Activity::SampleDistribution(){
  return 0;
}

double* WARP_AVERAGESAN::Instantaneous_Activity1Activity::ReturnDistributionParameters(){
    return NULL;
}

int WARP_AVERAGESAN::Instantaneous_Activity1Activity::Rank(){
  return 1;
}

BaseActionClass* WARP_AVERAGESAN::Instantaneous_Activity1Activity::Fire(){
  ALU->Mark()--;
  INST_SEL->Mark() = 7;
  return this;
}

/*======================Instantaneous_Activity2Activity========================*/


WARP_AVERAGESAN::Instantaneous_Activity2Activity::Instantaneous_Activity2Activity(){
  ActivityInitialize("Instantaneous_Activity2",2,Instantaneous , RaceEnabled, 2,3, false);
}

void WARP_AVERAGESAN::Instantaneous_Activity2Activity::LinkVariables(){

  L_MEM->Register(&L_MEM_Mobius_Mark);

}

bool WARP_AVERAGESAN::Instantaneous_Activity2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((INST_SEL->Mark() == -1 && L_MEM->Mark() > 0 && WARP->Mark() == -1));
  return NewEnabled;
}

double WARP_AVERAGESAN::Instantaneous_Activity2Activity::Weight(){ 
  return 1;
}

bool WARP_AVERAGESAN::Instantaneous_Activity2Activity::ReactivationPredicate(){ 
  return false;
}

bool WARP_AVERAGESAN::Instantaneous_Activity2Activity::ReactivationFunction(){ 
  return false;
}

double WARP_AVERAGESAN::Instantaneous_Activity2Activity::SampleDistribution(){
  return 0;
}

double* WARP_AVERAGESAN::Instantaneous_Activity2Activity::ReturnDistributionParameters(){
    return NULL;
}

int WARP_AVERAGESAN::Instantaneous_Activity2Activity::Rank(){
  return 1;
}

BaseActionClass* WARP_AVERAGESAN::Instantaneous_Activity2Activity::Fire(){
  L_MEM->Mark()--;
  INST_SEL->Mark() = 3;
  return this;
}

/*======================Instantaneous_Activity3Activity========================*/


WARP_AVERAGESAN::Instantaneous_Activity3Activity::Instantaneous_Activity3Activity(){
  ActivityInitialize("Instantaneous_Activity3",3,Instantaneous , RaceEnabled, 2,3, false);
}

void WARP_AVERAGESAN::Instantaneous_Activity3Activity::LinkVariables(){

  G_MEM->Register(&G_MEM_Mobius_Mark);

}

bool WARP_AVERAGESAN::Instantaneous_Activity3Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((INST_SEL->Mark() == -1 && G_MEM->Mark() > 0 && WARP->Mark() == -1));
  return NewEnabled;
}

double WARP_AVERAGESAN::Instantaneous_Activity3Activity::Weight(){ 
  return 1;
}

bool WARP_AVERAGESAN::Instantaneous_Activity3Activity::ReactivationPredicate(){ 
  return false;
}

bool WARP_AVERAGESAN::Instantaneous_Activity3Activity::ReactivationFunction(){ 
  return false;
}

double WARP_AVERAGESAN::Instantaneous_Activity3Activity::SampleDistribution(){
  return 0;
}

double* WARP_AVERAGESAN::Instantaneous_Activity3Activity::ReturnDistributionParameters(){
    return NULL;
}

int WARP_AVERAGESAN::Instantaneous_Activity3Activity::Rank(){
  return 1;
}

BaseActionClass* WARP_AVERAGESAN::Instantaneous_Activity3Activity::Fire(){
  G_MEM->Mark()--;
  INST_SEL->Mark() = 1;
  return this;
}

/*======================Instantaneous_Activity4Activity========================*/


WARP_AVERAGESAN::Instantaneous_Activity4Activity::Instantaneous_Activity4Activity(){
  ActivityInitialize("Instantaneous_Activity4",4,Instantaneous , RaceEnabled, 2,3, false);
}

void WARP_AVERAGESAN::Instantaneous_Activity4Activity::LinkVariables(){


  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool WARP_AVERAGESAN::Instantaneous_Activity4Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((INST_SEL->Mark() != -1 && WARP->Mark() == -1 && INSTRUCTION_READY->Mark() > 0));
  return NewEnabled;
}

double WARP_AVERAGESAN::Instantaneous_Activity4Activity::Weight(){ 
  return 1;
}

bool WARP_AVERAGESAN::Instantaneous_Activity4Activity::ReactivationPredicate(){ 
  return false;
}

bool WARP_AVERAGESAN::Instantaneous_Activity4Activity::ReactivationFunction(){ 
  return false;
}

double WARP_AVERAGESAN::Instantaneous_Activity4Activity::SampleDistribution(){
  return 0;
}

double* WARP_AVERAGESAN::Instantaneous_Activity4Activity::ReturnDistributionParameters(){
    return NULL;
}

int WARP_AVERAGESAN::Instantaneous_Activity4Activity::Rank(){
  return 1;
}

BaseActionClass* WARP_AVERAGESAN::Instantaneous_Activity4Activity::Fire(){
  WARP->Mark() = INST_SEL->Mark();
  INST_SEL->Mark() = -1;
  return this;
}

