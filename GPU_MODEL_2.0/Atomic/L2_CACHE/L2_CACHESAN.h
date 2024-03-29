#ifndef L2_CACHESAN_H_
#define L2_CACHESAN_H_

#include "Cpp/BaseClasses/EmptyGroup.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/state/StructStateVariable.h"
#include "Cpp/BaseClasses/state/ArrayStateVariable.h"
#include "Cpp/BaseClasses/SAN/SANModel.h" 
#include "Cpp/BaseClasses/SAN/Place.h"
#include "Cpp/BaseClasses/SAN/ExtendedPlace.h"
extern Short l2_size;
extern UserDistributions* TheDistribution;

void MemoryError();


/*********************************************************************
               L2_CACHESAN Submodel Definition                   
*********************************************************************/

class L2_CACHESAN:public SANModel{
public:

class Instantaneous_Activity23Activity:public Activity {
public:

  Place* KO_CONTENT_TEMP;
  short* KO_CONTENT_TEMP_Mobius_Mark;
  Place* MEM_OP_COMPLETE;
  short* MEM_OP_COMPLETE_Mobius_Mark;

  double* TheDistributionParameters;
  Instantaneous_Activity23Activity();
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
}; // Instantaneous_Activity23ActivityActivity

class WRITE_WITH_KO_DATAActivity:public Activity {
public:

  Place* WRITE_L2;
  short* WRITE_L2_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;
  Place* KO_CONTENT;
  short* KO_CONTENT_Mobius_Mark;
  Place* KO_CONTENT_TEMP;
  short* KO_CONTENT_TEMP_Mobius_Mark;
  Place* REPLACE_CONTENT;
  short* REPLACE_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  WRITE_WITH_KO_DATAActivity();
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
}; // WRITE_WITH_KO_DATAActivityActivity

class Instantaneous_Activity12Activity:public Activity {
public:

  Place* OK_CONTENT_TEMP;
  short* OK_CONTENT_TEMP_Mobius_Mark;
  Place* MEM_OP_COMPLETE;
  short* MEM_OP_COMPLETE_Mobius_Mark;

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

class WRITE_WITH_OK_DATAActivity:public Activity {
public:

  Place* WRITE_L2;
  short* WRITE_L2_Mobius_Mark;
  Place* RESULT_OK;
  short* RESULT_OK_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;
  Place* KO_CONTENT;
  short* KO_CONTENT_Mobius_Mark;
  Place* OK_CONTENT_TEMP;
  short* OK_CONTENT_TEMP_Mobius_Mark;
  Place* REPLACE_CONTENT;
  short* REPLACE_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  WRITE_WITH_OK_DATAActivity();
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
}; // WRITE_WITH_OK_DATAActivityActivity

class Instantaneous_Activity2Activity:public Activity {
public:

  Place* MEMORY_KO;
  short* MEMORY_KO_Mobius_Mark;
  Place* MEM_OP_COMPLETE;
  short* MEM_OP_COMPLETE_Mobius_Mark;
  Place* KO_READ;
  short* KO_READ_Mobius_Mark;

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

class READ_FROMActivity_case1:public Activity {
public:

  Place* READ_L2;
  short* READ_L2_Mobius_Mark;
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

  Place* READ_L2;
  short* READ_L2_Mobius_Mark;
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

class Instantaneous_Activity1Activity:public Activity {
public:

  Place* MEMORY_OK;
  short* MEMORY_OK_Mobius_Mark;
  Place* MEM_OP_COMPLETE;
  short* MEM_OP_COMPLETE_Mobius_Mark;
  Place* OK_READ;
  short* OK_READ_Mobius_Mark;

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

class REPLACEActivity_case1:public Activity {
public:

  Place* REPLACE_CONTENT;
  short* REPLACE_CONTENT_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;
  Place* OK_CONTENT_TEMP;
  short* OK_CONTENT_TEMP_Mobius_Mark;
  Place* KO_CONTENT;
  short* KO_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  REPLACEActivity_case1();
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
}; // REPLACEActivity_case1Activity

class REPLACEActivity_case2:public Activity {
public:

  Place* REPLACE_CONTENT;
  short* REPLACE_CONTENT_Mobius_Mark;
  Place* KO_CONTENT;
  short* KO_CONTENT_Mobius_Mark;
  Place* KO_CONTENT_TEMP;
  short* KO_CONTENT_TEMP_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  REPLACEActivity_case2();
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
}; // REPLACEActivity_case2Activity

  //List of user-specified place names
  Place* KO_CONTENT_TEMP;
  Place* WRITE_L2;
  Place* MEM_OP_COMPLETE;
  Place* OK_CONTENT_TEMP;
  Place* RESULT_KO;
  Place* RESULT_OK;
  Place* KO_READ;
  Place* MEMORY_KO;
  Place* READ_L2;
  Place* MEMORY_OK;
  Place* OK_READ;
  Place* KO_CONTENT;
  Place* OK_CONTENT;
  Place* REPLACE_CONTENT;

  // Create instances of all actvities
  Instantaneous_Activity23Activity Instantaneous_Activity23;
  WRITE_WITH_KO_DATAActivity WRITE_WITH_KO_DATA;
  Instantaneous_Activity12Activity Instantaneous_Activity12;
  WRITE_WITH_OK_DATAActivity WRITE_WITH_OK_DATA;
  Instantaneous_Activity2Activity Instantaneous_Activity2;
  READ_FROMActivity_case1 READ_FROM_case1;
  READ_FROMActivity_case2 READ_FROM_case2;
  Instantaneous_Activity1Activity Instantaneous_Activity1;
  REPLACEActivity_case1 REPLACE_case1;
  REPLACEActivity_case2 REPLACE_case2;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup Instantaneous_Activity23Group;
  PostselectGroup WRITE_WITH_KO_DATAGroup;
  PostselectGroup Instantaneous_Activity12Group;
  PostselectGroup WRITE_WITH_OK_DATAGroup;
  PostselectGroup Instantaneous_Activity2Group;
  PostselectGroup READ_FROMGroup;
  PostselectGroup Instantaneous_Activity1Group;
  PostselectGroup REPLACEGroup;

  L2_CACHESAN();
  ~L2_CACHESAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end L2_CACHESAN

#endif // L2_CACHESAN_H_
