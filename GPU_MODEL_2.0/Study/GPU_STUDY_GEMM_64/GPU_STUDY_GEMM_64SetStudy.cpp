
#include "Study/GPU_STUDY_GEMM_64/GPU_STUDY_GEMM_64SetStudy.h"

//******************************************************
//Global Variables
//******************************************************
Short dram_size;
Short failure_index;
Float global_read_dram;
Float global_read_l1;
Float global_read_l2;
Float global_write_dram;
Float global_write_l1;
Float global_write_l2;
Short l1_size;
Short l2_size;
Float local_read_dram;
Float local_read_l1;
Float local_read_l2;
Float local_write_dram;
Float local_write_l1;
Float local_write_l2;
Short nfailedprocessors;
Short nfailedsm;
Short nfailedwarps;
Short nprocessors;
Short nsm;
Short nwarps;
Short register_count_index;
Short sim_end;
Short size;

//********************************************************
//GPU_STUDY_GEMM_64SetStudy Constructor
//********************************************************
GPU_STUDY_GEMM_64SetStudy::GPU_STUDY_GEMM_64SetStudy() {

  // define arrays of global variable names and types
  NumGVs = 25;
  NumExps = 1;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];
  GVNames[0]=strdup("dram_size");
  GVTypes[0]=strdup("short");
  GVNames[1]=strdup("failure_index");
  GVTypes[1]=strdup("short");
  GVNames[2]=strdup("global_read_dram");
  GVTypes[2]=strdup("float");
  GVNames[3]=strdup("global_read_l1");
  GVTypes[3]=strdup("float");
  GVNames[4]=strdup("global_read_l2");
  GVTypes[4]=strdup("float");
  GVNames[5]=strdup("global_write_dram");
  GVTypes[5]=strdup("float");
  GVNames[6]=strdup("global_write_l1");
  GVTypes[6]=strdup("float");
  GVNames[7]=strdup("global_write_l2");
  GVTypes[7]=strdup("float");
  GVNames[8]=strdup("l1_size");
  GVTypes[8]=strdup("short");
  GVNames[9]=strdup("l2_size");
  GVTypes[9]=strdup("short");
  GVNames[10]=strdup("local_read_dram");
  GVTypes[10]=strdup("float");
  GVNames[11]=strdup("local_read_l1");
  GVTypes[11]=strdup("float");
  GVNames[12]=strdup("local_read_l2");
  GVTypes[12]=strdup("float");
  GVNames[13]=strdup("local_write_dram");
  GVTypes[13]=strdup("float");
  GVNames[14]=strdup("local_write_l1");
  GVTypes[14]=strdup("float");
  GVNames[15]=strdup("local_write_l2");
  GVTypes[15]=strdup("float");
  GVNames[16]=strdup("nfailedprocessors");
  GVTypes[16]=strdup("short");
  GVNames[17]=strdup("nfailedsm");
  GVTypes[17]=strdup("short");
  GVNames[18]=strdup("nfailedwarps");
  GVTypes[18]=strdup("short");
  GVNames[19]=strdup("nprocessors");
  GVTypes[19]=strdup("short");
  GVNames[20]=strdup("nsm");
  GVTypes[20]=strdup("short");
  GVNames[21]=strdup("nwarps");
  GVTypes[21]=strdup("short");
  GVNames[22]=strdup("register_count_index");
  GVTypes[22]=strdup("short");
  GVNames[23]=strdup("sim_end");
  GVTypes[23]=strdup("short");
  GVNames[24]=strdup("size");
  GVTypes[24]=strdup("short");

  // create the arrays to store the values of each gv
  dram_sizeValues = new short[NumExps];
  failure_indexValues = new short[NumExps];
  global_read_dramValues = new float[NumExps];
  global_read_l1Values = new float[NumExps];
  global_read_l2Values = new float[NumExps];
  global_write_dramValues = new float[NumExps];
  global_write_l1Values = new float[NumExps];
  global_write_l2Values = new float[NumExps];
  l1_sizeValues = new short[NumExps];
  l2_sizeValues = new short[NumExps];
  local_read_dramValues = new float[NumExps];
  local_read_l1Values = new float[NumExps];
  local_read_l2Values = new float[NumExps];
  local_write_dramValues = new float[NumExps];
  local_write_l1Values = new float[NumExps];
  local_write_l2Values = new float[NumExps];
  nfailedprocessorsValues = new short[NumExps];
  nfailedsmValues = new short[NumExps];
  nfailedwarpsValues = new short[NumExps];
  nprocessorsValues = new short[NumExps];
  nsmValues = new short[NumExps];
  nwarpsValues = new short[NumExps];
  register_count_indexValues = new short[NumExps];
  sim_endValues = new short[NumExps];
  sizeValues = new short[NumExps];

  // call methods to assign values to each gv
  SetValues_dram_size();
  SetValues_failure_index();
  SetValues_global_read_dram();
  SetValues_global_read_l1();
  SetValues_global_read_l2();
  SetValues_global_write_dram();
  SetValues_global_write_l1();
  SetValues_global_write_l2();
  SetValues_l1_size();
  SetValues_l2_size();
  SetValues_local_read_dram();
  SetValues_local_read_l1();
  SetValues_local_read_l2();
  SetValues_local_write_dram();
  SetValues_local_write_l1();
  SetValues_local_write_l2();
  SetValues_nfailedprocessors();
  SetValues_nfailedsm();
  SetValues_nfailedwarps();
  SetValues_nprocessors();
  SetValues_nsm();
  SetValues_nwarps();
  SetValues_register_count_index();
  SetValues_sim_end();
  SetValues_size();
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//GPU_STUDY_GEMM_64SetStudy Destructor
//******************************************************
GPU_STUDY_GEMM_64SetStudy::~GPU_STUDY_GEMM_64SetStudy() {
  delete [] dram_sizeValues;
  delete [] failure_indexValues;
  delete [] global_read_dramValues;
  delete [] global_read_l1Values;
  delete [] global_read_l2Values;
  delete [] global_write_dramValues;
  delete [] global_write_l1Values;
  delete [] global_write_l2Values;
  delete [] l1_sizeValues;
  delete [] l2_sizeValues;
  delete [] local_read_dramValues;
  delete [] local_read_l1Values;
  delete [] local_read_l2Values;
  delete [] local_write_dramValues;
  delete [] local_write_l1Values;
  delete [] local_write_l2Values;
  delete [] nfailedprocessorsValues;
  delete [] nfailedsmValues;
  delete [] nfailedwarpsValues;
  delete [] nprocessorsValues;
  delete [] nsmValues;
  delete [] nwarpsValues;
  delete [] register_count_indexValues;
  delete [] sim_endValues;
  delete [] sizeValues;
  delete ThePVModel;
}


//******************************************************
// set values for dram_size
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_dram_size() {
  dram_sizeValues[0] = 100;
}


//******************************************************
// set values for failure_index
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_failure_index() {
  failure_indexValues[0] = 10000;
}


//******************************************************
// set values for global_read_dram
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_global_read_dram() {
  global_read_dramValues[0] = 0;
}


//******************************************************
// set values for global_read_l1
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_global_read_l1() {
  global_read_l1Values[0] = 0.9;
}


//******************************************************
// set values for global_read_l2
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_global_read_l2() {
  global_read_l2Values[0] = 0.1;
}


//******************************************************
// set values for global_write_dram
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_global_write_dram() {
  global_write_dramValues[0] = 0;
}


//******************************************************
// set values for global_write_l1
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_global_write_l1() {
  global_write_l1Values[0] = 0;
}


//******************************************************
// set values for global_write_l2
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_global_write_l2() {
  global_write_l2Values[0] = 1.0;
}


//******************************************************
// set values for l1_size
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_l1_size() {
  l1_sizeValues[0] = 100;
}


//******************************************************
// set values for l2_size
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_l2_size() {
  l2_sizeValues[0] = 100;
}


//******************************************************
// set values for local_read_dram
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_local_read_dram() {
  local_read_dramValues[0] = 0;
}


//******************************************************
// set values for local_read_l1
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_local_read_l1() {
  local_read_l1Values[0] = 0;
}


//******************************************************
// set values for local_read_l2
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_local_read_l2() {
  local_read_l2Values[0] = 0;
}


//******************************************************
// set values for local_write_dram
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_local_write_dram() {
  local_write_dramValues[0] = 0;
}


//******************************************************
// set values for local_write_l1
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_local_write_l1() {
  local_write_l1Values[0] = 0;
}


//******************************************************
// set values for local_write_l2
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_local_write_l2() {
  local_write_l2Values[0] = 0;
}


//******************************************************
// set values for nfailedprocessors
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_nfailedprocessors() {
  nfailedprocessorsValues[0] = 0;
}


//******************************************************
// set values for nfailedsm
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_nfailedsm() {
  nfailedsmValues[0] = 0;
}


//******************************************************
// set values for nfailedwarps
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_nfailedwarps() {
  nfailedwarpsValues[0] = 0;
}


//******************************************************
// set values for nprocessors
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_nprocessors() {
  nprocessorsValues[0] = 4;
}


//******************************************************
// set values for nsm
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_nsm() {
  nsmValues[0] = 8;
}


//******************************************************
// set values for nwarps
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_nwarps() {
  nwarpsValues[0] = 1;
}


//******************************************************
// set values for register_count_index
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_register_count_index() {
  register_count_indexValues[0] = 0;
}


//******************************************************
// set values for sim_end
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_sim_end() {
  sim_endValues[0] = 100;
}


//******************************************************
// set values for size
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetValues_size() {
  sizeValues[0] = 224;
}



//******************************************************
//print values of gv (for debugging)
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::PrintGlobalValues(int expNum) {
  if (NumGVs == 0) {
    cout<<"There are no global variables."<<endl;
    return;
  }

  SetGVs(expNum);

  cout<<"The Global Variable values for experiment "<<
    GetExpName(expNum)<<" are:"<<endl;
  cout << "dram_size\tshort\t" << dram_size << endl;
  cout << "failure_index\tshort\t" << failure_index << endl;
  cout << "global_read_dram\tfloat\t" << global_read_dram << endl;
  cout << "global_read_l1\tfloat\t" << global_read_l1 << endl;
  cout << "global_read_l2\tfloat\t" << global_read_l2 << endl;
  cout << "global_write_dram\tfloat\t" << global_write_dram << endl;
  cout << "global_write_l1\tfloat\t" << global_write_l1 << endl;
  cout << "global_write_l2\tfloat\t" << global_write_l2 << endl;
  cout << "l1_size\tshort\t" << l1_size << endl;
  cout << "l2_size\tshort\t" << l2_size << endl;
  cout << "local_read_dram\tfloat\t" << local_read_dram << endl;
  cout << "local_read_l1\tfloat\t" << local_read_l1 << endl;
  cout << "local_read_l2\tfloat\t" << local_read_l2 << endl;
  cout << "local_write_dram\tfloat\t" << local_write_dram << endl;
  cout << "local_write_l1\tfloat\t" << local_write_l1 << endl;
  cout << "local_write_l2\tfloat\t" << local_write_l2 << endl;
  cout << "nfailedprocessors\tshort\t" << nfailedprocessors << endl;
  cout << "nfailedsm\tshort\t" << nfailedsm << endl;
  cout << "nfailedwarps\tshort\t" << nfailedwarps << endl;
  cout << "nprocessors\tshort\t" << nprocessors << endl;
  cout << "nsm\tshort\t" << nsm << endl;
  cout << "nwarps\tshort\t" << nwarps << endl;
  cout << "register_count_index\tshort\t" << register_count_index << endl;
  cout << "sim_end\tshort\t" << sim_end << endl;
  cout << "size\tshort\t" << size << endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *GPU_STUDY_GEMM_64SetStudy::GetGVValue(char *TheGVName) {
  if (strcmp("dram_size", TheGVName) == 0)
    return &dram_size;
  else if (strcmp("failure_index", TheGVName) == 0)
    return &failure_index;
  else if (strcmp("global_read_dram", TheGVName) == 0)
    return &global_read_dram;
  else if (strcmp("global_read_l1", TheGVName) == 0)
    return &global_read_l1;
  else if (strcmp("global_read_l2", TheGVName) == 0)
    return &global_read_l2;
  else if (strcmp("global_write_dram", TheGVName) == 0)
    return &global_write_dram;
  else if (strcmp("global_write_l1", TheGVName) == 0)
    return &global_write_l1;
  else if (strcmp("global_write_l2", TheGVName) == 0)
    return &global_write_l2;
  else if (strcmp("l1_size", TheGVName) == 0)
    return &l1_size;
  else if (strcmp("l2_size", TheGVName) == 0)
    return &l2_size;
  else if (strcmp("local_read_dram", TheGVName) == 0)
    return &local_read_dram;
  else if (strcmp("local_read_l1", TheGVName) == 0)
    return &local_read_l1;
  else if (strcmp("local_read_l2", TheGVName) == 0)
    return &local_read_l2;
  else if (strcmp("local_write_dram", TheGVName) == 0)
    return &local_write_dram;
  else if (strcmp("local_write_l1", TheGVName) == 0)
    return &local_write_l1;
  else if (strcmp("local_write_l2", TheGVName) == 0)
    return &local_write_l2;
  else if (strcmp("nfailedprocessors", TheGVName) == 0)
    return &nfailedprocessors;
  else if (strcmp("nfailedsm", TheGVName) == 0)
    return &nfailedsm;
  else if (strcmp("nfailedwarps", TheGVName) == 0)
    return &nfailedwarps;
  else if (strcmp("nprocessors", TheGVName) == 0)
    return &nprocessors;
  else if (strcmp("nsm", TheGVName) == 0)
    return &nsm;
  else if (strcmp("nwarps", TheGVName) == 0)
    return &nwarps;
  else if (strcmp("register_count_index", TheGVName) == 0)
    return &register_count_index;
  else if (strcmp("sim_end", TheGVName) == 0)
    return &sim_end;
  else if (strcmp("size", TheGVName) == 0)
    return &size;
  else 
    cerr<<"!! GPU_STUDY_GEMM_64SetStudy::GetGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
  return NULL;
}


//******************************************************
//override the value of a global variable
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::OverrideGVValue(char *TheGVName,void *TheGVValue) {
  if (strcmp("dram_size", TheGVName) == 0)
    SetGvValue(dram_size, *(short *)TheGVValue);
  else if (strcmp("failure_index", TheGVName) == 0)
    SetGvValue(failure_index, *(short *)TheGVValue);
  else if (strcmp("global_read_dram", TheGVName) == 0)
    SetGvValue(global_read_dram, *(float *)TheGVValue);
  else if (strcmp("global_read_l1", TheGVName) == 0)
    SetGvValue(global_read_l1, *(float *)TheGVValue);
  else if (strcmp("global_read_l2", TheGVName) == 0)
    SetGvValue(global_read_l2, *(float *)TheGVValue);
  else if (strcmp("global_write_dram", TheGVName) == 0)
    SetGvValue(global_write_dram, *(float *)TheGVValue);
  else if (strcmp("global_write_l1", TheGVName) == 0)
    SetGvValue(global_write_l1, *(float *)TheGVValue);
  else if (strcmp("global_write_l2", TheGVName) == 0)
    SetGvValue(global_write_l2, *(float *)TheGVValue);
  else if (strcmp("l1_size", TheGVName) == 0)
    SetGvValue(l1_size, *(short *)TheGVValue);
  else if (strcmp("l2_size", TheGVName) == 0)
    SetGvValue(l2_size, *(short *)TheGVValue);
  else if (strcmp("local_read_dram", TheGVName) == 0)
    SetGvValue(local_read_dram, *(float *)TheGVValue);
  else if (strcmp("local_read_l1", TheGVName) == 0)
    SetGvValue(local_read_l1, *(float *)TheGVValue);
  else if (strcmp("local_read_l2", TheGVName) == 0)
    SetGvValue(local_read_l2, *(float *)TheGVValue);
  else if (strcmp("local_write_dram", TheGVName) == 0)
    SetGvValue(local_write_dram, *(float *)TheGVValue);
  else if (strcmp("local_write_l1", TheGVName) == 0)
    SetGvValue(local_write_l1, *(float *)TheGVValue);
  else if (strcmp("local_write_l2", TheGVName) == 0)
    SetGvValue(local_write_l2, *(float *)TheGVValue);
  else if (strcmp("nfailedprocessors", TheGVName) == 0)
    SetGvValue(nfailedprocessors, *(short *)TheGVValue);
  else if (strcmp("nfailedsm", TheGVName) == 0)
    SetGvValue(nfailedsm, *(short *)TheGVValue);
  else if (strcmp("nfailedwarps", TheGVName) == 0)
    SetGvValue(nfailedwarps, *(short *)TheGVValue);
  else if (strcmp("nprocessors", TheGVName) == 0)
    SetGvValue(nprocessors, *(short *)TheGVValue);
  else if (strcmp("nsm", TheGVName) == 0)
    SetGvValue(nsm, *(short *)TheGVValue);
  else if (strcmp("nwarps", TheGVName) == 0)
    SetGvValue(nwarps, *(short *)TheGVValue);
  else if (strcmp("register_count_index", TheGVName) == 0)
    SetGvValue(register_count_index, *(short *)TheGVValue);
  else if (strcmp("sim_end", TheGVName) == 0)
    SetGvValue(sim_end, *(short *)TheGVValue);
  else if (strcmp("size", TheGVName) == 0)
    SetGvValue(size, *(short *)TheGVValue);
  else 
    cerr<<"!! GPU_STUDY_GEMM_64SetStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void GPU_STUDY_GEMM_64SetStudy::SetGVs(int expNum) {
  SetGvValue(dram_size, dram_sizeValues[expNum]);
  SetGvValue(failure_index, failure_indexValues[expNum]);
  SetGvValue(global_read_dram, global_read_dramValues[expNum]);
  SetGvValue(global_read_l1, global_read_l1Values[expNum]);
  SetGvValue(global_read_l2, global_read_l2Values[expNum]);
  SetGvValue(global_write_dram, global_write_dramValues[expNum]);
  SetGvValue(global_write_l1, global_write_l1Values[expNum]);
  SetGvValue(global_write_l2, global_write_l2Values[expNum]);
  SetGvValue(l1_size, l1_sizeValues[expNum]);
  SetGvValue(l2_size, l2_sizeValues[expNum]);
  SetGvValue(local_read_dram, local_read_dramValues[expNum]);
  SetGvValue(local_read_l1, local_read_l1Values[expNum]);
  SetGvValue(local_read_l2, local_read_l2Values[expNum]);
  SetGvValue(local_write_dram, local_write_dramValues[expNum]);
  SetGvValue(local_write_l1, local_write_l1Values[expNum]);
  SetGvValue(local_write_l2, local_write_l2Values[expNum]);
  SetGvValue(nfailedprocessors, nfailedprocessorsValues[expNum]);
  SetGvValue(nfailedsm, nfailedsmValues[expNum]);
  SetGvValue(nfailedwarps, nfailedwarpsValues[expNum]);
  SetGvValue(nprocessors, nprocessorsValues[expNum]);
  SetGvValue(nsm, nsmValues[expNum]);
  SetGvValue(nwarps, nwarpsValues[expNum]);
  SetGvValue(register_count_index, register_count_indexValues[expNum]);
  SetGvValue(sim_end, sim_endValues[expNum]);
  SetGvValue(size, sizeValues[expNum]);
}


//******************************************************
//static class method called by solvers to create study 
//(and thus create all of the model)
//******************************************************
BaseStudyClass* GlobalStudyPtr = NULL;
BaseStudyClass * GenerateStudy() {
  if (GlobalStudyPtr == NULL)
    GlobalStudyPtr = new GPU_STUDY_GEMM_64SetStudy();
  return GlobalStudyPtr;
}

void DestructStudy() {
  delete GlobalStudyPtr;
  GlobalStudyPtr = NULL;
}
//******************************************************
//get and create the PVModel
//******************************************************
PVModel* GPU_STUDY_GEMM_64SetStudy::GetPVModel(bool expandTimeArrays) {
  if (ThePVModel!=NULL)
    delete ThePVModel;
  // create the PV model
  ThePVModel=new GPU5PVModel(expandTimeArrays);
  return ThePVModel;
}


