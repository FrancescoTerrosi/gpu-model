

// This C++ file was created by SanEditor

#include "Atomic/WARP/WARPSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         WARPSAN Constructor             
******************************************************************/


WARPSAN::WARPSAN(){


  Activity* InitialActionList[1]={
    &DISPATCHER_Copy  // 0
  };

  BaseGroupClass* InitialGroupList[1]={
    (BaseGroupClass*) &(DISPATCHER_Copy)
  };

  INST_COUNTER = new Place("INST_COUNTER" ,-1);
  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  REGISTERS_FILL = new Place("REGISTERS_FILL" ,0);
  short temp_WARPinstructionsvalue = -1;
  WARP = new instructions("WARP",temp_WARPinstructionsvalue);
  short temp_SCHEDULERshort = -1;
  SCHEDULER = new ExtendedPlace<short>("SCHEDULER",temp_SCHEDULERshort);
  BaseStateVariableClass* InitialPlaces[5]={
    INST_COUNTER,  // 0
    INSTRUCTION_READY,  // 1
    REGISTERS_FILL,  // 2
    WARP,  // 3
    SCHEDULER   // 4
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("WARP", 5, InitialPlaces, 
                        0, InitialROPlaces, 
                        1, InitialActionList, 1, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[5][2]={ 
    {1,0}, {0,0}, {4,0}, {2,0}, {3,0}
  };
  for(int n=0;n<5;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[2][2]={ 
    {0,0}, {1,0}
  };
  for(int n=0;n<2;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<1;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void WARPSAN::CustomInitialization() {
WARP->Index(0)->Mark() = 5;WARP->Index(1)->Mark() = 5;WARP->Index(2)->Mark() = 5;WARP->Index(3)->Mark() = 7;WARP->Index(4)->Mark() = 5;WARP->Index(5)->Mark() = 2;WARP->Index(6)->Mark() = 5;WARP->Index(7)->Mark() = 7;WARP->Index(8)->Mark() = 5;WARP->Index(9)->Mark() = 5;WARP->Index(10)->Mark() = 5;WARP->Index(11)->Mark() = 5;WARP->Index(12)->Mark() = 7;WARP->Index(13)->Mark() = 7;WARP->Index(14)->Mark() = 7;WARP->Index(15)->Mark() = 5;WARP->Index(16)->Mark() = 7;WARP->Index(17)->Mark() = 7;WARP->Index(18)->Mark() = 7;WARP->Index(19)->Mark() = 0;WARP->Index(20)->Mark() = 0;WARP->Index(21)->Mark() = 7;WARP->Index(22)->Mark() = 1;WARP->Index(23)->Mark() = 7;WARP->Index(24)->Mark() = 2;WARP->Index(25)->Mark() = 7;WARP->Index(26)->Mark() = 7;WARP->Index(27)->Mark() = 7;WARP->Index(28)->Mark() = 7;WARP->Index(29)->Mark() = 7;WARP->Index(30)->Mark() = 5;WARP->Index(31)->Mark() = 2;WARP->Index(32)->Mark() = 5;WARP->Index(33)->Mark() = 7;WARP->Index(34)->Mark() = 5;WARP->Index(35)->Mark() = 5;WARP->Index(36)->Mark() = 5;WARP->Index(37)->Mark() = 5;WARP->Index(38)->Mark() = 7;WARP->Index(39)->Mark() = 7;WARP->Index(40)->Mark() = 7;WARP->Index(41)->Mark() = 5;WARP->Index(42)->Mark() = 7;WARP->Index(43)->Mark() = 7;WARP->Index(44)->Mark() = 7;WARP->Index(45)->Mark() = 0;WARP->Index(46)->Mark() = 0;WARP->Index(47)->Mark() = 7;WARP->Index(48)->Mark() = 1;WARP->Index(49)->Mark() = 7;WARP->Index(50)->Mark() = 2;WARP->Index(51)->Mark() = 7;WARP->Index(52)->Mark() = 7;WARP->Index(53)->Mark() = 7;WARP->Index(54)->Mark() = 7;WARP->Index(55)->Mark() = 7;WARP->Index(56)->Mark() = 5;WARP->Index(57)->Mark() = 2;WARP->Index(58)->Mark() = 5;WARP->Index(59)->Mark() = 7;WARP->Index(60)->Mark() = 5;WARP->Index(61)->Mark() = 5;WARP->Index(62)->Mark() = 5;WARP->Index(63)->Mark() = 5;WARP->Index(64)->Mark() = 7;WARP->Index(65)->Mark() = 7;WARP->Index(66)->Mark() = 7;WARP->Index(67)->Mark() = 5;WARP->Index(68)->Mark() = 7;WARP->Index(69)->Mark() = 7;WARP->Index(70)->Mark() = 7;WARP->Index(71)->Mark() = 0;WARP->Index(72)->Mark() = 0;WARP->Index(73)->Mark() = 7;WARP->Index(74)->Mark() = 1;WARP->Index(75)->Mark() = 7;WARP->Index(76)->Mark() = 2;WARP->Index(77)->Mark() = 7;WARP->Index(78)->Mark() = 7;WARP->Index(79)->Mark() = 7;WARP->Index(80)->Mark() = 7;WARP->Index(81)->Mark() = 7;WARP->Index(82)->Mark() = 5;WARP->Index(83)->Mark() = 2;WARP->Index(84)->Mark() = 5;WARP->Index(85)->Mark() = 7;WARP->Index(86)->Mark() = 5;WARP->Index(87)->Mark() = 5;WARP->Index(88)->Mark() = 5;WARP->Index(89)->Mark() = 5;WARP->Index(90)->Mark() = 7;WARP->Index(91)->Mark() = 7;WARP->Index(92)->Mark() = 7;WARP->Index(93)->Mark() = 5;WARP->Index(94)->Mark() = 7;WARP->Index(95)->Mark() = 7;WARP->Index(96)->Mark() = 7;WARP->Index(97)->Mark() = 0;WARP->Index(98)->Mark() = 0;WARP->Index(99)->Mark() = 7;WARP->Index(100)->Mark() = 1;WARP->Index(101)->Mark() = 7;WARP->Index(102)->Mark() = 2;WARP->Index(103)->Mark() = 7;WARP->Index(104)->Mark() = 7;WARP->Index(105)->Mark() = 7;WARP->Index(106)->Mark() = 7;
}
WARPSAN::~WARPSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void WARPSAN::assignPlacesToActivitiesInst(){
  DISPATCHER_Copy.INST_COUNTER = (Place*) LocalStateVariables[0];
  DISPATCHER_Copy.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
  DISPATCHER_Copy.SCHEDULER = (ExtendedPlace<short>*) LocalStateVariables[4];
  DISPATCHER_Copy.REGISTERS_FILL = (Place*) LocalStateVariables[2];
  DISPATCHER_Copy.WARP = (instructions*) LocalStateVariables[3];
}
void WARPSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================DISPATCHER_CopyActivity========================*/


WARPSAN::DISPATCHER_CopyActivity::DISPATCHER_CopyActivity(){
  ActivityInitialize("DISPATCHER_Copy",0,Instantaneous , RaceEnabled, 5,2, false);
}

void WARPSAN::DISPATCHER_CopyActivity::LinkVariables(){
  INST_COUNTER->Register(&INST_COUNTER_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);

  REGISTERS_FILL->Register(&REGISTERS_FILL_Mobius_Mark);

}

bool WARPSAN::DISPATCHER_CopyActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((INST_COUNTER->Mark() < size-1) && (INSTRUCTION_READY->Mark() > 0)));
  return NewEnabled;
}

double WARPSAN::DISPATCHER_CopyActivity::Weight(){ 
  return 1;
}

bool WARPSAN::DISPATCHER_CopyActivity::ReactivationPredicate(){ 
  return false;
}

bool WARPSAN::DISPATCHER_CopyActivity::ReactivationFunction(){ 
  return false;
}

double WARPSAN::DISPATCHER_CopyActivity::SampleDistribution(){
  return 0;
}

double* WARPSAN::DISPATCHER_CopyActivity::ReturnDistributionParameters(){
    return NULL;
}

int WARPSAN::DISPATCHER_CopyActivity::Rank(){
  return 1;
}

BaseActionClass* WARPSAN::DISPATCHER_CopyActivity::Fire(){
  INSTRUCTION_READY->Mark()--;
INST_COUNTER->Mark()++;
  SCHEDULER->Mark() = WARP->Index(INST_COUNTER->Mark())->Mark();
REGISTERS_FILL->Mark() = 1;
  return this;
}

