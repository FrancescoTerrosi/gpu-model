
#include "Study/GPU_STUDY/GPU_STUDYSetStudy.h"

//******************************************************
//Global Variables
//******************************************************
Float dram_global_read_prob;
Float dram_global_write_prob;
Float dram_local_read_prob;
Float dram_local_write_prob;
Short end;
Float l1_global_read_prob;
Float l1_global_write_prob;
Float l1_local_read_prob;
Float l1_local_write_prob;
Float l2_global_read_prob;
Float l2_global_write_prob;
Float l2_local_read_prob;
Float l2_local_write_prob;
Short nprocessors;
Short nwarps;
Short register_count_index;
Short size;

//********************************************************
//GPU_STUDYSetStudy Constructor
//********************************************************
GPU_STUDYSetStudy::GPU_STUDYSetStudy() {

  // define arrays of global variable names and types
  NumGVs = 17;
  NumExps = 1;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];
  GVNames[0]=strdup("dram_global_read_prob");
  GVTypes[0]=strdup("float");
  GVNames[1]=strdup("dram_global_write_prob");
  GVTypes[1]=strdup("float");
  GVNames[2]=strdup("dram_local_read_prob");
  GVTypes[2]=strdup("float");
  GVNames[3]=strdup("dram_local_write_prob");
  GVTypes[3]=strdup("float");
  GVNames[4]=strdup("end");
  GVTypes[4]=strdup("short");
  GVNames[5]=strdup("l1_global_read_prob");
  GVTypes[5]=strdup("float");
  GVNames[6]=strdup("l1_global_write_prob");
  GVTypes[6]=strdup("float");
  GVNames[7]=strdup("l1_local_read_prob");
  GVTypes[7]=strdup("float");
  GVNames[8]=strdup("l1_local_write_prob");
  GVTypes[8]=strdup("float");
  GVNames[9]=strdup("l2_global_read_prob");
  GVTypes[9]=strdup("float");
  GVNames[10]=strdup("l2_global_write_prob");
  GVTypes[10]=strdup("float");
  GVNames[11]=strdup("l2_local_read_prob");
  GVTypes[11]=strdup("float");
  GVNames[12]=strdup("l2_local_write_prob");
  GVTypes[12]=strdup("float");
  GVNames[13]=strdup("nprocessors");
  GVTypes[13]=strdup("short");
  GVNames[14]=strdup("nwarps");
  GVTypes[14]=strdup("short");
  GVNames[15]=strdup("register_count_index");
  GVTypes[15]=strdup("short");
  GVNames[16]=strdup("size");
  GVTypes[16]=strdup("short");

  // create the arrays to store the values of each gv
  dram_global_read_probValues = new float[NumExps];
  dram_global_write_probValues = new float[NumExps];
  dram_local_read_probValues = new float[NumExps];
  dram_local_write_probValues = new float[NumExps];
  endValues = new short[NumExps];
  l1_global_read_probValues = new float[NumExps];
  l1_global_write_probValues = new float[NumExps];
  l1_local_read_probValues = new float[NumExps];
  l1_local_write_probValues = new float[NumExps];
  l2_global_read_probValues = new float[NumExps];
  l2_global_write_probValues = new float[NumExps];
  l2_local_read_probValues = new float[NumExps];
  l2_local_write_probValues = new float[NumExps];
  nprocessorsValues = new short[NumExps];
  nwarpsValues = new short[NumExps];
  register_count_indexValues = new short[NumExps];
  sizeValues = new short[NumExps];

  // call methods to assign values to each gv
  SetValues_dram_global_read_prob();
  SetValues_dram_global_write_prob();
  SetValues_dram_local_read_prob();
  SetValues_dram_local_write_prob();
  SetValues_end();
  SetValues_l1_global_read_prob();
  SetValues_l1_global_write_prob();
  SetValues_l1_local_read_prob();
  SetValues_l1_local_write_prob();
  SetValues_l2_global_read_prob();
  SetValues_l2_global_write_prob();
  SetValues_l2_local_read_prob();
  SetValues_l2_local_write_prob();
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
  delete [] dram_global_read_probValues;
  delete [] dram_global_write_probValues;
  delete [] dram_local_read_probValues;
  delete [] dram_local_write_probValues;
  delete [] endValues;
  delete [] l1_global_read_probValues;
  delete [] l1_global_write_probValues;
  delete [] l1_local_read_probValues;
  delete [] l1_local_write_probValues;
  delete [] l2_global_read_probValues;
  delete [] l2_global_write_probValues;
  delete [] l2_local_read_probValues;
  delete [] l2_local_write_probValues;
  delete [] nprocessorsValues;
  delete [] nwarpsValues;
  delete [] register_count_indexValues;
  delete [] sizeValues;
  delete ThePVModel;
}


//******************************************************
// set values for dram_global_read_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_dram_global_read_prob() {
  dram_global_read_probValues[0] = 0.067;
}


//******************************************************
// set values for dram_global_write_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_dram_global_write_prob() {
  dram_global_write_probValues[0] = 0.0;
}


//******************************************************
// set values for dram_local_read_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_dram_local_read_prob() {
  dram_local_read_probValues[0] = 0.0;
}


//******************************************************
// set values for dram_local_write_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_dram_local_write_prob() {
  dram_local_write_probValues[0] = 0.0;
}


//******************************************************
// set values for end
//******************************************************
void GPU_STUDYSetStudy::SetValues_end() {
  endValues[0] = 100;
}


//******************************************************
// set values for l1_global_read_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_l1_global_read_prob() {
  l1_global_read_probValues[0] = 0.99;
}


//******************************************************
// set values for l1_global_write_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_l1_global_write_prob() {
  l1_global_write_probValues[0] = 0.93;
}


//******************************************************
// set values for l1_local_read_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_l1_local_read_prob() {
  l1_local_read_probValues[0] = 0.0;
}


//******************************************************
// set values for l1_local_write_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_l1_local_write_prob() {
  l1_local_write_probValues[0] = 0.0;
}


//******************************************************
// set values for l2_global_read_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_l2_global_read_prob() {
  l2_global_read_probValues[0] = 0.0;
}


//******************************************************
// set values for l2_global_write_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_l2_global_write_prob() {
  l2_global_write_probValues[0] = 0.07;
}


//******************************************************
// set values for l2_local_read_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_l2_local_read_prob() {
  l2_local_read_probValues[0] = 0.033;
}


//******************************************************
// set values for l2_local_write_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_l2_local_write_prob() {
  l2_local_write_probValues[0] = 0.0;
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
  cout << "dram_global_read_prob\tfloat\t" << dram_global_read_prob << endl;
  cout << "dram_global_write_prob\tfloat\t" << dram_global_write_prob << endl;
  cout << "dram_local_read_prob\tfloat\t" << dram_local_read_prob << endl;
  cout << "dram_local_write_prob\tfloat\t" << dram_local_write_prob << endl;
  cout << "end\tshort\t" << end << endl;
  cout << "l1_global_read_prob\tfloat\t" << l1_global_read_prob << endl;
  cout << "l1_global_write_prob\tfloat\t" << l1_global_write_prob << endl;
  cout << "l1_local_read_prob\tfloat\t" << l1_local_read_prob << endl;
  cout << "l1_local_write_prob\tfloat\t" << l1_local_write_prob << endl;
  cout << "l2_global_read_prob\tfloat\t" << l2_global_read_prob << endl;
  cout << "l2_global_write_prob\tfloat\t" << l2_global_write_prob << endl;
  cout << "l2_local_read_prob\tfloat\t" << l2_local_read_prob << endl;
  cout << "l2_local_write_prob\tfloat\t" << l2_local_write_prob << endl;
  cout << "nprocessors\tshort\t" << nprocessors << endl;
  cout << "nwarps\tshort\t" << nwarps << endl;
  cout << "register_count_index\tshort\t" << register_count_index << endl;
  cout << "size\tshort\t" << size << endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *GPU_STUDYSetStudy::GetGVValue(char *TheGVName) {
  if (strcmp("dram_global_read_prob", TheGVName) == 0)
    return &dram_global_read_prob;
  else if (strcmp("dram_global_write_prob", TheGVName) == 0)
    return &dram_global_write_prob;
  else if (strcmp("dram_local_read_prob", TheGVName) == 0)
    return &dram_local_read_prob;
  else if (strcmp("dram_local_write_prob", TheGVName) == 0)
    return &dram_local_write_prob;
  else if (strcmp("end", TheGVName) == 0)
    return &end;
  else if (strcmp("l1_global_read_prob", TheGVName) == 0)
    return &l1_global_read_prob;
  else if (strcmp("l1_global_write_prob", TheGVName) == 0)
    return &l1_global_write_prob;
  else if (strcmp("l1_local_read_prob", TheGVName) == 0)
    return &l1_local_read_prob;
  else if (strcmp("l1_local_write_prob", TheGVName) == 0)
    return &l1_local_write_prob;
  else if (strcmp("l2_global_read_prob", TheGVName) == 0)
    return &l2_global_read_prob;
  else if (strcmp("l2_global_write_prob", TheGVName) == 0)
    return &l2_global_write_prob;
  else if (strcmp("l2_local_read_prob", TheGVName) == 0)
    return &l2_local_read_prob;
  else if (strcmp("l2_local_write_prob", TheGVName) == 0)
    return &l2_local_write_prob;
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
  if (strcmp("dram_global_read_prob", TheGVName) == 0)
    SetGvValue(dram_global_read_prob, *(float *)TheGVValue);
  else if (strcmp("dram_global_write_prob", TheGVName) == 0)
    SetGvValue(dram_global_write_prob, *(float *)TheGVValue);
  else if (strcmp("dram_local_read_prob", TheGVName) == 0)
    SetGvValue(dram_local_read_prob, *(float *)TheGVValue);
  else if (strcmp("dram_local_write_prob", TheGVName) == 0)
    SetGvValue(dram_local_write_prob, *(float *)TheGVValue);
  else if (strcmp("end", TheGVName) == 0)
    SetGvValue(end, *(short *)TheGVValue);
  else if (strcmp("l1_global_read_prob", TheGVName) == 0)
    SetGvValue(l1_global_read_prob, *(float *)TheGVValue);
  else if (strcmp("l1_global_write_prob", TheGVName) == 0)
    SetGvValue(l1_global_write_prob, *(float *)TheGVValue);
  else if (strcmp("l1_local_read_prob", TheGVName) == 0)
    SetGvValue(l1_local_read_prob, *(float *)TheGVValue);
  else if (strcmp("l1_local_write_prob", TheGVName) == 0)
    SetGvValue(l1_local_write_prob, *(float *)TheGVValue);
  else if (strcmp("l2_global_read_prob", TheGVName) == 0)
    SetGvValue(l2_global_read_prob, *(float *)TheGVValue);
  else if (strcmp("l2_global_write_prob", TheGVName) == 0)
    SetGvValue(l2_global_write_prob, *(float *)TheGVValue);
  else if (strcmp("l2_local_read_prob", TheGVName) == 0)
    SetGvValue(l2_local_read_prob, *(float *)TheGVValue);
  else if (strcmp("l2_local_write_prob", TheGVName) == 0)
    SetGvValue(l2_local_write_prob, *(float *)TheGVValue);
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
  SetGvValue(dram_global_read_prob, dram_global_read_probValues[expNum]);
  SetGvValue(dram_global_write_prob, dram_global_write_probValues[expNum]);
  SetGvValue(dram_local_read_prob, dram_local_read_probValues[expNum]);
  SetGvValue(dram_local_write_prob, dram_local_write_probValues[expNum]);
  SetGvValue(end, endValues[expNum]);
  SetGvValue(l1_global_read_prob, l1_global_read_probValues[expNum]);
  SetGvValue(l1_global_write_prob, l1_global_write_probValues[expNum]);
  SetGvValue(l1_local_read_prob, l1_local_read_probValues[expNum]);
  SetGvValue(l1_local_write_prob, l1_local_write_probValues[expNum]);
  SetGvValue(l2_global_read_prob, l2_global_read_probValues[expNum]);
  SetGvValue(l2_global_write_prob, l2_global_write_probValues[expNum]);
  SetGvValue(l2_local_read_prob, l2_local_read_probValues[expNum]);
  SetGvValue(l2_local_write_prob, l2_local_write_probValues[expNum]);
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
  ThePVModel=new GPU4PVModel(expandTimeArrays);
  return ThePVModel;
}


