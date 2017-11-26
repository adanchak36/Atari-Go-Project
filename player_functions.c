#include <stdio.h> 
#include "player_functions.h"
#include "player_input.h" 

void player1moving(int *player1_i, int *player1_z){
    
    do{
        printf("Player 1:");
        scanf(" %d %d", player1_i, player1_z);
        
        if((int)*player1_i < 0 || (int)*player1_z < 0){
            printf("Error: Values cannot be negative");
        }else if((int)*player1_i > (height - 1) || (int)*player1_z > (width - 1)){
            printf("Error: Values cannot be greater than height(%d) or width(%d)\n", height, width);
        }
        
        //updates values of player1_i, player1_z, values can now go from main into print_grid
        //bounds checking for right grid size here
    }while((int)*player1_i < 0 || (int)*player1_z < 0 || (int)*player1_i > (height - 1) || (int)*player1_z > (width - 1));
    
    return;
}


void player2moving(int *player2_i, int *player2_z){
    do{
        printf("Player 2:");
        scanf(" %d %d", player2_i, player2_z);
        
        if((int)*player2_i < 0 || (int)*player2_z < 0){
            printf("Error: Values cannot be negative");
        }else if((int)*player2_i > (height - 1) || (int)*player2_z > (width - 1)){
            printf("Error: Values cannot be greater than height(%d) or width(%d)\n", height, width);
        }
        
        //updates values of player1_i, player1_z, values can now go from main into print_grid
        //bounds checking for right grid size here
    }while((int)*player2_i < 0 || (int)*player2_z < 0 || (int)*player2_i > (height - 1) || (int)*player2_z > (width - 1));
    
    return;
}



int player_win_check(char player_lost){//called inside nested if/elif/else in game_results
    if(player_lost == 'X'){
        printf("Player 1 Wins!!!");
    }else{
        printf("Player 2 Wins!!!");
    }
    
    return(1);
}
