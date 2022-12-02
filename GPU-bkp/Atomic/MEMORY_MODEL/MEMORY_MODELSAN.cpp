

// This C++ file was created by SanEditor

#include "Atomic/MEMORY_MODEL/MEMORY_MODELSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         MEMORY_MODELSAN Constructor             
******************************************************************/


MEMORY_MODELSAN::MEMORY_MODELSAN(){


  T_READGroup.initialize(2, "T_READGroup");
  T_READGroup.appendGroup((BaseGroupClass*) &T_READ_case1);
  T_READGroup.appendGroup((BaseGroupClass*) &T_READ_case2);

  T_WRITEGroup.initialize(2, "T_WRITEGroup");
  T_WRITEGroup.appendGroup((BaseGroupClass*) &T_WRITE_case1);
  T_WRITEGroup.appendGroup((BaseGroupClass*) &T_WRITE_case2);

  Activity* InitialActionList[6]={
    &T_READ_case1, //0
    &T_READ_case2, //1
    &T_WRITE_case1, //2
    &T_WRITE_case2, //3
    &REGISTER_FILE_IN, //4
    &FORWARD_TO_DRAM_IF_FULL_OR_FINISH  // 5
  };

  BaseGroupClass* InitialGroupList[4]={
    (BaseGroupClass*) &(T_READGroup), 
    (BaseGroupClass*) &(T_WRITEGroup), 
    (BaseGroupClass*) &(REGISTER_FILE_IN), 
    (BaseGroupClass*) &(FORWARD_TO_DRAM_IF_FULL_OR_FINISH)
  };

  READ = new Place("READ" ,0);
  WRITE = new Place("WRITE" ,0);
  L2_OK_CONTENT = new Place("L2_OK_CONTENT" ,0);
  L2_KO_CONTENT = new Place("L2_KO_CONTENT" ,0);
  PERFORM_OK_READ = new Place("PERFORM_OK_READ" ,0);
  PERFORM_KO_READ = new Place("PERFORM_KO_READ" ,0);
  READ_DATA_IS_OK = new Place("READ_DATA_IS_OK" ,0);
  READ_DATA_IS_KO = new Place("READ_DATA_IS_KO" ,0);
  BaseStateVariableClass* InitialPlaces[8]={
    READ,  // 0
    WRITE,  // 1
    L2_OK_CONTENT,  // 2
    L2_KO_CONTENT,  // 3
    PERFORM_OK_READ,  // 4
    PERFORM_KO_READ,  // 5
    READ_DATA_IS_OK,  // 6
    READ_DATA_IS_KO   // 7
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("MEMORY_MODEL", 8, InitialPlaces, 
                        0, InitialROPlaces, 
                        6, InitialActionList, 4, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[14][2]={ 
    {0,0}, {4,0}, {0,1}, {5,1}, {1,2}, {2,2}, {1,3}, {3,3}, {4,4}, 
    {5,4}, {6,4}, {7,4}, {2,5}, {3,5}
  };
  for(int n=0;n<14;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[8][2]={ 
    {0,0}, {0,1}, {1,2}, {1,3}, {4,4}, {5,4}, {2,5}, {3,5}
  };
  for(int n=0;n<8;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<6;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void MEMORY_MODELSAN::CustomInitialization() {

}
MEMORY_MODELSAN::~MEMORY_MODELSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void MEMORY_MODELSAN::assignPlacesToActivitiesInst(){
  T_READ_case1.READ = (Place*) LocalStateVariables[0];
  T_READ_case1.PERFORM_OK_READ = (Place*) LocalStateVariables[4];
  T_READ_case2.READ = (Place*) LocalStateVariables[0];
  T_READ_case2.PERFORM_KO_READ = (Place*) LocalStateVariables[5];
  T_WRITE_case1.WRITE = (Place*) LocalStateVariables[1];
  T_WRITE_case1.L2_OK_CONTENT = (Place*) LocalStateVariables[2];
  T_WRITE_case2.WRITE = (Place*) LocalStateVariables[1];
  T_WRITE_case2.L2_KO_CONTENT = (Place*) LocalStateVariables[3];
  REGISTER_FILE_IN.PERFORM_OK_READ = (Place*) LocalStateVariables[4];
  REGISTER_FILE_IN.PERFORM_KO_READ = (Place*) LocalStateVariables[5];
  REGISTER_FILE_IN.READ_DATA_IS_OK = (Place*) LocalStateVariables[6];
  REGISTER_FILE_IN.READ_DATA_IS_KO = (Place*) LocalStateVariables[7];
  FORWARD_TO_DRAM_IF_FULL_OR_FINISH.L2_OK_CONTENT = (Place*) LocalStateVariables[2];
  FORWARD_TO_DRAM_IF_FULL_OR_FINISH.L2_KO_CONTENT = (Place*) LocalStateVariables[3];
}
void MEMORY_MODELSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================T_READActivity_case1========================*/


MEMORY_MODELSAN::T_READActivity_case1::T_READActivity_case1(){
  ActivityInitialize("T_READ_case1",0,Instantaneous , RaceEnabled, 2,1, false);
}

void MEMORY_MODELSAN::T_READActivity_case1::LinkVariables(){
  READ->Register(&READ_Mobius_Mark);
  PERFORM_OK_READ->Register(&PERFORM_OK_READ_Mobius_Mark);
}

bool MEMORY_MODELSAN::T_READActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORY_MODELSAN::T_READActivity_case1::Weight(){ 
  return //basato sul numero di token in OK Content
READ->Mark()--
PERFORM_OK_READ->Mark()--;
}

bool MEMORY_MODELSAN::T_READActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool MEMORY_MODELSAN::T_READActivity_case1::ReactivationFunction(){ 
  return false;
}

double MEMORY_MODELSAN::T_READActivity_case1::SampleDistribution(){
  return 0;
}

double* MEMORY_MODELSAN::T_READActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int MEMORY_MODELSAN::T_READActivity_case1::Rank(){
  return 1;
}

BaseActionClass* MEMORY_MODELSAN::T_READActivity_case1::Fire(){
  (*(READ_Mobius_Mark))--;
  (*(PERFORM_OK_READ_Mobius_Mark))++;
  return this;
}

/*======================T_READActivity_case2========================*/


MEMORY_MODELSAN::T_READActivity_case2::T_READActivity_case2(){
  ActivityInitialize("T_READ_case2",0,Instantaneous , RaceEnabled, 2,1, false);
}

void MEMORY_MODELSAN::T_READActivity_case2::LinkVariables(){
  READ->Register(&READ_Mobius_Mark);
  PERFORM_KO_READ->Register(&PERFORM_KO_READ_Mobius_Mark);
}

bool MEMORY_MODELSAN::T_READActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORY_MODELSAN::T_READActivity_case2::Weight(){ 
  return //basato sul numero di token in KO Content
READ->Mark()--
PERFORM_KO_READ->Mark()++;
}

bool MEMORY_MODELSAN::T_READActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool MEMORY_MODELSAN::T_READActivity_case2::ReactivationFunction(){ 
  return false;
}

double MEMORY_MODELSAN::T_READActivity_case2::SampleDistribution(){
  return 0;
}

double* MEMORY_MODELSAN::T_READActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int MEMORY_MODELSAN::T_READActivity_case2::Rank(){
  return 1;
}

BaseActionClass* MEMORY_MODELSAN::T_READActivity_case2::Fire(){
  (*(READ_Mobius_Mark))--;
  (*(PERFORM_KO_READ_Mobius_Mark))++;
  return this;
}

/*======================T_WRITEActivity_case1========================*/


MEMORY_MODELSAN::T_WRITEActivity_case1::T_WRITEActivity_case1(){
  ActivityInitialize("T_WRITE_case1",1,Instantaneous , RaceEnabled, 2,1, false);
}

void MEMORY_MODELSAN::T_WRITEActivity_case1::LinkVariables(){
  WRITE->Register(&WRITE_Mobius_Mark);
  L2_OK_CONTENT->Register(&L2_OK_CONTENT_Mobius_Mark);
}

bool MEMORY_MODELSAN::T_WRITEActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORY_MODELSAN::T_WRITEActivity_case1::Weight(){ 
  return WRITE->Mark()--
L2_OK_CONTENT->Mark()++;
}

bool MEMORY_MODELSAN::T_WRITEActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool MEMORY_MODELSAN::T_WRITEActivity_case1::ReactivationFunction(){ 
  return false;
}

double MEMORY_MODELSAN::T_WRITEActivity_case1::SampleDistribution(){
  return 0;
}

double* MEMORY_MODELSAN::T_WRITEActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int MEMORY_MODELSAN::T_WRITEActivity_case1::Rank(){
  return 1;
}

BaseActionClass* MEMORY_MODELSAN::T_WRITEActivity_case1::Fire(){
  (*(WRITE_Mobius_Mark))--;
  (*(L2_OK_CONTENT_Mobius_Mark))++;
  return this;
}

/*======================T_WRITEActivity_case2========================*/


MEMORY_MODELSAN::T_WRITEActivity_case2::T_WRITEActivity_case2(){
  ActivityInitialize("T_WRITE_case2",1,Instantaneous , RaceEnabled, 2,1, false);
}

void MEMORY_MODELSAN::T_WRITEActivity_case2::LinkVariables(){
  WRITE->Register(&WRITE_Mobius_Mark);
  L2_KO_CONTENT->Register(&L2_KO_CONTENT_Mobius_Mark);
}

bool MEMORY_MODELSAN::T_WRITEActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORY_MODELSAN::T_WRITEActivity_case2::Weight(){ 
  return WRITE->Mark()--
L2_KO_CONTENT->Mark()++;
}

bool MEMORY_MODELSAN::T_WRITEActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool MEMORY_MODELSAN::T_WRITEActivity_case2::ReactivationFunction(){ 
  return false;
}

double MEMORY_MODELSAN::T_WRITEActivity_case2::SampleDistribution(){
  return 0;
}

double* MEMORY_MODELSAN::T_WRITEActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int MEMORY_MODELSAN::T_WRITEActivity_case2::Rank(){
  return 1;
}

BaseActionClass* MEMORY_MODELSAN::T_WRITEActivity_case2::Fire(){
  (*(WRITE_Mobius_Mark))--;
  (*(L2_KO_CONTENT_Mobius_Mark))++;
  return this;
}

/*======================REGISTER_FILE_INActivity========================*/


MEMORY_MODELSAN::REGISTER_FILE_INActivity::REGISTER_FILE_INActivity(){
  ActivityInitialize("REGISTER_FILE_IN",2,Instantaneous , RaceEnabled, 4,2, false);
}

void MEMORY_MODELSAN::REGISTER_FILE_INActivity::LinkVariables(){
  PERFORM_OK_READ->Register(&PERFORM_OK_READ_Mobius_Mark);
  PERFORM_KO_READ->Register(&PERFORM_KO_READ_Mobius_Mark);
  READ_DATA_IS_OK->Register(&READ_DATA_IS_OK_Mobius_Mark);
  READ_DATA_IS_KO->Register(&READ_DATA_IS_KO_Mobius_Mark);
}

bool MEMORY_MODELSAN::REGISTER_FILE_INActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PERFORM_OK_READ_Mobius_Mark)) >=1)&&((*(PERFORM_KO_READ_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORY_MODELSAN::REGISTER_FILE_INActivity::Weight(){ 
  return 1;
}

bool MEMORY_MODELSAN::REGISTER_FILE_INActivity::ReactivationPredicate(){ 
  return false;
}

bool MEMORY_MODELSAN::REGISTER_FILE_INActivity::ReactivationFunction(){ 
  return false;
}

double MEMORY_MODELSAN::REGISTER_FILE_INActivity::SampleDistribution(){
  return 0;
}

double* MEMORY_MODELSAN::REGISTER_FILE_INActivity::ReturnDistributionParameters(){
    return NULL;
}

int MEMORY_MODELSAN::REGISTER_FILE_INActivity::Rank(){
  return 1;
}

BaseActionClass* MEMORY_MODELSAN::REGISTER_FILE_INActivity::Fire(){
  (*(PERFORM_OK_READ_Mobius_Mark))--;
  (*(PERFORM_KO_READ_Mobius_Mark))--;
  (*(READ_DATA_IS_OK_Mobius_Mark))++;
  (*(READ_DATA_IS_KO_Mobius_Mark))++;
  return this;
}

/*======================FORWARD_TO_DRAM_IF_FULL_OR_FINISHActivity========================*/


MEMORY_MODELSAN::FORWARD_TO_DRAM_IF_FULL_OR_FINISHActivity::FORWARD_TO_DRAM_IF_FULL_OR_FINISHActivity(){
  ActivityInitialize("FORWARD_TO_DRAM_IF_FULL_OR_FINISH",3,Instantaneous , RaceEnabled, 2,2, false);
}

void MEMORY_MODELSAN::FORWARD_TO_DRAM_IF_FULL_OR_FINISHActivity::LinkVariables(){
  L2_OK_CONTENT->Register(&L2_OK_CONTENT_Mobius_Mark);
  L2_KO_CONTENT->Register(&L2_KO_CONTENT_Mobius_Mark);
}

bool MEMORY_MODELSAN::FORWARD_TO_DRAM_IF_FULL_OR_FINISHActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(L2_OK_CONTENT_Mobius_Mark)) >=1)&&((*(L2_KO_CONTENT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double MEMORY_MODELSAN::FORWARD_TO_DRAM_IF_FULL_OR_FINISHActivity::Weight(){ 
  return 1;
}

bool MEMORY_MODELSAN::FORWARD_TO_DRAM_IF_FULL_OR_FINISHActivity::ReactivationPredicate(){ 
  return false;
}

bool MEMORY_MODELSAN::FORWARD_TO_DRAM_IF_FULL_OR_FINISHActivity::ReactivationFunction(){ 
  return false;
}

double MEMORY_MODELSAN::FORWARD_TO_DRAM_IF_FULL_OR_FINISHActivity::SampleDistribution(){
  return 0;
}

double* MEMORY_MODELSAN::FORWARD_TO_DRAM_IF_FULL_OR_FINISHActivity::ReturnDistributionParameters(){
    return NULL;
}

int MEMORY_MODELSAN::FORWARD_TO_DRAM_IF_FULL_OR_FINISHActivity::Rank(){
  return 1;
}

BaseActionClass* MEMORY_MODELSAN::FORWARD_TO_DRAM_IF_FULL_OR_FINISHActivity::Fire(){
  (*(L2_OK_CONTENT_Mobius_Mark))--;
  (*(L2_KO_CONTENT_Mobius_Mark))--;
  return this;
}

