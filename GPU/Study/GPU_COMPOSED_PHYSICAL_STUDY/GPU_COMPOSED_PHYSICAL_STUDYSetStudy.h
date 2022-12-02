
#ifndef GPU_COMPOSED_PHYSICAL_STUDYSetSTUDY_H_
#define GPU_COMPOSED_PHYSICAL_STUDYSetSTUDY_H_

#include "Reward/GPU_COMPOSED_PHYSICAL_REWARD/GPU_COMPOSED_PHYSICAL_REWARDPVNodes.h"
#include "Reward/GPU_COMPOSED_PHYSICAL_REWARD/GPU_COMPOSED_PHYSICAL_REWARDPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Float dram_result_read_rate;
extern Float dram_result_write_rate;
extern Float dram_total_read_rate;
extern Float l1_result_read_rate;
extern Float l1_result_write_rate;
extern Float l2_result_read_rate;
extern Float l2_result_write_rate;
extern Float l2_total_read_rate;
extern Short size;

class GPU_COMPOSED_PHYSICAL_STUDYSetStudy : public BaseStudyClass {
public:

GPU_COMPOSED_PHYSICAL_STUDYSetStudy();
~GPU_COMPOSED_PHYSICAL_STUDYSetStudy();

private:

float *dram_result_read_rateValues;
float *dram_result_write_rateValues;
float *dram_total_read_rateValues;
float *l1_result_read_rateValues;
float *l1_result_write_rateValues;
float *l2_result_read_rateValues;
float *l2_result_write_rateValues;
float *l2_total_read_rateValues;
short *sizeValues;

void SetValues_dram_result_read_rate();
void SetValues_dram_result_write_rate();
void SetValues_dram_total_read_rate();
void SetValues_l1_result_read_rate();
void SetValues_l1_result_write_rate();
void SetValues_l2_result_read_rate();
void SetValues_l2_result_write_rate();
void SetValues_l2_total_read_rate();
void SetValues_size();

void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif

