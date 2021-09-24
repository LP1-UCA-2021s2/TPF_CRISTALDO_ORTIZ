#include "datos.h"
int yes_no_options(int a){
	while(a != 1 && a != 0){
		puts("Opción inexistente. Intente de nuevo. 1- Si 0-No");
		scanf("%i",&a);
	}
	return a;
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
int verify_move(int **board,int row,int column){
	//cuando esta hacia el oeste
	if(board[row][column+1]== EMPTYBOX){
		return column+1;
	}else{
		//cuando esta hacia el este
		if(board[row][column-1]== EMPTYBOX){
				return column-1;
			}else{
				//cuando esta hacia sur
				if(board[row+1][column]== EMPTYBOX){
						return row+1;
					}else{
						//cuando esta hacia el norte
						if(board[row-1][column]== EMPTYBOX){
								return row-1;
							}
					}
			}
	}
	return 0;
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
void end_game(){
		exit(0);
}

void play_pc(int **board){
	int row=random_number(boardSize-1,0);
	int column=random_number(boardSize-1,0);
	while(board[row][column]==DOT || board[row][column]==EMPTYBOX || board[row][column]==LINE){
		row=random_number(boardSize-1,0);
		column=random_number(boardSize-1,0);
	}
	printf("Posicion : %i, %i",row,column);
	board[row][column]=LINE;
}
int **choice_board(){
	//el jugador decide si elige el tamaño del tablero o no
	//si es no, se genera de forma aleatoria
	int option,newSize;
	puts("Elegir tamaño del tablero? 1-Si 0-No");
	scanf("%d",&option);
	option =yes_no_options(option);
	if(option == TRUE){
		printf("\nIntroduzca el tamaño del tablero: ");
		scanf("%i",&boardSize);
		boardSize=check_size_board(boardSize);
		newSize=boardSize+(boardSize-1);
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
	//elegir quién comienza
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


void move_player(int **array){ //FUNCIONA
	int Row,Column;
	puts("Introduzca la Posicion a colocar la raya. Considerar que los 1 son los puntos y los 3 son vacío ");
	printf("\nFila: ");
	scanf("%i",&Row);
	printf("\nColumna: ");
	scanf("%i",&Column);
	printf("Posición %i, %i",Row,Column);
	while(array[Row][Column] == LINE || array[Row][Column] == EMPTYBOX || array[Row][Column] == DOT ){ //verificar que no esta ocupado
		printf("\nPosicion ocupada o no existe. Intente de nuevo");
		printf("\nFila: ");
		scanf("%i",&Row);
		printf("\nColumna: ");
		scanf("%i",&Column);
		printf("Posición %i, %i",Row,Column);
	}
	array[Row][Column] = LINE;
	int existBox = box(array,Row,Column);
	if(existBox == TRUE){
		add_points[PLAYER]+= 10;
		printf("Puntaje Jugador: %i",add_points[PLAYER]);
	}
}
void start_game(){ // AGG TURNOS, MENSAJE, PUNTOS,INDICAR FIN MAYBE

	int **board = choice_board();
	//while()
	if(choice_turns()==PLAYER){
		//Juega el jugador primero
		choice_colors();
		move_player(board);
		print_board(board);
		play_pc(board);
		print_board(board);

	}else{
		//Juega la pc
		choice_colors();
		play_pc(board);
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
		end_game(); //termina
	}

	return EXIT_SUCCESS;
}
