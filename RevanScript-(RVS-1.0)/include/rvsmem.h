#ifndef RVSMEM_H
#define RVSMEM_H

#include <stdbool.h>

#include "rvsbuf.h"


// RevanScript (RVS) Memory Debugger Mode Define
#define RVS_MEMORY_DEBUGGER_MODE false

// RevanScript Memory Standard Define
#define RVS_MEMORY_DEFAULT_SIZE 1000

// RevanScript Memory Variable Standard Define
#define RVS_MEMORY_VARIABLE_NAME_LENGTH 31
#define RVS_MEMORY_VARIABLE_DATA_LENGTH 2048
#define RVS_MEMORY_VARIABLE_TYPE_LENGTH 5


// RevanScript Memory Type
typedef struct{
    char** variable_names;
    char** variable_datas;
    char** variable_types;
    bool* variable_consts;
    bool* variable_ctrls;
    size_t variable_iter;
    size_t memory_size;
} RVSMEM;


// RevanScript (RVS) Memory Functions
RVSMEM* rvs_memory_create(void);
bool rvs_memory_insert(RVSMEM*, const RVSBUF*);
bool rvs_memory_check(const RVSMEM*, const RVSBUF*);
char* rvs_memory_get(const RVSMEM*, const RVSBUF*);
bool rvs_memory_set(RVSMEM* rvs_memory, const RVSBUF* const rvs_buffer);
bool rvs_memory_cst(RVSMEM*, const RVSBUF*);
bool rvs_memory_clear(RVSMEM*, const RVSBUF*);
void rvs_memory_delete(RVSMEM*);


#endif