#include <stdio.h>
#include <stddef.h>

#include "rvsio.h"


void rvs_standard_output(const char* const data){
    size_t i = 0;
    printf("%s", RVS_COLOR_GREEN);
    while (data[i] != '\0'){

        if (data[i] == '\\' && data[i + 1] == 'n'){
            putchar('\n');
            i += 2;
        }

        else if (data[i] == '\\' && data[i + 1] == 't'){
            putchar('\t');
            i += 2;
        }

        else if (data[i] == '\\' && data[i + 1] == 'a'){
            putchar('\a');
            i += 2;
        }

        else{
            putchar(data[i]);
            i++;
        }
    }
    printf("%s", RVS_COLOR_RESET);
    putchar('\n');
}


void rvs_standard_error(const char* const type, const char* const notified){
    if (!notified){
        fprintf(stderr, type , RVS_COLOR_RED, RVS_COLOR_RESET);
    }

    else{
        fprintf(stderr, type , RVS_COLOR_RED, notified, RVS_COLOR_RESET);
    }
}

