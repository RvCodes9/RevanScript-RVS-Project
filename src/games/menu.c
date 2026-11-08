// C Standard Libraries
#include <stdio.h>
#include <stdbool.h>

// RevanScript (RVS) Core/Engine Libraries
#include "../../includes/rvsio.h"
#include "../../includes/rvstbl.h"
#include "../../includes/rvscol.h"

// RevanScript (RVS) Subsystem Libraries
#include "../../includes/games/console/guess-the-number/init.h"
#include "../../includes/games/menu.h"


// RevanScript (RVS) Game Mode Menu Function 
bool rvs_games_menu_init(void){
    struct RVSTBLConfig __rvs_game_table_config = {.rows=3, .cols=9, .width=20, .height=1};
    RVSTBL* __rvs_game_table = rvs_table_create(__rvs_game_table_config);
    if (!__rvs_game_table) return false;
    
    rvs_table_insert(__rvs_game_table, 27, 
        "Index", "Games", "Type",
        "1", "Guess the number", "Console",
        "2", "Tic Tac Toe", "Console", 
        "3", "Minesweeper", "Console", 
        "4", "Sudoku", "Console", 
        "5", "Chess", "Console",
        "6", "Sea Battle", "Console",
        "7", "Flappy Bird", "Graphic",
        "8", "Tetris", "Graphic"); 
    
    bool menu_active = true;
    while (menu_active){
        printf("\n\t\t%s[RevanScript (RVS) <-(GAME MODE)->]%s\n\n", 
        RVS_COLOR_MAGENTA_ESCAPE_CODE, 
        RVS_COLOR_RESET_ESCAPE_CODE);
    
        rvs_standard_table_output(__rvs_game_table);

        printf("%s[Enter the selected game's index] : %s",
        RVS_COLOR_CYAN_ESCAPE_CODE,
        RVS_COLOR_RESET_ESCAPE_CODE);

        int input_game_index;
        scanf("%d", &input_game_index);
        
        switch (input_game_index){
            case 1: 
                if (console_game_guess_the_number_init() == false) return false; 
                break;
            case 2: 
                break; 
            case 3: 
                break;
            case 4: 
                break;
            case 5: 
                break;
            case 6: 
                break;
            case 7: 
                break;
            case 8: 
                break;
            default : 
                menu_active = false; 
                break;
        }
    }

    rvs_table_delete(__rvs_game_table);
    return true;
}
