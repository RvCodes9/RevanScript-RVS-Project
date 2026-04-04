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
	C Source Codes
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

	RevanScript kısa adıyla RVS də "REPL MODE" dan əlavə "FILE MODE" da var.
	Bu xüsusiyyətdən yararlanmaq üçün main.rvs adlı fayl yaradmaqla başlayırsınız.

	Linux Terminal 
		> touch main.rvs
		> micro main.rvs

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
		typedef olunmuş C məlumat tipləri məslən size_t kimi tiplər.
		Sabitlər (const) bilmək lazımdır.
		Şərtlər və dövrlər də çox önəmlidir.
		Ən önəmlisi göstəricilər (Pointer) ləri ən azından orta səviyyədə bilmək.
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
#include <stdbool.h>

// RevanScript (RVS) Standard Engine Librarys
#include "rvsio.h"
#include "rvsctl.h"


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
bool keys(const char* const code_line){
	if (strncmp(code_line, "...", 3) == 0){
		return true;
	}

	else if (strncmp(code_line, "prt ", 4) == 0){
		if (!prt(code_line + 4)) return false;
		return true;
	}

	else if (strncmp(code_line, "end", 3) == 0){
		exit(0);
		return true;
	}
	
	else{
		char* keyword_name = (char*) malloc(sizeof(char) * 5);
		if (!keyword_name) return false;
		strncpy(keyword_name, code_line, 4);
		rvs_standard_error(RVS_KEYWORD_NAME_ERROR, keyword_name);
		free(keyword_name);
		return false;
	}
}


// RevanScript (RVS) Read Eval Print Loop (REPL) Function
bool repl(void){
	char* code_line = (char*) malloc(sizeof(char) * 2049);
	if (!code_line) return false;

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

		else if (!keys(code_line)){
			free(code_line);
			return false;
		}
	}

	free(code_line);
	return true;
}


// RevanScript (RVS) File Reader
bool file(const char* const file_name){
	FILE* file_open = fopen(file_name, "r");

	if (!file){
		rvs_standard_error(RVS_FILE_PATH_OR_NAME_ERROR, NULL);
		return false;
	}

	else{
		char* code_line = (char*) malloc(sizeof(char) * 2049);

		while (!feof(file_open)){
			if (!fgets(code_line, 2048, file_open)){
				free(code_line);
				return false;
			}

			else if (code_line[0] == '\0' || code_line[0] == '\n'){
				continue;
			}

			else if (!keys(code_line)){
				free(code_line);
				return false;
			}
		}

		fclose(file_open);
		free(code_line);
		return true;
	}
}


// RevanScript Main Function
int main(const int argc, const char** const argv){

	// REPL mode
	if (argc == 1){
		if (!repl()){
			return 1;
		}
	}
	
	// File mode
	else if (argc == 2){
		if (rvs_file_type_check(argv[1] + (strlen(argv[1]) - 4)) == true){

			if (!file(argv[1])){
				return 1;
			}

			else{
				return 0;
			}
		}

		else{
			return 1;
		}
	}

	else{
		return 1;
	}
}
