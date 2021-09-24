#include "datos.h"
int yes_no_options(int option){
	while(option != 1 && option != 0){
		puts("Opción inexistente. Intente de nuevo. 1- Si 0-No");
		scanf("%i",&option);
	}
	return option;
}
int play_game(){
	// el jugador decide si quiere jugar o no
	int option;
	puts("Iniciar el juego? 1- Si 0-No");
	scanf("%i",&option);
	option = yes_no_options(option);
	if(option == TRUE){
		return TRUE;
	}else{
		return FALSE;
	}

}
int box(int **board,int row, int column){
	//Funcion si es que se formo la caja
	if(board[row][column+1]==LINE && board[row][column-1]==LINE && board[row+1][column]==LINE && board[row-1][column]==LINE){
		return TRUE;
	}else{
		return FALSE;
	}
}
void verify_move(int **board,int *row,int *column){
	for(int i=0;i<boardSize+(boardSize-1);i++){
		for(int j=0;j<boardSize+(boardSize-1);j++){
			if(i%2!=0 && j%2!=0){
				if(i-1==*row && j==*column){
					*row=*row+1;
				}else{
					if(i+1==*row && j==*column){
						*row=*row+1;
					}else{
						if(j-1==*column && i==*row){
							*column=*column+1;
						}else{
							if(j+1==*column && i==*row){
								*column=*column-1;
							}
						}
					}
				}
			}
		}
	}
}
int choice_colors(){
	// el jugador elige el color
	int color, option;
	printf("\nDesea elegir color ? 1- Si 0-No");
	scanf("%i",&option);
	option = yes_no_options(option);
	if(option == TRUE){
		printf("\nElegir color a usar 1- Rojo 0-Azul");
		scanf("%i",&color);
			while(color != 1 && color !=0){
				printf("\nOpción inexistente");
				printf("\nElegir color 1- Rojo 0-Azul");
				scanf("%i",&color);
			}
			if(color == TRUE){
				puts("Color a usar: Rojo ");
				return RED;
			}else{
				puts("Color a usar: Azul ");
				return BLUE;
			}
	}else{
		puts("Elección de color aleatoriamente");
		color = random_number(1,0);
	}
	if(color == TRUE){
		puts("Color a usar: Rojo ");
		return RED;
	}else{
		puts("Color a usar: Azul ");
		return BLUE;
	}
}
int end_game(int **array){
	int acumuletor=0;
	for(int i=0;i<boardSize+(boardSize-1);i++){
			for(int j=0;j<boardSize +(boardSize-1);j++){
				if(i%2!=0 && j%2!=0){
					if(array[i][j]==BOX){
						acumuletor++;
					}
				}
		}
	}
	return acumuletor;
}
int **choice_board(){
	//Funcion que se encarga de definir el tamaño del tablero
	int option,newSize;
	puts("Elegir tamaño del tablero? 1-Si 0-No");
	scanf("%d",&option);
	option =yes_no_options(option);
	if(option == TRUE){
		printf("\nIntroduzca el tamaño del tablero: ");
		scanf("%i",&boardSize);
		boardSize=check_size_board(boardSize);
		newSize=boardSize+(boardSize-1);
		printf("el tamaño del tablero %i y el nuevo %i ",boardSize,newSize);
		int **board=create_board(newSize);
		initialize_board(board);
		print_board(board);
		return board;
		}else{
			boardSize = random_number(15,3);
			printf("Tamaño del tablero %i",boardSize);
			boardSize=check_size_board(boardSize);
			newSize=boardSize+(boardSize-1);
			int **board=create_board(newSize);
			initialize_board(board);
			print_board(board);
			return board;
		}
}
int choice_turns(){
	//Funcion que se encarga de definir quien empieza
	int choice,player;
	puts("Elegir quién comienza? 1-Si 0-No");
	scanf("%i",&choice);
	choice = yes_no_options(choice);//validacion de la opcion
	if(choice==TRUE){
		puts("Elegir quién comienza 1-CPU 0-JUGADOR");
		scanf("%i",&player);
		while(player != 1 && player !=0){
			puts("Opción inexistente");
			puts("Elegir quién comienza 1-CPU 0-JUGADOR");
			scanf("%i",&player);
		}
		if(player == TRUE){
			puts("Comienza CPU ");
			return CPU;
		}else{
			puts("Comienza JUGADOR ");
			return PLAYER;
		}
	}else{
		puts("Elección de quién empieza aleatoriamente");
				player = random_number(1,0);
	} // imprime la elección
	if(player == TRUE){
		puts("Comienza CPU ");
		return CPU;
	}else{
		puts("Comienza JUGADOR ");
		return PLAYER;
	}

}
void move_pc(int **board){
	//Funcion que se encarga de realiazar los movimientos de la pc
	int max=(boardSize+(boardSize-1))-1;
	int row,column;
	printf("\nTurno de la CPU");
	line();
	printf("\nEligiendo.....");
	row=random_number(max,0);
	column=random_number(max,0);
	while(board[row][column]==DOT || board[row][column]==LINE || board[row][column]==EMPTYBOX){
		row=random_number(max,0);
		column=random_number(max,0);
	}
	printf("\nPosicion a poner la recta: %i, %i",row,column);
	board[row][column]=LINE;
	verify_move(board,&row,&column);
	if(box(board,row,column)){
		add_points[PLAYER]+= 10;
		board[row][column]=BOX;
		printf("\nPuntaje CPU: %i",add_points[PLAYER]);
	}
}
void move_player(int **array){
	//Procedimiento que se encarga de los movimientos del jugador
	int row,column;
	printf("\nTurno del jugador");
	line();
	puts("\nIntroduzca la Posicion a colocar la raya. Considerar que los 1 son los puntos y los 3 son vacío ");
	printf("\nFila: ");
	scanf("%i",&row);
	printf("\nColumna: ");
	scanf("%i",&column);
	printf("\nPosición %i, %i",row,column);
	while(array[row][column] == LINE || array[row][column] == EMPTYBOX || array[row][column] == DOT ){ //verificar que no esta ocupado
		printf("\nPosicion ocupada o no existe. Intente de nuevo");
		printf("\nFila: ");
		scanf("%i",&row);
		printf("\nColumna: ");
		scanf("%i",&column);
		printf("\nPosición %i, %i",row,column);
	}
	array[row][column] = LINE;
	verify_move(array,&row,&column);
	if(box(array,row,column)){
		add_points[PLAYER]+=10;
		array[row][column]=BOX;
		printf("\nPuntaje Jugador: %i",add_points[PLAYER]);
	}
}
void start_game(){
	//Procedimiento que hace que funcione el juego
	int **board = choice_board();
	if(choice_turns()==PLAYER){
		choice_colors();
		//Juega el jugador
		while(end_game(board)<(boardSize+1)){
			move_player(board);
			print_board(board);
			move_pc(board);
			print_board(board);
		}
		printf("\nTermino el juego");
	}else{
		//Juega la pc
		choice_colors();
		move_pc(board);
		print_board(board);
		move_player(board);
		print_board(board);
	}
}
int main(void) {
	srand(time(NULL));
	if(play_game() == 1){
		start_game();
	}else{
		puts("Saliendo del juego");
		exit(0);
	}

	return EXIT_SUCCESS;
}
