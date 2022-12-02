#ifndef MEMORY_MODELSAN_H_
#define MEMORY_MODELSAN_H_

#include "Cpp/BaseClasses/EmptyGroup.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/state/StructStateVariable.h"
#include "Cpp/BaseClasses/state/ArrayStateVariable.h"
#include "Cpp/BaseClasses/SAN/SANModel.h" 
#include "Cpp/BaseClasses/SAN/Place.h"
#include "Cpp/BaseClasses/SAN/ExtendedPlace.h"
extern UserDistributions* TheDistribution;

void MemoryError();


/*********************************************************************
               MEMORY_MODELSAN Submodel Definition                   
*********************************************************************/

class MEMORY_MODELSAN:public SANModel{
public:

class T_READActivity_case1:public Activity {
public:

  Place* READ;
  short* READ_Mobius_Mark;
  Place* PERFORM_OK_READ;
  short* PERFORM_OK_READ_Mobius_Mark;

  double* TheDistributionParameters;
  T_READActivity_case1();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // T_READActivity_case1Activity

class T_READActivity_case2:public Activity {
public:

  Place* READ;
  short* READ_Mobius_Mark;
  Place* PERFORM_KO_READ;
  short* PERFORM_KO_READ_Mobius_Mark;

  double* TheDistributionParameters;
  T_READActivity_case2();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // T_READActivity_case2Activity

class T_WRITEActivity_case1:public Activity {
public:

  Place* WRITE;
  short* WRITE_Mobius_Mark;
  Place* L2_OK_CONTENT;
  short* L2_OK_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  T_WRITEActivity_case1();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // T_WRITEActivity_case1Activity

class T_WRITEActivity_case2:public Activity {
public:

  Place* WRITE;
  short* WRITE_Mobius_Mark;
  Place* L2_KO_CONTENT;
  short* L2_KO_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  T_WRITEActivity_case2();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // T_WRITEActivity_case2Activity

class REGISTER_FILE_INActivity:public Activity {
public:

  Place* PERFORM_OK_READ;
  short* PERFORM_OK_READ_Mobius_Mark;
  Place* PERFORM_KO_READ;
  short* PERFORM_KO_READ_Mobius_Mark;
  Place* READ_DATA_IS_OK;
  short* READ_DATA_IS_OK_Mobius_Mark;
  Place* READ_DATA_IS_KO;
  short* READ_DATA_IS_KO_Mobius_Mark;

  double* TheDistributionParameters;
  REGISTER_FILE_INActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // REGISTER_FILE_INActivityActivity

class FORWARD_TO_DRAM_IF_FULL_OR_FINISHActivity:public Activity {
public:

  Place* L2_OK_CONTENT;
  short* L2_OK_CONTENT_Mobius_Mark;
  Place* L2_KO_CONTENT;
  short* L2_KO_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  FORWARD_TO_DRAM_IF_FULL_OR_FINISHActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // FORWARD_TO_DRAM_IF_FULL_OR_FINISHActivityActivity

  //List of user-specified place names
  Place* READ;
  Place* WRITE;
  Place* L2_OK_CONTENT;
  Place* L2_KO_CONTENT;
  Place* PERFORM_OK_READ;
  Place* PERFORM_KO_READ;
  Place* READ_DATA_IS_OK;
  Place* READ_DATA_IS_KO;

  // Create instances of all actvities
  T_READActivity_case1 T_READ_case1;
  T_READActivity_case2 T_READ_case2;
  T_WRITEActivity_case1 T_WRITE_case1;
  T_WRITEActivity_case2 T_WRITE_case2;
  REGISTER_FILE_INActivity REGISTER_FILE_IN;
  FORWARD_TO_DRAM_IF_FULL_OR_FINISHActivity FORWARD_TO_DRAM_IF_FULL_OR_FINISH;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup T_READGroup;
  PostselectGroup T_WRITEGroup;
  PostselectGroup REGISTER_FILE_INGroup;
  PostselectGroup FORWARD_TO_DRAM_IF_FULL_OR_FINISHGroup;

  MEMORY_MODELSAN();
  ~MEMORY_MODELSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end MEMORY_MODELSAN

#endif // MEMORY_MODELSAN_H_
