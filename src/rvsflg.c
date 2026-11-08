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


// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

// RevanScript (RVS) Core / Engine Libraries
#include "../includes/rvsio.h"
#include "../includes/rvserr.h"
#include "../includes/rvsdef.h"
#include "../includes/rvsflg.h"
#include "../includes/rvscol.h"

// RevanScript (RVS) Subsystem Libraries
#include "../includes/games/menu.h"


void rvs_flag_version(void){
    printf("%s\n\t\tRevanScript (RVS) version %.1f%s", 
        RVS_COLOR_YELLOW_ESCAPE_CODE, RVS_VERSION, RVS_COLOR_RESET_ESCAPE_CODE);
    #if __RVS_GCC_COMPILER_DEFINE__
        printf(
            "%s\n\tGNU Compiler Collections (GCC) version %d.%d.%d%s\n\n", 
            RVS_COLOR_YELLOW_ESCAPE_CODE, 
            __GNUC__, 
            __GNUC_MINOR__, 
            __GNUC_PATCHLEVEL__, 
            RVS_COLOR_RESET_ESCAPE_CODE
        );
    #elif __RVS_CLANG_COMPILER_DEFINE__
        printf(
            "%s\n\tC/C++ Compiler (Clang/LLVM) version %d.%d.%d%s\n\n",
            RVS_COLOR_YELLOW_ESCAPE_CODE,
            __clang_major__,
            __clang_minor__,
            __clang_patchlevel__,
            RVS_COLOR_RESET_ESCAPE_CODE
        );
    #endif
    printf("\n%s ____                              ____               _         _   \n",
        RVS_COLOR_CYAN_ESCAPE_CODE);
    printf("|  _ \\   ___ __   __  __ _  _ __  / ___|   ___  _ __ (_) _ __  | |_\n");
    printf("| |_) | / _ \\\\ \\ / / / _` || '_ \\ \\___ \\  / __|| '__|| || '_ \\ | __|\n");
    printf("|  _ < |  __/ \\ V / | (_| || | | | ___) || (__ | |   | || |_) || |_ \n");
    printf("|_| \\_\\ \\___|  \\_/   \\__,_||_| |_||____/  \\___||_|   |_|| .__/  \\__|\n");
    printf("                                                        |_|         %s\n\n", 
        RVS_COLOR_RESET_ESCAPE_CODE);
}

void rvs_flag_about(void){
    printf("%s\n\t\t\t\tRevanScript (RVS) Programming Language%s\n", RVS_COLOR_YELLOW_ESCAPE_CODE, RVS_COLOR_RESET_ESCAPE_CODE);
    printf("\n\t%sThe RevanScript (RVS) programming language was created in 2026 by a programmer named Revan Babayev.\n\tThis programming language is notable for its exterely simple code writing and minimal runtime environment.\n\n%s", RVS_COLOR_CYAN_ESCAPE_CODE, RVS_COLOR_RESET_ESCAPE_CODE);
}

bool rvs_flag_documentation(void){
    if (!system("xdg-open https://rvcodes9.github.io/RevanScript-RVS-Documentation-Site/")){
        return false;
    }
    return true;
}

bool rvs_flag_games(void){
    if (rvs_games_menu_init() == false) return false;
    return true;
}

uint8_t rvs_flag_title_check(const char* const flag_title){
    if (strcmp(flag_title, "-V") == 0 || strcmp(flag_title, "--version") == 0){
        rvs_flag_version();
        return 0;
    }

    else if (strcmp(flag_title, "-A") == 0 || strcmp(flag_title, "--about") == 0){
        rvs_flag_about();
        return 0;
    }

    else if (strcmp(flag_title, "-D") == 0 || strcmp(flag_title, "--documentation") == 0){
        if (!rvs_flag_documentation()) return 1;
        return 0;
    }

    else if (strcmp(flag_title, "-G") == 0 || strcmp(flag_title, "--games") == 0){
        if (!rvs_flag_games()) return 1;
        return 0;
    }

    else{
        if (flag_title[0] == '-' || strncmp(flag_title, "--", 2) == 0){
            rvs_standard_error(RVS_FLAG_TITLE_ERROR, flag_title);
            return 1;
        }

        else{
            return 2;
        }
    }
}

