#ifndef GPU5RJ__PROCESSOR_FAILURE_H_
#define GPU5RJ__PROCESSOR_FAILURE_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Atomic/EXEC_UNIT/EXEC_UNITSAN.h"
#include "Atomic/MEMORY/MEMORYSAN.h"
#include "Composed/GPU5/GPU5RJ__Rep2.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;
extern Short nsm;
extern Short nfailedprocessors;
extern Short nfailedsm;
extern Short nfailedwarps;

class GPU5RJ__PROCESSOR_FAILURE: public Join {
 public:
  EXEC_UNITSAN * EXEC_UNIT_FAILURE;
  MEMORYSAN * MEMORY_FAILURE;
  GPU5RJ__Rep2 * Rep2;
  Place * FLOAT_ALU_FAILURE;
  Place * INSTRUCTION_READY;
  Place * INT_ALU_FAILURE;
  Place * KO_CONTENT;
  Place * MEM_FAILURE;
  Place * OK_CONTENT;
  Place * READ;
  Place * READ_DRAM;
  Place * READ_L1;
  Place * READ_L2;
  Place * REGISTERS_FILL;
  Place * RESULT_KO;
  Place * RESULT_OK;
  Place * SCHEDULER;
  Place * WARP_ACCESS_DRAM;
  Place * WARP_ACCESS_L1;
  Place * WARP_ACCESS_L2;
  Place * WRITE;
  Place * WRITE_DRAM;
  Place * WRITE_L1;
  Place * WRITE_L2;

  GPU5RJ__PROCESSOR_FAILURE();
  ~GPU5RJ__PROCESSOR_FAILURE();
};

#endif
