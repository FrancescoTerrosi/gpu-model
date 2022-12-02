

// This C++ file was created by SanEditor

#include "Atomic/GPU_MODEL_ATOMIC_COMPOSITION/GPU_MODEL_ATOMIC_COMPOSITIONSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         GPU_MODEL_ATOMIC_COMPOSITIONSAN Constructor             
******************************************************************/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::GPU_MODEL_ATOMIC_COMPOSITIONSAN(){


  T_WRITE_RESULTGroup.initialize(2, "T_WRITE_RESULTGroup");
  T_WRITE_RESULTGroup.appendGroup((BaseGroupClass*) &T_WRITE_RESULT_case1);
  T_WRITE_RESULTGroup.appendGroup((BaseGroupClass*) &T_WRITE_RESULT_case2);

  T_READ_RESULTGroup.initialize(2, "T_READ_RESULTGroup");
  T_READ_RESULTGroup.appendGroup((BaseGroupClass*) &T_READ_RESULT_case1);
  T_READ_RESULTGroup.appendGroup((BaseGroupClass*) &T_READ_RESULT_case2);

  T_READ_TOTALGroup.initialize(2, "T_READ_TOTALGroup");
  T_READ_TOTALGroup.appendGroup((BaseGroupClass*) &T_READ_TOTAL_case1);
  T_READ_TOTALGroup.appendGroup((BaseGroupClass*) &T_READ_TOTAL_case2);

  T_WRITE_OUTPUTGroup.initialize(2, "T_WRITE_OUTPUTGroup");
  T_WRITE_OUTPUTGroup.appendGroup((BaseGroupClass*) &T_WRITE_OUTPUT_case1);
  T_WRITE_OUTPUTGroup.appendGroup((BaseGroupClass*) &T_WRITE_OUTPUT_case2);

  Activity* InitialActionList[12]={
    &T_WRITE_RESULT_case1, //0
    &T_WRITE_RESULT_case2, //1
    &T_READ_RESULT_case1, //2
    &T_READ_RESULT_case2, //3
    &T_READ_TOTAL_case1, //4
    &T_READ_TOTAL_case2, //5
    &T_WRITE_OUTPUT_case1, //6
    &T_WRITE_OUTPUT_case2, //7
    &DISPATCHER, //8
    &PREPARE_DATA, //9
    &COMPUTE_OK, //10
    &COMPUTE_KO  // 11
  };

  BaseGroupClass* InitialGroupList[8]={
    (BaseGroupClass*) &(T_WRITE_RESULTGroup), 
    (BaseGroupClass*) &(T_READ_RESULTGroup), 
    (BaseGroupClass*) &(T_READ_TOTALGroup), 
    (BaseGroupClass*) &(T_WRITE_OUTPUTGroup), 
    (BaseGroupClass*) &(DISPATCHER), 
    (BaseGroupClass*) &(PREPARE_DATA), 
    (BaseGroupClass*) &(COMPUTE_OK), 
    (BaseGroupClass*) &(COMPUTE_KO)
  };

  RESULT_KO = new Place("RESULT_KO" ,0);
  RESULT_OK = new Place("RESULT_OK" ,0);
  RESULT_KO_CONTENT = new Place("RESULT_KO_CONTENT" ,0);
  RESULT_PERFORM_KO_READ = new Place("RESULT_PERFORM_KO_READ" ,0);
  TOTAL_PERFORM_OK_READ = new Place("TOTAL_PERFORM_OK_READ" ,0);
  TOTAL_PERFORM_KO_READ = new Place("TOTAL_PERFORM_KO_READ" ,0);
  RESULT_OK_CONTENT = new Place("RESULT_OK_CONTENT" ,0);
  ALU_INSTRUCTION = new Place("ALU_INSTRUCTION" ,0);
  WRITE_RESULT_MEMORY = new Place("WRITE_RESULT_MEMORY" ,0);
  READ_TOTAL_MEMORY = new Place("READ_TOTAL_MEMORY" ,0);
  RESULT_PERFORM_OK_READ = new Place("RESULT_PERFORM_OK_READ" ,0);
  OUTPUT_OK_CONTENT = new Place("OUTPUT_OK_CONTENT" ,0);
  OUTPUT_KO_CONTENT = new Place("OUTPUT_KO_CONTENT" ,0);
  READ_RESULT_MEMORY = new Place("READ_RESULT_MEMORY" ,0);
  WRITE_OUTPUT_MEMORY = new Place("WRITE_OUTPUT_MEMORY" ,0);
  INST_COUNTER = new Place("INST_COUNTER" ,-1);
  GET_KO_DATA = new Place("GET_KO_DATA" ,0);
  GET_OK_DATA = new Place("GET_OK_DATA" ,0);
  INST_COMPLETED = new Place("INST_COMPLETED" ,1);
  int temp_SCHEDULERInstructionsvalue = 0;
  SCHEDULER = new Instructions("SCHEDULER",temp_SCHEDULERInstructionsvalue);
  BaseStateVariableClass* InitialPlaces[20]={
    RESULT_KO,  // 0
    RESULT_OK,  // 1
    RESULT_KO_CONTENT,  // 2
    RESULT_PERFORM_KO_READ,  // 3
    TOTAL_PERFORM_OK_READ,  // 4
    TOTAL_PERFORM_KO_READ,  // 5
    RESULT_OK_CONTENT,  // 6
    ALU_INSTRUCTION,  // 7
    WRITE_RESULT_MEMORY,  // 8
    READ_TOTAL_MEMORY,  // 9
    RESULT_PERFORM_OK_READ,  // 10
    OUTPUT_OK_CONTENT,  // 11
    OUTPUT_KO_CONTENT,  // 12
    READ_RESULT_MEMORY,  // 13
    WRITE_OUTPUT_MEMORY,  // 14
    INST_COUNTER,  // 15
    GET_KO_DATA,  // 16
    GET_OK_DATA,  // 17
    INST_COMPLETED,  // 18
    SCHEDULER   // 19
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("GPU_MODEL_ATOMIC_COMPOSITION", 20, InitialPlaces, 
                        0, InitialROPlaces, 
                        12, InitialActionList, 8, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[43][2]={ 
    {6,0}, {18,0}, {8,0}, {2,1}, {18,1}, {8,1}, {13,2}, {10,2}, 
    {18,2}, {13,3}, {3,3}, {18,3}, {9,4}, {4,4}, {18,4}, {9,5}, 
    {5,5}, {18,5}, {14,6}, {11,6}, {14,7}, {12,7}, {15,8}, {18,8}, 
    {9,8}, {13,8}, {8,8}, {14,8}, {7,8}, {19,8}, {7,9}, {4,9}, 
    {17,9}, {5,9}, {16,9}, {6,9}, {2,9}, {17,10}, {1,10}, {18,10}, 
    {16,11}, {0,11}, {18,11}
  };
  for(int n=0;n<43;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[23][2]={ 
    {8,0}, {1,0}, {0,0}, {15,0}, {8,1}, {1,1}, {0,1}, {15,1}, 
    {13,2}, {13,3}, {9,4}, {9,5}, {14,6}, {14,7}, {15,8}, {18,8}, 
    {4,9}, {5,9}, {7,9}, {6,9}, {2,9}, {17,10}, {16,11}
  };
  for(int n=0;n<23;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<12;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::CustomInitialization() {
SCHEDULER->Index(0)->Mark() = 0;
SCHEDULER->Index(1)->Mark() = 0;
SCHEDULER->Index(2)->Mark() = 4;
SCHEDULER->Index(3)->Mark() = 2;
SCHEDULER->Index(4)->Mark() = 0;
SCHEDULER->Index(5)->Mark() = 1;
SCHEDULER->Index(6)->Mark() = 4;
SCHEDULER->Index(7)->Mark() = 2;
SCHEDULER->Index(8)->Mark() = 1;
SCHEDULER->Index(9)->Mark() = 0;
SCHEDULER->Index(10)->Mark() = 0;
SCHEDULER->Index(11)->Mark() = 4;
SCHEDULER->Index(12)->Mark() = 3;

}
GPU_MODEL_ATOMIC_COMPOSITIONSAN::~GPU_MODEL_ATOMIC_COMPOSITIONSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::assignPlacesToActivitiesInst(){
  T_WRITE_RESULT_case1.WRITE_RESULT_MEMORY = (Place*) LocalStateVariables[8];
  T_WRITE_RESULT_case1.RESULT_OK = (Place*) LocalStateVariables[1];
  T_WRITE_RESULT_case1.RESULT_KO = (Place*) LocalStateVariables[0];
  T_WRITE_RESULT_case1.INST_COUNTER = (Place*) LocalStateVariables[15];
  T_WRITE_RESULT_case1.RESULT_OK_CONTENT = (Place*) LocalStateVariables[6];
  T_WRITE_RESULT_case1.INST_COMPLETED = (Place*) LocalStateVariables[18];
  T_WRITE_RESULT_case2.WRITE_RESULT_MEMORY = (Place*) LocalStateVariables[8];
  T_WRITE_RESULT_case2.RESULT_OK = (Place*) LocalStateVariables[1];
  T_WRITE_RESULT_case2.RESULT_KO = (Place*) LocalStateVariables[0];
  T_WRITE_RESULT_case2.INST_COUNTER = (Place*) LocalStateVariables[15];
  T_WRITE_RESULT_case2.RESULT_KO_CONTENT = (Place*) LocalStateVariables[2];
  T_WRITE_RESULT_case2.INST_COMPLETED = (Place*) LocalStateVariables[18];
  T_READ_RESULT_case1.READ_RESULT_MEMORY = (Place*) LocalStateVariables[13];
  T_READ_RESULT_case1.RESULT_PERFORM_OK_READ = (Place*) LocalStateVariables[10];
  T_READ_RESULT_case1.INST_COMPLETED = (Place*) LocalStateVariables[18];
  T_READ_RESULT_case1.RESULT_OK_CONTENT = (Place*) LocalStateVariables[6];
  T_READ_RESULT_case2.READ_RESULT_MEMORY = (Place*) LocalStateVariables[13];
  T_READ_RESULT_case2.RESULT_PERFORM_KO_READ = (Place*) LocalStateVariables[3];
  T_READ_RESULT_case2.INST_COMPLETED = (Place*) LocalStateVariables[18];
  T_READ_RESULT_case2.RESULT_KO_CONTENT = (Place*) LocalStateVariables[2];
  T_READ_TOTAL_case1.READ_TOTAL_MEMORY = (Place*) LocalStateVariables[9];
  T_READ_TOTAL_case1.TOTAL_PERFORM_OK_READ = (Place*) LocalStateVariables[4];
  T_READ_TOTAL_case1.INST_COMPLETED = (Place*) LocalStateVariables[18];
  T_READ_TOTAL_case2.READ_TOTAL_MEMORY = (Place*) LocalStateVariables[9];
  T_READ_TOTAL_case2.TOTAL_PERFORM_KO_READ = (Place*) LocalStateVariables[5];
  T_READ_TOTAL_case2.INST_COMPLETED = (Place*) LocalStateVariables[18];
  T_WRITE_OUTPUT_case1.WRITE_OUTPUT_MEMORY = (Place*) LocalStateVariables[14];
  T_WRITE_OUTPUT_case1.OUTPUT_OK_CONTENT = (Place*) LocalStateVariables[11];
  T_WRITE_OUTPUT_case1.RESULT_OK = (Place*) LocalStateVariables[1];
  T_WRITE_OUTPUT_case2.WRITE_OUTPUT_MEMORY = (Place*) LocalStateVariables[14];
  T_WRITE_OUTPUT_case2.OUTPUT_KO_CONTENT = (Place*) LocalStateVariables[12];
  T_WRITE_OUTPUT_case2.RESULT_KO = (Place*) LocalStateVariables[0];
  DISPATCHER.INST_COUNTER = (Place*) LocalStateVariables[15];
  DISPATCHER.INST_COMPLETED = (Place*) LocalStateVariables[18];
  DISPATCHER.READ_TOTAL_MEMORY = (Place*) LocalStateVariables[9];
  DISPATCHER.READ_RESULT_MEMORY = (Place*) LocalStateVariables[13];
  DISPATCHER.WRITE_RESULT_MEMORY = (Place*) LocalStateVariables[8];
  DISPATCHER.WRITE_OUTPUT_MEMORY = (Place*) LocalStateVariables[14];
  DISPATCHER.ALU_INSTRUCTION = (Place*) LocalStateVariables[7];
  DISPATCHER.SCHEDULER = (Instructions*) LocalStateVariables[19];
  PREPARE_DATA.TOTAL_PERFORM_OK_READ = (Place*) LocalStateVariables[4];
  PREPARE_DATA.TOTAL_PERFORM_KO_READ = (Place*) LocalStateVariables[5];
  PREPARE_DATA.ALU_INSTRUCTION = (Place*) LocalStateVariables[7];
  PREPARE_DATA.RESULT_OK_CONTENT = (Place*) LocalStateVariables[6];
  PREPARE_DATA.RESULT_KO_CONTENT = (Place*) LocalStateVariables[2];
  PREPARE_DATA.GET_OK_DATA = (Place*) LocalStateVariables[17];
  PREPARE_DATA.GET_KO_DATA = (Place*) LocalStateVariables[16];
  COMPUTE_OK.GET_OK_DATA = (Place*) LocalStateVariables[17];
  COMPUTE_OK.RESULT_OK = (Place*) LocalStateVariables[1];
  COMPUTE_OK.INST_COMPLETED = (Place*) LocalStateVariables[18];
  COMPUTE_KO.GET_KO_DATA = (Place*) LocalStateVariables[16];
  COMPUTE_KO.RESULT_KO = (Place*) LocalStateVariables[0];
  COMPUTE_KO.INST_COMPLETED = (Place*) LocalStateVariables[18];
}
void GPU_MODEL_ATOMIC_COMPOSITIONSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================T_WRITE_RESULTActivity_case1========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case1::T_WRITE_RESULTActivity_case1(){
  ActivityInitialize("T_WRITE_RESULT_case1",0,Instantaneous , RaceEnabled, 3,4, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case1::LinkVariables(){
  WRITE_RESULT_MEMORY->Register(&WRITE_RESULT_MEMORY_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
  INST_COUNTER->Register(&INST_COUNTER_Mobius_Mark);
  RESULT_OK_CONTENT->Register(&RESULT_OK_CONTENT_Mobius_Mark);
  INST_COMPLETED->Register(&INST_COMPLETED_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((( WRITE_RESULT_MEMORY->Mark() > 0 && (RESULT_OK->Mark() + RESULT_KO->Mark() > 0) )
||
INST_COUNTER->Mark() > size && WRITE_RESULT_MEMORY->Mark() > 0));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case1::Weight(){ 
  return ( 0.95 * RESULT_OK->Mark() ) + ( 0.05 * RESULT_KO->Mark() );
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case1::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case1::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case1::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case1::Fire(){
  WRITE_RESULT_MEMORY->Mark()--;
  (*(RESULT_OK_CONTENT_Mobius_Mark))++;
  (*(INST_COMPLETED_Mobius_Mark))++;
  return this;
}

/*======================T_WRITE_RESULTActivity_case2========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case2::T_WRITE_RESULTActivity_case2(){
  ActivityInitialize("T_WRITE_RESULT_case2",0,Instantaneous , RaceEnabled, 3,4, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case2::LinkVariables(){
  WRITE_RESULT_MEMORY->Register(&WRITE_RESULT_MEMORY_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
  INST_COUNTER->Register(&INST_COUNTER_Mobius_Mark);
  RESULT_KO_CONTENT->Register(&RESULT_KO_CONTENT_Mobius_Mark);
  INST_COMPLETED->Register(&INST_COMPLETED_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((( WRITE_RESULT_MEMORY->Mark() > 0 && (RESULT_OK->Mark() + RESULT_KO->Mark() > 0) )
||
INST_COUNTER->Mark() > size && WRITE_RESULT_MEMORY->Mark() > 0));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case2::Weight(){ 
  return ( 0.95 * RESULT_KO->Mark() ) + ( 0.05 * RESULT_OK->Mark() );
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case2::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case2::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case2::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case2::Fire(){
  WRITE_RESULT_MEMORY->Mark()--;
  (*(RESULT_KO_CONTENT_Mobius_Mark))++;
  (*(INST_COMPLETED_Mobius_Mark))++;
  return this;
}

/*======================T_READ_RESULTActivity_case1========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case1::T_READ_RESULTActivity_case1(){
  ActivityInitialize("T_READ_RESULT_case1",1,Instantaneous , RaceEnabled, 3,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case1::LinkVariables(){
  READ_RESULT_MEMORY->Register(&READ_RESULT_MEMORY_Mobius_Mark);
  RESULT_PERFORM_OK_READ->Register(&RESULT_PERFORM_OK_READ_Mobius_Mark);
  INST_COMPLETED->Register(&INST_COMPLETED_Mobius_Mark);
  RESULT_OK_CONTENT->Register(&RESULT_OK_CONTENT_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case1::Weight(){ 
  return RESULT_OK_CONTENT->Mark();
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case1::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case1::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case1::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case1::Fire(){
  (*(READ_RESULT_MEMORY_Mobius_Mark))--;
  (*(RESULT_PERFORM_OK_READ_Mobius_Mark))++;
  (*(INST_COMPLETED_Mobius_Mark))++;
  return this;
}

/*======================T_READ_RESULTActivity_case2========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case2::T_READ_RESULTActivity_case2(){
  ActivityInitialize("T_READ_RESULT_case2",1,Instantaneous , RaceEnabled, 3,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case2::LinkVariables(){
  READ_RESULT_MEMORY->Register(&READ_RESULT_MEMORY_Mobius_Mark);
  RESULT_PERFORM_KO_READ->Register(&RESULT_PERFORM_KO_READ_Mobius_Mark);
  INST_COMPLETED->Register(&INST_COMPLETED_Mobius_Mark);
  RESULT_KO_CONTENT->Register(&RESULT_KO_CONTENT_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case2::Weight(){ 
  return RESULT_KO_CONTENT->Mark();
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case2::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case2::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case2::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_RESULTActivity_case2::Fire(){
  (*(READ_RESULT_MEMORY_Mobius_Mark))--;
  (*(RESULT_PERFORM_KO_READ_Mobius_Mark))++;
  (*(INST_COMPLETED_Mobius_Mark))++;
  return this;
}

/*======================T_READ_TOTALActivity_case1========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case1::T_READ_TOTALActivity_case1(){
  ActivityInitialize("T_READ_TOTAL_case1",2,Instantaneous , RaceEnabled, 3,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case1::LinkVariables(){
  READ_TOTAL_MEMORY->Register(&READ_TOTAL_MEMORY_Mobius_Mark);
  TOTAL_PERFORM_OK_READ->Register(&TOTAL_PERFORM_OK_READ_Mobius_Mark);
  INST_COMPLETED->Register(&INST_COMPLETED_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_TOTAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case1::Weight(){ 
  return 0.99;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case1::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case1::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case1::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case1::Fire(){
  (*(READ_TOTAL_MEMORY_Mobius_Mark))--;
  (*(TOTAL_PERFORM_OK_READ_Mobius_Mark))++;
  (*(INST_COMPLETED_Mobius_Mark))++;
  return this;
}

/*======================T_READ_TOTALActivity_case2========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case2::T_READ_TOTALActivity_case2(){
  ActivityInitialize("T_READ_TOTAL_case2",2,Instantaneous , RaceEnabled, 3,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case2::LinkVariables(){
  READ_TOTAL_MEMORY->Register(&READ_TOTAL_MEMORY_Mobius_Mark);
  TOTAL_PERFORM_KO_READ->Register(&TOTAL_PERFORM_KO_READ_Mobius_Mark);
  INST_COMPLETED->Register(&INST_COMPLETED_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_TOTAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case2::Weight(){ 
  return 0.01;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case2::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case2::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case2::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case2::Fire(){
  (*(READ_TOTAL_MEMORY_Mobius_Mark))--;
  (*(TOTAL_PERFORM_KO_READ_Mobius_Mark))++;
  (*(INST_COMPLETED_Mobius_Mark))++;
  return this;
}

/*======================T_WRITE_OUTPUTActivity_case1========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case1::T_WRITE_OUTPUTActivity_case1(){
  ActivityInitialize("T_WRITE_OUTPUT_case1",3,Instantaneous , RaceEnabled, 2,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case1::LinkVariables(){
  WRITE_OUTPUT_MEMORY->Register(&WRITE_OUTPUT_MEMORY_Mobius_Mark);
  OUTPUT_OK_CONTENT->Register(&OUTPUT_OK_CONTENT_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_OUTPUT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case1::Weight(){ 
  return RESULT_OK->Mark();
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case1::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case1::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case1::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case1::Fire(){
  (*(WRITE_OUTPUT_MEMORY_Mobius_Mark))--;
  (*(OUTPUT_OK_CONTENT_Mobius_Mark))++;
  return this;
}

/*======================T_WRITE_OUTPUTActivity_case2========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case2::T_WRITE_OUTPUTActivity_case2(){
  ActivityInitialize("T_WRITE_OUTPUT_case2",3,Instantaneous , RaceEnabled, 2,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case2::LinkVariables(){
  WRITE_OUTPUT_MEMORY->Register(&WRITE_OUTPUT_MEMORY_Mobius_Mark);
  OUTPUT_KO_CONTENT->Register(&OUTPUT_KO_CONTENT_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_OUTPUT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case2::Weight(){ 
  return RESULT_KO->Mark();
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case2::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case2::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case2::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case2::Fire(){
  (*(WRITE_OUTPUT_MEMORY_Mobius_Mark))--;
  (*(OUTPUT_KO_CONTENT_Mobius_Mark))++;
  return this;
}

/*======================DISPATCHERActivity========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::DISPATCHERActivity::DISPATCHERActivity(){
  ActivityInitialize("DISPATCHER",4,Instantaneous , RaceEnabled, 8,2, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::DISPATCHERActivity::LinkVariables(){
  INST_COUNTER->Register(&INST_COUNTER_Mobius_Mark);
  INST_COMPLETED->Register(&INST_COMPLETED_Mobius_Mark);
  READ_TOTAL_MEMORY->Register(&READ_TOTAL_MEMORY_Mobius_Mark);
  READ_RESULT_MEMORY->Register(&READ_RESULT_MEMORY_Mobius_Mark);
  WRITE_RESULT_MEMORY->Register(&WRITE_RESULT_MEMORY_Mobius_Mark);
  WRITE_OUTPUT_MEMORY->Register(&WRITE_OUTPUT_MEMORY_Mobius_Mark);
  ALU_INSTRUCTION->Register(&ALU_INSTRUCTION_Mobius_Mark);

}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::DISPATCHERActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((INST_COUNTER->Mark() < size-1) && (INST_COMPLETED->Mark() > 0)));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::DISPATCHERActivity::Weight(){ 
  return 1;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::DISPATCHERActivity::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::DISPATCHERActivity::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::DISPATCHERActivity::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::DISPATCHERActivity::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::DISPATCHERActivity::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::DISPATCHERActivity::Fire(){
  INST_COUNTER->Mark()++;
INST_COMPLETED->Mark()--;
  switch( SCHEDULER->Index(INST_COUNTER->Mark())->Mark() ) {
    case 0:
        READ_TOTAL_MEMORY->Mark()++;
    break;

    case 1:
        READ_RESULT_MEMORY->Mark()++;
    break;

    case 2:
        WRITE_RESULT_MEMORY->Mark()++;
    break;

    case 3:
        WRITE_OUTPUT_MEMORY->Mark()++;
    break;

    case 4:
        ALU_INSTRUCTION->Mark()++;
    break;

    default:
    break;
}

  return this;
}

/*======================PREPARE_DATAActivity========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::PREPARE_DATAActivity::PREPARE_DATAActivity(){
  ActivityInitialize("PREPARE_DATA",5,Instantaneous , RaceEnabled, 7,5, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::PREPARE_DATAActivity::LinkVariables(){
  TOTAL_PERFORM_OK_READ->Register(&TOTAL_PERFORM_OK_READ_Mobius_Mark);
  TOTAL_PERFORM_KO_READ->Register(&TOTAL_PERFORM_KO_READ_Mobius_Mark);
  ALU_INSTRUCTION->Register(&ALU_INSTRUCTION_Mobius_Mark);
  RESULT_OK_CONTENT->Register(&RESULT_OK_CONTENT_Mobius_Mark);
  RESULT_KO_CONTENT->Register(&RESULT_KO_CONTENT_Mobius_Mark);
  GET_OK_DATA->Register(&GET_OK_DATA_Mobius_Mark);
  GET_KO_DATA->Register(&GET_KO_DATA_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::PREPARE_DATAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((( (TOTAL_PERFORM_OK_READ->Mark() + TOTAL_PERFORM_KO_READ->Mark() > 0) && ALU_INSTRUCTION->Mark() > 0 )
||
( (RESULT_OK_CONTENT->Mark() + RESULT_KO_CONTENT->Mark() > 0) && ALU_INSTRUCTION->Mark() > 0 )));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::PREPARE_DATAActivity::Weight(){ 
  return 1;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::PREPARE_DATAActivity::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::PREPARE_DATAActivity::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::PREPARE_DATAActivity::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::PREPARE_DATAActivity::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::PREPARE_DATAActivity::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::PREPARE_DATAActivity::Fire(){
  ALU_INSTRUCTION->Mark()--;
  if (TOTAL_PERFORM_OK_READ->Mark() > 0) {
    TOTAL_PERFORM_OK_READ->Mark()--;
    GET_OK_DATA->Mark()++;
} else if (TOTAL_PERFORM_KO_READ->Mark() > 0) {
    TOTAL_PERFORM_KO_READ->Mark()--;
    GET_KO_DATA->Mark()++;
} else if (RESULT_OK_CONTENT->Mark() > 0) {
    RESULT_OK_CONTENT->Mark()--;
    GET_OK_DATA->Mark()++;
} else if (RESULT_KO_CONTENT->Mark() > 0) {
    RESULT_KO_CONTENT->Mark()--;
    GET_KO_DATA->Mark()++;
}
  return this;
}

/*======================COMPUTE_OKActivity========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_OKActivity::COMPUTE_OKActivity(){
  ActivityInitialize("COMPUTE_OK",6,Instantaneous , RaceEnabled, 3,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_OKActivity::LinkVariables(){
  GET_OK_DATA->Register(&GET_OK_DATA_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
  INST_COMPLETED->Register(&INST_COMPLETED_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_OKActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(GET_OK_DATA_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_OKActivity::Weight(){ 
  return 1;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_OKActivity::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_OKActivity::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_OKActivity::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_OKActivity::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_OKActivity::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_OKActivity::Fire(){
  (*(GET_OK_DATA_Mobius_Mark))--;
  (*(RESULT_OK_Mobius_Mark))++;
  (*(INST_COMPLETED_Mobius_Mark))++;
  return this;
}

/*======================COMPUTE_KOActivity========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_KOActivity::COMPUTE_KOActivity(){
  ActivityInitialize("COMPUTE_KO",7,Instantaneous , RaceEnabled, 3,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_KOActivity::LinkVariables(){
  GET_KO_DATA->Register(&GET_KO_DATA_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
  INST_COMPLETED->Register(&INST_COMPLETED_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_KOActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(GET_KO_DATA_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_KOActivity::Weight(){ 
  return 1;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_KOActivity::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_KOActivity::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_KOActivity::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_KOActivity::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_KOActivity::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTE_KOActivity::Fire(){
  (*(GET_KO_DATA_Mobius_Mark))--;
  (*(RESULT_KO_Mobius_Mark))++;
  (*(INST_COMPLETED_Mobius_Mark))++;
  return this;
}

