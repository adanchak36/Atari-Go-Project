#include <stdio.h> 
#include "grid_functions.h"
#include "player_input.h" 




void start_print_grid(char grid[height][width]){
    int i, z;
    for(i = 0; i < height; ++i){
        printf("|"); //left boundary
        for(z = 0; z < width; ++z){
            grid[i][z] = '.'; //fills every space with '.' for start of game
            printf("%c", grid[i][z]);
        }
        printf("|"); //right boundary
        printf("\n");
    }
}//end of start_print_grid function


void print_grid(char grid[height][width], int player1_i, int player1_z, int player2_i, int player2_z){
    
    int i,z; // i is vertical counter(row), z is horizontal counter(column)
    
    for(i=0; i < height; ++i){
        printf("|"); //left boundary
        for(z=0;z < width; ++z){
            if(grid[i][z] == '.'){ //Blank Slate
                if(player1_i == i){
                    if(player1_z == z){
                        grid[i][z] = 'O';
                    }
                }
                //checking player2 coordinates
                if(player2_i == i){
                    if(player2_z == z){
                        grid[i][z] = 'X';
                    }
                }
                printf("%c", grid[i][z]);
                
            }else{//Either 'O' or 'X'
                printf("%c", grid[i][z]); 
            }
            
        }
        printf("|"); //right boundary
        printf("\n");
        
    }
    
}//end of print_grid