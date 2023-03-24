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

class Instantaneous_Activity2Activity:public Activity {
public:

  Place* INST_COUNTER;
  short* INST_COUNTER_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;
  ExtendedPlace<short>* SCHEDULER;
  Place* REGISTERS_FILL;
  short* REGISTERS_FILL_Mobius_Mark;
  instructions* WARP;

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

  //List of user-specified place names
  Place* INST_COUNTER;
  Place* INSTRUCTION_READY;
  Place* REGISTERS_FILL;
  instructions* WARP;
  ExtendedPlace<short>* SCHEDULER;

  // Create instances of all actvities
  Instantaneous_Activity2Activity Instantaneous_Activity2;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup Instantaneous_Activity2Group;

  WARPSAN();
  ~WARPSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end WARPSAN

#endif // WARPSAN_H_
