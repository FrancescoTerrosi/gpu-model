
#include "Study/GPU_STUDY/GPU_STUDYSetStudy.h"

//******************************************************
//Global Variables
//******************************************************
Short dram_size;
Short end;
Short failure_index;
Short l1_size;
Short l2_size;
Short ngpu;
Short nprocessors;
Short nwarps;
Short register_count_index;
Short size;

//********************************************************
//GPU_STUDYSetStudy Constructor
//********************************************************
GPU_STUDYSetStudy::GPU_STUDYSetStudy() {

  // define arrays of global variable names and types
  NumGVs = 10;
  NumExps = 1;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];
  GVNames[0]=strdup("dram_size");
  GVTypes[0]=strdup("short");
  GVNames[1]=strdup("end");
  GVTypes[1]=strdup("short");
  GVNames[2]=strdup("failure_index");
  GVTypes[2]=strdup("short");
  GVNames[3]=strdup("l1_size");
  GVTypes[3]=strdup("short");
  GVNames[4]=strdup("l2_size");
  GVTypes[4]=strdup("short");
  GVNames[5]=strdup("ngpu");
  GVTypes[5]=strdup("short");
  GVNames[6]=strdup("nprocessors");
  GVTypes[6]=strdup("short");
  GVNames[7]=strdup("nwarps");
  GVTypes[7]=strdup("short");
  GVNames[8]=strdup("register_count_index");
  GVTypes[8]=strdup("short");
  GVNames[9]=strdup("size");
  GVTypes[9]=strdup("short");

  // create the arrays to store the values of each gv
  dram_sizeValues = new short[NumExps];
  endValues = new short[NumExps];
  failure_indexValues = new short[NumExps];
  l1_sizeValues = new short[NumExps];
  l2_sizeValues = new short[NumExps];
  ngpuValues = new short[NumExps];
  nprocessorsValues = new short[NumExps];
  nwarpsValues = new short[NumExps];
  register_count_indexValues = new short[NumExps];
  sizeValues = new short[NumExps];

  // call methods to assign values to each gv
  SetValues_dram_size();
  SetValues_end();
  SetValues_failure_index();
  SetValues_l1_size();
  SetValues_l2_size();
  SetValues_ngpu();
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
  delete [] dram_sizeValues;
  delete [] endValues;
  delete [] failure_indexValues;
  delete [] l1_sizeValues;
  delete [] l2_sizeValues;
  delete [] ngpuValues;
  delete [] nprocessorsValues;
  delete [] nwarpsValues;
  delete [] register_count_indexValues;
  delete [] sizeValues;
  delete ThePVModel;
}


//******************************************************
// set values for dram_size
//******************************************************
void GPU_STUDYSetStudy::SetValues_dram_size() {
  dram_sizeValues[0] = 100;
}


//******************************************************
// set values for end
//******************************************************
void GPU_STUDYSetStudy::SetValues_end() {
  endValues[0] = 100;
}


//******************************************************
// set values for failure_index
//******************************************************
void GPU_STUDYSetStudy::SetValues_failure_index() {
  failure_indexValues[0] = 10;
}


//******************************************************
// set values for l1_size
//******************************************************
void GPU_STUDYSetStudy::SetValues_l1_size() {
  l1_sizeValues[0] = 100;
}


//******************************************************
// set values for l2_size
//******************************************************
void GPU_STUDYSetStudy::SetValues_l2_size() {
  l2_sizeValues[0] = 100;
}


//******************************************************
// set values for ngpu
//******************************************************
void GPU_STUDYSetStudy::SetValues_ngpu() {
  ngpuValues[0] = 1;
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
  sizeValues[0] = 3781;
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
  cout << "dram_size\tshort\t" << dram_size << endl;
  cout << "end\tshort\t" << end << endl;
  cout << "failure_index\tshort\t" << failure_index << endl;
  cout << "l1_size\tshort\t" << l1_size << endl;
  cout << "l2_size\tshort\t" << l2_size << endl;
  cout << "ngpu\tshort\t" << ngpu << endl;
  cout << "nprocessors\tshort\t" << nprocessors << endl;
  cout << "nwarps\tshort\t" << nwarps << endl;
  cout << "register_count_index\tshort\t" << register_count_index << endl;
  cout << "size\tshort\t" << size << endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *GPU_STUDYSetStudy::GetGVValue(char *TheGVName) {
  if (strcmp("dram_size", TheGVName) == 0)
    return &dram_size;
  else if (strcmp("end", TheGVName) == 0)
    return &end;
  else if (strcmp("failure_index", TheGVName) == 0)
    return &failure_index;
  else if (strcmp("l1_size", TheGVName) == 0)
    return &l1_size;
  else if (strcmp("l2_size", TheGVName) == 0)
    return &l2_size;
  else if (strcmp("ngpu", TheGVName) == 0)
    return &ngpu;
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
  if (strcmp("dram_size", TheGVName) == 0)
    SetGvValue(dram_size, *(short *)TheGVValue);
  else if (strcmp("end", TheGVName) == 0)
    SetGvValue(end, *(short *)TheGVValue);
  else if (strcmp("failure_index", TheGVName) == 0)
    SetGvValue(failure_index, *(short *)TheGVValue);
  else if (strcmp("l1_size", TheGVName) == 0)
    SetGvValue(l1_size, *(short *)TheGVValue);
  else if (strcmp("l2_size", TheGVName) == 0)
    SetGvValue(l2_size, *(short *)TheGVValue);
  else if (strcmp("ngpu", TheGVName) == 0)
    SetGvValue(ngpu, *(short *)TheGVValue);
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
  SetGvValue(dram_size, dram_sizeValues[expNum]);
  SetGvValue(end, endValues[expNum]);
  SetGvValue(failure_index, failure_indexValues[expNum]);
  SetGvValue(l1_size, l1_sizeValues[expNum]);
  SetGvValue(l2_size, l2_sizeValues[expNum]);
  SetGvValue(ngpu, ngpuValues[expNum]);
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


