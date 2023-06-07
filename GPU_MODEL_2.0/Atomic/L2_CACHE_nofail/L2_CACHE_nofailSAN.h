#ifndef L2_CACHE_nofailSAN_H_
#define L2_CACHE_nofailSAN_H_

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
               L2_CACHE_nofailSAN Submodel Definition                   
*********************************************************************/

class L2_CACHE_nofailSAN:public SANModel{
public:

class PERFORM_READActivity:public Activity {
public:

  Place* READ_L2;
  short* READ_L2_Mobius_Mark;
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

  Place* WRITE_L2;
  short* WRITE_L2_Mobius_Mark;
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
  Place* READ_L2;
  Place* WRITE_L2;

  // Create instances of all actvities
  PERFORM_READActivity PERFORM_READ;
  PERFORM_WRITEActivity PERFORM_WRITE;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup PERFORM_READGroup;
  PostselectGroup PERFORM_WRITEGroup;

  L2_CACHE_nofailSAN();
  ~L2_CACHE_nofailSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end L2_CACHE_nofailSAN

#endif // L2_CACHE_nofailSAN_H_
