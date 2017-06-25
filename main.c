#include <stdio.h> //printf,scanf


void print_grid(int height,int width,char grid[height][width]);//function prototype for print_grid function




int main(void){
    
    int height, width;
    
    //start from saved game (check if it exists or not)
        // open file
        // read game stats
        // close file
    
    do{
        //error message when wrong value is placed
        printf("Enter height of grid:");
        scanf(" %d", &height);
        
        printf("Enter width of grid:");
        scanf(" %d", &width);
        
    }while(((height < 4) || (height > 25)) || ((width < 4) || (width > 25))); // do while sets bounds for height and width
    
    char grid[height][width]; // 2-d character array
    
    
    printf("\n");
    
    print_grid(height, width, grid);//At beginning of game display the grid
    
    

    //Users should play game here
    // function with commands
    return(0);
}



void print_grid(int height,int width,char grid[height][width]){
    
    int i,z; // i is vertical counter(row), z is horizontal counter(column)
    
    for(i=0; i < height; ++i){
        printf("|"); //left boundary
        for(z=0;z < width; ++z){
            grid[height][width] = '.';
            printf("%c", grid[height][width]);
            
        }
        printf("|"); //right boundary
        printf("\n");
    }
    
}
