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
GtkWidget *window_choiceModo;
GtkWidget *window_pcName;
GtkWidget *window_choiceTurn1;
GtkWidget *window_choiceColor1;
GtkWidget *window_turnSelected1;
GtkWidget *window_colorSelected1;
/*IMAGENES*/
GtkWidget *image_programmer;
GtkWidget *image_playerFirtsTurn;
GtkWidget *image_playerFirtsTurn1;
GtkWidget *image_color1;
GtkWidget *image_color2;
GtkWidget *image_color3;
GtkWidget *image_color4;
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
GtkWidget *btn_back9;
//Botones next
GtkWidget *btn_next1;
GtkWidget *btn_next2;
GtkWidget *btn_next3;
GtkWidget *btn_next4;
GtkWidget *btn_next5;
GtkWidget *btn_next6;
GtkWidget *btn_next7;
//Botones cancel
GtkWidget *btn_cancel1;
GtkWidget *btn_cancel2;
GtkWidget *btn_cancel3;
GtkWidget *btn_cancel4;
GtkWidget *btn_cancel5;
GtkWidget *btn_cancel6;
GtkWidget *btn_cancel7;
GtkWidget *btn_cancel8;
GtkWidget *btn_cancel9;
GtkWidget *btn_cancel10;
//Otros botones
GtkWidget *btn_help;
GtkWidget *btn_player;
GtkWidget *btn_pc;
GtkWidget *btn_ethel;
GtkWidget *btn_daniela;
GtkWidget *btn_color1;
GtkWidget *btn_color2;
GtkWidget *btn_color3;
GtkWidget *btn_color4;
GtkWidget *btn_ok;
GtkWidget *btn_pause;
GtkWidget *btn_continue;
GtkWidget *btn_starAgain;
GtkWidget *btn_menu;
GtkWidget *btn_nextPlayer;
GtkWidget *btn_pcVspc;
GtkWidget *btn_pcVsplayer;
GtkWidget *btn_pcLocal;
GtkWidget *btn_pcOponent;
GtkWidget *btn_actualizarTablero;
/*ENTRADAS*/
GtkWidget *txt_player;
GtkWidget *txt_pc;
GtkWidget *txt_boardSize;
GtkWidget *txt_pcLocal;
GtkWidget *txt_pcOponent;
/*LABELS*/
GtkWidget *label_description;
GtkWidget *label_namePcLocal;
GtkWidget *label_namePcOponent;
GtkWidget *label_namePcLocal2;
GtkWidget *label_namePcOponent2;
GtkWidget *label_namePlayer2;
GtkWidget *label_namePlayer;
GtkWidget *label_namePc;
GtkWidget *label_nameFirtsTurn;
GtkWidget *label_nameFirtsTurn1;
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
GtkWidget *box1;
GtkWidget *image;

const gchar *name1;
const gchar *name2;
const gchar *namepc1;
const gchar *namepc2;

/*FUNCIONES*/
GtkWidget *crear_tablero();
int random_number(int max,int min);
int randomOdd(int max,int min);
void open_statistics(GtkWidget *widget, gpointer data);
void open_credits(GtkWidget *widget, gpointer data);
void open_newGame(GtkWidget *widget, gpointer data);
void emptyLabels(GtkWidget *label);
void emptyEntry(GtkWidget *entry);
void isClickedPcVsPlayer(GtkWidget *widget, gpointer data);
void isClickedPcVsPc(GtkWidget *widget, gpointer data);
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
void isClickedNext5(GtkWidget *widget, gpointer data);
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
void isClickedCancel8(GtkWidget *widget, gpointer data);
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
GtkWidget *crear_tableropcvspc();
void placeLine(int **board,int *rowOdd,int *columnOdd);
void validMove(int **board,int *rowOdd,int *columnOdd,int aux1);
void isClickedBack9(GtkWidget *widget, gpointer data);
void isClickedPcLocal(GtkWidget *widget, gpointer data);
void isClickedNext6(GtkWidget *widget, gpointer data);
void isClickedPcOponent(GtkWidget *widget, gpointer data);
void isClickedCancel7(GtkWidget *widget, gpointer data);
void isClickedCancel6(GtkWidget *widget, gpointer data);
void isClickedCancel9(GtkWidget *widget, gpointer data);
void isClickedColor3(GtkWidget *widget, gpointer data);
void isClickedColor4(GtkWidget *widget, gpointer data);
void isClickedCancel10(GtkWidget *widget, gpointer data);
void isClickedNext7(GtkWidget *widget, gpointer data);
void isClickedActualizarTablero(GtkWidget *widget, gpointer data);
void PCVSPC();
GtkWidget *crear_tablero2();
void convertLinesToDots(int *row1,int *column1,int *row2,int *column2,int row,int column);
#endif /* SRC_DECLARACIONESGTK_H_ */
