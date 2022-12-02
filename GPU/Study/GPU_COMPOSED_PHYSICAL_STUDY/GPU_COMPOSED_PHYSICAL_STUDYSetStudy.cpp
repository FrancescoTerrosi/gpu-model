
#include "Study/GPU_COMPOSED_PHYSICAL_STUDY/GPU_COMPOSED_PHYSICAL_STUDYSetStudy.h"

//******************************************************
//Global Variables
//******************************************************
Float dram_result_read_rate;
Float dram_result_write_rate;
Float dram_total_read_rate;
Float l1_result_read_rate;
Float l1_result_write_rate;
Float l2_result_read_rate;
Float l2_result_write_rate;
Float l2_total_read_rate;
Short size;

//********************************************************
//GPU_COMPOSED_PHYSICAL_STUDYSetStudy Constructor
//********************************************************
GPU_COMPOSED_PHYSICAL_STUDYSetStudy::GPU_COMPOSED_PHYSICAL_STUDYSetStudy() {

  // define arrays of global variable names and types
  NumGVs = 9;
  NumExps = 1;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];
  GVNames[0]=strdup("dram_result_read_rate");
  GVTypes[0]=strdup("float");
  GVNames[1]=strdup("dram_result_write_rate");
  GVTypes[1]=strdup("float");
  GVNames[2]=strdup("dram_total_read_rate");
  GVTypes[2]=strdup("float");
  GVNames[3]=strdup("l1_result_read_rate");
  GVTypes[3]=strdup("float");
  GVNames[4]=strdup("l1_result_write_rate");
  GVTypes[4]=strdup("float");
  GVNames[5]=strdup("l2_result_read_rate");
  GVTypes[5]=strdup("float");
  GVNames[6]=strdup("l2_result_write_rate");
  GVTypes[6]=strdup("float");
  GVNames[7]=strdup("l2_total_read_rate");
  GVTypes[7]=strdup("float");
  GVNames[8]=strdup("size");
  GVTypes[8]=strdup("short");

  // create the arrays to store the values of each gv
  dram_result_read_rateValues = new float[NumExps];
  dram_result_write_rateValues = new float[NumExps];
  dram_total_read_rateValues = new float[NumExps];
  l1_result_read_rateValues = new float[NumExps];
  l1_result_write_rateValues = new float[NumExps];
  l2_result_read_rateValues = new float[NumExps];
  l2_result_write_rateValues = new float[NumExps];
  l2_total_read_rateValues = new float[NumExps];
  sizeValues = new short[NumExps];

  // call methods to assign values to each gv
  SetValues_dram_result_read_rate();
  SetValues_dram_result_write_rate();
  SetValues_dram_total_read_rate();
  SetValues_l1_result_read_rate();
  SetValues_l1_result_write_rate();
  SetValues_l2_result_read_rate();
  SetValues_l2_result_write_rate();
  SetValues_l2_total_read_rate();
  SetValues_size();
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//GPU_COMPOSED_PHYSICAL_STUDYSetStudy Destructor
//******************************************************
GPU_COMPOSED_PHYSICAL_STUDYSetStudy::~GPU_COMPOSED_PHYSICAL_STUDYSetStudy() {
  delete [] dram_result_read_rateValues;
  delete [] dram_result_write_rateValues;
  delete [] dram_total_read_rateValues;
  delete [] l1_result_read_rateValues;
  delete [] l1_result_write_rateValues;
  delete [] l2_result_read_rateValues;
  delete [] l2_result_write_rateValues;
  delete [] l2_total_read_rateValues;
  delete [] sizeValues;
  delete ThePVModel;
}


//******************************************************
// set values for dram_result_read_rate
//******************************************************
void GPU_COMPOSED_PHYSICAL_STUDYSetStudy::SetValues_dram_result_read_rate() {
  dram_result_read_rateValues[0] = 0.0;
}


//******************************************************
// set values for dram_result_write_rate
//******************************************************
void GPU_COMPOSED_PHYSICAL_STUDYSetStudy::SetValues_dram_result_write_rate() {
  dram_result_write_rateValues[0] = 0.0;
}


//******************************************************
// set values for dram_total_read_rate
//******************************************************
void GPU_COMPOSED_PHYSICAL_STUDYSetStudy::SetValues_dram_total_read_rate() {
  dram_total_read_rateValues[0] = 1.0;
}


//******************************************************
// set values for l1_result_read_rate
//******************************************************
void GPU_COMPOSED_PHYSICAL_STUDYSetStudy::SetValues_l1_result_read_rate() {
  l1_result_read_rateValues[0] = 0.04;
}


//******************************************************
// set values for l1_result_write_rate
//******************************************************
void GPU_COMPOSED_PHYSICAL_STUDYSetStudy::SetValues_l1_result_write_rate() {
  l1_result_write_rateValues[0] = 0.97;
}


//******************************************************
// set values for l2_result_read_rate
//******************************************************
void GPU_COMPOSED_PHYSICAL_STUDYSetStudy::SetValues_l2_result_read_rate() {
  l2_result_read_rateValues[0] = 0.96;
}


//******************************************************
// set values for l2_result_write_rate
//******************************************************
void GPU_COMPOSED_PHYSICAL_STUDYSetStudy::SetValues_l2_result_write_rate() {
  l2_result_write_rateValues[0] = 0.03;
}


//******************************************************
// set values for l2_total_read_rate
//******************************************************
void GPU_COMPOSED_PHYSICAL_STUDYSetStudy::SetValues_l2_total_read_rate() {
  l2_total_read_rateValues[0] = 0.0;
}


//******************************************************
// set values for size
//******************************************************
void GPU_COMPOSED_PHYSICAL_STUDYSetStudy::SetValues_size() {
  sizeValues[0] = 13;
}



//******************************************************
//print values of gv (for debugging)
//******************************************************
void GPU_COMPOSED_PHYSICAL_STUDYSetStudy::PrintGlobalValues(int expNum) {
  if (NumGVs == 0) {
    cout<<"There are no global variables."<<endl;
    return;
  }

  SetGVs(expNum);

  cout<<"The Global Variable values for experiment "<<
    GetExpName(expNum)<<" are:"<<endl;
  cout << "dram_result_read_rate\tfloat\t" << dram_result_read_rate << endl;
  cout << "dram_result_write_rate\tfloat\t" << dram_result_write_rate << endl;
  cout << "dram_total_read_rate\tfloat\t" << dram_total_read_rate << endl;
  cout << "l1_result_read_rate\tfloat\t" << l1_result_read_rate << endl;
  cout << "l1_result_write_rate\tfloat\t" << l1_result_write_rate << endl;
  cout << "l2_result_read_rate\tfloat\t" << l2_result_read_rate << endl;
  cout << "l2_result_write_rate\tfloat\t" << l2_result_write_rate << endl;
  cout << "l2_total_read_rate\tfloat\t" << l2_total_read_rate << endl;
  cout << "size\tshort\t" << size << endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *GPU_COMPOSED_PHYSICAL_STUDYSetStudy::GetGVValue(char *TheGVName) {
  if (strcmp("dram_result_read_rate", TheGVName) == 0)
    return &dram_result_read_rate;
  else if (strcmp("dram_result_write_rate", TheGVName) == 0)
    return &dram_result_write_rate;
  else if (strcmp("dram_total_read_rate", TheGVName) == 0)
    return &dram_total_read_rate;
  else if (strcmp("l1_result_read_rate", TheGVName) == 0)
    return &l1_result_read_rate;
  else if (strcmp("l1_result_write_rate", TheGVName) == 0)
    return &l1_result_write_rate;
  else if (strcmp("l2_result_read_rate", TheGVName) == 0)
    return &l2_result_read_rate;
  else if (strcmp("l2_result_write_rate", TheGVName) == 0)
    return &l2_result_write_rate;
  else if (strcmp("l2_total_read_rate", TheGVName) == 0)
    return &l2_total_read_rate;
  else if (strcmp("size", TheGVName) == 0)
    return &size;
  else 
    cerr<<"!! GPU_COMPOSED_PHYSICAL_STUDYSetStudy::GetGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
  return NULL;
}


//******************************************************
//override the value of a global variable
//******************************************************
void GPU_COMPOSED_PHYSICAL_STUDYSetStudy::OverrideGVValue(char *TheGVName,void *TheGVValue) {
  if (strcmp("dram_result_read_rate", TheGVName) == 0)
    SetGvValue(dram_result_read_rate, *(float *)TheGVValue);
  else if (strcmp("dram_result_write_rate", TheGVName) == 0)
    SetGvValue(dram_result_write_rate, *(float *)TheGVValue);
  else if (strcmp("dram_total_read_rate", TheGVName) == 0)
    SetGvValue(dram_total_read_rate, *(float *)TheGVValue);
  else if (strcmp("l1_result_read_rate", TheGVName) == 0)
    SetGvValue(l1_result_read_rate, *(float *)TheGVValue);
  else if (strcmp("l1_result_write_rate", TheGVName) == 0)
    SetGvValue(l1_result_write_rate, *(float *)TheGVValue);
  else if (strcmp("l2_result_read_rate", TheGVName) == 0)
    SetGvValue(l2_result_read_rate, *(float *)TheGVValue);
  else if (strcmp("l2_result_write_rate", TheGVName) == 0)
    SetGvValue(l2_result_write_rate, *(float *)TheGVValue);
  else if (strcmp("l2_total_read_rate", TheGVName) == 0)
    SetGvValue(l2_total_read_rate, *(float *)TheGVValue);
  else if (strcmp("size", TheGVName) == 0)
    SetGvValue(size, *(short *)TheGVValue);
  else 
    cerr<<"!! GPU_COMPOSED_PHYSICAL_STUDYSetStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void GPU_COMPOSED_PHYSICAL_STUDYSetStudy::SetGVs(int expNum) {
  SetGvValue(dram_result_read_rate, dram_result_read_rateValues[expNum]);
  SetGvValue(dram_result_write_rate, dram_result_write_rateValues[expNum]);
  SetGvValue(dram_total_read_rate, dram_total_read_rateValues[expNum]);
  SetGvValue(l1_result_read_rate, l1_result_read_rateValues[expNum]);
  SetGvValue(l1_result_write_rate, l1_result_write_rateValues[expNum]);
  SetGvValue(l2_result_read_rate, l2_result_read_rateValues[expNum]);
  SetGvValue(l2_result_write_rate, l2_result_write_rateValues[expNum]);
  SetGvValue(l2_total_read_rate, l2_total_read_rateValues[expNum]);
  SetGvValue(size, sizeValues[expNum]);
}


//******************************************************
//static class method called by solvers to create study 
//(and thus create all of the model)
//******************************************************
BaseStudyClass* GlobalStudyPtr = NULL;
BaseStudyClass * GenerateStudy() {
  if (GlobalStudyPtr == NULL)
    GlobalStudyPtr = new GPU_COMPOSED_PHYSICAL_STUDYSetStudy();
  return GlobalStudyPtr;
}

void DestructStudy() {
  delete GlobalStudyPtr;
  GlobalStudyPtr = NULL;
}
//******************************************************
//get and create the PVModel
//******************************************************
PVModel* GPU_COMPOSED_PHYSICAL_STUDYSetStudy::GetPVModel(bool expandTimeArrays) {
  if (ThePVModel!=NULL)
    delete ThePVModel;
  // create the PV model
  ThePVModel=new GPU_COMPOSED_PHYSICAL_REWARDPVModel(expandTimeArrays);
  return ThePVModel;
}


