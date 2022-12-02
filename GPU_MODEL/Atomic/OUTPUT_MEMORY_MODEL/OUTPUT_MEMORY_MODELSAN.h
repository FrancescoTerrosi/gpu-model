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

class WRITE_TOActivity:public Activity {
public:

  Place* WRITE_OUTPUT_MEMORY;
  short* WRITE_OUTPUT_MEMORY_Mobius_Mark;
  Place* WRITE_DRAM;
  short* WRITE_DRAM_Mobius_Mark;

  double* TheDistributionParameters;
  WRITE_TOActivity();
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
}; // WRITE_TOActivityActivity

  //List of user-specified place names
  Place* WRITE_OUTPUT_MEMORY;
  Place* WRITE_DRAM;

  // Create instances of all actvities
  WRITE_TOActivity WRITE_TO;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup WRITE_TOGroup;

  OUTPUT_MEMORY_MODELSAN();
  ~OUTPUT_MEMORY_MODELSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end OUTPUT_MEMORY_MODELSAN

#endif // OUTPUT_MEMORY_MODELSAN_H_
