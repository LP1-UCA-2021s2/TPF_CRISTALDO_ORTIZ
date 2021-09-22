#include "datos.h"
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
int valid_move(int initialRow,int initialColumn,int finalRow, int finalColumn){
	//Verifica si hace un movimiento valido (vertical y horizontal)
	//#Si la resta entre las columnas es 0 es un movimiento vertical
	//#Si la resta entre las filas es 0 es un movimiento horizontal
	//Para tener en cuenta la diferencia del movimiento no debe ser mayor a 1
	int columnDifference=initialColumn-finalColumn;
	int rowDifference=initialRow-finalRow;
	if(columnDifference==0 && abs(rowDifference)==1){
		return TRUE;
	}else{
		if(rowDifference==0 && abs(columnDifference)==1){
			return TRUE;
		}else{
			return FALSE;
		}
	}
}
void move_player(){
	//mensaje para ethel: te dejo esta funcion para que mejores
	int initialRow,initialColumn,finalRow,finalColumn;
	printf("\nIntroduzca la posicion inicial fila: ");
	scanf("%i",&initialRow);
	printf("\nIntroduzca la posicion inicial columna: ");
	scanf("%i",&initialColumn);
	printf("\nIntroduzca la posicion final fila: ");
	scanf("%i",&finalRow);
	printf("\nIntroduzca la posicion final columna: ");
	scanf("%i",&finalColumn);
	if(valid_move(initialRow,initialColumn,finalRow,finalColumn)){
		printf("\nMovimiento valido");
	}else{
		printf("\nMovimiento invalido");
	}
}
int main(void) {
	printf("\nIntroduzca el tamaño del tablero: ");
	scanf("%i",&boardSize);
	boardSize=check_size_board(boardSize);
	move_player();
	return EXIT_SUCCESS;
}
