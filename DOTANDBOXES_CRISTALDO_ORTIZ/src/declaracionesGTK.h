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
GtkWidget *window_menu;
GtkWidget *window_name;
GtkWidget *window_statistics;
GtkWidget *window_credits;
GtkWidget *window_choiceBoardSize;
GtkWidget *window_choiceColor;
GtkWidget *window_choiceTurn;
GtkWidget *window_colorSelected;
GtkWidget *window_pause;
GtkWidget *window_turnSelected;
GtkWidget *window_board;
GtkWidget *window_winer;
GtkWidget *window_chau;
/*IMAGENES*/
GtkWidget *image_programmer;
GtkWidget *image_playerFirtsTurn;
GtkWidget *image_color1;
GtkWidget *image_color2;
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
GtkWidget *btn_player;
GtkWidget *btn_pc;
GtkWidget *btn_ethel;
GtkWidget *btn_daniela;
GtkWidget *btn_color1;
GtkWidget *btn_color2;
GtkWidget *btn_ok;

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

/*Dialogos*/
GtkWidget *dialog;

/*OTROS*/
GtkWidget *board;
GtkWidget *box_board;

const gchar *name1;
const gchar *name2;
const gchar *message;
const gchar *FirtsTurn;

/*FUNCIONES*/
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
void tablero_cb(GtkWidget *event_box, GdkEventButton *event, gpointer data);
GtkWidget *crear_tablero();
#endif /* SRC_DECLARACIONESGTK_H_ */
