#ifndef INITIAL_MEMORY_MODELSAN_H_
#define INITIAL_MEMORY_MODELSAN_H_

#include "Cpp/BaseClasses/EmptyGroup.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/state/StructStateVariable.h"
#include "Cpp/BaseClasses/state/ArrayStateVariable.h"
#include "Cpp/BaseClasses/SAN/SANModel.h" 
#include "Cpp/BaseClasses/SAN/Place.h"
#include "Cpp/BaseClasses/SAN/ExtendedPlace.h"
extern Float dram_total_read_prob;
extern Float l2_total_read_prob;
extern UserDistributions* TheDistribution;

void MemoryError();


/*********************************************************************
               INITIAL_MEMORY_MODELSAN Submodel Definition                   
*********************************************************************/

class INITIAL_MEMORY_MODELSAN:public SANModel{
public:

class READ_FROMActivity_case1:public Activity {
public:

  Place* READ_INITIAL_MEMORY;
  short* READ_INITIAL_MEMORY_Mobius_Mark;
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

  Place* READ_INITIAL_MEMORY;
  short* READ_INITIAL_MEMORY_Mobius_Mark;
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

  //List of user-specified place names
  Place* READ_L2;
  Place* READ_INITIAL_MEMORY;
  Place* READ_DRAM;

  // Create instances of all actvities
  READ_FROMActivity_case1 READ_FROM_case1;
  READ_FROMActivity_case2 READ_FROM_case2;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup READ_FROMGroup;

  INITIAL_MEMORY_MODELSAN();
  ~INITIAL_MEMORY_MODELSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end INITIAL_MEMORY_MODELSAN

#endif // INITIAL_MEMORY_MODELSAN_H_
