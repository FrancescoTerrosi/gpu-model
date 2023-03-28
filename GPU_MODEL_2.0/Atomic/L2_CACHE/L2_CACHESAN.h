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

  Place* ROUTE_READ;
  short* ROUTE_READ_Mobius_Mark;
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

  Place* ROUTE_READ;
  short* ROUTE_READ_Mobius_Mark;
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

class Instantaneous_Activity4Activity:public Activity {
public:

  Place* READ_L2;
  short* READ_L2_Mobius_Mark;
  Place* MEM_FAILURE;
  short* MEM_FAILURE_Mobius_Mark;
  Place* MEMORY_KO;
  short* MEMORY_KO_Mobius_Mark;
  Place* MEM_FAILURE_COUNT;
  short* MEM_FAILURE_COUNT_Mobius_Mark;
  Place* ROUTE_READ;
  short* ROUTE_READ_Mobius_Mark;

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

class dhnActivity:public Activity {
public:

  Place* MEM_FAILURE_COUNT;
  short* MEM_FAILURE_COUNT_Mobius_Mark;
  Place* Place1;
  short* Place1_Mobius_Mark;

  double* TheDistributionParameters;
  dhnActivity();
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
}; // dhnActivityActivity

class Instantaneous_Activity3Activity_case1:public Activity {
public:

  Place* ROUTE_WRITE;
  short* ROUTE_WRITE_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;
  Place* KO_CONTENT;
  short* KO_CONTENT_Mobius_Mark;
  Place* OK_CONTENT_TEMP;
  short* OK_CONTENT_TEMP_Mobius_Mark;
  Place* REPLACE_CONTENT_OK;
  short* REPLACE_CONTENT_OK_Mobius_Mark;

  double* TheDistributionParameters;
  Instantaneous_Activity3Activity_case1();
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
}; // Instantaneous_Activity3Activity_case1Activity

class Instantaneous_Activity3Activity_case2:public Activity {
public:

  Place* ROUTE_WRITE;
  short* ROUTE_WRITE_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;
  Place* KO_CONTENT;
  short* KO_CONTENT_Mobius_Mark;
  Place* KO_CONTENT_TEMP;
  short* KO_CONTENT_TEMP_Mobius_Mark;
  Place* REPLACE_CONTENT_KO;
  short* REPLACE_CONTENT_KO_Mobius_Mark;

  double* TheDistributionParameters;
  Instantaneous_Activity3Activity_case2();
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
}; // Instantaneous_Activity3Activity_case2Activity

class Instantaneous_Activity5Activity:public Activity {
public:

  Place* WRITE_L2;
  short* WRITE_L2_Mobius_Mark;
  Place* MEM_FAILURE;
  short* MEM_FAILURE_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;
  Place* KO_CONTENT;
  short* KO_CONTENT_Mobius_Mark;
  Place* KO_CONTENT_TEMP;
  short* KO_CONTENT_TEMP_Mobius_Mark;
  Place* REPLACE_CONTENT_KO;
  short* REPLACE_CONTENT_KO_Mobius_Mark;
  Place* MEM_FAILURE_COUNT;
  short* MEM_FAILURE_COUNT_Mobius_Mark;
  Place* ROUTE_WRITE;
  short* ROUTE_WRITE_Mobius_Mark;

  double* TheDistributionParameters;
  Instantaneous_Activity5Activity();
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
}; // Instantaneous_Activity5ActivityActivity

class REPLACEActivity_case1:public Activity {
public:

  Place* REPLACE_CONTENT_OK;
  short* REPLACE_CONTENT_OK_Mobius_Mark;
  Place* OK_CONTENT_TEMP;
  short* OK_CONTENT_TEMP_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;

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

  Place* REPLACE_CONTENT_OK;
  short* REPLACE_CONTENT_OK_Mobius_Mark;
  Place* KO_CONTENT_TEMP;
  short* KO_CONTENT_TEMP_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;
  Place* KO_CONTENT;
  short* KO_CONTENT_Mobius_Mark;

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

class REPLACE_KOActivity_case1:public Activity {
public:

  Place* REPLACE_CONTENT_KO;
  short* REPLACE_CONTENT_KO_Mobius_Mark;
  Place* KO_CONTENT_TEMP;
  short* KO_CONTENT_TEMP_Mobius_Mark;

  double* TheDistributionParameters;
  REPLACE_KOActivity_case1();
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
}; // REPLACE_KOActivity_case1Activity

class REPLACE_KOActivity_case2:public Activity {
public:

  Place* REPLACE_CONTENT_KO;
  short* REPLACE_CONTENT_KO_Mobius_Mark;
  Place* KO_CONTENT_TEMP;
  short* KO_CONTENT_TEMP_Mobius_Mark;
  Place* KO_CONTENT;
  short* KO_CONTENT_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  REPLACE_KOActivity_case2();
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
}; // REPLACE_KOActivity_case2Activity

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

  //List of user-specified place names
  Place* MEM_OP_COMPLETE;
  Place* KO_READ;
  Place* MEMORY_KO;
  Place* READ_L2;
  Place* MEMORY_OK;
  Place* OK_READ;
  Place* MEM_FAILURE;
  Place* ROUTE_READ;
  Place* MEM_FAILURE_COUNT;
  Place* Place1;
  Place* WRITE_L2;
  Place* ROUTE_WRITE;
  Place* REPLACE_CONTENT_OK;
  Place* REPLACE_CONTENT_KO;
  Place* KO_CONTENT_TEMP;
  Place* OK_CONTENT_TEMP;
  Place* OK_CONTENT;
  Place* KO_CONTENT;

  // Create instances of all actvities
  Instantaneous_Activity2Activity Instantaneous_Activity2;
  READ_FROMActivity_case1 READ_FROM_case1;
  READ_FROMActivity_case2 READ_FROM_case2;
  Instantaneous_Activity1Activity Instantaneous_Activity1;
  Instantaneous_Activity4Activity Instantaneous_Activity4;
  dhnActivity dhn;
  Instantaneous_Activity3Activity_case1 Instantaneous_Activity3_case1;
  Instantaneous_Activity3Activity_case2 Instantaneous_Activity3_case2;
  Instantaneous_Activity5Activity Instantaneous_Activity5;
  REPLACEActivity_case1 REPLACE_case1;
  REPLACEActivity_case2 REPLACE_case2;
  REPLACE_KOActivity_case1 REPLACE_KO_case1;
  REPLACE_KOActivity_case2 REPLACE_KO_case2;
  Instantaneous_Activity23Activity Instantaneous_Activity23;
  Instantaneous_Activity12Activity Instantaneous_Activity12;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup Instantaneous_Activity2Group;
  PostselectGroup READ_FROMGroup;
  PostselectGroup Instantaneous_Activity1Group;
  PostselectGroup Instantaneous_Activity4Group;
  PostselectGroup dhnGroup;
  PostselectGroup Instantaneous_Activity3Group;
  PostselectGroup Instantaneous_Activity5Group;
  PostselectGroup REPLACEGroup;
  PostselectGroup REPLACE_KOGroup;
  PostselectGroup Instantaneous_Activity23Group;
  PostselectGroup Instantaneous_Activity12Group;

  L2_CACHESAN();
  ~L2_CACHESAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end L2_CACHESAN

#endif // L2_CACHESAN_H_
