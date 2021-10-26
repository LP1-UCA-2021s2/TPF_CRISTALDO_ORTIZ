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
#include <gtk/gtk.h>
#define DOT 1
#define EMPTYBOX 3
#define CPU 0
#define PLAYER 1
#define RED 4
#define BLUE 5
int **logicBoard;
int PlayerFirtsTurn;//	Primer jugador
int boardSize;    // 	Tamaño del tablero
int ColorPlayer1; // 	Color del jugador 1
int ColorPlayer2; // 	Color del jugador 2
int horizontal,vertical;
char playerName[50];
char pcName[50];
	//suma 10 puntos
	//suma los puntos de la PLAYER en posi 1
	//los puntos del CPU en posi 0
/*FUNCIONES*/
int random_number(int max,int min);
void check_size_board(int number);
void line();
int yes_no_options(int option);
int play_game();
int **create_board(int size);
void initialize_board(int **array);
void print_board(int **array);
int box(int **board,int row, int column);
int select_color(int color);
int verify_move(int **board,int *row,int *column,int player,int color);
void choice_colors(int choice);
int end_game(int **array);
void choice_board(int choice);
void choice_turns(int choice);
void move_pc();
#endif /* SRC_DATOS_H_ */
