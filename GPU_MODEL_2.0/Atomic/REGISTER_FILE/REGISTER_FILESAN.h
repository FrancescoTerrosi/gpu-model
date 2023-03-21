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

class Instantaneous_Activity3Activity_case1:public Activity {
public:

  Place* indexes;
  short* indexes_Mobius_Mark;
  Place* REGISTERS_FILL;
  short* REGISTERS_FILL_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;
  registers_counter* LIVE_REGISTERS;

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

  Place* indexes;
  short* indexes_Mobius_Mark;
  Place* REGISTERS_FILL;
  short* REGISTERS_FILL_Mobius_Mark;
  Place* KO_CONTENT;
  short* KO_CONTENT_Mobius_Mark;
  Place* OK_CONTENT;
  short* OK_CONTENT_Mobius_Mark;
  registers_counter* LIVE_REGISTERS;

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

  //List of user-specified place names
  Place* indexes;
  Place* REGISTERS_FILL;
  Place* OK_CONTENT;
  Place* KO_CONTENT;
  registers_counter* LIVE_REGISTERS;

  // Create instances of all actvities
  Instantaneous_Activity3Activity_case1 Instantaneous_Activity3_case1;
  Instantaneous_Activity3Activity_case2 Instantaneous_Activity3_case2;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup Instantaneous_Activity3Group;

  REGISTER_FILESAN();
  ~REGISTER_FILESAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end REGISTER_FILESAN

#endif // REGISTER_FILESAN_H_
