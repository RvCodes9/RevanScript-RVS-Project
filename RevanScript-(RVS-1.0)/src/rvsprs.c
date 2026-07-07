// C Standard Libraries
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


// RevanScript (RVS) Core/Engine Libraries
#include "../include/rvsprs.h"
#include "../include/rvsbuf.h"
#include "../include/rvsexp.h"
#include "../include/rvslgc.h"
#include "../include/rvsmem.h"
#include "../include/rvsctl.h"
#include "../include/rvserr.h"


// RevanScript (RVS) Direct Parser Memory (Create Function)
RVS_DIRECT_PARSER* rvs_direct_parser_create(void){

	// RevanScript (RVS) Direct Parser Memory Allocate
	RVS_DIRECT_PARSER* rvs_direct_parser = (RVS_DIRECT_PARSER*) malloc(sizeof(RVS_DIRECT_PARSER));
	if (!rvs_direct_parser) return NULL;

	// RevanScript Direct Buffer Memory Allocate
	RVS_DIRECT_BUFFER* rvs_direct_buffer = rvs_direct_buffer_create();
	if (!rvs_direct_buffer){
		free(rvs_direct_parser);
		return NULL;
	}

	// RevanScript Direct Logic Memory Allocate
	RVS_DIRECT_LOGIC* rvs_direct_logic = rvs_direct_logic_create();
	if (!rvs_direct_logic){
		rvs_direct_buffer_delete(rvs_direct_buffer);
		free(rvs_direct_parser);
		return NULL;
	}

	// Connect Pointers
	rvs_direct_parser->rvs_direct_buffer = rvs_direct_buffer;
	rvs_direct_parser->rvs_direct_logic = rvs_direct_logic;

	// Return Direct Parser
	return rvs_direct_parser;
}


// RevanScript (RVS) Direct Parser Memory (Delete Function)
void rvs_direct_parser_delete(RVS_DIRECT_PARSER* rvs_direct_parser){
	rvs_direct_buffer_delete(rvs_direct_parser->rvs_direct_buffer);
	rvs_direct_logic_delete(rvs_direct_parser->rvs_direct_logic);
	free(rvs_direct_parser);
}


// RevanScript (RVS) Variable Parser Memory (Create Function)
RVSPRS* rvs_parser_create(void){

	// RevanScript (RVS) Parser Memory Allocate
	RVSPRS* rvs_parser = (RVSPRS*) malloc(sizeof(RVSPRS));
	if (!rvs_parser) return NULL;

	// RevanScript (RVS) Buffer Memory Allocate
	RVSBUF* rvs_variable_buffer = rvs_buffer_create();
	if (!rvs_variable_buffer){
		free(rvs_parser);
		return NULL;
	}
 
	// RevanScript (RVS) Expression Memory Allocate
	RVSEXP* rvs_variable_expression = rvs_expression_create();
	if (!rvs_variable_expression){
		rvs_buffer_delete(rvs_variable_buffer);
		free(rvs_parser);
		return NULL;
	}

	// RevanScript Parsing Logic Memory Allocate
	RVSLGC* rvs_variable_logic = rvs_logic_create();
	if (!rvs_variable_logic){
		rvs_buffer_delete(rvs_variable_buffer);
		rvs_expression_delete(rvs_variable_expression);
		free(rvs_parser);
		return NULL;
	}

	// Connect Pointers
	rvs_parser->rvs_buffer = rvs_variable_buffer;
	rvs_parser->rvs_expression = rvs_variable_expression;
	rvs_parser->rvs_logic = rvs_variable_logic;

	// Return Parser
	return rvs_parser;
}


// RevanScript (RVS) Variable Parser Memory (Delete Function)
void rvs_parser_delete(RVSPRS* rvs_parser){
	rvs_buffer_delete(rvs_parser->rvs_buffer);
	rvs_expression_delete(rvs_parser->rvs_expression);
	rvs_logic_delete(rvs_parser->rvs_logic);
	free(rvs_parser);
}


// RevanScript (RVS) Variable Parser Function
RVSPRS* rvs_variable_parser(const char* const code_line){

	// RevanScript (RVS) Parser Memory
	RVSPRS* rvs_parser = rvs_parser_create();
	if (!rvs_parser) return NULL;

	// Parsing
	for (size_t i = 0; code_line[i] != '\n' && code_line[i] != '\0'; i++){

		// Assignment Operator
		if (code_line[i] == '='){
			if (rvs_parser->rvs_logic->assignment_operation_check == false){
				rvs_parser->rvs_logic->assignment_operation_check = true;
			}
		}

		// Variable Name
		else if (rvs_parser->rvs_logic->assignment_operation_check == false){
			if (code_line[i] == ' ') continue;
			rvs_parser->rvs_buffer->variable_name[rvs_parser->rvs_buffer->variable_name_counter++] = code_line[i];
		}

		// Variable Data 
		else if (rvs_parser->rvs_logic->assignment_operation_check == true){

			// String Data Literal (Open / Close) System
			if (code_line[i] == '\"'){
				if (rvs_parser->rvs_logic->string_literal_check == false){
					rvs_parser->rvs_logic->string_literal_check = true;
					if (rvs_parser->rvs_buffer->variable_type == RVS_UNDEFINED_TYPE){
						rvs_parser->rvs_buffer->variable_type = RVS_STRING_TYPE;
					}
				}

				else{
					rvs_parser->rvs_logic->string_literal_check = false;
					break;
				}
			}

			// Binary Type (Open) System
 			else if (rvs_parser->rvs_logic->string_literal_check == false && code_line[i] == 'b'){
				if (rvs_parser->rvs_logic->binary_start_operation_check == false){
					rvs_parser->rvs_logic->binary_start_operation_check = true;
					if (rvs_parser->rvs_buffer->variable_type == RVS_UNDEFINED_TYPE){
						rvs_parser->rvs_buffer->variable_type = RVS_BINARY_TYPE;
					}
				}
			}

			// Expression Parsing
			else if (code_line[i] == '('){ // Open 
				if (rvs_parser->rvs_logic->expression_check == false){
					rvs_parser->rvs_logic->expression_check = true;
					if (rvs_parser->rvs_buffer->variable_type == RVS_UNDEFINED_TYPE){
						rvs_parser->rvs_buffer->variable_type = RVS_EXPRESSION_TYPE;
					}
				}
			}
			
			else if (code_line[i] == ')'){ // Close
				if (rvs_parser->rvs_logic->expression_check == true){
					rvs_parser->rvs_logic->expression_check = false;
					break;
				}
			}

			// Expression Data write
			else if (rvs_parser->rvs_logic->expression_check == true){
				if (code_line[i] == ' ') continue;

				// Numbers Buffer Write
				else if (isdigit(code_line[i]) != 0){
					rvs_parser->rvs_expression->nums[rvs_parser->rvs_expression->nums_counter][rvs_parser->rvs_expression->char_counter++] = code_line[i];
					if (rvs_parser->rvs_logic->expression_queue != RVS_NUMBER_QUEUE){
						rvs_parser->rvs_logic->expression_queue = RVS_NUMBER_QUEUE;
					}
				}

				//  Operators Buffer Write
				else if (code_line[i] == '+' || code_line[i] == '-' || code_line[i] == '*' || code_line[i] == '/'){
					if (rvs_parser->rvs_logic->expression_queue == RVS_UNDEFINED_QUEUE){
						//printf("\nEXPRESSION FIRST OPERATOR INVALID\n");
						rvs_parser_delete(rvs_parser);
						return NULL;
					}

					else if (rvs_parser->rvs_logic->expression_queue == RVS_OPERATOR_QUEUE){
						//printf("\nEXPRESSION INVALID\n");
						rvs_parser_delete(rvs_parser);
						return NULL;
					}

					// Number Buffer Config
					rvs_parser->rvs_expression->nums[rvs_parser->rvs_expression->nums_counter][rvs_parser->rvs_expression->char_counter] = '\0';
					rvs_parser->rvs_expression->nums_counter++;
					rvs_parser->rvs_expression->char_counter = 0;

					rvs_parser->rvs_expression->ops[rvs_parser->rvs_expression->ops_counter++] = code_line[i]; 
					rvs_parser->rvs_logic->expression_queue = RVS_OPERATOR_QUEUE;
				}
			} 

			// String Data Buffer write
			else if (rvs_parser->rvs_logic->string_literal_check == true){
				if (code_line[i] == '\\' && code_line[i + 1] == '\\'){
					rvs_parser->rvs_buffer->variable_data[rvs_parser->rvs_buffer->variable_data_counter++] = '\\';
					++i;
				}

				else if (code_line[i] == '\\' && code_line[i + 1] == '\"'){
					rvs_parser->rvs_buffer->variable_data[rvs_parser->rvs_buffer->variable_data_counter++] = '\"';
					++i;
				}

				else{
					rvs_parser->rvs_buffer->variable_data[rvs_parser->rvs_buffer->variable_data_counter++] = code_line[i];
				}
			}

			// Boolean, Integer, Float, Binary, Null and Variable Types Parsing
			else{
				if (code_line[i] == ' ') continue;
				rvs_parser->rvs_buffer->variable_data[rvs_parser->rvs_buffer->variable_data_counter++] = code_line[i];
			}
		}
	}

	// RevanScript (RVS) Buffer Null Terminators
	rvs_parser->rvs_buffer->variable_name[rvs_parser->rvs_buffer->variable_name_counter] = '\0';
	rvs_parser->rvs_buffer->variable_data[rvs_parser->rvs_buffer->variable_data_counter] = '\0';
	rvs_parser->rvs_expression->ops[rvs_parser->rvs_expression->ops_counter] = '\0';
	rvs_parser->rvs_expression->nums[rvs_parser->rvs_expression->nums_counter++][rvs_parser->rvs_expression->char_counter] = '\0';

    return rvs_parser;
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


// RevanScript (RVS) Direct String Parser
RVS_DIRECT_PARSER* rvs_direct_data_parser(const char* const code_line){
	// RevanScript Direct Parser Memory Allocate
	RVS_DIRECT_PARSER* rvs_direct_parser = rvs_direct_parser_create();
	if (!rvs_direct_parser) return NULL;

	for (size_t i = 0; code_line[i] != '\n' && code_line[i] != '\0'; i++){

		// String Parsing
		if (code_line[i] == '\"'){
			if (rvs_direct_parser->rvs_direct_logic->string_literal_check == false){
				rvs_direct_parser->rvs_direct_logic->string_literal_check = true;
				continue;
			}

			else{
				rvs_direct_parser->rvs_direct_logic->string_literal_check = false;
			}
		}

		// Escape Sequances Parsing Define
		else if (rvs_direct_parser->rvs_direct_logic->string_literal_check == true){
			if (code_line[i] == '\\' && code_line[i + 1] == '\\'){
				rvs_direct_parser->rvs_direct_buffer->direct_data[rvs_direct_parser->rvs_direct_buffer->direct_data_counter++] = '\\';
				++i;
			}

			else if (code_line[i] == '\\' && code_line[i + 1] == '\"'){
				rvs_direct_parser->rvs_direct_buffer->direct_data[rvs_direct_parser->rvs_direct_buffer->direct_data_counter++] = '\"';
				++i;
			}

			else{
				rvs_direct_parser->rvs_direct_buffer->direct_data[rvs_direct_parser->rvs_direct_buffer->direct_data_counter++] = code_line[i];
			}
		}

		// Boolean, Integer, Float, Binary, Null and Variable Types Parsing
		else{
			if (code_line[i] == ' ') continue;
			rvs_direct_parser->rvs_direct_buffer->direct_data[rvs_direct_parser->rvs_direct_buffer->direct_data_counter++] = code_line[i];
		}
	}

	if (rvs_direct_parser->rvs_direct_logic->string_literal_check == true){
		rvs_standard_error(RVS_STRING_LITERAL_ERROR, NULL);
		free(rvs_direct_parser);
		return NULL;
	}

	rvs_direct_parser->rvs_direct_buffer->direct_data[rvs_direct_parser->rvs_direct_buffer->direct_data_counter] = '\0';
	return rvs_direct_parser;
}