// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

// RevanScript (RVS) Core / Engine Libraries
#include "../include/rvsio.h"
#include "../include/rvserr.h"
#include "../include/rvsflg.h"


void rvs_flag_version(void){
    printf("%s\n\t\tRevanScript (RVS) version %.1f%s", 
        RVS_COLOR_YELLOW_ESCAPE_CODE, RVS_VERSION, RVS_COLOR_RESET_ESCAPE_CODE);
    #if defined( __GNUC__) && !defined(__clang__)
        printf(
            "%s\n\tGNU Compiler Collections (GCC) version %d.%d.%d%s\n\n", 
            RVS_COLOR_YELLOW_ESCAPE_CODE, 
            __GNUC__, 
            __GNUC_MINOR__, 
            __GNUC_PATCHLEVEL__, 
            RVS_COLOR_RESET_ESCAPE_CODE
        );
    #elif defined(__clang__)
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
    if (system("xdg-open https://rvcodes9.github.io/RevanScript-RVS-Documentation-Site/") != 0){
        return false;
    }
    return true;
}


void rvs_flag_help(void){
    printf("%s", RVS_COLOR_MAGENTA_ESCAPE_CODE);
    puts("\n\tRevanScript (RVS) Flags\n");
    printf("%s", RVS_COLOR_YELLOW_ESCAPE_CODE);
    puts("\t[--version or -V]\n");
    puts("\t[--about or -A]\n");
    puts("\t[--documentation or -D]\n");
    puts("\t[--help or -H]\n");
    printf("%s", RVS_COLOR_RESET_ESCAPE_CODE);
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

    else if (strcmp(flag_title, "-H") == 0 || strcmp(flag_title, "--help") == 0){
        rvs_flag_help();
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

