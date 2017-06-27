#include <stdio.h> //printf,scanf

//needs to be in header file below
int height, width;//height and width are global variables. Used in print_grid, main, and player1, 2 moving functions

void start_print_grid(char grid[height][width]);

void print_grid(char grid[height][width], int player1_i, int player1_z, int player2_i, int player2_z);//function prototype for print_grid function

void player1moving(int *player1_i, int *player1_z);

void player2moving(int *player2_i, int *player2_z);// Second human player for 2 person game

int game_results(char grid[height][width]);

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
    
    
    do{
        
        printf("Enter height of grid:");
        scanf(" %d", &height);
        
        printf("Enter width of grid:");
        scanf(" %d", &width);
        
        if((height < 4) || (width < 4)){
            printf("Error: The smallest grid size can only be (4 X 4)\n");//error message for small grid inputs
        }else if((height > 25) || (width > 25)){
            printf("Error: The largest grid size can only be (25 X 25)\n");//error message for large grid inputs
        }
        
    }while(((height < 4) || (height > 25)) || ((width < 4) || (width > 25))); // do while sets bounds for height and width
    
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
    
    
    
    
    
    //Users should play game here
    // function with commands
    return(0);
}//end of main

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

int game_results(char grid[height][width]){
    int i;//vertical counter
    int z;//horizontal counter
    
    for(i = 0; i < height; ++i){
        for(z = 0; z < width; ++z){
            //Special corner cases
            //BUG: PERIODS ARE THE SAME VALUE
            
            
            if((i == 0 && z == 0) || (i == 0 && z == width) || (i == height && z == 0) ||((i == height) && (z == width))){ // (0,0), (0,4), (4,0), (4,4)
                if(i == 0){ //(0,0) and (0,4)
                    if(grid[i+1][z] != '.'){/* No period*/
                        
                        if(z == 0){//(0,0)
                            if((grid[i][z] != grid[i][z+1]) && (grid[i][z] != grid[i+1][z])){
                                printf("You lost the game at (0,0)\n");
                                return(1);
                            }
                        }else{//(0,4)
                            if((grid[i][z] != grid[i][z-1]) && (grid[i][z] != grid[i+1][z])){
                                printf("You lost the game at (0,4)\n");
                                return(1);
                            }
                        }
                        
                    }/* No period */else{//Has Period
                        return(0);
                    }//Has Period
                }/*(0,0) and (0,2)*/else{//(4,0) and (4,4)
                    if(grid[i-1][z] != '.'){//No period
                        
                        if(z == 0){//(4,0)
                            if((grid[i][z] != grid[i-1][z]) && (grid[i][z] != grid[i][z+1])){
                                printf("You lost the game at (4,0\n)");
                                return(1);
                            }
                        }else{//(4,4)
                            if((grid[i][z] != grid[i-1][z]) && (grid[i][z] != grid[i][z-1])){
                                printf("You lost the game at (4,4)\n");
                                return(1);
                            }
                        }
                        
                        
                    }/* No period */else{//Has period
                        return(0);
                    }//Has Period
                    
                }
                
                
                
                
                
                
            }// (0,0), (0,4), (4,0), (4,4)
            
            
            
        }//horizontal for loop
    }//vertical for loop
    
    
    //return 1 for player1 winning
    //return 2 for player2 winning
    return(0);
}

