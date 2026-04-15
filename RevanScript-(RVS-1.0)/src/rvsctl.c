#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

#include "../include/rvsmem.h"
#include "../include/rvsio.h"

#include "../include/rvsctl.h"


bool rvs_file_type_check(const char* const file_type){
    if (strcmp(file_type, ".rvs") == 0){
        return true;
    }

    else{
        rvs_standard_error(RVS_FILE_TYPE_ERROR, NULL);
        return false;
    }
}


bool rvs_variable_name_check(const RVSBUF* const rvs_buffer, const RVSMEM* const rvs_memory, bool create_type){

    if (rvs_buffer->variable_name[0] == '\0'){
        rvs_standard_error(RVS_VARIABLE_NO_NAME_ERROR, NULL);
        return false;
    }

    if (isdigit(rvs_buffer->variable_name[0]) != 0){
        rvs_standard_error(RVS_VARIABLE_NAME_FIRST_CHARACTER_NUMBER_ERROR, NULL);
        return false;
    }

    if (strlen(rvs_buffer->variable_name) > 30){
        rvs_standard_error(RVS_VARIABLE_NAME_LENGTH_ERROR, NULL);
        return false;
    }
    
    for (size_t i = 0; rvs_buffer->variable_name[i] != '\0'; i++){
        if (isalnum(rvs_buffer->variable_name[i]) == 0 && rvs_buffer->variable_name[i] != '_'){
            rvs_standard_error(RVS_VARIABLE_NAME_CHARACTER_ERROR, NULL);
            return false;
        }
    }

    if (create_type == true){
        if (rvs_memory_check(rvs_memory, rvs_buffer) == true){
            rvs_standard_error(RVS_VARIABLE_NAME_DUBLICATE_ERROR, NULL);
            return false;
        }
    }

    return true;
}


bool rvs_variable_data_check(const RVSBUF* const rvs_variable_buffer, const RVSTYPE* const rvs_variable_types, const RVSLOGIC* const rvs_variable_logic){

    if (rvs_variable_logic->assignment_operation_check == true && rvs_variable_buffer->variable_data[0] == '\0'){
		rvs_standard_error(RVS_VARIABLE_NO_DATA_ERROR, NULL);
		return false;
	}

	else if (rvs_variable_types->string_type_check == true){
		if (rvs_variable_logic->string_literal_check == true){
			rvs_standard_error(RVS_STRING_LITERAL_ERROR, NULL);
			return false;
		}
	}

    return true;
}

