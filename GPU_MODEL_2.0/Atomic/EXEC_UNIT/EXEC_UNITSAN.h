#ifndef EXEC_UNITSAN_H_
#define EXEC_UNITSAN_H_

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
               EXEC_UNITSAN Submodel Definition                   
*********************************************************************/

class EXEC_UNITSAN:public SANModel{
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
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;
  ExtendedPlace<short>* READ;
  ExtendedPlace<short>* WRITE;
  Place* ALU_INSTRUCTION_NO_DATA;
  short* ALU_INSTRUCTION_NO_DATA_Mobius_Mark;

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
  Place* REG_KO_CONTENT;
  short* REG_KO_CONTENT_Mobius_Mark;
  Place* REG_OK_CONTENT;
  short* REG_OK_CONTENT_Mobius_Mark;

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
  Place* REG_OK_CONTENT;
  short* REG_OK_CONTENT_Mobius_Mark;
  Place* REG_KO_CONTENT;
  short* REG_KO_CONTENT_Mobius_Mark;

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

  //List of user-specified place names
  Place* INSTRUCTION_READY;
  Place* ALU_INSTRUCTION;
  Place* RESULT_KO;
  Place* RESULT_OK;
  Place* MEM_OP_COMPLETE;
  Place* ALU_INSTRUCTION_NO_DATA;
  Place* REGISTERS_FILL;
  Place* REG_OK_CONTENT;
  Place* REG_KO_CONTENT;
  ExtendedPlace<short>* SCHEDULER;
  ExtendedPlace<short>* READ;
  ExtendedPlace<short>* WRITE;

  // Create instances of all actvities
  Instantaneous_Activity1Activity Instantaneous_Activity1;
  DISPATCHERActivity DISPATCHER;
  COMPUTE_WITH_KO_DATAActivity COMPUTE_WITH_KO_DATA;
  COMPUTE_WITH_OK_DATAActivity COMPUTE_WITH_OK_DATA;
  Instantaneous_Activity2Activity_case1 Instantaneous_Activity2_case1;
  Instantaneous_Activity2Activity_case2 Instantaneous_Activity2_case2;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup Instantaneous_Activity1Group;
  PostselectGroup DISPATCHERGroup;
  PostselectGroup COMPUTE_WITH_KO_DATAGroup;
  PostselectGroup COMPUTE_WITH_OK_DATAGroup;
  PostselectGroup Instantaneous_Activity2Group;

  EXEC_UNITSAN();
  ~EXEC_UNITSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end EXEC_UNITSAN

#endif // EXEC_UNITSAN_H_
