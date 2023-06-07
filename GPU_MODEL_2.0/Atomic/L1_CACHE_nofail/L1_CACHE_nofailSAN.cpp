

// This C++ file was created by SanEditor

#include "Atomic/L1_CACHE_nofail/L1_CACHE_nofailSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         L1_CACHE_nofailSAN Constructor             
******************************************************************/


L1_CACHE_nofailSAN::L1_CACHE_nofailSAN(){


  Activity* InitialActionList[2]={
    &Instantaneous_Activity1, //0
    &Instantaneous_Activity2  // 1
  };

  BaseGroupClass* InitialGroupList[2]={
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(Instantaneous_Activity2)
  };

  WRITE_L1 = new Place("WRITE_L1" ,0);
  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  READ_L1 = new Place("READ_L1" ,0);
  BaseStateVariableClass* InitialPlaces[3]={
    WRITE_L1,  // 0
    INSTRUCTION_READY,  // 1
    READ_L1   // 2
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("L1_CACHE_nofail", 3, InitialPlaces, 
                        0, InitialROPlaces, 
                        2, InitialActionList, 2, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[4][2]={ 
    {2,0}, {1,0}, {0,1}, {1,1}
  };
  for(int n=0;n<4;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[2][2]={ 
    {2,0}, {0,1}
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

void L1_CACHE_nofailSAN::CustomInitialization() {

}
L1_CACHE_nofailSAN::~L1_CACHE_nofailSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void L1_CACHE_nofailSAN::assignPlacesToActivitiesInst(){
  Instantaneous_Activity1.READ_L1 = (Place*) LocalStateVariables[2];
  Instantaneous_Activity1.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
  Instantaneous_Activity2.WRITE_L1 = (Place*) LocalStateVariables[0];
  Instantaneous_Activity2.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
}
void L1_CACHE_nofailSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================Instantaneous_Activity1Activity========================*/


L1_CACHE_nofailSAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",0,Instantaneous , RaceEnabled, 2,1, false);
}

void L1_CACHE_nofailSAN::Instantaneous_Activity1Activity::LinkVariables(){
  READ_L1->Register(&READ_L1_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool L1_CACHE_nofailSAN::Instantaneous_Activity1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_L1_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHE_nofailSAN::Instantaneous_Activity1Activity::Weight(){ 
  return 1;
}

bool L1_CACHE_nofailSAN::Instantaneous_Activity1Activity::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHE_nofailSAN::Instantaneous_Activity1Activity::ReactivationFunction(){ 
  return false;
}

double L1_CACHE_nofailSAN::Instantaneous_Activity1Activity::SampleDistribution(){
  return 0;
}

double* L1_CACHE_nofailSAN::Instantaneous_Activity1Activity::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHE_nofailSAN::Instantaneous_Activity1Activity::Rank(){
  return 1;
}

BaseActionClass* L1_CACHE_nofailSAN::Instantaneous_Activity1Activity::Fire(){
  (*(READ_L1_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity2Activity========================*/


L1_CACHE_nofailSAN::Instantaneous_Activity2Activity::Instantaneous_Activity2Activity(){
  ActivityInitialize("Instantaneous_Activity2",1,Instantaneous , RaceEnabled, 2,1, false);
}

void L1_CACHE_nofailSAN::Instantaneous_Activity2Activity::LinkVariables(){
  WRITE_L1->Register(&WRITE_L1_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool L1_CACHE_nofailSAN::Instantaneous_Activity2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_L1_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L1_CACHE_nofailSAN::Instantaneous_Activity2Activity::Weight(){ 
  return 1;
}

bool L1_CACHE_nofailSAN::Instantaneous_Activity2Activity::ReactivationPredicate(){ 
  return false;
}

bool L1_CACHE_nofailSAN::Instantaneous_Activity2Activity::ReactivationFunction(){ 
  return false;
}

double L1_CACHE_nofailSAN::Instantaneous_Activity2Activity::SampleDistribution(){
  return 0;
}

double* L1_CACHE_nofailSAN::Instantaneous_Activity2Activity::ReturnDistributionParameters(){
    return NULL;
}

int L1_CACHE_nofailSAN::Instantaneous_Activity2Activity::Rank(){
  return 1;
}

BaseActionClass* L1_CACHE_nofailSAN::Instantaneous_Activity2Activity::Fire(){
  (*(WRITE_L1_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

