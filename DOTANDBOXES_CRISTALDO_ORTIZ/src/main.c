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
int valid_move(int initialRow,int initialColumn,int finalRow, int finalColumn){
	//Verifica si hace un movimiento valido (vertical y horizontal)
	//#Si la resta entre las columnas es 0 es un movimiento vertical
	//#Si la resta entre las filas es 0 es un movimiento horizontal
	//Para tener en cuenta la diferencia del movimiento no debe ser mayor a 1
	int columnDifference=initialColumn-finalColumn;
	int rowDifference=initialRow-finalRow;
	if(columnDifference==0 && abs(rowDifference)==2){
		return TRUE;
	}else{
		if(rowDifference==0 && abs(columnDifference)==2){
			return TRUE;
		}else{
			return FALSE;
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
int end_game(){
		return TRUE;
}
void move_player(int **array){
	int initialRow,initialColumn,finalRow,finalColumn;
	printf("\nIntroduzca la Posicion Inicial");
	scanf("\nFila %i , Columna %i",&initialRow,&initialColumn);
	printf("\nIntroduzca la Posicion Final: ");
	scanf("\nFila: %i, Columna: %i",&finalRow,&finalColumn);
	while(array[finalRow][finalColumn] == LINE ){ //verificar que no esta ocupado
		printf("\nPosicion Final ocupada o no existe. Intente de nuevo");
		printf("\nIntroduzca la Posicion Final: ");
		scanf("\nFila: %i, Columna: %i",&finalRow,&finalColumn);
	}
}
void play_pc(int **board){
	int row=random_number(boardSize-1,0);
	int column=random_number(boardSize-1,0);
	while(board[row][column]==DOT || board[row][column]==EMPTYBOX || board[row][column]==LINE){
		row=random_number(boardSize-1,0);
		column=random_number(boardSize-1,0);
	}
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
void turns(int **array,int player){
	//funcion para saber si terminan los turnos, osea, define el fin del juego y
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
/*int **points(int turns){
	//manera de sumar puntos
	int add_points[2] = {0};
	add_points[turns] =+ 10;
	//suma 10 puntos
	//suma los puntos de la cpu en posi 1
	//los puntos del jugador en posi 0
	return add_points;
<<<<<<< HEAD

}
int box(int **array){
	//una manera de saber si en el tablero hay una caja cerrada
	if(array[i][j]==2 && array[i+1][j-1]==2 && array[i+2][j]==2 && array[i+1][j+1]){
		return BOX;
=======
}*/
void star_game(){
	int **board = choice_board();
	if(choice_turns()==PLAYER){
		//Juega el jugador primero
		move_player(board);
		print_board(board);
		play_pc(board);
		print_board(board);
	}else{
		//Juega la pc
		play_pc(board);
		print_board(board);
		move_player(board);
		print_board(board);
>>>>>>> e0a3082e21110776f9b40b081db3f788bdfa86db
	}
}
int main(void) {
	srand(time(NULL));
	if(play_game() == 1){
		star_game();
	}else{
		puts("Saliendo del juego");
		exit(0); //termina
	}

	return EXIT_SUCCESS;
}
