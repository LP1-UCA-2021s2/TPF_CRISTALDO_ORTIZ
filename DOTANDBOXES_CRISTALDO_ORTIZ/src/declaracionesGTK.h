/*
 * declaracionesGTK.h
 *
 *  Created on: 8 oct. 2021
 *      Author: lp1-2021
 */

#ifndef SRC_DECLARACIONESGTK_H_
#define SRC_DECLARACIONESGTK_H_
#include <gtk/gtk.h>
GtkBuilder *builder;
/*VENTANAS*/
GtkWidget *window_menu; //Ventana del menu principial (lo que se ve al comienzo).
GtkWidget *window_name; //Ventana para poder introducir los nombres, el del jugador y el rival.
GtkWidget *window_statistics; //Ventana que se visualizara las estadisticas de las partidas.
GtkWidget *window_credits; //Ventana para los creditos, donde aparecen los nombres de los integrates del proyecto
GtkWidget *window_choiceBoardSize; //Ventana para que el usuario introduzca el tamaño del tablero.
GtkWidget *window_choiceColor; //Ventana que permite seleccionar al jugador el color.
GtkWidget *window_choiceTurn; //Ventana que permite al jugador que seleccione quien comienza primero.
GtkWidget *window_colorSelected; //Ventana que visualiza el color que corresponde el color para cada jugador.
GtkWidget *window_pause; //Ventana de pausa que tiene los botones continuar comenzar de nuevo y menu (para salir de la partida)
GtkWidget *window_turnSelected; //Ventana que visualiza quien comenza primero si el jugador o el rival.
GtkWidget *window_board; //Ventana en donde se desarrolla el juego, se muestra el tablero los turno y los puntos.
GtkWidget *window_winner; //Ventana que visualiza quien gano el juego.
/*IMAGENES*/
GtkWidget *image_programmer;
GtkWidget *image_playerFirtsTurn;
GtkWidget *image_color1;
GtkWidget *image_color2;
GtkWidget *image_player1;
GtkWidget *image_player2;
GtkWidget *image_winner;
/*BOTONES*/
//Botones del menu principal
GtkWidget *btn_newGame;
GtkWidget *btn_statistics;
GtkWidget *btn_credits;
GtkWidget *btn_exit;
//Botones back
GtkWidget *btn_back1;
GtkWidget *btn_back2;
GtkWidget *btn_back3;
GtkWidget *btn_back4;
GtkWidget *btn_back5;
GtkWidget *btn_back6;
GtkWidget *btn_back7;
GtkWidget *btn_back8;
//Botones next
GtkWidget *btn_next1;
GtkWidget *btn_next2;
GtkWidget *btn_next3;
GtkWidget *btn_next4;
//Botones cancel
GtkWidget *btn_cancel1;
GtkWidget *btn_cancel2;
GtkWidget *btn_cancel3;
GtkWidget *btn_cancel4;
GtkWidget *btn_cancel5;
//Otros botones
GtkWidget *btn_help;
GtkWidget *btn_player;
GtkWidget *btn_pc;
GtkWidget *btn_ethel;
GtkWidget *btn_daniela;
GtkWidget *btn_color1;
GtkWidget *btn_color2;
GtkWidget *btn_ok;
GtkWidget *btn_pause;
GtkWidget *btn_continue;
GtkWidget *btn_starAgain;
GtkWidget *btn_menu;
GtkWidget *btn_nextPlayer;

/*ENTRADAS*/
GtkWidget *txt_player;
GtkWidget *txt_pc;
GtkWidget *txt_boardSize;
/*LABELS*/
GtkWidget *label_description;
GtkWidget *label_namePlayer;
GtkWidget *label_namePc;
GtkWidget *label_nameFirtsTurn;
GtkWidget *label_namePlayer1;
GtkWidget *label_namePc1;
GtkWidget *label_turn;
GtkWidget *label_status;
GtkWidget *label_pointsPlayer1;
GtkWidget *label_pointsPlayer2;
GtkWidget *label_points;
/*Dialogos*/
GtkWidget *dialog;

/*OTROS*/
GtkWidget *board;
GtkWidget *box_board;
GtkWidget *eventbox;
GtkWidget *image;

const gchar *name1;
const gchar *name2;

/*FUNCIONES*/
GtkWidget *crear_tablero();
void open_statistics(GtkWidget *widget, gpointer data);
void open_credits(GtkWidget *widget, gpointer data);
void open_newGame(GtkWidget *widget, gpointer data);
void emptyLabels(GtkWidget *label);
void emptyEntry(GtkWidget *entry);
void isClickedExit(GtkWidget *widget, gpointer data);
void isClickedBack(GtkWidget *widget, gpointer data);
void isClickedCancel(GtkWidget *widget, gpointer data);
void isClickedPlayer(GtkWidget *widget, gpointer data);
void isClickedPc(GtkWidget *widget, gpointer data);
void isClickedEthel(GtkWidget *widget, gpointer data);
void isClickedDaniela(GtkWidget *widget, gpointer data);
void isClickedNext1(GtkWidget *widget, gpointer data);
void isClickedNext2(GtkWidget *widget, gpointer data);
void isClickedNext3(GtkWidget *widget, gpointer data);
void isClickedNext4(GtkWidget *widget, gpointer data);
void isClickedColor1(GtkWidget *widget, gpointer data);
void isClickedColor2(GtkWidget *widget, gpointer data);
void move_player(GtkWidget *event_box, GdkEventButton *event, gpointer data);
void isClickedPause(GtkWidget *widget, gpointer data);
void isClickedContinue(GtkWidget *widget, gpointer data);
void isClickedMenu(GtkWidget *widget, gpointer data);
void isClickedStarAgain(GtkWidget *widget, gpointer data);
void isClickedBack1(GtkWidget *widget, gpointer data);
void isClickedBack2(GtkWidget *widget, gpointer data);
void isClickedBack3(GtkWidget *widget, gpointer data);
void isClickedBack4(GtkWidget *widget, gpointer data);
void isClickedBack5(GtkWidget *widget, gpointer data);
void isClickedBack6(GtkWidget *widget, gpointer data);
void isClickedBack7(GtkWidget *widget, gpointer data);
void isClickedBack8(GtkWidget *widget, gpointer data);
void isClickedCancel1(GtkWidget *widget, gpointer data);
void isClickedCancel2(GtkWidget *widget, gpointer data);
void isClickedCancel3(GtkWidget *widget, gpointer data);
void isClickedCancel4(GtkWidget *widget, gpointer data);
void isClickedCancel5(GtkWidget *widget, gpointer data);
void isClickedHelp(GtkWidget *widget,gpointer data);
void getsPosition(int color);
void emptyBoard();
void winner();
void isCLickedOk(GtkWidget *widget, gpointer data);
void setSquare(int row,int column,int color);
void setPoints(int points,int player);
void isCLickedNextPlayer(GtkWidget *widget, gpointer data);
int markFourthLine(int **logicBoard,int *row,int *column,int color,int player);
void placeLinesInTheGrid(int row,int column,int color);
void randomLine(int number,int *row,int *column);
int exitsMoves(int **board);
void cleanChain(int **board);
void placeLine(int **board,int *rowOdd,int *columnOdd);
void validMove(int **board,int *rowOdd,int *columnOdd,int aux1);
#endif /* SRC_DECLARACIONESGTK_H_ */
