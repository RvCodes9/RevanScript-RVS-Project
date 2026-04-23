/*
	© 2026 Rəvan Babayev. All rights reserved.
	--------------------------------------------
	License : GPLv3 / Open Source Project
	--------------------------------------------
	RvCodes9 -- GitHub / YouTube -- Platform
	--------------------------------------------
	RevanScript (RVS) Programming Language
	RevanScript (RVS) Interpreter Program (Direct Execution Model)
	--------------------------------------------
	C Source Codes  |  C1999 / C99 Standard | Compiler -> GNU Compiler Collection (GCC)
	automatic compile file -> executable.sh
	--------------------------------------------
	Cmake Compile Support
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

	String, Integer, Float, Boolean, Chracter, Object, Binary

	dəstək verə bilmək üçün tələblər : ---

	C proqramlaşdırma dilini bilmək lazım gələcək.
	    Dəyişənlər və dəyərlər.
		Məlumat tipləri (char, int, float, double, unsigned, signed) 
		typedef olunmuş C məlumat tipləri məslən size_t, int8_t, uint8_t (stdint.h, stddef.h) vs s.
		Sabitlər (const) bilçox önəmlidir.
		Ən önəmlisi göstəricilmək lazımdır.
		Şərtlər və dövrlər də ər (Pointer) ləri ən azından orta səviyyədə bilmək.
		Funksiyalar (Function) lar və Function Pointerlə işləmək bacarığı olmalıdır.
		Compile Time əməliyyatları bilmək önəmlidir. (#include, #define, #ifdef, #ifndef, #endif)
		Struct lar və Union kimi detalları bilmək lazım gələcək irəlidə.
		Kitabxana biliyədə mütləqdir C nin Standard Library lərin tanımaq lazım gələcək.
		Məsələn (stdio.h, stdlib.h, stddef.h, stdbool.h, string.h, stdint.h) kimi kitabxanalar çox önəmlidir.
		Sadə alqoritlərdən baş açmaq önəmlir və Array, Matrix kimi data sturukturlar önəm daşıyır.

	Linux Terminal biliyi önəmlidir.
	GitHub və Git biliyidə önəmlidir.
*/


// C Standard Librarys
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

// RevanScript (RVS) Standard Core/Engine Librarys
#include "../include/rvsio.h"
#include "../include/rvsctl.h"
#include "../include/rvsmem.h"
#include "../include/rvsbuf.h"
#include "../include/rvsflg.h"


// RevanScript (RVS) Variable Create Function
bool var(const char* const code_line, RVSMEM* rvs_global_memory){
	RVSBUF* rvs_variable_buffer = rvs_buffer_create();
	if (!rvs_variable_buffer) return false;

	RVSLOGIC rvs_variable_logic;
	rvs_variable_logic.assignment_operation_check = false;
	rvs_variable_logic.string_literal_check = false;
	rvs_variable_logic.binary_start_operation_check = false;

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
	if (rvs_variable_name_check(rvs_variable_buffer, rvs_global_memory, true) == false){
		rvs_buffer_delete(rvs_variable_buffer);
		return false;
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
			return false;
		}
	}

	// RevanScript Insert Memory
	if (rvs_memory_insert(rvs_global_memory, rvs_variable_buffer) == false){
		rvs_buffer_delete(rvs_variable_buffer);
		return false;
	}

	rvs_buffer_delete(rvs_variable_buffer);
	return true;
}


// RevanScript (RVS) Output Function
bool out(const char* const code_line, const RVSMEM* const rvs_global_memory){
	RVSBUF* variable_buffer = rvs_buffer_create();
	if (!variable_buffer) return false;

	for (size_t i = 0; code_line[i] != '\n' && code_line[i] != '\0'; i++){
		if (code_line[i] == ' ') continue;
		variable_buffer->variable_name[variable_buffer->variable_name_counter++] = code_line[i];
	}

	variable_buffer->variable_name[variable_buffer->variable_name_counter] = '\0';
	if (!rvs_variable_name_check(variable_buffer, NULL, false)) return false;

	char* output_buffer = rvs_memory_get(rvs_global_memory, variable_buffer);

	if (output_buffer != NULL){
		rvs_standard_output(output_buffer);
		rvs_buffer_delete(variable_buffer);
		return true;
	}

	else{
		rvs_standard_error(RVS_VARIABLE_NO_NAME_ERROR, NULL);
		rvs_buffer_delete(variable_buffer);
		return false;
	}

	rvs_buffer_delete(variable_buffer);
	return true;
}


// RevanScript (RVS) Print Function
bool prt(const char* const code_line){
	char* buffer = (char*) malloc(sizeof(char) * 2048);
	if (!buffer) return false;
	size_t buffer_counter = 0;

	bool string_literal_check = false;

	for (size_t i = 0; code_line[i] != '\n' && code_line[i] != '\0'; i++){

		if (code_line[i] == '\"'){
			if (string_literal_check == false){
				string_literal_check = true;
				continue;
			}

			else{
				string_literal_check = false;
			}
		}

		else if (string_literal_check == true){
			if (code_line[i] == '\\' && code_line[i + 1] == '\\'){
				buffer[buffer_counter++] = '\\';
				++i;
			}

			else if (code_line[i] == '\\' && code_line[i + 1] == '\"'){
				buffer[buffer_counter++] = '\"';
				++i;
			}

			else{
				buffer[buffer_counter++] = code_line[i];
			}
		}
	}

	if (string_literal_check == true){
		rvs_standard_error(RVS_STRING_LITERAL_ERROR, NULL);
		free(buffer);
		return false;
	}

	buffer[buffer_counter] = '\0';
	rvs_standard_output(buffer);
	free(buffer);

	return true;
}


// RevanScript (RVS) Keyword Search Function
bool keys(const char* const code_line, RVSMEM* rvs_global_memory, bool* end_process_check){
	if (strncmp(code_line, "...", 3) == 0){
		return true;
	}

	else if (strncmp(code_line, "var ", 4) == 0){
		if (!var(code_line + 4, rvs_global_memory)) return false;
		return true;
	}

	else if (strncmp(code_line, "out ", 4) == 0){
		if (!out(code_line + 4, rvs_global_memory)) return false;
		return true;
	}

	else if (strncmp(code_line, "prt ", 4) == 0){
		if (!prt(code_line + 4)) return false;
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
bool repl(RVSMEM* rvs_global_memory){
	char* code_line = (char*) malloc(sizeof(char) * 2049);
	if (!code_line) return false;

	bool end_process_check = false;

	printf("\n%s%s%s\n\n", RVS_COLOR_YELLOW, RVS_REPL_MESSAGE, RVS_COLOR_RESET);

	while (true){
		printf("%s>>> %s", RVS_COLOR_MAGENTA, RVS_COLOR_CYAN);

		if (!fgets(code_line, 2048, stdin)){
			free(code_line);
			return false;
		}

		if (code_line[0] == '\0' || code_line[0] == '\n'){
			continue;
		}

		else if (!keys(code_line, rvs_global_memory, &end_process_check)){
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
bool file(const char* const file_name, RVSMEM* rvs_global_memory){
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

			else if (!keys(code_line, rvs_global_memory, &end_process_check)){
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
