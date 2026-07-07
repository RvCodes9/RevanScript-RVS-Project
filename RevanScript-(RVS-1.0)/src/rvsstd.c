// C Standard Librarys
#include <stdbool.h>
#include <string.h>

#include <stdio.h>

// RevanScript (RVS) Core / Engine Libraries
#include "../include/rvsprs.h"
#include "../include/rvsmem.h"
#include "../include/rvsbuf.h"
#include "../include/rvsctl.h"


// RevanScript Variable Automatic Configure Function 
RVSPRS* rvs_standard_variable(const char* const code_line, RVSMEM* rvs_memory, bool create_mode){
    // Variable Parser
	RVSPRS* rvs_parser = rvs_variable_parser(code_line);
	if (!rvs_parser) return NULL;

	// RevanScript Buffer "Variable Name" Checking
	if (rvs_variable_name_check(rvs_parser->rvs_buffer->variable_name, rvs_memory, create_mode) == false){
		// Dellocate
		rvs_buffer_delete(rvs_parser->rvs_buffer);
		rvs_expression_delete(rvs_parser->rvs_expression);
		rvs_logic_delete(rvs_parser->rvs_logic);
		rvs_parser_delete(rvs_parser);
		return NULL;
	}

	// RevanScript "Constant Variable" Define
	if (rvs_parser->rvs_buffer->variable_name[0] == '_'){
		rvs_parser->rvs_buffer->variable_const = true;
	}

	// RevanScript automatic NULL data
	if (rvs_parser->rvs_logic->assignment_operation_check == false){
		strcpy(rvs_parser->rvs_buffer->variable_data, "NULL");
		rvs_parser->rvs_buffer->variable_type = RVS_NULL_TYPE;
	}

	// RevanScript Buffer "Variable Data" Checking
	else if (rvs_variable_data_check(rvs_parser->rvs_buffer, rvs_memory, rvs_parser->rvs_logic) == false){
		// Dellocate
		rvs_buffer_delete(rvs_parser->rvs_buffer);
		rvs_expression_delete(rvs_parser->rvs_expression);
		rvs_logic_delete(rvs_parser->rvs_logic);
		rvs_parser_delete(rvs_parser);
		return NULL;
	}

	// RevanScript Binary Type Default Data
	if (rvs_parser->rvs_buffer->variable_type == RVS_BINARY_TYPE){
		if (strlen(rvs_parser->rvs_buffer->variable_data) == 0){
			strcpy(rvs_parser->rvs_buffer->variable_data, "00000000");
			rvs_parser->rvs_buffer->variable_data[8] = '\0';
		}
	}

	// RevanScript Expression Process
	if (rvs_parser->rvs_buffer->variable_type == RVS_EXPRESSION_TYPE){
		if (!rvs_expression_process(rvs_parser->rvs_expression, rvs_parser->rvs_buffer)){
			// Dellocate
			rvs_buffer_delete(rvs_parser->rvs_buffer);
			rvs_expression_delete(rvs_parser->rvs_expression);
			rvs_logic_delete(rvs_parser->rvs_logic);
			rvs_parser_delete(rvs_parser);
			return NULL;
		}
	}

    return rvs_parser;
}