// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

// RevanScript (RVS) Core / Engine Libraries
#include "../include/rvsio.h"
#include "../include/rvserr.h"
#include "../include/rvsbuf.h"
#include "../include/rvsmem.h"


// RevanScript (RVS) Memory (RVSMEM) Realloc Function
bool _rvs_memory_realloc(RVSMEM* rvs_memory){
    size_t rvs_new_memory_size = rvs_memory->memory_size * 2;

    // Reallocate Memory
    bool* variables_ctrls = (bool*) realloc(rvs_memory->variable_ctrls, sizeof(bool) * rvs_new_memory_size);
    if (!variables_ctrls){
        if (RVS_MEMORY_DEBUGGER_MODE == true){
            rvs_standard_debug(false, "Memory Realloc.");
        }
        return false;
    }

    char** variables_names = (char**) realloc(rvs_memory->variable_names, sizeof(char*) * rvs_new_memory_size);
    if (!variables_names){
        if (RVS_MEMORY_DEBUGGER_MODE == true){
            rvs_standard_debug(false, "Memory Realloc.");
        }
        return false;
    }

    char** variables_datas = (char**) realloc(rvs_memory->variable_datas, sizeof(char*) * rvs_new_memory_size);
    if (!variables_datas){
        if (RVS_MEMORY_DEBUGGER_MODE == true){
            rvs_standard_debug(false, "Memory Realloc.");
        }
        return false;
    }

    char** variables_types = (char**) realloc(rvs_memory->variable_types, sizeof(char*) * rvs_new_memory_size);
    if (!variables_types){
        if (RVS_MEMORY_DEBUGGER_MODE == true){
            rvs_standard_debug(false, "Memory Realloc.");
        }
        return false;
    }

    bool* variables_consts = (bool*) realloc(rvs_memory->variable_consts, sizeof(bool) * rvs_new_memory_size);
    if (!variables_consts){
        if (RVS_MEMORY_DEBUGGER_MODE == true){
            rvs_standard_debug(false, "Memory Realloc.");
        }
        return false;
    }

    // Allocate Memory
    for (size_t i = rvs_memory->memory_size; i < rvs_new_memory_size; i++){

        // Variable Name
        variables_names[i] = (char*) malloc(sizeof(char) * RVS_MEMORY_VARIABLE_NAME_LENGTH);
        if (!variables_names[i]){
            for (size_t j = rvs_memory->memory_size; j < i; j++){
                free(variables_names[j]);
                free(variables_datas[j]);
                free(variables_types[j]);
            }
            if (RVS_MEMORY_DEBUGGER_MODE == true){
                rvs_standard_debug(false, "Memory Realloc.");
            }
            return false;
        }

        // Variable Data
        variables_datas[i] = (char*) malloc(sizeof(char) * RVS_MEMORY_VARIABLE_DATA_LENGTH);
        if (!variables_datas[i]){
            for (size_t j = rvs_memory->memory_size; j < i; j++){
                free(variables_names[j]);
                free(variables_datas[j]);
                free(variables_types[j]);
            }
            if (RVS_MEMORY_DEBUGGER_MODE == true){
                rvs_standard_debug(false, "Memory Realloc.");
            }
            return false;
        }

        // Variable Type
        variables_types[i] = (char*) malloc(sizeof(char) * RVS_MEMORY_VARIABLE_TYPE_LENGTH);
        if (!variables_types[i]){
            for (size_t j = rvs_memory->memory_size; j < i; j++){
                free(variables_names[j]);
                free(variables_datas[j]);
                free(variables_types[j]);
            }
            if (RVS_MEMORY_DEBUGGER_MODE == true){
                rvs_standard_debug(false, "Memory Realloc.");
            }
            return false;
        }
    }

    rvs_memory->variable_ctrls = variables_ctrls;
    for (size_t i = rvs_memory->memory_size; i < rvs_new_memory_size; i++){
        rvs_memory->variable_ctrls[i] = false;
        rvs_memory->variable_consts[i] = false;
    }

    rvs_memory->variable_names = variables_names;
    rvs_memory->variable_datas = variables_datas;
    rvs_memory->variable_types = variables_types;
    rvs_memory->variable_consts = variables_consts;

    rvs_memory->memory_size *= 2;

    if (RVS_MEMORY_DEBUGGER_MODE == true){
        rvs_standard_debug(true, "Memory Realloc.");
    }

    return true;
}


// RevanScript Memory (RVSMEM) Type Define
void _rvs_memory_type_define(RVSMEM* rvs_memory, const RVSBUF* const rvs_buffer){
    // Variable Type Write Memory
    switch (rvs_buffer->variable_type){
        case RVS_STRING_TYPE:   
            strcpy(rvs_memory->variable_types[rvs_memory->variable_iter], "STR");
            rvs_standard_debug(false, "Variable Type <String>"); 
            break;
        case RVS_INTEGER_TYPE:  
            strcpy(rvs_memory->variable_types[rvs_memory->variable_iter], "INT"); 
            rvs_standard_debug(false, "Variable Type <Integer>");  
            break;
        case RVS_FLOAT_TYPE:    
            strcpy(rvs_memory->variable_types[rvs_memory->variable_iter], "FLT");
            rvs_standard_debug(false, "Variable Type <Float>");    
            break;
        case RVS_BOOLEAN_TYPE:  
            strcpy(rvs_memory->variable_types[rvs_memory->variable_iter], "BLN");
            rvs_standard_debug(false, "Variable Type <Boolean>");    
            break;
        case RVS_BINARY_TYPE:   
            strcpy(rvs_memory->variable_types[rvs_memory->variable_iter], "BIN");  
            rvs_standard_debug(false, "Variable Type <Binary>");  
            break;
        case RVS_NULL_TYPE:     
            strcpy(rvs_memory->variable_types[rvs_memory->variable_iter], "NULL");
            rvs_standard_debug(false, "Variable Type <Null>");   
            break;
    }
}


// RevanScript Memory (RVSMEM) Type Get
void _rvs_memory_type_get(const RVSMEM* const rvs_memory, 
                          const size_t* const rvsmem_index, 
                          RVSBUF* rvs_buffer)
{
    if (strcmp(rvs_memory->variable_types[*rvsmem_index], "STR") == 0){
        rvs_buffer->variable_type = RVS_STRING_TYPE;
    }
    else if (strcmp(rvs_memory->variable_types[*rvsmem_index], "INT") == 0){
        rvs_buffer->variable_type = RVS_INTEGER_TYPE;
    }
    else if (strcmp(rvs_memory->variable_types[*rvsmem_index], "FLT") == 0){
        rvs_buffer->variable_type = RVS_FLOAT_TYPE;
    }
    else if (strcmp(rvs_memory->variable_types[*rvsmem_index], "BLN") == 0){
        rvs_buffer->variable_type = RVS_BOOLEAN_TYPE;
    }
    else if (strcmp(rvs_memory->variable_types[*rvsmem_index], "BIN") == 0){
        rvs_buffer->variable_type = RVS_BINARY_TYPE;
    }
    else if (strcmp(rvs_memory->variable_types[*rvsmem_index], "NULL") == 0){
        rvs_buffer->variable_type = RVS_NULL_TYPE;
    }
}

 
// RevanScript Memory (RVSMEM) Create Function
RVSMEM* rvs_memory_create(void){
    RVSMEM* rvs_memory = (RVSMEM*) malloc(sizeof(RVSMEM));
    if (!rvs_memory) return NULL;

    rvs_memory->variable_ctrls = (bool*) malloc(sizeof(bool) * RVS_MEMORY_DEFAULT_SIZE);
    if (!rvs_memory->variable_ctrls){
        if (RVS_MEMORY_DEBUGGER_MODE == true){
            rvs_standard_debug(false, "Memory create.");
        }
        free(rvs_memory);
        return NULL;
    }

    rvs_memory->variable_names = (char**) malloc(sizeof(char*) * RVS_MEMORY_DEFAULT_SIZE);
    if (!rvs_memory->variable_names){
        if (RVS_MEMORY_DEBUGGER_MODE == true){
            rvs_standard_debug(false, "Memory create.");
        }
        free(rvs_memory->variable_ctrls);
        free(rvs_memory);
        return NULL;
    }

    rvs_memory->variable_datas = (char**) malloc(sizeof(char*) * RVS_MEMORY_DEFAULT_SIZE);
    if (!rvs_memory->variable_datas){
        if (RVS_MEMORY_DEBUGGER_MODE == true){
            rvs_standard_debug(false, "Memory create.");
        }
        free(rvs_memory->variable_ctrls);
        free(rvs_memory->variable_names);
        free(rvs_memory);
        return NULL;
    }

    rvs_memory->variable_types = (char**) malloc(sizeof(char*) * RVS_MEMORY_DEFAULT_SIZE);
    if (!rvs_memory->variable_types){
        if (RVS_MEMORY_DEBUGGER_MODE == true){
            rvs_standard_debug(false, "Memory create.");
        }
        free(rvs_memory->variable_ctrls);
        free(rvs_memory->variable_names);
        free(rvs_memory->variable_datas);
        free(rvs_memory);
        return NULL;
    }

    rvs_memory->variable_consts = (bool*) malloc(sizeof(bool) * RVS_MEMORY_DEFAULT_SIZE);
    if (!rvs_memory->variable_consts){
        if (RVS_MEMORY_DEBUGGER_MODE == true){
            rvs_standard_debug(false, "Memory create.");
        }
        free(rvs_memory->variable_ctrls);
        free(rvs_memory->variable_names);
        free(rvs_memory->variable_datas);
        free(rvs_memory->variable_types);
        free(rvs_memory);
        return NULL;
    }

    for (size_t i = 0; i < RVS_MEMORY_DEFAULT_SIZE; i++){

        // Variable Name
        rvs_memory->variable_names[i] = (char*) malloc(sizeof(char) * RVS_MEMORY_VARIABLE_NAME_LENGTH);
        if (!rvs_memory->variable_names[i]){
            for (size_t j = 0; j < i; j++){
                free(rvs_memory->variable_names[j]);
                free(rvs_memory->variable_datas[j]);
                free(rvs_memory->variable_types[j]);
            }
            free(rvs_memory->variable_ctrls);
            free(rvs_memory->variable_names);
            free(rvs_memory->variable_datas);
            free(rvs_memory->variable_types);
            free(rvs_memory->variable_consts);
            free(rvs_memory);
            if (RVS_MEMORY_DEBUGGER_MODE == true){
                rvs_standard_debug(false, "Memory create.");
            }
            return NULL;
        }
        rvs_memory->variable_names[i][0] = '\0';

        // Variable Data
        rvs_memory->variable_datas[i] = (char*) malloc(sizeof(char) * RVS_MEMORY_VARIABLE_DATA_LENGTH);
        if (!rvs_memory->variable_datas[i]){
            for (size_t j = 0; j < i; j++){
                free(rvs_memory->variable_names[j]);
                free(rvs_memory->variable_datas[j]);
                free(rvs_memory->variable_types[j]);
            }
            free(rvs_memory->variable_ctrls);
            free(rvs_memory->variable_names);
            free(rvs_memory->variable_datas);
            free(rvs_memory->variable_types);
            free(rvs_memory->variable_consts);
            free(rvs_memory);
            if (RVS_MEMORY_DEBUGGER_MODE == true){
                rvs_standard_debug(false, "Memory create.");
            }
            return NULL;
        }
        rvs_memory->variable_datas[i][0] = '\0';

        // Variable Type
        rvs_memory->variable_types[i] = (char*) malloc(sizeof(char) * RVS_MEMORY_VARIABLE_TYPE_LENGTH);
        if (!rvs_memory->variable_types[i]){
            for (size_t j = 0; j < i; j++){
                free(rvs_memory->variable_names[j]);
                free(rvs_memory->variable_datas[j]);
                free(rvs_memory->variable_types[j]);
            }
            free(rvs_memory->variable_ctrls);
            free(rvs_memory->variable_names);
            free(rvs_memory->variable_datas);
            free(rvs_memory->variable_types);
            free(rvs_memory->variable_consts);
            free(rvs_memory);
            if (RVS_MEMORY_DEBUGGER_MODE == true){
                rvs_standard_debug(false, "Memory create.");
            }
            return NULL;
        }
        rvs_memory->variable_types[i][0] = '\0';
    }

    for (size_t i = 0; i < RVS_MEMORY_DEFAULT_SIZE; i++){
        rvs_memory->variable_ctrls[i] = false;
        rvs_memory->variable_consts[i] = false;
    }

    rvs_memory->variable_iter = 0;
    rvs_memory->memory_size = RVS_MEMORY_DEFAULT_SIZE;

    if (RVS_MEMORY_DEBUGGER_MODE == true){
        rvs_standard_debug(true, "Memory create.");
    }

    return rvs_memory;
}


// RevanScript (RVS) Memory (RVSMEM) Insert Function
bool rvs_memory_insert(RVSMEM* rvs_memory ,const RVSBUF const* rvs_buffer){
    while (rvs_memory->memory_size > rvs_memory->variable_iter){
        if ((rvs_memory->memory_size - 1) == rvs_memory->variable_iter){
            if (!_rvs_memory_realloc(rvs_memory)){
                return false;
            }
        }
    
        if (rvs_memory->variable_ctrls[rvs_memory->variable_iter] == false){
            strcpy(rvs_memory->variable_names[rvs_memory->variable_iter], rvs_buffer->variable_name);
            strcpy(rvs_memory->variable_datas[rvs_memory->variable_iter], rvs_buffer->variable_data);
            _rvs_memory_type_define(rvs_memory, rvs_buffer);
            rvs_memory->variable_consts[rvs_memory->variable_iter] = rvs_buffer->variable_const;
            rvs_memory->variable_ctrls[rvs_memory->variable_iter] = true;
            rvs_memory->variable_iter++;
            if (RVS_MEMORY_DEBUGGER_MODE == true){
                rvs_standard_debug(true, "Memory insert.");
            }
            return true;
        }
    }
    return false;
}


// RevanScript (RVS) Memory (RVSMEM) Check / Variable Name Check Function
bool rvs_memory_check(const RVSMEM* const rvs_memory, const char* const variable_name){
    for (size_t i = 0; i < rvs_memory->memory_size; i++){
        if (rvs_memory->variable_ctrls[i] == true){
            if (strcmp(rvs_memory->variable_names[i], variable_name) == 0){
                return true;
            }
        }
    }
    return false;
}


// RevanScript (RVS) Memory (RVSMEM) Get Function
bool rvs_memory_get(const RVSMEM* const rvs_memory, RVSBUF* rvs_buffer){
    for (size_t i = 0; i < rvs_memory->memory_size; i++){
        if (rvs_memory->variable_ctrls[i] == true){
            if (strcmp(rvs_memory->variable_names[i], rvs_buffer->variable_name) == 0){
                strcpy(rvs_buffer->variable_data, rvs_memory->variable_datas[i]);
                _rvs_memory_type_get(rvs_memory, &i, rvs_buffer);
                rvs_buffer->variable_const = rvs_memory->variable_consts[i];
                snprintf(rvs_buffer->variable_address, RVS_BUFFER_VARIABLE_ADDRESS_LENGTH, "0x%zx", i);
                return true;
            }
        }
    }
    rvs_standard_error(RVS_VARIABLE_UNDEFINED_ERROR, rvs_buffer->variable_name);
    return false;
}


// RevanScript (RVS) Memory (RVSMEM) Set Function
bool rvs_memory_set(RVSMEM* rvs_memory, const RVSBUF* const rvs_buffer){
    for (size_t i = 0; i < rvs_memory->memory_size; i++){
        if (rvs_memory->variable_ctrls[i] == true){
            if (strcmp(rvs_memory->variable_names[i], rvs_buffer->variable_name) == 0){
                if (rvs_memory->variable_consts[i] == false){
                    strcpy(rvs_memory->variable_datas[i], rvs_buffer->variable_data);
                    _rvs_memory_type_define(rvs_memory, rvs_buffer);
                    return true;
                }

                else{
                    rvs_standard_error(RVS_VARIABLE_CONSTANT_ERROR, NULL);
                    return false;
                }
            }
        }
    }
    rvs_standard_error(RVS_VARIABLE_UNDEFINED_ERROR, rvs_buffer->variable_name);
    return false;
}


// RevanScript (RVS) Memory (RVSMEM) Cst (Constant Variable) Function
bool rvs_memory_const(RVSMEM* rvs_memory, const RVSBUF* const rvs_buffer){
    for (size_t i = 0; i < rvs_memory->memory_size; i++){
        if (strcmp(rvs_memory->variable_names[i], rvs_buffer->variable_name) == 0){
            if (rvs_memory->variable_consts[i] == false){
                rvs_memory->variable_consts[i] = true;
                return true;
            }

            else{
                rvs_standard_info(RVS_VARIABLE_CONSTANT_INFO);
                return true;
            }
        }
    }
    rvs_standard_error(RVS_VARIABLE_UNDEFINED_ERROR, rvs_buffer->variable_name);
    return false;
}


// RevanScript (RVS) Memory (RVSMEM) Clear Function
bool rvs_memory_clear(RVSMEM* rvs_memory, const RVSBUF* const rvs_buffer){
    for (size_t i = 0; i < rvs_memory->memory_size; i++){
        if (rvs_memory->variable_ctrls[i] == true){
            if (strcmp(rvs_memory->variable_names[i], rvs_buffer->variable_name) == 0){
                rvs_memory->variable_names[i][0] = '\0';
                rvs_memory->variable_datas[i][0] = '\0';
                rvs_memory->variable_types[i][0] = '\0';
                rvs_memory->variable_consts[i] = false;
                rvs_memory->variable_ctrls[i] = false;
                rvs_memory->variable_iter = 0;
                return true;
            }
        }
    }
    rvs_standard_error(RVS_VARIABLE_UNDEFINED_ERROR, rvs_buffer->variable_name);
    return false;
}


// RevanScript (RVS) Memory (RVSMEM) Delete / (free) Function
void rvs_memory_delete(RVSMEM* rvs_memory){
    for (size_t i = 0; i < rvs_memory->memory_size; i++){
        free(rvs_memory->variable_names[i]);
        free(rvs_memory->variable_datas[i]);
        free(rvs_memory->variable_types[i]);
    }
    free(rvs_memory->variable_ctrls);
    free(rvs_memory->variable_names);
    free(rvs_memory->variable_datas);
    free(rvs_memory->variable_types);
    free(rvs_memory->variable_consts);
    free(rvs_memory);
}