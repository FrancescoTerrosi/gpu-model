#ifndef GPU4.BKPRJ_H_
#define GPU4.BKPRJ_H_
#include <math.h>
#include "Cpp/Composer/Join.h"
#include "Cpp/Composer/AllStateVariableTypes.h"
#include "Composed/GPU4.BKP/GPU4.BKPRJ__STREAMING_MULTIPROCESSOR.h"
#include "Atomic/DRAM/DRAMSAN.h"
#include "Atomic/L2_CACHE/L2_CACHESAN.h"

//State variable headers
#include "Cpp/BaseClasses/SAN/Place.h"

class GPU4.BKPRJ: public Join {
 public:
  GPU4.BKPRJ__STREAMING_MULTIPROCESSOR * STREAMING_MULTIPROCESSOR;
  DRAMSAN * DRAM;
  L2_CACHESAN * L2_CACHE;
  Place * KO_READ;
  Place * MEM_OP_COMPLETE;
  Place * OK_READ;
  Place * READ_DRAM;
  Place * READ_L2;
  Place * RESULT_KO;
  Place * RESULT_OK;
  Place * WRITE_DRAM;
  Place * WRITE_L2;

  GPU4.BKPRJ();
  ~GPU4.BKPRJ();
};

#endif
