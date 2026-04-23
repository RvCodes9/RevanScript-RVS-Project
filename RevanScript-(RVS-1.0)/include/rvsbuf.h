#ifndef RVSBUF_H
#define RVSBUF_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>


// RevanScript Buffer Variable Standard Define
#define RVS_BUFFER_VARIABLE_NAME_LENGHT 2048
#define RVS_BUFFER_VARIABLE_DATA_LENGHT 2048
#define RVS_BUFFER_VARIABLE_TYPE_LENGHT 5


// RevanScript Main Data Types
enum{
    RVS_UNDEFINED_TYPE = 0,
    RVS_STRING_TYPE,
    RVS_INTEGER_TYPE,
    RVS_FLOAT_TYPE,
    RVS_BOOLEAN_TYPE,
    RVS_BINARY_TYPE,
    RVS_NULL_TYPE
};


// RevanScript Buffer Type
typedef struct{
    char* variable_name;
    char* variable_data;
    uint8_t variable_type;
    bool variable_const;
    size_t variable_name_counter;
    size_t variable_data_counter;
} RVSBUF;


RVSBUF* rvs_buffer_create(void);
void rvs_buffer_delete(RVSBUF*);

#endif