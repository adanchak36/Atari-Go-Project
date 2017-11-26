#include <stdio.h> //printf,scanf
#include "player_input.h" 
#include "grid_functions.h" //start_print_grid, print_grid functions 
#include "player_functions.h" //moving and check winner functions
#include "game_results.h" 


//needs to be in header file below





//check score function (entire game function)
//void playgame()






int main(void){
    
    //start from saved game (check if it exists or not)
    // open file
    // read game stats
    // close file
    // game option. Single Player. Double Player
    
    //player1 variables - they will change every round
    int player1_i = 100;
    int player1_z = 100; // player's cooridnates, this way it won't print out (0,0) in grid
    //player2's variables
    int player2_i = 100;
    int player2_z = 100;
    
    



    player_input(); 

 
    char grid[height][width]; // 2-D character array initialization
    printf("\n");
    
    
    
    start_print_grid(grid);//At beginning of game display the grid and fills 2-D array
    
    
    //play game function- while loop conditions is the return of that function
    while(1){
        player1moving(&player1_i, &player1_z);
        print_grid(grid, player1_i, player1_z,player2_i, player2_z);
        
        
        if(game_results(grid) == 1){
            break;
        }
        
        
        player2moving(&player2_i, &player2_z);
        
        print_grid(grid, player1_i, player1_z,player2_i, player2_z);
        
        
        if(game_results(grid) == 1){
            break;
        }
        
    }
    printf("I'm out of the loop, thank goodness\n");
    printf("somebody won\n");
    
    
    
    
    
    
    // function with commands
    return(0);
}//end of main









