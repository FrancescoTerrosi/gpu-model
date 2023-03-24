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

class Instantaneous_Activity3Activity:public Activity {
public:

  Place* indexes;
  short* indexes_Mobius_Mark;
  Place* REGISTERS_FILL;
  short* REGISTERS_FILL_Mobius_Mark;
  Place* WRITE_REG;
  short* WRITE_REG_Mobius_Mark;
  registers_counter* LIVE_REGISTERS;

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

class Instantaneous_Activity1Activity:public Activity {
public:

  Place* WRITE_REG;
  short* WRITE_REG_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;

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

  Place* WRITE_REG;
  short* WRITE_REG_Mobius_Mark;
  Place* KO_CONTENT;
  short* KO_CONTENT_Mobius_Mark;

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
  Place* indexes;
  Place* REGISTERS_FILL;
  Place* OK_CONTENT;
  Place* KO_CONTENT;
  Place* REG_FAILURE;
  Place* WRITE_REG;
  Place* RESULT_OK;
  Place* RESULT_KO;
  registers_counter* LIVE_REGISTERS;

  // Create instances of all actvities
  Instantaneous_Activity3Activity Instantaneous_Activity3;
  Instantaneous_Activity1Activity Instantaneous_Activity1;
  Instantaneous_Activity2Activity Instantaneous_Activity2;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup Instantaneous_Activity3Group;
  PostselectGroup Instantaneous_Activity1Group;
  PostselectGroup Instantaneous_Activity2Group;

  REGISTER_FILESAN();
  ~REGISTER_FILESAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end REGISTER_FILESAN

#endif // REGISTER_FILESAN_H_
