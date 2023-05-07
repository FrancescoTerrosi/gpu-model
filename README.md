Il problema di gemm512 potrebbe essere anche dato dal fatto che ogni thread fa 512 iterazioni ma essendo tutti i dati contigui, può darsi che alla prima load si scarichi un bel po' di elementi.

Il codice SASS viene generato con 16 iterazioni * 32 iterazioni (16*32 = 512)


# gpu-model

<h1>MOBIUS GPU</h1>

<h2>Atomic</h2>

EXEC_UNIT

MEMORY

DRAM

L2_CACHE

L1_CACHE

REGISTER_FILE

WARP

<h2>Composed</h2>

GPU5

<h2>Reward</h2>

GPU5

<h2>Study</h2>

GPU_STUDY

<h2>Solver</h2>

GPU_SOLVER
