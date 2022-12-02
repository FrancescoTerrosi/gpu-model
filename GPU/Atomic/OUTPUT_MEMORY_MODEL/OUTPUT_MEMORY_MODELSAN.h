#ifndef OUTPUT_MEMORY_MODELSAN_H_
#define OUTPUT_MEMORY_MODELSAN_H_

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
               OUTPUT_MEMORY_MODELSAN Submodel Definition                   
*********************************************************************/

class OUTPUT_MEMORY_MODELSAN:public SANModel{
public:

class Instantaneous_Activity1Activity:public Activity {
public:

  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;
  Place* MEM_OP_COMPLETE;
  short* MEM_OP_COMPLETE_Mobius_Mark;

  double* TheDistributionParameters;
  Instantaneous_Activity1Activity();
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
}; // Instantaneous_Activity1ActivityActivity

class Instantaneous_Activity2Activity:public Activity {
public:

  Place* KO_CONTENT;
  short* KO_CONTENT_Mobius_Mark;
  Place* MEM_OP_COMPLETE;
  short* MEM_OP_COMPLETE_Mobius_Mark;

  double* TheDistributionParameters;
  Instantaneous_Activity2Activity();
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
}; // Instantaneous_Activity2ActivityActivity

class Instantaneous_Activity12Activity:public Activity {
public:

  Place* RESULT_OK;
  short* RESULT_OK_Mobius_Mark;
  Place* WRITE_OUTPUT_MEMORY;
  short* WRITE_OUTPUT_MEMORY_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  Instantaneous_Activity12Activity();
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
}; // Instantaneous_Activity12ActivityActivity

class Instantaneous_Activity3Activity:public Activity {
public:

  Place* WRITE_OUTPUT_MEMORY;
  short* WRITE_OUTPUT_MEMORY_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;
  Place* KO_CONTENT;
  short* KO_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  Instantaneous_Activity3Activity();
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
}; // Instantaneous_Activity3ActivityActivity

  //List of user-specified place names
  Place* WRITE_OUTPUT_MEMORY;
  Place* OK_CONTENT;
  Place* KO_CONTENT;
  Place* MEM_OP_COMPLETE;
  Place* RESULT_OK;
  Place* RESULT_KO;

  // Create instances of all actvities
  Instantaneous_Activity1Activity Instantaneous_Activity1;
  Instantaneous_Activity2Activity Instantaneous_Activity2;
  Instantaneous_Activity12Activity Instantaneous_Activity12;
  Instantaneous_Activity3Activity Instantaneous_Activity3;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup Instantaneous_Activity1Group;
  PostselectGroup Instantaneous_Activity2Group;
  PostselectGroup Instantaneous_Activity12Group;
  PostselectGroup Instantaneous_Activity3Group;

  OUTPUT_MEMORY_MODELSAN();
  ~OUTPUT_MEMORY_MODELSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end OUTPUT_MEMORY_MODELSAN

#endif // OUTPUT_MEMORY_MODELSAN_H_
