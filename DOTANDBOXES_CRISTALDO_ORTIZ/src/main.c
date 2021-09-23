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
	int go;
	puts("Iniciar el juego? 1- Si 0-No");
	scanf("%i",&go);
	go = yes_no_options(go);
	if(go == TRUE){
		return TRUE;
	}else{
		return FALSE;
	}

}
int random_number(int max,int min){
	//Funcion que me genera numeros aleatorios entre dos numeros
	return rand()%(max-min+1) + min;
}
int check_size_board(int number){
	//Verifica el tamaño que el usuario ingresa para el tablero
	while(number<3 || number>15){
		printf("\nError, introduzca un valor entre 3 y 15: ");
		scanf("%i",&number);
	}
	return number;
}
int **create_board(int size){
	//Crea el tablero
	int **array;
	array=calloc(size,sizeof(int *));
	for(int i=0;i<size;i++){
		array[i]=calloc(size,sizeof(int *));
	}
	return array;
}
void initialize_board(int **array){
	//Iniciliza el tablero para el juego
	for(int i=0;i<boardSize;i++){
		for(int j=0;j<boardSize;j++){
			if(i%2==0 && j%2==0){
				array[i][j]=DOT;
			}else{
				if(i%2!=0 && j%2!=0){
					array[i][j]=EMPTYBOX;
				}
			}
		}
	}
}
void print_board(int **array){
	//Imprime el tablero
	for(int i=0;i<boardSize;i++){
		for(int j=0;j<boardSize;j++){
			/*switch(array[i][j]){
			case DOT:
				printf(" * ");
				break;
			case EMPTYBOX:
				printf("   ");
				break;
			case LINE:
				printf("-");
			}*/
			printf(" %i ",array[i][j]);
		}printf("\n");
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
	if(valid_move(initialRow,initialColumn,finalRow,finalColumn)){
		printf("\nMovimiento valido");
	}else{
		printf("\nMovimiento invalido");
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
	int option;
	puts("Elegir tamaño del tablero? 1-Si 0-No");
	scanf("%d",&option);
	option =yes_no_options(option);
	if(option == TRUE){
		printf("\nIntroduzca el tamaño del tablero: ");
		scanf("%i",&boardSize);
		boardSize=check_size_board(boardSize);
		boardSize=boardSize+(boardSize-1);
		int **board=create_board(boardSize);
		initialize_board(board);
		print_board(board);
		return board;
		}else{
			boardSize = random_number(15,3);
			printf("Tamaño del tablero %i",boardSize);
			boardSize=check_size_board(boardSize);
			boardSize=boardSize+(boardSize-1);
			int **board=create_board(boardSize);
			initialize_board(board);
			print_board(board);
			return board;
		}
}
void turns(int **array){
//funcion para saber si terminan los turnos, osea, define el fin del juego y
	//cuando continua el jugador o cpu después de hacer una caja
}

void choice_turns(){
	//elegir quién comienza
	int choice,player;
	puts("Elegir quién comienza? 1-Si 0-No");
	scanf("%i",&choice);
	choice = yes_no_options(choice);
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
int **points(int turns){
	//manera de sumar puntos
	int add_points[2] = {0};
	add_points[turns] =+ 10;
	//suma 10 puntos
	//suma los puntos de la cpu en posi 1
	//los puntos del jugador en posi 0

	return add_points;

}
int box(int **array){
	//una manera de saber si en el tablero hay una caja cerrada
	for(int i=0;i<boardSize;i++){
		for(int j=0;j<boardSize;j++){
			if((i%2!=0 && j%2!=0)){
				if(array[i][j]==2 && array[i+1][j-1]==2 && array[i+2][j]==2 && array[i+1][j+1]){
					return BOX;
				}
			}
		}
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
		puts("Salir juego");
		exit(0); //termina
	}

	return EXIT_SUCCESS;
}
