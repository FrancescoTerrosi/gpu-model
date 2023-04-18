

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
WARP->Index(0)->Mark() = 5;WARP->Index(1)->Mark() = 5;WARP->Index(2)->Mark() = 5;WARP->Index(3)->Mark() = 5;WARP->Index(4)->Mark() = 5;WARP->Index(5)->Mark() = 7;WARP->Index(6)->Mark() = 5;WARP->Index(7)->Mark() = 7;WARP->Index(8)->Mark() = 7;WARP->Index(9)->Mark() = 5;WARP->Index(10)->Mark() = 7;WARP->Index(11)->Mark() = 7;WARP->Index(12)->Mark() = 7;WARP->Index(13)->Mark() = 7;WARP->Index(14)->Mark() = 2;WARP->Index(15)->Mark() = 2;WARP->Index(16)->Mark() = 2;WARP->Index(17)->Mark() = 7;WARP->Index(18)->Mark() = 7;WARP->Index(19)->Mark() = 7;WARP->Index(20)->Mark() = 3;WARP->Index(21)->Mark() = 2;WARP->Index(22)->Mark() = 2;WARP->Index(23)->Mark() = 7;WARP->Index(24)->Mark() = 7;WARP->Index(25)->Mark() = 7;WARP->Index(26)->Mark() = 3;WARP->Index(27)->Mark() = 2;WARP->Index(28)->Mark() = 2;WARP->Index(29)->Mark() = 7;WARP->Index(30)->Mark() = 7;WARP->Index(31)->Mark() = 7;WARP->Index(32)->Mark() = 3;WARP->Index(33)->Mark() = 2;WARP->Index(34)->Mark() = 2;WARP->Index(35)->Mark() = 7;WARP->Index(36)->Mark() = 7;WARP->Index(37)->Mark() = 7;WARP->Index(38)->Mark() = 3;WARP->Index(39)->Mark() = 2;WARP->Index(40)->Mark() = 2;WARP->Index(41)->Mark() = 7;WARP->Index(42)->Mark() = 7;WARP->Index(43)->Mark() = 7;WARP->Index(44)->Mark() = 3;WARP->Index(45)->Mark() = 2;WARP->Index(46)->Mark() = 2;WARP->Index(47)->Mark() = 7;WARP->Index(48)->Mark() = 7;WARP->Index(49)->Mark() = 7;WARP->Index(50)->Mark() = 3;WARP->Index(51)->Mark() = 2;WARP->Index(52)->Mark() = 2;WARP->Index(53)->Mark() = 7;WARP->Index(54)->Mark() = 7;WARP->Index(55)->Mark() = 7;WARP->Index(56)->Mark() = 3;WARP->Index(57)->Mark() = 2;WARP->Index(58)->Mark() = 2;WARP->Index(59)->Mark() = 0;WARP->Index(60)->Mark() = 7;WARP->Index(61)->Mark() = 7;WARP->Index(62)->Mark() = 0;WARP->Index(63)->Mark() = 7;WARP->Index(64)->Mark() = 7;WARP->Index(65)->Mark() = 6;WARP->Index(66)->Mark() = 7;WARP->Index(67)->Mark() = 6;WARP->Index(68)->Mark() = 7;WARP->Index(69)->Mark() = 7;WARP->Index(70)->Mark() = 7;WARP->Index(71)->Mark() = 3;WARP->Index(72)->Mark() = 2;WARP->Index(73)->Mark() = 2;WARP->Index(74)->Mark() = 7;WARP->Index(75)->Mark() = 7;WARP->Index(76)->Mark() = 7;WARP->Index(77)->Mark() = 3;WARP->Index(78)->Mark() = 2;WARP->Index(79)->Mark() = 2;WARP->Index(80)->Mark() = 7;WARP->Index(81)->Mark() = 7;WARP->Index(82)->Mark() = 7;WARP->Index(83)->Mark() = 3;WARP->Index(84)->Mark() = 2;WARP->Index(85)->Mark() = 2;WARP->Index(86)->Mark() = 7;WARP->Index(87)->Mark() = 7;WARP->Index(88)->Mark() = 7;WARP->Index(89)->Mark() = 3;WARP->Index(90)->Mark() = 2;WARP->Index(91)->Mark() = 2;WARP->Index(92)->Mark() = 7;WARP->Index(93)->Mark() = 7;WARP->Index(94)->Mark() = 7;WARP->Index(95)->Mark() = 3;WARP->Index(96)->Mark() = 2;WARP->Index(97)->Mark() = 2;WARP->Index(98)->Mark() = 7;WARP->Index(99)->Mark() = 7;WARP->Index(100)->Mark() = 7;WARP->Index(101)->Mark() = 3;WARP->Index(102)->Mark() = 2;WARP->Index(103)->Mark() = 2;WARP->Index(104)->Mark() = 7;WARP->Index(105)->Mark() = 7;WARP->Index(106)->Mark() = 7;WARP->Index(107)->Mark() = 3;WARP->Index(108)->Mark() = 2;WARP->Index(109)->Mark() = 2;WARP->Index(110)->Mark() = 7;WARP->Index(111)->Mark() = 7;WARP->Index(112)->Mark() = 7;WARP->Index(113)->Mark() = 3;WARP->Index(114)->Mark() = 2;WARP->Index(115)->Mark() = 2;WARP->Index(116)->Mark() = 7;WARP->Index(117)->Mark() = 7;WARP->Index(118)->Mark() = 7;WARP->Index(119)->Mark() = 7;WARP->Index(120)->Mark() = 7;WARP->Index(121)->Mark() = 3;WARP->Index(122)->Mark() = 2;WARP->Index(123)->Mark() = 2;WARP->Index(124)->Mark() = 7;WARP->Index(125)->Mark() = 7;WARP->Index(126)->Mark() = 7;WARP->Index(127)->Mark() = 3;WARP->Index(128)->Mark() = 2;WARP->Index(129)->Mark() = 2;WARP->Index(130)->Mark() = 7;WARP->Index(131)->Mark() = 7;WARP->Index(132)->Mark() = 7;WARP->Index(133)->Mark() = 3;WARP->Index(134)->Mark() = 2;WARP->Index(135)->Mark() = 2;WARP->Index(136)->Mark() = 7;WARP->Index(137)->Mark() = 7;WARP->Index(138)->Mark() = 7;WARP->Index(139)->Mark() = 3;WARP->Index(140)->Mark() = 2;WARP->Index(141)->Mark() = 2;WARP->Index(142)->Mark() = 7;WARP->Index(143)->Mark() = 7;WARP->Index(144)->Mark() = 7;WARP->Index(145)->Mark() = 3;WARP->Index(146)->Mark() = 2;WARP->Index(147)->Mark() = 2;WARP->Index(148)->Mark() = 7;WARP->Index(149)->Mark() = 7;WARP->Index(150)->Mark() = 7;WARP->Index(151)->Mark() = 3;WARP->Index(152)->Mark() = 2;WARP->Index(153)->Mark() = 2;WARP->Index(154)->Mark() = 7;WARP->Index(155)->Mark() = 7;WARP->Index(156)->Mark() = 7;WARP->Index(157)->Mark() = 3;WARP->Index(158)->Mark() = 2;WARP->Index(159)->Mark() = 2;WARP->Index(160)->Mark() = 7;WARP->Index(161)->Mark() = 7;WARP->Index(162)->Mark() = 7;WARP->Index(163)->Mark() = 3;WARP->Index(164)->Mark() = 2;WARP->Index(165)->Mark() = 2;WARP->Index(166)->Mark() = 7;WARP->Index(167)->Mark() = 7;WARP->Index(168)->Mark() = 7;WARP->Index(169)->Mark() = 7;WARP->Index(170)->Mark() = 7;WARP->Index(171)->Mark() = 3;WARP->Index(172)->Mark() = 2;WARP->Index(173)->Mark() = 2;WARP->Index(174)->Mark() = 7;WARP->Index(175)->Mark() = 7;WARP->Index(176)->Mark() = 7;WARP->Index(177)->Mark() = 3;WARP->Index(178)->Mark() = 2;WARP->Index(179)->Mark() = 2;WARP->Index(180)->Mark() = 7;WARP->Index(181)->Mark() = 7;WARP->Index(182)->Mark() = 7;WARP->Index(183)->Mark() = 3;WARP->Index(184)->Mark() = 2;WARP->Index(185)->Mark() = 2;WARP->Index(186)->Mark() = 7;WARP->Index(187)->Mark() = 7;WARP->Index(188)->Mark() = 7;WARP->Index(189)->Mark() = 3;WARP->Index(190)->Mark() = 2;WARP->Index(191)->Mark() = 2;WARP->Index(192)->Mark() = 7;WARP->Index(193)->Mark() = 7;WARP->Index(194)->Mark() = 7;WARP->Index(195)->Mark() = 3;WARP->Index(196)->Mark() = 2;WARP->Index(197)->Mark() = 2;WARP->Index(198)->Mark() = 7;WARP->Index(199)->Mark() = 7;WARP->Index(200)->Mark() = 7;WARP->Index(201)->Mark() = 3;WARP->Index(202)->Mark() = 2;WARP->Index(203)->Mark() = 2;WARP->Index(204)->Mark() = 7;WARP->Index(205)->Mark() = 7;WARP->Index(206)->Mark() = 7;WARP->Index(207)->Mark() = 3;WARP->Index(208)->Mark() = 2;WARP->Index(209)->Mark() = 2;WARP->Index(210)->Mark() = 7;WARP->Index(211)->Mark() = 7;WARP->Index(212)->Mark() = 7;WARP->Index(213)->Mark() = 3;WARP->Index(214)->Mark() = 2;WARP->Index(215)->Mark() = 2;WARP->Index(216)->Mark() = 7;WARP->Index(217)->Mark() = 7;WARP->Index(218)->Mark() = 7;WARP->Index(219)->Mark() = 3;WARP->Index(220)->Mark() = 7;WARP->Index(221)->Mark() = 7;WARP->Index(222)->Mark() = 7;WARP->Index(223)->Mark() = 7;WARP->Index(224)->Mark() = 5;WARP->Index(225)->Mark() = 5;WARP->Index(226)->Mark() = 5;WARP->Index(227)->Mark() = 5;WARP->Index(228)->Mark() = 5;WARP->Index(229)->Mark() = 7;WARP->Index(230)->Mark() = 5;WARP->Index(231)->Mark() = 7;WARP->Index(232)->Mark() = 7;WARP->Index(233)->Mark() = 5;WARP->Index(234)->Mark() = 7;WARP->Index(235)->Mark() = 7;WARP->Index(236)->Mark() = 7;WARP->Index(237)->Mark() = 7;WARP->Index(238)->Mark() = 2;WARP->Index(239)->Mark() = 2;WARP->Index(240)->Mark() = 2;WARP->Index(241)->Mark() = 7;WARP->Index(242)->Mark() = 7;WARP->Index(243)->Mark() = 7;WARP->Index(244)->Mark() = 3;WARP->Index(245)->Mark() = 2;WARP->Index(246)->Mark() = 2;WARP->Index(247)->Mark() = 7;WARP->Index(248)->Mark() = 7;WARP->Index(249)->Mark() = 7;WARP->Index(250)->Mark() = 3;WARP->Index(251)->Mark() = 2;WARP->Index(252)->Mark() = 2;WARP->Index(253)->Mark() = 7;WARP->Index(254)->Mark() = 7;WARP->Index(255)->Mark() = 7;WARP->Index(256)->Mark() = 3;WARP->Index(257)->Mark() = 2;WARP->Index(258)->Mark() = 2;WARP->Index(259)->Mark() = 7;WARP->Index(260)->Mark() = 7;WARP->Index(261)->Mark() = 7;WARP->Index(262)->Mark() = 3;WARP->Index(263)->Mark() = 2;WARP->Index(264)->Mark() = 2;WARP->Index(265)->Mark() = 7;WARP->Index(266)->Mark() = 7;WARP->Index(267)->Mark() = 7;WARP->Index(268)->Mark() = 3;WARP->Index(269)->Mark() = 2;WARP->Index(270)->Mark() = 2;WARP->Index(271)->Mark() = 7;WARP->Index(272)->Mark() = 7;WARP->Index(273)->Mark() = 7;WARP->Index(274)->Mark() = 3;WARP->Index(275)->Mark() = 2;WARP->Index(276)->Mark() = 2;WARP->Index(277)->Mark() = 7;WARP->Index(278)->Mark() = 7;WARP->Index(279)->Mark() = 7;WARP->Index(280)->Mark() = 3;WARP->Index(281)->Mark() = 2;WARP->Index(282)->Mark() = 2;WARP->Index(283)->Mark() = 0;WARP->Index(284)->Mark() = 7;WARP->Index(285)->Mark() = 7;WARP->Index(286)->Mark() = 0;WARP->Index(287)->Mark() = 7;WARP->Index(288)->Mark() = 7;WARP->Index(289)->Mark() = 6;WARP->Index(290)->Mark() = 7;WARP->Index(291)->Mark() = 6;WARP->Index(292)->Mark() = 7;WARP->Index(293)->Mark() = 7;WARP->Index(294)->Mark() = 7;WARP->Index(295)->Mark() = 3;WARP->Index(296)->Mark() = 2;WARP->Index(297)->Mark() = 2;WARP->Index(298)->Mark() = 7;WARP->Index(299)->Mark() = 7;WARP->Index(300)->Mark() = 7;WARP->Index(301)->Mark() = 3;WARP->Index(302)->Mark() = 2;WARP->Index(303)->Mark() = 2;WARP->Index(304)->Mark() = 7;WARP->Index(305)->Mark() = 7;WARP->Index(306)->Mark() = 7;WARP->Index(307)->Mark() = 3;WARP->Index(308)->Mark() = 2;WARP->Index(309)->Mark() = 2;WARP->Index(310)->Mark() = 7;WARP->Index(311)->Mark() = 7;WARP->Index(312)->Mark() = 7;WARP->Index(313)->Mark() = 3;WARP->Index(314)->Mark() = 2;WARP->Index(315)->Mark() = 2;WARP->Index(316)->Mark() = 7;WARP->Index(317)->Mark() = 7;WARP->Index(318)->Mark() = 7;WARP->Index(319)->Mark() = 3;WARP->Index(320)->Mark() = 2;WARP->Index(321)->Mark() = 2;WARP->Index(322)->Mark() = 7;WARP->Index(323)->Mark() = 7;WARP->Index(324)->Mark() = 7;WARP->Index(325)->Mark() = 3;WARP->Index(326)->Mark() = 2;WARP->Index(327)->Mark() = 2;WARP->Index(328)->Mark() = 7;WARP->Index(329)->Mark() = 7;WARP->Index(330)->Mark() = 7;WARP->Index(331)->Mark() = 3;WARP->Index(332)->Mark() = 2;WARP->Index(333)->Mark() = 2;WARP->Index(334)->Mark() = 7;WARP->Index(335)->Mark() = 7;WARP->Index(336)->Mark() = 7;WARP->Index(337)->Mark() = 3;WARP->Index(338)->Mark() = 2;WARP->Index(339)->Mark() = 2;WARP->Index(340)->Mark() = 7;WARP->Index(341)->Mark() = 7;WARP->Index(342)->Mark() = 7;WARP->Index(343)->Mark() = 7;WARP->Index(344)->Mark() = 7;WARP->Index(345)->Mark() = 3;WARP->Index(346)->Mark() = 2;WARP->Index(347)->Mark() = 2;WARP->Index(348)->Mark() = 7;WARP->Index(349)->Mark() = 7;WARP->Index(350)->Mark() = 7;WARP->Index(351)->Mark() = 3;WARP->Index(352)->Mark() = 2;WARP->Index(353)->Mark() = 2;WARP->Index(354)->Mark() = 7;WARP->Index(355)->Mark() = 7;WARP->Index(356)->Mark() = 7;WARP->Index(357)->Mark() = 3;WARP->Index(358)->Mark() = 2;WARP->Index(359)->Mark() = 2;WARP->Index(360)->Mark() = 7;WARP->Index(361)->Mark() = 7;WARP->Index(362)->Mark() = 7;WARP->Index(363)->Mark() = 3;WARP->Index(364)->Mark() = 2;WARP->Index(365)->Mark() = 2;WARP->Index(366)->Mark() = 7;WARP->Index(367)->Mark() = 7;WARP->Index(368)->Mark() = 7;WARP->Index(369)->Mark() = 3;WARP->Index(370)->Mark() = 2;WARP->Index(371)->Mark() = 2;WARP->Index(372)->Mark() = 7;WARP->Index(373)->Mark() = 7;WARP->Index(374)->Mark() = 7;WARP->Index(375)->Mark() = 3;WARP->Index(376)->Mark() = 2;WARP->Index(377)->Mark() = 2;WARP->Index(378)->Mark() = 7;WARP->Index(379)->Mark() = 7;WARP->Index(380)->Mark() = 7;WARP->Index(381)->Mark() = 3;WARP->Index(382)->Mark() = 2;WARP->Index(383)->Mark() = 2;WARP->Index(384)->Mark() = 7;WARP->Index(385)->Mark() = 7;WARP->Index(386)->Mark() = 7;WARP->Index(387)->Mark() = 3;WARP->Index(388)->Mark() = 2;WARP->Index(389)->Mark() = 2;WARP->Index(390)->Mark() = 7;WARP->Index(391)->Mark() = 7;WARP->Index(392)->Mark() = 7;WARP->Index(393)->Mark() = 7;WARP->Index(394)->Mark() = 7;WARP->Index(395)->Mark() = 3;WARP->Index(396)->Mark() = 2;WARP->Index(397)->Mark() = 2;WARP->Index(398)->Mark() = 7;WARP->Index(399)->Mark() = 7;WARP->Index(400)->Mark() = 7;WARP->Index(401)->Mark() = 3;WARP->Index(402)->Mark() = 2;WARP->Index(403)->Mark() = 2;WARP->Index(404)->Mark() = 7;WARP->Index(405)->Mark() = 7;WARP->Index(406)->Mark() = 7;WARP->Index(407)->Mark() = 3;WARP->Index(408)->Mark() = 2;WARP->Index(409)->Mark() = 2;WARP->Index(410)->Mark() = 7;WARP->Index(411)->Mark() = 7;WARP->Index(412)->Mark() = 7;WARP->Index(413)->Mark() = 3;WARP->Index(414)->Mark() = 2;WARP->Index(415)->Mark() = 2;WARP->Index(416)->Mark() = 7;WARP->Index(417)->Mark() = 7;WARP->Index(418)->Mark() = 7;WARP->Index(419)->Mark() = 3;WARP->Index(420)->Mark() = 2;WARP->Index(421)->Mark() = 2;WARP->Index(422)->Mark() = 7;WARP->Index(423)->Mark() = 7;WARP->Index(424)->Mark() = 7;WARP->Index(425)->Mark() = 3;WARP->Index(426)->Mark() = 2;WARP->Index(427)->Mark() = 2;WARP->Index(428)->Mark() = 7;WARP->Index(429)->Mark() = 7;WARP->Index(430)->Mark() = 7;WARP->Index(431)->Mark() = 3;WARP->Index(432)->Mark() = 2;WARP->Index(433)->Mark() = 2;WARP->Index(434)->Mark() = 7;WARP->Index(435)->Mark() = 7;WARP->Index(436)->Mark() = 7;WARP->Index(437)->Mark() = 3;WARP->Index(438)->Mark() = 2;WARP->Index(439)->Mark() = 2;WARP->Index(440)->Mark() = 7;WARP->Index(441)->Mark() = 7;WARP->Index(442)->Mark() = 7;WARP->Index(443)->Mark() = 3;WARP->Index(444)->Mark() = 7;WARP->Index(445)->Mark() = 7;WARP->Index(446)->Mark() = 7;WARP->Index(447)->Mark() = 7;WARP->Index(448)->Mark() = 5;WARP->Index(449)->Mark() = 5;WARP->Index(450)->Mark() = 5;WARP->Index(451)->Mark() = 5;WARP->Index(452)->Mark() = 5;WARP->Index(453)->Mark() = 7;WARP->Index(454)->Mark() = 5;WARP->Index(455)->Mark() = 7;WARP->Index(456)->Mark() = 7;WARP->Index(457)->Mark() = 5;WARP->Index(458)->Mark() = 7;WARP->Index(459)->Mark() = 7;WARP->Index(460)->Mark() = 7;WARP->Index(461)->Mark() = 7;WARP->Index(462)->Mark() = 2;WARP->Index(463)->Mark() = 2;WARP->Index(464)->Mark() = 2;WARP->Index(465)->Mark() = 7;WARP->Index(466)->Mark() = 7;WARP->Index(467)->Mark() = 7;WARP->Index(468)->Mark() = 3;WARP->Index(469)->Mark() = 2;WARP->Index(470)->Mark() = 2;WARP->Index(471)->Mark() = 7;WARP->Index(472)->Mark() = 7;WARP->Index(473)->Mark() = 7;WARP->Index(474)->Mark() = 3;WARP->Index(475)->Mark() = 2;WARP->Index(476)->Mark() = 2;WARP->Index(477)->Mark() = 7;WARP->Index(478)->Mark() = 7;WARP->Index(479)->Mark() = 7;WARP->Index(480)->Mark() = 3;WARP->Index(481)->Mark() = 2;WARP->Index(482)->Mark() = 2;WARP->Index(483)->Mark() = 7;WARP->Index(484)->Mark() = 7;WARP->Index(485)->Mark() = 7;WARP->Index(486)->Mark() = 3;WARP->Index(487)->Mark() = 2;WARP->Index(488)->Mark() = 2;WARP->Index(489)->Mark() = 7;WARP->Index(490)->Mark() = 7;WARP->Index(491)->Mark() = 7;WARP->Index(492)->Mark() = 3;WARP->Index(493)->Mark() = 2;WARP->Index(494)->Mark() = 2;WARP->Index(495)->Mark() = 7;WARP->Index(496)->Mark() = 7;WARP->Index(497)->Mark() = 7;WARP->Index(498)->Mark() = 3;WARP->Index(499)->Mark() = 2;WARP->Index(500)->Mark() = 2;WARP->Index(501)->Mark() = 7;WARP->Index(502)->Mark() = 7;WARP->Index(503)->Mark() = 7;WARP->Index(504)->Mark() = 3;WARP->Index(505)->Mark() = 2;WARP->Index(506)->Mark() = 2;WARP->Index(507)->Mark() = 0;WARP->Index(508)->Mark() = 7;WARP->Index(509)->Mark() = 7;WARP->Index(510)->Mark() = 0;WARP->Index(511)->Mark() = 7;WARP->Index(512)->Mark() = 7;WARP->Index(513)->Mark() = 6;WARP->Index(514)->Mark() = 7;WARP->Index(515)->Mark() = 6;WARP->Index(516)->Mark() = 7;WARP->Index(517)->Mark() = 7;WARP->Index(518)->Mark() = 7;WARP->Index(519)->Mark() = 3;WARP->Index(520)->Mark() = 2;WARP->Index(521)->Mark() = 2;WARP->Index(522)->Mark() = 7;WARP->Index(523)->Mark() = 7;WARP->Index(524)->Mark() = 7;WARP->Index(525)->Mark() = 3;WARP->Index(526)->Mark() = 2;WARP->Index(527)->Mark() = 2;WARP->Index(528)->Mark() = 7;WARP->Index(529)->Mark() = 7;WARP->Index(530)->Mark() = 7;WARP->Index(531)->Mark() = 3;WARP->Index(532)->Mark() = 2;WARP->Index(533)->Mark() = 2;WARP->Index(534)->Mark() = 7;WARP->Index(535)->Mark() = 7;WARP->Index(536)->Mark() = 7;WARP->Index(537)->Mark() = 3;WARP->Index(538)->Mark() = 2;WARP->Index(539)->Mark() = 2;WARP->Index(540)->Mark() = 7;WARP->Index(541)->Mark() = 7;WARP->Index(542)->Mark() = 7;WARP->Index(543)->Mark() = 3;WARP->Index(544)->Mark() = 2;WARP->Index(545)->Mark() = 2;WARP->Index(546)->Mark() = 7;WARP->Index(547)->Mark() = 7;WARP->Index(548)->Mark() = 7;WARP->Index(549)->Mark() = 3;WARP->Index(550)->Mark() = 2;WARP->Index(551)->Mark() = 2;WARP->Index(552)->Mark() = 7;WARP->Index(553)->Mark() = 7;WARP->Index(554)->Mark() = 7;WARP->Index(555)->Mark() = 3;WARP->Index(556)->Mark() = 2;WARP->Index(557)->Mark() = 2;WARP->Index(558)->Mark() = 7;WARP->Index(559)->Mark() = 7;WARP->Index(560)->Mark() = 7;WARP->Index(561)->Mark() = 3;WARP->Index(562)->Mark() = 2;WARP->Index(563)->Mark() = 2;WARP->Index(564)->Mark() = 7;WARP->Index(565)->Mark() = 7;WARP->Index(566)->Mark() = 7;WARP->Index(567)->Mark() = 7;WARP->Index(568)->Mark() = 7;WARP->Index(569)->Mark() = 3;WARP->Index(570)->Mark() = 2;WARP->Index(571)->Mark() = 2;WARP->Index(572)->Mark() = 7;WARP->Index(573)->Mark() = 7;WARP->Index(574)->Mark() = 7;WARP->Index(575)->Mark() = 3;WARP->Index(576)->Mark() = 2;WARP->Index(577)->Mark() = 2;WARP->Index(578)->Mark() = 7;WARP->Index(579)->Mark() = 7;WARP->Index(580)->Mark() = 7;WARP->Index(581)->Mark() = 3;WARP->Index(582)->Mark() = 2;WARP->Index(583)->Mark() = 2;WARP->Index(584)->Mark() = 7;WARP->Index(585)->Mark() = 7;WARP->Index(586)->Mark() = 7;WARP->Index(587)->Mark() = 3;WARP->Index(588)->Mark() = 2;WARP->Index(589)->Mark() = 2;WARP->Index(590)->Mark() = 7;WARP->Index(591)->Mark() = 7;WARP->Index(592)->Mark() = 7;WARP->Index(593)->Mark() = 3;WARP->Index(594)->Mark() = 2;WARP->Index(595)->Mark() = 2;WARP->Index(596)->Mark() = 7;WARP->Index(597)->Mark() = 7;WARP->Index(598)->Mark() = 7;WARP->Index(599)->Mark() = 3;WARP->Index(600)->Mark() = 2;WARP->Index(601)->Mark() = 2;WARP->Index(602)->Mark() = 7;WARP->Index(603)->Mark() = 7;WARP->Index(604)->Mark() = 7;WARP->Index(605)->Mark() = 3;WARP->Index(606)->Mark() = 2;WARP->Index(607)->Mark() = 2;WARP->Index(608)->Mark() = 7;WARP->Index(609)->Mark() = 7;WARP->Index(610)->Mark() = 7;WARP->Index(611)->Mark() = 3;WARP->Index(612)->Mark() = 2;WARP->Index(613)->Mark() = 2;WARP->Index(614)->Mark() = 7;WARP->Index(615)->Mark() = 7;WARP->Index(616)->Mark() = 7;WARP->Index(617)->Mark() = 7;WARP->Index(618)->Mark() = 7;WARP->Index(619)->Mark() = 3;WARP->Index(620)->Mark() = 2;WARP->Index(621)->Mark() = 2;WARP->Index(622)->Mark() = 7;WARP->Index(623)->Mark() = 7;WARP->Index(624)->Mark() = 7;WARP->Index(625)->Mark() = 3;WARP->Index(626)->Mark() = 2;WARP->Index(627)->Mark() = 2;WARP->Index(628)->Mark() = 7;WARP->Index(629)->Mark() = 7;WARP->Index(630)->Mark() = 7;WARP->Index(631)->Mark() = 3;WARP->Index(632)->Mark() = 2;WARP->Index(633)->Mark() = 2;WARP->Index(634)->Mark() = 7;WARP->Index(635)->Mark() = 7;WARP->Index(636)->Mark() = 7;WARP->Index(637)->Mark() = 3;WARP->Index(638)->Mark() = 2;WARP->Index(639)->Mark() = 2;WARP->Index(640)->Mark() = 7;WARP->Index(641)->Mark() = 7;WARP->Index(642)->Mark() = 7;WARP->Index(643)->Mark() = 3;WARP->Index(644)->Mark() = 2;WARP->Index(645)->Mark() = 2;WARP->Index(646)->Mark() = 7;WARP->Index(647)->Mark() = 7;WARP->Index(648)->Mark() = 7;WARP->Index(649)->Mark() = 3;WARP->Index(650)->Mark() = 2;WARP->Index(651)->Mark() = 2;WARP->Index(652)->Mark() = 7;WARP->Index(653)->Mark() = 7;WARP->Index(654)->Mark() = 7;WARP->Index(655)->Mark() = 3;WARP->Index(656)->Mark() = 2;WARP->Index(657)->Mark() = 2;WARP->Index(658)->Mark() = 7;WARP->Index(659)->Mark() = 7;WARP->Index(660)->Mark() = 7;WARP->Index(661)->Mark() = 3;WARP->Index(662)->Mark() = 2;WARP->Index(663)->Mark() = 2;WARP->Index(664)->Mark() = 7;WARP->Index(665)->Mark() = 7;WARP->Index(666)->Mark() = 7;WARP->Index(667)->Mark() = 3;WARP->Index(668)->Mark() = 7;WARP->Index(669)->Mark() = 7;WARP->Index(670)->Mark() = 7;WARP->Index(671)->Mark() = 7;WARP->Index(672)->Mark() = 5;WARP->Index(673)->Mark() = 5;WARP->Index(674)->Mark() = 5;WARP->Index(675)->Mark() = 5;WARP->Index(676)->Mark() = 5;WARP->Index(677)->Mark() = 7;WARP->Index(678)->Mark() = 5;WARP->Index(679)->Mark() = 7;WARP->Index(680)->Mark() = 7;WARP->Index(681)->Mark() = 5;WARP->Index(682)->Mark() = 7;WARP->Index(683)->Mark() = 7;WARP->Index(684)->Mark() = 7;WARP->Index(685)->Mark() = 7;WARP->Index(686)->Mark() = 2;WARP->Index(687)->Mark() = 2;WARP->Index(688)->Mark() = 2;WARP->Index(689)->Mark() = 7;WARP->Index(690)->Mark() = 7;WARP->Index(691)->Mark() = 7;WARP->Index(692)->Mark() = 3;WARP->Index(693)->Mark() = 2;WARP->Index(694)->Mark() = 2;WARP->Index(695)->Mark() = 7;WARP->Index(696)->Mark() = 7;WARP->Index(697)->Mark() = 7;WARP->Index(698)->Mark() = 3;WARP->Index(699)->Mark() = 2;WARP->Index(700)->Mark() = 2;WARP->Index(701)->Mark() = 7;WARP->Index(702)->Mark() = 7;WARP->Index(703)->Mark() = 7;WARP->Index(704)->Mark() = 3;WARP->Index(705)->Mark() = 2;WARP->Index(706)->Mark() = 2;WARP->Index(707)->Mark() = 7;WARP->Index(708)->Mark() = 7;WARP->Index(709)->Mark() = 7;WARP->Index(710)->Mark() = 3;WARP->Index(711)->Mark() = 2;WARP->Index(712)->Mark() = 2;WARP->Index(713)->Mark() = 7;WARP->Index(714)->Mark() = 7;WARP->Index(715)->Mark() = 7;WARP->Index(716)->Mark() = 3;WARP->Index(717)->Mark() = 2;WARP->Index(718)->Mark() = 2;WARP->Index(719)->Mark() = 7;WARP->Index(720)->Mark() = 7;WARP->Index(721)->Mark() = 7;WARP->Index(722)->Mark() = 3;WARP->Index(723)->Mark() = 2;WARP->Index(724)->Mark() = 2;WARP->Index(725)->Mark() = 7;WARP->Index(726)->Mark() = 7;WARP->Index(727)->Mark() = 7;WARP->Index(728)->Mark() = 3;WARP->Index(729)->Mark() = 2;WARP->Index(730)->Mark() = 2;WARP->Index(731)->Mark() = 0;WARP->Index(732)->Mark() = 7;WARP->Index(733)->Mark() = 7;WARP->Index(734)->Mark() = 0;WARP->Index(735)->Mark() = 7;WARP->Index(736)->Mark() = 7;WARP->Index(737)->Mark() = 6;WARP->Index(738)->Mark() = 7;WARP->Index(739)->Mark() = 6;WARP->Index(740)->Mark() = 7;WARP->Index(741)->Mark() = 7;WARP->Index(742)->Mark() = 7;WARP->Index(743)->Mark() = 3;WARP->Index(744)->Mark() = 2;WARP->Index(745)->Mark() = 2;WARP->Index(746)->Mark() = 7;WARP->Index(747)->Mark() = 7;WARP->Index(748)->Mark() = 7;WARP->Index(749)->Mark() = 3;WARP->Index(750)->Mark() = 2;WARP->Index(751)->Mark() = 2;WARP->Index(752)->Mark() = 7;WARP->Index(753)->Mark() = 7;WARP->Index(754)->Mark() = 7;WARP->Index(755)->Mark() = 3;WARP->Index(756)->Mark() = 2;WARP->Index(757)->Mark() = 2;WARP->Index(758)->Mark() = 7;WARP->Index(759)->Mark() = 7;WARP->Index(760)->Mark() = 7;WARP->Index(761)->Mark() = 3;WARP->Index(762)->Mark() = 2;WARP->Index(763)->Mark() = 2;WARP->Index(764)->Mark() = 7;WARP->Index(765)->Mark() = 7;WARP->Index(766)->Mark() = 7;WARP->Index(767)->Mark() = 3;WARP->Index(768)->Mark() = 2;WARP->Index(769)->Mark() = 2;WARP->Index(770)->Mark() = 7;WARP->Index(771)->Mark() = 7;WARP->Index(772)->Mark() = 7;WARP->Index(773)->Mark() = 3;WARP->Index(774)->Mark() = 2;WARP->Index(775)->Mark() = 2;WARP->Index(776)->Mark() = 7;WARP->Index(777)->Mark() = 7;WARP->Index(778)->Mark() = 7;WARP->Index(779)->Mark() = 3;WARP->Index(780)->Mark() = 2;WARP->Index(781)->Mark() = 2;WARP->Index(782)->Mark() = 7;WARP->Index(783)->Mark() = 7;WARP->Index(784)->Mark() = 7;WARP->Index(785)->Mark() = 3;WARP->Index(786)->Mark() = 2;WARP->Index(787)->Mark() = 2;WARP->Index(788)->Mark() = 7;WARP->Index(789)->Mark() = 7;WARP->Index(790)->Mark() = 7;WARP->Index(791)->Mark() = 7;WARP->Index(792)->Mark() = 7;WARP->Index(793)->Mark() = 3;WARP->Index(794)->Mark() = 2;WARP->Index(795)->Mark() = 2;WARP->Index(796)->Mark() = 7;WARP->Index(797)->Mark() = 7;WARP->Index(798)->Mark() = 7;WARP->Index(799)->Mark() = 3;WARP->Index(800)->Mark() = 2;WARP->Index(801)->Mark() = 2;WARP->Index(802)->Mark() = 7;WARP->Index(803)->Mark() = 7;WARP->Index(804)->Mark() = 7;WARP->Index(805)->Mark() = 3;WARP->Index(806)->Mark() = 2;WARP->Index(807)->Mark() = 2;WARP->Index(808)->Mark() = 7;WARP->Index(809)->Mark() = 7;WARP->Index(810)->Mark() = 7;WARP->Index(811)->Mark() = 3;WARP->Index(812)->Mark() = 2;WARP->Index(813)->Mark() = 2;WARP->Index(814)->Mark() = 7;WARP->Index(815)->Mark() = 7;WARP->Index(816)->Mark() = 7;WARP->Index(817)->Mark() = 3;WARP->Index(818)->Mark() = 2;WARP->Index(819)->Mark() = 2;WARP->Index(820)->Mark() = 7;WARP->Index(821)->Mark() = 7;WARP->Index(822)->Mark() = 7;WARP->Index(823)->Mark() = 3;WARP->Index(824)->Mark() = 2;WARP->Index(825)->Mark() = 2;WARP->Index(826)->Mark() = 7;WARP->Index(827)->Mark() = 7;WARP->Index(828)->Mark() = 7;WARP->Index(829)->Mark() = 3;WARP->Index(830)->Mark() = 2;WARP->Index(831)->Mark() = 2;WARP->Index(832)->Mark() = 7;WARP->Index(833)->Mark() = 7;WARP->Index(834)->Mark() = 7;WARP->Index(835)->Mark() = 3;WARP->Index(836)->Mark() = 2;WARP->Index(837)->Mark() = 2;WARP->Index(838)->Mark() = 7;WARP->Index(839)->Mark() = 7;WARP->Index(840)->Mark() = 7;WARP->Index(841)->Mark() = 7;WARP->Index(842)->Mark() = 7;WARP->Index(843)->Mark() = 3;WARP->Index(844)->Mark() = 2;WARP->Index(845)->Mark() = 2;WARP->Index(846)->Mark() = 7;WARP->Index(847)->Mark() = 7;WARP->Index(848)->Mark() = 7;WARP->Index(849)->Mark() = 3;WARP->Index(850)->Mark() = 2;WARP->Index(851)->Mark() = 2;WARP->Index(852)->Mark() = 7;WARP->Index(853)->Mark() = 7;WARP->Index(854)->Mark() = 7;WARP->Index(855)->Mark() = 3;WARP->Index(856)->Mark() = 2;WARP->Index(857)->Mark() = 2;WARP->Index(858)->Mark() = 7;WARP->Index(859)->Mark() = 7;WARP->Index(860)->Mark() = 7;WARP->Index(861)->Mark() = 3;WARP->Index(862)->Mark() = 2;WARP->Index(863)->Mark() = 2;WARP->Index(864)->Mark() = 7;WARP->Index(865)->Mark() = 7;WARP->Index(866)->Mark() = 7;WARP->Index(867)->Mark() = 3;WARP->Index(868)->Mark() = 2;WARP->Index(869)->Mark() = 2;WARP->Index(870)->Mark() = 7;WARP->Index(871)->Mark() = 7;WARP->Index(872)->Mark() = 7;WARP->Index(873)->Mark() = 3;WARP->Index(874)->Mark() = 2;WARP->Index(875)->Mark() = 2;WARP->Index(876)->Mark() = 7;WARP->Index(877)->Mark() = 7;WARP->Index(878)->Mark() = 7;WARP->Index(879)->Mark() = 3;WARP->Index(880)->Mark() = 2;WARP->Index(881)->Mark() = 2;WARP->Index(882)->Mark() = 7;WARP->Index(883)->Mark() = 7;WARP->Index(884)->Mark() = 7;WARP->Index(885)->Mark() = 3;WARP->Index(886)->Mark() = 2;WARP->Index(887)->Mark() = 2;WARP->Index(888)->Mark() = 7;WARP->Index(889)->Mark() = 7;WARP->Index(890)->Mark() = 7;WARP->Index(891)->Mark() = 3;WARP->Index(892)->Mark() = 7;WARP->Index(893)->Mark() = 7;WARP->Index(894)->Mark() = 7;WARP->Index(895)->Mark() = 7;WARP->Index(896)->Mark() = 5;WARP->Index(897)->Mark() = 5;WARP->Index(898)->Mark() = 5;WARP->Index(899)->Mark() = 5;WARP->Index(900)->Mark() = 5;WARP->Index(901)->Mark() = 7;WARP->Index(902)->Mark() = 5;WARP->Index(903)->Mark() = 7;WARP->Index(904)->Mark() = 7;WARP->Index(905)->Mark() = 5;WARP->Index(906)->Mark() = 7;WARP->Index(907)->Mark() = 7;WARP->Index(908)->Mark() = 7;WARP->Index(909)->Mark() = 7;WARP->Index(910)->Mark() = 2;WARP->Index(911)->Mark() = 2;WARP->Index(912)->Mark() = 2;WARP->Index(913)->Mark() = 7;WARP->Index(914)->Mark() = 7;WARP->Index(915)->Mark() = 7;WARP->Index(916)->Mark() = 3;WARP->Index(917)->Mark() = 2;WARP->Index(918)->Mark() = 2;WARP->Index(919)->Mark() = 7;WARP->Index(920)->Mark() = 7;WARP->Index(921)->Mark() = 7;WARP->Index(922)->Mark() = 3;WARP->Index(923)->Mark() = 2;WARP->Index(924)->Mark() = 2;WARP->Index(925)->Mark() = 7;WARP->Index(926)->Mark() = 7;WARP->Index(927)->Mark() = 7;WARP->Index(928)->Mark() = 3;WARP->Index(929)->Mark() = 2;WARP->Index(930)->Mark() = 2;WARP->Index(931)->Mark() = 7;WARP->Index(932)->Mark() = 7;WARP->Index(933)->Mark() = 7;WARP->Index(934)->Mark() = 3;WARP->Index(935)->Mark() = 2;WARP->Index(936)->Mark() = 2;WARP->Index(937)->Mark() = 7;WARP->Index(938)->Mark() = 7;WARP->Index(939)->Mark() = 7;WARP->Index(940)->Mark() = 3;WARP->Index(941)->Mark() = 2;WARP->Index(942)->Mark() = 2;WARP->Index(943)->Mark() = 7;WARP->Index(944)->Mark() = 7;WARP->Index(945)->Mark() = 7;WARP->Index(946)->Mark() = 3;WARP->Index(947)->Mark() = 2;WARP->Index(948)->Mark() = 2;WARP->Index(949)->Mark() = 7;WARP->Index(950)->Mark() = 7;WARP->Index(951)->Mark() = 7;WARP->Index(952)->Mark() = 3;WARP->Index(953)->Mark() = 2;WARP->Index(954)->Mark() = 2;WARP->Index(955)->Mark() = 0;WARP->Index(956)->Mark() = 7;WARP->Index(957)->Mark() = 7;WARP->Index(958)->Mark() = 0;WARP->Index(959)->Mark() = 7;WARP->Index(960)->Mark() = 7;WARP->Index(961)->Mark() = 6;WARP->Index(962)->Mark() = 7;WARP->Index(963)->Mark() = 6;WARP->Index(964)->Mark() = 7;WARP->Index(965)->Mark() = 7;WARP->Index(966)->Mark() = 7;WARP->Index(967)->Mark() = 3;WARP->Index(968)->Mark() = 2;WARP->Index(969)->Mark() = 2;WARP->Index(970)->Mark() = 7;WARP->Index(971)->Mark() = 7;WARP->Index(972)->Mark() = 7;WARP->Index(973)->Mark() = 3;WARP->Index(974)->Mark() = 2;WARP->Index(975)->Mark() = 2;WARP->Index(976)->Mark() = 7;WARP->Index(977)->Mark() = 7;WARP->Index(978)->Mark() = 7;WARP->Index(979)->Mark() = 3;WARP->Index(980)->Mark() = 2;WARP->Index(981)->Mark() = 2;WARP->Index(982)->Mark() = 7;WARP->Index(983)->Mark() = 7;WARP->Index(984)->Mark() = 7;WARP->Index(985)->Mark() = 3;WARP->Index(986)->Mark() = 2;WARP->Index(987)->Mark() = 2;WARP->Index(988)->Mark() = 7;WARP->Index(989)->Mark() = 7;WARP->Index(990)->Mark() = 7;WARP->Index(991)->Mark() = 3;WARP->Index(992)->Mark() = 2;WARP->Index(993)->Mark() = 2;WARP->Index(994)->Mark() = 7;WARP->Index(995)->Mark() = 7;WARP->Index(996)->Mark() = 7;WARP->Index(997)->Mark() = 3;WARP->Index(998)->Mark() = 2;WARP->Index(999)->Mark() = 2;WARP->Index(1000)->Mark() = 7;WARP->Index(1001)->Mark() = 7;WARP->Index(1002)->Mark() = 7;WARP->Index(1003)->Mark() = 3;WARP->Index(1004)->Mark() = 2;WARP->Index(1005)->Mark() = 2;WARP->Index(1006)->Mark() = 7;WARP->Index(1007)->Mark() = 7;WARP->Index(1008)->Mark() = 7;WARP->Index(1009)->Mark() = 3;WARP->Index(1010)->Mark() = 2;WARP->Index(1011)->Mark() = 2;WARP->Index(1012)->Mark() = 7;WARP->Index(1013)->Mark() = 7;WARP->Index(1014)->Mark() = 7;WARP->Index(1015)->Mark() = 7;WARP->Index(1016)->Mark() = 7;WARP->Index(1017)->Mark() = 3;WARP->Index(1018)->Mark() = 2;WARP->Index(1019)->Mark() = 2;WARP->Index(1020)->Mark() = 7;WARP->Index(1021)->Mark() = 7;WARP->Index(1022)->Mark() = 7;WARP->Index(1023)->Mark() = 3;WARP->Index(1024)->Mark() = 2;WARP->Index(1025)->Mark() = 2;WARP->Index(1026)->Mark() = 7;WARP->Index(1027)->Mark() = 7;WARP->Index(1028)->Mark() = 7;WARP->Index(1029)->Mark() = 3;WARP->Index(1030)->Mark() = 2;WARP->Index(1031)->Mark() = 2;WARP->Index(1032)->Mark() = 7;WARP->Index(1033)->Mark() = 7;WARP->Index(1034)->Mark() = 7;WARP->Index(1035)->Mark() = 3;WARP->Index(1036)->Mark() = 2;WARP->Index(1037)->Mark() = 2;WARP->Index(1038)->Mark() = 7;WARP->Index(1039)->Mark() = 7;WARP->Index(1040)->Mark() = 7;WARP->Index(1041)->Mark() = 3;WARP->Index(1042)->Mark() = 2;WARP->Index(1043)->Mark() = 2;WARP->Index(1044)->Mark() = 7;WARP->Index(1045)->Mark() = 7;WARP->Index(1046)->Mark() = 7;WARP->Index(1047)->Mark() = 3;WARP->Index(1048)->Mark() = 2;WARP->Index(1049)->Mark() = 2;WARP->Index(1050)->Mark() = 7;WARP->Index(1051)->Mark() = 7;WARP->Index(1052)->Mark() = 7;WARP->Index(1053)->Mark() = 3;WARP->Index(1054)->Mark() = 2;WARP->Index(1055)->Mark() = 2;WARP->Index(1056)->Mark() = 7;WARP->Index(1057)->Mark() = 7;WARP->Index(1058)->Mark() = 7;WARP->Index(1059)->Mark() = 3;WARP->Index(1060)->Mark() = 2;WARP->Index(1061)->Mark() = 2;WARP->Index(1062)->Mark() = 7;WARP->Index(1063)->Mark() = 7;WARP->Index(1064)->Mark() = 7;WARP->Index(1065)->Mark() = 7;WARP->Index(1066)->Mark() = 7;WARP->Index(1067)->Mark() = 3;WARP->Index(1068)->Mark() = 2;WARP->Index(1069)->Mark() = 2;WARP->Index(1070)->Mark() = 7;WARP->Index(1071)->Mark() = 7;WARP->Index(1072)->Mark() = 7;WARP->Index(1073)->Mark() = 3;WARP->Index(1074)->Mark() = 2;WARP->Index(1075)->Mark() = 2;WARP->Index(1076)->Mark() = 7;WARP->Index(1077)->Mark() = 7;WARP->Index(1078)->Mark() = 7;WARP->Index(1079)->Mark() = 3;WARP->Index(1080)->Mark() = 2;WARP->Index(1081)->Mark() = 2;WARP->Index(1082)->Mark() = 7;WARP->Index(1083)->Mark() = 7;WARP->Index(1084)->Mark() = 7;WARP->Index(1085)->Mark() = 3;WARP->Index(1086)->Mark() = 2;WARP->Index(1087)->Mark() = 2;WARP->Index(1088)->Mark() = 7;WARP->Index(1089)->Mark() = 7;WARP->Index(1090)->Mark() = 7;WARP->Index(1091)->Mark() = 3;WARP->Index(1092)->Mark() = 2;WARP->Index(1093)->Mark() = 2;WARP->Index(1094)->Mark() = 7;WARP->Index(1095)->Mark() = 7;WARP->Index(1096)->Mark() = 7;WARP->Index(1097)->Mark() = 3;WARP->Index(1098)->Mark() = 2;WARP->Index(1099)->Mark() = 2;WARP->Index(1100)->Mark() = 7;WARP->Index(1101)->Mark() = 7;WARP->Index(1102)->Mark() = 7;WARP->Index(1103)->Mark() = 3;WARP->Index(1104)->Mark() = 2;WARP->Index(1105)->Mark() = 2;WARP->Index(1106)->Mark() = 7;WARP->Index(1107)->Mark() = 7;WARP->Index(1108)->Mark() = 7;WARP->Index(1109)->Mark() = 3;WARP->Index(1110)->Mark() = 2;WARP->Index(1111)->Mark() = 2;WARP->Index(1112)->Mark() = 7;WARP->Index(1113)->Mark() = 7;WARP->Index(1114)->Mark() = 7;WARP->Index(1115)->Mark() = 3;WARP->Index(1116)->Mark() = 7;WARP->Index(1117)->Mark() = 7;WARP->Index(1118)->Mark() = 7;WARP->Index(1119)->Mark() = 7;WARP->Index(1120)->Mark() = 5;WARP->Index(1121)->Mark() = 5;WARP->Index(1122)->Mark() = 5;WARP->Index(1123)->Mark() = 5;WARP->Index(1124)->Mark() = 5;WARP->Index(1125)->Mark() = 7;WARP->Index(1126)->Mark() = 5;WARP->Index(1127)->Mark() = 7;WARP->Index(1128)->Mark() = 7;WARP->Index(1129)->Mark() = 5;WARP->Index(1130)->Mark() = 7;WARP->Index(1131)->Mark() = 7;WARP->Index(1132)->Mark() = 7;WARP->Index(1133)->Mark() = 7;WARP->Index(1134)->Mark() = 2;WARP->Index(1135)->Mark() = 2;WARP->Index(1136)->Mark() = 2;WARP->Index(1137)->Mark() = 7;WARP->Index(1138)->Mark() = 7;WARP->Index(1139)->Mark() = 7;WARP->Index(1140)->Mark() = 3;WARP->Index(1141)->Mark() = 2;WARP->Index(1142)->Mark() = 2;WARP->Index(1143)->Mark() = 7;WARP->Index(1144)->Mark() = 7;WARP->Index(1145)->Mark() = 7;WARP->Index(1146)->Mark() = 3;WARP->Index(1147)->Mark() = 2;WARP->Index(1148)->Mark() = 2;WARP->Index(1149)->Mark() = 7;WARP->Index(1150)->Mark() = 7;WARP->Index(1151)->Mark() = 7;WARP->Index(1152)->Mark() = 3;WARP->Index(1153)->Mark() = 2;WARP->Index(1154)->Mark() = 2;WARP->Index(1155)->Mark() = 7;WARP->Index(1156)->Mark() = 7;WARP->Index(1157)->Mark() = 7;WARP->Index(1158)->Mark() = 3;WARP->Index(1159)->Mark() = 2;WARP->Index(1160)->Mark() = 2;WARP->Index(1161)->Mark() = 7;WARP->Index(1162)->Mark() = 7;WARP->Index(1163)->Mark() = 7;WARP->Index(1164)->Mark() = 3;WARP->Index(1165)->Mark() = 2;WARP->Index(1166)->Mark() = 2;WARP->Index(1167)->Mark() = 7;WARP->Index(1168)->Mark() = 7;WARP->Index(1169)->Mark() = 7;WARP->Index(1170)->Mark() = 3;WARP->Index(1171)->Mark() = 2;WARP->Index(1172)->Mark() = 2;WARP->Index(1173)->Mark() = 7;WARP->Index(1174)->Mark() = 7;WARP->Index(1175)->Mark() = 7;WARP->Index(1176)->Mark() = 3;WARP->Index(1177)->Mark() = 2;WARP->Index(1178)->Mark() = 2;WARP->Index(1179)->Mark() = 0;WARP->Index(1180)->Mark() = 7;WARP->Index(1181)->Mark() = 7;WARP->Index(1182)->Mark() = 0;WARP->Index(1183)->Mark() = 7;WARP->Index(1184)->Mark() = 7;WARP->Index(1185)->Mark() = 6;WARP->Index(1186)->Mark() = 7;WARP->Index(1187)->Mark() = 6;WARP->Index(1188)->Mark() = 7;WARP->Index(1189)->Mark() = 7;WARP->Index(1190)->Mark() = 7;WARP->Index(1191)->Mark() = 3;WARP->Index(1192)->Mark() = 2;WARP->Index(1193)->Mark() = 2;WARP->Index(1194)->Mark() = 7;WARP->Index(1195)->Mark() = 7;WARP->Index(1196)->Mark() = 7;WARP->Index(1197)->Mark() = 3;WARP->Index(1198)->Mark() = 2;WARP->Index(1199)->Mark() = 2;WARP->Index(1200)->Mark() = 7;WARP->Index(1201)->Mark() = 7;WARP->Index(1202)->Mark() = 7;WARP->Index(1203)->Mark() = 3;WARP->Index(1204)->Mark() = 2;WARP->Index(1205)->Mark() = 2;WARP->Index(1206)->Mark() = 7;WARP->Index(1207)->Mark() = 7;WARP->Index(1208)->Mark() = 7;WARP->Index(1209)->Mark() = 3;WARP->Index(1210)->Mark() = 2;WARP->Index(1211)->Mark() = 2;WARP->Index(1212)->Mark() = 7;WARP->Index(1213)->Mark() = 7;WARP->Index(1214)->Mark() = 7;WARP->Index(1215)->Mark() = 3;WARP->Index(1216)->Mark() = 2;WARP->Index(1217)->Mark() = 2;WARP->Index(1218)->Mark() = 7;WARP->Index(1219)->Mark() = 7;WARP->Index(1220)->Mark() = 7;WARP->Index(1221)->Mark() = 3;WARP->Index(1222)->Mark() = 2;WARP->Index(1223)->Mark() = 2;WARP->Index(1224)->Mark() = 7;WARP->Index(1225)->Mark() = 7;WARP->Index(1226)->Mark() = 7;WARP->Index(1227)->Mark() = 3;WARP->Index(1228)->Mark() = 2;WARP->Index(1229)->Mark() = 2;WARP->Index(1230)->Mark() = 7;WARP->Index(1231)->Mark() = 7;WARP->Index(1232)->Mark() = 7;WARP->Index(1233)->Mark() = 3;WARP->Index(1234)->Mark() = 2;WARP->Index(1235)->Mark() = 2;WARP->Index(1236)->Mark() = 7;WARP->Index(1237)->Mark() = 7;WARP->Index(1238)->Mark() = 7;WARP->Index(1239)->Mark() = 7;WARP->Index(1240)->Mark() = 7;WARP->Index(1241)->Mark() = 3;WARP->Index(1242)->Mark() = 2;WARP->Index(1243)->Mark() = 2;WARP->Index(1244)->Mark() = 7;WARP->Index(1245)->Mark() = 7;WARP->Index(1246)->Mark() = 7;WARP->Index(1247)->Mark() = 3;WARP->Index(1248)->Mark() = 2;WARP->Index(1249)->Mark() = 2;WARP->Index(1250)->Mark() = 7;WARP->Index(1251)->Mark() = 7;WARP->Index(1252)->Mark() = 7;WARP->Index(1253)->Mark() = 3;WARP->Index(1254)->Mark() = 2;WARP->Index(1255)->Mark() = 2;WARP->Index(1256)->Mark() = 7;WARP->Index(1257)->Mark() = 7;WARP->Index(1258)->Mark() = 7;WARP->Index(1259)->Mark() = 3;WARP->Index(1260)->Mark() = 2;WARP->Index(1261)->Mark() = 2;WARP->Index(1262)->Mark() = 7;WARP->Index(1263)->Mark() = 7;WARP->Index(1264)->Mark() = 7;WARP->Index(1265)->Mark() = 3;WARP->Index(1266)->Mark() = 2;WARP->Index(1267)->Mark() = 2;WARP->Index(1268)->Mark() = 7;WARP->Index(1269)->Mark() = 7;WARP->Index(1270)->Mark() = 7;WARP->Index(1271)->Mark() = 3;WARP->Index(1272)->Mark() = 2;WARP->Index(1273)->Mark() = 2;WARP->Index(1274)->Mark() = 7;WARP->Index(1275)->Mark() = 7;WARP->Index(1276)->Mark() = 7;WARP->Index(1277)->Mark() = 3;WARP->Index(1278)->Mark() = 2;WARP->Index(1279)->Mark() = 2;WARP->Index(1280)->Mark() = 7;WARP->Index(1281)->Mark() = 7;WARP->Index(1282)->Mark() = 7;WARP->Index(1283)->Mark() = 3;WARP->Index(1284)->Mark() = 2;WARP->Index(1285)->Mark() = 2;WARP->Index(1286)->Mark() = 7;WARP->Index(1287)->Mark() = 7;WARP->Index(1288)->Mark() = 7;WARP->Index(1289)->Mark() = 7;WARP->Index(1290)->Mark() = 7;WARP->Index(1291)->Mark() = 3;WARP->Index(1292)->Mark() = 2;WARP->Index(1293)->Mark() = 2;WARP->Index(1294)->Mark() = 7;WARP->Index(1295)->Mark() = 7;WARP->Index(1296)->Mark() = 7;WARP->Index(1297)->Mark() = 3;WARP->Index(1298)->Mark() = 2;WARP->Index(1299)->Mark() = 2;WARP->Index(1300)->Mark() = 7;WARP->Index(1301)->Mark() = 7;WARP->Index(1302)->Mark() = 7;WARP->Index(1303)->Mark() = 3;WARP->Index(1304)->Mark() = 2;WARP->Index(1305)->Mark() = 2;WARP->Index(1306)->Mark() = 7;WARP->Index(1307)->Mark() = 7;WARP->Index(1308)->Mark() = 7;WARP->Index(1309)->Mark() = 3;WARP->Index(1310)->Mark() = 2;WARP->Index(1311)->Mark() = 2;WARP->Index(1312)->Mark() = 7;WARP->Index(1313)->Mark() = 7;WARP->Index(1314)->Mark() = 7;WARP->Index(1315)->Mark() = 3;WARP->Index(1316)->Mark() = 2;WARP->Index(1317)->Mark() = 2;WARP->Index(1318)->Mark() = 7;WARP->Index(1319)->Mark() = 7;WARP->Index(1320)->Mark() = 7;WARP->Index(1321)->Mark() = 3;WARP->Index(1322)->Mark() = 2;WARP->Index(1323)->Mark() = 2;WARP->Index(1324)->Mark() = 7;WARP->Index(1325)->Mark() = 7;WARP->Index(1326)->Mark() = 7;WARP->Index(1327)->Mark() = 3;WARP->Index(1328)->Mark() = 2;WARP->Index(1329)->Mark() = 2;WARP->Index(1330)->Mark() = 7;WARP->Index(1331)->Mark() = 7;WARP->Index(1332)->Mark() = 7;WARP->Index(1333)->Mark() = 3;WARP->Index(1334)->Mark() = 2;WARP->Index(1335)->Mark() = 2;WARP->Index(1336)->Mark() = 7;WARP->Index(1337)->Mark() = 7;WARP->Index(1338)->Mark() = 7;WARP->Index(1339)->Mark() = 3;WARP->Index(1340)->Mark() = 7;WARP->Index(1341)->Mark() = 7;WARP->Index(1342)->Mark() = 7;WARP->Index(1343)->Mark() = 7;WARP->Index(1344)->Mark() = 5;WARP->Index(1345)->Mark() = 5;WARP->Index(1346)->Mark() = 5;WARP->Index(1347)->Mark() = 5;WARP->Index(1348)->Mark() = 5;WARP->Index(1349)->Mark() = 7;WARP->Index(1350)->Mark() = 5;WARP->Index(1351)->Mark() = 7;WARP->Index(1352)->Mark() = 7;WARP->Index(1353)->Mark() = 5;WARP->Index(1354)->Mark() = 7;WARP->Index(1355)->Mark() = 7;WARP->Index(1356)->Mark() = 7;WARP->Index(1357)->Mark() = 7;WARP->Index(1358)->Mark() = 2;WARP->Index(1359)->Mark() = 2;WARP->Index(1360)->Mark() = 2;WARP->Index(1361)->Mark() = 7;WARP->Index(1362)->Mark() = 7;WARP->Index(1363)->Mark() = 7;WARP->Index(1364)->Mark() = 3;WARP->Index(1365)->Mark() = 2;WARP->Index(1366)->Mark() = 2;WARP->Index(1367)->Mark() = 7;WARP->Index(1368)->Mark() = 7;WARP->Index(1369)->Mark() = 7;WARP->Index(1370)->Mark() = 3;WARP->Index(1371)->Mark() = 2;WARP->Index(1372)->Mark() = 2;WARP->Index(1373)->Mark() = 7;WARP->Index(1374)->Mark() = 7;WARP->Index(1375)->Mark() = 7;WARP->Index(1376)->Mark() = 3;WARP->Index(1377)->Mark() = 2;WARP->Index(1378)->Mark() = 2;WARP->Index(1379)->Mark() = 7;WARP->Index(1380)->Mark() = 7;WARP->Index(1381)->Mark() = 7;WARP->Index(1382)->Mark() = 3;WARP->Index(1383)->Mark() = 2;WARP->Index(1384)->Mark() = 2;WARP->Index(1385)->Mark() = 7;WARP->Index(1386)->Mark() = 7;WARP->Index(1387)->Mark() = 7;WARP->Index(1388)->Mark() = 3;WARP->Index(1389)->Mark() = 2;WARP->Index(1390)->Mark() = 2;WARP->Index(1391)->Mark() = 7;WARP->Index(1392)->Mark() = 7;WARP->Index(1393)->Mark() = 7;WARP->Index(1394)->Mark() = 3;WARP->Index(1395)->Mark() = 2;WARP->Index(1396)->Mark() = 2;WARP->Index(1397)->Mark() = 7;WARP->Index(1398)->Mark() = 7;WARP->Index(1399)->Mark() = 7;WARP->Index(1400)->Mark() = 3;WARP->Index(1401)->Mark() = 2;WARP->Index(1402)->Mark() = 2;WARP->Index(1403)->Mark() = 0;WARP->Index(1404)->Mark() = 7;WARP->Index(1405)->Mark() = 7;WARP->Index(1406)->Mark() = 0;WARP->Index(1407)->Mark() = 7;WARP->Index(1408)->Mark() = 7;WARP->Index(1409)->Mark() = 6;WARP->Index(1410)->Mark() = 7;WARP->Index(1411)->Mark() = 6;WARP->Index(1412)->Mark() = 7;WARP->Index(1413)->Mark() = 7;WARP->Index(1414)->Mark() = 7;WARP->Index(1415)->Mark() = 3;WARP->Index(1416)->Mark() = 2;WARP->Index(1417)->Mark() = 2;WARP->Index(1418)->Mark() = 7;WARP->Index(1419)->Mark() = 7;WARP->Index(1420)->Mark() = 7;WARP->Index(1421)->Mark() = 3;WARP->Index(1422)->Mark() = 2;WARP->Index(1423)->Mark() = 2;WARP->Index(1424)->Mark() = 7;WARP->Index(1425)->Mark() = 7;WARP->Index(1426)->Mark() = 7;WARP->Index(1427)->Mark() = 3;WARP->Index(1428)->Mark() = 2;WARP->Index(1429)->Mark() = 2;WARP->Index(1430)->Mark() = 7;WARP->Index(1431)->Mark() = 7;WARP->Index(1432)->Mark() = 7;WARP->Index(1433)->Mark() = 3;WARP->Index(1434)->Mark() = 2;WARP->Index(1435)->Mark() = 2;WARP->Index(1436)->Mark() = 7;WARP->Index(1437)->Mark() = 7;WARP->Index(1438)->Mark() = 7;WARP->Index(1439)->Mark() = 3;WARP->Index(1440)->Mark() = 2;WARP->Index(1441)->Mark() = 2;WARP->Index(1442)->Mark() = 7;WARP->Index(1443)->Mark() = 7;WARP->Index(1444)->Mark() = 7;WARP->Index(1445)->Mark() = 3;WARP->Index(1446)->Mark() = 2;WARP->Index(1447)->Mark() = 2;WARP->Index(1448)->Mark() = 7;WARP->Index(1449)->Mark() = 7;WARP->Index(1450)->Mark() = 7;WARP->Index(1451)->Mark() = 3;WARP->Index(1452)->Mark() = 2;WARP->Index(1453)->Mark() = 2;WARP->Index(1454)->Mark() = 7;WARP->Index(1455)->Mark() = 7;WARP->Index(1456)->Mark() = 7;WARP->Index(1457)->Mark() = 3;WARP->Index(1458)->Mark() = 2;WARP->Index(1459)->Mark() = 2;WARP->Index(1460)->Mark() = 7;WARP->Index(1461)->Mark() = 7;WARP->Index(1462)->Mark() = 7;WARP->Index(1463)->Mark() = 7;WARP->Index(1464)->Mark() = 7;WARP->Index(1465)->Mark() = 3;WARP->Index(1466)->Mark() = 2;WARP->Index(1467)->Mark() = 2;WARP->Index(1468)->Mark() = 7;WARP->Index(1469)->Mark() = 7;WARP->Index(1470)->Mark() = 7;WARP->Index(1471)->Mark() = 3;WARP->Index(1472)->Mark() = 2;WARP->Index(1473)->Mark() = 2;WARP->Index(1474)->Mark() = 7;WARP->Index(1475)->Mark() = 7;WARP->Index(1476)->Mark() = 7;WARP->Index(1477)->Mark() = 3;WARP->Index(1478)->Mark() = 2;WARP->Index(1479)->Mark() = 2;WARP->Index(1480)->Mark() = 7;WARP->Index(1481)->Mark() = 7;WARP->Index(1482)->Mark() = 7;WARP->Index(1483)->Mark() = 3;WARP->Index(1484)->Mark() = 2;WARP->Index(1485)->Mark() = 2;WARP->Index(1486)->Mark() = 7;WARP->Index(1487)->Mark() = 7;WARP->Index(1488)->Mark() = 7;WARP->Index(1489)->Mark() = 3;WARP->Index(1490)->Mark() = 2;WARP->Index(1491)->Mark() = 2;WARP->Index(1492)->Mark() = 7;WARP->Index(1493)->Mark() = 7;WARP->Index(1494)->Mark() = 7;WARP->Index(1495)->Mark() = 3;WARP->Index(1496)->Mark() = 2;WARP->Index(1497)->Mark() = 2;WARP->Index(1498)->Mark() = 7;WARP->Index(1499)->Mark() = 7;WARP->Index(1500)->Mark() = 7;WARP->Index(1501)->Mark() = 3;WARP->Index(1502)->Mark() = 2;WARP->Index(1503)->Mark() = 2;WARP->Index(1504)->Mark() = 7;WARP->Index(1505)->Mark() = 7;WARP->Index(1506)->Mark() = 7;WARP->Index(1507)->Mark() = 3;WARP->Index(1508)->Mark() = 2;WARP->Index(1509)->Mark() = 2;WARP->Index(1510)->Mark() = 7;WARP->Index(1511)->Mark() = 7;WARP->Index(1512)->Mark() = 7;WARP->Index(1513)->Mark() = 7;WARP->Index(1514)->Mark() = 7;WARP->Index(1515)->Mark() = 3;WARP->Index(1516)->Mark() = 2;WARP->Index(1517)->Mark() = 2;WARP->Index(1518)->Mark() = 7;WARP->Index(1519)->Mark() = 7;WARP->Index(1520)->Mark() = 7;WARP->Index(1521)->Mark() = 3;WARP->Index(1522)->Mark() = 2;WARP->Index(1523)->Mark() = 2;WARP->Index(1524)->Mark() = 7;WARP->Index(1525)->Mark() = 7;WARP->Index(1526)->Mark() = 7;WARP->Index(1527)->Mark() = 3;WARP->Index(1528)->Mark() = 2;WARP->Index(1529)->Mark() = 2;WARP->Index(1530)->Mark() = 7;WARP->Index(1531)->Mark() = 7;WARP->Index(1532)->Mark() = 7;WARP->Index(1533)->Mark() = 3;WARP->Index(1534)->Mark() = 2;WARP->Index(1535)->Mark() = 2;WARP->Index(1536)->Mark() = 7;WARP->Index(1537)->Mark() = 7;WARP->Index(1538)->Mark() = 7;WARP->Index(1539)->Mark() = 3;WARP->Index(1540)->Mark() = 2;WARP->Index(1541)->Mark() = 2;WARP->Index(1542)->Mark() = 7;WARP->Index(1543)->Mark() = 7;WARP->Index(1544)->Mark() = 7;WARP->Index(1545)->Mark() = 3;WARP->Index(1546)->Mark() = 2;WARP->Index(1547)->Mark() = 2;WARP->Index(1548)->Mark() = 7;WARP->Index(1549)->Mark() = 7;WARP->Index(1550)->Mark() = 7;WARP->Index(1551)->Mark() = 3;WARP->Index(1552)->Mark() = 2;WARP->Index(1553)->Mark() = 2;WARP->Index(1554)->Mark() = 7;WARP->Index(1555)->Mark() = 7;WARP->Index(1556)->Mark() = 7;WARP->Index(1557)->Mark() = 3;WARP->Index(1558)->Mark() = 2;WARP->Index(1559)->Mark() = 2;WARP->Index(1560)->Mark() = 7;WARP->Index(1561)->Mark() = 7;WARP->Index(1562)->Mark() = 7;WARP->Index(1563)->Mark() = 3;WARP->Index(1564)->Mark() = 7;WARP->Index(1565)->Mark() = 7;WARP->Index(1566)->Mark() = 7;WARP->Index(1567)->Mark() = 7;WARP->Index(1568)->Mark() = 5;WARP->Index(1569)->Mark() = 5;WARP->Index(1570)->Mark() = 5;WARP->Index(1571)->Mark() = 5;WARP->Index(1572)->Mark() = 5;WARP->Index(1573)->Mark() = 7;WARP->Index(1574)->Mark() = 5;WARP->Index(1575)->Mark() = 7;WARP->Index(1576)->Mark() = 7;WARP->Index(1577)->Mark() = 5;WARP->Index(1578)->Mark() = 7;WARP->Index(1579)->Mark() = 7;WARP->Index(1580)->Mark() = 7;WARP->Index(1581)->Mark() = 7;WARP->Index(1582)->Mark() = 2;WARP->Index(1583)->Mark() = 2;WARP->Index(1584)->Mark() = 2;WARP->Index(1585)->Mark() = 7;WARP->Index(1586)->Mark() = 7;WARP->Index(1587)->Mark() = 7;WARP->Index(1588)->Mark() = 3;WARP->Index(1589)->Mark() = 2;WARP->Index(1590)->Mark() = 2;WARP->Index(1591)->Mark() = 7;WARP->Index(1592)->Mark() = 7;WARP->Index(1593)->Mark() = 7;WARP->Index(1594)->Mark() = 3;WARP->Index(1595)->Mark() = 2;WARP->Index(1596)->Mark() = 2;WARP->Index(1597)->Mark() = 7;WARP->Index(1598)->Mark() = 7;WARP->Index(1599)->Mark() = 7;WARP->Index(1600)->Mark() = 3;WARP->Index(1601)->Mark() = 2;WARP->Index(1602)->Mark() = 2;WARP->Index(1603)->Mark() = 7;WARP->Index(1604)->Mark() = 7;WARP->Index(1605)->Mark() = 7;WARP->Index(1606)->Mark() = 3;WARP->Index(1607)->Mark() = 2;WARP->Index(1608)->Mark() = 2;WARP->Index(1609)->Mark() = 7;WARP->Index(1610)->Mark() = 7;WARP->Index(1611)->Mark() = 7;WARP->Index(1612)->Mark() = 3;WARP->Index(1613)->Mark() = 2;WARP->Index(1614)->Mark() = 2;WARP->Index(1615)->Mark() = 7;WARP->Index(1616)->Mark() = 7;WARP->Index(1617)->Mark() = 7;WARP->Index(1618)->Mark() = 3;WARP->Index(1619)->Mark() = 2;WARP->Index(1620)->Mark() = 2;WARP->Index(1621)->Mark() = 7;WARP->Index(1622)->Mark() = 7;WARP->Index(1623)->Mark() = 7;WARP->Index(1624)->Mark() = 3;WARP->Index(1625)->Mark() = 2;WARP->Index(1626)->Mark() = 2;WARP->Index(1627)->Mark() = 0;WARP->Index(1628)->Mark() = 7;WARP->Index(1629)->Mark() = 7;WARP->Index(1630)->Mark() = 0;WARP->Index(1631)->Mark() = 7;WARP->Index(1632)->Mark() = 7;WARP->Index(1633)->Mark() = 6;WARP->Index(1634)->Mark() = 7;WARP->Index(1635)->Mark() = 6;WARP->Index(1636)->Mark() = 7;WARP->Index(1637)->Mark() = 7;WARP->Index(1638)->Mark() = 7;WARP->Index(1639)->Mark() = 3;WARP->Index(1640)->Mark() = 2;WARP->Index(1641)->Mark() = 2;WARP->Index(1642)->Mark() = 7;WARP->Index(1643)->Mark() = 7;WARP->Index(1644)->Mark() = 7;WARP->Index(1645)->Mark() = 3;WARP->Index(1646)->Mark() = 2;WARP->Index(1647)->Mark() = 2;WARP->Index(1648)->Mark() = 7;WARP->Index(1649)->Mark() = 7;WARP->Index(1650)->Mark() = 7;WARP->Index(1651)->Mark() = 3;WARP->Index(1652)->Mark() = 2;WARP->Index(1653)->Mark() = 2;WARP->Index(1654)->Mark() = 7;WARP->Index(1655)->Mark() = 7;WARP->Index(1656)->Mark() = 7;WARP->Index(1657)->Mark() = 3;WARP->Index(1658)->Mark() = 2;WARP->Index(1659)->Mark() = 2;WARP->Index(1660)->Mark() = 7;WARP->Index(1661)->Mark() = 7;WARP->Index(1662)->Mark() = 7;WARP->Index(1663)->Mark() = 3;WARP->Index(1664)->Mark() = 2;WARP->Index(1665)->Mark() = 2;WARP->Index(1666)->Mark() = 7;WARP->Index(1667)->Mark() = 7;WARP->Index(1668)->Mark() = 7;WARP->Index(1669)->Mark() = 3;WARP->Index(1670)->Mark() = 2;WARP->Index(1671)->Mark() = 2;WARP->Index(1672)->Mark() = 7;WARP->Index(1673)->Mark() = 7;WARP->Index(1674)->Mark() = 7;WARP->Index(1675)->Mark() = 3;WARP->Index(1676)->Mark() = 2;WARP->Index(1677)->Mark() = 2;WARP->Index(1678)->Mark() = 7;WARP->Index(1679)->Mark() = 7;WARP->Index(1680)->Mark() = 7;WARP->Index(1681)->Mark() = 3;WARP->Index(1682)->Mark() = 2;WARP->Index(1683)->Mark() = 2;WARP->Index(1684)->Mark() = 7;WARP->Index(1685)->Mark() = 7;WARP->Index(1686)->Mark() = 7;WARP->Index(1687)->Mark() = 7;WARP->Index(1688)->Mark() = 7;WARP->Index(1689)->Mark() = 3;WARP->Index(1690)->Mark() = 2;WARP->Index(1691)->Mark() = 2;WARP->Index(1692)->Mark() = 7;WARP->Index(1693)->Mark() = 7;WARP->Index(1694)->Mark() = 7;WARP->Index(1695)->Mark() = 3;WARP->Index(1696)->Mark() = 2;WARP->Index(1697)->Mark() = 2;WARP->Index(1698)->Mark() = 7;WARP->Index(1699)->Mark() = 7;WARP->Index(1700)->Mark() = 7;WARP->Index(1701)->Mark() = 3;WARP->Index(1702)->Mark() = 2;WARP->Index(1703)->Mark() = 2;WARP->Index(1704)->Mark() = 7;WARP->Index(1705)->Mark() = 7;WARP->Index(1706)->Mark() = 7;WARP->Index(1707)->Mark() = 3;WARP->Index(1708)->Mark() = 2;WARP->Index(1709)->Mark() = 2;WARP->Index(1710)->Mark() = 7;WARP->Index(1711)->Mark() = 7;WARP->Index(1712)->Mark() = 7;WARP->Index(1713)->Mark() = 3;WARP->Index(1714)->Mark() = 2;WARP->Index(1715)->Mark() = 2;WARP->Index(1716)->Mark() = 7;WARP->Index(1717)->Mark() = 7;WARP->Index(1718)->Mark() = 7;WARP->Index(1719)->Mark() = 3;WARP->Index(1720)->Mark() = 2;WARP->Index(1721)->Mark() = 2;WARP->Index(1722)->Mark() = 7;WARP->Index(1723)->Mark() = 7;WARP->Index(1724)->Mark() = 7;WARP->Index(1725)->Mark() = 3;WARP->Index(1726)->Mark() = 2;WARP->Index(1727)->Mark() = 2;WARP->Index(1728)->Mark() = 7;WARP->Index(1729)->Mark() = 7;WARP->Index(1730)->Mark() = 7;WARP->Index(1731)->Mark() = 3;WARP->Index(1732)->Mark() = 2;WARP->Index(1733)->Mark() = 2;WARP->Index(1734)->Mark() = 7;WARP->Index(1735)->Mark() = 7;WARP->Index(1736)->Mark() = 7;WARP->Index(1737)->Mark() = 7;WARP->Index(1738)->Mark() = 7;WARP->Index(1739)->Mark() = 3;WARP->Index(1740)->Mark() = 2;WARP->Index(1741)->Mark() = 2;WARP->Index(1742)->Mark() = 7;WARP->Index(1743)->Mark() = 7;WARP->Index(1744)->Mark() = 7;WARP->Index(1745)->Mark() = 3;WARP->Index(1746)->Mark() = 2;WARP->Index(1747)->Mark() = 2;WARP->Index(1748)->Mark() = 7;WARP->Index(1749)->Mark() = 7;WARP->Index(1750)->Mark() = 7;WARP->Index(1751)->Mark() = 3;WARP->Index(1752)->Mark() = 2;WARP->Index(1753)->Mark() = 2;WARP->Index(1754)->Mark() = 7;WARP->Index(1755)->Mark() = 7;WARP->Index(1756)->Mark() = 7;WARP->Index(1757)->Mark() = 3;WARP->Index(1758)->Mark() = 2;WARP->Index(1759)->Mark() = 2;WARP->Index(1760)->Mark() = 7;WARP->Index(1761)->Mark() = 7;WARP->Index(1762)->Mark() = 7;WARP->Index(1763)->Mark() = 3;WARP->Index(1764)->Mark() = 2;WARP->Index(1765)->Mark() = 2;WARP->Index(1766)->Mark() = 7;WARP->Index(1767)->Mark() = 7;WARP->Index(1768)->Mark() = 7;WARP->Index(1769)->Mark() = 3;WARP->Index(1770)->Mark() = 2;WARP->Index(1771)->Mark() = 2;WARP->Index(1772)->Mark() = 7;WARP->Index(1773)->Mark() = 7;WARP->Index(1774)->Mark() = 7;WARP->Index(1775)->Mark() = 3;WARP->Index(1776)->Mark() = 2;WARP->Index(1777)->Mark() = 2;WARP->Index(1778)->Mark() = 7;WARP->Index(1779)->Mark() = 7;WARP->Index(1780)->Mark() = 7;WARP->Index(1781)->Mark() = 3;WARP->Index(1782)->Mark() = 2;WARP->Index(1783)->Mark() = 2;WARP->Index(1784)->Mark() = 7;WARP->Index(1785)->Mark() = 7;WARP->Index(1786)->Mark() = 7;WARP->Index(1787)->Mark() = 3;WARP->Index(1788)->Mark() = 7;WARP->Index(1789)->Mark() = 7;WARP->Index(1790)->Mark() = 7;WARP->Index(1791)->Mark() = 7;
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

