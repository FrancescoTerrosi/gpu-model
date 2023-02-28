

// This C++ file was created by SanEditor

#include "Atomic/WARP/WARPSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         WARPSAN Constructor             
******************************************************************/


WARPSAN::WARPSAN(){


  Activity* InitialActionList[1]={
    &DISPATCHER_Copy  // 0
  };

  BaseGroupClass* InitialGroupList[1]={
    (BaseGroupClass*) &(DISPATCHER_Copy)
  };

  INST_COUNTER = new Place("INST_COUNTER" ,-1);
  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  REGISTERS_FILL = new Place("REGISTERS_FILL" ,0);
  short temp_WARPinstructionsvalue = -1;
  WARP = new instructions("WARP",temp_WARPinstructionsvalue);
  short temp_SCHEDULERshort = -1;
  SCHEDULER = new ExtendedPlace<short>("SCHEDULER",temp_SCHEDULERshort);
  BaseStateVariableClass* InitialPlaces[5]={
    INST_COUNTER,  // 0
    INSTRUCTION_READY,  // 1
    REGISTERS_FILL,  // 2
    WARP,  // 3
    SCHEDULER   // 4
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("WARP", 5, InitialPlaces, 
                        0, InitialROPlaces, 
                        1, InitialActionList, 1, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[5][2]={ 
    {1,0}, {0,0}, {4,0}, {2,0}, {3,0}
  };
  for(int n=0;n<5;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[2][2]={ 
    {0,0}, {1,0}
  };
  for(int n=0;n<2;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<1;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void WARPSAN::CustomInitialization() {
WARP->Index(0)->Mark() = 5;WARP->Index(1)->Mark() = 7;
}
WARPSAN::~WARPSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void WARPSAN::assignPlacesToActivitiesInst(){
  DISPATCHER_Copy.INST_COUNTER = (Place*) LocalStateVariables[0];
  DISPATCHER_Copy.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
  DISPATCHER_Copy.SCHEDULER = (ExtendedPlace<short>*) LocalStateVariables[4];
  DISPATCHER_Copy.REGISTERS_FILL = (Place*) LocalStateVariables[2];
  DISPATCHER_Copy.WARP = (instructions*) LocalStateVariables[3];
}
void WARPSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================DISPATCHER_CopyActivity========================*/


WARPSAN::DISPATCHER_CopyActivity::DISPATCHER_CopyActivity(){
  ActivityInitialize("DISPATCHER_Copy",0,Instantaneous , RaceEnabled, 5,2, false);
}

void WARPSAN::DISPATCHER_CopyActivity::LinkVariables(){
  INST_COUNTER->Register(&INST_COUNTER_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);

  REGISTERS_FILL->Register(&REGISTERS_FILL_Mobius_Mark);

}

bool WARPSAN::DISPATCHER_CopyActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((INST_COUNTER->Mark() < size-1) && (INSTRUCTION_READY->Mark() > 0)));
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
  INSTRUCTION_READY->Mark()--;
INST_COUNTER->Mark()++;
  SCHEDULER->Mark() = WARP->Index(INST_COUNTER->Mark())->Mark();
REGISTERS_FILL->Mark() = 1;
  return this;
}

