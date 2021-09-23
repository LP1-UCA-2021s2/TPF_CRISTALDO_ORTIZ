/*
 * datos.h
 *
 *  Created on: 21 sept. 2021
 *      Author: lp1-2021
 */

#ifndef SRC_DATOS_H_
#define SRC_DATOS_H_
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define TRUE 1
#define FALSE 0
#define DOT 1
#define LINE 2
#define VERTICALINE 5
#define EMPTYBOX 3
#define BOX 4
#define PLAYER1 0
#define PLAYER2 1
#define RED 0
#define BLUE 1
int boardSize;
//funciones
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
	printf("\n");
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

#endif /* SRC_DATOS_H_ */
