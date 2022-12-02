
#include "Study/GPUS_STUDY/GPUS_STUDYSetStudy.h"

//******************************************************
//Global Variables
//******************************************************
Short size;

//********************************************************
//GPUS_STUDYSetStudy Constructor
//********************************************************
GPUS_STUDYSetStudy::GPUS_STUDYSetStudy() {

  // define arrays of global variable names and types
  NumGVs = 1;
  NumExps = 1;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];
  GVNames[0]=strdup("size");
  GVTypes[0]=strdup("short");

  // create the arrays to store the values of each gv
  sizeValues = new short[NumExps];

  // call methods to assign values to each gv
  SetValues_size();
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//GPUS_STUDYSetStudy Destructor
//******************************************************
GPUS_STUDYSetStudy::~GPUS_STUDYSetStudy() {
  delete [] sizeValues;
  delete ThePVModel;
}


//******************************************************
// set values for size
//******************************************************
void GPUS_STUDYSetStudy::SetValues_size() {
  sizeValues[0] = 13;
}



//******************************************************
//print values of gv (for debugging)
//******************************************************
void GPUS_STUDYSetStudy::PrintGlobalValues(int expNum) {
  if (NumGVs == 0) {
    cout<<"There are no global variables."<<endl;
    return;
  }

  SetGVs(expNum);

  cout<<"The Global Variable values for experiment "<<
    GetExpName(expNum)<<" are:"<<endl;
  cout << "size\tshort\t" << size << endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *GPUS_STUDYSetStudy::GetGVValue(char *TheGVName) {
  if (strcmp("size", TheGVName) == 0)
    return &size;
  else 
    cerr<<"!! GPUS_STUDYSetStudy::GetGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
  return NULL;
}


//******************************************************
//override the value of a global variable
//******************************************************
void GPUS_STUDYSetStudy::OverrideGVValue(char *TheGVName,void *TheGVValue) {
  if (strcmp("size", TheGVName) == 0)
    SetGvValue(size, *(short *)TheGVValue);
  else 
    cerr<<"!! GPUS_STUDYSetStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void GPUS_STUDYSetStudy::SetGVs(int expNum) {
  SetGvValue(size, sizeValues[expNum]);
}


//******************************************************
//static class method called by solvers to create study 
//(and thus create all of the model)
//******************************************************
BaseStudyClass* GlobalStudyPtr = NULL;
BaseStudyClass * GenerateStudy() {
  if (GlobalStudyPtr == NULL)
    GlobalStudyPtr = new GPUS_STUDYSetStudy();
  return GlobalStudyPtr;
}

void DestructStudy() {
  delete GlobalStudyPtr;
  GlobalStudyPtr = NULL;
}
//******************************************************
//get and create the PVModel
//******************************************************
PVModel* GPUS_STUDYSetStudy::GetPVModel(bool expandTimeArrays) {
  if (ThePVModel!=NULL)
    delete ThePVModel;
  // create the PV model
  ThePVModel=new GPU_REWARDPVModel(expandTimeArrays);
  return ThePVModel;
}


