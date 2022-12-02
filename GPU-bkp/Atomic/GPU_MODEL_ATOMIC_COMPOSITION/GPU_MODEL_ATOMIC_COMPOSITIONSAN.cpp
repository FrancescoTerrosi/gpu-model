

// This C++ file was created by SanEditor

#include "Atomic/GPU_MODEL_ATOMIC_COMPOSITION/GPU_MODEL_ATOMIC_COMPOSITIONSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         GPU_MODEL_ATOMIC_COMPOSITIONSAN Constructor             
******************************************************************/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::GPU_MODEL_ATOMIC_COMPOSITIONSAN(){


  T_READ_TOTALGroup.initialize(2, "T_READ_TOTALGroup");
  T_READ_TOTALGroup.appendGroup((BaseGroupClass*) &T_READ_TOTAL_case1);
  T_READ_TOTALGroup.appendGroup((BaseGroupClass*) &T_READ_TOTAL_case2);

  T_WRITE_RESULTGroup.initialize(2, "T_WRITE_RESULTGroup");
  T_WRITE_RESULTGroup.appendGroup((BaseGroupClass*) &T_WRITE_RESULT_case1);
  T_WRITE_RESULTGroup.appendGroup((BaseGroupClass*) &T_WRITE_RESULT_case2);

  COMPUTEGroup.initialize(2, "COMPUTEGroup");
  COMPUTEGroup.appendGroup((BaseGroupClass*) &COMPUTE_case1);
  COMPUTEGroup.appendGroup((BaseGroupClass*) &COMPUTE_case2);

  T_READGroup.initialize(2, "T_READGroup");
  T_READGroup.appendGroup((BaseGroupClass*) &T_READ_case1);
  T_READGroup.appendGroup((BaseGroupClass*) &T_READ_case2);

  T_WRITE_OUTPUTGroup.initialize(2, "T_WRITE_OUTPUTGroup");
  T_WRITE_OUTPUTGroup.appendGroup((BaseGroupClass*) &T_WRITE_OUTPUT_case1);
  T_WRITE_OUTPUTGroup.appendGroup((BaseGroupClass*) &T_WRITE_OUTPUT_case2);

  READ_TOTALGroup.initialize(2, "READ_TOTALGroup");
  READ_TOTALGroup.appendGroup((BaseGroupClass*) &READ_TOTAL_case1);
  READ_TOTALGroup.appendGroup((BaseGroupClass*) &READ_TOTAL_case2);

  WRITE_TOGroup.initialize(2, "WRITE_TOGroup");
  WRITE_TOGroup.appendGroup((BaseGroupClass*) &WRITE_TO_case1);
  WRITE_TOGroup.appendGroup((BaseGroupClass*) &WRITE_TO_case2);

  Activity* InitialActionList[15]={
    &T_READ_TOTAL_case1, //0
    &T_READ_TOTAL_case2, //1
    &T_WRITE_RESULT_case1, //2
    &T_WRITE_RESULT_case2, //3
    &COMPUTE_case1, //4
    &COMPUTE_case2, //5
    &T_READ_case1, //6
    &T_READ_case2, //7
    &T_WRITE_OUTPUT_case1, //8
    &T_WRITE_OUTPUT_case2, //9
    &DISPATCHER, //10
    &READ_TOTAL_case1, //11
    &READ_TOTAL_case2, //12
    &WRITE_TO_case1, //13
    &WRITE_TO_case2  // 14
  };

  BaseGroupClass* InitialGroupList[8]={
    (BaseGroupClass*) &(T_READ_TOTALGroup), 
    (BaseGroupClass*) &(T_WRITE_RESULTGroup), 
    (BaseGroupClass*) &(COMPUTEGroup), 
    (BaseGroupClass*) &(T_READGroup), 
    (BaseGroupClass*) &(T_WRITE_OUTPUTGroup), 
    (BaseGroupClass*) &(DISPATCHER), 
    (BaseGroupClass*) &(READ_TOTALGroup), 
    (BaseGroupClass*) &(WRITE_TOGroup)
  };

  TOTAL_PERFORM_OK_READ = new Place("TOTAL_PERFORM_OK_READ" ,0);
  TOTAL_PERFORM_KO_READ = new Place("TOTAL_PERFORM_KO_READ" ,0);
  RESULT_OK_CONTENT = new Place("RESULT_OK_CONTENT" ,0);
  RESULT_KO_CONTENT = new Place("RESULT_KO_CONTENT" ,0);
  RESULT_KO = new Place("RESULT_KO" ,0);
  RESULT_OK = new Place("RESULT_OK" ,0);
  ALU_INSTRUCTION = new Place("ALU_INSTRUCTION" ,0);
  OUTPUT_MEMORY = new Place("OUTPUT_MEMORY" ,0);
  WRITE_RESULT_MEMORY = new Place("WRITE_RESULT_MEMORY" ,0);
  RESULT_MEMORY = new Place("RESULT_MEMORY" ,0);
  READ_TOTAL_MEMORY = new Place("READ_TOTAL_MEMORY" ,0);
  TOTAL_MEMORY = new Place("TOTAL_MEMORY" ,0);
  RESULT_PERFORM_OK_READ = new Place("RESULT_PERFORM_OK_READ" ,0);
  RESULT_PERFORM_KO_READ = new Place("RESULT_PERFORM_KO_READ" ,0);
  OUTPUT_OK_CONTENT = new Place("OUTPUT_OK_CONTENT" ,0);
  OUTPUT_KO_CONTENT = new Place("OUTPUT_KO_CONTENT" ,0);
  READ_RESULT_MEMORY = new Place("READ_RESULT_MEMORY" ,0);
  WRITE_OUTPUT_MEMORY = new Place("WRITE_OUTPUT_MEMORY" ,0);
  ALU_INSTRUCTION_WITH_INPUT = new Place("ALU_INSTRUCTION_WITH_INPUT" ,0);
  INST_COUNTER = new Place("INST_COUNTER" ,-1);
  int temp_SCHEDULERInstructionsvalue = 0;
  SCHEDULER = new Instructions("SCHEDULER",temp_SCHEDULERInstructionsvalue);
  BaseStateVariableClass* InitialPlaces[21]={
    TOTAL_PERFORM_OK_READ,  // 0
    TOTAL_PERFORM_KO_READ,  // 1
    RESULT_OK_CONTENT,  // 2
    RESULT_KO_CONTENT,  // 3
    RESULT_KO,  // 4
    RESULT_OK,  // 5
    ALU_INSTRUCTION,  // 6
    OUTPUT_MEMORY,  // 7
    WRITE_RESULT_MEMORY,  // 8
    RESULT_MEMORY,  // 9
    READ_TOTAL_MEMORY,  // 10
    TOTAL_MEMORY,  // 11
    RESULT_PERFORM_OK_READ,  // 12
    RESULT_PERFORM_KO_READ,  // 13
    OUTPUT_OK_CONTENT,  // 14
    OUTPUT_KO_CONTENT,  // 15
    READ_RESULT_MEMORY,  // 16
    WRITE_OUTPUT_MEMORY,  // 17
    ALU_INSTRUCTION_WITH_INPUT,  // 18
    INST_COUNTER,  // 19
    SCHEDULER   // 20
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("GPU_MODEL_ATOMIC_COMPOSITION", 21, InitialPlaces, 
                        0, InitialROPlaces, 
                        15, InitialActionList, 8, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[38][2]={ 
    {11,0}, {0,0}, {11,1}, {1,1}, {9,2}, {2,2}, {9,3}, {3,3}, 
    {6,4}, {5,4}, {6,5}, {4,5}, {9,6}, {12,6}, {9,7}, {13,7}, 
    {7,8}, {14,8}, {7,9}, {15,9}, {19,10}, {10,10}, {16,10}, 
    {8,10}, {17,10}, {6,10}, {20,10}, {10,11}, {16,11}, {11,11}, 
    {10,12}, {16,12}, {8,13}, {17,13}, {9,13}, {8,14}, {17,14}, 
    {7,14}
  };
  for(int n=0;n<38;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[19][2]={ 
    {11,0}, {11,1}, {9,2}, {9,3}, {6,4}, {6,5}, {9,6}, {9,7}, 
    {7,8}, {7,9}, {19,10}, {10,11}, {16,11}, {10,12}, {16,12}, 
    {8,13}, {17,13}, {8,14}, {17,14}
  };
  for(int n=0;n<19;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<15;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::CustomInitialization() {
int i;
for (i = 0; i < 5; i++){
    SCHEDULER->Index(i)->Mark() = i;
}
}
GPU_MODEL_ATOMIC_COMPOSITIONSAN::~GPU_MODEL_ATOMIC_COMPOSITIONSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::assignPlacesToActivitiesInst(){
  T_READ_TOTAL_case1.TOTAL_MEMORY = (Place*) LocalStateVariables[11];
  T_READ_TOTAL_case1.TOTAL_PERFORM_OK_READ = (Place*) LocalStateVariables[0];
  T_READ_TOTAL_case2.TOTAL_MEMORY = (Place*) LocalStateVariables[11];
  T_READ_TOTAL_case2.TOTAL_PERFORM_KO_READ = (Place*) LocalStateVariables[1];
  T_WRITE_RESULT_case1.RESULT_MEMORY = (Place*) LocalStateVariables[9];
  T_WRITE_RESULT_case1.RESULT_OK_CONTENT = (Place*) LocalStateVariables[2];
  T_WRITE_RESULT_case2.RESULT_MEMORY = (Place*) LocalStateVariables[9];
  T_WRITE_RESULT_case2.RESULT_KO_CONTENT = (Place*) LocalStateVariables[3];
  COMPUTE_case1.ALU_INSTRUCTION = (Place*) LocalStateVariables[6];
  COMPUTE_case1.RESULT_OK = (Place*) LocalStateVariables[5];
  COMPUTE_case2.ALU_INSTRUCTION = (Place*) LocalStateVariables[6];
  COMPUTE_case2.RESULT_KO = (Place*) LocalStateVariables[4];
  T_READ_case1.RESULT_MEMORY = (Place*) LocalStateVariables[9];
  T_READ_case1.RESULT_PERFORM_OK_READ = (Place*) LocalStateVariables[12];
  T_READ_case2.RESULT_MEMORY = (Place*) LocalStateVariables[9];
  T_READ_case2.RESULT_PERFORM_KO_READ = (Place*) LocalStateVariables[13];
  T_WRITE_OUTPUT_case1.OUTPUT_MEMORY = (Place*) LocalStateVariables[7];
  T_WRITE_OUTPUT_case1.OUTPUT_OK_CONTENT = (Place*) LocalStateVariables[14];
  T_WRITE_OUTPUT_case2.OUTPUT_MEMORY = (Place*) LocalStateVariables[7];
  T_WRITE_OUTPUT_case2.OUTPUT_KO_CONTENT = (Place*) LocalStateVariables[15];
  DISPATCHER.INST_COUNTER = (Place*) LocalStateVariables[19];
  DISPATCHER.READ_TOTAL_MEMORY = (Place*) LocalStateVariables[10];
  DISPATCHER.READ_RESULT_MEMORY = (Place*) LocalStateVariables[16];
  DISPATCHER.WRITE_RESULT_MEMORY = (Place*) LocalStateVariables[8];
  DISPATCHER.WRITE_OUTPUT_MEMORY = (Place*) LocalStateVariables[17];
  DISPATCHER.ALU_INSTRUCTION = (Place*) LocalStateVariables[6];
  DISPATCHER.SCHEDULER = (Instructions*) LocalStateVariables[20];
  READ_TOTAL_case1.READ_TOTAL_MEMORY = (Place*) LocalStateVariables[10];
  READ_TOTAL_case1.READ_RESULT_MEMORY = (Place*) LocalStateVariables[16];
  READ_TOTAL_case1.TOTAL_MEMORY = (Place*) LocalStateVariables[11];
  READ_TOTAL_case2.READ_TOTAL_MEMORY = (Place*) LocalStateVariables[10];
  READ_TOTAL_case2.READ_RESULT_MEMORY = (Place*) LocalStateVariables[16];
  WRITE_TO_case1.WRITE_RESULT_MEMORY = (Place*) LocalStateVariables[8];
  WRITE_TO_case1.WRITE_OUTPUT_MEMORY = (Place*) LocalStateVariables[17];
  WRITE_TO_case1.RESULT_MEMORY = (Place*) LocalStateVariables[9];
  WRITE_TO_case2.WRITE_RESULT_MEMORY = (Place*) LocalStateVariables[8];
  WRITE_TO_case2.WRITE_OUTPUT_MEMORY = (Place*) LocalStateVariables[17];
  WRITE_TO_case2.OUTPUT_MEMORY = (Place*) LocalStateVariables[7];
}
void GPU_MODEL_ATOMIC_COMPOSITIONSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================T_READ_TOTALActivity_case1========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case1::T_READ_TOTALActivity_case1(){
  ActivityInitialize("T_READ_TOTAL_case1",0,Instantaneous , RaceEnabled, 2,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case1::LinkVariables(){
  TOTAL_MEMORY->Register(&TOTAL_MEMORY_Mobius_Mark);
  TOTAL_PERFORM_OK_READ->Register(&TOTAL_PERFORM_OK_READ_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(TOTAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case1::Weight(){ 
  return 1/2;
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
  (*(TOTAL_MEMORY_Mobius_Mark))--;
  (*(TOTAL_PERFORM_OK_READ_Mobius_Mark))++;
  return this;
}

/*======================T_READ_TOTALActivity_case2========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case2::T_READ_TOTALActivity_case2(){
  ActivityInitialize("T_READ_TOTAL_case2",0,Instantaneous , RaceEnabled, 2,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case2::LinkVariables(){
  TOTAL_MEMORY->Register(&TOTAL_MEMORY_Mobius_Mark);
  TOTAL_PERFORM_KO_READ->Register(&TOTAL_PERFORM_KO_READ_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(TOTAL_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READ_TOTALActivity_case2::Weight(){ 
  return 1/2;
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
  (*(TOTAL_MEMORY_Mobius_Mark))--;
  (*(TOTAL_PERFORM_KO_READ_Mobius_Mark))++;
  return this;
}

/*======================T_WRITE_RESULTActivity_case1========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case1::T_WRITE_RESULTActivity_case1(){
  ActivityInitialize("T_WRITE_RESULT_case1",1,Instantaneous , RaceEnabled, 2,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case1::LinkVariables(){
  RESULT_MEMORY->Register(&RESULT_MEMORY_Mobius_Mark);
  RESULT_OK_CONTENT->Register(&RESULT_OK_CONTENT_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case1::Weight(){ 
  return 1/2;
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
  (*(RESULT_MEMORY_Mobius_Mark))--;
  (*(RESULT_OK_CONTENT_Mobius_Mark))++;
  return this;
}

/*======================T_WRITE_RESULTActivity_case2========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case2::T_WRITE_RESULTActivity_case2(){
  ActivityInitialize("T_WRITE_RESULT_case2",1,Instantaneous , RaceEnabled, 2,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case2::LinkVariables(){
  RESULT_MEMORY->Register(&RESULT_MEMORY_Mobius_Mark);
  RESULT_KO_CONTENT->Register(&RESULT_KO_CONTENT_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_RESULTActivity_case2::Weight(){ 
  return 1/2;
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
  (*(RESULT_MEMORY_Mobius_Mark))--;
  (*(RESULT_KO_CONTENT_Mobius_Mark))++;
  return this;
}

/*======================COMPUTEActivity_case1========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case1::COMPUTEActivity_case1(){
  ActivityInitialize("COMPUTE_case1",2,Instantaneous , RaceEnabled, 2,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case1::LinkVariables(){
  ALU_INSTRUCTION->Register(&ALU_INSTRUCTION_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ALU_INSTRUCTION_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case1::Weight(){ 
  return 1/2;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case1::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case1::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case1::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case1::Fire(){
  (*(ALU_INSTRUCTION_Mobius_Mark))--;
  (*(RESULT_OK_Mobius_Mark))++;
  return this;
}

/*======================COMPUTEActivity_case2========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case2::COMPUTEActivity_case2(){
  ActivityInitialize("COMPUTE_case2",2,Instantaneous , RaceEnabled, 2,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case2::LinkVariables(){
  ALU_INSTRUCTION->Register(&ALU_INSTRUCTION_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ALU_INSTRUCTION_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case2::Weight(){ 
  return 1/2;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case2::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case2::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case2::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::COMPUTEActivity_case2::Fire(){
  (*(ALU_INSTRUCTION_Mobius_Mark))--;
  (*(RESULT_KO_Mobius_Mark))++;
  return this;
}

/*======================T_READActivity_case1========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case1::T_READActivity_case1(){
  ActivityInitialize("T_READ_case1",3,Instantaneous , RaceEnabled, 2,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case1::LinkVariables(){
  RESULT_MEMORY->Register(&RESULT_MEMORY_Mobius_Mark);
  RESULT_PERFORM_OK_READ->Register(&RESULT_PERFORM_OK_READ_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case1::Weight(){ 
  return 1/2;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case1::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case1::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case1::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case1::Fire(){
  (*(RESULT_MEMORY_Mobius_Mark))--;
  (*(RESULT_PERFORM_OK_READ_Mobius_Mark))++;
  return this;
}

/*======================T_READActivity_case2========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case2::T_READActivity_case2(){
  ActivityInitialize("T_READ_case2",3,Instantaneous , RaceEnabled, 2,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case2::LinkVariables(){
  RESULT_MEMORY->Register(&RESULT_MEMORY_Mobius_Mark);
  RESULT_PERFORM_KO_READ->Register(&RESULT_PERFORM_KO_READ_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case2::Weight(){ 
  return 1/2;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case2::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case2::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case2::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_READActivity_case2::Fire(){
  (*(RESULT_MEMORY_Mobius_Mark))--;
  (*(RESULT_PERFORM_KO_READ_Mobius_Mark))++;
  return this;
}

/*======================T_WRITE_OUTPUTActivity_case1========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case1::T_WRITE_OUTPUTActivity_case1(){
  ActivityInitialize("T_WRITE_OUTPUT_case1",4,Instantaneous , RaceEnabled, 2,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case1::LinkVariables(){
  OUTPUT_MEMORY->Register(&OUTPUT_MEMORY_Mobius_Mark);
  OUTPUT_OK_CONTENT->Register(&OUTPUT_OK_CONTENT_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(OUTPUT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case1::Weight(){ 
  return 1/2;
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
  (*(OUTPUT_MEMORY_Mobius_Mark))--;
  (*(OUTPUT_OK_CONTENT_Mobius_Mark))++;
  return this;
}

/*======================T_WRITE_OUTPUTActivity_case2========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case2::T_WRITE_OUTPUTActivity_case2(){
  ActivityInitialize("T_WRITE_OUTPUT_case2",4,Instantaneous , RaceEnabled, 2,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case2::LinkVariables(){
  OUTPUT_MEMORY->Register(&OUTPUT_MEMORY_Mobius_Mark);
  OUTPUT_KO_CONTENT->Register(&OUTPUT_KO_CONTENT_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(OUTPUT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::T_WRITE_OUTPUTActivity_case2::Weight(){ 
  return 1/2;
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
  (*(OUTPUT_MEMORY_Mobius_Mark))--;
  (*(OUTPUT_KO_CONTENT_Mobius_Mark))++;
  return this;
}

/*======================DISPATCHERActivity========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::DISPATCHERActivity::DISPATCHERActivity(){
  ActivityInitialize("DISPATCHER",5,Instantaneous , RaceEnabled, 7,1, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::DISPATCHERActivity::LinkVariables(){
  INST_COUNTER->Register(&INST_COUNTER_Mobius_Mark);
  READ_TOTAL_MEMORY->Register(&READ_TOTAL_MEMORY_Mobius_Mark);
  READ_RESULT_MEMORY->Register(&READ_RESULT_MEMORY_Mobius_Mark);
  WRITE_RESULT_MEMORY->Register(&WRITE_RESULT_MEMORY_Mobius_Mark);
  WRITE_OUTPUT_MEMORY->Register(&WRITE_OUTPUT_MEMORY_Mobius_Mark);
  ALU_INSTRUCTION->Register(&ALU_INSTRUCTION_Mobius_Mark);

}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::DISPATCHERActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((INST_COUNTER->Mark() < 4));
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

  (*(INST_COUNTER_Mobius_Mark))++;
  return this;
}

/*======================READ_TOTALActivity_case1========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case1::READ_TOTALActivity_case1(){
  ActivityInitialize("READ_TOTAL_case1",6,Instantaneous , RaceEnabled, 3,2, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case1::LinkVariables(){
  READ_TOTAL_MEMORY->Register(&READ_TOTAL_MEMORY_Mobius_Mark);
  READ_RESULT_MEMORY->Register(&READ_RESULT_MEMORY_Mobius_Mark);
  TOTAL_MEMORY->Register(&TOTAL_MEMORY_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_TOTAL_MEMORY_Mobius_Mark)) >=1)&&((*(READ_RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case1::Weight(){ 
  return 1/2;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case1::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case1::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case1::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case1::Fire(){
  (*(READ_TOTAL_MEMORY_Mobius_Mark))--;
  (*(READ_RESULT_MEMORY_Mobius_Mark))--;
  (*(TOTAL_MEMORY_Mobius_Mark))++;
  return this;
}

/*======================READ_TOTALActivity_case2========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case2::READ_TOTALActivity_case2(){
  ActivityInitialize("READ_TOTAL_case2",6,Instantaneous , RaceEnabled, 2,2, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case2::LinkVariables(){
  READ_TOTAL_MEMORY->Register(&READ_TOTAL_MEMORY_Mobius_Mark);
  READ_RESULT_MEMORY->Register(&READ_RESULT_MEMORY_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_TOTAL_MEMORY_Mobius_Mark)) >=1)&&((*(READ_RESULT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case2::Weight(){ 
  return 1/2;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case2::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case2::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case2::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::READ_TOTALActivity_case2::Fire(){
  (*(READ_TOTAL_MEMORY_Mobius_Mark))--;
  (*(READ_RESULT_MEMORY_Mobius_Mark))--;
  return this;
}

/*======================WRITE_TOActivity_case1========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case1::WRITE_TOActivity_case1(){
  ActivityInitialize("WRITE_TO_case1",7,Instantaneous , RaceEnabled, 3,2, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case1::LinkVariables(){
  WRITE_RESULT_MEMORY->Register(&WRITE_RESULT_MEMORY_Mobius_Mark);
  WRITE_OUTPUT_MEMORY->Register(&WRITE_OUTPUT_MEMORY_Mobius_Mark);
  RESULT_MEMORY->Register(&RESULT_MEMORY_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_RESULT_MEMORY_Mobius_Mark)) >=1)&&((*(WRITE_OUTPUT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case1::Weight(){ 
  return 1/2;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case1::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case1::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case1::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case1::Fire(){
  (*(WRITE_RESULT_MEMORY_Mobius_Mark))--;
  (*(WRITE_OUTPUT_MEMORY_Mobius_Mark))--;
  (*(RESULT_MEMORY_Mobius_Mark))++;
  return this;
}

/*======================WRITE_TOActivity_case2========================*/


GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case2::WRITE_TOActivity_case2(){
  ActivityInitialize("WRITE_TO_case2",7,Instantaneous , RaceEnabled, 3,2, false);
}

void GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case2::LinkVariables(){
  WRITE_RESULT_MEMORY->Register(&WRITE_RESULT_MEMORY_Mobius_Mark);
  WRITE_OUTPUT_MEMORY->Register(&WRITE_OUTPUT_MEMORY_Mobius_Mark);
  OUTPUT_MEMORY->Register(&OUTPUT_MEMORY_Mobius_Mark);
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_RESULT_MEMORY_Mobius_Mark)) >=1)&&((*(WRITE_OUTPUT_MEMORY_Mobius_Mark)) >=1));
  return NewEnabled;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case2::Weight(){ 
  return 1/2;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case2::ReactivationFunction(){ 
  return false;
}

double GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case2::SampleDistribution(){
  return 0;
}

double* GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case2::Rank(){
  return 1;
}

BaseActionClass* GPU_MODEL_ATOMIC_COMPOSITIONSAN::WRITE_TOActivity_case2::Fire(){
  (*(WRITE_RESULT_MEMORY_Mobius_Mark))--;
  (*(WRITE_OUTPUT_MEMORY_Mobius_Mark))--;
  (*(OUTPUT_MEMORY_Mobius_Mark))++;
  return this;
}

