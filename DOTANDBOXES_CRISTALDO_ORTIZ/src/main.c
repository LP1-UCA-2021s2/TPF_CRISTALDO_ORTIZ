#include "datos.h"
int random_number(int max,int min){
	//Funcion que me genera numeros aleatorios entre dos numeros
	return rand()%(max-min+1) + min;
}
int check_size_board(int number){
	//Verifica el tamaño que el usuario ingresa para el tablero
	while(number<3 || number>15){
		printf("Error, introduzca un valor entre 3 y 15: ");
		scanf("%i",&number);
	}
	return number;
}
int main(void) {
	printf("\nIntroduzca el tamaño del tablero: ");
	scanf("%i",&boardSize);
	boardSize=check_size_board(boardSize);
	return EXIT_SUCCESS;
}
