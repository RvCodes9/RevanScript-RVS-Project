#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

#include "rvsio.h"


bool rvs_file_type_check(const char* const file_type){
    if (strcmp(file_type, ".rvs") == 0){
        return true;
    }

    else{
        rvs_standard_error(RVS_FILE_TYPE_ERROR, NULL);
        return false;
    }
}


bool rvs_variable_name_check(const char* const variable_name){

    if (variable_name[0] == '\0'){
        rvs_standard_error(RVS_VARIABLE_NO_NAME_ERROR, NULL);
        return false;
    }

    if (isdigit(variable_name[0]) != 0){
        rvs_standard_error(RVS_VARIABLE_NAME_FIRST_CHARACTER_NUMBER_ERROR, NULL);
        return false;
    }

    if (strlen(variable_name) > 30){
        rvs_standard_error(RVS_VARIABLE_NAME_LENGTH_ERROR, NULL);
        return false;
    }
    
    for (size_t i = 0; variable_name[i] != '\0'; i++){
        if (isalnum(variable_name[i]) == 0 && variable_name[i] != '_'){
            rvs_standard_error(RVS_VARIABLE_NAME_CHARACTER_ERROR, NULL);
            return false;
        }
    }

    return true;
}

