
#ifndef GPUS_STUDYSetSTUDY_H_
#define GPUS_STUDYSetSTUDY_H_

#include "Reward/GPU_REWARD/GPU_REWARDPVNodes.h"
#include "Reward/GPU_REWARD/GPU_REWARDPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Short size;

class GPUS_STUDYSetStudy : public BaseStudyClass {
public:

GPUS_STUDYSetStudy();
~GPUS_STUDYSetStudy();

private:

short *sizeValues;

void SetValues_size();

void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif

