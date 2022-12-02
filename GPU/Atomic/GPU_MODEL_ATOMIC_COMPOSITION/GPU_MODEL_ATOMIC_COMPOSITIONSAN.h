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
extern Short size;
extern UserDistributions* TheDistribution;

void MemoryError();

#ifndef _Instructions_header_
#define _Instructions_header_

typedef int Instructions_state;
class Instructions: public ArrayStateVariable<ExtendedPlace<int> > {
  public:
  Instructions(char* name, char* fullname):
    ArrayStateVariable<ExtendedPlace<int> >(name, fullname, ArrayType_INT ,size) {
    char varname[12];
    char fqname[strlen(fullname) + strlen(name) + 2];
    sprintf(fqname, "%s%s", fullname, name);
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<int>(varname, fqname));
    }
  }

  Instructions(char* name):
    ArrayStateVariable<ExtendedPlace<int> >(name, "", ArrayType_INT ,size) {
    char varname[12];
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<int>(varname, name));
    }
  }

  Instructions(char* name, char* fullname, int & initialValue):
    ArrayStateVariable<ExtendedPlace<int> >(name, fullname, ArrayType_INT ,size) {
    char varname[12];
    char fqname[strlen(fullname) + strlen(name) + 2];
    sprintf(fqname, "%s%s", fullname, name);
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<int>(varname, fqname, initialValue));
    }
  }

  Instructions(char* name, int & initialValue):
    ArrayStateVariable<ExtendedPlace<int> >(name, "", ArrayType_INT ,size) {
    char varname[12];
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<int>(varname, name, initialValue));
    }
  }

  Instructions(char* name, char* fullname, int * initialValue):
    ArrayStateVariable<ExtendedPlace<int> >(name, fullname, ArrayType_INT ,size) {
    char varname[12];
    char fqname[strlen(fullname) + strlen(name) + 2];
    sprintf(fqname, "%s%s", fullname, name);
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<int>(varname, fqname, initialValue[i]));
    }
  }

  Instructions(char* name, int * initialValue):
    ArrayStateVariable<ExtendedPlace<int> >(name, "", ArrayType_INT ,size) {
    char varname[12];
    for (int i=0;i<size;i++) {
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

class T_WRITE_RESULTActivity_case1:public Activity {
public:

  Place* WRITE_RESULT_MEMORY;
  short* WRITE_RESULT_MEMORY_Mobius_Mark;
  Place* RESULT_OK;
  short* RESULT_OK_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;
  Place* INST_COUNTER;
  short* INST_COUNTER_Mobius_Mark;
  Place* RESULT_OK_CONTENT;
  short* RESULT_OK_CONTENT_Mobius_Mark;
  Place* INST_COMPLETED;
  short* INST_COMPLETED_Mobius_Mark;

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

  Place* WRITE_RESULT_MEMORY;
  short* WRITE_RESULT_MEMORY_Mobius_Mark;
  Place* RESULT_OK;
  short* RESULT_OK_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;
  Place* INST_COUNTER;
  short* INST_COUNTER_Mobius_Mark;
  Place* RESULT_KO_CONTENT;
  short* RESULT_KO_CONTENT_Mobius_Mark;
  Place* INST_COMPLETED;
  short* INST_COMPLETED_Mobius_Mark;

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

class T_READ_RESULTActivity_case1:public Activity {
public:

  Place* READ_RESULT_MEMORY;
  short* READ_RESULT_MEMORY_Mobius_Mark;
  Place* RESULT_PERFORM_OK_READ;
  short* RESULT_PERFORM_OK_READ_Mobius_Mark;
  Place* INST_COMPLETED;
  short* INST_COMPLETED_Mobius_Mark;
  Place* RESULT_OK_CONTENT;
  short* RESULT_OK_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  T_READ_RESULTActivity_case1();
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
}; // T_READ_RESULTActivity_case1Activity

class T_READ_RESULTActivity_case2:public Activity {
public:

  Place* READ_RESULT_MEMORY;
  short* READ_RESULT_MEMORY_Mobius_Mark;
  Place* RESULT_PERFORM_KO_READ;
  short* RESULT_PERFORM_KO_READ_Mobius_Mark;
  Place* INST_COMPLETED;
  short* INST_COMPLETED_Mobius_Mark;
  Place* RESULT_KO_CONTENT;
  short* RESULT_KO_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  T_READ_RESULTActivity_case2();
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
}; // T_READ_RESULTActivity_case2Activity

class T_READ_TOTALActivity_case1:public Activity {
public:

  Place* READ_TOTAL_MEMORY;
  short* READ_TOTAL_MEMORY_Mobius_Mark;
  Place* TOTAL_PERFORM_OK_READ;
  short* TOTAL_PERFORM_OK_READ_Mobius_Mark;
  Place* INST_COMPLETED;
  short* INST_COMPLETED_Mobius_Mark;

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

  Place* READ_TOTAL_MEMORY;
  short* READ_TOTAL_MEMORY_Mobius_Mark;
  Place* TOTAL_PERFORM_KO_READ;
  short* TOTAL_PERFORM_KO_READ_Mobius_Mark;
  Place* INST_COMPLETED;
  short* INST_COMPLETED_Mobius_Mark;

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

class T_WRITE_OUTPUTActivity_case1:public Activity {
public:

  Place* WRITE_OUTPUT_MEMORY;
  short* WRITE_OUTPUT_MEMORY_Mobius_Mark;
  Place* OUTPUT_OK_CONTENT;
  short* OUTPUT_OK_CONTENT_Mobius_Mark;
  Place* RESULT_OK;
  short* RESULT_OK_Mobius_Mark;

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

  Place* WRITE_OUTPUT_MEMORY;
  short* WRITE_OUTPUT_MEMORY_Mobius_Mark;
  Place* OUTPUT_KO_CONTENT;
  short* OUTPUT_KO_CONTENT_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;

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
  Place* INST_COMPLETED;
  short* INST_COMPLETED_Mobius_Mark;
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

class PREPARE_DATAActivity:public Activity {
public:

  Place* TOTAL_PERFORM_OK_READ;
  short* TOTAL_PERFORM_OK_READ_Mobius_Mark;
  Place* TOTAL_PERFORM_KO_READ;
  short* TOTAL_PERFORM_KO_READ_Mobius_Mark;
  Place* ALU_INSTRUCTION;
  short* ALU_INSTRUCTION_Mobius_Mark;
  Place* RESULT_OK_CONTENT;
  short* RESULT_OK_CONTENT_Mobius_Mark;
  Place* RESULT_KO_CONTENT;
  short* RESULT_KO_CONTENT_Mobius_Mark;
  Place* GET_OK_DATA;
  short* GET_OK_DATA_Mobius_Mark;
  Place* GET_KO_DATA;
  short* GET_KO_DATA_Mobius_Mark;

  double* TheDistributionParameters;
  PREPARE_DATAActivity();
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
}; // PREPARE_DATAActivityActivity

class COMPUTE_OKActivity:public Activity {
public:

  Place* GET_OK_DATA;
  short* GET_OK_DATA_Mobius_Mark;
  Place* RESULT_OK;
  short* RESULT_OK_Mobius_Mark;
  Place* INST_COMPLETED;
  short* INST_COMPLETED_Mobius_Mark;

  double* TheDistributionParameters;
  COMPUTE_OKActivity();
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
}; // COMPUTE_OKActivityActivity

class COMPUTE_KOActivity:public Activity {
public:

  Place* GET_KO_DATA;
  short* GET_KO_DATA_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;
  Place* INST_COMPLETED;
  short* INST_COMPLETED_Mobius_Mark;

  double* TheDistributionParameters;
  COMPUTE_KOActivity();
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
}; // COMPUTE_KOActivityActivity

  //List of user-specified place names
  Place* RESULT_KO;
  Place* RESULT_OK;
  Place* RESULT_KO_CONTENT;
  Place* RESULT_PERFORM_KO_READ;
  Place* TOTAL_PERFORM_OK_READ;
  Place* TOTAL_PERFORM_KO_READ;
  Place* RESULT_OK_CONTENT;
  Place* ALU_INSTRUCTION;
  Place* WRITE_RESULT_MEMORY;
  Place* READ_TOTAL_MEMORY;
  Place* RESULT_PERFORM_OK_READ;
  Place* OUTPUT_OK_CONTENT;
  Place* OUTPUT_KO_CONTENT;
  Place* READ_RESULT_MEMORY;
  Place* WRITE_OUTPUT_MEMORY;
  Place* INST_COUNTER;
  Place* GET_KO_DATA;
  Place* GET_OK_DATA;
  Place* INST_COMPLETED;
  Instructions* SCHEDULER;

  // Create instances of all actvities
  T_WRITE_RESULTActivity_case1 T_WRITE_RESULT_case1;
  T_WRITE_RESULTActivity_case2 T_WRITE_RESULT_case2;
  T_READ_RESULTActivity_case1 T_READ_RESULT_case1;
  T_READ_RESULTActivity_case2 T_READ_RESULT_case2;
  T_READ_TOTALActivity_case1 T_READ_TOTAL_case1;
  T_READ_TOTALActivity_case2 T_READ_TOTAL_case2;
  T_WRITE_OUTPUTActivity_case1 T_WRITE_OUTPUT_case1;
  T_WRITE_OUTPUTActivity_case2 T_WRITE_OUTPUT_case2;
  DISPATCHERActivity DISPATCHER;
  PREPARE_DATAActivity PREPARE_DATA;
  COMPUTE_OKActivity COMPUTE_OK;
  COMPUTE_KOActivity COMPUTE_KO;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup T_WRITE_RESULTGroup;
  PostselectGroup T_READ_RESULTGroup;
  PostselectGroup T_READ_TOTALGroup;
  PostselectGroup T_WRITE_OUTPUTGroup;
  PostselectGroup DISPATCHERGroup;
  PostselectGroup PREPARE_DATAGroup;
  PostselectGroup COMPUTE_OKGroup;
  PostselectGroup COMPUTE_KOGroup;

  GPU_MODEL_ATOMIC_COMPOSITIONSAN();
  ~GPU_MODEL_ATOMIC_COMPOSITIONSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end GPU_MODEL_ATOMIC_COMPOSITIONSAN

#endif // GPU_MODEL_ATOMIC_COMPOSITIONSAN_H_
