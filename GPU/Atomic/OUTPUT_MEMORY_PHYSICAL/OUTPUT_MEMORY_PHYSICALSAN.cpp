

// This C++ file was created by SanEditor

#include "Atomic/OUTPUT_MEMORY_PHYSICAL/OUTPUT_MEMORY_PHYSICALSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         OUTPUT_MEMORY_PHYSICALSAN Constructor             
******************************************************************/


OUTPUT_MEMORY_PHYSICALSAN::OUTPUT_MEMORY_PHYSICALSAN(){


  Activity* InitialActionList[1]={
    &WRITE_TO  // 0
  };

  BaseGroupClass* InitialGroupList[1]={
    (BaseGroupClass*) &(WRITE_TO)
  };

  WRITE_DRAM = new Place("WRITE_DRAM" ,0);
  WRITE_OUTPUT_MEMORY = new Place("WRITE_OUTPUT_MEMORY" ,0);
  BaseStateVariableClass* InitialPlaces[2]={
    WRITE_DRAM,  // 0
    WRITE_OUTPUT_MEMORY   // 1
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("OUTPUT_MEMORY_PHYSICAL", 2, InitialPlaces, 
                        0, InitialROPlaces, 
                        1, InitialActionList, 1, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[2][2]={ 
    {1,0}, {0,0}
  };
  for(int n=0;n<2;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[1][2]={ 
    {1,0}
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

void OUTPUT_MEMORY_PHYSICALSAN::CustomInitialization() {

}
OUTPUT_MEMORY_PHYSICALSAN::~OUTPUT_MEMORY_PHYSICALSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void OUTPUT_MEMORY_PHYSICALSAN::assignPlacesToActivitiesInst(){
  WRITE_TO.WRITE_OUTPUT_MEMORY = (Place*) LocalStateVariables[1];
  WRITE_TO.WRITE_DRAM = (Place*) LocalStateVariables[0];
}
void OUTPUT_MEMORY_PHYSICALSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================WRITE_TOActivity========================*/


OUTPUT_MEMORY_PHYSICALSAN::WRITE_TOActivity::WRITE_TOActivity(){
  ActivityInitialize("WRITE_TO",0,Instantaneous , RaceEnabled, 2,1, false);
}

void OUTPUT_MEMORY_PHYSICALSAN::WRITE_TOActivity::LinkVariables(){
  WRITE_OUTPUT_MEMORY->Register(&WRITE_OUTPUT_MEMORY_Mobius_Mark);
  WRITE_DRAM->Register(&WRITE_DRAM_Mobius_Mark);
}

bool OUTPUT_MEMORY_PHYSICALSAN::WRITE_TOActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_OUTPUT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double OUTPUT_MEMORY_PHYSICALSAN::WRITE_TOActivity::Weight(){ 
  return 1;
}

bool OUTPUT_MEMORY_PHYSICALSAN::WRITE_TOActivity::ReactivationPredicate(){ 
  return false;
}

bool OUTPUT_MEMORY_PHYSICALSAN::WRITE_TOActivity::ReactivationFunction(){ 
  return false;
}

double OUTPUT_MEMORY_PHYSICALSAN::WRITE_TOActivity::SampleDistribution(){
  return 0;
}

double* OUTPUT_MEMORY_PHYSICALSAN::WRITE_TOActivity::ReturnDistributionParameters(){
    return NULL;
}

int OUTPUT_MEMORY_PHYSICALSAN::WRITE_TOActivity::Rank(){
  return 1;
}

BaseActionClass* OUTPUT_MEMORY_PHYSICALSAN::WRITE_TOActivity::Fire(){
  (*(WRITE_OUTPUT_MEMORY_Mobius_Mark))--;
  (*(WRITE_DRAM_Mobius_Mark))++;
  return this;
}

