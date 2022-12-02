
#include "Study/GPUS_STUDY/GPUS_STUDYSetStudy.h"

//******************************************************
//Global Variables
//******************************************************

//********************************************************
//GPUS_STUDYSetStudy Constructor
//********************************************************
GPUS_STUDYSetStudy::GPUS_STUDYSetStudy() {

  // define arrays of global variable names and types
  NumGVs = 0;
  NumExps = 1;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];

  // create the arrays to store the values of each gv

  // call methods to assign values to each gv
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//GPUS_STUDYSetStudy Destructor
//******************************************************
GPUS_STUDYSetStudy::~GPUS_STUDYSetStudy() {
  delete ThePVModel;
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
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *GPUS_STUDYSetStudy::GetGVValue(char *TheGVName) {
  
    cerr<<"!! GPUS_STUDYSetStudy::GetGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
  return NULL;
}


//******************************************************
//override the value of a global variable
//******************************************************
void GPUS_STUDYSetStudy::OverrideGVValue(char *TheGVName,void *TheGVValue) {
  
    cerr<<"!! GPUS_STUDYSetStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void GPUS_STUDYSetStudy::SetGVs(int expNum) {
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


