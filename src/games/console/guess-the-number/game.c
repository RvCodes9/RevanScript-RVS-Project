// C Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// RevanScript (RVS) Core / Engine Libraries
#include "../../../../includes/rvscol.h"

// RevanScript (RVS) Subsystem Libraries
#include "../../../../includes/games/console/guess-the-number/game.h"

// Guess The Number Game -- Main Function
bool guess_the_number_game_main(void){
    unsigned int random_number = rand() % 10 + 1;
    int input_number;
    int score = 0;

    printf("\n\n%s----->%s[GUESS THE NUMBER]%s<-----\n\n", 
        RVS_COLOR_BLUE_ESCAPE_CODE, 
        RVS_COLOR_GREEN_ESCAPE_CODE, 
        RVS_COLOR_BLUE_ESCAPE_CODE);

    while (true){
        printf("%sEnter a number : ", RVS_COLOR_BLUE_ESCAPE_CODE);
        scanf("%d", &input_number);

        if (random_number == input_number){
            random_number = rand() % 10 + 1;
            score += 1;
            printf("%sCorrect! You Won!\n", RVS_COLOR_GREEN_ESCAPE_CODE);
            printf("%sThe number has changed!\n", RVS_COLOR_YELLOW_ESCAPE_CODE);
            printf("%sScore : %d\n", RVS_COLOR_MAGENTA_ESCAPE_CODE, score);
        }

        else if ((input_number >= 1 && input_number <= 10) && (random_number > input_number)){
            if (score > 0) score -= 1;
            printf("%sToo high!\n", RVS_COLOR_YELLOW_ESCAPE_CODE);
            printf("%sScore : %d\n", RVS_COLOR_MAGENTA_ESCAPE_CODE, score);
        }

        else if ((input_number >= 1 && input_number <= 10) && (random_number < input_number)){
            if (score > 0) score -= 1;
            printf("%sToo low!\n", RVS_COLOR_YELLOW_ESCAPE_CODE);
            printf("%sScore : %d\n", RVS_COLOR_MAGENTA_ESCAPE_CODE, score);
        }

        else if (input_number == -1){
            printf("%s[Exit]%s\n", RVS_COLOR_RED_ESCAPE_CODE, RVS_COLOR_RESET_ESCAPE_CODE);
            break;
        }

        else {
            printf("%s[Enter a number between 1 and 10]\n", RVS_COLOR_YELLOW_ESCAPE_CODE);
        }
    }

    return true;
}