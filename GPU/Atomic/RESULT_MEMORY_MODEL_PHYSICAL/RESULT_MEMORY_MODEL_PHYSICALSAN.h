#ifndef RESULT_MEMORY_MODEL_PHYSICALSAN_H_
#define RESULT_MEMORY_MODEL_PHYSICALSAN_H_

#include "Cpp/BaseClasses/EmptyGroup.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/state/StructStateVariable.h"
#include "Cpp/BaseClasses/state/ArrayStateVariable.h"
#include "Cpp/BaseClasses/SAN/SANModel.h" 
#include "Cpp/BaseClasses/SAN/Place.h"
#include "Cpp/BaseClasses/SAN/ExtendedPlace.h"
extern Float dram_result_read_rate;
extern Float l2_result_read_rate;
extern Float l1_result_read_rate;
extern Float dram_result_write_rate;
extern Float l2_result_write_rate;
extern Float l1_result_write_rate;
extern UserDistributions* TheDistribution;

void MemoryError();


/*********************************************************************
               RESULT_MEMORY_MODEL_PHYSICALSAN Submodel Definition                   
*********************************************************************/

class RESULT_MEMORY_MODEL_PHYSICALSAN:public SANModel{
public:

class READ_FROMActivity_case1:public Activity {
public:

  Place* READ_RESULT_MEMORY;
  short* READ_RESULT_MEMORY_Mobius_Mark;
  Place* READ_DRAM;
  short* READ_DRAM_Mobius_Mark;

  double* TheDistributionParameters;
  READ_FROMActivity_case1();
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
}; // READ_FROMActivity_case1Activity

class READ_FROMActivity_case2:public Activity {
public:

  Place* READ_RESULT_MEMORY;
  short* READ_RESULT_MEMORY_Mobius_Mark;
  Place* READ_L2;
  short* READ_L2_Mobius_Mark;

  double* TheDistributionParameters;
  READ_FROMActivity_case2();
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
}; // READ_FROMActivity_case2Activity

class READ_FROMActivity_case3:public Activity {
public:

  Place* READ_RESULT_MEMORY;
  short* READ_RESULT_MEMORY_Mobius_Mark;
  Place* READ_L1;
  short* READ_L1_Mobius_Mark;

  double* TheDistributionParameters;
  READ_FROMActivity_case3();
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
}; // READ_FROMActivity_case3Activity

class WRITE_TOActivity_case1:public Activity {
public:

  Place* WRITE_RESULT_MEMORY;
  short* WRITE_RESULT_MEMORY_Mobius_Mark;
  Place* WRITE_DRAM;
  short* WRITE_DRAM_Mobius_Mark;

  double* TheDistributionParameters;
  WRITE_TOActivity_case1();
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
}; // WRITE_TOActivity_case1Activity

class WRITE_TOActivity_case2:public Activity {
public:

  Place* WRITE_RESULT_MEMORY;
  short* WRITE_RESULT_MEMORY_Mobius_Mark;
  Place* WRITE_L2;
  short* WRITE_L2_Mobius_Mark;

  double* TheDistributionParameters;
  WRITE_TOActivity_case2();
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
}; // WRITE_TOActivity_case2Activity

class WRITE_TOActivity_case3:public Activity {
public:

  Place* WRITE_RESULT_MEMORY;
  short* WRITE_RESULT_MEMORY_Mobius_Mark;
  Place* WRITE_L1;
  short* WRITE_L1_Mobius_Mark;

  double* TheDistributionParameters;
  WRITE_TOActivity_case3();
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
}; // WRITE_TOActivity_case3Activity

  //List of user-specified place names
  Place* WRITE_RESULT_MEMORY;
  Place* READ_RESULT_MEMORY;
  Place* READ_DRAM;
  Place* READ_L2;
  Place* READ_L1;
  Place* WRITE_DRAM;
  Place* WRITE_L2;
  Place* WRITE_L1;

  // Create instances of all actvities
  READ_FROMActivity_case1 READ_FROM_case1;
  READ_FROMActivity_case2 READ_FROM_case2;
  READ_FROMActivity_case3 READ_FROM_case3;
  WRITE_TOActivity_case1 WRITE_TO_case1;
  WRITE_TOActivity_case2 WRITE_TO_case2;
  WRITE_TOActivity_case3 WRITE_TO_case3;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup READ_FROMGroup;
  PostselectGroup WRITE_TOGroup;

  RESULT_MEMORY_MODEL_PHYSICALSAN();
  ~RESULT_MEMORY_MODEL_PHYSICALSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end RESULT_MEMORY_MODEL_PHYSICALSAN

#endif // RESULT_MEMORY_MODEL_PHYSICALSAN_H_
