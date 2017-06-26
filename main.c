#include <stdio.h> //printf,scanf

//needs to be in header file below
int height, width;//height and width are global variables. Used in print_grid, main, and player1, 2 moving functions

void print_grid(char grid[height][width], int player1_i, int player1_z);//function prototype for print_grid function

void player1moving(int *player1_i, int *player1_z);

//function for player2moving

//check score function






int main(void){
    
    //player1 variables - they will change every round
    int player1_i = 100;
    int player1_z = 100; // player1's cooridnates, this way it won't print out (0,0) in grid
    
    //start from saved game (check if it exists or not)
        // open file
        // read game stats
        // close file
    
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
    
    char grid[height][width]; // 2-d character array initialization
    
    
    printf("\n");
    
    print_grid(grid, player1_i, player1_z);//At beginning of game display the grid
    
    player1moving(&player1_i, &player1_z);
    
    
    print_grid(grid, player1_i, player1_z);
    


    //Users should play game here
    // function with commands
    return(0);
}//end of main



void print_grid(char grid[height][width], int player1_i, int player1_z){
    
    int i,z; // i is vertical counter(row), z is horizontal counter(column)
    
    for(i=0; i < height; ++i){
        printf("|"); //left boundary
        for(z=0;z < width; ++z){
            grid[height][width] = '.';
            //checking player1 coordinates
            if(player1_i == i){
                if(player1_z == z){
                    grid[height][width] = 'O';
                }
            }
            //checking player2 coordinates
            
            printf("%c", grid[height][width]);
            
        }
        printf("|"); //right boundary
        printf("\n");
    }
    
}//end of print_grid


void player1moving(int *player1_i, int *player1_z){
    printf("Player 1:");
    scanf(" %d %d", player1_i, player1_z);
    
    //updates values of player1_i, player1_z, values can now go from main into print_grid
    //bounds checking for right grid size here
    return;
}

