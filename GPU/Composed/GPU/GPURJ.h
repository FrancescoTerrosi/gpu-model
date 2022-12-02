#ifndef GPURJ_H_
#define GPURJ_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Atomic/COMPUTE_UNIT/COMPUTE_UNITSAN.h"
#include "Atomic/TOTAL_MEMORY_MODEL/TOTAL_MEMORY_MODELSAN.h"
#include "Atomic/OUTPUT_MEMORY_MODEL/OUTPUT_MEMORY_MODELSAN.h"
#include "Atomic/RESULT_MEMORY_MODEL/RESULT_MEMORY_MODELSAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short size;

class GPURJ: public Join {
 public:
  COMPUTE_UNITSAN * COMPUTE_UNIT;
  TOTAL_MEMORY_MODELSAN * TOTAL_MEMORY;
  OUTPUT_MEMORY_MODELSAN * OUTPUT_MEMORY;
  RESULT_MEMORY_MODELSAN * RESULT_MEMORY;
  Place * KO_READ;
  Place * MEM_OP_COMPLETE;
  Place * OK_READ;
  Place * READ_RESULT_MEMORY;
  Place * READ_TOTAL_MEMORY;
  Place * RESULT_KO;
  Place * RESULT_OK;
  Place * WRITE_OUTPUT_MEMORY;
  Place * WRITE_RESULT_MEMORY;

  GPURJ();
  ~GPURJ();
};

#endif
