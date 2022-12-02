
#include "Study/GPU_STUDY/GPU_STUDYSetStudy.h"

//******************************************************
//Global Variables
//******************************************************
Float dram_result_read_prob;
Float dram_result_write_prob;
Float dram_total_read_prob;
Short end;
Float l1_result_read_prob;
Float l1_result_write_prob;
Float l2_result_read_prob;
Float l2_result_write_prob;
Float l2_total_read_prob;
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
  GVNames[0]=strdup("dram_result_read_prob");
  GVTypes[0]=strdup("float");
  GVNames[1]=strdup("dram_result_write_prob");
  GVTypes[1]=strdup("float");
  GVNames[2]=strdup("dram_total_read_prob");
  GVTypes[2]=strdup("float");
  GVNames[3]=strdup("end");
  GVTypes[3]=strdup("short");
  GVNames[4]=strdup("l1_result_read_prob");
  GVTypes[4]=strdup("float");
  GVNames[5]=strdup("l1_result_write_prob");
  GVTypes[5]=strdup("float");
  GVNames[6]=strdup("l2_result_read_prob");
  GVTypes[6]=strdup("float");
  GVNames[7]=strdup("l2_result_write_prob");
  GVTypes[7]=strdup("float");
  GVNames[8]=strdup("l2_total_read_prob");
  GVTypes[8]=strdup("float");
  GVNames[9]=strdup("size");
  GVTypes[9]=strdup("short");

  // create the arrays to store the values of each gv
  dram_result_read_probValues = new float[NumExps];
  dram_result_write_probValues = new float[NumExps];
  dram_total_read_probValues = new float[NumExps];
  endValues = new short[NumExps];
  l1_result_read_probValues = new float[NumExps];
  l1_result_write_probValues = new float[NumExps];
  l2_result_read_probValues = new float[NumExps];
  l2_result_write_probValues = new float[NumExps];
  l2_total_read_probValues = new float[NumExps];
  sizeValues = new short[NumExps];

  // call methods to assign values to each gv
  SetValues_dram_result_read_prob();
  SetValues_dram_result_write_prob();
  SetValues_dram_total_read_prob();
  SetValues_end();
  SetValues_l1_result_read_prob();
  SetValues_l1_result_write_prob();
  SetValues_l2_result_read_prob();
  SetValues_l2_result_write_prob();
  SetValues_l2_total_read_prob();
  SetValues_size();
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//GPU_STUDYSetStudy Destructor
//******************************************************
GPU_STUDYSetStudy::~GPU_STUDYSetStudy() {
  delete [] dram_result_read_probValues;
  delete [] dram_result_write_probValues;
  delete [] dram_total_read_probValues;
  delete [] endValues;
  delete [] l1_result_read_probValues;
  delete [] l1_result_write_probValues;
  delete [] l2_result_read_probValues;
  delete [] l2_result_write_probValues;
  delete [] l2_total_read_probValues;
  delete [] sizeValues;
  delete ThePVModel;
}


//******************************************************
// set values for dram_result_read_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_dram_result_read_prob() {
  dram_result_read_probValues[0] = 0;
}


//******************************************************
// set values for dram_result_write_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_dram_result_write_prob() {
  dram_result_write_probValues[0] = 0;
}


//******************************************************
// set values for dram_total_read_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_dram_total_read_prob() {
  dram_total_read_probValues[0] = 0.02;
}


//******************************************************
// set values for end
//******************************************************
void GPU_STUDYSetStudy::SetValues_end() {
  endValues[0] = 1000;
}


//******************************************************
// set values for l1_result_read_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_l1_result_read_prob() {
  l1_result_read_probValues[0] = 1.0;
}


//******************************************************
// set values for l1_result_write_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_l1_result_write_prob() {
  l1_result_write_probValues[0] = 1.0;
}


//******************************************************
// set values for l2_result_read_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_l2_result_read_prob() {
  l2_result_read_probValues[0] = 0.0;
}


//******************************************************
// set values for l2_result_write_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_l2_result_write_prob() {
  l2_result_write_probValues[0] = 0.0;
}


//******************************************************
// set values for l2_total_read_prob
//******************************************************
void GPU_STUDYSetStudy::SetValues_l2_total_read_prob() {
  l2_total_read_probValues[0] = 0.98;
}


//******************************************************
// set values for size
//******************************************************
void GPU_STUDYSetStudy::SetValues_size() {
  sizeValues[0] = 13;
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
  cout << "dram_result_read_prob\tfloat\t" << dram_result_read_prob << endl;
  cout << "dram_result_write_prob\tfloat\t" << dram_result_write_prob << endl;
  cout << "dram_total_read_prob\tfloat\t" << dram_total_read_prob << endl;
  cout << "end\tshort\t" << end << endl;
  cout << "l1_result_read_prob\tfloat\t" << l1_result_read_prob << endl;
  cout << "l1_result_write_prob\tfloat\t" << l1_result_write_prob << endl;
  cout << "l2_result_read_prob\tfloat\t" << l2_result_read_prob << endl;
  cout << "l2_result_write_prob\tfloat\t" << l2_result_write_prob << endl;
  cout << "l2_total_read_prob\tfloat\t" << l2_total_read_prob << endl;
  cout << "size\tshort\t" << size << endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *GPU_STUDYSetStudy::GetGVValue(char *TheGVName) {
  if (strcmp("dram_result_read_prob", TheGVName) == 0)
    return &dram_result_read_prob;
  else if (strcmp("dram_result_write_prob", TheGVName) == 0)
    return &dram_result_write_prob;
  else if (strcmp("dram_total_read_prob", TheGVName) == 0)
    return &dram_total_read_prob;
  else if (strcmp("end", TheGVName) == 0)
    return &end;
  else if (strcmp("l1_result_read_prob", TheGVName) == 0)
    return &l1_result_read_prob;
  else if (strcmp("l1_result_write_prob", TheGVName) == 0)
    return &l1_result_write_prob;
  else if (strcmp("l2_result_read_prob", TheGVName) == 0)
    return &l2_result_read_prob;
  else if (strcmp("l2_result_write_prob", TheGVName) == 0)
    return &l2_result_write_prob;
  else if (strcmp("l2_total_read_prob", TheGVName) == 0)
    return &l2_total_read_prob;
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
  if (strcmp("dram_result_read_prob", TheGVName) == 0)
    SetGvValue(dram_result_read_prob, *(float *)TheGVValue);
  else if (strcmp("dram_result_write_prob", TheGVName) == 0)
    SetGvValue(dram_result_write_prob, *(float *)TheGVValue);
  else if (strcmp("dram_total_read_prob", TheGVName) == 0)
    SetGvValue(dram_total_read_prob, *(float *)TheGVValue);
  else if (strcmp("end", TheGVName) == 0)
    SetGvValue(end, *(short *)TheGVValue);
  else if (strcmp("l1_result_read_prob", TheGVName) == 0)
    SetGvValue(l1_result_read_prob, *(float *)TheGVValue);
  else if (strcmp("l1_result_write_prob", TheGVName) == 0)
    SetGvValue(l1_result_write_prob, *(float *)TheGVValue);
  else if (strcmp("l2_result_read_prob", TheGVName) == 0)
    SetGvValue(l2_result_read_prob, *(float *)TheGVValue);
  else if (strcmp("l2_result_write_prob", TheGVName) == 0)
    SetGvValue(l2_result_write_prob, *(float *)TheGVValue);
  else if (strcmp("l2_total_read_prob", TheGVName) == 0)
    SetGvValue(l2_total_read_prob, *(float *)TheGVValue);
  else if (strcmp("size", TheGVName) == 0)
    SetGvValue(size, *(short *)TheGVValue);
  else 
    cerr<<"!! GPU_STUDYSetStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void GPU_STUDYSetStudy::SetGVs(int expNum) {
  SetGvValue(dram_result_read_prob, dram_result_read_probValues[expNum]);
  SetGvValue(dram_result_write_prob, dram_result_write_probValues[expNum]);
  SetGvValue(dram_total_read_prob, dram_total_read_probValues[expNum]);
  SetGvValue(end, endValues[expNum]);
  SetGvValue(l1_result_read_prob, l1_result_read_probValues[expNum]);
  SetGvValue(l1_result_write_prob, l1_result_write_probValues[expNum]);
  SetGvValue(l2_result_read_prob, l2_result_read_probValues[expNum]);
  SetGvValue(l2_result_write_prob, l2_result_write_probValues[expNum]);
  SetGvValue(l2_total_read_prob, l2_total_read_probValues[expNum]);
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
  ThePVModel=new GPU_REWARDPVModel(expandTimeArrays);
  return ThePVModel;
}


