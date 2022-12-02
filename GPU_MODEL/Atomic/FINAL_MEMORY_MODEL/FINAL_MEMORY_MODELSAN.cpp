

// This C++ file was created by SanEditor

#include "Atomic/FINAL_MEMORY_MODEL/FINAL_MEMORY_MODELSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         FINAL_MEMORY_MODELSAN Constructor             
******************************************************************/


FINAL_MEMORY_MODELSAN::FINAL_MEMORY_MODELSAN(){


  Activity* InitialActionList[1]={
    &WRITE_TO  // 0
  };

  BaseGroupClass* InitialGroupList[1]={
    (BaseGroupClass*) &(WRITE_TO)
  };

  WRITE_FINAL_MEMORY = new Place("WRITE_FINAL_MEMORY" ,0);
  WRITE_DRAM = new Place("WRITE_DRAM" ,0);
  BaseStateVariableClass* InitialPlaces[2]={
    WRITE_FINAL_MEMORY,  // 0
    WRITE_DRAM   // 1
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("FINAL_MEMORY_MODEL", 2, InitialPlaces, 
                        0, InitialROPlaces, 
                        1, InitialActionList, 1, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[2][2]={ 
    {0,0}, {1,0}
  };
  for(int n=0;n<2;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[1][2]={ 
    {0,0}
  };
  for(int n=0;n<1;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<1;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void FINAL_MEMORY_MODELSAN::CustomInitialization() {

}
FINAL_MEMORY_MODELSAN::~FINAL_MEMORY_MODELSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void FINAL_MEMORY_MODELSAN::assignPlacesToActivitiesInst(){
  WRITE_TO.WRITE_FINAL_MEMORY = (Place*) LocalStateVariables[0];
  WRITE_TO.WRITE_DRAM = (Place*) LocalStateVariables[1];
}
void FINAL_MEMORY_MODELSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================WRITE_TOActivity========================*/


FINAL_MEMORY_MODELSAN::WRITE_TOActivity::WRITE_TOActivity(){
  ActivityInitialize("WRITE_TO",0,Instantaneous , RaceEnabled, 2,1, false);
}

void FINAL_MEMORY_MODELSAN::WRITE_TOActivity::LinkVariables(){
  WRITE_FINAL_MEMORY->Register(&WRITE_FINAL_MEMORY_Mobius_Mark);
  WRITE_DRAM->Register(&WRITE_DRAM_Mobius_Mark);
}

bool FINAL_MEMORY_MODELSAN::WRITE_TOActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_FINAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double FINAL_MEMORY_MODELSAN::WRITE_TOActivity::Weight(){ 
  return 1;
}

bool FINAL_MEMORY_MODELSAN::WRITE_TOActivity::ReactivationPredicate(){ 
  return false;
}

bool FINAL_MEMORY_MODELSAN::WRITE_TOActivity::ReactivationFunction(){ 
  return false;
}

double FINAL_MEMORY_MODELSAN::WRITE_TOActivity::SampleDistribution(){
  return 0;
}

double* FINAL_MEMORY_MODELSAN::WRITE_TOActivity::ReturnDistributionParameters(){
    return NULL;
}

int FINAL_MEMORY_MODELSAN::WRITE_TOActivity::Rank(){
  return 1;
}

BaseActionClass* FINAL_MEMORY_MODELSAN::WRITE_TOActivity::Fire(){
  (*(WRITE_FINAL_MEMORY_Mobius_Mark))--;
  (*(WRITE_DRAM_Mobius_Mark))++;
  return this;
}

