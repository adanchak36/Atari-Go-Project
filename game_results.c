#include <stdio.h> 
#include "game_results.h" 
#include "player_functions.h"
#include "player_input.h" 


int game_results(char grid[height][width]){
    int i;//vertical counter
    int z;//horizontal counter
    int answer; //return variable for when everything is good, to continue loop running and checking.
    
    for(i = 0; i < height; ++i){
        for(z = 0; z < width; ++z){
            if(grid[i][z] != '.'){
                //Special corner cases: (0,0), (0,4), (4,0), (4,4)
                if((i == 0 && z == 0) || (i == 0 && z == (width -1)) || (i == (height - 1) && z == 0) || (i == (height - 1) && z == (width - 1))){ // (0,0), (0,4), (4,0), (4,4)
                    if( (i== 0 && z == 0) || (i == 0 && z == (width - 1))){ //(0,0) and (0,4)
                        if((grid[i+1][z] != '.')){/* No period*/
                            if(z == 0){//(0,0)
                                if((grid[i][z] != grid[i][z+1]) && (grid[i][z+1] == grid[i+1][z])){
                                    return(player_win_check(grid[i][z]));
                                }else{
                                    answer = 0;
                                }
                            }else{//(0,4)
                                if((grid[i][z] != grid[i][z-1]) && (grid[i][z-1] == grid[i+1][z])){
                                    return(player_win_check(grid[i][z]));
                                }else{
                                    answer = 0;
                                }
                            }
                            
                        }else{//Has Period
                            answer = 0;
                        }//Has Period
                    }/*(0,0) and (0,4)*/else{//(4,0) and (4,4)
                        if((grid[i-1][z] != '.')){//No period
                            if(z == 0){//(4,0)
                                if((grid[i][z] != grid[i-1][z]) && (grid[i-1][z] == grid[i][z+1])){
                                    return(player_win_check(grid[i][z]));
                                }else{
                                    answer = 0;
                                }
                            }else{//(4,4)
                                if((grid[i][z] != grid[i-1][z])&& (grid[i-1][z] == grid[i][z-1])){
                                    return(player_win_check(grid[i][z]));
                                }else{
                                    answer = 0;
                                }
                            }
                        }/* No period */else{//Has period
                            answer = 0;
                        }//Has Period
                    }
                }/*Special corner cases: (0,0), (0,4), (4,0), (4,4)*/else if((i == 0) || (z == 0) || i ==(height - 1) || z ==(width - 1)){//outer bounds
                    if(i == 0){
                        if((grid[i][z-1] != '.')){
                            if((grid[i][z] != grid[i][z-1])&&(grid[i][z-1]== grid[i][z+1]) &&(grid[i][z-1] == grid[i+1][z])){//left,right,down
                                return(player_win_check(grid[i][z]));
                            }else{
                                answer = 0;
                            }
                        }//check period for i == 0
                    }else if(z == 0){
                        if((grid[i][z+1] != '.')){
                            if((grid[i][z] != grid[i][z+1])&&(grid[i][z+1]== grid[i-1][z])&&(grid[i][z+1] == grid[i+1][z])){
                                return(player_win_check(grid[i][z]));
                            }
                        }else{
                            answer = 0;
                        }
                    }else if(i == (height -1)){
                        if((grid[i][z+1] != '.')){
                            if((grid[i][z] != grid[i][z+1]) &&(grid[i][z+1] == grid[i][z-1]) &&(grid[i][z+1] == grid[i-1][z])){
                                return(player_win_check(grid[i][z]));
                            }else{
                                answer = 0;
                            }
                        }else{
                            answer = 0;
                        }
                    }else{
                        if(z == (width-1)){
                            
                            if((grid[i][z-1]!='.')){
                                
                                if((grid[i][z] != grid[i][z-1]) &&(grid[i][z-1] == grid[i+1][z]) &&(grid[i][z-1] == grid[i-1][z])){
                                    return(player_win_check(grid[i][z]));
                                }else{
                                    answer = 0;
                                }
                            }else{
                                answer = 0;
                            }
                        }
                    }
                    
                }/*outer bounds*/else{
                    if((grid[i][z+1] != '.')){
                        if((grid[i][z] != grid[i][z+1]) &&(grid[i][z+1] == grid[i][z-1])&&(grid[i][z+1] == grid[i+1][z])&&(grid[i][z+1] == grid[i-1][z])){
                            return(player_win_check(grid[i][z]));
                        }else{
                            answer = 0;
                        }
                    }else{
                        answer = 0;
                    }
                }
            }//checks in ther is period on current value
        }//horizontal for loop
    }//vertical for loop
    
    
    //return 1 for player1 winning
    //return 2 for player2 winning
    return(answer);
}




