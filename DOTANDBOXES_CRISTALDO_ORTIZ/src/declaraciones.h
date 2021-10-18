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
#define DOT 1
#define EMPTYBOX 3
#define CPU 0
#define PLAYER 1
#define RED 4
#define BLUE 5
int boardSize;
int back;
int next;
int cancel;
char playerName[50];
char pcName[50];
	//suma 10 puntos
	//suma los puntos de la cpu en posi 1
	//los puntos del jugador en posi 0
/*FUNCIONES*/
int random_number(int max,int min);
int check_size_board(int number);
void line();
int yes_no_options(int option);
int play_game();
int **create_board(int size);
void initialize_board(int **array);
void print_board(int **array);
int box(int **board,int row, int column);
int select_color(int color);
int verify_move(int **board,int *row,int *column,int player,int color);
void choice_colors(int *color1,int *color2);
int end_game(int **array);
int **choice_board(void);
int choice_turns(void);
int move_pc(int **board,int color);
int move_player(int **array,int color);
void start_game();
#endif /* SRC_DATOS_H_ */
