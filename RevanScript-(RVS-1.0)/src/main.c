/*
	© 2026 Rəvan Babayev. All rights reserved.
	--------------------------------------------
	License : GPLv3 / Open Source Project
	--------------------------------------------
	RvCodes9 -- GitHub / YouTube / Reddit -- Platform
	--------------------------------------------
	RevanScript (RVS) Programming Language
	RevanScript (RVS) Interpreter Program (Direct Execution Model)
	--------------------------------------------
	C Source Codes  |  C1999 / C99 Standard | Compiler -> GNU Compiler Collection (GCC)
	--------------------------------------------
	automatic gcc compile file -> shell/executable-gcc.sh
	automatic clang compile file -> shell/executable-clang.sh
	---------------------------------------------
	SimpleMake (Source Codes Build Tool) Support
	---------------------------------------------
*/

/*
    RevanScript (RVS) haqqında və istifadə qaydaları.
	---------------------------------------------------------------------------------------
	RevanScript minimal bir proqramlaşdırma dilidir.
	Dilin əsas xüsusiyyətləri təməl I/O və sadə yaddaş idarəsi funksiyanallığı verməkdir.
	Dildə hazırda Simvolları çap etmə xüsusiyəti var.
	Bu xüsusiyyətdən yararlanmaq üçün "REPL MODE" da daxil olub bu kodu yazmaq yetərlidir.
	
	prt "Hello, World!"

	"Escape Sequances" dəndə yararlanmaq mümkündür.

	prt "Hello, World!\n"
	prt "\tHello, World!\n"
	prt "\a"
	prt "\""
	prt "\\"
	prt "\c1Hello\c0"

	RevanScript kısa adıyla RVS də "REPL MODE" dan əlavə "FILE MODE" da var.
	Bu xüsusiyyətdən yararlanmaq üçün main.rvs adlı fayl yaradmaqla başlayırsınız.


	Linux Terminal 
		> touch main.rvs
		> micro main.rvs

		1 prt "Hello, World!"

		<Ctrl S>

		> ./bin/RevanScript main.rvs
		<interpreter> --- [Run Process] --- <runtime>
		Hello, World!


	faylın içinə micro vəya vim kimi terminal editorlar istifadə edərək faylı aça bilərsiniz.
	faylın içərisinə sadə bir kod yazırsınız.

	main.rvs
	    prt "Hello, World"

	icra etmək üçün ./RevanScript main.rvs yazmaq yetərlidir.

	Kommnet yazmaq üçün ... istifadə etmək yetərlidir.

	... RevanScript (RVS) Programming Language

	RevanScript (RVS) ə gələcək də əlavə edəcəyim imkanlar yaddaşla işləmək olacaq.
	Bunun üçün dinamik tipli dəyişən yaratmaq funksiyanallığı əlavə edəcəm.

	var text = "Hello, World" -> "Dynamic Typing" - Dinamik tipli dəyişən yaratmaq.
	set text = "RevanScript" -> dəyiçənin dəyərini dəyişmək.
	inp text -> klaviyaturadan məlumat oxuyub dəyişə yazmaq.
	out text -> dəyişənin dəyərini ekrana çap etmək funksiyanallığı olacaq.
	cst text -> dəyişəni (Variable) sabit "Constant" elan etmək üçün olacaq.
	del text -> dəyişəni yaddaşdan silmək üçün olacaq.

	Birdə daha çox tip əlavə etməyi düşünürəm.

	RevanScript Data Types -> [String, Integer, Float, Boolean, Binary]
*/


// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

// RevanScript (RVS) Standard Core/Engine Libraries
#include "../include/rvsio.h"
#include "../include/rvsctl.h"
#include "../include/rvsmem.h"
#include "../include/rvsflg.h"
#include "../include/rvsprs.h"
#include "../include/rvstbl.h"
#include "../include/rvsstd.h"
#include "../include/rvserr.h"


// RevanScript (RVS) Variable Create Function
bool var(const char* const code_line, RVSMEM* rvs_memory){
	// RevanScript Standard Variable Parser
	RVSPRS* rvs_parser = rvs_standard_variable(code_line, rvs_memory, true);
	if (!rvs_parser) return false;

	// RevanScript Insert Memory
	if (rvs_memory_insert(rvs_memory, rvs_parser->rvs_buffer) == false){
		rvs_parser_delete(rvs_parser);
		return false;
	}
	
	// Delete (Buffer, Expression, Parser) Memorys
	rvs_parser_delete(rvs_parser);
	return true;
}


// RevanScript (RVS) Set Function
bool set(const char* const code_line, RVSMEM* rvs_memory){
	// Variable Parser
	RVSPRS* rvs_parser = rvs_standard_variable(code_line, rvs_memory, false);
	if (!rvs_parser) return false;

	// RevanScript Set Memory
	if (rvs_memory_set(rvs_memory, rvs_parser->rvs_buffer) == false){
		rvs_parser_delete(rvs_parser);
		return false;
	}

	// Delete Buffer
	rvs_parser_delete(rvs_parser);
	return true;
}


// RevanScript (RVS) Get (Variable Meta Data Information) Function
bool get(const char* const code_line, 
		const RVSMEM* const rvs_memory, 
		const int8_t* const rvs_execution_mode)
{
	// RevanScript Variable Name Parser
	RVSBUF* rvs_buffer = rvs_variable_name_parser(code_line);
	if (!rvs_buffer) return false;

	if (!rvs_variable_name_check(rvs_buffer->variable_name, NULL, false)){
		rvs_buffer_delete(rvs_buffer);
		return false;
	}

	if (rvs_memory_get(rvs_memory, rvs_buffer) == true){
		struct RVSTBLConfig rvs_table_config = {.rows=2, .cols=5, .width=25, .height=1};
		RVSTBL* rvs_table = rvs_table_create(rvs_table_config);
		rvs_table_insert(rvs_table, "Variable Name");
		rvs_table_insert(rvs_table, rvs_buffer->variable_name);
		rvs_table_insert(rvs_table, "Variable Data");
		rvs_table_insert(rvs_table, rvs_buffer->variable_data);
		rvs_table_insert(rvs_table, "Variable Type");

		switch (rvs_buffer->variable_type){
			case RVS_STRING_TYPE:  rvs_table_insert(rvs_table, "String");   break;
			case RVS_INTEGER_TYPE: rvs_table_insert(rvs_table, "Integer");  break;
			case RVS_FLOAT_TYPE:   rvs_table_insert(rvs_table, "Float");    break;
			case RVS_BOOLEAN_TYPE: rvs_table_insert(rvs_table, "Boolean");  break;
			case RVS_BINARY_TYPE:  rvs_table_insert(rvs_table, "Binary");   break;
			case RVS_NULL_TYPE:    rvs_table_insert(rvs_table, "Null");     break;
		}
		
		rvs_table_insert(rvs_table, "Variable Constant");
		rvs_table_insert(rvs_table, (rvs_buffer->variable_const == true) ? "TRUE" : "FALSE");
		rvs_table_insert(rvs_table, "Variable Address");
		rvs_table_insert(rvs_table, rvs_buffer->variable_address);
		rvs_standard_table_output(rvs_table);
		rvs_table_delete(rvs_table);
	}

	else{
		rvs_buffer_delete(rvs_buffer);
		return false;
	}

	rvs_buffer_delete(rvs_buffer);
	return true;
}


// RevanScript (RVS) Output Function
bool out(const char* const code_line, 
		 const RVSMEM* const rvs_memory, 
		 const int8_t* const rvs_execution_mode)
{
	// RevanScript Variable Name Parser
	RVSBUF* rvs_buffer = rvs_variable_name_parser(code_line);
	if (!rvs_buffer) return false;

	// RevanScript Variable Name Check
	if (!rvs_variable_name_check(rvs_buffer->variable_name, NULL, false)){
		rvs_buffer_delete(rvs_buffer);
		return false;
	}

	// RevanScript Output
	if (rvs_memory_get(rvs_memory, rvs_buffer) == true){
		rvs_standard_output(rvs_buffer->variable_data, rvs_execution_mode);
		rvs_buffer_delete(rvs_buffer);
		return true;
	}

	else{
		rvs_buffer_delete(rvs_buffer);
		return false;
	}

	// RevanScript Buffer Delete
	rvs_buffer_delete(rvs_buffer);
	return true;
}


// RevanScript (RVS) Input Function
bool inp(const char* const code_line, RVSMEM* rvs_memory, const int8_t* const rvs_execution_mode){
	// RevanScript Variable Name Parser
	RVSBUF* rvs_buffer = rvs_variable_name_parser(code_line);
	if (!rvs_buffer) return false;

	// Variable Name Check
	if (rvs_variable_name_check(rvs_buffer->variable_name, rvs_memory, false) == false){
		rvs_buffer_delete(rvs_buffer);
		return false;
	}
	
	// RevanScript Standard Input
	rvs_standard_input(rvs_buffer->variable_data, rvs_execution_mode);
	rvs_buffer->variable_type = RVS_STRING_TYPE;

	// RevanScript Set Memory
	if (rvs_memory_set(rvs_memory, rvs_buffer) == false){
		rvs_buffer_delete(rvs_buffer);
		return false;
	}
	
	// Delete Buffer
	rvs_buffer_delete(rvs_buffer);
	return true;
}


// RevanScript (RVS) Constant Function
bool cst(const char* const code_line, RVSMEM* rvs_memory){
	// RevanScript Variable Name Parser
	RVSBUF* rvs_buffer = rvs_variable_name_parser(code_line);
	if (!rvs_buffer) return false;

	// RevanScript Variable Name Check
	if (rvs_variable_name_check(rvs_buffer->variable_name, rvs_memory, false) == false){
		rvs_buffer_delete(rvs_buffer);
		return false;
	}

	// RevanScript Memory Variable Constant Define
	if (rvs_memory_const(rvs_memory, rvs_buffer) == false){
		rvs_buffer_delete(rvs_buffer);
		return false;
	}

	// Delete Buffer
	rvs_buffer_delete(rvs_buffer);
	return true;
}


// RevanScript (RVS) Delete Function
bool del(const char* const code_line, RVSMEM* rvs_memory){
	// RevanScript Variable Name Parser
	RVSBUF* rvs_buffer = rvs_variable_name_parser(code_line);
	if (!rvs_buffer) return false;

	// RevanScript Variable Name Check
	if (rvs_variable_name_check(rvs_buffer->variable_name, rvs_memory, false) == false){
		rvs_buffer_delete(rvs_buffer);
		return false;
	}

	// RevanScript Variable Clear Memory
	if (rvs_memory_clear(rvs_memory, rvs_buffer) == false){
		rvs_buffer_delete(rvs_buffer);
		return false;
	}

	// RevanScript Buffer Delete
	rvs_buffer_delete(rvs_buffer);
	return true;
}


// RevanScript (RVS) Print Function
bool prt(const char* const code_line, const int8_t* const rvs_execution_mode){
	RVS_DIRECT_PARSER* rvs_direct_parser = rvs_direct_data_parser(code_line);
	if (!rvs_direct_parser) return false;
	if (rvs_direct_data_check(rvs_direct_parser->rvs_direct_buffer, rvs_direct_parser->rvs_direct_logic) == false){
		free(rvs_direct_parser);
		return false;
	}
	rvs_standard_output(rvs_direct_parser->rvs_direct_buffer->direct_data, rvs_execution_mode);
	return true;
}


// RevanScript (RVS) Keyword Search Function
bool keys(const char* const code_line, RVSMEM* rvs_memory, bool* end_process_check, const int8_t const* rvs_execution_mode){
	if (strncmp(code_line, "...", 3) == 0){
		return true;
	}

	else if (strncmp(code_line, "var ", 4) == 0){
		if (!var(code_line + 4, rvs_memory)) return false;
		return true;
	}

	else if (strncmp(code_line, "set ", 4) == 0){
		if (!set(code_line + 4, rvs_memory)) return false;
		return true;
	}

	else if (strncmp(code_line, "get ", 4) == 0){
		if (!get(code_line + 4, rvs_memory, rvs_execution_mode)) return false;
		return true;
	}

	else if (strncmp(code_line, "out ", 4) == 0){
		if (!out(code_line + 4, rvs_memory, rvs_execution_mode)) return false;
		return true;
	}

	else if (strncmp(code_line, "inp ", 4) == 0){
		if (!inp(code_line + 4, rvs_memory, rvs_execution_mode)) return false;
		return true;
	}

	else if (strncmp(code_line, "cst ", 4) == 0){
		if (!cst(code_line + 4, rvs_memory)) return false;
		return true;
	}

	else if (strncmp(code_line, "del ", 4) == 0){
		if (!del(code_line + 4, rvs_memory)) return false;
		return true;
	}

	else if (strncmp(code_line, "prt ", 4) == 0){
		if (!prt(code_line + 4, rvs_execution_mode)) return false;
		return true;
	}

	else if (strncmp(code_line, "end", 3) == 0){
		*end_process_check = true;
		return true;
	}
	
	else{
		char* keyword_name = (char*) malloc(sizeof(char) * 5);
		if (!keyword_name) return false;
		strncpy(keyword_name, code_line, 4);
		keyword_name[strlen(keyword_name) - 1] = '\0';
		rvs_standard_error(RVS_KEYWORD_NAME_ERROR, keyword_name);
		free(keyword_name);
		return false;
	}
}


// RevanScript (RVS) Read Eval Print Loop (REPL) Function
bool repl(RVSMEM* rvs_memory){
	int8_t rvs_execution_mode = RVS_REPL_MODE;

	char* code_line = (char*) malloc(sizeof(char) * 2049);
	if (!code_line) return false;

	bool end_process_check = false;

	printf("\n%s%s%s\n\n", RVS_COLOR_YELLOW_ESCAPE_CODE, RVS_REPL_MESSAGE, RVS_COLOR_RESET_ESCAPE_CODE);

	while (true){
		printf("%s>>> %s", RVS_COLOR_MAGENTA_ESCAPE_CODE, RVS_COLOR_CYAN_ESCAPE_CODE);

		if (!fgets(code_line, 2048, stdin)){
			free(code_line);
			return false;
		}

		if (code_line[0] == '\0' || code_line[0] == '\n'){
			continue;
		}

		else if (!keys(code_line, rvs_memory, &end_process_check, &rvs_execution_mode)){
			free(code_line);
			return false;
		}

		else if (end_process_check == true){
			free(code_line);
			return true;
		}
	}

	free(code_line);
	return true;
}


// RevanScript (RVS) File Reader
bool file(const char* const file_name, RVSMEM* rvs_memory){
	int8_t rvs_execution_mode = RVS_FILE_MODE;
	FILE* file_open = fopen(file_name, "r");

	if (!file_open){
		rvs_standard_error(RVS_FILE_PATH_OR_NAME_ERROR, NULL);
		return false;
	}

	else{
		char* code_line = (char*) malloc(sizeof(char) * 2049);
		if (!code_line){
			fclose(file_open);
			return false;
		}

		bool end_process_check = false;

		while (true){
			if (!fgets(code_line, 2048, file_open)){
				free(code_line);
				fclose(file_open);
				return true;
			}

			else if (code_line[0] == '\0' || code_line[0] == '\n'){
				continue;
			}

			else if (!keys(code_line, rvs_memory, &end_process_check, &rvs_execution_mode)){
				free(code_line);
				fclose(file_open);
				return false;
			}

			else if (end_process_check == true){
				free(code_line);
				fclose(file_open);
				return true;
			}
		}

		free(code_line);
		fclose(file_open);
		return true;
	}
}


// RevanScript Main Function
int main(const int argc, const char** const argv){

	// RevanScript Global Memory
	RVSMEM* rvs_global_memory = rvs_memory_create();
	if (!rvs_global_memory) return 1;

	// REPL mode
	if (argc == 1){
		if (!repl(rvs_global_memory)){
			rvs_memory_delete(rvs_global_memory);
			return 1;
		}

		else{
			rvs_memory_delete(rvs_global_memory);
			return 0;
		}
	}
	
	// File mode & Flag mode
	else if (argc == 2){
		uint8_t flag_title_check = rvs_flag_title_check(argv[1]);

		if (flag_title_check == 0){
			return 0;
		}

		else if (flag_title_check == 2 && rvs_file_type_check(argv[1] + (strlen(argv[1]) - 4)) == true){

			if (!file(argv[1], rvs_global_memory)){
				rvs_memory_delete(rvs_global_memory);
				return 1;
			}

			else{
				rvs_memory_delete(rvs_global_memory);
				return 0;
			}
		}

		else{
			rvs_memory_delete(rvs_global_memory);
			return 1;
		}
	}

	else{
		rvs_memory_delete(rvs_global_memory);
		return 1;
	}
}
