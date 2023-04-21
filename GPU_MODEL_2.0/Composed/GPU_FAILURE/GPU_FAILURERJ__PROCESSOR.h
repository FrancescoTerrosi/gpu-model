#ifndef GPU_FAILURERJ__PROCESSOR_H_
#define GPU_FAILURERJ__PROCESSOR_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Composed/GPU_FAILURE/GPU_FAILURERJ__Rep1.h"
#include "Atomic/EXEC_UNIT/EXEC_UNITSAN.h"
#include "Atomic/MEMORY/MEMORYSAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;
extern Short nsm;
extern Short nfailedprocessors;
extern Short nfailedsm;
extern Short nfailedwarps;

class GPU_FAILURERJ__PROCESSOR: public Join {
 public:
  GPU_FAILURERJ__Rep1 * Rep1;
  EXEC_UNITSAN * EXEC_UNIT;
  MEMORYSAN * MEMORY;
  Place * FLOAT_ALU_FAILURE;
  Place * INSTRUCTION_READY;
  Place * INT_ALU_FAILURE;
  Place * KO_CONTENT;
  Place * MEM_FAILURE;
  Place * MEM_OP_COMPLETE;
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

  GPU_FAILURERJ__PROCESSOR();
  ~GPU_FAILURERJ__PROCESSOR();
};

#endif
