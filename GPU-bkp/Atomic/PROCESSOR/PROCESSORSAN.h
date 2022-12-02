#ifndef PROCESSORSAN_H_
#define PROCESSORSAN_H_

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
               PROCESSORSAN Submodel Definition                   
*********************************************************************/

class PROCESSORSAN:public SANModel{
public:

class SCHEDULE_WARPActivity_case1:public Activity {
public:

  Place* INSTRUCTIONS_POOL;
  short* INSTRUCTIONS_POOL_Mobius_Mark;
  Place* READ_P;
  short* READ_P_Mobius_Mark;

  double* TheDistributionParameters;
  SCHEDULE_WARPActivity_case1();
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
}; // SCHEDULE_WARPActivity_case1Activity

class SCHEDULE_WARPActivity_case2:public Activity {
public:

  Place* INSTRUCTIONS_POOL;
  short* INSTRUCTIONS_POOL_Mobius_Mark;
  Place* WRITE_P;
  short* WRITE_P_Mobius_Mark;

  double* TheDistributionParameters;
  SCHEDULE_WARPActivity_case2();
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
}; // SCHEDULE_WARPActivity_case2Activity

class SCHEDULE_WARPActivity_case3:public Activity {
public:

  Place* INSTRUCTIONS_POOL;
  short* INSTRUCTIONS_POOL_Mobius_Mark;
  Place* ALU;
  short* ALU_Mobius_Mark;

  double* TheDistributionParameters;
  SCHEDULE_WARPActivity_case3();
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
}; // SCHEDULE_WARPActivity_case3Activity

class READ_FROMActivity_case1:public Activity {
public:

  Place* READ_P;
  short* READ_P_Mobius_Mark;
  Place* TOTAL_MEMORY;
  short* TOTAL_MEMORY_Mobius_Mark;

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

  Place* READ_P;
  short* READ_P_Mobius_Mark;
  Place* RESULT_MEMORY;
  short* RESULT_MEMORY_Mobius_Mark;

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

class WRITE_TOActivity_case1:public Activity {
public:

  Place* WRITE_P;
  short* WRITE_P_Mobius_Mark;
  Place* RESULT_OK;
  short* RESULT_OK_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;
  Place* RESULT_MEMORY;
  short* RESULT_MEMORY_Mobius_Mark;

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

  Place* WRITE_P;
  short* WRITE_P_Mobius_Mark;
  Place* RESULT_OK;
  short* RESULT_OK_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;
  Place* OUTPUT_MEMORY;
  short* OUTPUT_MEMORY_Mobius_Mark;

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

class COMPUTEActivity_case1:public Activity {
public:

  Place* ALU;
  short* ALU_Mobius_Mark;
  Place* READ_DATA_IS_OK;
  short* READ_DATA_IS_OK_Mobius_Mark;
  Place* READ_DATA_IS_KO;
  short* READ_DATA_IS_KO_Mobius_Mark;
  Place* RESULT_OK;
  short* RESULT_OK_Mobius_Mark;

  double* TheDistributionParameters;
  COMPUTEActivity_case1();
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
}; // COMPUTEActivity_case1Activity

class COMPUTEActivity_case2:public Activity {
public:

  Place* ALU;
  short* ALU_Mobius_Mark;
  Place* READ_DATA_IS_OK;
  short* READ_DATA_IS_OK_Mobius_Mark;
  Place* READ_DATA_IS_KO;
  short* READ_DATA_IS_KO_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;

  double* TheDistributionParameters;
  COMPUTEActivity_case2();
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
}; // COMPUTEActivity_case2Activity

class REGISTER_FILE_INActivity_case1:public Activity {
public:

  Place* READ;
  short* READ_Mobius_Mark;
  Place* READ_DATA_IS_OK;
  short* READ_DATA_IS_OK_Mobius_Mark;

  double* TheDistributionParameters;
  REGISTER_FILE_INActivity_case1();
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
}; // REGISTER_FILE_INActivity_case1Activity

class REGISTER_FILE_INActivity_case2:public Activity {
public:

  Place* READ;
  short* READ_Mobius_Mark;
  Place* READ_DATA_IS_KO;
  short* READ_DATA_IS_KO_Mobius_Mark;

  double* TheDistributionParameters;
  REGISTER_FILE_INActivity_case2();
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
}; // REGISTER_FILE_INActivity_case2Activity

class PERFORM_READActivity:public Activity {
public:

  Place* TOTAL_MEMORY;
  short* TOTAL_MEMORY_Mobius_Mark;
  Place* RESULT_MEMORY;
  short* RESULT_MEMORY_Mobius_Mark;
  Place* READ;
  short* READ_Mobius_Mark;

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

class PERFORM_WRITEActivity:public Activity {
public:

  Place* RESULT_MEMORY;
  short* RESULT_MEMORY_Mobius_Mark;
  Place* OUTPUT_MEMORY;
  short* OUTPUT_MEMORY_Mobius_Mark;
  Place* WRITE;
  short* WRITE_Mobius_Mark;

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

  //List of user-specified place names
  Place* INSTRUCTIONS_POOL;
  Place* READ_P;
  Place* WRITE_P;
  Place* ALU;
  Place* TOTAL_MEMORY;
  Place* RESULT_MEMORY;
  Place* OUTPUT_MEMORY;
  Place* RESULT_OK;
  Place* RESULT_KO;
  Place* READ_DATA_IS_OK;
  Place* READ_DATA_IS_KO;
  Place* READ;
  Place* WRITE;

  // Create instances of all actvities
  SCHEDULE_WARPActivity_case1 SCHEDULE_WARP_case1;
  SCHEDULE_WARPActivity_case2 SCHEDULE_WARP_case2;
  SCHEDULE_WARPActivity_case3 SCHEDULE_WARP_case3;
  READ_FROMActivity_case1 READ_FROM_case1;
  READ_FROMActivity_case2 READ_FROM_case2;
  WRITE_TOActivity_case1 WRITE_TO_case1;
  WRITE_TOActivity_case2 WRITE_TO_case2;
  COMPUTEActivity_case1 COMPUTE_case1;
  COMPUTEActivity_case2 COMPUTE_case2;
  REGISTER_FILE_INActivity_case1 REGISTER_FILE_IN_case1;
  REGISTER_FILE_INActivity_case2 REGISTER_FILE_IN_case2;
  PERFORM_READActivity PERFORM_READ;
  PERFORM_WRITEActivity PERFORM_WRITE;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup SCHEDULE_WARPGroup;
  PostselectGroup READ_FROMGroup;
  PostselectGroup WRITE_TOGroup;
  PostselectGroup COMPUTEGroup;
  PostselectGroup REGISTER_FILE_INGroup;
  PostselectGroup PERFORM_READGroup;
  PostselectGroup PERFORM_WRITEGroup;

  PROCESSORSAN();
  ~PROCESSORSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end PROCESSORSAN

#endif // PROCESSORSAN_H_
