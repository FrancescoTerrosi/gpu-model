#ifndef RESULT_MEMORY_MODELSAN_H_
#define RESULT_MEMORY_MODELSAN_H_

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
               RESULT_MEMORY_MODELSAN Submodel Definition                   
*********************************************************************/

class RESULT_MEMORY_MODELSAN:public SANModel{
public:

class READ_FROMActivity_case1:public Activity {
public:

  Place* READ_RESULT_MEMORY;
  short* READ_RESULT_MEMORY_Mobius_Mark;
  Place* MEMORY_OK;
  short* MEMORY_OK_Mobius_Mark;

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
  Place* MEMORY_KO;
  short* MEMORY_KO_Mobius_Mark;

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

class WRITE_OKActivity:public Activity {
public:

  Place* WRITE_RESULT_MEMORY;
  short* WRITE_RESULT_MEMORY_Mobius_Mark;
  Place* RESULT_OK;
  short* RESULT_OK_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  WRITE_OKActivity();
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
}; // WRITE_OKActivityActivity

class WRITE_KOActivity:public Activity {
public:

  Place* WRITE_RESULT_MEMORY;
  short* WRITE_RESULT_MEMORY_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;
  Place* KO_CONTENT;
  short* KO_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  WRITE_KOActivity();
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
}; // WRITE_KOActivityActivity

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

class Instantaneous_Activity3Activity:public Activity {
public:

  Place* MEMORY_OK;
  short* MEMORY_OK_Mobius_Mark;
  Place* MEM_OP_COMPLETE;
  short* MEM_OP_COMPLETE_Mobius_Mark;
  Place* OK_READ;
  short* OK_READ_Mobius_Mark;

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

class Instantaneous_Activity4Activity:public Activity {
public:

  Place* MEMORY_KO;
  short* MEMORY_KO_Mobius_Mark;
  Place* MEM_OP_COMPLETE;
  short* MEM_OP_COMPLETE_Mobius_Mark;
  Place* KO_READ;
  short* KO_READ_Mobius_Mark;

  double* TheDistributionParameters;
  Instantaneous_Activity4Activity();
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
}; // Instantaneous_Activity4ActivityActivity

  //List of user-specified place names
  Place* WRITE_RESULT_MEMORY;
  Place* OK_CONTENT;
  Place* KO_CONTENT;
  Place* READ_RESULT_MEMORY;
  Place* MEMORY_OK;
  Place* MEMORY_KO;
  Place* RESULT_OK;
  Place* RESULT_KO;
  Place* MEM_OP_COMPLETE;
  Place* OK_READ;
  Place* KO_READ;

  // Create instances of all actvities
  READ_FROMActivity_case1 READ_FROM_case1;
  READ_FROMActivity_case2 READ_FROM_case2;
  WRITE_OKActivity WRITE_OK;
  WRITE_KOActivity WRITE_KO;
  Instantaneous_Activity1Activity Instantaneous_Activity1;
  Instantaneous_Activity2Activity Instantaneous_Activity2;
  Instantaneous_Activity3Activity Instantaneous_Activity3;
  Instantaneous_Activity4Activity Instantaneous_Activity4;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup READ_FROMGroup;
  PostselectGroup WRITE_OKGroup;
  PostselectGroup WRITE_KOGroup;
  PostselectGroup Instantaneous_Activity1Group;
  PostselectGroup Instantaneous_Activity2Group;
  PostselectGroup Instantaneous_Activity3Group;
  PostselectGroup Instantaneous_Activity4Group;

  RESULT_MEMORY_MODELSAN();
  ~RESULT_MEMORY_MODELSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end RESULT_MEMORY_MODELSAN

#endif // RESULT_MEMORY_MODELSAN_H_
