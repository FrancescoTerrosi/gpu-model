#ifndef GPU4.BKPRJ__PROCESSOR_H_
#define GPU4.BKPRJ__PROCESSOR_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Composed/GPU4.BKP/GPU4.BKPRJ__Rep1.h"
#include "Atomic/COMPUTE_UNIT/COMPUTE_UNITSAN.h"
#include "Atomic/LOCAL_MEMORY/LOCAL_MEMORYSAN.h"
#include "Atomic/GLOBAL_MEMORY/GLOBAL_MEMORYSAN.h"
#include "Atomic/REGISTER_FILE/REGISTER_FILESAN.h"
#include "Atomic/OUTPUT_MEMORY/OUTPUT_MEMORYSAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"

class GPU4.BKPRJ__PROCESSOR: public Join {
 public:
  GPU4.BKPRJ__Rep1 * Rep1;
  COMPUTE_UNITSAN * COMPUTE_UNIT;
  LOCAL_MEMORYSAN * LOCAL_MEMORY;
  GLOBAL_MEMORYSAN * GLOBAL_MEMORY;
  REGISTER_FILESAN * REGISTER_FILE;
  OUTPUT_MEMORYSAN * OUTPUT_MEMORY;
  Place * INSTRUCTION_READY;
  Place * KO_READ;
  Place * MEM_OP_COMPLETE;
  Place * OK_READ;
  Place * READ_DRAM;
  Place * READ_GLOBAL_MEMORY;
  Place * READ_L1;
  Place * READ_L2;
  Place * READ_LOCAL_MEMORY;
  Place * READ_REGISTER_FILE;
  Place * RESULT_KO;
  Place * RESULT_OK;
  Place * SCHEDULER;
  Place * WRITE_DRAM;
  Place * WRITE_GLOBAL_MEMORY;
  Place * WRITE_L1;
  Place * WRITE_L2;
  Place * WRITE_LOCAL_MEMORY;
  Place * WRITE_OUTPUT_MEMORY;
  Place * WRITE_REGISTER_FILE;

  GPU4.BKPRJ__PROCESSOR();
  ~GPU4.BKPRJ__PROCESSOR();
};

#endif
