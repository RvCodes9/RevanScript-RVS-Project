#include <stdlib.h>
#include <stddef.h>

#include "rvsmem.h"


RVSMEM* rvs_memory_create(void){
    RVSMEM* rvs_memory = (RVSMEM*) malloc(sizeof(RVSMEM));
    if (!rvs_memory) return NULL;

    rvs_memory->variable_names = (char**) malloc(sizeof(char*) * RVS_MEMORY_DEFAULT_SIZE);
    if (!rvs_memory->variable_names){
        free(rvs_memory);
        return NULL;
    }

    rvs_memory->variable_datas = (char**) malloc(sizeof(char*) * RVS_MEMORY_DEFAULT_SIZE);
    if (!rvs_memory->variable_datas){
        free(rvs_memory->variable_names);
        free(rvs_memory);
        return NULL;
    }

    rvs_memory->variable_types = (char**) malloc(sizeof(char*) * RVS_MEMORY_DEFAULT_SIZE);
    if (!rvs_memory->variable_types){
        free(rvs_memory->variable_names);
        free(rvs_memory->variable_datas);
        free(rvs_memory);
        return NULL;
    }

    for (size_t i = 0; i < RVS_MEMORY_DEFAULT_SIZE; i++){
        rvs_memory->variable_names[i] = (char*) malloc(sizeof(char) * RVS_MEMORY_VARIABLE_NAME_LENGHT);
        if (!rvs_memory->variable_names[i]){
            for (size_t j = 0; j < i; j++){
                free(rvs_memory->variable_names[j]);
            }
            free(rvs_memory->variable_names);
            free(rvs_memory->variable_datas);
            free(rvs_memory->variable_types);
            free(rvs_memory);
            return NULL;
        }
        rvs_memory->variable_names[i][0] = '\0';
    }

    for (size_t i = 0; i < RVS_MEMORY_DEFAULT_SIZE; i++){
        rvs_memory->variable_datas[i] = (char*) malloc(sizeof(char) * RVS_MEMORY_VARIABLE_DATA_LENGHT);
        if (!rvs_memory->variable_datas[i]){
            for (size_t j = 0; j < RVS_MEMORY_DEFAULT_SIZE; j++){
                free(rvs_memory->variable_names[j]);
            }
            for (size_t j = 0; j < i; j++){
                free(rvs_memory->variable_datas[j]);
            }
            free(rvs_memory->variable_names);
            free(rvs_memory->variable_datas);
            free(rvs_memory->variable_types);
            free(rvs_memory);
            return NULL;
        }
        rvs_memory->variable_datas[i][0] = '\0';
    }

    for (size_t i = 0; i < RVS_MEMORY_DEFAULT_SIZE; i++){
        rvs_memory->variable_types[i] = (char*) malloc(sizeof(char) * RVS_MEMORY_VARIABLE_TYPE_LENGHT);
        if (!rvs_memory->variable_types[i]){
            for (size_t j = 0; j < RVS_MEMORY_DEFAULT_SIZE; j++){
                free(rvs_memory->variable_names[j]);
                free(rvs_memory->variable_datas[j]);
            }
            for (size_t j = 0; j < i; j++){
                free(rvs_memory->variable_types[j]);
            }
            free(rvs_memory->variable_names);
            free(rvs_memory->variable_datas);
            free(rvs_memory->variable_types);
            free(rvs_memory);
            return NULL;
        }
        rvs_memory->variable_types[i][0] = '\0';
    }

    rvs_memory->variable_iter = 0;
    return rvs_memory;
}


void rvs_memory_delete(RVSMEM* memory){
    for (size_t i = 0; i < RVS_MEMORY_DEFAULT_SIZE; i++){
        free(memory->variable_names[i]);
        free(memory->variable_datas[i]);
        free(memory->variable_types[i]);
    }
    free(memory->variable_names);
    free(memory->variable_datas);
    free(memory->variable_types);
    free(memory);
}