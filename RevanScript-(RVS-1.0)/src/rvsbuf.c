#include <stdlib.h>
#include <stdbool.h>

#include "../include/rvsbuf.h"


RVSBUF* rvs_buffer_create(void){
    RVSBUF* rvs_buffer = (RVSBUF*) malloc(sizeof(RVSBUF));
    if (!rvs_buffer) return NULL;

    rvs_buffer->variable_name = (char*) malloc(sizeof(char) * RVS_BUFFER_VARIABLE_NAME_LENGHT);
    if (!rvs_buffer->variable_name){
        free(rvs_buffer);
        return NULL;
    }

    rvs_buffer->variable_data = (char*) malloc(sizeof(char) * RVS_BUFFER_VARIABLE_DATA_LENGHT);
    if (!rvs_buffer->variable_data){
        free(rvs_buffer->variable_name);
        free(rvs_buffer);
        return NULL;
    }

    rvs_buffer->variable_type = (char*) malloc(sizeof(char) * RVS_BUFFER_VARIABLE_TYPE_LENGHT);
    if (!rvs_buffer->variable_type){
        free(rvs_buffer->variable_name);
        free(rvs_buffer->variable_data);
        free(rvs_buffer);
        return NULL;
    }

    rvs_buffer->variable_name[0] = '\0';
    rvs_buffer->variable_data[0] = '\0';
    rvs_buffer->variable_type[0] = '\0';

    rvs_buffer->variable_const = false;
    rvs_buffer->variable_name_counter = 0;
    rvs_buffer->variable_data_counter = 0;

    return rvs_buffer;
}


void rvs_buffer_delete(RVSBUF* buffer){
    free(buffer->variable_name);
    free(buffer->variable_data);
    free(buffer->variable_type);
    free(buffer);
}