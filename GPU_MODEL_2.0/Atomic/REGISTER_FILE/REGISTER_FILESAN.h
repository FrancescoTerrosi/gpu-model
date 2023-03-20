#ifndef REGISTER_FILESAN_H_
#define REGISTER_FILESAN_H_

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
extern Short register_count_index;
extern UserDistributions* TheDistribution;

void MemoryError();

#ifndef _registers_counter_header_
#define _registers_counter_header_

typedef short registers_counter_state;
class registers_counter: public ArrayStateVariable<ExtendedPlace<short> > {
  public:
  registers_counter(char* name, char* fullname):
    ArrayStateVariable<ExtendedPlace<short> >(name, fullname, ArrayType_SHORT ,size) {
    char varname[12];
    char fqname[strlen(fullname) + strlen(name) + 2];
    sprintf(fqname, "%s%s", fullname, name);
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, fqname));
    }
  }

  registers_counter(char* name):
    ArrayStateVariable<ExtendedPlace<short> >(name, "", ArrayType_SHORT ,size) {
    char varname[12];
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, name));
    }
  }

  registers_counter(char* name, char* fullname, short & initialValue):
    ArrayStateVariable<ExtendedPlace<short> >(name, fullname, ArrayType_SHORT ,size) {
    char varname[12];
    char fqname[strlen(fullname) + strlen(name) + 2];
    sprintf(fqname, "%s%s", fullname, name);
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, fqname, initialValue));
    }
  }

  registers_counter(char* name, short & initialValue):
    ArrayStateVariable<ExtendedPlace<short> >(name, "", ArrayType_SHORT ,size) {
    char varname[12];
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, name, initialValue));
    }
  }

  registers_counter(char* name, char* fullname, short * initialValue):
    ArrayStateVariable<ExtendedPlace<short> >(name, fullname, ArrayType_SHORT ,size) {
    char varname[12];
    char fqname[strlen(fullname) + strlen(name) + 2];
    sprintf(fqname, "%s%s", fullname, name);
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, fqname, initialValue[i]));
    }
  }

  registers_counter(char* name, short * initialValue):
    ArrayStateVariable<ExtendedPlace<short> >(name, "", ArrayType_SHORT ,size) {
    char varname[12];
    for (int i=0;i<size;i++) {
      sprintf(varname,"%d",i);
      fields.push_back(new ExtendedPlace<short>(varname, name, initialValue[i]));
    }
  }
  ~registers_counter() {
    for (fieldIterator i=fields.begin();i!=fields.end();++i)
      delete (*i);
  }
};
#endif

/*********************************************************************
               REGISTER_FILESAN Submodel Definition                   
*********************************************************************/

class REGISTER_FILESAN:public SANModel{
public:

class Instantaneous_Activity23Activity:public Activity {
public:

  Place* KO_CONTENT_TEMP;
  short* KO_CONTENT_TEMP_Mobius_Mark;
  Place* MEM_OP_COMPLETE;
  short* MEM_OP_COMPLETE_Mobius_Mark;

  double* TheDistributionParameters;
  Instantaneous_Activity23Activity();
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
}; // Instantaneous_Activity23ActivityActivity

class Instantaneous_Activity12Activity:public Activity {
public:

  Place* OK_CONTENT_TEMP;
  short* OK_CONTENT_TEMP_Mobius_Mark;
  Place* MEM_OP_COMPLETE;
  short* MEM_OP_COMPLETE_Mobius_Mark;

  double* TheDistributionParameters;
  Instantaneous_Activity12Activity();
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
}; // Instantaneous_Activity12ActivityActivity

class WRITE_WITH_KO_DATAActivity:public Activity {
public:

  Place* WRITE_REGISTER_FILE;
  short* WRITE_REGISTER_FILE_Mobius_Mark;
  Place* RESULT_KO;
  short* RESULT_KO_Mobius_Mark;
  Place* KO_CONTENT_TEMP;
  short* KO_CONTENT_TEMP_Mobius_Mark;
  Place* REG_KO_CONTENT;
  short* REG_KO_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  WRITE_WITH_KO_DATAActivity();
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
}; // WRITE_WITH_KO_DATAActivityActivity

class WRITE_WITH_OK_DATAActivity:public Activity {
public:

  Place* WRITE_REGISTER_FILE;
  short* WRITE_REGISTER_FILE_Mobius_Mark;
  Place* RESULT_OK;
  short* RESULT_OK_Mobius_Mark;
  Place* OK_CONTENT_TEMP;
  short* OK_CONTENT_TEMP_Mobius_Mark;
  Place* REG_OK_CONTENT;
  short* REG_OK_CONTENT_Mobius_Mark;

  double* TheDistributionParameters;
  WRITE_WITH_OK_DATAActivity();
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
}; // WRITE_WITH_OK_DATAActivityActivity

class Instantaneous_Activity2Activity:public Activity {
public:

  Place* MEMORY_KO;
  short* MEMORY_KO_Mobius_Mark;
  Place* MEM_OP_COMPLETE;
  short* MEM_OP_COMPLETE_Mobius_Mark;
  Place* KO_READ;
  short* KO_READ_Mobius_Mark;

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

class READ_FROMActivity_case1:public Activity {
public:

  Place* READ_REGISTER_FILE;
  short* READ_REGISTER_FILE_Mobius_Mark;
  Place* MEMORY_OK;
  short* MEMORY_OK_Mobius_Mark;

  double* TheDistributionParameters;
  READ_FROMActivity_case1();
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
}; // READ_FROMActivity_case1Activity

class READ_FROMActivity_case2:public Activity {
public:

  Place* READ_REGISTER_FILE;
  short* READ_REGISTER_FILE_Mobius_Mark;
  Place* MEMORY_KO;
  short* MEMORY_KO_Mobius_Mark;

  double* TheDistributionParameters;
  READ_FROMActivity_case2();
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
}; // READ_FROMActivity_case2Activity

class Instantaneous_Activity1Activity:public Activity {
public:

  Place* MEMORY_OK;
  short* MEMORY_OK_Mobius_Mark;
  Place* MEM_OP_COMPLETE;
  short* MEM_OP_COMPLETE_Mobius_Mark;
  Place* OK_READ;
  short* OK_READ_Mobius_Mark;

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

class Instantaneous_Activity3Activity:public Activity {
public:

  Place* indexes;
  short* indexes_Mobius_Mark;
  Place* REGISTERS_FILL;
  short* REGISTERS_FILL_Mobius_Mark;
  Place* REG_OK_CONTENT;
  short* REG_OK_CONTENT_Mobius_Mark;
  registers_counter* LIVE_REGISTERS;
  Place* OK_CONTENT_TEMP;
  short* OK_CONTENT_TEMP_Mobius_Mark;

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

  //List of user-specified place names
  Place* KO_CONTENT_TEMP;
  Place* MEM_OP_COMPLETE;
  Place* OK_CONTENT_TEMP;
  Place* WRITE_REGISTER_FILE;
  Place* RESULT_KO;
  Place* RESULT_OK;
  Place* KO_READ;
  Place* MEMORY_KO;
  Place* READ_REGISTER_FILE;
  Place* MEMORY_OK;
  Place* OK_READ;
  Place* indexes;
  Place* REGISTERS_FILL;
  Place* REG_OK_CONTENT;
  Place* REG_KO_CONTENT;
  registers_counter* LIVE_REGISTERS;

  // Create instances of all actvities
  Instantaneous_Activity23Activity Instantaneous_Activity23;
  Instantaneous_Activity12Activity Instantaneous_Activity12;
  WRITE_WITH_KO_DATAActivity WRITE_WITH_KO_DATA;
  WRITE_WITH_OK_DATAActivity WRITE_WITH_OK_DATA;
  Instantaneous_Activity2Activity Instantaneous_Activity2;
  READ_FROMActivity_case1 READ_FROM_case1;
  READ_FROMActivity_case2 READ_FROM_case2;
  Instantaneous_Activity1Activity Instantaneous_Activity1;
  Instantaneous_Activity3Activity Instantaneous_Activity3;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup Instantaneous_Activity23Group;
  PostselectGroup Instantaneous_Activity12Group;
  PostselectGroup WRITE_WITH_KO_DATAGroup;
  PostselectGroup WRITE_WITH_OK_DATAGroup;
  PostselectGroup Instantaneous_Activity2Group;
  PostselectGroup READ_FROMGroup;
  PostselectGroup Instantaneous_Activity1Group;
  PostselectGroup Instantaneous_Activity3Group;

  REGISTER_FILESAN();
  ~REGISTER_FILESAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end REGISTER_FILESAN

#endif // REGISTER_FILESAN_H_
