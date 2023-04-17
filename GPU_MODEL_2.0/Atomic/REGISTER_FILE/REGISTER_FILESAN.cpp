

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
LIVE_REGISTERS->Index(0)->Mark() = 0;LIVE_REGISTERS->Index(1)->Mark() = 0;LIVE_REGISTERS->Index(2)->Mark() = 0;LIVE_REGISTERS->Index(3)->Mark() = 0;LIVE_REGISTERS->Index(4)->Mark() = 0;LIVE_REGISTERS->Index(5)->Mark() = 1;LIVE_REGISTERS->Index(6)->Mark() = 1;LIVE_REGISTERS->Index(7)->Mark() = 1;LIVE_REGISTERS->Index(8)->Mark() = 1;LIVE_REGISTERS->Index(9)->Mark() = 0;LIVE_REGISTERS->Index(10)->Mark() = 0;LIVE_REGISTERS->Index(11)->Mark() = 1;LIVE_REGISTERS->Index(12)->Mark() = 0;LIVE_REGISTERS->Index(13)->Mark() = 0;LIVE_REGISTERS->Index(14)->Mark() = 0;LIVE_REGISTERS->Index(15)->Mark() = 2;LIVE_REGISTERS->Index(16)->Mark() = 2;LIVE_REGISTERS->Index(17)->Mark() = -2;LIVE_REGISTERS->Index(18)->Mark() = 1;LIVE_REGISTERS->Index(19)->Mark() = 1;LIVE_REGISTERS->Index(20)->Mark() = 1;LIVE_REGISTERS->Index(21)->Mark() = 0;LIVE_REGISTERS->Index(22)->Mark() = 0;LIVE_REGISTERS->Index(23)->Mark() = 1;LIVE_REGISTERS->Index(24)->Mark() = 1;LIVE_REGISTERS->Index(25)->Mark() = 0;LIVE_REGISTERS->Index(26)->Mark() = 0;LIVE_REGISTERS->Index(27)->Mark() = 0;LIVE_REGISTERS->Index(28)->Mark() = 1;LIVE_REGISTERS->Index(29)->Mark() = 0;LIVE_REGISTERS->Index(30)->Mark() = 0;LIVE_REGISTERS->Index(31)->Mark() = 0;LIVE_REGISTERS->Index(32)->Mark() = 1;LIVE_REGISTERS->Index(33)->Mark() = 0;LIVE_REGISTERS->Index(34)->Mark() = 1;LIVE_REGISTERS->Index(35)->Mark() = 0;LIVE_REGISTERS->Index(36)->Mark() = 0;LIVE_REGISTERS->Index(37)->Mark() = 0;LIVE_REGISTERS->Index(38)->Mark() = 0;LIVE_REGISTERS->Index(39)->Mark() = 0;LIVE_REGISTERS->Index(40)->Mark() = 0;LIVE_REGISTERS->Index(41)->Mark() = 0;LIVE_REGISTERS->Index(42)->Mark() = 0;LIVE_REGISTERS->Index(43)->Mark() = 0;LIVE_REGISTERS->Index(44)->Mark() = 0;LIVE_REGISTERS->Index(45)->Mark() = 0;LIVE_REGISTERS->Index(46)->Mark() = 0;LIVE_REGISTERS->Index(47)->Mark() = 0;LIVE_REGISTERS->Index(48)->Mark() = 0;LIVE_REGISTERS->Index(49)->Mark() = 0;LIVE_REGISTERS->Index(50)->Mark() = 0;LIVE_REGISTERS->Index(51)->Mark() = 0;LIVE_REGISTERS->Index(52)->Mark() = 0;LIVE_REGISTERS->Index(53)->Mark() = 0;LIVE_REGISTERS->Index(54)->Mark() = 0;LIVE_REGISTERS->Index(55)->Mark() = 0;LIVE_REGISTERS->Index(56)->Mark() = 0;LIVE_REGISTERS->Index(57)->Mark() = 0;LIVE_REGISTERS->Index(58)->Mark() = 0;LIVE_REGISTERS->Index(59)->Mark() = 0;LIVE_REGISTERS->Index(60)->Mark() = 0;LIVE_REGISTERS->Index(61)->Mark() = 0;LIVE_REGISTERS->Index(62)->Mark() = 0;LIVE_REGISTERS->Index(63)->Mark() = 1;LIVE_REGISTERS->Index(64)->Mark() = 1;LIVE_REGISTERS->Index(65)->Mark() = 0;LIVE_REGISTERS->Index(66)->Mark() = 1;LIVE_REGISTERS->Index(67)->Mark() = 0;LIVE_REGISTERS->Index(68)->Mark() = -1;LIVE_REGISTERS->Index(69)->Mark() = -1;LIVE_REGISTERS->Index(70)->Mark() = 0;LIVE_REGISTERS->Index(71)->Mark() = -1;LIVE_REGISTERS->Index(72)->Mark() = 0;LIVE_REGISTERS->Index(73)->Mark() = 0;LIVE_REGISTERS->Index(74)->Mark() = 0;LIVE_REGISTERS->Index(75)->Mark() = 0;LIVE_REGISTERS->Index(76)->Mark() = 0;LIVE_REGISTERS->Index(77)->Mark() = 0;LIVE_REGISTERS->Index(78)->Mark() = 0;LIVE_REGISTERS->Index(79)->Mark() = 0;LIVE_REGISTERS->Index(80)->Mark() = 0;LIVE_REGISTERS->Index(81)->Mark() = 0;LIVE_REGISTERS->Index(82)->Mark() = 0;LIVE_REGISTERS->Index(83)->Mark() = 0;LIVE_REGISTERS->Index(84)->Mark() = 0;LIVE_REGISTERS->Index(85)->Mark() = 0;LIVE_REGISTERS->Index(86)->Mark() = 0;LIVE_REGISTERS->Index(87)->Mark() = 0;LIVE_REGISTERS->Index(88)->Mark() = 0;LIVE_REGISTERS->Index(89)->Mark() = 0;LIVE_REGISTERS->Index(90)->Mark() = 0;LIVE_REGISTERS->Index(91)->Mark() = 0;LIVE_REGISTERS->Index(92)->Mark() = 0;LIVE_REGISTERS->Index(93)->Mark() = 0;LIVE_REGISTERS->Index(94)->Mark() = 0;LIVE_REGISTERS->Index(95)->Mark() = 0;LIVE_REGISTERS->Index(96)->Mark() = 0;LIVE_REGISTERS->Index(97)->Mark() = 0;LIVE_REGISTERS->Index(98)->Mark() = 0;LIVE_REGISTERS->Index(99)->Mark() = 0;LIVE_REGISTERS->Index(100)->Mark() = 0;LIVE_REGISTERS->Index(101)->Mark() = 0;LIVE_REGISTERS->Index(102)->Mark() = 0;LIVE_REGISTERS->Index(103)->Mark() = 0;LIVE_REGISTERS->Index(104)->Mark() = 0;LIVE_REGISTERS->Index(105)->Mark() = 0;LIVE_REGISTERS->Index(106)->Mark() = 0;LIVE_REGISTERS->Index(107)->Mark() = 0;LIVE_REGISTERS->Index(108)->Mark() = 0;LIVE_REGISTERS->Index(109)->Mark() = 0;LIVE_REGISTERS->Index(110)->Mark() = 0;LIVE_REGISTERS->Index(111)->Mark() = 0;LIVE_REGISTERS->Index(112)->Mark() = 0;LIVE_REGISTERS->Index(113)->Mark() = 0;LIVE_REGISTERS->Index(114)->Mark() = 0;LIVE_REGISTERS->Index(115)->Mark() = 0;LIVE_REGISTERS->Index(116)->Mark() = 0;LIVE_REGISTERS->Index(117)->Mark() = 0;LIVE_REGISTERS->Index(118)->Mark() = 0;LIVE_REGISTERS->Index(119)->Mark() = 0;LIVE_REGISTERS->Index(120)->Mark() = 0;LIVE_REGISTERS->Index(121)->Mark() = 0;LIVE_REGISTERS->Index(122)->Mark() = 0;LIVE_REGISTERS->Index(123)->Mark() = 0;LIVE_REGISTERS->Index(124)->Mark() = 0;LIVE_REGISTERS->Index(125)->Mark() = 0;LIVE_REGISTERS->Index(126)->Mark() = 0;LIVE_REGISTERS->Index(127)->Mark() = 0;LIVE_REGISTERS->Index(128)->Mark() = 0;LIVE_REGISTERS->Index(129)->Mark() = 0;LIVE_REGISTERS->Index(130)->Mark() = 0;LIVE_REGISTERS->Index(131)->Mark() = 0;LIVE_REGISTERS->Index(132)->Mark() = 0;LIVE_REGISTERS->Index(133)->Mark() = 0;LIVE_REGISTERS->Index(134)->Mark() = 0;LIVE_REGISTERS->Index(135)->Mark() = 0;LIVE_REGISTERS->Index(136)->Mark() = 0;LIVE_REGISTERS->Index(137)->Mark() = 0;LIVE_REGISTERS->Index(138)->Mark() = 0;LIVE_REGISTERS->Index(139)->Mark() = 0;LIVE_REGISTERS->Index(140)->Mark() = 0;LIVE_REGISTERS->Index(141)->Mark() = 0;LIVE_REGISTERS->Index(142)->Mark() = 0;LIVE_REGISTERS->Index(143)->Mark() = 0;LIVE_REGISTERS->Index(144)->Mark() = 0;LIVE_REGISTERS->Index(145)->Mark() = 0;LIVE_REGISTERS->Index(146)->Mark() = 0;LIVE_REGISTERS->Index(147)->Mark() = 0;LIVE_REGISTERS->Index(148)->Mark() = 0;LIVE_REGISTERS->Index(149)->Mark() = 0;LIVE_REGISTERS->Index(150)->Mark() = 0;LIVE_REGISTERS->Index(151)->Mark() = 0;LIVE_REGISTERS->Index(152)->Mark() = 0;LIVE_REGISTERS->Index(153)->Mark() = 0;LIVE_REGISTERS->Index(154)->Mark() = 0;LIVE_REGISTERS->Index(155)->Mark() = 0;LIVE_REGISTERS->Index(156)->Mark() = 0;LIVE_REGISTERS->Index(157)->Mark() = 0;LIVE_REGISTERS->Index(158)->Mark() = 0;LIVE_REGISTERS->Index(159)->Mark() = 0;LIVE_REGISTERS->Index(160)->Mark() = 0;LIVE_REGISTERS->Index(161)->Mark() = 0;LIVE_REGISTERS->Index(162)->Mark() = 0;LIVE_REGISTERS->Index(163)->Mark() = 0;LIVE_REGISTERS->Index(164)->Mark() = 0;LIVE_REGISTERS->Index(165)->Mark() = -1;LIVE_REGISTERS->Index(166)->Mark() = 0;LIVE_REGISTERS->Index(167)->Mark() = 0;LIVE_REGISTERS->Index(168)->Mark() = 0;LIVE_REGISTERS->Index(169)->Mark() = 0;LIVE_REGISTERS->Index(170)->Mark() = 0;LIVE_REGISTERS->Index(171)->Mark() = -1;LIVE_REGISTERS->Index(172)->Mark() = -1;LIVE_REGISTERS->Index(173)->Mark() = 0;LIVE_REGISTERS->Index(174)->Mark() = 0;LIVE_REGISTERS->Index(175)->Mark() = 0;LIVE_REGISTERS->Index(176)->Mark() = 0;LIVE_REGISTERS->Index(177)->Mark() = 0;LIVE_REGISTERS->Index(178)->Mark() = 0;LIVE_REGISTERS->Index(179)->Mark() = 0;LIVE_REGISTERS->Index(180)->Mark() = -2;LIVE_REGISTERS->Index(181)->Mark() = 0;LIVE_REGISTERS->Index(182)->Mark() = 0;LIVE_REGISTERS->Index(183)->Mark() = 0;LIVE_REGISTERS->Index(184)->Mark() = 0;LIVE_REGISTERS->Index(185)->Mark() = 0;LIVE_REGISTERS->Index(186)->Mark() = 0;LIVE_REGISTERS->Index(187)->Mark() = 0;LIVE_REGISTERS->Index(188)->Mark() = 0;LIVE_REGISTERS->Index(189)->Mark() = 0;LIVE_REGISTERS->Index(190)->Mark() = 0;LIVE_REGISTERS->Index(191)->Mark() = 0;LIVE_REGISTERS->Index(192)->Mark() = 0;LIVE_REGISTERS->Index(193)->Mark() = 0;LIVE_REGISTERS->Index(194)->Mark() = 0;LIVE_REGISTERS->Index(195)->Mark() = 0;LIVE_REGISTERS->Index(196)->Mark() = 0;LIVE_REGISTERS->Index(197)->Mark() = 0;LIVE_REGISTERS->Index(198)->Mark() = 0;LIVE_REGISTERS->Index(199)->Mark() = 0;LIVE_REGISTERS->Index(200)->Mark() = 0;LIVE_REGISTERS->Index(201)->Mark() = 0;LIVE_REGISTERS->Index(202)->Mark() = 0;LIVE_REGISTERS->Index(203)->Mark() = 0;LIVE_REGISTERS->Index(204)->Mark() = 0;LIVE_REGISTERS->Index(205)->Mark() = 0;LIVE_REGISTERS->Index(206)->Mark() = 0;LIVE_REGISTERS->Index(207)->Mark() = 0;LIVE_REGISTERS->Index(208)->Mark() = 0;LIVE_REGISTERS->Index(209)->Mark() = 0;LIVE_REGISTERS->Index(210)->Mark() = 0;LIVE_REGISTERS->Index(211)->Mark() = 0;LIVE_REGISTERS->Index(212)->Mark() = 0;LIVE_REGISTERS->Index(213)->Mark() = 0;LIVE_REGISTERS->Index(214)->Mark() = 0;LIVE_REGISTERS->Index(215)->Mark() = -1;LIVE_REGISTERS->Index(216)->Mark() = -3;LIVE_REGISTERS->Index(217)->Mark() = 0;LIVE_REGISTERS->Index(218)->Mark() = 0;LIVE_REGISTERS->Index(219)->Mark() = 0;LIVE_REGISTERS->Index(220)->Mark() = -1;LIVE_REGISTERS->Index(221)->Mark() = -2;LIVE_REGISTERS->Index(222)->Mark() = -3;LIVE_REGISTERS->Index(223)->Mark() = -2;LIVE_REGISTERS->Index(224)->Mark() = 0;LIVE_REGISTERS->Index(225)->Mark() = 0;LIVE_REGISTERS->Index(226)->Mark() = 0;LIVE_REGISTERS->Index(227)->Mark() = 0;LIVE_REGISTERS->Index(228)->Mark() = 0;LIVE_REGISTERS->Index(229)->Mark() = 0;LIVE_REGISTERS->Index(230)->Mark() = 0;LIVE_REGISTERS->Index(231)->Mark() = 1;LIVE_REGISTERS->Index(232)->Mark() = 1;LIVE_REGISTERS->Index(233)->Mark() = 1;LIVE_REGISTERS->Index(234)->Mark() = 1;LIVE_REGISTERS->Index(235)->Mark() = 0;LIVE_REGISTERS->Index(236)->Mark() = 0;LIVE_REGISTERS->Index(237)->Mark() = 1;LIVE_REGISTERS->Index(238)->Mark() = 0;LIVE_REGISTERS->Index(239)->Mark() = 0;LIVE_REGISTERS->Index(240)->Mark() = 0;LIVE_REGISTERS->Index(241)->Mark() = 2;LIVE_REGISTERS->Index(242)->Mark() = 2;LIVE_REGISTERS->Index(243)->Mark() = -2;LIVE_REGISTERS->Index(244)->Mark() = 1;LIVE_REGISTERS->Index(245)->Mark() = 1;LIVE_REGISTERS->Index(246)->Mark() = 1;LIVE_REGISTERS->Index(247)->Mark() = 0;LIVE_REGISTERS->Index(248)->Mark() = 0;LIVE_REGISTERS->Index(249)->Mark() = 1;LIVE_REGISTERS->Index(250)->Mark() = 1;LIVE_REGISTERS->Index(251)->Mark() = 0;LIVE_REGISTERS->Index(252)->Mark() = 0;LIVE_REGISTERS->Index(253)->Mark() = 0;LIVE_REGISTERS->Index(254)->Mark() = 1;LIVE_REGISTERS->Index(255)->Mark() = 0;LIVE_REGISTERS->Index(256)->Mark() = 0;LIVE_REGISTERS->Index(257)->Mark() = 0;LIVE_REGISTERS->Index(258)->Mark() = 1;LIVE_REGISTERS->Index(259)->Mark() = 0;LIVE_REGISTERS->Index(260)->Mark() = 1;LIVE_REGISTERS->Index(261)->Mark() = 0;LIVE_REGISTERS->Index(262)->Mark() = 0;LIVE_REGISTERS->Index(263)->Mark() = 0;LIVE_REGISTERS->Index(264)->Mark() = 0;LIVE_REGISTERS->Index(265)->Mark() = 0;LIVE_REGISTERS->Index(266)->Mark() = 0;LIVE_REGISTERS->Index(267)->Mark() = 0;LIVE_REGISTERS->Index(268)->Mark() = 0;LIVE_REGISTERS->Index(269)->Mark() = 0;LIVE_REGISTERS->Index(270)->Mark() = 0;LIVE_REGISTERS->Index(271)->Mark() = 0;LIVE_REGISTERS->Index(272)->Mark() = 0;LIVE_REGISTERS->Index(273)->Mark() = 0;LIVE_REGISTERS->Index(274)->Mark() = 0;LIVE_REGISTERS->Index(275)->Mark() = 0;LIVE_REGISTERS->Index(276)->Mark() = 0;LIVE_REGISTERS->Index(277)->Mark() = 0;LIVE_REGISTERS->Index(278)->Mark() = 0;LIVE_REGISTERS->Index(279)->Mark() = 0;LIVE_REGISTERS->Index(280)->Mark() = 0;LIVE_REGISTERS->Index(281)->Mark() = 0;LIVE_REGISTERS->Index(282)->Mark() = 0;LIVE_REGISTERS->Index(283)->Mark() = 0;LIVE_REGISTERS->Index(284)->Mark() = 0;LIVE_REGISTERS->Index(285)->Mark() = 0;LIVE_REGISTERS->Index(286)->Mark() = 0;LIVE_REGISTERS->Index(287)->Mark() = 0;LIVE_REGISTERS->Index(288)->Mark() = 0;LIVE_REGISTERS->Index(289)->Mark() = 1;LIVE_REGISTERS->Index(290)->Mark() = 1;LIVE_REGISTERS->Index(291)->Mark() = 0;LIVE_REGISTERS->Index(292)->Mark() = 1;LIVE_REGISTERS->Index(293)->Mark() = 0;LIVE_REGISTERS->Index(294)->Mark() = -1;LIVE_REGISTERS->Index(295)->Mark() = -1;LIVE_REGISTERS->Index(296)->Mark() = 0;LIVE_REGISTERS->Index(297)->Mark() = -1;LIVE_REGISTERS->Index(298)->Mark() = 0;LIVE_REGISTERS->Index(299)->Mark() = 0;LIVE_REGISTERS->Index(300)->Mark() = 0;LIVE_REGISTERS->Index(301)->Mark() = 0;LIVE_REGISTERS->Index(302)->Mark() = 0;LIVE_REGISTERS->Index(303)->Mark() = 0;LIVE_REGISTERS->Index(304)->Mark() = 0;LIVE_REGISTERS->Index(305)->Mark() = 0;LIVE_REGISTERS->Index(306)->Mark() = 0;LIVE_REGISTERS->Index(307)->Mark() = 0;LIVE_REGISTERS->Index(308)->Mark() = 0;LIVE_REGISTERS->Index(309)->Mark() = 0;LIVE_REGISTERS->Index(310)->Mark() = 0;LIVE_REGISTERS->Index(311)->Mark() = 0;LIVE_REGISTERS->Index(312)->Mark() = 0;LIVE_REGISTERS->Index(313)->Mark() = 0;LIVE_REGISTERS->Index(314)->Mark() = 0;LIVE_REGISTERS->Index(315)->Mark() = 0;LIVE_REGISTERS->Index(316)->Mark() = 0;LIVE_REGISTERS->Index(317)->Mark() = 0;LIVE_REGISTERS->Index(318)->Mark() = 0;LIVE_REGISTERS->Index(319)->Mark() = 0;LIVE_REGISTERS->Index(320)->Mark() = 0;LIVE_REGISTERS->Index(321)->Mark() = 0;LIVE_REGISTERS->Index(322)->Mark() = 0;LIVE_REGISTERS->Index(323)->Mark() = 0;LIVE_REGISTERS->Index(324)->Mark() = 0;LIVE_REGISTERS->Index(325)->Mark() = 0;LIVE_REGISTERS->Index(326)->Mark() = 0;LIVE_REGISTERS->Index(327)->Mark() = 0;LIVE_REGISTERS->Index(328)->Mark() = 0;LIVE_REGISTERS->Index(329)->Mark() = 0;LIVE_REGISTERS->Index(330)->Mark() = 0;LIVE_REGISTERS->Index(331)->Mark() = 0;LIVE_REGISTERS->Index(332)->Mark() = 0;LIVE_REGISTERS->Index(333)->Mark() = 0;LIVE_REGISTERS->Index(334)->Mark() = 0;LIVE_REGISTERS->Index(335)->Mark() = 0;LIVE_REGISTERS->Index(336)->Mark() = 0;LIVE_REGISTERS->Index(337)->Mark() = 0;LIVE_REGISTERS->Index(338)->Mark() = 0;LIVE_REGISTERS->Index(339)->Mark() = 0;LIVE_REGISTERS->Index(340)->Mark() = 0;LIVE_REGISTERS->Index(341)->Mark() = 0;LIVE_REGISTERS->Index(342)->Mark() = 0;LIVE_REGISTERS->Index(343)->Mark() = 0;LIVE_REGISTERS->Index(344)->Mark() = 0;LIVE_REGISTERS->Index(345)->Mark() = 0;LIVE_REGISTERS->Index(346)->Mark() = 0;LIVE_REGISTERS->Index(347)->Mark() = 0;LIVE_REGISTERS->Index(348)->Mark() = 0;LIVE_REGISTERS->Index(349)->Mark() = 0;LIVE_REGISTERS->Index(350)->Mark() = 0;LIVE_REGISTERS->Index(351)->Mark() = 0;LIVE_REGISTERS->Index(352)->Mark() = 0;LIVE_REGISTERS->Index(353)->Mark() = 0;LIVE_REGISTERS->Index(354)->Mark() = 0;LIVE_REGISTERS->Index(355)->Mark() = 0;LIVE_REGISTERS->Index(356)->Mark() = 0;LIVE_REGISTERS->Index(357)->Mark() = 0;LIVE_REGISTERS->Index(358)->Mark() = 0;LIVE_REGISTERS->Index(359)->Mark() = 0;LIVE_REGISTERS->Index(360)->Mark() = 0;LIVE_REGISTERS->Index(361)->Mark() = 0;LIVE_REGISTERS->Index(362)->Mark() = 0;LIVE_REGISTERS->Index(363)->Mark() = 0;LIVE_REGISTERS->Index(364)->Mark() = 0;LIVE_REGISTERS->Index(365)->Mark() = 0;LIVE_REGISTERS->Index(366)->Mark() = 0;LIVE_REGISTERS->Index(367)->Mark() = 0;LIVE_REGISTERS->Index(368)->Mark() = 0;LIVE_REGISTERS->Index(369)->Mark() = 0;LIVE_REGISTERS->Index(370)->Mark() = 0;LIVE_REGISTERS->Index(371)->Mark() = 0;LIVE_REGISTERS->Index(372)->Mark() = 0;LIVE_REGISTERS->Index(373)->Mark() = 0;LIVE_REGISTERS->Index(374)->Mark() = 0;LIVE_REGISTERS->Index(375)->Mark() = 0;LIVE_REGISTERS->Index(376)->Mark() = 0;LIVE_REGISTERS->Index(377)->Mark() = 0;LIVE_REGISTERS->Index(378)->Mark() = 0;LIVE_REGISTERS->Index(379)->Mark() = 0;LIVE_REGISTERS->Index(380)->Mark() = 0;LIVE_REGISTERS->Index(381)->Mark() = 0;LIVE_REGISTERS->Index(382)->Mark() = 0;LIVE_REGISTERS->Index(383)->Mark() = 0;LIVE_REGISTERS->Index(384)->Mark() = 0;LIVE_REGISTERS->Index(385)->Mark() = 0;LIVE_REGISTERS->Index(386)->Mark() = 0;LIVE_REGISTERS->Index(387)->Mark() = 0;LIVE_REGISTERS->Index(388)->Mark() = 0;LIVE_REGISTERS->Index(389)->Mark() = 0;LIVE_REGISTERS->Index(390)->Mark() = 0;LIVE_REGISTERS->Index(391)->Mark() = -1;LIVE_REGISTERS->Index(392)->Mark() = 0;LIVE_REGISTERS->Index(393)->Mark() = 0;LIVE_REGISTERS->Index(394)->Mark() = 0;LIVE_REGISTERS->Index(395)->Mark() = 0;LIVE_REGISTERS->Index(396)->Mark() = 0;LIVE_REGISTERS->Index(397)->Mark() = -1;LIVE_REGISTERS->Index(398)->Mark() = -1;LIVE_REGISTERS->Index(399)->Mark() = 0;LIVE_REGISTERS->Index(400)->Mark() = 0;LIVE_REGISTERS->Index(401)->Mark() = 0;LIVE_REGISTERS->Index(402)->Mark() = 0;LIVE_REGISTERS->Index(403)->Mark() = 0;LIVE_REGISTERS->Index(404)->Mark() = 0;LIVE_REGISTERS->Index(405)->Mark() = 0;LIVE_REGISTERS->Index(406)->Mark() = -2;LIVE_REGISTERS->Index(407)->Mark() = 0;LIVE_REGISTERS->Index(408)->Mark() = 0;LIVE_REGISTERS->Index(409)->Mark() = 0;LIVE_REGISTERS->Index(410)->Mark() = 0;LIVE_REGISTERS->Index(411)->Mark() = 0;LIVE_REGISTERS->Index(412)->Mark() = 0;LIVE_REGISTERS->Index(413)->Mark() = 0;LIVE_REGISTERS->Index(414)->Mark() = 0;LIVE_REGISTERS->Index(415)->Mark() = 0;LIVE_REGISTERS->Index(416)->Mark() = 0;LIVE_REGISTERS->Index(417)->Mark() = 0;LIVE_REGISTERS->Index(418)->Mark() = 0;LIVE_REGISTERS->Index(419)->Mark() = 0;LIVE_REGISTERS->Index(420)->Mark() = 0;LIVE_REGISTERS->Index(421)->Mark() = 0;LIVE_REGISTERS->Index(422)->Mark() = 0;LIVE_REGISTERS->Index(423)->Mark() = 0;LIVE_REGISTERS->Index(424)->Mark() = 0;LIVE_REGISTERS->Index(425)->Mark() = 0;LIVE_REGISTERS->Index(426)->Mark() = 0;LIVE_REGISTERS->Index(427)->Mark() = 0;LIVE_REGISTERS->Index(428)->Mark() = 0;LIVE_REGISTERS->Index(429)->Mark() = 0;LIVE_REGISTERS->Index(430)->Mark() = 0;LIVE_REGISTERS->Index(431)->Mark() = 0;LIVE_REGISTERS->Index(432)->Mark() = 0;LIVE_REGISTERS->Index(433)->Mark() = 0;LIVE_REGISTERS->Index(434)->Mark() = 0;LIVE_REGISTERS->Index(435)->Mark() = 0;LIVE_REGISTERS->Index(436)->Mark() = 0;LIVE_REGISTERS->Index(437)->Mark() = 0;LIVE_REGISTERS->Index(438)->Mark() = 0;LIVE_REGISTERS->Index(439)->Mark() = 0;LIVE_REGISTERS->Index(440)->Mark() = 0;LIVE_REGISTERS->Index(441)->Mark() = -1;LIVE_REGISTERS->Index(442)->Mark() = -3;LIVE_REGISTERS->Index(443)->Mark() = 0;LIVE_REGISTERS->Index(444)->Mark() = 0;LIVE_REGISTERS->Index(445)->Mark() = 0;LIVE_REGISTERS->Index(446)->Mark() = -1;LIVE_REGISTERS->Index(447)->Mark() = -2;LIVE_REGISTERS->Index(448)->Mark() = -3;LIVE_REGISTERS->Index(449)->Mark() = -2;LIVE_REGISTERS->Index(450)->Mark() = 0;LIVE_REGISTERS->Index(451)->Mark() = 0;LIVE_REGISTERS->Index(452)->Mark() = 0;LIVE_REGISTERS->Index(453)->Mark() = 0;LIVE_REGISTERS->Index(454)->Mark() = 0;LIVE_REGISTERS->Index(455)->Mark() = 0;LIVE_REGISTERS->Index(456)->Mark() = 0;LIVE_REGISTERS->Index(457)->Mark() = 1;LIVE_REGISTERS->Index(458)->Mark() = 1;LIVE_REGISTERS->Index(459)->Mark() = 1;LIVE_REGISTERS->Index(460)->Mark() = 1;LIVE_REGISTERS->Index(461)->Mark() = 0;LIVE_REGISTERS->Index(462)->Mark() = 0;LIVE_REGISTERS->Index(463)->Mark() = 1;LIVE_REGISTERS->Index(464)->Mark() = 0;LIVE_REGISTERS->Index(465)->Mark() = 0;LIVE_REGISTERS->Index(466)->Mark() = 0;LIVE_REGISTERS->Index(467)->Mark() = 2;LIVE_REGISTERS->Index(468)->Mark() = 2;LIVE_REGISTERS->Index(469)->Mark() = -2;LIVE_REGISTERS->Index(470)->Mark() = 1;LIVE_REGISTERS->Index(471)->Mark() = 1;LIVE_REGISTERS->Index(472)->Mark() = 1;LIVE_REGISTERS->Index(473)->Mark() = 0;LIVE_REGISTERS->Index(474)->Mark() = 0;LIVE_REGISTERS->Index(475)->Mark() = 1;LIVE_REGISTERS->Index(476)->Mark() = 1;LIVE_REGISTERS->Index(477)->Mark() = 0;LIVE_REGISTERS->Index(478)->Mark() = 0;LIVE_REGISTERS->Index(479)->Mark() = 0;LIVE_REGISTERS->Index(480)->Mark() = 1;LIVE_REGISTERS->Index(481)->Mark() = 0;LIVE_REGISTERS->Index(482)->Mark() = 0;LIVE_REGISTERS->Index(483)->Mark() = 0;LIVE_REGISTERS->Index(484)->Mark() = 1;LIVE_REGISTERS->Index(485)->Mark() = 0;LIVE_REGISTERS->Index(486)->Mark() = 1;LIVE_REGISTERS->Index(487)->Mark() = 0;LIVE_REGISTERS->Index(488)->Mark() = 0;LIVE_REGISTERS->Index(489)->Mark() = 0;LIVE_REGISTERS->Index(490)->Mark() = 0;LIVE_REGISTERS->Index(491)->Mark() = 0;LIVE_REGISTERS->Index(492)->Mark() = 0;LIVE_REGISTERS->Index(493)->Mark() = 0;LIVE_REGISTERS->Index(494)->Mark() = 0;LIVE_REGISTERS->Index(495)->Mark() = 0;LIVE_REGISTERS->Index(496)->Mark() = 0;LIVE_REGISTERS->Index(497)->Mark() = 0;LIVE_REGISTERS->Index(498)->Mark() = 0;LIVE_REGISTERS->Index(499)->Mark() = 0;LIVE_REGISTERS->Index(500)->Mark() = 0;LIVE_REGISTERS->Index(501)->Mark() = 0;LIVE_REGISTERS->Index(502)->Mark() = 0;LIVE_REGISTERS->Index(503)->Mark() = 0;LIVE_REGISTERS->Index(504)->Mark() = 0;LIVE_REGISTERS->Index(505)->Mark() = 0;LIVE_REGISTERS->Index(506)->Mark() = 0;LIVE_REGISTERS->Index(507)->Mark() = 0;LIVE_REGISTERS->Index(508)->Mark() = 0;LIVE_REGISTERS->Index(509)->Mark() = 0;LIVE_REGISTERS->Index(510)->Mark() = 0;LIVE_REGISTERS->Index(511)->Mark() = 0;LIVE_REGISTERS->Index(512)->Mark() = 0;LIVE_REGISTERS->Index(513)->Mark() = 0;LIVE_REGISTERS->Index(514)->Mark() = 0;LIVE_REGISTERS->Index(515)->Mark() = 1;LIVE_REGISTERS->Index(516)->Mark() = 1;LIVE_REGISTERS->Index(517)->Mark() = 0;LIVE_REGISTERS->Index(518)->Mark() = 1;LIVE_REGISTERS->Index(519)->Mark() = 0;LIVE_REGISTERS->Index(520)->Mark() = -1;LIVE_REGISTERS->Index(521)->Mark() = -1;LIVE_REGISTERS->Index(522)->Mark() = 0;LIVE_REGISTERS->Index(523)->Mark() = -1;LIVE_REGISTERS->Index(524)->Mark() = 0;LIVE_REGISTERS->Index(525)->Mark() = 0;LIVE_REGISTERS->Index(526)->Mark() = 0;LIVE_REGISTERS->Index(527)->Mark() = 0;LIVE_REGISTERS->Index(528)->Mark() = 0;LIVE_REGISTERS->Index(529)->Mark() = 0;LIVE_REGISTERS->Index(530)->Mark() = 0;LIVE_REGISTERS->Index(531)->Mark() = 0;LIVE_REGISTERS->Index(532)->Mark() = 0;LIVE_REGISTERS->Index(533)->Mark() = 0;LIVE_REGISTERS->Index(534)->Mark() = 0;LIVE_REGISTERS->Index(535)->Mark() = 0;LIVE_REGISTERS->Index(536)->Mark() = 0;LIVE_REGISTERS->Index(537)->Mark() = 0;LIVE_REGISTERS->Index(538)->Mark() = 0;LIVE_REGISTERS->Index(539)->Mark() = 0;LIVE_REGISTERS->Index(540)->Mark() = 0;LIVE_REGISTERS->Index(541)->Mark() = 0;LIVE_REGISTERS->Index(542)->Mark() = 0;LIVE_REGISTERS->Index(543)->Mark() = 0;LIVE_REGISTERS->Index(544)->Mark() = 0;LIVE_REGISTERS->Index(545)->Mark() = 0;LIVE_REGISTERS->Index(546)->Mark() = 0;LIVE_REGISTERS->Index(547)->Mark() = 0;LIVE_REGISTERS->Index(548)->Mark() = 0;LIVE_REGISTERS->Index(549)->Mark() = 0;LIVE_REGISTERS->Index(550)->Mark() = 0;LIVE_REGISTERS->Index(551)->Mark() = 0;LIVE_REGISTERS->Index(552)->Mark() = 0;LIVE_REGISTERS->Index(553)->Mark() = 0;LIVE_REGISTERS->Index(554)->Mark() = 0;LIVE_REGISTERS->Index(555)->Mark() = 0;LIVE_REGISTERS->Index(556)->Mark() = 0;LIVE_REGISTERS->Index(557)->Mark() = 0;LIVE_REGISTERS->Index(558)->Mark() = 0;LIVE_REGISTERS->Index(559)->Mark() = 0;LIVE_REGISTERS->Index(560)->Mark() = 0;LIVE_REGISTERS->Index(561)->Mark() = 0;LIVE_REGISTERS->Index(562)->Mark() = 0;LIVE_REGISTERS->Index(563)->Mark() = 0;LIVE_REGISTERS->Index(564)->Mark() = 0;LIVE_REGISTERS->Index(565)->Mark() = 0;LIVE_REGISTERS->Index(566)->Mark() = 0;LIVE_REGISTERS->Index(567)->Mark() = 0;LIVE_REGISTERS->Index(568)->Mark() = 0;LIVE_REGISTERS->Index(569)->Mark() = 0;LIVE_REGISTERS->Index(570)->Mark() = 0;LIVE_REGISTERS->Index(571)->Mark() = 0;LIVE_REGISTERS->Index(572)->Mark() = 0;LIVE_REGISTERS->Index(573)->Mark() = 0;LIVE_REGISTERS->Index(574)->Mark() = 0;LIVE_REGISTERS->Index(575)->Mark() = 0;LIVE_REGISTERS->Index(576)->Mark() = 0;LIVE_REGISTERS->Index(577)->Mark() = 0;LIVE_REGISTERS->Index(578)->Mark() = 0;LIVE_REGISTERS->Index(579)->Mark() = 0;LIVE_REGISTERS->Index(580)->Mark() = 0;LIVE_REGISTERS->Index(581)->Mark() = 0;LIVE_REGISTERS->Index(582)->Mark() = 0;LIVE_REGISTERS->Index(583)->Mark() = 0;LIVE_REGISTERS->Index(584)->Mark() = 0;LIVE_REGISTERS->Index(585)->Mark() = 0;LIVE_REGISTERS->Index(586)->Mark() = 0;LIVE_REGISTERS->Index(587)->Mark() = 0;LIVE_REGISTERS->Index(588)->Mark() = 0;LIVE_REGISTERS->Index(589)->Mark() = 0;LIVE_REGISTERS->Index(590)->Mark() = 0;LIVE_REGISTERS->Index(591)->Mark() = 0;LIVE_REGISTERS->Index(592)->Mark() = 0;LIVE_REGISTERS->Index(593)->Mark() = 0;LIVE_REGISTERS->Index(594)->Mark() = 0;LIVE_REGISTERS->Index(595)->Mark() = 0;LIVE_REGISTERS->Index(596)->Mark() = 0;LIVE_REGISTERS->Index(597)->Mark() = 0;LIVE_REGISTERS->Index(598)->Mark() = 0;LIVE_REGISTERS->Index(599)->Mark() = 0;LIVE_REGISTERS->Index(600)->Mark() = 0;LIVE_REGISTERS->Index(601)->Mark() = 0;LIVE_REGISTERS->Index(602)->Mark() = 0;LIVE_REGISTERS->Index(603)->Mark() = 0;LIVE_REGISTERS->Index(604)->Mark() = 0;LIVE_REGISTERS->Index(605)->Mark() = 0;LIVE_REGISTERS->Index(606)->Mark() = 0;LIVE_REGISTERS->Index(607)->Mark() = 0;LIVE_REGISTERS->Index(608)->Mark() = 0;LIVE_REGISTERS->Index(609)->Mark() = 0;LIVE_REGISTERS->Index(610)->Mark() = 0;LIVE_REGISTERS->Index(611)->Mark() = 0;LIVE_REGISTERS->Index(612)->Mark() = 0;LIVE_REGISTERS->Index(613)->Mark() = 0;LIVE_REGISTERS->Index(614)->Mark() = 0;LIVE_REGISTERS->Index(615)->Mark() = 0;LIVE_REGISTERS->Index(616)->Mark() = 0;LIVE_REGISTERS->Index(617)->Mark() = -1;LIVE_REGISTERS->Index(618)->Mark() = 0;LIVE_REGISTERS->Index(619)->Mark() = 0;LIVE_REGISTERS->Index(620)->Mark() = 0;LIVE_REGISTERS->Index(621)->Mark() = 0;LIVE_REGISTERS->Index(622)->Mark() = 0;LIVE_REGISTERS->Index(623)->Mark() = -1;LIVE_REGISTERS->Index(624)->Mark() = -1;LIVE_REGISTERS->Index(625)->Mark() = 0;LIVE_REGISTERS->Index(626)->Mark() = 0;LIVE_REGISTERS->Index(627)->Mark() = 0;LIVE_REGISTERS->Index(628)->Mark() = 0;LIVE_REGISTERS->Index(629)->Mark() = 0;LIVE_REGISTERS->Index(630)->Mark() = 0;LIVE_REGISTERS->Index(631)->Mark() = 0;LIVE_REGISTERS->Index(632)->Mark() = -2;LIVE_REGISTERS->Index(633)->Mark() = 0;LIVE_REGISTERS->Index(634)->Mark() = 0;LIVE_REGISTERS->Index(635)->Mark() = 0;LIVE_REGISTERS->Index(636)->Mark() = 0;LIVE_REGISTERS->Index(637)->Mark() = 0;LIVE_REGISTERS->Index(638)->Mark() = 0;LIVE_REGISTERS->Index(639)->Mark() = 0;LIVE_REGISTERS->Index(640)->Mark() = 0;LIVE_REGISTERS->Index(641)->Mark() = 0;LIVE_REGISTERS->Index(642)->Mark() = 0;LIVE_REGISTERS->Index(643)->Mark() = 0;LIVE_REGISTERS->Index(644)->Mark() = 0;LIVE_REGISTERS->Index(645)->Mark() = 0;LIVE_REGISTERS->Index(646)->Mark() = 0;LIVE_REGISTERS->Index(647)->Mark() = 0;LIVE_REGISTERS->Index(648)->Mark() = 0;LIVE_REGISTERS->Index(649)->Mark() = 0;LIVE_REGISTERS->Index(650)->Mark() = 0;LIVE_REGISTERS->Index(651)->Mark() = 0;LIVE_REGISTERS->Index(652)->Mark() = 0;LIVE_REGISTERS->Index(653)->Mark() = 0;LIVE_REGISTERS->Index(654)->Mark() = 0;LIVE_REGISTERS->Index(655)->Mark() = 0;LIVE_REGISTERS->Index(656)->Mark() = 0;LIVE_REGISTERS->Index(657)->Mark() = 0;LIVE_REGISTERS->Index(658)->Mark() = 0;LIVE_REGISTERS->Index(659)->Mark() = 0;LIVE_REGISTERS->Index(660)->Mark() = 0;LIVE_REGISTERS->Index(661)->Mark() = 0;LIVE_REGISTERS->Index(662)->Mark() = 0;LIVE_REGISTERS->Index(663)->Mark() = 0;LIVE_REGISTERS->Index(664)->Mark() = 0;LIVE_REGISTERS->Index(665)->Mark() = 0;LIVE_REGISTERS->Index(666)->Mark() = 0;LIVE_REGISTERS->Index(667)->Mark() = -1;LIVE_REGISTERS->Index(668)->Mark() = -3;LIVE_REGISTERS->Index(669)->Mark() = 0;LIVE_REGISTERS->Index(670)->Mark() = 0;LIVE_REGISTERS->Index(671)->Mark() = 0;LIVE_REGISTERS->Index(672)->Mark() = -1;LIVE_REGISTERS->Index(673)->Mark() = -2;LIVE_REGISTERS->Index(674)->Mark() = -3;LIVE_REGISTERS->Index(675)->Mark() = -2;LIVE_REGISTERS->Index(676)->Mark() = 0;LIVE_REGISTERS->Index(677)->Mark() = 0;LIVE_REGISTERS->Index(678)->Mark() = 0;LIVE_REGISTERS->Index(679)->Mark() = 0;LIVE_REGISTERS->Index(680)->Mark() = 0;LIVE_REGISTERS->Index(681)->Mark() = 0;LIVE_REGISTERS->Index(682)->Mark() = 0;LIVE_REGISTERS->Index(683)->Mark() = 1;LIVE_REGISTERS->Index(684)->Mark() = 1;LIVE_REGISTERS->Index(685)->Mark() = 1;LIVE_REGISTERS->Index(686)->Mark() = 1;LIVE_REGISTERS->Index(687)->Mark() = 0;LIVE_REGISTERS->Index(688)->Mark() = 0;LIVE_REGISTERS->Index(689)->Mark() = 1;LIVE_REGISTERS->Index(690)->Mark() = 0;LIVE_REGISTERS->Index(691)->Mark() = 0;LIVE_REGISTERS->Index(692)->Mark() = 0;LIVE_REGISTERS->Index(693)->Mark() = 2;LIVE_REGISTERS->Index(694)->Mark() = 2;LIVE_REGISTERS->Index(695)->Mark() = -2;LIVE_REGISTERS->Index(696)->Mark() = 1;LIVE_REGISTERS->Index(697)->Mark() = 1;LIVE_REGISTERS->Index(698)->Mark() = 1;LIVE_REGISTERS->Index(699)->Mark() = 0;LIVE_REGISTERS->Index(700)->Mark() = 0;LIVE_REGISTERS->Index(701)->Mark() = 1;LIVE_REGISTERS->Index(702)->Mark() = 1;LIVE_REGISTERS->Index(703)->Mark() = 0;LIVE_REGISTERS->Index(704)->Mark() = 0;LIVE_REGISTERS->Index(705)->Mark() = 0;LIVE_REGISTERS->Index(706)->Mark() = 1;LIVE_REGISTERS->Index(707)->Mark() = 0;LIVE_REGISTERS->Index(708)->Mark() = 0;LIVE_REGISTERS->Index(709)->Mark() = 0;LIVE_REGISTERS->Index(710)->Mark() = 1;LIVE_REGISTERS->Index(711)->Mark() = 0;LIVE_REGISTERS->Index(712)->Mark() = 1;LIVE_REGISTERS->Index(713)->Mark() = 0;LIVE_REGISTERS->Index(714)->Mark() = 0;LIVE_REGISTERS->Index(715)->Mark() = 0;LIVE_REGISTERS->Index(716)->Mark() = 0;LIVE_REGISTERS->Index(717)->Mark() = 0;LIVE_REGISTERS->Index(718)->Mark() = 0;LIVE_REGISTERS->Index(719)->Mark() = 0;LIVE_REGISTERS->Index(720)->Mark() = 0;LIVE_REGISTERS->Index(721)->Mark() = 0;LIVE_REGISTERS->Index(722)->Mark() = 0;LIVE_REGISTERS->Index(723)->Mark() = 0;LIVE_REGISTERS->Index(724)->Mark() = 0;LIVE_REGISTERS->Index(725)->Mark() = 0;LIVE_REGISTERS->Index(726)->Mark() = 0;LIVE_REGISTERS->Index(727)->Mark() = 0;LIVE_REGISTERS->Index(728)->Mark() = 0;LIVE_REGISTERS->Index(729)->Mark() = 0;LIVE_REGISTERS->Index(730)->Mark() = 0;LIVE_REGISTERS->Index(731)->Mark() = 0;LIVE_REGISTERS->Index(732)->Mark() = 0;LIVE_REGISTERS->Index(733)->Mark() = 0;LIVE_REGISTERS->Index(734)->Mark() = 0;LIVE_REGISTERS->Index(735)->Mark() = 0;LIVE_REGISTERS->Index(736)->Mark() = 0;LIVE_REGISTERS->Index(737)->Mark() = 0;LIVE_REGISTERS->Index(738)->Mark() = 0;LIVE_REGISTERS->Index(739)->Mark() = 0;LIVE_REGISTERS->Index(740)->Mark() = 0;LIVE_REGISTERS->Index(741)->Mark() = 1;LIVE_REGISTERS->Index(742)->Mark() = 1;LIVE_REGISTERS->Index(743)->Mark() = 0;LIVE_REGISTERS->Index(744)->Mark() = 1;LIVE_REGISTERS->Index(745)->Mark() = 0;LIVE_REGISTERS->Index(746)->Mark() = -1;LIVE_REGISTERS->Index(747)->Mark() = -1;LIVE_REGISTERS->Index(748)->Mark() = 0;LIVE_REGISTERS->Index(749)->Mark() = -1;LIVE_REGISTERS->Index(750)->Mark() = 0;LIVE_REGISTERS->Index(751)->Mark() = 0;LIVE_REGISTERS->Index(752)->Mark() = 0;LIVE_REGISTERS->Index(753)->Mark() = 0;LIVE_REGISTERS->Index(754)->Mark() = 0;LIVE_REGISTERS->Index(755)->Mark() = 0;LIVE_REGISTERS->Index(756)->Mark() = 0;LIVE_REGISTERS->Index(757)->Mark() = 0;LIVE_REGISTERS->Index(758)->Mark() = 0;LIVE_REGISTERS->Index(759)->Mark() = 0;LIVE_REGISTERS->Index(760)->Mark() = 0;LIVE_REGISTERS->Index(761)->Mark() = 0;LIVE_REGISTERS->Index(762)->Mark() = 0;LIVE_REGISTERS->Index(763)->Mark() = 0;LIVE_REGISTERS->Index(764)->Mark() = 0;LIVE_REGISTERS->Index(765)->Mark() = 0;LIVE_REGISTERS->Index(766)->Mark() = 0;LIVE_REGISTERS->Index(767)->Mark() = 0;LIVE_REGISTERS->Index(768)->Mark() = 0;LIVE_REGISTERS->Index(769)->Mark() = 0;LIVE_REGISTERS->Index(770)->Mark() = 0;LIVE_REGISTERS->Index(771)->Mark() = 0;LIVE_REGISTERS->Index(772)->Mark() = 0;LIVE_REGISTERS->Index(773)->Mark() = 0;LIVE_REGISTERS->Index(774)->Mark() = 0;LIVE_REGISTERS->Index(775)->Mark() = 0;LIVE_REGISTERS->Index(776)->Mark() = 0;LIVE_REGISTERS->Index(777)->Mark() = 0;LIVE_REGISTERS->Index(778)->Mark() = 0;LIVE_REGISTERS->Index(779)->Mark() = 0;LIVE_REGISTERS->Index(780)->Mark() = 0;LIVE_REGISTERS->Index(781)->Mark() = 0;LIVE_REGISTERS->Index(782)->Mark() = 0;LIVE_REGISTERS->Index(783)->Mark() = 0;LIVE_REGISTERS->Index(784)->Mark() = 0;LIVE_REGISTERS->Index(785)->Mark() = 0;LIVE_REGISTERS->Index(786)->Mark() = 0;LIVE_REGISTERS->Index(787)->Mark() = 0;LIVE_REGISTERS->Index(788)->Mark() = 0;LIVE_REGISTERS->Index(789)->Mark() = 0;LIVE_REGISTERS->Index(790)->Mark() = 0;LIVE_REGISTERS->Index(791)->Mark() = 0;LIVE_REGISTERS->Index(792)->Mark() = 0;LIVE_REGISTERS->Index(793)->Mark() = 0;LIVE_REGISTERS->Index(794)->Mark() = 0;LIVE_REGISTERS->Index(795)->Mark() = 0;LIVE_REGISTERS->Index(796)->Mark() = 0;LIVE_REGISTERS->Index(797)->Mark() = 0;LIVE_REGISTERS->Index(798)->Mark() = 0;LIVE_REGISTERS->Index(799)->Mark() = 0;LIVE_REGISTERS->Index(800)->Mark() = 0;LIVE_REGISTERS->Index(801)->Mark() = 0;LIVE_REGISTERS->Index(802)->Mark() = 0;LIVE_REGISTERS->Index(803)->Mark() = 0;LIVE_REGISTERS->Index(804)->Mark() = 0;LIVE_REGISTERS->Index(805)->Mark() = 0;LIVE_REGISTERS->Index(806)->Mark() = 0;LIVE_REGISTERS->Index(807)->Mark() = 0;LIVE_REGISTERS->Index(808)->Mark() = 0;LIVE_REGISTERS->Index(809)->Mark() = 0;LIVE_REGISTERS->Index(810)->Mark() = 0;LIVE_REGISTERS->Index(811)->Mark() = 0;LIVE_REGISTERS->Index(812)->Mark() = 0;LIVE_REGISTERS->Index(813)->Mark() = 0;LIVE_REGISTERS->Index(814)->Mark() = 0;LIVE_REGISTERS->Index(815)->Mark() = 0;LIVE_REGISTERS->Index(816)->Mark() = 0;LIVE_REGISTERS->Index(817)->Mark() = 0;LIVE_REGISTERS->Index(818)->Mark() = 0;LIVE_REGISTERS->Index(819)->Mark() = 0;LIVE_REGISTERS->Index(820)->Mark() = 0;LIVE_REGISTERS->Index(821)->Mark() = 0;LIVE_REGISTERS->Index(822)->Mark() = 0;LIVE_REGISTERS->Index(823)->Mark() = 0;LIVE_REGISTERS->Index(824)->Mark() = 0;LIVE_REGISTERS->Index(825)->Mark() = 0;LIVE_REGISTERS->Index(826)->Mark() = 0;LIVE_REGISTERS->Index(827)->Mark() = 0;LIVE_REGISTERS->Index(828)->Mark() = 0;LIVE_REGISTERS->Index(829)->Mark() = 0;LIVE_REGISTERS->Index(830)->Mark() = 0;LIVE_REGISTERS->Index(831)->Mark() = 0;LIVE_REGISTERS->Index(832)->Mark() = 0;LIVE_REGISTERS->Index(833)->Mark() = 0;LIVE_REGISTERS->Index(834)->Mark() = 0;LIVE_REGISTERS->Index(835)->Mark() = 0;LIVE_REGISTERS->Index(836)->Mark() = 0;LIVE_REGISTERS->Index(837)->Mark() = 0;LIVE_REGISTERS->Index(838)->Mark() = 0;LIVE_REGISTERS->Index(839)->Mark() = 0;LIVE_REGISTERS->Index(840)->Mark() = 0;LIVE_REGISTERS->Index(841)->Mark() = 0;LIVE_REGISTERS->Index(842)->Mark() = 0;LIVE_REGISTERS->Index(843)->Mark() = -1;LIVE_REGISTERS->Index(844)->Mark() = 0;LIVE_REGISTERS->Index(845)->Mark() = 0;LIVE_REGISTERS->Index(846)->Mark() = 0;LIVE_REGISTERS->Index(847)->Mark() = 0;LIVE_REGISTERS->Index(848)->Mark() = 0;LIVE_REGISTERS->Index(849)->Mark() = -1;LIVE_REGISTERS->Index(850)->Mark() = -1;LIVE_REGISTERS->Index(851)->Mark() = 0;LIVE_REGISTERS->Index(852)->Mark() = 0;LIVE_REGISTERS->Index(853)->Mark() = 0;LIVE_REGISTERS->Index(854)->Mark() = 0;LIVE_REGISTERS->Index(855)->Mark() = 0;LIVE_REGISTERS->Index(856)->Mark() = 0;LIVE_REGISTERS->Index(857)->Mark() = 0;LIVE_REGISTERS->Index(858)->Mark() = -2;LIVE_REGISTERS->Index(859)->Mark() = 0;LIVE_REGISTERS->Index(860)->Mark() = 0;LIVE_REGISTERS->Index(861)->Mark() = 0;LIVE_REGISTERS->Index(862)->Mark() = 0;LIVE_REGISTERS->Index(863)->Mark() = 0;LIVE_REGISTERS->Index(864)->Mark() = 0;LIVE_REGISTERS->Index(865)->Mark() = 0;LIVE_REGISTERS->Index(866)->Mark() = 0;LIVE_REGISTERS->Index(867)->Mark() = 0;LIVE_REGISTERS->Index(868)->Mark() = 0;LIVE_REGISTERS->Index(869)->Mark() = 0;LIVE_REGISTERS->Index(870)->Mark() = 0;LIVE_REGISTERS->Index(871)->Mark() = 0;LIVE_REGISTERS->Index(872)->Mark() = 0;LIVE_REGISTERS->Index(873)->Mark() = 0;LIVE_REGISTERS->Index(874)->Mark() = 0;LIVE_REGISTERS->Index(875)->Mark() = 0;LIVE_REGISTERS->Index(876)->Mark() = 0;LIVE_REGISTERS->Index(877)->Mark() = 0;LIVE_REGISTERS->Index(878)->Mark() = 0;LIVE_REGISTERS->Index(879)->Mark() = 0;LIVE_REGISTERS->Index(880)->Mark() = 0;LIVE_REGISTERS->Index(881)->Mark() = 0;LIVE_REGISTERS->Index(882)->Mark() = 0;LIVE_REGISTERS->Index(883)->Mark() = 0;LIVE_REGISTERS->Index(884)->Mark() = 0;LIVE_REGISTERS->Index(885)->Mark() = 0;LIVE_REGISTERS->Index(886)->Mark() = 0;LIVE_REGISTERS->Index(887)->Mark() = 0;LIVE_REGISTERS->Index(888)->Mark() = 0;LIVE_REGISTERS->Index(889)->Mark() = 0;LIVE_REGISTERS->Index(890)->Mark() = 0;LIVE_REGISTERS->Index(891)->Mark() = 0;LIVE_REGISTERS->Index(892)->Mark() = 0;LIVE_REGISTERS->Index(893)->Mark() = -1;LIVE_REGISTERS->Index(894)->Mark() = -3;LIVE_REGISTERS->Index(895)->Mark() = 0;
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

