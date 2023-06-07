

// This C++ file was created by SanEditor

#include "Atomic/DRAM_nofail/DRAM_nofailSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         DRAM_nofailSAN Constructor             
******************************************************************/


DRAM_nofailSAN::DRAM_nofailSAN(){


  Activity* InitialActionList[2]={
    &Instantaneous_Activity1, //0
    &Instantaneous_Activity2  // 1
  };

  BaseGroupClass* InitialGroupList[2]={
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(Instantaneous_Activity2)
  };

  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  READ_DRAM = new Place("READ_DRAM" ,0);
  WRITE_DRAM = new Place("WRITE_DRAM" ,0);
  BaseStateVariableClass* InitialPlaces[3]={
    INSTRUCTION_READY,  // 0
    READ_DRAM,  // 1
    WRITE_DRAM   // 2
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("DRAM_nofail", 3, InitialPlaces, 
                        0, InitialROPlaces, 
                        2, InitialActionList, 2, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[4][2]={ 
    {1,0}, {0,0}, {2,1}, {0,1}
  };
  for(int n=0;n<4;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[2][2]={ 
    {1,0}, {2,1}
  };
  for(int n=0;n<2;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<2;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void DRAM_nofailSAN::CustomInitialization() {

}
DRAM_nofailSAN::~DRAM_nofailSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void DRAM_nofailSAN::assignPlacesToActivitiesInst(){
  Instantaneous_Activity1.READ_DRAM = (Place*) LocalStateVariables[1];
  Instantaneous_Activity1.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  Instantaneous_Activity2.WRITE_DRAM = (Place*) LocalStateVariables[2];
  Instantaneous_Activity2.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
}
void DRAM_nofailSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================Instantaneous_Activity1Activity========================*/


DRAM_nofailSAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",0,Instantaneous , RaceEnabled, 2,1, false);
}

void DRAM_nofailSAN::Instantaneous_Activity1Activity::LinkVariables(){
  READ_DRAM->Register(&READ_DRAM_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool DRAM_nofailSAN::Instantaneous_Activity1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_DRAM_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAM_nofailSAN::Instantaneous_Activity1Activity::Weight(){ 
  return 1;
}

bool DRAM_nofailSAN::Instantaneous_Activity1Activity::ReactivationPredicate(){ 
  return false;
}

bool DRAM_nofailSAN::Instantaneous_Activity1Activity::ReactivationFunction(){ 
  return false;
}

double DRAM_nofailSAN::Instantaneous_Activity1Activity::SampleDistribution(){
  return 0;
}

double* DRAM_nofailSAN::Instantaneous_Activity1Activity::ReturnDistributionParameters(){
    return NULL;
}

int DRAM_nofailSAN::Instantaneous_Activity1Activity::Rank(){
  return 1;
}

BaseActionClass* DRAM_nofailSAN::Instantaneous_Activity1Activity::Fire(){
  (*(READ_DRAM_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity2Activity========================*/


DRAM_nofailSAN::Instantaneous_Activity2Activity::Instantaneous_Activity2Activity(){
  ActivityInitialize("Instantaneous_Activity2",1,Instantaneous , RaceEnabled, 2,1, false);
}

void DRAM_nofailSAN::Instantaneous_Activity2Activity::LinkVariables(){
  WRITE_DRAM->Register(&WRITE_DRAM_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool DRAM_nofailSAN::Instantaneous_Activity2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_DRAM_Mobius_Mark)) >=1));
  return NewEnabled;
}

double DRAM_nofailSAN::Instantaneous_Activity2Activity::Weight(){ 
  return 1;
}

bool DRAM_nofailSAN::Instantaneous_Activity2Activity::ReactivationPredicate(){ 
  return false;
}

bool DRAM_nofailSAN::Instantaneous_Activity2Activity::ReactivationFunction(){ 
  return false;
}

double DRAM_nofailSAN::Instantaneous_Activity2Activity::SampleDistribution(){
  return 0;
}

double* DRAM_nofailSAN::Instantaneous_Activity2Activity::ReturnDistributionParameters(){
    return NULL;
}

int DRAM_nofailSAN::Instantaneous_Activity2Activity::Rank(){
  return 1;
}

BaseActionClass* DRAM_nofailSAN::Instantaneous_Activity2Activity::Fire(){
  (*(WRITE_DRAM_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

