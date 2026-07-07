// C Standard Libraries
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// RevanScript (RVS) Core / Engine Libraries
#include "../include/rvstbl.h"


// RevanScript (RVS) Table Create Function
RVSTBL* rvs_table_create(const struct RVSTBLConfig const rvs_table_config){
    RVSTBL* rvs_table = (RVSTBL*) malloc(sizeof(RVSTBL));
    if (!rvs_table) return NULL;
    size_t length = rvs_table_config.rows * rvs_table_config.cols;

    rvs_table->datas = (char**) malloc(sizeof(RVSTBL*) * length);
    if (!rvs_table->datas){
        free(rvs_table);
        return NULL;
    }

    for (size_t i = 0; i < length; i++){
        rvs_table->datas[i] = (char*) calloc(sizeof(char), 2048);
        if (!rvs_table->datas[i]){
            for (size_t j = 0; j < i; j++){
                free(rvs_table->datas[i]);
            }
            return NULL;
        }
    }

    rvs_table->config.rows = rvs_table_config.rows;
    rvs_table->config.cols = rvs_table_config.cols;
    rvs_table->config.width = rvs_table_config.width;
    rvs_table->config.height = rvs_table_config.height;

    rvs_table->length = length;
    rvs_table->iter = 0;

    return rvs_table;
}


// RevanScript (RVS) Table Insert Function
bool rvs_table_insert(RVSTBL* rvs_table, const char* const data){
    // Reallocate Table Memory
    if (rvs_table->iter == rvs_table->length){
        size_t new_rvs_table_length = rvs_table->length * 2;
        char** new_rvs_table_datas = (char**) realloc(
            rvs_table->datas, 
            sizeof(char*) * new_rvs_table_length);
        if (!new_rvs_table_datas) return false;
        else rvs_table->datas = new_rvs_table_datas;
    }

    size_t data_length = strlen(data);
    size_t i = 0;

    // Data Write
    rvs_table->datas[rvs_table->iter][i++] = ' ';
    for (; i < data_length + 1; i++){
        rvs_table->datas[rvs_table->iter][i] = data[i - 1];
    }

    // Space Write
    if (rvs_table->config.width > data_length){
        for (; i < rvs_table->config.width; i++){
            rvs_table->datas[rvs_table->iter][i] = ' ';
        }
    }

    rvs_table->datas[rvs_table->iter][i] = '\0';
    rvs_table->iter++;

    return true;
}


// RevanScript (RVS) Table Delete Function
void rvs_table_delete(RVSTBL* rvs_table){
    for (size_t i = 0; i < (rvs_table->config.rows * rvs_table->config.cols); i++){
        free(rvs_table->datas[i]);
    }
    free(rvs_table->datas);
    free(rvs_table);
}