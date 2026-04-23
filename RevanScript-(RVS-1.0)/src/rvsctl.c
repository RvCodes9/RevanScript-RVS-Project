#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

#include <stdio.h>

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


bool rvs_variable_data_check(RVSBUF* rvs_variable_buffer, const RVSLOGIC* const rvs_variable_logic){

    // No Data Checking
    if (rvs_variable_logic->assignment_operation_check == true && rvs_variable_buffer->variable_data[0] == '\0'){
		rvs_standard_error(RVS_VARIABLE_NO_DATA_ERROR, NULL);
		return false;
	}

    // String Type Checking
	else if (rvs_variable_buffer->variable_type == RVS_STRING_TYPE){
		if (rvs_variable_logic->string_literal_check == true){
			rvs_standard_error(RVS_STRING_LITERAL_ERROR, NULL);
			return false;
		}
	}

    else if (rvs_variable_buffer->variable_type == RVS_BINARY_TYPE){
        for (size_t i = 0; rvs_variable_buffer->variable_data[i] != '\0'; i++){
            if (rvs_variable_buffer->variable_data[i] != '0' && rvs_variable_buffer->variable_data[i] != '1'){
                rvs_standard_error(RVS_BINARY_TYPE_ERROR, NULL);
                return false;
            }
        }
    }

    // (Boolean, Integer, Float and NULL) Type Checking
    else if (rvs_variable_buffer->variable_type == RVS_UNDEFINED_TYPE){
        if (strcmp(rvs_variable_buffer->variable_data, "TRUE") != 0 && strcmp(rvs_variable_buffer->variable_data, "FALSE") != 0){
            if (strcmp(rvs_variable_buffer->variable_data, "NULL") != 0){
                bool point_check = false;
                size_t point_count = 0;

                for (size_t i = 0; rvs_variable_buffer->variable_data[i] != '\0'; i++){
                    if (!isdigit(rvs_variable_buffer->variable_data[i])){
                        if (rvs_variable_buffer->variable_data[i] != '.'){
                            rvs_standard_error(RVS_UNDEFINED_TYPE_ERROR, NULL);
                            return false;
                        }

                        else{
                            if (point_check == false){
                                point_check = true;
                            }
                            ++point_count;
                        }
                    }
                }

                // Float Type
                if (point_check == true){
                    
                    // Float First Char Point Problem (Error)
                    if (rvs_variable_buffer->variable_data[0] == '.'){
                        rvs_standard_error(RVS_FLOAT_FIRST_POINT_ERROR, NULL);
                        return false;
                    }

                    if (point_count > 1){
                        rvs_standard_error(RVS_FLOAT_MULTI_POINT_ERROR, NULL);
                        return false;
                    }

                    if (rvs_variable_buffer->variable_data[strlen(rvs_variable_buffer->variable_data) - 1] == '.'){
                        rvs_standard_error(RVS_FLOAT_LAST_POINT_ERROR, NULL);
                        return false;
                    }

                    rvs_variable_buffer->variable_type = RVS_FLOAT_TYPE;
                }

                // Integer Type
                else{

                    // Integer First Char Digit Zero Problem (Error)
                    if (strlen(rvs_variable_buffer->variable_data) > 1 && rvs_variable_buffer->variable_data[0] == '0'){
                        rvs_standard_error(RVS_INTEGER_FIRST_DIGIT_ZERO_ERROR, NULL);
                        return false;
                    }

                    rvs_variable_buffer->variable_type = RVS_INTEGER_TYPE;
                }
            }

            // NULL Type
            else{
                rvs_variable_buffer->variable_type = RVS_NULL_TYPE;
            }
        }

        // Boolean Type (TRUE, FALSE)
        else{
            rvs_variable_buffer->variable_type = RVS_BOOLEAN_TYPE;
        }
    }

    return true;
}

