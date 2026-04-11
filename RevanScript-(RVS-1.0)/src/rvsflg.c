#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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


bool rvs_flag_title_check(const char* const flag_title){
    if (strcmp(flag_title, "-V") == 0 || strcmp(flag_title, "--version") == 0){
        rvs_flag_version();
        return true;
    }

    else if (strcmp(flag_title, "-A") == 0 || strcmp(flag_title, "--about") == 0){
        return true;
    }

    else{
        return false;
    }
}

