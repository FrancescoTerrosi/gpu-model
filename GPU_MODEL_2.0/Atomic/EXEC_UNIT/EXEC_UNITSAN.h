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

class handle_failure_floatActivity:public Activity {
public:

  Place* FLOAT_ALU;
  short* FLOAT_ALU_Mobius_Mark;
  Place* FLOAT_ALU_FAILURE;
  short* FLOAT_ALU_FAILURE_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;
  Place* ROUTE_ALU_FLOAT;
  short* ROUTE_ALU_FLOAT_Mobius_Mark;

  double* TheDistributionParameters;
  handle_failure_floatActivity();
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
}; // handle_failure_floatActivityActivity

class DISPATCHERActivity:public Activity {
public:

  ExtendedPlace<short>* SCHEDULER;
  Place* REGISTERS_FILL;
  short* REGISTERS_FILL_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;
  ExtendedPlace<short>* READ;
  ExtendedPlace<short>* WRITE;
  Place* INT_ALU;
  short* INT_ALU_Mobius_Mark;
  Place* BARRIER;
  short* BARRIER_Mobius_Mark;

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

class Instantaneous_Activity2Activity_case1:public Activity {
public:

  Place* ROUTE_ALU_INT;
  short* ROUTE_ALU_INT_Mobius_Mark;
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

  Place* ROUTE_ALU_INT;
  short* ROUTE_ALU_INT_Mobius_Mark;
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

class handle_failureActivity:public Activity {
public:

  Place* INT_ALU;
  short* INT_ALU_Mobius_Mark;
  Place* INT_ALU_FAILURE;
  short* INT_ALU_FAILURE_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;
  Place* ROUTE_ALU_INT;
  short* ROUTE_ALU_INT_Mobius_Mark;

  double* TheDistributionParameters;
  handle_failureActivity();
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
}; // handle_failureActivityActivity

class dhnActivity:public Activity {
public:

  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;
  Place* Place1;
  short* Place1_Mobius_Mark;

  double* TheDistributionParameters;
  dhnActivity();
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
}; // dhnActivityActivity

class Instantaneous_Activity3Activity_case1:public Activity {
public:

  Place* ROUTE_ALU_FLOAT;
  short* ROUTE_ALU_FLOAT_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;

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

  Place* ROUTE_ALU_FLOAT;
  short* ROUTE_ALU_FLOAT_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;
  Place* RESULT_OK;
  short* RESULT_OK_Mobius_Mark;

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

class BARRIER_SYNCActivity:public Activity {
public:

  Place* BARRIER;
  short* BARRIER_Mobius_Mark;
  Place* INSTRUCTION_READY;
  short* INSTRUCTION_READY_Mobius_Mark;

  double* TheDistributionParameters;
  BARRIER_SYNCActivity();
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
}; // BARRIER_SYNCActivityActivity

  //List of user-specified place names
  Place* FLOAT_ALU_FAILURE;
  Place* ROUTE_ALU_FLOAT;
  Place* INSTRUCTION_READY;
  Place* FLOAT_ALU;
  Place* RESULT_KO;
  Place* RESULT_OK;
  Place* MEM_OP_COMPLETE;
  Place* INT_ALU;
  Place* REGISTERS_FILL;
  Place* OK_CONTENT;
  Place* KO_CONTENT;
  Place* INT_ALU_FAILURE;
  Place* ROUTE_ALU_INT;
  Place* Place1;
  Place* BARRIER;
  ExtendedPlace<short>* SCHEDULER;
  ExtendedPlace<short>* READ;
  ExtendedPlace<short>* WRITE;

  // Create instances of all actvities
  handle_failure_floatActivity handle_failure_float;
  DISPATCHERActivity DISPATCHER;
  Instantaneous_Activity2Activity_case1 Instantaneous_Activity2_case1;
  Instantaneous_Activity2Activity_case2 Instantaneous_Activity2_case2;
  handle_failureActivity handle_failure;
  dhnActivity dhn;
  Instantaneous_Activity3Activity_case1 Instantaneous_Activity3_case1;
  Instantaneous_Activity3Activity_case2 Instantaneous_Activity3_case2;
  BARRIER_SYNCActivity BARRIER_SYNC;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup handle_failure_floatGroup;
  PostselectGroup DISPATCHERGroup;
  PostselectGroup Instantaneous_Activity2Group;
  PostselectGroup handle_failureGroup;
  PostselectGroup dhnGroup;
  PostselectGroup Instantaneous_Activity3Group;
  PostselectGroup BARRIER_SYNCGroup;

  EXEC_UNITSAN();
  ~EXEC_UNITSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end EXEC_UNITSAN

#endif // EXEC_UNITSAN_H_
