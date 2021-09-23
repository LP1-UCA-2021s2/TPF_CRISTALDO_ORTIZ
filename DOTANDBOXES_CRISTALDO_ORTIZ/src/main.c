#include "datos.h"

int play_game(){
	// el jugador decide si quiere jugar o no
	int go;
	puts("Iniciar el juego? 1- si 0-no");
	scanf("%d",&go);
	while(go != 1 && go !=0){
		puts("Opción inexistente");
		puts("Iniciar el juego? 1- si 0-no");
		scanf("%d",&go);
	}
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
int choice_colors(){
	// el jugador elige el color
	int color;
	puts("Elegir color  1- Rojo 0-Azul");
	scanf("%d",&color);
	while(color != 1 && color !=0){
		puts("Opción inexistente");
		puts("Elegir color  1- Rojo 0-Azul");
		scanf("%d",&color);
	}
	if(color == TRUE){
		return TRUE;
	}else{
		return FALSE;
	}

}
void move_player(int **board){
	int initialRow,initialColumn,finalRow,finalColumn;
	puts("Introduzca la Posicion Inicial");
	scanf("\nFila %i",&initialRow);
	scanf("\nColumna %i",&initialColumn);
	printf("\nPosición Inicial: %i, %i",initialRow,initialColumn);
	puts("Introduzca la Posicion Final: ");
	scanf("\nFila%i",&finalRow);
	scanf("\nColumna%i",&finalColumn);
	printf("\nPosición Final: %i, %i",finalRow,finalColumn);
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
	puts("Elegir tamaño del tablero? 1-si 0-no");
	scanf("%d",&option);
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
			boardSize=check_size_board(boardSize);
			boardSize=boardSize+(boardSize-1);
			int **board=create_board(boardSize);
			initialize_board(board);
			print_board(board);
			return board;
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
