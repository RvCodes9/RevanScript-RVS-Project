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
	C Source Codes  |  C1999 / C99 Standard | Compiler -> GNU Compiler Collection (GCC) and Clang
	--------------------------------------------
	automatic gcc compile file -> shell/executable-gcc.sh
	automatic clang compile file -> shell/executable-clang.sh
	automatic mingw-gcc compile file -> shell/executable-mingw-gcc.sh
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

	var text = "Hello, World" -> "Dynamic Typing" (Mutable) - Dinamik tipli dəyişən yaratmaq.
	let ntext = "Star" -> "Dynamic Typing" (Immutable) - Dinamik tipli deyishen yaratmaq.
	set text = "RevanScript" -> dəyiçənin dəyərini dəyişmək.
	inp text -> klaviyaturadan məlumat oxuyub dəyişə yazmaq.
	out text -> dəyişənin dəyərini ekrana çap etmək funksiyanallığı olacaq.
	cst text -> dəyişəni (Variable) sabit "Constant" elan etmək üçün olacaq.
	del text -> dəyişəni yaddaşdan silmək üçün olacaq.

	Birdə daha çox tip əlavə etməyi düşünürəm.

	RevanScript Data Types -> [String, Integer, Float, Boolean, Null]
	RevanScript Data Structure Types -> [Box, Map]

	[Box == Dynamic Array]
	[Map == Hash Map]
*/


// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

// RevanScript (RVS) Standard Core/Engine Libraries
#include "../includes/rvsio.h"
#include "../includes/rvsctl.h"
#include "../includes/rvsmem.h"
#include "../includes/rvsflg.h"
#include "../includes/rvskey.h"
#include "../includes/rvserr.h"
#include "../includes/rvscol.h"


// RevanScript (RVS) Windows Application Programming Interface (API) Library
#ifdef __RVS_WINDOWS_OS_DEFINE__
	#include "../include/rvswin.h"
#endif


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

	// Windows Support (Console)
	#ifdef __RVS_WINDOWS_OS_DEFINE__
		rvs_windows_console_init();
	#endif

	// Random Value Generate
	srand(time(NULL));

	// RevanScript Global Memory
	RVSMEM* rvs_memory = rvs_memory_create();
	if (!rvs_memory) return 1;

	// REPL mode
	if (argc == 1){
		if (!repl(rvs_memory)){
			rvs_memory_delete(rvs_memory);
			return 1;
		}

		else{
			rvs_memory_delete(rvs_memory);
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
			if (!file(argv[1], rvs_memory)){
				rvs_memory_delete(rvs_memory);
				return 1;
			}

			else{
				rvs_memory_delete(rvs_memory);
				return 0;
			}
		}

		else{
			rvs_memory_delete(rvs_memory);
			return 1;
		}
	}

	else{
		rvs_memory_delete(rvs_memory);
		return 1;
	}
}
