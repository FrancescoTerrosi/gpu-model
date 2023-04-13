#ifndef MEMORYSAN_H_
#define MEMORYSAN_H_

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
               MEMORYSAN Submodel Definition                   
*********************************************************************/

class MEMORYSAN:public SANModel{
public:

class PERFORM_READActivity:public Activity {
public:

  ExtendedPlace<short>* READ;
  Place* WRITE_LOCAL;
  short* WRITE_LOCAL_Mobius_Mark;
  Place* READ_LOCAL;
  short* READ_LOCAL_Mobius_Mark;
  Place* READ_GLOBAL;
  short* READ_GLOBAL_Mobius_Mark;
  Place* READ_REGISTER_FILE;
  short* READ_REGISTER_FILE_Mobius_Mark;

  double* TheDistributionParameters;
  PERFORM_READActivity();
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
}; // PERFORM_READActivityActivity

class LOCAL_READ_FROMActivity_case1:public Activity {
public:

  Place* READ_LOCAL;
  short* READ_LOCAL_Mobius_Mark;
  Place* READ_L1;
  short* READ_L1_Mobius_Mark;
  Place* WARP_ACCESS_L1;
  short* WARP_ACCESS_L1_Mobius_Mark;

  double* TheDistributionParameters;
  LOCAL_READ_FROMActivity_case1();
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
}; // LOCAL_READ_FROMActivity_case1Activity

class LOCAL_READ_FROMActivity_case2:public Activity {
public:

  Place* READ_LOCAL;
  short* READ_LOCAL_Mobius_Mark;
  Place* READ_L2;
  short* READ_L2_Mobius_Mark;
  Place* WARP_ACCESS_L2;
  short* WARP_ACCESS_L2_Mobius_Mark;

  double* TheDistributionParameters;
  LOCAL_READ_FROMActivity_case2();
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
}; // LOCAL_READ_FROMActivity_case2Activity

class LOCAL_READ_FROMActivity_case3:public Activity {
public:

  Place* READ_LOCAL;
  short* READ_LOCAL_Mobius_Mark;
  Place* READ_DRAM;
  short* READ_DRAM_Mobius_Mark;
  Place* WARP_ACCESS_DRAM;
  short* WARP_ACCESS_DRAM_Mobius_Mark;

  double* TheDistributionParameters;
  LOCAL_READ_FROMActivity_case3();
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
}; // LOCAL_READ_FROMActivity_case3Activity

class GLOBAL_READ_FROMActivity_case1:public Activity {
public:

  Place* READ_GLOBAL;
  short* READ_GLOBAL_Mobius_Mark;
  Place* READ_L1;
  short* READ_L1_Mobius_Mark;
  Place* WARP_ACCESS_L1;
  short* WARP_ACCESS_L1_Mobius_Mark;

  double* TheDistributionParameters;
  GLOBAL_READ_FROMActivity_case1();
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
}; // GLOBAL_READ_FROMActivity_case1Activity

class GLOBAL_READ_FROMActivity_case2:public Activity {
public:

  Place* READ_GLOBAL;
  short* READ_GLOBAL_Mobius_Mark;
  Place* READ_L2;
  short* READ_L2_Mobius_Mark;
  Place* WARP_ACCESS_L2;
  short* WARP_ACCESS_L2_Mobius_Mark;

  double* TheDistributionParameters;
  GLOBAL_READ_FROMActivity_case2();
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
}; // GLOBAL_READ_FROMActivity_case2Activity

class GLOBAL_READ_FROMActivity_case3:public Activity {
public:

  Place* READ_GLOBAL;
  short* READ_GLOBAL_Mobius_Mark;
  Place* READ_DRAM;
  short* READ_DRAM_Mobius_Mark;
  Place* WARP_ACCESS_DRAM;
  short* WARP_ACCESS_DRAM_Mobius_Mark;

  double* TheDistributionParameters;
  GLOBAL_READ_FROMActivity_case3();
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
}; // GLOBAL_READ_FROMActivity_case3Activity

class PERFORM_WRITEActivity:public Activity {
public:

  ExtendedPlace<short>* WRITE;
  Place* WRITE_GLOBAL;
  short* WRITE_GLOBAL_Mobius_Mark;
  Place* WRITE_LOCAL;
  short* WRITE_LOCAL_Mobius_Mark;
  Place* WRITE_REGISTER_FILE;
  short* WRITE_REGISTER_FILE_Mobius_Mark;

  double* TheDistributionParameters;
  PERFORM_WRITEActivity();
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
}; // PERFORM_WRITEActivityActivity

class LOCAL_WRITE_TOActivity_case1:public Activity {
public:

  Place* WRITE_LOCAL;
  short* WRITE_LOCAL_Mobius_Mark;
  Place* WRITE_L1;
  short* WRITE_L1_Mobius_Mark;
  Place* WARP_ACCESS_L1;
  short* WARP_ACCESS_L1_Mobius_Mark;

  double* TheDistributionParameters;
  LOCAL_WRITE_TOActivity_case1();
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
}; // LOCAL_WRITE_TOActivity_case1Activity

class LOCAL_WRITE_TOActivity_case2:public Activity {
public:

  Place* WRITE_LOCAL;
  short* WRITE_LOCAL_Mobius_Mark;
  Place* WRITE_L2;
  short* WRITE_L2_Mobius_Mark;
  Place* WARP_ACCESS_L2;
  short* WARP_ACCESS_L2_Mobius_Mark;

  double* TheDistributionParameters;
  LOCAL_WRITE_TOActivity_case2();
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
}; // LOCAL_WRITE_TOActivity_case2Activity

class LOCAL_WRITE_TOActivity_case3:public Activity {
public:

  Place* WRITE_LOCAL;
  short* WRITE_LOCAL_Mobius_Mark;
  Place* WRITE_DRAM;
  short* WRITE_DRAM_Mobius_Mark;
  Place* WARP_ACCESS_DRAM;
  short* WARP_ACCESS_DRAM_Mobius_Mark;

  double* TheDistributionParameters;
  LOCAL_WRITE_TOActivity_case3();
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
}; // LOCAL_WRITE_TOActivity_case3Activity

class GLOBAL_WRITE_TOActivity_case1:public Activity {
public:

  Place* WRITE_GLOBAL;
  short* WRITE_GLOBAL_Mobius_Mark;
  Place* WRITE_L1;
  short* WRITE_L1_Mobius_Mark;
  Place* WARP_ACCESS_L1;
  short* WARP_ACCESS_L1_Mobius_Mark;

  double* TheDistributionParameters;
  GLOBAL_WRITE_TOActivity_case1();
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
}; // GLOBAL_WRITE_TOActivity_case1Activity

class GLOBAL_WRITE_TOActivity_case2:public Activity {
public:

  Place* WRITE_GLOBAL;
  short* WRITE_GLOBAL_Mobius_Mark;
  Place* WRITE_L2;
  short* WRITE_L2_Mobius_Mark;
  Place* WARP_ACCESS_L2;
  short* WARP_ACCESS_L2_Mobius_Mark;

  double* TheDistributionParameters;
  GLOBAL_WRITE_TOActivity_case2();
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
}; // GLOBAL_WRITE_TOActivity_case2Activity

class GLOBAL_WRITE_TOActivity_case3:public Activity {
public:

  Place* WRITE_GLOBAL;
  short* WRITE_GLOBAL_Mobius_Mark;
  Place* WRITE_DRAM;
  short* WRITE_DRAM_Mobius_Mark;
  Place* WARP_ACCESS_DRAM;
  short* WARP_ACCESS_DRAM_Mobius_Mark;

  double* TheDistributionParameters;
  GLOBAL_WRITE_TOActivity_case3();
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
}; // GLOBAL_WRITE_TOActivity_case3Activity

  //List of user-specified place names
  Place* READ_L1;
  Place* READ_L2;
  Place* READ_DRAM;
  Place* READ_LOCAL;
  Place* READ_GLOBAL;
  Place* WRITE_LOCAL;
  Place* WRITE_GLOBAL;
  Place* WRITE_L1;
  Place* WRITE_L2;
  Place* WRITE_DRAM;
  Place* READ_REGISTER_FILE;
  Place* WRITE_REGISTER_FILE;
  Place* WARP_ACCESS_L1;
  Place* WARP_ACCESS_L2;
  Place* WARP_ACCESS_DRAM;
  ExtendedPlace<short>* READ;
  ExtendedPlace<short>* WRITE;

  // Create instances of all actvities
  PERFORM_READActivity PERFORM_READ;
  LOCAL_READ_FROMActivity_case1 LOCAL_READ_FROM_case1;
  LOCAL_READ_FROMActivity_case2 LOCAL_READ_FROM_case2;
  LOCAL_READ_FROMActivity_case3 LOCAL_READ_FROM_case3;
  GLOBAL_READ_FROMActivity_case1 GLOBAL_READ_FROM_case1;
  GLOBAL_READ_FROMActivity_case2 GLOBAL_READ_FROM_case2;
  GLOBAL_READ_FROMActivity_case3 GLOBAL_READ_FROM_case3;
  PERFORM_WRITEActivity PERFORM_WRITE;
  LOCAL_WRITE_TOActivity_case1 LOCAL_WRITE_TO_case1;
  LOCAL_WRITE_TOActivity_case2 LOCAL_WRITE_TO_case2;
  LOCAL_WRITE_TOActivity_case3 LOCAL_WRITE_TO_case3;
  GLOBAL_WRITE_TOActivity_case1 GLOBAL_WRITE_TO_case1;
  GLOBAL_WRITE_TOActivity_case2 GLOBAL_WRITE_TO_case2;
  GLOBAL_WRITE_TOActivity_case3 GLOBAL_WRITE_TO_case3;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup PERFORM_READGroup;
  PostselectGroup LOCAL_READ_FROMGroup;
  PostselectGroup GLOBAL_READ_FROMGroup;
  PostselectGroup PERFORM_WRITEGroup;
  PostselectGroup LOCAL_WRITE_TOGroup;
  PostselectGroup GLOBAL_WRITE_TOGroup;

  MEMORYSAN();
  ~MEMORYSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end MEMORYSAN

#endif // MEMORYSAN_H_
