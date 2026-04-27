#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "../include/rvsprs.h"
#include "../include/rvsbuf.h"
#include "../include/rvsmem.h"
#include "../include/rvsctl.h"


// RevanScript (RVS) Variable Parser Function
RVSBUF* rvs_variable_parser(const char* const code_line, RVSMEM* rvs_memory, bool create_mode){

    // RevanScript (RVS) Buffer Memory
	RVSBUF* rvs_variable_buffer = rvs_buffer_create();
	if (!rvs_variable_buffer) return false;

	// RevanScript Parsing Logic Operation
	RVSLOGIC rvs_variable_logic;
	rvs_variable_logic.assignment_operation_check = false;
	rvs_variable_logic.string_literal_check = false;
	rvs_variable_logic.binary_start_operation_check = false;

	// Parsing
	for (size_t i = 0; code_line[i] != '\n' && code_line[i] != '\0'; i++){

		// Assignment Operator
		if (code_line[i] == '='){
			if (rvs_variable_logic.assignment_operation_check == false){
				rvs_variable_logic.assignment_operation_check = true;
			}
		}

		// Variable Name
		else if (rvs_variable_logic.assignment_operation_check == false){
			if (code_line[i] == ' ') continue;
			rvs_variable_buffer->variable_name[rvs_variable_buffer->variable_name_counter++] = code_line[i];
		}

		// Variable Data 
		else if (rvs_variable_logic.assignment_operation_check == true){

			// String Data Literal (Open / Close) System
			if (code_line[i] == '\"'){
				if (rvs_variable_logic.string_literal_check == false){
					rvs_variable_logic.string_literal_check = true;
					if (rvs_variable_buffer->variable_type == RVS_UNDEFINED_TYPE){
						rvs_variable_buffer->variable_type = RVS_STRING_TYPE;
					}
				}

				else{
					rvs_variable_logic.string_literal_check = false;
					break;
				}
			}

			// Binary Type (Open) System
 			else if (rvs_variable_logic.string_literal_check == false && code_line[i] == 'b'){
				if (rvs_variable_logic.binary_start_operation_check == false){
					rvs_variable_logic.binary_start_operation_check = true;
					if (rvs_variable_buffer->variable_type == RVS_UNDEFINED_TYPE){
						rvs_variable_buffer->variable_type = RVS_BINARY_TYPE;
					}
				}
			}

			// String Data Buffer write
			else if (rvs_variable_logic.string_literal_check == true){
				if (code_line[i] == '\\' && code_line[i + 1] == '\\'){
					rvs_variable_buffer->variable_data[rvs_variable_buffer->variable_data_counter++] = '\\';
					++i;
				}

				else if (code_line[i] == '\\' && code_line[i + 1] == '\"'){
					rvs_variable_buffer->variable_data[rvs_variable_buffer->variable_data_counter++] = '\"';
					++i;
				}

				else{
					rvs_variable_buffer->variable_data[rvs_variable_buffer->variable_data_counter++] = code_line[i];
				}
			}

			// Boolean, Integer, Float, Binary and NULL Types Parsing
			else{
				if (code_line[i] == ' ') continue;
				rvs_variable_buffer->variable_data[rvs_variable_buffer->variable_data_counter++] = code_line[i];
			}
		}
	}

	rvs_variable_buffer->variable_name[rvs_variable_buffer->variable_name_counter] = '\0';
	rvs_variable_buffer->variable_data[rvs_variable_buffer->variable_data_counter] = '\0';

    // RevanScript Buffer "Variable Name" Checking
	if (rvs_variable_name_check(rvs_variable_buffer, rvs_memory, create_mode) == false){
		rvs_buffer_delete(rvs_variable_buffer);
		return NULL;
	}

	// RevanScript "Constant Variable" Define
	if (rvs_variable_buffer->variable_name[0] == '_'){
		rvs_variable_buffer->variable_const = true;
	}

	// RevanScript Binary Type Default Data
	if (strlen(rvs_variable_buffer->variable_data) == 0){
		strcpy(rvs_variable_buffer->variable_data, "00000000");
		rvs_variable_buffer->variable_data[8] = '\0';
	}

	// RevanScript automatic NULL data
	if (rvs_variable_logic.assignment_operation_check == false){
		strcpy(rvs_variable_buffer->variable_data, "NULL");
		rvs_variable_buffer->variable_type = RVS_NULL_TYPE;
	}

	else{
		// RevanScript Buffer "Variable Data" Checking
		if (rvs_variable_data_check(rvs_variable_buffer, &rvs_variable_logic) == false){
			rvs_buffer_delete(rvs_variable_buffer);
			return NULL;
		}
	}

    return rvs_variable_buffer;
}


// RevanScript (RVS) Variable Name Parser
RVSBUF* rvs_variable_name_parser(const char* const code_line){
	// RevanScript (RVS) Variable Buffer
	RVSBUF* rvs_buffer = rvs_buffer_create();
	if (!rvs_buffer) return NULL;

	// Parsing
	for (size_t i = 0; code_line[i] != '\n' && code_line[i] != '\0'; i++){
		if (code_line[i] == ' ') continue;
		rvs_buffer->variable_name[rvs_buffer->variable_name_counter++] = code_line[i];
	}
	rvs_buffer->variable_name[rvs_buffer->variable_name_counter] = '\0';
	return rvs_buffer;
}