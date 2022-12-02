#ifndef GPU_MODEL_ATOMIC_COMPOSITIONSAN_H_
#define GPU_MODEL_ATOMIC_COMPOSITIONSAN_H_

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

#ifndef _Instructions_header_
#define _Instructions_header_

typedef int Instructions_state;
class Instructions: public ArrayStateVariable<ExtendedPlace<int> > {
  public:
  Instructions(char* name, char* fullname):
    ArrayStateVariable<ExtendedPlace<int> >(name, fullname, ArrayType_INT ,5) {
    char varname[12];
    char fqname[strlen(fullname) + strlen(name) + 2];
    sprintf(fqname, "%s%s", fullname, name);
    for (int i=0;i<5;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<int>(varname, fqname));
    }
  }

  Instructions(char* name):
    ArrayStateVariable<ExtendedPlace<int> >(name, "", ArrayType_INT ,5) {
    char varname[12];
    for (int i=0;i<5;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<int>(varname, name));
    }
  }

  Instructions(char* name, char* fullname, int & initialValue):
    ArrayStateVariable<ExtendedPlace<int> >(name, fullname, ArrayType_INT ,5) {
    char varname[12];
    char fqname[strlen(fullname) + strlen(name) + 2];
    sprintf(fqname, "%s%s", fullname, name);
    for (int i=0;i<5;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<int>(varname, fqname, initialValue));
    }
  }

  Instructions(char* name, int & initialValue):
    ArrayStateVariable<ExtendedPlace<int> >(name, "", ArrayType_INT ,5) {
    char varname[12];
    for (int i=0;i<5;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<int>(varname, name, initialValue));
    }
  }

  Instructions(char* name, char* fullname, int * initialValue):
    ArrayStateVariable<ExtendedPlace<int> >(name, fullname, ArrayType_INT ,5) {
    char varname[12];
    char fqname[strlen(fullname) + strlen(name) + 2];
    sprintf(fqname, "%s%s", fullname, name);
    for (int i=0;i<5;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<int>(varname, fqname, initialValue[i]));
    }
  }

  Instructions(char* name, int * initialValue):
    ArrayStateVariable<ExtendedPlace<int> >(name, "", ArrayType_INT ,5) {
    char varname[12];
    for (int i=0;i<5;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<int>(varname, name, initialValue[i]));
    }
  }
  ~Instructions() {
    for (fieldIterator i=fields.begin();i!=fields.end();++i)
      delete (*i);
  }
};
#endif

/*********************************************************************
               GPU_MODEL_ATOMIC_COMPOSITIONSAN Submodel Definition                   
*********************************************************************/

class GPU_MODEL_ATOMIC_COMPOSITIONSAN:public SANModel{
public:

class T_READ_TOTALActivity_case1:public Activity {
public:

  Place* TOTAL_MEMORY;
  short* TOTAL_MEMORY_Mobius_Mark;
  Place* TOTAL_PERFORM_OK_READ;
  short* TOTAL_PERFORM_OK_READ_Mobius_Mark;

  double* TheDistributionParameters;
  T_READ_TOTALActivity_case1();
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
}; // T_READ_TOTALActivity_case1Activity

class T_READ_TOTALActivity_case2:public Activity {
public:

  Place* TOTAL_MEMORY;
  short* TOTAL_MEMORY_Mobius_Mark;
  Place* TOTAL_PERFORM_KO_READ;
  short* TOTAL_PERFORM_KO_READ_Mobius_Mark;

  double* TheDistributionParameters;
  T_READ_TOTALActivity_case2();
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
}; // T_READ_TOTALActivity_case2Activity

class T_WRITE_RESULTActivity_case1:public Activity {
public:

  Place* RESULT_MEMORY;
  short* RESULT_MEMORY_Mobius_Mark;
  Place* RESULT_OK_CONTENT;
  short* RESULT_OK_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  T_WRITE_RESULTActivity_case1();
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
}; // T_WRITE_RESULTActivity_case1Activity

class T_WRITE_RESULTActivity_case2:public Activity {
public:

  Place* RESULT_MEMORY;
  short* RESULT_MEMORY_Mobius_Mark;
  Place* RESULT_KO_CONTENT;
  short* RESULT_KO_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  T_WRITE_RESULTActivity_case2();
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
}; // T_WRITE_RESULTActivity_case2Activity

class COMPUTEActivity_case1:public Activity {
public:

  Place* ALU_INSTRUCTION;
  short* ALU_INSTRUCTION_Mobius_Mark;
  Place* RESULT_OK;
  short* RESULT_OK_Mobius_Mark;

  double* TheDistributionParameters;
  COMPUTEActivity_case1();
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
}; // COMPUTEActivity_case1Activity

class COMPUTEActivity_case2:public Activity {
public:

  Place* ALU_INSTRUCTION;
  short* ALU_INSTRUCTION_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;

  double* TheDistributionParameters;
  COMPUTEActivity_case2();
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
}; // COMPUTEActivity_case2Activity

class T_READActivity_case1:public Activity {
public:

  Place* RESULT_MEMORY;
  short* RESULT_MEMORY_Mobius_Mark;
  Place* RESULT_PERFORM_OK_READ;
  short* RESULT_PERFORM_OK_READ_Mobius_Mark;

  double* TheDistributionParameters;
  T_READActivity_case1();
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
}; // T_READActivity_case1Activity

class T_READActivity_case2:public Activity {
public:

  Place* RESULT_MEMORY;
  short* RESULT_MEMORY_Mobius_Mark;
  Place* RESULT_PERFORM_KO_READ;
  short* RESULT_PERFORM_KO_READ_Mobius_Mark;

  double* TheDistributionParameters;
  T_READActivity_case2();
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
}; // T_READActivity_case2Activity

class T_WRITE_OUTPUTActivity_case1:public Activity {
public:

  Place* OUTPUT_MEMORY;
  short* OUTPUT_MEMORY_Mobius_Mark;
  Place* OUTPUT_OK_CONTENT;
  short* OUTPUT_OK_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  T_WRITE_OUTPUTActivity_case1();
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
}; // T_WRITE_OUTPUTActivity_case1Activity

class T_WRITE_OUTPUTActivity_case2:public Activity {
public:

  Place* OUTPUT_MEMORY;
  short* OUTPUT_MEMORY_Mobius_Mark;
  Place* OUTPUT_KO_CONTENT;
  short* OUTPUT_KO_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  T_WRITE_OUTPUTActivity_case2();
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
}; // T_WRITE_OUTPUTActivity_case2Activity

class DISPATCHERActivity:public Activity {
public:

  Place* INST_COUNTER;
  short* INST_COUNTER_Mobius_Mark;
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

class READ_TOTALActivity_case1:public Activity {
public:

  Place* READ_TOTAL_MEMORY;
  short* READ_TOTAL_MEMORY_Mobius_Mark;
  Place* READ_RESULT_MEMORY;
  short* READ_RESULT_MEMORY_Mobius_Mark;
  Place* TOTAL_MEMORY;
  short* TOTAL_MEMORY_Mobius_Mark;

  double* TheDistributionParameters;
  READ_TOTALActivity_case1();
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
}; // READ_TOTALActivity_case1Activity

class READ_TOTALActivity_case2:public Activity {
public:

  Place* READ_TOTAL_MEMORY;
  short* READ_TOTAL_MEMORY_Mobius_Mark;
  Place* READ_RESULT_MEMORY;
  short* READ_RESULT_MEMORY_Mobius_Mark;

  double* TheDistributionParameters;
  READ_TOTALActivity_case2();
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
}; // READ_TOTALActivity_case2Activity

class WRITE_TOActivity_case1:public Activity {
public:

  Place* WRITE_RESULT_MEMORY;
  short* WRITE_RESULT_MEMORY_Mobius_Mark;
  Place* WRITE_OUTPUT_MEMORY;
  short* WRITE_OUTPUT_MEMORY_Mobius_Mark;
  Place* RESULT_MEMORY;
  short* RESULT_MEMORY_Mobius_Mark;

  double* TheDistributionParameters;
  WRITE_TOActivity_case1();
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
}; // WRITE_TOActivity_case1Activity

class WRITE_TOActivity_case2:public Activity {
public:

  Place* WRITE_RESULT_MEMORY;
  short* WRITE_RESULT_MEMORY_Mobius_Mark;
  Place* WRITE_OUTPUT_MEMORY;
  short* WRITE_OUTPUT_MEMORY_Mobius_Mark;
  Place* OUTPUT_MEMORY;
  short* OUTPUT_MEMORY_Mobius_Mark;

  double* TheDistributionParameters;
  WRITE_TOActivity_case2();
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
}; // WRITE_TOActivity_case2Activity

  //List of user-specified place names
  Place* TOTAL_PERFORM_OK_READ;
  Place* TOTAL_PERFORM_KO_READ;
  Place* RESULT_OK_CONTENT;
  Place* RESULT_KO_CONTENT;
  Place* RESULT_KO;
  Place* RESULT_OK;
  Place* ALU_INSTRUCTION;
  Place* OUTPUT_MEMORY;
  Place* WRITE_RESULT_MEMORY;
  Place* RESULT_MEMORY;
  Place* READ_TOTAL_MEMORY;
  Place* TOTAL_MEMORY;
  Place* RESULT_PERFORM_OK_READ;
  Place* RESULT_PERFORM_KO_READ;
  Place* OUTPUT_OK_CONTENT;
  Place* OUTPUT_KO_CONTENT;
  Place* READ_RESULT_MEMORY;
  Place* WRITE_OUTPUT_MEMORY;
  Place* ALU_INSTRUCTION_WITH_INPUT;
  Place* INST_COUNTER;
  Instructions* SCHEDULER;

  // Create instances of all actvities
  T_READ_TOTALActivity_case1 T_READ_TOTAL_case1;
  T_READ_TOTALActivity_case2 T_READ_TOTAL_case2;
  T_WRITE_RESULTActivity_case1 T_WRITE_RESULT_case1;
  T_WRITE_RESULTActivity_case2 T_WRITE_RESULT_case2;
  COMPUTEActivity_case1 COMPUTE_case1;
  COMPUTEActivity_case2 COMPUTE_case2;
  T_READActivity_case1 T_READ_case1;
  T_READActivity_case2 T_READ_case2;
  T_WRITE_OUTPUTActivity_case1 T_WRITE_OUTPUT_case1;
  T_WRITE_OUTPUTActivity_case2 T_WRITE_OUTPUT_case2;
  DISPATCHERActivity DISPATCHER;
  READ_TOTALActivity_case1 READ_TOTAL_case1;
  READ_TOTALActivity_case2 READ_TOTAL_case2;
  WRITE_TOActivity_case1 WRITE_TO_case1;
  WRITE_TOActivity_case2 WRITE_TO_case2;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup T_READ_TOTALGroup;
  PostselectGroup T_WRITE_RESULTGroup;
  PostselectGroup COMPUTEGroup;
  PostselectGroup T_READGroup;
  PostselectGroup T_WRITE_OUTPUTGroup;
  PostselectGroup DISPATCHERGroup;
  PostselectGroup READ_TOTALGroup;
  PostselectGroup WRITE_TOGroup;

  GPU_MODEL_ATOMIC_COMPOSITIONSAN();
  ~GPU_MODEL_ATOMIC_COMPOSITIONSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end GPU_MODEL_ATOMIC_COMPOSITIONSAN

#endif // GPU_MODEL_ATOMIC_COMPOSITIONSAN_H_
