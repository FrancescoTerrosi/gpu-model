#ifndef COMPUTE_UNITSAN_H_
#define COMPUTE_UNITSAN_H_

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
extern UserDistributions* TheDistribution;

void MemoryError();

#ifndef _Instructions_header_
#define _Instructions_header_

typedef short Instructions_state;
class Instructions: public ArrayStateVariable<ExtendedPlace<short> > {
  public:
  Instructions(char* name, char* fullname):
    ArrayStateVariable<ExtendedPlace<short> >(name, fullname, ArrayType_SHORT ,size) {
    char varname[12];
    char fqname[strlen(fullname) + strlen(name) + 2];
    sprintf(fqname, "%s%s", fullname, name);
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, fqname));
    }
  }

  Instructions(char* name):
    ArrayStateVariable<ExtendedPlace<short> >(name, "", ArrayType_SHORT ,size) {
    char varname[12];
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, name));
    }
  }

  Instructions(char* name, char* fullname, short & initialValue):
    ArrayStateVariable<ExtendedPlace<short> >(name, fullname, ArrayType_SHORT ,size) {
    char varname[12];
    char fqname[strlen(fullname) + strlen(name) + 2];
    sprintf(fqname, "%s%s", fullname, name);
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, fqname, initialValue));
    }
  }

  Instructions(char* name, short & initialValue):
    ArrayStateVariable<ExtendedPlace<short> >(name, "", ArrayType_SHORT ,size) {
    char varname[12];
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, name, initialValue));
    }
  }

  Instructions(char* name, char* fullname, short * initialValue):
    ArrayStateVariable<ExtendedPlace<short> >(name, fullname, ArrayType_SHORT ,size) {
    char varname[12];
    char fqname[strlen(fullname) + strlen(name) + 2];
    sprintf(fqname, "%s%s", fullname, name);
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, fqname, initialValue[i]));
    }
  }

  Instructions(char* name, short * initialValue):
    ArrayStateVariable<ExtendedPlace<short> >(name, "", ArrayType_SHORT ,size) {
    char varname[12];
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, name, initialValue[i]));
    }
  }
  ~Instructions() {
    for (fieldIterator i=fields.begin();i!=fields.end();++i)
      delete (*i);
  }
};
#endif

/*********************************************************************
               COMPUTE_UNITSAN Submodel Definition                   
*********************************************************************/

class COMPUTE_UNITSAN:public SANModel{
public:

class DISPATCHERActivity:public Activity {
public:

  Place* INST_COUNTER;
  short* INST_COUNTER_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;
  Place* READ_TOTAL_MEMORY;
  short* READ_TOTAL_MEMORY_Mobius_Mark;
  Place* READ_RESULT_MEMORY;
  short* READ_RESULT_MEMORY_Mobius_Mark;
  Place* WRITE_RESULT_MEMORY;
  short* WRITE_RESULT_MEMORY_Mobius_Mark;
  Place* WRITE_OUTPUT_MEMORY;
  short* WRITE_OUTPUT_MEMORY_Mobius_Mark;
  Place* ALU_INSTRUCTION;
  short* ALU_INSTRUCTION_Mobius_Mark;
  Instructions* SCHEDULER;

  double* TheDistributionParameters;
  DISPATCHERActivity();
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
}; // DISPATCHERActivityActivity

class COMPUTE_WITH_OK_DATAActivity:public Activity {
public:

  Place* ALU_INSTRUCTION;
  short* ALU_INSTRUCTION_Mobius_Mark;
  Place* OK_READ;
  short* OK_READ_Mobius_Mark;
  Place* RESULT_OK;
  short* RESULT_OK_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;

  double* TheDistributionParameters;
  COMPUTE_WITH_OK_DATAActivity();
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
}; // COMPUTE_WITH_OK_DATAActivityActivity

class COMPUTE_WITH_KO_DATAActivity:public Activity {
public:

  Place* ALU_INSTRUCTION;
  short* ALU_INSTRUCTION_Mobius_Mark;
  Place* KO_READ;
  short* KO_READ_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;

  double* TheDistributionParameters;
  COMPUTE_WITH_KO_DATAActivity();
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
}; // COMPUTE_WITH_KO_DATAActivityActivity

class Instantaneous_Activity1Activity:public Activity {
public:

  Place* MEM_OP_COMPLETE;
  short* MEM_OP_COMPLETE_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;

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

  //List of user-specified place names
  Place* READ_TOTAL_MEMORY;
  Place* READ_RESULT_MEMORY;
  Place* INST_COUNTER;
  Place* ALU_INSTRUCTION;
  Place* WRITE_OUTPUT_MEMORY;
  Place* WRITE_RESULT_MEMORY;
  Place* OK_READ;
  Place* KO_READ;
  Place* RESULT_KO;
  Place* RESULT_OK;
  Place* INSTRUCTION_READY;
  Place* MEM_OP_COMPLETE;
  Instructions* SCHEDULER;

  // Create instances of all actvities
  DISPATCHERActivity DISPATCHER;
  COMPUTE_WITH_OK_DATAActivity COMPUTE_WITH_OK_DATA;
  COMPUTE_WITH_KO_DATAActivity COMPUTE_WITH_KO_DATA;
  Instantaneous_Activity1Activity Instantaneous_Activity1;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup DISPATCHERGroup;
  PostselectGroup COMPUTE_WITH_OK_DATAGroup;
  PostselectGroup COMPUTE_WITH_KO_DATAGroup;
  PostselectGroup Instantaneous_Activity1Group;

  COMPUTE_UNITSAN();
  ~COMPUTE_UNITSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end COMPUTE_UNITSAN

#endif // COMPUTE_UNITSAN_H_
