
#ifndef GPU_STUDY_GEMM_64SetSTUDY_H_
#define GPU_STUDY_GEMM_64SetSTUDY_H_

#include "Reward/GPU5/GPU5PVNodes.h"
#include "Reward/GPU5/GPU5PVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Short dram_size;
extern Short failure_index;
extern Float global_read_dram;
extern Float global_read_l1;
extern Float global_read_l2;
extern Float global_write_dram;
extern Float global_write_l1;
extern Float global_write_l2;
extern Short l1_size;
extern Short l2_size;
extern Float local_read_dram;
extern Float local_read_l1;
extern Float local_read_l2;
extern Float local_write_dram;
extern Float local_write_l1;
extern Float local_write_l2;
extern Short nfailedprocessors;
extern Short nfailedsm;
extern Short nfailedwarps;
extern Short nprocessors;
extern Short nsm;
extern Short nwarps;
extern Short register_count_index;
extern Short sim_end;
extern Short size;

class GPU_STUDY_GEMM_64SetStudy : public BaseStudyClass {
public:

GPU_STUDY_GEMM_64SetStudy();
~GPU_STUDY_GEMM_64SetStudy();

private:

short *dram_sizeValues;
short *failure_indexValues;
float *global_read_dramValues;
float *global_read_l1Values;
float *global_read_l2Values;
float *global_write_dramValues;
float *global_write_l1Values;
float *global_write_l2Values;
short *l1_sizeValues;
short *l2_sizeValues;
float *local_read_dramValues;
float *local_read_l1Values;
float *local_read_l2Values;
float *local_write_dramValues;
float *local_write_l1Values;
float *local_write_l2Values;
short *nfailedprocessorsValues;
short *nfailedsmValues;
short *nfailedwarpsValues;
short *nprocessorsValues;
short *nsmValues;
short *nwarpsValues;
short *register_count_indexValues;
short *sim_endValues;
short *sizeValues;

void SetValues_dram_size();
void SetValues_failure_index();
void SetValues_global_read_dram();
void SetValues_global_read_l1();
void SetValues_global_read_l2();
void SetValues_global_write_dram();
void SetValues_global_write_l1();
void SetValues_global_write_l2();
void SetValues_l1_size();
void SetValues_l2_size();
void SetValues_local_read_dram();
void SetValues_local_read_l1();
void SetValues_local_read_l2();
void SetValues_local_write_dram();
void SetValues_local_write_l1();
void SetValues_local_write_l2();
void SetValues_nfailedprocessors();
void SetValues_nfailedsm();
void SetValues_nfailedwarps();
void SetValues_nprocessors();
void SetValues_nsm();
void SetValues_nwarps();
void SetValues_register_count_index();
void SetValues_sim_end();
void SetValues_size();

void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif

