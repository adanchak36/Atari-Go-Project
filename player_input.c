#include <stdio.h>
#include "player_input.h"

int height, width;

player_input(void){
    do{
        
        printf("Enter height of grid:");
        scanf(" %d", &height);
        
        printf("Enter width of grid:");
        scanf(" %d", &width);
        
        if((height < 4) || (width < 4)){
            printf("Error: The smallest grid size can only be (4 X 4)\n");
        }else if((height > 25) || (width > 25)){
            printf("Error: The largest grid size can only be (25 X 25)\n");
        }
        
    }while(((height < 4) || (height > 25)) || ((width < 4) || (width > 25))); // do while sets bounds for height and width
    
    return(0);
}//end of function 
