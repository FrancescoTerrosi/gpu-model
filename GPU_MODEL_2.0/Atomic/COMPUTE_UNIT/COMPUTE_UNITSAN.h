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

class DISPATCHERActivity:public Activity {
public:

  ExtendedPlace<short>* SCHEDULER;
  Place* REGISTERS_FILL;
  short* REGISTERS_FILL_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;
  Place* READ_GLOBAL_WITH_PROBABILITY;
  short* READ_GLOBAL_WITH_PROBABILITY_Mobius_Mark;
  Place* WRITE_GLOBAL_MEMORY;
  short* WRITE_GLOBAL_MEMORY_Mobius_Mark;
  Place* READ_LOCAL_WITH_PROBABILITY;
  short* READ_LOCAL_WITH_PROBABILITY_Mobius_Mark;
  Place* WRITE_LOCAL_MEMORY;
  short* WRITE_LOCAL_MEMORY_Mobius_Mark;
  Place* READ_REGISTER_FILE;
  short* READ_REGISTER_FILE_Mobius_Mark;
  Place* WRITE_REGISTER_FILE;
  short* WRITE_REGISTER_FILE_Mobius_Mark;
  Place* WRITE_OUTPUT_MEMORY;
  short* WRITE_OUTPUT_MEMORY_Mobius_Mark;
  Place* ALU_INSTRUCTION_NO_DATA;
  short* ALU_INSTRUCTION_NO_DATA_Mobius_Mark;
  Place* ALU_INSTRUCTION;
  short* ALU_INSTRUCTION_Mobius_Mark;

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

class COMPUTE_WITH_KO_DATAActivity:public Activity {
public:

  Place* ALU_INSTRUCTION;
  short* ALU_INSTRUCTION_Mobius_Mark;
  Place* KO_READ;
  short* KO_READ_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;

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

class COMPUTE_WITH_OK_DATAActivity:public Activity {
public:

  Place* ALU_INSTRUCTION;
  short* ALU_INSTRUCTION_Mobius_Mark;
  Place* OK_READ;
  short* OK_READ_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;
  Place* RESULT_OK;
  short* RESULT_OK_Mobius_Mark;

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

class Instantaneous_Activity2Activity_case1:public Activity {
public:

  Place* ALU_INSTRUCTION_NO_DATA;
  short* ALU_INSTRUCTION_NO_DATA_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;

  double* TheDistributionParameters;
  Instantaneous_Activity2Activity_case1();
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
}; // Instantaneous_Activity2Activity_case1Activity

class Instantaneous_Activity2Activity_case2:public Activity {
public:

  Place* ALU_INSTRUCTION_NO_DATA;
  short* ALU_INSTRUCTION_NO_DATA_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;
  Place* RESULT_OK;
  short* RESULT_OK_Mobius_Mark;

  double* TheDistributionParameters;
  Instantaneous_Activity2Activity_case2();
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
}; // Instantaneous_Activity2Activity_case2Activity

class Instantaneous_Activity3Activity_case1:public Activity {
public:

  Place* READ_GLOBAL_WITH_PROBABILITY;
  short* READ_GLOBAL_WITH_PROBABILITY_Mobius_Mark;
  Place* READ_REGISTER_FILE;
  short* READ_REGISTER_FILE_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;

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

  Place* READ_GLOBAL_WITH_PROBABILITY;
  short* READ_GLOBAL_WITH_PROBABILITY_Mobius_Mark;
  Place* READ_GLOBAL_MEMORY;
  short* READ_GLOBAL_MEMORY_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;

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

class Instantaneous_Activity4Activity_case1:public Activity {
public:

  Place* READ_LOCAL_WITH_PROBABILITY;
  short* READ_LOCAL_WITH_PROBABILITY_Mobius_Mark;
  Place* READ_REGISTER_FILE;
  short* READ_REGISTER_FILE_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  Instantaneous_Activity4Activity_case1();
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
}; // Instantaneous_Activity4Activity_case1Activity

class Instantaneous_Activity4Activity_case2:public Activity {
public:

  Place* READ_LOCAL_WITH_PROBABILITY;
  short* READ_LOCAL_WITH_PROBABILITY_Mobius_Mark;
  Place* READ_LOCAL_MEMORY;
  short* READ_LOCAL_MEMORY_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  Instantaneous_Activity4Activity_case2();
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
}; // Instantaneous_Activity4Activity_case2Activity

  //List of user-specified place names
  Place* INSTRUCTION_READY;
  Place* ALU_INSTRUCTION;
  Place* KO_READ;
  Place* READ_GLOBAL_MEMORY;
  Place* WRITE_GLOBAL_MEMORY;
  Place* WRITE_LOCAL_MEMORY;
  Place* READ_LOCAL_MEMORY;
  Place* RESULT_KO;
  Place* OK_READ;
  Place* RESULT_OK;
  Place* READ_REGISTER_FILE;
  Place* WRITE_OUTPUT_MEMORY;
  Place* WRITE_REGISTER_FILE;
  Place* MEM_OP_COMPLETE;
  Place* ALU_INSTRUCTION_NO_DATA;
  Place* REGISTERS_FILL;
  Place* OK_CONTENT;
  Place* READ_GLOBAL_WITH_PROBABILITY;
  Place* READ_LOCAL_WITH_PROBABILITY;
  ExtendedPlace<short>* SCHEDULER;

  // Create instances of all actvities
  Instantaneous_Activity1Activity Instantaneous_Activity1;
  DISPATCHERActivity DISPATCHER;
  COMPUTE_WITH_KO_DATAActivity COMPUTE_WITH_KO_DATA;
  COMPUTE_WITH_OK_DATAActivity COMPUTE_WITH_OK_DATA;
  Instantaneous_Activity2Activity_case1 Instantaneous_Activity2_case1;
  Instantaneous_Activity2Activity_case2 Instantaneous_Activity2_case2;
  Instantaneous_Activity3Activity_case1 Instantaneous_Activity3_case1;
  Instantaneous_Activity3Activity_case2 Instantaneous_Activity3_case2;
  Instantaneous_Activity4Activity_case1 Instantaneous_Activity4_case1;
  Instantaneous_Activity4Activity_case2 Instantaneous_Activity4_case2;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup Instantaneous_Activity1Group;
  PostselectGroup DISPATCHERGroup;
  PostselectGroup COMPUTE_WITH_KO_DATAGroup;
  PostselectGroup COMPUTE_WITH_OK_DATAGroup;
  PostselectGroup Instantaneous_Activity2Group;
  PostselectGroup Instantaneous_Activity3Group;
  PostselectGroup Instantaneous_Activity4Group;

  COMPUTE_UNITSAN();
  ~COMPUTE_UNITSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end COMPUTE_UNITSAN

#endif // COMPUTE_UNITSAN_H_
