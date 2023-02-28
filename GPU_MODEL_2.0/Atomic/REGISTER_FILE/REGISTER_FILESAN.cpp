

// This C++ file was created by SanEditor

#include "Atomic/REGISTER_FILE/REGISTER_FILESAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         REGISTER_FILESAN Constructor             
******************************************************************/


REGISTER_FILESAN::REGISTER_FILESAN(){


  READ_FROMGroup.initialize(2, "READ_FROMGroup");
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case1);
  READ_FROMGroup.appendGroup((BaseGroupClass*) &READ_FROM_case2);

  Activity* InitialActionList[9]={
    &Instantaneous_Activity23, //0
    &Instantaneous_Activity12, //1
    &WRITE_WITH_KO_DATA, //2
    &WRITE_WITH_OK_DATA, //3
    &Instantaneous_Activity2, //4
    &READ_FROM_case1, //5
    &READ_FROM_case2, //6
    &Instantaneous_Activity1, //7
    &Instantaneous_Activity3  // 8
  };

  BaseGroupClass* InitialGroupList[8]={
    (BaseGroupClass*) &(Instantaneous_Activity23), 
    (BaseGroupClass*) &(Instantaneous_Activity12), 
    (BaseGroupClass*) &(WRITE_WITH_KO_DATA), 
    (BaseGroupClass*) &(WRITE_WITH_OK_DATA), 
    (BaseGroupClass*) &(Instantaneous_Activity2), 
    (BaseGroupClass*) &(READ_FROMGroup), 
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(Instantaneous_Activity3)
  };

  KO_CONTENT = new Place("KO_CONTENT" ,0);
  MEM_OP_COMPLETE = new Place("MEM_OP_COMPLETE" ,0);
  OK_CONTENT = new Place("OK_CONTENT" ,0);
  WRITE_REGISTER_FILE = new Place("WRITE_REGISTER_FILE" ,0);
  RESULT_KO = new Place("RESULT_KO" ,10000);
  RESULT_OK = new Place("RESULT_OK" ,10000);
  KO_READ = new Place("KO_READ" ,0);
  MEMORY_KO = new Place("MEMORY_KO" ,0);
  READ_REGISTER_FILE = new Place("READ_REGISTER_FILE" ,0);
  MEMORY_OK = new Place("MEMORY_OK" ,0);
  OK_READ = new Place("OK_READ" ,0);
  indexes = new Place("indexes" ,0);
  REGISTERS_FILL = new Place("REGISTERS_FILL" ,0);
  short temp_LIVE_REGISTERSregisters_countervalue = 0;
  LIVE_REGISTERS = new registers_counter("LIVE_REGISTERS",temp_LIVE_REGISTERSregisters_countervalue);
  BaseStateVariableClass* InitialPlaces[14]={
    KO_CONTENT,  // 0
    MEM_OP_COMPLETE,  // 1
    OK_CONTENT,  // 2
    WRITE_REGISTER_FILE,  // 3
    RESULT_KO,  // 4
    RESULT_OK,  // 5
    KO_READ,  // 6
    MEMORY_KO,  // 7
    READ_REGISTER_FILE,  // 8
    MEMORY_OK,  // 9
    OK_READ,  // 10
    indexes,  // 11
    REGISTERS_FILL,  // 12
    LIVE_REGISTERS   // 13
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("REGISTER_FILE", 14, InitialPlaces, 
                        0, InitialROPlaces, 
                        9, InitialActionList, 8, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[24][2]={ 
    {0,0}, {1,0}, {2,1}, {1,1}, {3,2}, {4,2}, {0,2}, {3,3}, {5,3}, 
    {2,3}, {7,4}, {1,4}, {6,4}, {8,5}, {9,5}, {8,6}, {7,6}, {9,7}, 
    {1,7}, {10,7}, {2,8}, {11,8}, {12,8}, {13,8}
  };
  for(int n=0;n<24;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[12][2]={ 
    {0,0}, {2,1}, {3,2}, {4,2}, {3,3}, {5,3}, {7,4}, {8,5}, {8,6}, 
    {9,7}, {11,8}, {12,8}
  };
  for(int n=0;n<12;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<9;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void REGISTER_FILESAN::CustomInitialization() {
LIVE_REGISTERS->Index(0)->Mark() = 0;LIVE_REGISTERS->Index(1)->Mark() = 0;
}
REGISTER_FILESAN::~REGISTER_FILESAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void REGISTER_FILESAN::assignPlacesToActivitiesInst(){
  Instantaneous_Activity23.KO_CONTENT = (Place*) LocalStateVariables[0];
  Instantaneous_Activity23.MEM_OP_COMPLETE = (Place*) LocalStateVariables[1];
  Instantaneous_Activity12.OK_CONTENT = (Place*) LocalStateVariables[2];
  Instantaneous_Activity12.MEM_OP_COMPLETE = (Place*) LocalStateVariables[1];
  WRITE_WITH_KO_DATA.WRITE_REGISTER_FILE = (Place*) LocalStateVariables[3];
  WRITE_WITH_KO_DATA.RESULT_KO = (Place*) LocalStateVariables[4];
  WRITE_WITH_KO_DATA.KO_CONTENT = (Place*) LocalStateVariables[0];
  WRITE_WITH_OK_DATA.WRITE_REGISTER_FILE = (Place*) LocalStateVariables[3];
  WRITE_WITH_OK_DATA.RESULT_OK = (Place*) LocalStateVariables[5];
  WRITE_WITH_OK_DATA.OK_CONTENT = (Place*) LocalStateVariables[2];
  Instantaneous_Activity2.MEMORY_KO = (Place*) LocalStateVariables[7];
  Instantaneous_Activity2.MEM_OP_COMPLETE = (Place*) LocalStateVariables[1];
  Instantaneous_Activity2.KO_READ = (Place*) LocalStateVariables[6];
  READ_FROM_case1.READ_REGISTER_FILE = (Place*) LocalStateVariables[8];
  READ_FROM_case1.MEMORY_OK = (Place*) LocalStateVariables[9];
  READ_FROM_case2.READ_REGISTER_FILE = (Place*) LocalStateVariables[8];
  READ_FROM_case2.MEMORY_KO = (Place*) LocalStateVariables[7];
  Instantaneous_Activity1.MEMORY_OK = (Place*) LocalStateVariables[9];
  Instantaneous_Activity1.MEM_OP_COMPLETE = (Place*) LocalStateVariables[1];
  Instantaneous_Activity1.OK_READ = (Place*) LocalStateVariables[10];
  Instantaneous_Activity3.indexes = (Place*) LocalStateVariables[11];
  Instantaneous_Activity3.REGISTERS_FILL = (Place*) LocalStateVariables[12];
  Instantaneous_Activity3.OK_CONTENT = (Place*) LocalStateVariables[2];
  Instantaneous_Activity3.LIVE_REGISTERS = (registers_counter*) LocalStateVariables[13];
}
void REGISTER_FILESAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================Instantaneous_Activity23Activity========================*/


REGISTER_FILESAN::Instantaneous_Activity23Activity::Instantaneous_Activity23Activity(){
  ActivityInitialize("Instantaneous_Activity23",0,Instantaneous , RaceEnabled, 2,1, false);
}

void REGISTER_FILESAN::Instantaneous_Activity23Activity::LinkVariables(){
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
}

bool REGISTER_FILESAN::Instantaneous_Activity23Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(KO_CONTENT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double REGISTER_FILESAN::Instantaneous_Activity23Activity::Weight(){ 
  return 1;
}

bool REGISTER_FILESAN::Instantaneous_Activity23Activity::ReactivationPredicate(){ 
  return false;
}

bool REGISTER_FILESAN::Instantaneous_Activity23Activity::ReactivationFunction(){ 
  return false;
}

double REGISTER_FILESAN::Instantaneous_Activity23Activity::SampleDistribution(){
  return 0;
}

double* REGISTER_FILESAN::Instantaneous_Activity23Activity::ReturnDistributionParameters(){
    return NULL;
}

int REGISTER_FILESAN::Instantaneous_Activity23Activity::Rank(){
  return 1;
}

BaseActionClass* REGISTER_FILESAN::Instantaneous_Activity23Activity::Fire(){
  (*(KO_CONTENT_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity12Activity========================*/


REGISTER_FILESAN::Instantaneous_Activity12Activity::Instantaneous_Activity12Activity(){
  ActivityInitialize("Instantaneous_Activity12",1,Instantaneous , RaceEnabled, 2,1, false);
}

void REGISTER_FILESAN::Instantaneous_Activity12Activity::LinkVariables(){
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
}

bool REGISTER_FILESAN::Instantaneous_Activity12Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(OK_CONTENT_Mobius_Mark)) >=1));
  return NewEnabled;
}

double REGISTER_FILESAN::Instantaneous_Activity12Activity::Weight(){ 
  return 1;
}

bool REGISTER_FILESAN::Instantaneous_Activity12Activity::ReactivationPredicate(){ 
  return false;
}

bool REGISTER_FILESAN::Instantaneous_Activity12Activity::ReactivationFunction(){ 
  return false;
}

double REGISTER_FILESAN::Instantaneous_Activity12Activity::SampleDistribution(){
  return 0;
}

double* REGISTER_FILESAN::Instantaneous_Activity12Activity::ReturnDistributionParameters(){
    return NULL;
}

int REGISTER_FILESAN::Instantaneous_Activity12Activity::Rank(){
  return 1;
}

BaseActionClass* REGISTER_FILESAN::Instantaneous_Activity12Activity::Fire(){
  (*(OK_CONTENT_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  return this;
}

/*======================WRITE_WITH_KO_DATAActivity========================*/


REGISTER_FILESAN::WRITE_WITH_KO_DATAActivity::WRITE_WITH_KO_DATAActivity(){
  ActivityInitialize("WRITE_WITH_KO_DATA",2,Instantaneous , RaceEnabled, 3,2, false);
}

void REGISTER_FILESAN::WRITE_WITH_KO_DATAActivity::LinkVariables(){
  WRITE_REGISTER_FILE->Register(&WRITE_REGISTER_FILE_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
}

bool REGISTER_FILESAN::WRITE_WITH_KO_DATAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_REGISTER_FILE_Mobius_Mark)) >=1)&&((*(RESULT_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double REGISTER_FILESAN::WRITE_WITH_KO_DATAActivity::Weight(){ 
  return 1;
}

bool REGISTER_FILESAN::WRITE_WITH_KO_DATAActivity::ReactivationPredicate(){ 
  return false;
}

bool REGISTER_FILESAN::WRITE_WITH_KO_DATAActivity::ReactivationFunction(){ 
  return false;
}

double REGISTER_FILESAN::WRITE_WITH_KO_DATAActivity::SampleDistribution(){
  return 0;
}

double* REGISTER_FILESAN::WRITE_WITH_KO_DATAActivity::ReturnDistributionParameters(){
    return NULL;
}

int REGISTER_FILESAN::WRITE_WITH_KO_DATAActivity::Rank(){
  return 1;
}

BaseActionClass* REGISTER_FILESAN::WRITE_WITH_KO_DATAActivity::Fire(){
  (*(WRITE_REGISTER_FILE_Mobius_Mark))--;
  (*(RESULT_KO_Mobius_Mark))--;
  (*(KO_CONTENT_Mobius_Mark))++;
  return this;
}

/*======================WRITE_WITH_OK_DATAActivity========================*/


REGISTER_FILESAN::WRITE_WITH_OK_DATAActivity::WRITE_WITH_OK_DATAActivity(){
  ActivityInitialize("WRITE_WITH_OK_DATA",3,Instantaneous , RaceEnabled, 3,2, false);
}

void REGISTER_FILESAN::WRITE_WITH_OK_DATAActivity::LinkVariables(){
  WRITE_REGISTER_FILE->Register(&WRITE_REGISTER_FILE_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
}

bool REGISTER_FILESAN::WRITE_WITH_OK_DATAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WRITE_REGISTER_FILE_Mobius_Mark)) >=1)&&((*(RESULT_OK_Mobius_Mark)) >=1));
  return NewEnabled;
}

double REGISTER_FILESAN::WRITE_WITH_OK_DATAActivity::Weight(){ 
  return 1;
}

bool REGISTER_FILESAN::WRITE_WITH_OK_DATAActivity::ReactivationPredicate(){ 
  return false;
}

bool REGISTER_FILESAN::WRITE_WITH_OK_DATAActivity::ReactivationFunction(){ 
  return false;
}

double REGISTER_FILESAN::WRITE_WITH_OK_DATAActivity::SampleDistribution(){
  return 0;
}

double* REGISTER_FILESAN::WRITE_WITH_OK_DATAActivity::ReturnDistributionParameters(){
    return NULL;
}

int REGISTER_FILESAN::WRITE_WITH_OK_DATAActivity::Rank(){
  return 1;
}

BaseActionClass* REGISTER_FILESAN::WRITE_WITH_OK_DATAActivity::Fire(){
  (*(WRITE_REGISTER_FILE_Mobius_Mark))--;
  (*(RESULT_OK_Mobius_Mark))--;
  (*(OK_CONTENT_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity2Activity========================*/


REGISTER_FILESAN::Instantaneous_Activity2Activity::Instantaneous_Activity2Activity(){
  ActivityInitialize("Instantaneous_Activity2",4,Instantaneous , RaceEnabled, 3,1, false);
}

void REGISTER_FILESAN::Instantaneous_Activity2Activity::LinkVariables(){
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
  KO_READ->Register(&KO_READ_Mobius_Mark);
}

bool REGISTER_FILESAN::Instantaneous_Activity2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEMORY_KO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double REGISTER_FILESAN::Instantaneous_Activity2Activity::Weight(){ 
  return 1;
}

bool REGISTER_FILESAN::Instantaneous_Activity2Activity::ReactivationPredicate(){ 
  return false;
}

bool REGISTER_FILESAN::Instantaneous_Activity2Activity::ReactivationFunction(){ 
  return false;
}

double REGISTER_FILESAN::Instantaneous_Activity2Activity::SampleDistribution(){
  return 0;
}

double* REGISTER_FILESAN::Instantaneous_Activity2Activity::ReturnDistributionParameters(){
    return NULL;
}

int REGISTER_FILESAN::Instantaneous_Activity2Activity::Rank(){
  return 1;
}

BaseActionClass* REGISTER_FILESAN::Instantaneous_Activity2Activity::Fire(){
  (*(MEMORY_KO_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  (*(KO_READ_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case1========================*/


REGISTER_FILESAN::READ_FROMActivity_case1::READ_FROMActivity_case1(){
  ActivityInitialize("READ_FROM_case1",5,Instantaneous , RaceEnabled, 2,1, false);
}

void REGISTER_FILESAN::READ_FROMActivity_case1::LinkVariables(){
  READ_REGISTER_FILE->Register(&READ_REGISTER_FILE_Mobius_Mark);
  MEMORY_OK->Register(&MEMORY_OK_Mobius_Mark);
}

bool REGISTER_FILESAN::READ_FROMActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_REGISTER_FILE_Mobius_Mark)) >=1));
  return NewEnabled;
}

double REGISTER_FILESAN::READ_FROMActivity_case1::Weight(){ 
  return 0.5;
}

bool REGISTER_FILESAN::READ_FROMActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool REGISTER_FILESAN::READ_FROMActivity_case1::ReactivationFunction(){ 
  return false;
}

double REGISTER_FILESAN::READ_FROMActivity_case1::SampleDistribution(){
  return 0;
}

double* REGISTER_FILESAN::READ_FROMActivity_case1::ReturnDistributionParameters(){
    return NULL;
}

int REGISTER_FILESAN::READ_FROMActivity_case1::Rank(){
  return 1;
}

BaseActionClass* REGISTER_FILESAN::READ_FROMActivity_case1::Fire(){
  (*(READ_REGISTER_FILE_Mobius_Mark))--;
  (*(MEMORY_OK_Mobius_Mark))++;
  return this;
}

/*======================READ_FROMActivity_case2========================*/


REGISTER_FILESAN::READ_FROMActivity_case2::READ_FROMActivity_case2(){
  ActivityInitialize("READ_FROM_case2",5,Instantaneous , RaceEnabled, 2,1, false);
}

void REGISTER_FILESAN::READ_FROMActivity_case2::LinkVariables(){
  READ_REGISTER_FILE->Register(&READ_REGISTER_FILE_Mobius_Mark);
  MEMORY_KO->Register(&MEMORY_KO_Mobius_Mark);
}

bool REGISTER_FILESAN::READ_FROMActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(READ_REGISTER_FILE_Mobius_Mark)) >=1));
  return NewEnabled;
}

double REGISTER_FILESAN::READ_FROMActivity_case2::Weight(){ 
  return 0.5;
}

bool REGISTER_FILESAN::READ_FROMActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool REGISTER_FILESAN::READ_FROMActivity_case2::ReactivationFunction(){ 
  return false;
}

double REGISTER_FILESAN::READ_FROMActivity_case2::SampleDistribution(){
  return 0;
}

double* REGISTER_FILESAN::READ_FROMActivity_case2::ReturnDistributionParameters(){
    return NULL;
}

int REGISTER_FILESAN::READ_FROMActivity_case2::Rank(){
  return 1;
}

BaseActionClass* REGISTER_FILESAN::READ_FROMActivity_case2::Fire(){
  (*(READ_REGISTER_FILE_Mobius_Mark))--;
  (*(MEMORY_KO_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity1Activity========================*/


REGISTER_FILESAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",6,Instantaneous , RaceEnabled, 3,1, false);
}

void REGISTER_FILESAN::Instantaneous_Activity1Activity::LinkVariables(){
  MEMORY_OK->Register(&MEMORY_OK_Mobius_Mark);
  MEM_OP_COMPLETE->Register(&MEM_OP_COMPLETE_Mobius_Mark);
  OK_READ->Register(&OK_READ_Mobius_Mark);
}

bool REGISTER_FILESAN::Instantaneous_Activity1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(MEMORY_OK_Mobius_Mark)) >=1));
  return NewEnabled;
}

double REGISTER_FILESAN::Instantaneous_Activity1Activity::Weight(){ 
  return 1;
}

bool REGISTER_FILESAN::Instantaneous_Activity1Activity::ReactivationPredicate(){ 
  return false;
}

bool REGISTER_FILESAN::Instantaneous_Activity1Activity::ReactivationFunction(){ 
  return false;
}

double REGISTER_FILESAN::Instantaneous_Activity1Activity::SampleDistribution(){
  return 0;
}

double* REGISTER_FILESAN::Instantaneous_Activity1Activity::ReturnDistributionParameters(){
    return NULL;
}

int REGISTER_FILESAN::Instantaneous_Activity1Activity::Rank(){
  return 1;
}

BaseActionClass* REGISTER_FILESAN::Instantaneous_Activity1Activity::Fire(){
  (*(MEMORY_OK_Mobius_Mark))--;
  (*(MEM_OP_COMPLETE_Mobius_Mark))++;
  (*(OK_READ_Mobius_Mark))++;
  return this;
}

/*======================Instantaneous_Activity3Activity========================*/


REGISTER_FILESAN::Instantaneous_Activity3Activity::Instantaneous_Activity3Activity(){
  ActivityInitialize("Instantaneous_Activity3",7,Instantaneous , RaceEnabled, 4,2, false);
}

void REGISTER_FILESAN::Instantaneous_Activity3Activity::LinkVariables(){
  indexes->Register(&indexes_Mobius_Mark);
  REGISTERS_FILL->Register(&REGISTERS_FILL_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);

}

bool REGISTER_FILESAN::Instantaneous_Activity3Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((indexes->Mark() < size && REGISTERS_FILL->Mark() == 1));
  return NewEnabled;
}

double REGISTER_FILESAN::Instantaneous_Activity3Activity::Weight(){ 
  return 1;
}

bool REGISTER_FILESAN::Instantaneous_Activity3Activity::ReactivationPredicate(){ 
  return false;
}

bool REGISTER_FILESAN::Instantaneous_Activity3Activity::ReactivationFunction(){ 
  return false;
}

double REGISTER_FILESAN::Instantaneous_Activity3Activity::SampleDistribution(){
  return 0;
}

double* REGISTER_FILESAN::Instantaneous_Activity3Activity::ReturnDistributionParameters(){
    return NULL;
}

int REGISTER_FILESAN::Instantaneous_Activity3Activity::Rank(){
  return 1;
}

BaseActionClass* REGISTER_FILESAN::Instantaneous_Activity3Activity::Fire(){
  OK_CONTENT->Mark() += LIVE_REGISTERS->Index(indexes->Mark())->Mark();
REGISTERS_FILL->Mark() = 0;
indexes->Mark()++;
  (*(OK_CONTENT_Mobius_Mark))++;
  return this;
}

