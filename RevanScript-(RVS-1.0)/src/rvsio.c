// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>


// RevanScript (RVS) Core / Engine Libraries
#include "../include/rvsio.h"
#include "../include/rvstbl.h"


// RevanScript Standard Output Function
void rvs_standard_output(const RVSIOBUF* const data, const int8_t* const rvs_execution_mode){
    size_t data_length = strlen(data);
    size_t i = 0;
    printf("%s", RVS_COLOR_GREEN_ESCAPE_CODE);
    while (data[i] != '\0'){

        // Time Escape Sequance
        if (data_length >= i + 3 && data[i] == '\\' && data[i + 1] == 't' && data[i + 2] == 'm'){
            time_t current_time = time(NULL);
            struct tm* local_time = localtime(&current_time);
            printf("%02d:%02d:%02d", local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
            i += 3;
        }

        // Date Escape Sequance
        else if (data_length >= i + 3 && data[i] == '\\' && data[i + 1] == 'd' && data[i + 2] == 't'){
            time_t current_date = time(NULL);
            struct tm* local_date = localtime(&current_date);
            printf("%02d:%02d:%02d", local_date->tm_mday, local_date->tm_mon + 1, local_date->tm_year + 1900);
            i += 3;
        } 

        // Classic Escape Sequances

        // New Line (\n)
        else if (data_length >= i + 2 && data[i] == '\\' && data[i + 1] == 'n'){
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
                case '0': printf("%s", RVS_COLOR_RESET_ESCAPE_CODE);   i += 3; break;
                case '1': printf("%s", RVS_COLOR_BLACK_ESCAPE_CODE);   i += 3; break;
                case '2': printf("%s", RVS_COLOR_RED_ESCAPE_CODE);     i += 3; break;
                case '3': printf("%s", RVS_COLOR_GREEN_ESCAPE_CODE);   i += 3; break;
                case '4': printf("%s", RVS_COLOR_YELLOW_ESCAPE_CODE);  i += 3; break;
                case '5': printf("%s", RVS_COLOR_BLUE_ESCAPE_CODE);    i += 3; break;
                case '6': printf("%s", RVS_COLOR_MAGENTA_ESCAPE_CODE); i += 3; break;
                case '7': printf("%s", RVS_COLOR_CYAN_ESCAPE_CODE);    i += 3; break;
                case '8': printf("%s", RVS_COLOR_WHITE_ESCAPE_CODE);   i += 3; break;
                case 'r':
                    srand(time(NULL));
                    unsigned int random_color_index = (unsigned int) rand() % 8;
                    switch (random_color_index){
                        case 0: printf("%s", RVS_COLOR_RESET_ESCAPE_CODE);    break;
                        case 1: printf("%s", RVS_COLOR_BLACK_ESCAPE_CODE);    break;
                        case 2: printf("%s", RVS_COLOR_RED_ESCAPE_CODE);      break;
                        case 3: printf("%s", RVS_COLOR_GREEN_ESCAPE_CODE);    break;
                        case 4: printf("%s", RVS_COLOR_YELLOW_ESCAPE_CODE);   break;
                        case 5: printf("%s", RVS_COLOR_BLUE_ESCAPE_CODE);     break;
                        case 6: printf("%s", RVS_COLOR_MAGENTA_ESCAPE_CODE);  break;
                        case 7: printf("%s", RVS_COLOR_CYAN_ESCAPE_CODE);     break;
                        case 8: printf("%s", RVS_COLOR_WHITE_ESCAPE_CODE);    break;
                    }
                    i += 3;
                    break; 
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
                case 'r':
                    srand(time(NULL));
                    unsigned int random_emoji_index = (unsigned int) rand() % 9;
                    switch (random_emoji_index){
                        case 0: printf("😀"); break;
                        case 1: printf("😄"); break;
                        case 2: printf("😁"); break;
                        case 3: printf("😅"); break;
                        case 4: printf("😂"); break;
                        case 5: printf("😍"); break;
                        case 6: printf("🤩"); break;
                        case 7: printf("🤔"); break;
                        case 8: printf("😵"); break;
                        case 9: printf("🥱"); break;
                    }
                    i += 3;
                    break; 
            }
        }

        // Output Character
        else{
            putchar(data[i]);
            i++;
        }
    }
    printf("%s", RVS_COLOR_CYAN_ESCAPE_CODE);
    if (*rvs_execution_mode == RVS_REPL_MODE){
        putchar('\n');
    }
}


// RevanScript Standard Table Output Function
void rvs_standard_table_output(const RVSTBL* const rvs_table){
    // Square draw
    size_t c_i = 0;
    size_t data_counter = 0;
    goto start_and_end_draw_block;

    // Cycle label
    next_draw_block:
    for (size_t h_i = 0; h_i < rvs_table->config.height; h_i++){
        putchar('|');
        for (size_t r_i = 0; r_i < rvs_table->config.rows; r_i++){
            for (size_t w_i = 0; w_i < rvs_table->config.width; w_i++){
                putchar(rvs_table->datas[data_counter][w_i]);
            }
            putchar('|');
            data_counter++;
        }
        putchar('\n');
    }
    goto start_and_end_draw_block;

    // Start and end label
    start_and_end_draw_block:
    putchar('+');
    for (size_t r_i = 0; r_i < rvs_table->config.rows; r_i++){
        for (size_t w_i = 0; w_i < rvs_table->config.width; w_i++){
            putchar('-');
        }
        putchar('+');
    }
    putchar('\n');
    if (c_i < rvs_table->config.cols){
        c_i++;
        goto next_draw_block;
    }
}


// RevanScript Standard Input Function
void rvs_standard_input(RVSIOBUF* input_buffer, const int8_t const* rvs_execution_mode){
    if (*rvs_execution_mode == RVS_REPL_MODE){
        printf("%s::: %s", RVS_COLOR_MAGENTA_ESCAPE_CODE, RVS_COLOR_RESET_ESCAPE_CODE);
    }
    printf("%s", RVS_COLOR_GREEN_ESCAPE_CODE);
    if (!fgets(input_buffer, 2048, stdin)){
        return;
    }
    else{
        input_buffer[strlen(input_buffer) - 1] = '\0';
    }
    printf("%s", RVS_COLOR_CYAN_ESCAPE_CODE);
}


// RevanScript Standard Debug Function
void rvs_standard_debug(bool type, const char* const message){
    if (type == true){
        printf("%s[DEBUG] : %s%s\n", RVS_COLOR_GREEN_ESCAPE_CODE, message, RVS_COLOR_RESET_ESCAPE_CODE);
    }

    else{
        printf("%s[DEBUG] : %s%s\n", RVS_COLOR_YELLOW_ESCAPE_CODE, message, RVS_COLOR_RESET_ESCAPE_CODE);
    }
}


// RevanScript Standard Information Function
void rvs_standard_info(const char* const message){
    printf(message, RVS_COLOR_BLUE_ESCAPE_CODE, RVS_COLOR_RESET_ESCAPE_CODE);
}


// RevanScript Standard Error Function
void rvs_standard_error(const char* const type, const char* const notified){
    if (!notified){
        fprintf(stderr, type , RVS_COLOR_RED_ESCAPE_CODE, RVS_COLOR_RESET_ESCAPE_CODE);
    }

    else{
        fprintf(stderr, type , RVS_COLOR_RED_ESCAPE_CODE, notified, RVS_COLOR_RESET_ESCAPE_CODE);
    }
}
