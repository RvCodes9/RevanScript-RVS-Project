#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "../include/rvsio.h"


void rvs_standard_output(const char* const data){
    size_t data_length = strlen(data);
    size_t i = 0;
    printf("%s", RVS_COLOR_GREEN);
    while (data[i] != '\0'){

        // Classic Escape Sequances

        // New Line (\n)
        if (data_length >= i + 2 && data[i] == '\\' && data[i + 1] == 'n'){
            putchar('\n');
            i += 2;
        }

        // Tab Line (\t)
        else if (data_length >= i + 2 && data[i] == '\\' && data[i + 1] == 't'){
            putchar('\t');
            i += 2;
        }

        // Beep sound (\a)
        else if (data_length >= i + 2 && data[i] == '\\' && data[i + 1] == 'a'){
            putchar('\a');
            i += 2;
        }

        // Backspace (\b)
        else if (data_length >= i + 3 && data[i + 1] == '\\' && data[i + 2] == 'b'){
            i += 3;
        }

        // Display Clear (\cl)
        else if (data_length >= i + 3 && data[i] == '\\' && data[i + 1] == 'c' && data[i + 2] == 'l'){
            if (!system("clear")){
                return;
            }
            i += 3;
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

        // Emoji Escape Sequances
        else if (data_length >= i + 3 && data[i] == '\\' && data[i + 1] == 'e'){
            switch (data[i + 2]){
                case '0': printf("😀"); i += 3; break;
                case '1': printf("😄"); i += 3; break;
                case '2': printf("😁"); i += 3; break;
                case '3': printf("😅"); i += 3; break;
                case '4': printf("😂"); i += 3; break;
                case '5': printf("😍"); i += 3; break;
                case '6': printf("🤩"); i += 3; break;
                case '7': printf("🤔"); i += 3; break;
                case '8': printf("😵"); i += 3; break;
                case '9': printf("🥱"); i += 3; break;
            }
        }

        // Output Character
        else{
            putchar(data[i]);
            i++;
        }
    }
    printf("%s", RVS_COLOR_RESET);
    putchar('\n');
}


void rvs_standard_debug(bool type, const char* const message){
    if (type == true){
        printf("%s[DEBUG] : %s%s\n", RVS_COLOR_GREEN, message, RVS_COLOR_RESET);
    }

    else{
        printf("%s[DEBUG] : %s%s\n", RVS_COLOR_YELLOW, message, RVS_COLOR_RESET);
    }
}


void rvs_standard_error(const char* const type, const char* const notified){
    if (!notified){
        fprintf(stderr, type , RVS_COLOR_RED, RVS_COLOR_RESET);
    }

    else{
        fprintf(stderr, type , RVS_COLOR_RED, notified, RVS_COLOR_RESET);
    }
}

