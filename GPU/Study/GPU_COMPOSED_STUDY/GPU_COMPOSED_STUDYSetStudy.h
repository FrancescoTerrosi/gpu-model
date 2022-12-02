
#ifndef GPU_COMPOSED_STUDYSetSTUDY_H_
#define GPU_COMPOSED_STUDYSetSTUDY_H_

#include "Reward/GPU_COMPOSED_REWARD/GPU_COMPOSED_REWARDPVNodes.h"
#include "Reward/GPU_COMPOSED_REWARD/GPU_COMPOSED_REWARDPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Short size;

class GPU_COMPOSED_STUDYSetStudy : public BaseStudyClass {
public:

GPU_COMPOSED_STUDYSetStudy();
~GPU_COMPOSED_STUDYSetStudy();

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

