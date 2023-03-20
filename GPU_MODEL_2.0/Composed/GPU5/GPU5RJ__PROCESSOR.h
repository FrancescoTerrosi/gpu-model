#ifndef GPU5RJ__PROCESSOR_H_
#define GPU5RJ__PROCESSOR_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Composed/GPU5/GPU5RJ__Rep1.h"
#include "Atomic/REGISTER_FILE/REGISTER_FILESAN.h"
#include "Atomic/EXEC_UNIT/EXEC_UNITSAN.h"
#include "Atomic/MEMORY/MEMORYSAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"
extern Short nwarps;
extern Short nprocessors;

class GPU5RJ__PROCESSOR: public Join {
 public:
  GPU5RJ__Rep1 * Rep1;
  REGISTER_FILESAN * REGISTER_FILE;
  EXEC_UNITSAN * EXEC_UNIT;
  MEMORYSAN * MEMORY;
  Place * INSTRUCTION_READY;
  Place * MEM_OP_COMPLETE;
  Place * READ;
  Place * READ_DRAM;
  Place * READ_L1;
  Place * READ_L2;
  Place * READ_REGISTER_FILE;
  Place * REGISTERS_FILL;
  Place * REG_KO_CONTENT;
  Place * REG_OK_CONTENT;
  Place * RESULT_KO;
  Place * RESULT_OK;
  Place * SCHEDULER;
  Place * WRITE;
  Place * WRITE_DRAM;
  Place * WRITE_L1;
  Place * WRITE_L2;
  Place * WRITE_REGISTER_FILE;

  GPU5RJ__PROCESSOR();
  ~GPU5RJ__PROCESSOR();
};

#endif
