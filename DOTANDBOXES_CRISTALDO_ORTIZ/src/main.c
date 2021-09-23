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
void choice_colors(){
	// el jugador elige el color
	int color, option;
	puts("Desea elegir color ? 1- Si 0-No");
	scanf("%i",&option);
	option = yes_no_options(option);
	if(option == TRUE){
		puts("Elegir color a usar 1- Rojo 0-Azul");
		scanf("%i",&color);
			while(color != 1 && color !=0){
				puts("Opción inexistente");
				puts("Elegir color 1- Rojo 0-Azul");
				scanf("%i",&color);
			}
	}else{
		puts("Elección de color aleatoriamente");
		color = random_number(1,0);
	}
	if(color == TRUE){
		puts("Color a usar: Rojo ");
	}else{
		puts("Color a usar: Azul ");
	}

}
int end_game(int **board, int row, int column){
	//Funcion que determina el fin del juego
	int collector=0;
	collector=collector + box(board,row,column);
	int condition=(boardSize-1)*(boardSize-1);
	if(collector < condition){
		return FALSE;
	}else{
		return TRUE;
	}
}
void move_player(int **array){
	int initialRow,initialColumn,finalRow,finalColumn;
	puts("Introduzca la Posicion Inicial");
	scanf("\nFila %i , Columna %i",&initialRow,&initialColumn);
	puts("Introduzca la Posicion Final: ");
	scanf("\nFila: %i, Columna: %i",&finalRow,&finalColumn);
	while(array[finalRow][finalColumn] == LINE ){ //verificar que no esta ocupado
		puts("Posicion Final ocupada o no existe. Intente de nuevo");
		puts("Introduzca la Posicion Final: ");
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

void choice_turns(){
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

	}else{
		puts("Elección de quién empieza aleatoriamente");
				player = random_number(1,0);
	} // imprime la elección
	if(player == TRUE){
		puts("Comienza CPU ");
	}else{
		puts("Comienza JUGADOR ");
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
}*/
void star_game(){
	while(0){
		int **board = choice_board();
		choice_colors();
		move_player(board);
		play_pc(board);
		puts(" ");
		print_board(board);
	}
}
int main(void) {
	srand(time(NULL));
	if(play_game() == 1){
		int **board = choice_board();
		choice_colors();
		move_player(board);
		play_pc(board);
		puts(" ");
		print_board(board);
	}else{
		puts("Saliendo del juego");
		exit(0); //termina
	}

	return EXIT_SUCCESS;
}
