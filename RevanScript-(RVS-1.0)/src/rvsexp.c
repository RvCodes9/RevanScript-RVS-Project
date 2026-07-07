// C Standard Libraries
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

// RevanScript (RVS) Core / Engine Libraries
#include "../include/rvsexp.h"
#include "../include/rvsbuf.h"
#include "../include/rvsmth.h"


// RevanScript Expression Memory Create
RVSEXP* rvs_expression_create(void){
    // RevanScript Expression Memory Allocate
    RVSEXP* rvs_expression = (RVSEXP*) malloc(sizeof(RVSEXP));
    if (!rvs_expression){
        return NULL;
    }
    
    // Operations Memory Allocate
    rvs_expression->ops = (char*) malloc(sizeof(char) * 2048);
    if (!rvs_expression){
        free(rvs_expression);
        return NULL;
    }

    // Numbers Memory Allocate
    rvs_expression->nums = (char**) malloc(sizeof(char*) * 2048);
    if (!rvs_expression){
        free(rvs_expression->ops);
        free(rvs_expression);
        return NULL;
    }

    for (size_t i = 0; i < RVS_EXPRESSION_NUMS_SIZE; i++){
        rvs_expression->nums[i] = (char*) malloc(sizeof(char) * 2048);
        if (!rvs_expression->nums[i]){
            for (size_t j = 0; j < i; j++){
                free(rvs_expression->nums[j]);
            }
            free(rvs_expression->ops);
            free(rvs_expression->nums);
            free(rvs_expression);
            return NULL;
        }
        rvs_expression->nums[i][0] = '\0';
    }

    rvs_expression->ops_counter = 0;
    rvs_expression->nums_counter = 0;
    rvs_expression->char_counter = 0;
    
    return rvs_expression;
}


// RevanScript (RVS) Expression Process Engine
bool rvs_expression_process(const RVSEXP* const rvs_expression, RVSBUF* rvs_buffer){
    char* total = (char*) calloc(sizeof(char), 2048);
    if (!total) return false;
    strcpy(total, rvs_expression->nums[0]);
    for (size_t i = 0; i < strlen(rvs_expression->ops); i++){
        if (rvs_expression->ops[i] == '+'){
            RVSMTH* rvs_addition_operation = rvs_math_int_add(total, rvs_expression->nums[i + 1]);
            if (!rvs_addition_operation){
                free(total);
                return false;
            }
            strcpy(total, rvs_addition_operation);
            rvs_math_memory_delete(rvs_addition_operation);
        }
    }
    strcpy(rvs_buffer->variable_data, total);
    free(total);
    return true;
}


// RevanScript Expression Memory Delete
void rvs_expression_delete(RVSEXP* rvs_expression){
    for (size_t i = 0; i < RVS_EXPRESSION_NUMS_SIZE; i++){
        free(rvs_expression->nums[i]);
    }
    free(rvs_expression->nums);
    free(rvs_expression->ops);
    free(rvs_expression);
}