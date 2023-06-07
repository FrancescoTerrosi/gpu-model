#ifndef DRAM_nofailSAN_H_
#define DRAM_nofailSAN_H_

#include "Cpp/BaseClasses/EmptyGroup.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/state/StructStateVariable.h"
#include "Cpp/BaseClasses/state/ArrayStateVariable.h"
#include "Cpp/BaseClasses/SAN/SANModel.h" 
#include "Cpp/BaseClasses/SAN/Place.h"
#include "Cpp/BaseClasses/SAN/ExtendedPlace.h"
extern Short dram_size;
extern UserDistributions* TheDistribution;

void MemoryError();


/*********************************************************************
               DRAM_nofailSAN Submodel Definition                   
*********************************************************************/

class DRAM_nofailSAN:public SANModel{
public:

class PERFORM_READActivity:public Activity {
public:

  Place* READ_DRAM;
  short* READ_DRAM_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;

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

  Place* WRITE_DRAM;
  short* WRITE_DRAM_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;

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
  Place* INSTRUCTION_READY;
  Place* READ_DRAM;
  Place* WRITE_DRAM;

  // Create instances of all actvities
  PERFORM_READActivity PERFORM_READ;
  PERFORM_WRITEActivity PERFORM_WRITE;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup PERFORM_READGroup;
  PostselectGroup PERFORM_WRITEGroup;

  DRAM_nofailSAN();
  ~DRAM_nofailSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end DRAM_nofailSAN

#endif // DRAM_nofailSAN_H_
