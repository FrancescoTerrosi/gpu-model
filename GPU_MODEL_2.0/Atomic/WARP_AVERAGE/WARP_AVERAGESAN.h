#ifndef WARP_AVERAGESAN_H_
#define WARP_AVERAGESAN_H_

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
extern Double alu_prob;
extern Double local_mem_prob;
extern Double global_mem_prob;
extern Short alu_ops;
extern Short l_mem_ops;
extern Short g_mem_ops;
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
               WARP_AVERAGESAN Submodel Definition                   
*********************************************************************/

class WARP_AVERAGESAN:public SANModel{
public:

class DISPATCHER_Copy_CopyActivity:public Activity {
public:

  Place* INST_COUNTER;
  short* INST_COUNTER_Mobius_Mark;
  ExtendedPlace<short>* WARP;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;
  ExtendedPlace<short>* SCHEDULER;

  double* TheDistributionParameters;
  DISPATCHER_Copy_CopyActivity();
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
}; // DISPATCHER_Copy_CopyActivityActivity

class Instantaneous_Activity1Activity:public Activity {
public:

  ExtendedPlace<short>* INST_SEL;
  Place* ALU;
  short* ALU_Mobius_Mark;
  ExtendedPlace<short>* WARP;

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

  ExtendedPlace<short>* INST_SEL;
  Place* L_MEM;
  short* L_MEM_Mobius_Mark;
  ExtendedPlace<short>* WARP;

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

  ExtendedPlace<short>* INST_SEL;
  Place* G_MEM;
  short* G_MEM_Mobius_Mark;
  ExtendedPlace<short>* WARP;

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

  ExtendedPlace<short>* INST_SEL;
  ExtendedPlace<short>* WARP;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;

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
  Place* INSTRUCTION_READY;
  Place* INST_COUNTER;
  Place* ALU;
  Place* L_MEM;
  Place* G_MEM;
  ExtendedPlace<short>* SCHEDULER;
  ExtendedPlace<short>* WARP;
  ExtendedPlace<short>* INST_SEL;

  // Create instances of all actvities
  DISPATCHER_Copy_CopyActivity DISPATCHER_Copy_Copy;
  Instantaneous_Activity1Activity Instantaneous_Activity1;
  Instantaneous_Activity2Activity Instantaneous_Activity2;
  Instantaneous_Activity3Activity Instantaneous_Activity3;
  Instantaneous_Activity4Activity Instantaneous_Activity4;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup DISPATCHER_Copy_CopyGroup;
  PostselectGroup Instantaneous_Activity1Group;
  PostselectGroup Instantaneous_Activity2Group;
  PostselectGroup Instantaneous_Activity3Group;
  PostselectGroup Instantaneous_Activity4Group;

  WARP_AVERAGESAN();
  ~WARP_AVERAGESAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end WARP_AVERAGESAN

#endif // WARP_AVERAGESAN_H_
