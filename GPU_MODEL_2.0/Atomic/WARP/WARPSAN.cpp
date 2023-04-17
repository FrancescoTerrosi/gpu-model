

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
  short temp_WARPinstructionsvalue = -1;
  WARP = new instructions("WARP",temp_WARPinstructionsvalue);
  short temp_SCHEDULERshort = -1;
  SCHEDULER = new ExtendedPlace<short>("SCHEDULER",temp_SCHEDULERshort);
  short temp_FAILURE_INSTshort = failure_index;
  FAILURE_INST = new ExtendedPlace<short>("FAILURE_INST",temp_FAILURE_INSTshort);
  BaseStateVariableClass* InitialPlaces[13]={
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
    WARP,  // 10
    SCHEDULER,  // 11
    FAILURE_INST   // 12
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("WARP", 13, InitialPlaces, 
                        0, InitialROPlaces, 
                        5, InitialActionList, 5, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[17][2]={ 
    {1,0}, {0,0}, {11,0}, {2,0}, {10,0}, {3,1}, {4,1}, {5,1}, 
    {6,1}, {1,1}, {0,1}, {11,1}, {2,1}, {10,1}, {9,2}, {8,3}, 
    {7,4}
  };
  for(int n=0;n<17;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[9][2]={ 
    {0,0}, {1,0}, {12,0}, {12,1}, {0,1}, {1,1}, {9,2}, {8,3}, 
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
WARP->Index(0)->Mark() = 5;WARP->Index(1)->Mark() = 5;WARP->Index(2)->Mark() = 5;WARP->Index(3)->Mark() = 5;WARP->Index(4)->Mark() = 5;WARP->Index(5)->Mark() = 7;WARP->Index(6)->Mark() = 5;WARP->Index(7)->Mark() = 7;WARP->Index(8)->Mark() = 7;WARP->Index(9)->Mark() = 5;WARP->Index(10)->Mark() = 7;WARP->Index(11)->Mark() = 7;WARP->Index(12)->Mark() = 7;WARP->Index(13)->Mark() = 7;WARP->Index(14)->Mark() = 2;WARP->Index(15)->Mark() = 2;WARP->Index(16)->Mark() = 2;WARP->Index(17)->Mark() = 7;WARP->Index(18)->Mark() = 7;WARP->Index(19)->Mark() = 7;WARP->Index(20)->Mark() = 3;WARP->Index(21)->Mark() = 2;WARP->Index(22)->Mark() = 2;WARP->Index(23)->Mark() = 7;WARP->Index(24)->Mark() = 7;WARP->Index(25)->Mark() = 7;WARP->Index(26)->Mark() = 3;WARP->Index(27)->Mark() = 2;WARP->Index(28)->Mark() = 2;WARP->Index(29)->Mark() = 7;WARP->Index(30)->Mark() = 7;WARP->Index(31)->Mark() = 7;WARP->Index(32)->Mark() = 3;WARP->Index(33)->Mark() = 2;WARP->Index(34)->Mark() = 2;WARP->Index(35)->Mark() = 7;WARP->Index(36)->Mark() = 7;WARP->Index(37)->Mark() = 7;WARP->Index(38)->Mark() = 3;WARP->Index(39)->Mark() = 2;WARP->Index(40)->Mark() = 2;WARP->Index(41)->Mark() = 7;WARP->Index(42)->Mark() = 7;WARP->Index(43)->Mark() = 7;WARP->Index(44)->Mark() = 3;WARP->Index(45)->Mark() = 2;WARP->Index(46)->Mark() = 2;WARP->Index(47)->Mark() = 7;WARP->Index(48)->Mark() = 7;WARP->Index(49)->Mark() = 7;WARP->Index(50)->Mark() = 3;WARP->Index(51)->Mark() = 2;WARP->Index(52)->Mark() = 2;WARP->Index(53)->Mark() = 7;WARP->Index(54)->Mark() = 7;WARP->Index(55)->Mark() = 7;WARP->Index(56)->Mark() = 3;WARP->Index(57)->Mark() = 2;WARP->Index(58)->Mark() = 2;WARP->Index(59)->Mark() = 0;WARP->Index(60)->Mark() = 7;WARP->Index(61)->Mark() = 7;WARP->Index(62)->Mark() = 0;WARP->Index(63)->Mark() = 7;WARP->Index(64)->Mark() = 7;WARP->Index(65)->Mark() = 6;WARP->Index(66)->Mark() = 7;WARP->Index(67)->Mark() = 6;WARP->Index(68)->Mark() = 7;WARP->Index(69)->Mark() = 7;WARP->Index(70)->Mark() = 7;WARP->Index(71)->Mark() = 3;WARP->Index(72)->Mark() = 2;WARP->Index(73)->Mark() = 2;WARP->Index(74)->Mark() = 7;WARP->Index(75)->Mark() = 7;WARP->Index(76)->Mark() = 7;WARP->Index(77)->Mark() = 3;WARP->Index(78)->Mark() = 2;WARP->Index(79)->Mark() = 2;WARP->Index(80)->Mark() = 7;WARP->Index(81)->Mark() = 7;WARP->Index(82)->Mark() = 7;WARP->Index(83)->Mark() = 3;WARP->Index(84)->Mark() = 2;WARP->Index(85)->Mark() = 2;WARP->Index(86)->Mark() = 7;WARP->Index(87)->Mark() = 7;WARP->Index(88)->Mark() = 7;WARP->Index(89)->Mark() = 3;WARP->Index(90)->Mark() = 2;WARP->Index(91)->Mark() = 2;WARP->Index(92)->Mark() = 7;WARP->Index(93)->Mark() = 7;WARP->Index(94)->Mark() = 7;WARP->Index(95)->Mark() = 3;WARP->Index(96)->Mark() = 2;WARP->Index(97)->Mark() = 2;WARP->Index(98)->Mark() = 7;WARP->Index(99)->Mark() = 7;WARP->Index(100)->Mark() = 7;WARP->Index(101)->Mark() = 3;WARP->Index(102)->Mark() = 2;WARP->Index(103)->Mark() = 2;WARP->Index(104)->Mark() = 7;WARP->Index(105)->Mark() = 7;WARP->Index(106)->Mark() = 7;WARP->Index(107)->Mark() = 3;WARP->Index(108)->Mark() = 2;WARP->Index(109)->Mark() = 2;WARP->Index(110)->Mark() = 7;WARP->Index(111)->Mark() = 7;WARP->Index(112)->Mark() = 7;WARP->Index(113)->Mark() = 3;WARP->Index(114)->Mark() = 2;WARP->Index(115)->Mark() = 2;WARP->Index(116)->Mark() = 7;WARP->Index(117)->Mark() = 7;WARP->Index(118)->Mark() = 7;WARP->Index(119)->Mark() = 7;WARP->Index(120)->Mark() = 7;WARP->Index(121)->Mark() = 3;WARP->Index(122)->Mark() = 2;WARP->Index(123)->Mark() = 2;WARP->Index(124)->Mark() = 7;WARP->Index(125)->Mark() = 7;WARP->Index(126)->Mark() = 7;WARP->Index(127)->Mark() = 3;WARP->Index(128)->Mark() = 2;WARP->Index(129)->Mark() = 2;WARP->Index(130)->Mark() = 7;WARP->Index(131)->Mark() = 7;WARP->Index(132)->Mark() = 7;WARP->Index(133)->Mark() = 3;WARP->Index(134)->Mark() = 2;WARP->Index(135)->Mark() = 2;WARP->Index(136)->Mark() = 7;WARP->Index(137)->Mark() = 7;WARP->Index(138)->Mark() = 7;WARP->Index(139)->Mark() = 3;WARP->Index(140)->Mark() = 2;WARP->Index(141)->Mark() = 2;WARP->Index(142)->Mark() = 7;WARP->Index(143)->Mark() = 7;WARP->Index(144)->Mark() = 7;WARP->Index(145)->Mark() = 3;WARP->Index(146)->Mark() = 2;WARP->Index(147)->Mark() = 2;WARP->Index(148)->Mark() = 7;WARP->Index(149)->Mark() = 7;WARP->Index(150)->Mark() = 7;WARP->Index(151)->Mark() = 3;WARP->Index(152)->Mark() = 2;WARP->Index(153)->Mark() = 2;WARP->Index(154)->Mark() = 7;WARP->Index(155)->Mark() = 7;WARP->Index(156)->Mark() = 7;WARP->Index(157)->Mark() = 3;WARP->Index(158)->Mark() = 2;WARP->Index(159)->Mark() = 2;WARP->Index(160)->Mark() = 7;WARP->Index(161)->Mark() = 7;WARP->Index(162)->Mark() = 7;WARP->Index(163)->Mark() = 3;WARP->Index(164)->Mark() = 2;WARP->Index(165)->Mark() = 2;WARP->Index(166)->Mark() = 7;WARP->Index(167)->Mark() = 7;WARP->Index(168)->Mark() = 7;WARP->Index(169)->Mark() = 7;WARP->Index(170)->Mark() = 7;WARP->Index(171)->Mark() = 3;WARP->Index(172)->Mark() = 2;WARP->Index(173)->Mark() = 2;WARP->Index(174)->Mark() = 7;WARP->Index(175)->Mark() = 7;WARP->Index(176)->Mark() = 7;WARP->Index(177)->Mark() = 3;WARP->Index(178)->Mark() = 2;WARP->Index(179)->Mark() = 2;WARP->Index(180)->Mark() = 7;WARP->Index(181)->Mark() = 7;WARP->Index(182)->Mark() = 7;WARP->Index(183)->Mark() = 3;WARP->Index(184)->Mark() = 2;WARP->Index(185)->Mark() = 2;WARP->Index(186)->Mark() = 7;WARP->Index(187)->Mark() = 7;WARP->Index(188)->Mark() = 7;WARP->Index(189)->Mark() = 3;WARP->Index(190)->Mark() = 2;WARP->Index(191)->Mark() = 2;WARP->Index(192)->Mark() = 7;WARP->Index(193)->Mark() = 7;WARP->Index(194)->Mark() = 7;WARP->Index(195)->Mark() = 3;WARP->Index(196)->Mark() = 2;WARP->Index(197)->Mark() = 2;WARP->Index(198)->Mark() = 7;WARP->Index(199)->Mark() = 7;WARP->Index(200)->Mark() = 7;WARP->Index(201)->Mark() = 3;WARP->Index(202)->Mark() = 2;WARP->Index(203)->Mark() = 2;WARP->Index(204)->Mark() = 7;WARP->Index(205)->Mark() = 7;WARP->Index(206)->Mark() = 7;WARP->Index(207)->Mark() = 3;WARP->Index(208)->Mark() = 2;WARP->Index(209)->Mark() = 2;WARP->Index(210)->Mark() = 7;WARP->Index(211)->Mark() = 7;WARP->Index(212)->Mark() = 7;WARP->Index(213)->Mark() = 3;WARP->Index(214)->Mark() = 2;WARP->Index(215)->Mark() = 2;WARP->Index(216)->Mark() = 7;WARP->Index(217)->Mark() = 7;WARP->Index(218)->Mark() = 7;WARP->Index(219)->Mark() = 3;WARP->Index(220)->Mark() = 7;WARP->Index(221)->Mark() = 7;WARP->Index(222)->Mark() = 7;WARP->Index(223)->Mark() = 7;WARP->Index(224)->Mark() = 5;WARP->Index(225)->Mark() = 5;WARP->Index(226)->Mark() = 5;WARP->Index(227)->Mark() = 5;WARP->Index(228)->Mark() = 5;WARP->Index(229)->Mark() = 7;WARP->Index(230)->Mark() = 5;WARP->Index(231)->Mark() = 7;WARP->Index(232)->Mark() = 7;WARP->Index(233)->Mark() = 5;WARP->Index(234)->Mark() = 7;WARP->Index(235)->Mark() = 7;WARP->Index(236)->Mark() = 7;WARP->Index(237)->Mark() = 7;WARP->Index(238)->Mark() = 2;WARP->Index(239)->Mark() = 2;WARP->Index(240)->Mark() = 2;WARP->Index(241)->Mark() = 7;WARP->Index(242)->Mark() = 7;WARP->Index(243)->Mark() = 7;WARP->Index(244)->Mark() = 3;WARP->Index(245)->Mark() = 2;WARP->Index(246)->Mark() = 2;WARP->Index(247)->Mark() = 7;WARP->Index(248)->Mark() = 7;WARP->Index(249)->Mark() = 7;WARP->Index(250)->Mark() = 3;WARP->Index(251)->Mark() = 2;WARP->Index(252)->Mark() = 2;WARP->Index(253)->Mark() = 7;WARP->Index(254)->Mark() = 7;WARP->Index(255)->Mark() = 7;WARP->Index(256)->Mark() = 3;WARP->Index(257)->Mark() = 2;WARP->Index(258)->Mark() = 2;WARP->Index(259)->Mark() = 7;WARP->Index(260)->Mark() = 7;WARP->Index(261)->Mark() = 7;WARP->Index(262)->Mark() = 3;WARP->Index(263)->Mark() = 2;WARP->Index(264)->Mark() = 2;WARP->Index(265)->Mark() = 7;WARP->Index(266)->Mark() = 7;WARP->Index(267)->Mark() = 7;WARP->Index(268)->Mark() = 3;WARP->Index(269)->Mark() = 2;WARP->Index(270)->Mark() = 2;WARP->Index(271)->Mark() = 7;WARP->Index(272)->Mark() = 7;WARP->Index(273)->Mark() = 7;WARP->Index(274)->Mark() = 3;WARP->Index(275)->Mark() = 2;WARP->Index(276)->Mark() = 2;WARP->Index(277)->Mark() = 7;WARP->Index(278)->Mark() = 7;WARP->Index(279)->Mark() = 7;WARP->Index(280)->Mark() = 3;WARP->Index(281)->Mark() = 2;WARP->Index(282)->Mark() = 2;WARP->Index(283)->Mark() = 0;WARP->Index(284)->Mark() = 7;WARP->Index(285)->Mark() = 7;WARP->Index(286)->Mark() = 0;WARP->Index(287)->Mark() = 7;WARP->Index(288)->Mark() = 7;WARP->Index(289)->Mark() = 6;WARP->Index(290)->Mark() = 7;WARP->Index(291)->Mark() = 6;WARP->Index(292)->Mark() = 7;WARP->Index(293)->Mark() = 7;WARP->Index(294)->Mark() = 7;WARP->Index(295)->Mark() = 3;WARP->Index(296)->Mark() = 2;WARP->Index(297)->Mark() = 2;WARP->Index(298)->Mark() = 7;WARP->Index(299)->Mark() = 7;WARP->Index(300)->Mark() = 7;WARP->Index(301)->Mark() = 3;WARP->Index(302)->Mark() = 2;WARP->Index(303)->Mark() = 2;WARP->Index(304)->Mark() = 7;WARP->Index(305)->Mark() = 7;WARP->Index(306)->Mark() = 7;WARP->Index(307)->Mark() = 3;WARP->Index(308)->Mark() = 2;WARP->Index(309)->Mark() = 2;WARP->Index(310)->Mark() = 7;WARP->Index(311)->Mark() = 7;WARP->Index(312)->Mark() = 7;WARP->Index(313)->Mark() = 3;WARP->Index(314)->Mark() = 2;WARP->Index(315)->Mark() = 2;WARP->Index(316)->Mark() = 7;WARP->Index(317)->Mark() = 7;WARP->Index(318)->Mark() = 7;WARP->Index(319)->Mark() = 3;WARP->Index(320)->Mark() = 2;WARP->Index(321)->Mark() = 2;WARP->Index(322)->Mark() = 7;WARP->Index(323)->Mark() = 7;WARP->Index(324)->Mark() = 7;WARP->Index(325)->Mark() = 3;WARP->Index(326)->Mark() = 2;WARP->Index(327)->Mark() = 2;WARP->Index(328)->Mark() = 7;WARP->Index(329)->Mark() = 7;WARP->Index(330)->Mark() = 7;WARP->Index(331)->Mark() = 3;WARP->Index(332)->Mark() = 2;WARP->Index(333)->Mark() = 2;WARP->Index(334)->Mark() = 7;WARP->Index(335)->Mark() = 7;WARP->Index(336)->Mark() = 7;WARP->Index(337)->Mark() = 3;WARP->Index(338)->Mark() = 2;WARP->Index(339)->Mark() = 2;WARP->Index(340)->Mark() = 7;WARP->Index(341)->Mark() = 7;WARP->Index(342)->Mark() = 7;WARP->Index(343)->Mark() = 7;WARP->Index(344)->Mark() = 7;WARP->Index(345)->Mark() = 3;WARP->Index(346)->Mark() = 2;WARP->Index(347)->Mark() = 2;WARP->Index(348)->Mark() = 7;WARP->Index(349)->Mark() = 7;WARP->Index(350)->Mark() = 7;WARP->Index(351)->Mark() = 3;WARP->Index(352)->Mark() = 2;WARP->Index(353)->Mark() = 2;WARP->Index(354)->Mark() = 7;WARP->Index(355)->Mark() = 7;WARP->Index(356)->Mark() = 7;WARP->Index(357)->Mark() = 3;WARP->Index(358)->Mark() = 2;WARP->Index(359)->Mark() = 2;WARP->Index(360)->Mark() = 7;WARP->Index(361)->Mark() = 7;WARP->Index(362)->Mark() = 7;WARP->Index(363)->Mark() = 3;WARP->Index(364)->Mark() = 2;WARP->Index(365)->Mark() = 2;WARP->Index(366)->Mark() = 7;WARP->Index(367)->Mark() = 7;WARP->Index(368)->Mark() = 7;WARP->Index(369)->Mark() = 3;WARP->Index(370)->Mark() = 2;WARP->Index(371)->Mark() = 2;WARP->Index(372)->Mark() = 7;WARP->Index(373)->Mark() = 7;WARP->Index(374)->Mark() = 7;WARP->Index(375)->Mark() = 3;WARP->Index(376)->Mark() = 2;WARP->Index(377)->Mark() = 2;WARP->Index(378)->Mark() = 7;WARP->Index(379)->Mark() = 7;WARP->Index(380)->Mark() = 7;WARP->Index(381)->Mark() = 3;WARP->Index(382)->Mark() = 2;WARP->Index(383)->Mark() = 2;WARP->Index(384)->Mark() = 7;WARP->Index(385)->Mark() = 7;WARP->Index(386)->Mark() = 7;WARP->Index(387)->Mark() = 3;WARP->Index(388)->Mark() = 2;WARP->Index(389)->Mark() = 2;WARP->Index(390)->Mark() = 7;WARP->Index(391)->Mark() = 7;WARP->Index(392)->Mark() = 7;WARP->Index(393)->Mark() = 7;WARP->Index(394)->Mark() = 7;WARP->Index(395)->Mark() = 3;WARP->Index(396)->Mark() = 2;WARP->Index(397)->Mark() = 2;WARP->Index(398)->Mark() = 7;WARP->Index(399)->Mark() = 7;WARP->Index(400)->Mark() = 7;WARP->Index(401)->Mark() = 3;WARP->Index(402)->Mark() = 2;WARP->Index(403)->Mark() = 2;WARP->Index(404)->Mark() = 7;WARP->Index(405)->Mark() = 7;WARP->Index(406)->Mark() = 7;WARP->Index(407)->Mark() = 3;WARP->Index(408)->Mark() = 2;WARP->Index(409)->Mark() = 2;WARP->Index(410)->Mark() = 7;WARP->Index(411)->Mark() = 7;WARP->Index(412)->Mark() = 7;WARP->Index(413)->Mark() = 3;WARP->Index(414)->Mark() = 2;WARP->Index(415)->Mark() = 2;WARP->Index(416)->Mark() = 7;WARP->Index(417)->Mark() = 7;WARP->Index(418)->Mark() = 7;WARP->Index(419)->Mark() = 3;WARP->Index(420)->Mark() = 2;WARP->Index(421)->Mark() = 2;WARP->Index(422)->Mark() = 7;WARP->Index(423)->Mark() = 7;WARP->Index(424)->Mark() = 7;WARP->Index(425)->Mark() = 3;WARP->Index(426)->Mark() = 2;WARP->Index(427)->Mark() = 2;WARP->Index(428)->Mark() = 7;WARP->Index(429)->Mark() = 7;WARP->Index(430)->Mark() = 7;WARP->Index(431)->Mark() = 3;WARP->Index(432)->Mark() = 2;WARP->Index(433)->Mark() = 2;WARP->Index(434)->Mark() = 7;WARP->Index(435)->Mark() = 7;WARP->Index(436)->Mark() = 7;WARP->Index(437)->Mark() = 3;WARP->Index(438)->Mark() = 2;WARP->Index(439)->Mark() = 2;WARP->Index(440)->Mark() = 7;WARP->Index(441)->Mark() = 7;WARP->Index(442)->Mark() = 7;WARP->Index(443)->Mark() = 3;WARP->Index(444)->Mark() = 7;WARP->Index(445)->Mark() = 7;WARP->Index(446)->Mark() = 7;WARP->Index(447)->Mark() = 7;

}
WARPSAN::~WARPSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void WARPSAN::assignPlacesToActivitiesInst(){
  DISPATCHER_Copy.INST_COUNTER = (Place*) LocalStateVariables[0];
  DISPATCHER_Copy.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
  DISPATCHER_Copy.FAILURE_INST = (ExtendedPlace<short>*) LocalStateVariables[12];
  DISPATCHER_Copy.SCHEDULER = (ExtendedPlace<short>*) LocalStateVariables[11];
  DISPATCHER_Copy.REGISTERS_FILL = (Place*) LocalStateVariables[2];
  DISPATCHER_Copy.WARP = (instructions*) LocalStateVariables[10];
  Instantaneous_Activity1.FAILURE_INST = (ExtendedPlace<short>*) LocalStateVariables[12];
  Instantaneous_Activity1.INST_COUNTER = (Place*) LocalStateVariables[0];
  Instantaneous_Activity1.INSTRUCTION_READY = (Place*) LocalStateVariables[1];
  Instantaneous_Activity1.INT_ALU_FAILURE = (Place*) LocalStateVariables[3];
  Instantaneous_Activity1.FLOAT_ALU_FAILURE = (Place*) LocalStateVariables[4];
  Instantaneous_Activity1.MEM_FAILURE = (Place*) LocalStateVariables[5];
  Instantaneous_Activity1.REG_FAILURE = (Place*) LocalStateVariables[6];
  Instantaneous_Activity1.SCHEDULER = (ExtendedPlace<short>*) LocalStateVariables[11];
  Instantaneous_Activity1.REGISTERS_FILL = (Place*) LocalStateVariables[2];
  Instantaneous_Activity1.WARP = (instructions*) LocalStateVariables[10];
  L1_CLOCK.WARP_ACCESS_L1 = (Place*) LocalStateVariables[9];
  L2_CLOCK.WARP_ACCESS_L2 = (Place*) LocalStateVariables[8];
  DRAM_CLOCK.WARP_ACCESS_DRAM = (Place*) LocalStateVariables[7];
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
  ActivityInitialize("L1_CLOCK",2,Instantaneous , RaceEnabled, 1,1, false);
}

void WARPSAN::L1_CLOCKActivity::LinkVariables(){
  WARP_ACCESS_L1->Register(&WARP_ACCESS_L1_Mobius_Mark);
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
  return this;
}

/*======================L2_CLOCKActivity========================*/


WARPSAN::L2_CLOCKActivity::L2_CLOCKActivity(){
  ActivityInitialize("L2_CLOCK",3,Instantaneous , RaceEnabled, 1,1, false);
}

void WARPSAN::L2_CLOCKActivity::LinkVariables(){
  WARP_ACCESS_L2->Register(&WARP_ACCESS_L2_Mobius_Mark);
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
  return this;
}

/*======================DRAM_CLOCKActivity========================*/


WARPSAN::DRAM_CLOCKActivity::DRAM_CLOCKActivity(){
  ActivityInitialize("DRAM_CLOCK",4,Instantaneous , RaceEnabled, 1,1, false);
}

void WARPSAN::DRAM_CLOCKActivity::LinkVariables(){
  WARP_ACCESS_DRAM->Register(&WARP_ACCESS_DRAM_Mobius_Mark);
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
  return this;
}

