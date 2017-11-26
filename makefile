atari: main.o game_results.o player_functions.o grid_functions.o 
	gcc main.c game_results.c player_input.c grid_functions.c player_functions.c -o atari -lm

main.o: main.c 
	gcc -c main.c 

player_input.o: player_input.c 
	gcc -c player_input.c 

game_results.o: game_results.c 
	gcc -c game_results.c  


player_functions.o: player_functions.c 
	gcc -c player_functions.c  


grid_functions.o: grid_functions.c 
	gcc -c grid_functions.c 

clean:
	rm -f *.o 


