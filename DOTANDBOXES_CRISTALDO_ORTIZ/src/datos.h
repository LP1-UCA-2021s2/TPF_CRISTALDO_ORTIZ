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
#define EMPTYBOX 3
#define BOX 4
#define CPU 0
#define PLAYER 1
#define RED 4
#define BLUE 5
int boardSize;
int add_points[2] = {0};
	//suma 10 puntos
	//suma los puntos de la cpu en posi 1
	//los puntos del jugador en posi 0
//Funciones
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
void line(){
	//Procedimiento con objetivo meramente estetico
	printf("\n------------------------------------------");
}
#endif /* SRC_DATOS_H_ */
