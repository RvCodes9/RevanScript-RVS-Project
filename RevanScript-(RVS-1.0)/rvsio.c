#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "rvsio.h"


void rvs_standard_output(const char* const data){
    size_t data_length = strlen(data);
    size_t i = 0;
    printf("%s", RVS_COLOR_GREEN);
    while (data[i] != '\0'){

        // Classic Escape Sequances
        if (data_length >= i + 2 && data[i] == '\\' && data[i + 1] == 'n'){
            putchar('\n');
            i += 2;
        }

        else if (data_length >= i + 2 && data[i] == '\\' && data[i + 1] == 't'){
            putchar('\t');
            i += 2;
        }

        else if (data_length >= i + 2 && data[i] == '\\' && data[i + 1] == 'a'){
            putchar('\a');
            i += 2;
        }
        
        // Color Escape Sequances
        else if (data_length >= i + 3 && data[i] == '\\' && data[i + 1] == 'c'){
            switch (data[i + 2]){
                case '0': printf("%s", RVS_COLOR_RESET);   i += 3; break;
                case '1': printf("%s", RVS_COLOR_BLACK);   i += 3; break;
                case '2': printf("%s", RVS_COLOR_RED);     i += 3; break;
                case '3': printf("%s", RVS_COLOR_GREEN);   i += 3; break;
                case '4': printf("%s", RVS_COLOR_YELLOW);  i += 3; break;
                case '5': printf("%s", RVS_COLOR_BLUE);    i += 3; break;
                case '6': printf("%s", RVS_COLOR_MAGENTA); i += 3; break;
                case '7': printf("%s", RVS_COLOR_CYAN);    i += 3; break;
                case '8': printf("%s", RVS_COLOR_WHITE);   i += 3; break;
            }
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

