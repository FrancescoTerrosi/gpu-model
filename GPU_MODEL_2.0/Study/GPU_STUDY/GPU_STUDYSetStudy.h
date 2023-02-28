
#ifndef GPU_STUDYSetSTUDY_H_
#define GPU_STUDYSetSTUDY_H_

#include "Reward/GPU5/GPU5PVNodes.h"
#include "Reward/GPU5/GPU5PVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Short end;
extern Short nprocessors;
extern Short nwarps;
extern Short register_count_index;
extern Short size;

class GPU_STUDYSetStudy : public BaseStudyClass {
public:

GPU_STUDYSetStudy();
~GPU_STUDYSetStudy();

private:

short *endValues;
short *nprocessorsValues;
short *nwarpsValues;
short *register_count_indexValues;
short *sizeValues;

void SetValues_end();
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

