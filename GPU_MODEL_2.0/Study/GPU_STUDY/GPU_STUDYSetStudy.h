
#ifndef GPU_STUDYSetSTUDY_H_
#define GPU_STUDYSetSTUDY_H_

#include "Reward/GPU4/GPU4PVNodes.h"
#include "Reward/GPU4/GPU4PVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Float dram_global_read_prob;
extern Float dram_global_write_prob;
extern Float dram_local_read_prob;
extern Float dram_local_write_prob;
extern Short end;
extern Float l1_global_read_prob;
extern Float l1_global_write_prob;
extern Float l1_local_read_prob;
extern Float l1_local_write_prob;
extern Float l2_global_read_prob;
extern Float l2_global_write_prob;
extern Float l2_local_read_prob;
extern Float l2_local_write_prob;
extern Short nprocessors;
extern Short nwarps;
extern Short register_count_index;
extern Short size;

class GPU_STUDYSetStudy : public BaseStudyClass {
public:

GPU_STUDYSetStudy();
~GPU_STUDYSetStudy();

private:

float *dram_global_read_probValues;
float *dram_global_write_probValues;
float *dram_local_read_probValues;
float *dram_local_write_probValues;
short *endValues;
float *l1_global_read_probValues;
float *l1_global_write_probValues;
float *l1_local_read_probValues;
float *l1_local_write_probValues;
float *l2_global_read_probValues;
float *l2_global_write_probValues;
float *l2_local_read_probValues;
float *l2_local_write_probValues;
short *nprocessorsValues;
short *nwarpsValues;
short *register_count_indexValues;
short *sizeValues;

void SetValues_dram_global_read_prob();
void SetValues_dram_global_write_prob();
void SetValues_dram_local_read_prob();
void SetValues_dram_local_write_prob();
void SetValues_end();
void SetValues_l1_global_read_prob();
void SetValues_l1_global_write_prob();
void SetValues_l1_local_read_prob();
void SetValues_l1_local_write_prob();
void SetValues_l2_global_read_prob();
void SetValues_l2_global_write_prob();
void SetValues_l2_local_read_prob();
void SetValues_l2_local_write_prob();
void SetValues_nprocessors();
void SetValues_nwarps();
void SetValues_register_count_index();
void SetValues_size();

void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif

