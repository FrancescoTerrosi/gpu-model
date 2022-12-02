
#ifndef GPU_STUDYSetSTUDY_H_
#define GPU_STUDYSetSTUDY_H_

#include "Reward/GPU_REWARD/GPU_REWARDPVNodes.h"
#include "Reward/GPU_REWARD/GPU_REWARDPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Float dram_result_read_prob;
extern Float dram_result_write_prob;
extern Float dram_total_read_prob;
extern Short end;
extern Float l1_result_read_prob;
extern Float l1_result_write_prob;
extern Float l2_result_read_prob;
extern Float l2_result_write_prob;
extern Float l2_total_read_prob;
extern Short size;

class GPU_STUDYSetStudy : public BaseStudyClass {
public:

GPU_STUDYSetStudy();
~GPU_STUDYSetStudy();

private:

float *dram_result_read_probValues;
float *dram_result_write_probValues;
float *dram_total_read_probValues;
short *endValues;
float *l1_result_read_probValues;
float *l1_result_write_probValues;
float *l2_result_read_probValues;
float *l2_result_write_probValues;
float *l2_total_read_probValues;
short *sizeValues;

void SetValues_dram_result_read_prob();
void SetValues_dram_result_write_prob();
void SetValues_dram_total_read_prob();
void SetValues_end();
void SetValues_l1_result_read_prob();
void SetValues_l1_result_write_prob();
void SetValues_l2_result_read_prob();
void SetValues_l2_result_write_prob();
void SetValues_l2_total_read_prob();
void SetValues_size();

void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif

