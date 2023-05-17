

// This C++ file was created by SanEditor

#include "Atomic/WARP/WARPSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         WARPSAN Constructor             
******************************************************************/


WARPSAN::WARPSAN(){


  Activity* InitialActionList[5]={
    &DISPATCHER_Copy, //0
    &Instantaneous_Activity1, //1
    &L1_CLOCK, //2
    &L2_CLOCK, //3
    &DRAM_CLOCK  // 4
  };

  BaseGroupClass* InitialGroupList[5]={
    (BaseGroupClass*) &(DISPATCHER_Copy), 
    (BaseGroupClass*) &(Instantaneous_Activity1), 
    (BaseGroupClass*) &(L1_CLOCK), 
    (BaseGroupClass*) &(L2_CLOCK), 
    (BaseGroupClass*) &(DRAM_CLOCK)
  };

  INST_COUNTER = new Place("INST_COUNTER" ,-1);
  INSTRUCTION_READY = new Place("INSTRUCTION_READY" ,1);
  REGISTERS_FILL = new Place("REGISTERS_FILL" ,0);
  INT_ALU_FAILURE = new Place("INT_ALU_FAILURE" ,0);
  FLOAT_ALU_FAILURE = new Place("FLOAT_ALU_FAILURE" ,0);
  MEM_FAILURE = new Place("MEM_FAILURE" ,0);
  REG_FAILURE = new Place("REG_FAILURE" ,0);
  WARP_ACCESS_DRAM = new Place("WARP_ACCESS_DRAM" ,0);
  WARP_ACCESS_L2 = new Place("WARP_ACCESS_L2" ,0);
  WARP_ACCESS_L1 = new Place("WARP_ACCESS_L1" ,0);
  Place1 = new Place("Place1" ,0);
  short temp_WARPinstructionsvalue = -1;
  WARP = new instructions("WARP",temp_WARPinstructionsvalue);
  short temp_SCHEDULERshort = -1;
  SCHEDULER = new ExtendedPlace<short>("SCHEDULER",temp_SCHEDULERshort);
  short temp_FAILURE_INSTshort = failure_index;
  FAILURE_INST = new ExtendedPlace<short>("FAILURE_INST",temp_FAILURE_INSTshort);
  BaseStateVariableClass* InitialPlaces[14]={
    INST_COUNTER,  // 0
    INSTRUCTION_READY,  // 1
    REGISTERS_FILL,  // 2
    INT_ALU_FAILURE,  // 3
    FLOAT_ALU_FAILURE,  // 4
    MEM_FAILURE,  // 5
    REG_FAILURE,  // 6
    WARP_ACCESS_DRAM,  // 7
    WARP_ACCESS_L2,  // 8
    WARP_ACCESS_L1,  // 9
    Place1,  // 10
    WARP,  // 11
    SCHEDULER,  // 12
    FAILURE_INST   // 13
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("WARP", 14, InitialPlaces, 
                        0, InitialROPlaces, 
                        5, InitialActionList, 5, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[20][2]={ 
    {1,0}, {0,0}, {12,0}, {2,0}, {11,0}, {3,1}, {4,1}, {5,1}, 
    {6,1}, {1,1}, {0,1}, {12,1}, {2,1}, {11,1}, {9,2}, {10,2}, 
    {8,3}, {10,3}, {7,4}, {10,4}
  };
  for(int n=0;n<20;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[9][2]={ 
    {0,0}, {1,0}, {13,0}, {13,1}, {0,1}, {1,1}, {9,2}, {8,3}, 
    {7,4}
  };
  for(int n=0;n<9;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<5;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void WARPSAN::CustomInitialization() {
WARP->Index(0)->Mark() = 5;WARP->Index(1)->Mark() = 5;WARP->Index(2)->Mark() = 5;WARP->Index(3)->Mark() = 5;WARP->Index(4)->Mark() = 5;WARP->Index(5)->Mark() = 7;WARP->Index(6)->Mark() = 5;WARP->Index(7)->Mark() = 7;WARP->Index(8)->Mark() = 7;WARP->Index(9)->Mark() = 5;WARP->Index(10)->Mark() = 5;WARP->Index(11)->Mark() = 7;WARP->Index(12)->Mark() = 5;WARP->Index(13)->Mark() = 5;WARP->Index(14)->Mark() = 7;WARP->Index(15)->Mark() = 7;WARP->Index(16)->Mark() = 5;WARP->Index(17)->Mark() = 5;WARP->Index(18)->Mark() = 7;WARP->Index(19)->Mark() = 2;WARP->Index(20)->Mark() = 5;WARP->Index(21)->Mark() = 5;WARP->Index(22)->Mark() = 7;WARP->Index(23)->Mark() = 7;WARP->Index(24)->Mark() = 7;WARP->Index(25)->Mark() = 7;WARP->Index(26)->Mark() = 3;WARP->Index(27)->Mark() = 2;WARP->Index(28)->Mark() = 7;WARP->Index(29)->Mark() = 7;WARP->Index(30)->Mark() = 7;WARP->Index(31)->Mark() = 7;WARP->Index(32)->Mark() = 3;WARP->Index(33)->Mark() = 7;WARP->Index(34)->Mark() = 7;WARP->Index(35)->Mark() = 2;WARP->Index(36)->Mark() = 7;WARP->Index(37)->Mark() = 7;WARP->Index(38)->Mark() = 7;WARP->Index(39)->Mark() = 3;WARP->Index(40)->Mark() = 5;WARP->Index(41)->Mark() = 7;WARP->Index(42)->Mark() = 7;WARP->Index(43)->Mark() = 0;WARP->Index(44)->Mark() = 5;WARP->Index(45)->Mark() = 7;WARP->Index(46)->Mark() = 7;WARP->Index(47)->Mark() = 7;WARP->Index(48)->Mark() = 7;WARP->Index(49)->Mark() = 7;WARP->Index(50)->Mark() = 7;WARP->Index(51)->Mark() = 7;WARP->Index(52)->Mark() = 7;WARP->Index(53)->Mark() = 5;WARP->Index(54)->Mark() = 7;WARP->Index(55)->Mark() = 2;WARP->Index(56)->Mark() = 7;WARP->Index(57)->Mark() = 7;WARP->Index(58)->Mark() = 3;WARP->Index(59)->Mark() = 2;WARP->Index(60)->Mark() = 5;WARP->Index(61)->Mark() = 7;WARP->Index(62)->Mark() = 5;WARP->Index(63)->Mark() = 3;WARP->Index(64)->Mark() = 2;WARP->Index(65)->Mark() = 5;WARP->Index(66)->Mark() = 5;WARP->Index(67)->Mark() = 3;WARP->Index(68)->Mark() = 2;WARP->Index(69)->Mark() = 7;WARP->Index(70)->Mark() = 7;WARP->Index(71)->Mark() = 3;WARP->Index(72)->Mark() = 2;WARP->Index(73)->Mark() = 7;WARP->Index(74)->Mark() = 5;WARP->Index(75)->Mark() = 3;WARP->Index(76)->Mark() = 2;WARP->Index(77)->Mark() = 7;WARP->Index(78)->Mark() = 5;WARP->Index(79)->Mark() = 3;WARP->Index(80)->Mark() = 2;WARP->Index(81)->Mark() = 5;WARP->Index(82)->Mark() = 5;WARP->Index(83)->Mark() = 3;WARP->Index(84)->Mark() = 2;WARP->Index(85)->Mark() = 7;WARP->Index(86)->Mark() = 7;WARP->Index(87)->Mark() = 3;WARP->Index(88)->Mark() = 2;WARP->Index(89)->Mark() = 7;WARP->Index(90)->Mark() = 5;WARP->Index(91)->Mark() = 3;WARP->Index(92)->Mark() = 2;WARP->Index(93)->Mark() = 7;WARP->Index(94)->Mark() = 5;WARP->Index(95)->Mark() = 3;WARP->Index(96)->Mark() = 2;WARP->Index(97)->Mark() = 5;WARP->Index(98)->Mark() = 5;WARP->Index(99)->Mark() = 3;WARP->Index(100)->Mark() = 2;WARP->Index(101)->Mark() = 7;WARP->Index(102)->Mark() = 7;WARP->Index(103)->Mark() = 3;WARP->Index(104)->Mark() = 2;WARP->Index(105)->Mark() = 7;WARP->Index(106)->Mark() = 5;WARP->Index(107)->Mark() = 3;WARP->Index(108)->Mark() = 2;WARP->Index(109)->Mark() = 7;WARP->Index(110)->Mark() = 5;WARP->Index(111)->Mark() = 3;WARP->Index(112)->Mark() = 2;WARP->Index(113)->Mark() = 7;WARP->Index(114)->Mark() = 5;WARP->Index(115)->Mark() = 3;WARP->Index(116)->Mark() = 2;WARP->Index(117)->Mark() = 7;WARP->Index(118)->Mark() = 7;WARP->Index(119)->Mark() = 5;WARP->Index(120)->Mark() = 5;WARP->Index(121)->Mark() = 5;WARP->Index(122)->Mark() = 3;WARP->Index(123)->Mark() = 7;WARP->Index(124)->Mark() = 7;WARP->Index(125)->Mark() = 7;WARP->Index(126)->Mark() = 7;WARP->Index(127)->Mark() = 2;WARP->Index(128)->Mark() = 7;WARP->Index(129)->Mark() = 5;WARP->Index(130)->Mark() = 7;WARP->Index(131)->Mark() = 3;WARP->Index(132)->Mark() = 2;WARP->Index(133)->Mark() = 5;WARP->Index(134)->Mark() = 7;WARP->Index(135)->Mark() = 5;WARP->Index(136)->Mark() = 3;WARP->Index(137)->Mark() = 2;WARP->Index(138)->Mark() = 5;WARP->Index(139)->Mark() = 5;WARP->Index(140)->Mark() = 3;WARP->Index(141)->Mark() = 2;WARP->Index(142)->Mark() = 7;WARP->Index(143)->Mark() = 7;WARP->Index(144)->Mark() = 3;WARP->Index(145)->Mark() = 2;WARP->Index(146)->Mark() = 7;WARP->Index(147)->Mark() = 5;WARP->Index(148)->Mark() = 3;WARP->Index(149)->Mark() = 2;WARP->Index(150)->Mark() = 7;WARP->Index(151)->Mark() = 5;WARP->Index(152)->Mark() = 3;WARP->Index(153)->Mark() = 2;WARP->Index(154)->Mark() = 3;WARP->Index(155)->Mark() = 2;WARP->Index(156)->Mark() = 7;WARP->Index(157)->Mark() = 7;WARP->Index(158)->Mark() = 7;WARP->Index(159)->Mark() = 5;WARP->Index(160)->Mark() = 7;WARP->Index(161)->Mark() = 5;WARP->Index(162)->Mark() = 5;WARP->Index(163)->Mark() = 3;WARP->Index(164)->Mark() = 5;WARP->Index(165)->Mark() = 7;WARP->Index(166)->Mark() = 2;WARP->Index(167)->Mark() = 7;WARP->Index(168)->Mark() = 5;WARP->Index(169)->Mark() = 7;WARP->Index(170)->Mark() = 3;WARP->Index(171)->Mark() = 2;WARP->Index(172)->Mark() = 5;WARP->Index(173)->Mark() = 7;WARP->Index(174)->Mark() = 5;WARP->Index(175)->Mark() = 3;WARP->Index(176)->Mark() = 2;WARP->Index(177)->Mark() = 3;WARP->Index(178)->Mark() = 2;WARP->Index(179)->Mark() = 3;WARP->Index(180)->Mark() = 7;WARP->Index(181)->Mark() = 7;WARP->Index(182)->Mark() = 7;WARP->Index(183)->Mark() = 7;
}
WARPSAN::~WARPSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void WARPSAN::assignPlacesToActivitiesInst(){
  DISPATCHER_Copy.INST_COUNTER = (Place*) LocalStateVariables[0];
  DISPATCHER_Copy.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
  DISPATCHER_Copy.FAILURE_INST = (ExtendedPlace<short>*) LocalStateVariables[13];
  DISPATCHER_Copy.SCHEDULER = (ExtendedPlace<short>*) LocalStateVariables[12];
  DISPATCHER_Copy.REGISTERS_FILL = (Place*) LocalStateVariables[2];
  DISPATCHER_Copy.WARP = (instructions*) LocalStateVariables[11];
  Instantaneous_Activity1.FAILURE_INST = (ExtendedPlace<short>*) LocalStateVariables[13];
  Instantaneous_Activity1.INST_COUNTER = (Place*) LocalStateVariables[0];
  Instantaneous_Activity1.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
  Instantaneous_Activity1.INT_ALU_FAILURE = (Place*) LocalStateVariables[3];
  Instantaneous_Activity1.FLOAT_ALU_FAILURE = (Place*) LocalStateVariables[4];
  Instantaneous_Activity1.MEM_FAILURE = (Place*) LocalStateVariables[5];
  Instantaneous_Activity1.REG_FAILURE = (Place*) LocalStateVariables[6];
  Instantaneous_Activity1.SCHEDULER = (ExtendedPlace<short>*) LocalStateVariables[12];
  Instantaneous_Activity1.REGISTERS_FILL = (Place*) LocalStateVariables[2];
  Instantaneous_Activity1.WARP = (instructions*) LocalStateVariables[11];
  L1_CLOCK.WARP_ACCESS_L1 = (Place*) LocalStateVariables[9];
  L1_CLOCK.Place1 = (Place*) LocalStateVariables[10];
  L2_CLOCK.WARP_ACCESS_L2 = (Place*) LocalStateVariables[8];
  L2_CLOCK.Place1 = (Place*) LocalStateVariables[10];
  DRAM_CLOCK.WARP_ACCESS_DRAM = (Place*) LocalStateVariables[7];
  DRAM_CLOCK.Place1 = (Place*) LocalStateVariables[10];
}
void WARPSAN::assignPlacesToActivitiesTimed(){
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================DISPATCHER_CopyActivity========================*/


WARPSAN::DISPATCHER_CopyActivity::DISPATCHER_CopyActivity(){
  ActivityInitialize("DISPATCHER_Copy",0,Instantaneous , RaceEnabled, 5,3, false);
}

void WARPSAN::DISPATCHER_CopyActivity::LinkVariables(){
  INST_COUNTER->Register(&INST_COUNTER_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);


  REGISTERS_FILL->Register(&REGISTERS_FILL_Mobius_Mark);

}

bool WARPSAN::DISPATCHER_CopyActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((INST_COUNTER->Mark() < size-1) && (INSTRUCTION_READY->Mark() > 0) && (FAILURE_INST->Mark() != INST_COUNTER->Mark())));
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

/*======================Instantaneous_Activity1Activity========================*/


WARPSAN::Instantaneous_Activity1Activity::Instantaneous_Activity1Activity(){
  ActivityInitialize("Instantaneous_Activity1",1,Instantaneous , RaceEnabled, 9,3, false);
}

void WARPSAN::Instantaneous_Activity1Activity::LinkVariables(){

  INST_COUNTER->Register(&INST_COUNTER_Mobius_Mark);
  INSTRUCTION_READY->Register(&INSTRUCTION_READY_Mobius_Mark);
  INT_ALU_FAILURE->Register(&INT_ALU_FAILURE_Mobius_Mark);
  FLOAT_ALU_FAILURE->Register(&FLOAT_ALU_FAILURE_Mobius_Mark);
  MEM_FAILURE->Register(&MEM_FAILURE_Mobius_Mark);
  REG_FAILURE->Register(&REG_FAILURE_Mobius_Mark);

  REGISTERS_FILL->Register(&REGISTERS_FILL_Mobius_Mark);

}

bool WARPSAN::Instantaneous_Activity1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((FAILURE_INST->Mark() == INST_COUNTER->Mark()) && (INSTRUCTION_READY->Mark() == 1)));
  return NewEnabled;
}

double WARPSAN::Instantaneous_Activity1Activity::Weight(){ 
  return 1;
}

bool WARPSAN::Instantaneous_Activity1Activity::ReactivationPredicate(){ 
  return false;
}

bool WARPSAN::Instantaneous_Activity1Activity::ReactivationFunction(){ 
  return false;
}

double WARPSAN::Instantaneous_Activity1Activity::SampleDistribution(){
  return 0;
}

double* WARPSAN::Instantaneous_Activity1Activity::ReturnDistributionParameters(){
    return NULL;
}

int WARPSAN::Instantaneous_Activity1Activity::Rank(){
  return 1;
}

BaseActionClass* WARPSAN::Instantaneous_Activity1Activity::Fire(){
  INSTRUCTION_READY->Mark()--;
INST_COUNTER->Mark()++;
  SCHEDULER->Mark() = WARP->Index(INST_COUNTER->Mark())->Mark();
REGISTERS_FILL->Mark() = 1;
  (*(INT_ALU_FAILURE_Mobius_Mark))++;
  (*(FLOAT_ALU_FAILURE_Mobius_Mark))++;
  (*(MEM_FAILURE_Mobius_Mark))++;
  (*(REG_FAILURE_Mobius_Mark))++;
  return this;
}

/*======================L1_CLOCKActivity========================*/


WARPSAN::L1_CLOCKActivity::L1_CLOCKActivity(){
  ActivityInitialize("L1_CLOCK",2,Instantaneous , RaceEnabled, 2,1, false);
}

void WARPSAN::L1_CLOCKActivity::LinkVariables(){
  WARP_ACCESS_L1->Register(&WARP_ACCESS_L1_Mobius_Mark);
  Place1->Register(&Place1_Mobius_Mark);
}

bool WARPSAN::L1_CLOCKActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WARP_ACCESS_L1_Mobius_Mark)) >=1));
  return NewEnabled;
}

double WARPSAN::L1_CLOCKActivity::Weight(){ 
  return 1;
}

bool WARPSAN::L1_CLOCKActivity::ReactivationPredicate(){ 
  return false;
}

bool WARPSAN::L1_CLOCKActivity::ReactivationFunction(){ 
  return false;
}

double WARPSAN::L1_CLOCKActivity::SampleDistribution(){
  return 0;
}

double* WARPSAN::L1_CLOCKActivity::ReturnDistributionParameters(){
    return NULL;
}

int WARPSAN::L1_CLOCKActivity::Rank(){
  return 1;
}

BaseActionClass* WARPSAN::L1_CLOCKActivity::Fire(){
  (*(WARP_ACCESS_L1_Mobius_Mark))--;
  (*(Place1_Mobius_Mark))++;
  return this;
}

/*======================L2_CLOCKActivity========================*/


WARPSAN::L2_CLOCKActivity::L2_CLOCKActivity(){
  ActivityInitialize("L2_CLOCK",3,Instantaneous , RaceEnabled, 2,1, false);
}

void WARPSAN::L2_CLOCKActivity::LinkVariables(){
  WARP_ACCESS_L2->Register(&WARP_ACCESS_L2_Mobius_Mark);
  Place1->Register(&Place1_Mobius_Mark);
}

bool WARPSAN::L2_CLOCKActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WARP_ACCESS_L2_Mobius_Mark)) >=1));
  return NewEnabled;
}

double WARPSAN::L2_CLOCKActivity::Weight(){ 
  return 1;
}

bool WARPSAN::L2_CLOCKActivity::ReactivationPredicate(){ 
  return false;
}

bool WARPSAN::L2_CLOCKActivity::ReactivationFunction(){ 
  return false;
}

double WARPSAN::L2_CLOCKActivity::SampleDistribution(){
  return 0;
}

double* WARPSAN::L2_CLOCKActivity::ReturnDistributionParameters(){
    return NULL;
}

int WARPSAN::L2_CLOCKActivity::Rank(){
  return 1;
}

BaseActionClass* WARPSAN::L2_CLOCKActivity::Fire(){
  (*(WARP_ACCESS_L2_Mobius_Mark))--;
  (*(Place1_Mobius_Mark))++;
  return this;
}

/*======================DRAM_CLOCKActivity========================*/


WARPSAN::DRAM_CLOCKActivity::DRAM_CLOCKActivity(){
  ActivityInitialize("DRAM_CLOCK",4,Instantaneous , RaceEnabled, 2,1, false);
}

void WARPSAN::DRAM_CLOCKActivity::LinkVariables(){
  WARP_ACCESS_DRAM->Register(&WARP_ACCESS_DRAM_Mobius_Mark);
  Place1->Register(&Place1_Mobius_Mark);
}

bool WARPSAN::DRAM_CLOCKActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(WARP_ACCESS_DRAM_Mobius_Mark)) >=1));
  return NewEnabled;
}

double WARPSAN::DRAM_CLOCKActivity::Weight(){ 
  return 1;
}

bool WARPSAN::DRAM_CLOCKActivity::ReactivationPredicate(){ 
  return false;
}

bool WARPSAN::DRAM_CLOCKActivity::ReactivationFunction(){ 
  return false;
}

double WARPSAN::DRAM_CLOCKActivity::SampleDistribution(){
  return 0;
}

double* WARPSAN::DRAM_CLOCKActivity::ReturnDistributionParameters(){
    return NULL;
}

int WARPSAN::DRAM_CLOCKActivity::Rank(){
  return 1;
}

BaseActionClass* WARPSAN::DRAM_CLOCKActivity::Fire(){
  (*(WARP_ACCESS_DRAM_Mobius_Mark))--;
  (*(Place1_Mobius_Mark))++;
  return this;
}

