// C Standard Libraries
#include <stdbool.h>

// Subsystem Libraries
#include "../../../../includes/games/console/guess-the-number/init.h"
#include "../../../../includes/games/console/guess-the-number/game.h"

// Console Game Guess The Number Init Function
bool console_game_guess_the_number_init(void){
    if (guess_the_number_game_main() == true) return true;
    return false;
}