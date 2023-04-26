

// This C++ file was created by SanEditor

#include "Atomic/REGISTER_FILE/REGISTER_FILESAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         REGISTER_FILESAN Constructor             
******************************************************************/


REGISTER_FILESAN::REGISTER_FILESAN(){


  Instantaneous_Activity1Group.initialize(2, "Instantaneous_Activity1Group");
  Instantaneous_Activity1Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity1_case1);
  Instantaneous_Activity1Group.appendGroup((BaseGroupClass*) &Instantaneous_Activity1_case2);

  Activity* InitialActionList[3]={
    &Instantaneous_Activity3, //0
    &Instantaneous_Activity1_case1, //1
    &Instantaneous_Activity1_case2  // 2
  };

  BaseGroupClass* InitialGroupList[2]={
    (BaseGroupClass*) &(Instantaneous_Activity3), 
    (BaseGroupClass*) &(Instantaneous_Activity1Group)
  };

  indexes = new Place("indexes" ,-1);
  REGISTERS_FILL = new Place("REGISTERS_FILL" ,0);
  OK_CONTENT = new Place("OK_CONTENT" ,0);
  KO_CONTENT = new Place("KO_CONTENT" ,0);
  RESULT_OK = new Place("RESULT_OK" ,0);
  RESULT_KO = new Place("RESULT_KO" ,0);
  REG_FAILURE = new Place("REG_FAILURE" ,0);
  short temp_LIVE_REGISTERSregisters_countervalue = 0;
  LIVE_REGISTERS = new registers_counter("LIVE_REGISTERS",temp_LIVE_REGISTERSregisters_countervalue);
  BaseStateVariableClass* InitialPlaces[8]={
    indexes,  // 0
    REGISTERS_FILL,  // 1
    OK_CONTENT,  // 2
    KO_CONTENT,  // 3
    RESULT_OK,  // 4
    RESULT_KO,  // 5
    REG_FAILURE,  // 6
    LIVE_REGISTERS   // 7
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("REGISTER_FILE", 8, InitialPlaces, 
                        0, InitialROPlaces, 
                        3, InitialActionList, 2, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[11][2]={ 
    {1,0}, {0,0}, {4,0}, {5,0}, {2,0}, {3,0}, {7,0}, {6,1}, {6,2}, 
    {2,2}, {3,2}
  };
  for(int n=0;n<11;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[5][2]={ 
    {0,0}, {1,0}, {6,0}, {6,1}, {6,2}
  };
  for(int n=0;n<5;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<3;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void REGISTER_FILESAN::CustomInitialization() {
LIVE_REGISTERS->Index(0)->Mark() = 0;LIVE_REGISTERS->Index(1)->Mark() = 0;LIVE_REGISTERS->Index(2)->Mark() = 0;LIVE_REGISTERS->Index(3)->Mark() = 0;LIVE_REGISTERS->Index(4)->Mark() = 0;LIVE_REGISTERS->Index(5)->Mark() = 1;LIVE_REGISTERS->Index(6)->Mark() = 1;LIVE_REGISTERS->Index(7)->Mark() = 1;LIVE_REGISTERS->Index(8)->Mark() = 1;LIVE_REGISTERS->Index(9)->Mark() = 1;LIVE_REGISTERS->Index(10)->Mark() = 1;LIVE_REGISTERS->Index(11)->Mark() = 0;LIVE_REGISTERS->Index(12)->Mark() = 0;LIVE_REGISTERS->Index(13)->Mark() = 0;LIVE_REGISTERS->Index(14)->Mark() = 0;LIVE_REGISTERS->Index(15)->Mark() = 0;LIVE_REGISTERS->Index(16)->Mark() = 1;LIVE_REGISTERS->Index(17)->Mark() = 0;LIVE_REGISTERS->Index(18)->Mark() = 0;LIVE_REGISTERS->Index(19)->Mark() = 0;LIVE_REGISTERS->Index(20)->Mark() = 0;LIVE_REGISTERS->Index(21)->Mark() = 1;LIVE_REGISTERS->Index(22)->Mark() = 0;LIVE_REGISTERS->Index(23)->Mark() = 0;LIVE_REGISTERS->Index(24)->Mark() = 1;LIVE_REGISTERS->Index(25)->Mark() = 1;LIVE_REGISTERS->Index(26)->Mark() = 0;LIVE_REGISTERS->Index(27)->Mark() = 0;LIVE_REGISTERS->Index(28)->Mark() = 0;LIVE_REGISTERS->Index(29)->Mark() = 0;LIVE_REGISTERS->Index(30)->Mark() = 0;LIVE_REGISTERS->Index(31)->Mark() = 0;LIVE_REGISTERS->Index(32)->Mark() = 1;LIVE_REGISTERS->Index(33)->Mark() = 0;LIVE_REGISTERS->Index(34)->Mark() = 0;LIVE_REGISTERS->Index(35)->Mark() = -1;LIVE_REGISTERS->Index(36)->Mark() = 1;LIVE_REGISTERS->Index(37)->Mark() = 0;LIVE_REGISTERS->Index(38)->Mark() = 1;LIVE_REGISTERS->Index(39)->Mark() = 0;LIVE_REGISTERS->Index(40)->Mark() = 1;LIVE_REGISTERS->Index(41)->Mark() = 0;LIVE_REGISTERS->Index(42)->Mark() = 1;LIVE_REGISTERS->Index(43)->Mark() = 1;LIVE_REGISTERS->Index(44)->Mark() = 0;LIVE_REGISTERS->Index(45)->Mark() = 0;LIVE_REGISTERS->Index(46)->Mark() = 0;LIVE_REGISTERS->Index(47)->Mark() = 0;LIVE_REGISTERS->Index(48)->Mark() = 1;LIVE_REGISTERS->Index(49)->Mark() = 0;LIVE_REGISTERS->Index(50)->Mark() = 0;LIVE_REGISTERS->Index(51)->Mark() = 0;LIVE_REGISTERS->Index(52)->Mark() = 0;LIVE_REGISTERS->Index(53)->Mark() = 0;LIVE_REGISTERS->Index(54)->Mark() = 0;LIVE_REGISTERS->Index(55)->Mark() = 0;LIVE_REGISTERS->Index(56)->Mark() = -3;LIVE_REGISTERS->Index(57)->Mark() = 0;LIVE_REGISTERS->Index(58)->Mark() = 0;LIVE_REGISTERS->Index(59)->Mark() = 0;LIVE_REGISTERS->Index(60)->Mark() = 0;LIVE_REGISTERS->Index(61)->Mark() = 0;LIVE_REGISTERS->Index(62)->Mark() = 1;LIVE_REGISTERS->Index(63)->Mark() = 0;LIVE_REGISTERS->Index(64)->Mark() = 0;LIVE_REGISTERS->Index(65)->Mark() = 0;LIVE_REGISTERS->Index(66)->Mark() = 0;LIVE_REGISTERS->Index(67)->Mark() = 0;LIVE_REGISTERS->Index(68)->Mark() = 0;LIVE_REGISTERS->Index(69)->Mark() = 0;LIVE_REGISTERS->Index(70)->Mark() = 0;LIVE_REGISTERS->Index(71)->Mark() = 0;LIVE_REGISTERS->Index(72)->Mark() = 0;LIVE_REGISTERS->Index(73)->Mark() = 0;LIVE_REGISTERS->Index(74)->Mark() = -5;LIVE_REGISTERS->Index(75)->Mark() = 1;LIVE_REGISTERS->Index(76)->Mark() = 0;LIVE_REGISTERS->Index(77)->Mark() = 0;LIVE_REGISTERS->Index(78)->Mark() = -1;LIVE_REGISTERS->Index(79)->Mark() = 0;LIVE_REGISTERS->Index(80)->Mark() = -2;LIVE_REGISTERS->Index(81)->Mark() = -1;LIVE_REGISTERS->Index(82)->Mark() = 0;LIVE_REGISTERS->Index(83)->Mark() = -1;LIVE_REGISTERS->Index(84)->Mark() = 0;LIVE_REGISTERS->Index(85)->Mark() = -1;LIVE_REGISTERS->Index(86)->Mark() = 0;LIVE_REGISTERS->Index(87)->Mark() = -1;LIVE_REGISTERS->Index(88)->Mark() = -1;LIVE_REGISTERS->Index(89)->Mark() = 0;LIVE_REGISTERS->Index(90)->Mark() = 0;LIVE_REGISTERS->Index(91)->Mark() = 1;LIVE_REGISTERS->Index(92)->Mark() = 0;LIVE_REGISTERS->Index(93)->Mark() = -3;LIVE_REGISTERS->Index(94)->Mark() = -1;LIVE_REGISTERS->Index(95)->Mark() = 0;LIVE_REGISTERS->Index(96)->Mark() = 1;LIVE_REGISTERS->Index(97)->Mark() = 0;LIVE_REGISTERS->Index(98)->Mark() = -1;LIVE_REGISTERS->Index(99)->Mark() = -7;LIVE_REGISTERS->Index(100)->Mark() = -4;LIVE_REGISTERS->Index(101)->Mark() = 0;LIVE_REGISTERS->Index(102)->Mark() = 0;LIVE_REGISTERS->Index(103)->Mark() = 0;
}
REGISTER_FILESAN::~REGISTER_FILESAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void REGISTER_FILESAN::assignPlacesToActivitiesInst(){
  Instantaneous_Activity3.indexes = (Place*) LocalStateVariables[0];
  Instantaneous_Activity3.REGISTERS_FILL = (Place*) LocalStateVariables[1];
  Instantaneous_Activity3.REG_FAILURE = (Place*) LocalStateVariables[6];
  Instantaneous_Activity3.RESULT_OK = (Place*) LocalStateVariables[4];
  Instantaneous_Activity3.RESULT_KO = (Place*) LocalStateVariables[5];
  Instantaneous_Activity3.OK_CONTENT = (Place*) LocalStateVariables[2];
  Instantaneous_Activity3.KO_CONTENT = (Place*) LocalStateVariables[3];
  Instantaneous_Activity3.LIVE_REGISTERS = (registers_counter*) LocalStateVariables[7];
  Instantaneous_Activity1_case1.REG_FAILURE = (Place*) LocalStateVariables[6];
  Instantaneous_Activity1_case2.REG_FAILURE = (Place*) LocalStateVariables[6];
  Instantaneous_Activity1_case2.OK_CONTENT = (Place*) LocalStateVariables[2];
  Instantaneous_Activity1_case2.KO_CONTENT = (Place*) LocalStateVariables[3];
}
void REGISTER_FILESAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================Instantaneous_Activity3Activity========================*/


REGISTER_FILESAN::Instantaneous_Activity3Activity::Instantaneous_Activity3Activity(){
  ActivityInitialize("Instantaneous_Activity3",0,Instantaneous , RaceEnabled, 7,3, false);
}

void REGISTER_FILESAN::Instantaneous_Activity3Activity::LinkVariables(){
  indexes->Register(&indexes_Mobius_Mark);
  REGISTERS_FILL->Register(&REGISTERS_FILL_Mobius_Mark);
  REG_FAILURE->Register(&REG_FAILURE_Mobius_Mark);
  RESULT_OK->Register(&RESULT_OK_Mobius_Mark);
  RESULT_KO->Register(&RESULT_KO_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);

}

bool REGISTER_FILESAN::Instantaneous_Activity3Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((indexes->Mark() < size-1 && REGISTERS_FILL->Mark() == 1 && REG_FAILURE->Mark() == 0));
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
  REGISTERS_FILL->Mark() = 0;
indexes->Mark()++;
  if (RESULT_OK->Mark() == 0 && RESULT_KO->Mark() == 0) {

	OK_CONTENT->Mark() += LIVE_REGISTERS->Index(indexes->Mark())->Mark();

} else if (RESULT_OK->Mark() > 0) {

	OK_CONTENT->Mark() += LIVE_REGISTERS->Index(indexes->Mark())->Mark();
	RESULT_OK->Mark()--;


} else if (RESULT_KO->Mark() > 0) {

	KO_CONTENT->Mark() += LIVE_REGISTERS->Index(indexes->Mark())->Mark();
	RESULT_KO->Mark()--;


} else {

	OK_CONTENT->Mark() += LIVE_REGISTERS->Index(indexes->Mark())->Mark();

}
  return this;
}

/*======================Instantaneous_Activity1Activity_case1========================*/


REGISTER_FILESAN::Instantaneous_Activity1Activity_case1::Instantaneous_Activity1Activity_case1(){
  ActivityInitialize("Instantaneous_Activity1_case1",1,Instantaneous , RaceEnabled, 1,1, false);
}

void REGISTER_FILESAN::Instantaneous_Activity1Activity_case1::LinkVariables(){
  REG_FAILURE->Register(&REG_FAILURE_Mobius_Mark);
}

bool REGISTER_FILESAN::Instantaneous_Activity1Activity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(REG_FAILURE_Mobius_Mark)) >=1));
  return NewEnabled;
}

double REGISTER_FILESAN::Instantaneous_Activity1Activity_case1::Weight(){ 
  return 0.5;
}

bool REGISTER_FILESAN::Instantaneous_Activity1Activity_case1::ReactivationPredicate(){ 
  return false;
}

bool REGISTER_FILESAN::Instantaneous_Activity1Activity_case1::ReactivationFunction(){ 
  return false;
}

double REGISTER_FILESAN::Instantaneous_Activity1Activity_case1::SampleDistribution(){
  return 0;
}

double* REGISTER_FILESAN::Instantaneous_Activity1Activity_case1::ReturnDistributionParameters(){
    return NULL;
}

int REGISTER_FILESAN::Instantaneous_Activity1Activity_case1::Rank(){
  return 1;
}

BaseActionClass* REGISTER_FILESAN::Instantaneous_Activity1Activity_case1::Fire(){
  (*(REG_FAILURE_Mobius_Mark))--;
  return this;
}

/*======================Instantaneous_Activity1Activity_case2========================*/


REGISTER_FILESAN::Instantaneous_Activity1Activity_case2::Instantaneous_Activity1Activity_case2(){
  ActivityInitialize("Instantaneous_Activity1_case2",1,Instantaneous , RaceEnabled, 3,1, false);
}

void REGISTER_FILESAN::Instantaneous_Activity1Activity_case2::LinkVariables(){
  REG_FAILURE->Register(&REG_FAILURE_Mobius_Mark);
  OK_CONTENT->Register(&OK_CONTENT_Mobius_Mark);
  KO_CONTENT->Register(&KO_CONTENT_Mobius_Mark);
}

bool REGISTER_FILESAN::Instantaneous_Activity1Activity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(REG_FAILURE_Mobius_Mark)) >=1));
  return NewEnabled;
}

double REGISTER_FILESAN::Instantaneous_Activity1Activity_case2::Weight(){ 
  return 0.5;
}

bool REGISTER_FILESAN::Instantaneous_Activity1Activity_case2::ReactivationPredicate(){ 
  return false;
}

bool REGISTER_FILESAN::Instantaneous_Activity1Activity_case2::ReactivationFunction(){ 
  return false;
}

double REGISTER_FILESAN::Instantaneous_Activity1Activity_case2::SampleDistribution(){
  return 0;
}

double* REGISTER_FILESAN::Instantaneous_Activity1Activity_case2::ReturnDistributionParameters(){
    return NULL;
}

int REGISTER_FILESAN::Instantaneous_Activity1Activity_case2::Rank(){
  return 1;
}

BaseActionClass* REGISTER_FILESAN::Instantaneous_Activity1Activity_case2::Fire(){
  (*(REG_FAILURE_Mobius_Mark))--;
  OK_CONTENT->Mark()--;
KO_CONTENT->Mark()++;
  return this;
}

