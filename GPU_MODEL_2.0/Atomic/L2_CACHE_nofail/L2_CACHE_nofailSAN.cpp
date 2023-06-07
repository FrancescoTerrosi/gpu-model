

// This C++ file was created by SanEditor

#include "Atomic/L2_CACHE_nofail/L2_CACHE_nofailSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         L2_CACHE_nofailSAN Constructor             
******************************************************************/


L2_CACHE_nofailSAN::L2_CACHE_nofailSAN(){


  Activity* InitialActionList[2]={
    &PERFORM_READ, //0
    &PERFORM_WRITE  // 1
  };

  BaseGroupClass* InitialGroupList[2]={
    (BaseGroupClass*) &(PERFORM_READ), 
    (BaseGroupClass*) &(PERFORM_WRITE)
  };

  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  READ_L2 = new Place("READ_L2" ,0);
  WRITE_L2 = new Place("WRITE_L2" ,0);
  BaseStateVariableClass* InitialPlaces[3]={
    INSTRUCTION_READY,  // 0
    READ_L2,  // 1
    WRITE_L2   // 2
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("L2_CACHE_nofail", 3, InitialPlaces, 
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

void L2_CACHE_nofailSAN::CustomInitialization() {

}
L2_CACHE_nofailSAN::~L2_CACHE_nofailSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void L2_CACHE_nofailSAN::assignPlacesToActivitiesInst(){
  PERFORM_READ.READ_L2 = (Place*) LocalStateVariables[1];
  PERFORM_READ.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
  PERFORM_WRITE.WRITE_L2 = (Place*) LocalStateVariables[2];
  PERFORM_WRITE.INSTRUCTION_READY = (Place*) LocalStateVariables[0];
}
void L2_CACHE_nofailSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================PERFORM_READActivity========================*/


L2_CACHE_nofailSAN::PERFORM_READActivity::PERFORM_READActivity(){
  ActivityInitialize("PERFORM_READ",0,Instantaneous , RaceEnabled, 2,1, false);
}

void L2_CACHE_nofailSAN::PERFORM_READActivity::LinkVariables(){
  READ_L2->Register(&READ_L2_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool L2_CACHE_nofailSAN::PERFORM_READActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_L2_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L2_CACHE_nofailSAN::PERFORM_READActivity::Weight(){ 
  return 1;
}

bool L2_CACHE_nofailSAN::PERFORM_READActivity::ReactivationPredicate(){ 
  return false;
}

bool L2_CACHE_nofailSAN::PERFORM_READActivity::ReactivationFunction(){ 
  return false;
}

double L2_CACHE_nofailSAN::PERFORM_READActivity::SampleDistribution(){
  return 0;
}

double* L2_CACHE_nofailSAN::PERFORM_READActivity::ReturnDistributionParameters(){
    return NULL;
}

int L2_CACHE_nofailSAN::PERFORM_READActivity::Rank(){
  return 1;
}

BaseActionClass* L2_CACHE_nofailSAN::PERFORM_READActivity::Fire(){
  (*(READ_L2_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

/*======================PERFORM_WRITEActivity========================*/


L2_CACHE_nofailSAN::PERFORM_WRITEActivity::PERFORM_WRITEActivity(){
  ActivityInitialize("PERFORM_WRITE",1,Instantaneous , RaceEnabled, 2,1, false);
}

void L2_CACHE_nofailSAN::PERFORM_WRITEActivity::LinkVariables(){
  WRITE_L2->Register(&WRITE_L2_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
}

bool L2_CACHE_nofailSAN::PERFORM_WRITEActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_L2_Mobius_Mark)) >=1));
  return NewEnabled;
}

double L2_CACHE_nofailSAN::PERFORM_WRITEActivity::Weight(){ 
  return 1;
}

bool L2_CACHE_nofailSAN::PERFORM_WRITEActivity::ReactivationPredicate(){ 
  return false;
}

bool L2_CACHE_nofailSAN::PERFORM_WRITEActivity::ReactivationFunction(){ 
  return false;
}

double L2_CACHE_nofailSAN::PERFORM_WRITEActivity::SampleDistribution(){
  return 0;
}

double* L2_CACHE_nofailSAN::PERFORM_WRITEActivity::ReturnDistributionParameters(){
    return NULL;
}

int L2_CACHE_nofailSAN::PERFORM_WRITEActivity::Rank(){
  return 1;
}

BaseActionClass* L2_CACHE_nofailSAN::PERFORM_WRITEActivity::Fire(){
  (*(WRITE_L2_Mobius_Mark))--;
  (*(INSTRUCTION_READY_Mobius_Mark))++;
  return this;
}

