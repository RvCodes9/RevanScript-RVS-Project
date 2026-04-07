#ifndef RVSMEM_H
#define RVSMEM_H


// RevanScript Memory Standard Define
#define RVS_MEMORY_DEFAULT_SIZE 1000


// RevanScript Memory Variable Standard Define
#define RVS_MEMORY_VARIABLE_NAME_LENGHT 31
#define RVS_MEMORY_VARIABLE_DATA_LENGHT 2048
#define RVS_MEMORY_VARIABLE_TYPE_LENGHT 4


// RevanScript Memory Type
typedef struct{
    char** variable_names;
    char** variable_datas;
    char** variable_types;
    size_t variable_iter;
} RVSMEM;


RVSMEM* rvs_memory_create(void);
void rvs_memory_delete(RVSMEM*);

#endif