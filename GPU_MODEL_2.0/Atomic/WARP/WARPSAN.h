#ifndef WARPSAN_H_
#define WARPSAN_H_

#include "Cpp/BaseClasses/EmptyGroup.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/state/StructStateVariable.h"
#include "Cpp/BaseClasses/state/ArrayStateVariable.h"
#include "Cpp/BaseClasses/SAN/SANModel.h" 
#include "Cpp/BaseClasses/SAN/Place.h"
#include "Cpp/BaseClasses/SAN/ExtendedPlace.h"
extern Short size;
extern Short failure_index;
extern UserDistributions* TheDistribution;

void MemoryError();

#ifndef _instructions_header_
#define _instructions_header_

typedef short instructions_state;
class instructions: public ArrayStateVariable<ExtendedPlace<short> > {
  public:
  instructions(char* name, char* fullname):
    ArrayStateVariable<ExtendedPlace<short> >(name, fullname, ArrayType_SHORT ,size) {
    char varname[12];
    char fqname[strlen(fullname) + strlen(name) + 2];
    sprintf(fqname, "%s%s", fullname, name);
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, fqname));
    }
  }

  instructions(char* name):
    ArrayStateVariable<ExtendedPlace<short> >(name, "", ArrayType_SHORT ,size) {
    char varname[12];
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, name));
    }
  }

  instructions(char* name, char* fullname, short & initialValue):
    ArrayStateVariable<ExtendedPlace<short> >(name, fullname, ArrayType_SHORT ,size) {
    char varname[12];
    char fqname[strlen(fullname) + strlen(name) + 2];
    sprintf(fqname, "%s%s", fullname, name);
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, fqname, initialValue));
    }
  }

  instructions(char* name, short & initialValue):
    ArrayStateVariable<ExtendedPlace<short> >(name, "", ArrayType_SHORT ,size) {
    char varname[12];
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, name, initialValue));
    }
  }

  instructions(char* name, char* fullname, short * initialValue):
    ArrayStateVariable<ExtendedPlace<short> >(name, fullname, ArrayType_SHORT ,size) {
    char varname[12];
    char fqname[strlen(fullname) + strlen(name) + 2];
    sprintf(fqname, "%s%s", fullname, name);
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, fqname, initialValue[i]));
    }
  }

  instructions(char* name, short * initialValue):
    ArrayStateVariable<ExtendedPlace<short> >(name, "", ArrayType_SHORT ,size) {
    char varname[12];
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, name, initialValue[i]));
    }
  }
  ~instructions() {
    for (fieldIterator i=fields.begin();i!=fields.end();++i)
      delete (*i);
  }
};
#endif

/*********************************************************************
               WARPSAN Submodel Definition                   
*********************************************************************/

class WARPSAN:public SANModel{
public:

class DISPATCHER_CopyActivity:public Activity {
public:

  Place* INST_COUNTER;
  short* INST_COUNTER_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;
  ExtendedPlace<short>* FAILURE_INST;
  ExtendedPlace<short>* SCHEDULER;
  Place* REGISTERS_FILL;
  short* REGISTERS_FILL_Mobius_Mark;
  instructions* WARP;

  double* TheDistributionParameters;
  DISPATCHER_CopyActivity();
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
}; // DISPATCHER_CopyActivityActivity

class Instantaneous_Activity1Activity:public Activity {
public:

  ExtendedPlace<short>* FAILURE_INST;
  Place* INST_COUNTER;
  short* INST_COUNTER_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;
  Place* INT_ALU_FAILURE;
  short* INT_ALU_FAILURE_Mobius_Mark;
  Place* FLOAT_ALU_FAILURE;
  short* FLOAT_ALU_FAILURE_Mobius_Mark;
  Place* MEM_FAILURE;
  short* MEM_FAILURE_Mobius_Mark;
  Place* REG_FAILURE;
  short* REG_FAILURE_Mobius_Mark;
  ExtendedPlace<short>* SCHEDULER;
  Place* REGISTERS_FILL;
  short* REGISTERS_FILL_Mobius_Mark;
  instructions* WARP;

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

class L1_CLOCKActivity:public Activity {
public:

  Place* WARP_ACCESS_L1;
  short* WARP_ACCESS_L1_Mobius_Mark;
  Place* Place1;
  short* Place1_Mobius_Mark;

  double* TheDistributionParameters;
  L1_CLOCKActivity();
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
}; // L1_CLOCKActivityActivity

class L2_CLOCKActivity:public Activity {
public:

  Place* WARP_ACCESS_L2;
  short* WARP_ACCESS_L2_Mobius_Mark;
  Place* Place1;
  short* Place1_Mobius_Mark;

  double* TheDistributionParameters;
  L2_CLOCKActivity();
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
}; // L2_CLOCKActivityActivity

class DRAM_CLOCKActivity:public Activity {
public:

  Place* WARP_ACCESS_DRAM;
  short* WARP_ACCESS_DRAM_Mobius_Mark;
  Place* Place1;
  short* Place1_Mobius_Mark;

  double* TheDistributionParameters;
  DRAM_CLOCKActivity();
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
}; // DRAM_CLOCKActivityActivity

  //List of user-specified place names
  Place* INST_COUNTER;
  Place* INSTRUCTION_READY;
  Place* REGISTERS_FILL;
  Place* INT_ALU_FAILURE;
  Place* FLOAT_ALU_FAILURE;
  Place* MEM_FAILURE;
  Place* REG_FAILURE;
  Place* WARP_ACCESS_DRAM;
  Place* WARP_ACCESS_L2;
  Place* WARP_ACCESS_L1;
  Place* Place1;
  instructions* WARP;
  ExtendedPlace<short>* SCHEDULER;
  ExtendedPlace<short>* FAILURE_INST;

  // Create instances of all actvities
  DISPATCHER_CopyActivity DISPATCHER_Copy;
  Instantaneous_Activity1Activity Instantaneous_Activity1;
  L1_CLOCKActivity L1_CLOCK;
  L2_CLOCKActivity L2_CLOCK;
  DRAM_CLOCKActivity DRAM_CLOCK;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup DISPATCHER_CopyGroup;
  PostselectGroup Instantaneous_Activity1Group;
  PostselectGroup L1_CLOCKGroup;
  PostselectGroup L2_CLOCKGroup;
  PostselectGroup DRAM_CLOCKGroup;

  WARPSAN();
  ~WARPSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end WARPSAN

#endif // WARPSAN_H_
