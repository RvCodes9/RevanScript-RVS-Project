#ifndef RVSBUF_H
#define RVSBUF_H

#include <stddef.h>

// RevanScript Buffer Variable Standard Define
#define RVS_BUFFER_VARIABLE_NAME_LENGHT 2048
#define RVS_BUFFER_VARIABLE_DATA_LENGHT 2048
#define RVS_BUFFER_VARIABLE_TYPE_LENGHT 5


// RevanScript Buffer Type
typedef struct{
    char* variable_name;
    char* variable_data;
    char* variable_type;
    size_t variable_name_counter;
    size_t variable_data_counter;
} RVSBUF;


RVSBUF* rvs_buffer_create(void);
void rvs_buffer_delete(RVSBUF*);

#endif