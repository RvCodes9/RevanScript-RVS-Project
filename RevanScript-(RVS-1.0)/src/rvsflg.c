#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../include/rvsio.h"
#include "../include/rvsflg.h"


void rvs_flag_version(void){
    printf("%s\n\tRevanScript (RVS) version %.1f%s", 
        RVS_COLOR_YELLOW, RVS_VERSION,RVS_COLOR_RESET);
    #ifdef __GNUC__
        printf("%s\n\tGNU Compiler Collections (GCC) version %d.%d.%d%s\n\n", 
            RVS_COLOR_YELLOW, __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__, RVS_COLOR_RESET);
    #endif
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

