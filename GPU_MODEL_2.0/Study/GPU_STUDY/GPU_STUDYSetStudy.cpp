
#include "Study/GPU_STUDY/GPU_STUDYSetStudy.h"

//******************************************************
//Global Variables
//******************************************************
Short end;
Short nprocessors;
Short nwarps;
Short register_count_index;
Short size;

//********************************************************
//GPU_STUDYSetStudy Constructor
//********************************************************
GPU_STUDYSetStudy::GPU_STUDYSetStudy() {

  // define arrays of global variable names and types
  NumGVs = 5;
  NumExps = 1;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];
  GVNames[0]=strdup("end");
  GVTypes[0]=strdup("short");
  GVNames[1]=strdup("nprocessors");
  GVTypes[1]=strdup("short");
  GVNames[2]=strdup("nwarps");
  GVTypes[2]=strdup("short");
  GVNames[3]=strdup("register_count_index");
  GVTypes[3]=strdup("short");
  GVNames[4]=strdup("size");
  GVTypes[4]=strdup("short");

  // create the arrays to store the values of each gv
  endValues = new short[NumExps];
  nprocessorsValues = new short[NumExps];
  nwarpsValues = new short[NumExps];
  register_count_indexValues = new short[NumExps];
  sizeValues = new short[NumExps];

  // call methods to assign values to each gv
  SetValues_end();
  SetValues_nprocessors();
  SetValues_nwarps();
  SetValues_register_count_index();
  SetValues_size();
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//GPU_STUDYSetStudy Destructor
//******************************************************
GPU_STUDYSetStudy::~GPU_STUDYSetStudy() {
  delete [] endValues;
  delete [] nprocessorsValues;
  delete [] nwarpsValues;
  delete [] register_count_indexValues;
  delete [] sizeValues;
  delete ThePVModel;
}


//******************************************************
// set values for end
//******************************************************
void GPU_STUDYSetStudy::SetValues_end() {
  endValues[0] = 100;
}


//******************************************************
// set values for nprocessors
//******************************************************
void GPU_STUDYSetStudy::SetValues_nprocessors() {
  nprocessorsValues[0] = 1.0;
}


//******************************************************
// set values for nwarps
//******************************************************
void GPU_STUDYSetStudy::SetValues_nwarps() {
  nwarpsValues[0] = 1.0;
}


//******************************************************
// set values for register_count_index
//******************************************************
void GPU_STUDYSetStudy::SetValues_register_count_index() {
  register_count_indexValues[0] = 0;
}


//******************************************************
// set values for size
//******************************************************
void GPU_STUDYSetStudy::SetValues_size() {
  sizeValues[0] = 2;
}



//******************************************************
//print values of gv (for debugging)
//******************************************************
void GPU_STUDYSetStudy::PrintGlobalValues(int expNum) {
  if (NumGVs == 0) {
    cout<<"There are no global variables."<<endl;
    return;
  }

  SetGVs(expNum);

  cout<<"The Global Variable values for experiment "<<
    GetExpName(expNum)<<" are:"<<endl;
  cout << "end\tshort\t" << end << endl;
  cout << "nprocessors\tshort\t" << nprocessors << endl;
  cout << "nwarps\tshort\t" << nwarps << endl;
  cout << "register_count_index\tshort\t" << register_count_index << endl;
  cout << "size\tshort\t" << size << endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *GPU_STUDYSetStudy::GetGVValue(char *TheGVName) {
  if (strcmp("end", TheGVName) == 0)
    return &end;
  else if (strcmp("nprocessors", TheGVName) == 0)
    return &nprocessors;
  else if (strcmp("nwarps", TheGVName) == 0)
    return &nwarps;
  else if (strcmp("register_count_index", TheGVName) == 0)
    return &register_count_index;
  else if (strcmp("size", TheGVName) == 0)
    return &size;
  else 
    cerr<<"!! GPU_STUDYSetStudy::GetGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
  return NULL;
}


//******************************************************
//override the value of a global variable
//******************************************************
void GPU_STUDYSetStudy::OverrideGVValue(char *TheGVName,void *TheGVValue) {
  if (strcmp("end", TheGVName) == 0)
    SetGvValue(end, *(short *)TheGVValue);
  else if (strcmp("nprocessors", TheGVName) == 0)
    SetGvValue(nprocessors, *(short *)TheGVValue);
  else if (strcmp("nwarps", TheGVName) == 0)
    SetGvValue(nwarps, *(short *)TheGVValue);
  else if (strcmp("register_count_index", TheGVName) == 0)
    SetGvValue(register_count_index, *(short *)TheGVValue);
  else if (strcmp("size", TheGVName) == 0)
    SetGvValue(size, *(short *)TheGVValue);
  else 
    cerr<<"!! GPU_STUDYSetStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void GPU_STUDYSetStudy::SetGVs(int expNum) {
  SetGvValue(end, endValues[expNum]);
  SetGvValue(nprocessors, nprocessorsValues[expNum]);
  SetGvValue(nwarps, nwarpsValues[expNum]);
  SetGvValue(register_count_index, register_count_indexValues[expNum]);
  SetGvValue(size, sizeValues[expNum]);
}


//******************************************************
//static class method called by solvers to create study 
//(and thus create all of the model)
//******************************************************
BaseStudyClass* GlobalStudyPtr = NULL;
BaseStudyClass * GenerateStudy() {
  if (GlobalStudyPtr == NULL)
    GlobalStudyPtr = new GPU_STUDYSetStudy();
  return GlobalStudyPtr;
}

void DestructStudy() {
  delete GlobalStudyPtr;
  GlobalStudyPtr = NULL;
}
//******************************************************
//get and create the PVModel
//******************************************************
PVModel* GPU_STUDYSetStudy::GetPVModel(bool expandTimeArrays) {
  if (ThePVModel!=NULL)
    delete ThePVModel;
  // create the PV model
  ThePVModel=new GPU5PVModel(expandTimeArrays);
  return ThePVModel;
}


