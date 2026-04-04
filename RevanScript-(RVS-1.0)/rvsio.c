#include <stdio.h>
#include <stddef.h>

#include "rvsio.h"


void rvs_standard_output(const char* const data){
    size_t i = 0;
    printf("%s", RVS_COLOR_GREEN);
    while (data[i] != '\0'){

        // Classic Escape Sequances
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
        
        // Color Escape Sequances
        else if (data[i] == '\\' && data[i + 1] == 'c'){
            switch (data[i + 2]){
                case '0': 
                    printf("%s", RVS_COLOR_RESET); 
                    break;
                case '1':
                    printf("%s", RVS_COLOR_BLACK); 
                    break;
                case '2':
                    printf("%s", RVS_COLOR_RED); 
                    break;
                case '3':
                    printf("%s", RVS_COLOR_GREEN); 
                    break;
                case '4':
                    printf("%s", RVS_COLOR_YELLOW); 
                    break;
                case '5':
                    printf("%s", RVS_COLOR_BLUE); 
                    break;
                case '6':
                    printf("%s", RVS_COLOR_MAGENTA); 
                    break;
                case '7':
                    printf("%s", RVS_COLOR_CYAN); 
                    break;
                case '8':
                    printf("%s", RVS_COLOR_WHITE); 
                    break;
            }

            i += 3;
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

