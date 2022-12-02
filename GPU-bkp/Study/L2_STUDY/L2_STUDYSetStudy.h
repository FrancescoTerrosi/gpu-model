
#ifndef L2_STUDYSetSTUDY_H_
#define L2_STUDYSetSTUDY_H_

#include "Reward/L2_REWARD/L2_REWARDPVNodes.h"
#include "Reward/L2_REWARD/L2_REWARDPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"


class L2_STUDYSetStudy : public BaseStudyClass {
public:

L2_STUDYSetStudy();
~L2_STUDYSetStudy();

private:



void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif

