#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "../include/rvsio.h"
#include "../include/rvsflg.h"


void rvs_flag_version(void){
    printf("%s\n\t\tRevanScript (RVS) version %.1f%s", 
        RVS_COLOR_YELLOW, RVS_VERSION,RVS_COLOR_RESET);
    #ifdef __GNUC__
        printf("%s\n\tGNU Compiler Collections (GCC) version %d.%d.%d%s\n\n", 
            RVS_COLOR_YELLOW, __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__, RVS_COLOR_RESET);
    #endif
    printf("\n%s ____                              ____               _         _   \n",
        RVS_COLOR_CYAN);
    printf("|  _ \\   ___ __   __  __ _  _ __  / ___|   ___  _ __ (_) _ __  | |_\n");
    printf("| |_) | / _ \\\\ \\ / / / _` || '_ \\ \\___ \\  / __|| '__|| || '_ \\ | __|\n");
    printf("|  _ < |  __/ \\ V / | (_| || | | | ___) || (__ | |   | || |_) || |_ \n");
    printf("|_| \\_\\ \\___|  \\_/   \\__,_||_| |_||____/  \\___||_|   |_|| .__/  \\__|\n");
    printf("                                                        |_|         %s\n\n", 
        RVS_COLOR_RESET);
}


void rvs_flag_about(void){
    printf("%s\n\t\t\t\tRevanScript (RVS) Programming Language%s\n", RVS_COLOR_YELLOW, RVS_COLOR_RESET);
    printf("\n\t%sThe RevanScript (RVS) programming language was created in 2026 by a programmer named Revan Babayev.\n\tThis programming language is notable for its exterely simple code writing and minimal runtime environment.\n\n%s", RVS_COLOR_CYAN, RVS_COLOR_RESET);
}


bool rvs_flag_documentation(void){
    if (!system("xdg-open https://rvcodes9.github.io/RevanScript-RVS-Documetation-Site/")){
        return false;
    }
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

