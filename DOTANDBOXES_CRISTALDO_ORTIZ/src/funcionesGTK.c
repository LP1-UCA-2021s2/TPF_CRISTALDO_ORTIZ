/*
 * funciones.c
 *
 *  Created on: 18 oct. 2021
 *      Author: lp1-2021
 */
#include "declaracionesGTK.h"
#include "declaraciones.h"
int flag1=0;
char *imagenes[] = {"img/punto.png",
					"img/vacio1.png",
					"img/linea.png",
					"img/lineavertical.png",
					"img/linea1.png",
					"img/lineavertical1.png",
					"img/lleno1.png",
					"img/lleno2.png"};
int add_points[2] = {0,0};
//posi 0 para la pc
//posi 1 para el jugador
/*FUNCIONES*/
int random_number(int max,int min){
	/*
	 * Funcion que me genera numeros aleatorios entre dos numeros.
	 * Parámetros:
	 * 	max -> cota superior
	 * 	min -> cota interior
	 * Retorno:
	 *  El numero aleatorio entre la cota superior y la cota inferior.
	 */
	return rand()%(max-min+1) + min;
}
void check_size_board(int number){
	/*
	 * Funcion que verifica el tamaño para el tablero que introduce el usuario.
	 * Parámetros:
	 *  number -> tamaño del tablero que elige el usuario
	 * Retorno:
	 * 	El tamaño verificado que cumpla las condiciones de mayor o igual a 3 o menor o igual a 15.
	 */
	if(number<3 || number>15){
		dialog = gtk_message_dialog_new(GTK_WINDOW(window_choiceBoardSize),
			      GTK_DIALOG_DESTROY_WITH_PARENT,
			      GTK_MESSAGE_WARNING,
			      GTK_BUTTONS_OK,
			      "Introduzca un valor valido para el tamaño del tablero.");
	gtk_window_set_title(GTK_WINDOW(dialog), "Error");
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
	}else{
		gtk_box_pack_start(GTK_BOX(box_board), crear_tablero(), TRUE, FALSE, 20);
		gtk_label_set_text(GTK_LABEL(label_pointsPlayer1),"Puntos : 0");
		gtk_label_set_text(GTK_LABEL(label_pointsPlayer2),"Puntos : 0");
		gtk_widget_show_all(window_board);
		gtk_widget_hide(window_choiceBoardSize);
	}
}
void choice_colors(int option){
	/*
	* Procedimiento que permite 2 opciones, que el usuario seleccione el color deseado o se selecciona
	* aleatoriamente.
	* Parametros:
	* 	color1 -> posicion en la memoria para el color del jugador 1
	* 	color2 -> posicion en la memoria para el color del jugador 2
	* Retorno:
	*  	Ninguno
	*/
	int color;
	if(option == TRUE){
		//El usuario elige el color que desea
		gtk_widget_show_all(window_choiceColor);
		gtk_widget_hide(window_turnSelected);
	}else{
		//puts("Elección de color aleatoriamente");
		gtk_label_set_text(GTK_LABEL(label_namePlayer1),name1);
		gtk_label_set_text(GTK_LABEL(label_namePc1),name2);
		color=random_number(1,0);
		if(color == TRUE){
			//El jugador le toca el rojo y a la pc el azul
			ColorPlayer1=RED;
			ColorPlayer2=BLUE;
			gtk_image_set_from_file(GTK_IMAGE(image_color1),"img/color1.png");
			gtk_image_set_from_file(GTK_IMAGE(image_color2),"img/color2.png");
		}else{
			//A la pc le toca el roja y al jugador el azul
			ColorPlayer1=BLUE;
			ColorPlayer2=RED;
			gtk_image_set_from_file(GTK_IMAGE(image_color1),"img/color2.png");
			gtk_image_set_from_file(GTK_IMAGE(image_color2),"img/color1.png");
		}
		gtk_widget_show_all(window_colorSelected);
		gtk_widget_hide(window_turnSelected);
	}
}
void choice_board(int option){
	/*
	* Funcion que permite 2 opciones, si el usuario quiere definir el tamaño del tablero o
	* se selecciona aleatoriamente.
	* Parametros:
	* 	Ninguno.
	* Retorno:
	* 	Retorna la posicion en la memoria del tablero con su tamaño ya definido.
	*/
	if(option == TRUE){
		gtk_widget_show_all(window_choiceBoardSize);
		gtk_widget_hide(window_colorSelected);
		}else{
			boardSize = random_number(15,3);
			gtk_box_pack_start(GTK_BOX(box_board), crear_tablero(), TRUE, FALSE, 20);
			gtk_label_set_text(GTK_LABEL(label_pointsPlayer1),"Puntos : 0");
			gtk_label_set_text(GTK_LABEL(label_pointsPlayer2),"Puntos : 0");
			gtk_widget_show_all(window_board);
			gtk_widget_hide(window_colorSelected);
		}
}
void choice_turns(int choice){
	/*
	* Funcion que permite 2 opciones, que el usuario eliga quien comienza o se selecciona aleatoriamente.
	* Parametros:
	* 	Ninguno.
	* Retorno:
	* 	CPU		-> Si comienza el CPU
	* 	PLAYER 	-> Si comienza el jugador
	*/
	int player;
	if(choice==TRUE){
		//El usuario elige quien comienza
		gtk_widget_show_all(window_choiceTurn);
		gtk_widget_hide(window_name);
		gtk_label_set_text(GTK_LABEL(label_namePlayer),name1);
		gtk_label_set_text(GTK_LABEL(label_namePc),name2);
	}else{
		//Se elige quien comienza aleatoriamente
		player = random_number(1,0);
		if(player == TRUE){
			//empieza la pc
			PlayerFirtsTurn=CPU;
			gtk_image_set_from_file(GTK_IMAGE(image_playerFirtsTurn),"img/pc.jpg");
			gtk_label_set_text(GTK_LABEL(label_nameFirtsTurn),name2);
		}else{
			PlayerFirtsTurn=PLAYER;
			gtk_image_set_from_file(GTK_IMAGE(image_playerFirtsTurn),"img/jugador.jpg");
			gtk_label_set_text(GTK_LABEL(label_nameFirtsTurn),name1);
		}
		gtk_widget_show_all(window_turnSelected);
		gtk_widget_hide(window_name);
	}
}
void move_pc(){
	/*
	 * Funcion que realiza los movimientos de la computadora.
	 * Parametros:
	 * 	board	-> posicion en la memoria del tablero.
	 * 	color 	-> color que corresponde para la CPU.
	 * Retorno:
	 * 	TRUE 	-> si se formo una caja.
	 * 	FALSE	-> si no se formo una caja.
	 */
	int max=(boardSize+(boardSize-1))-1;
	gtk_label_set_text(GTK_LABEL(label_turn),name2);
	int row,column,flag;
	getsPosition(ColorPlayer2);
	printf("\nTurno de la CPU");
	line();
	printf("\nEligiendo.....");
	row=random_number(max,0);
	column=random_number(max,0);
	while(logicBoard[row][column]!=0){
		row=random_number(max,0);
		column=random_number(max,0);
	}
	printf("\nPosicion a poner la linea: %i, %i",row,column);
	logicBoard[row][column]=select_color(ColorPlayer2);
	if(row%2==0 && column%2!=0){
		gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),column,row)),imagenes[horizontal]);
	}else{
		if(row%2!=0 && column%2==0){
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),column,row)),imagenes[vertical]);
		}
	}
	flag=verify_move(logicBoard,&row,&column,CPU,ColorPlayer2);
	gtk_label_set_text(GTK_LABEL(label_turn),name1);
	printf(" %i ",flag);
	print_board(logicBoard);
	if(end_game(logicBoard)==((boardSize-1)*(boardSize-1))){
		winer();
		flag=FALSE;
	}else{
		if(flag==TRUE){
			move_pc();
		}
	}
}
void move_player(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	int row,column;
	guint i,j;
	i = (GUINT_FROM_LE(event->y) / 15); //las imagenes tienen son 50x50pixeles
	j = (GUINT_FROM_LE(event->x) / 15);
	row=i;
	column=j;
	gtk_label_set_text(GTK_LABEL(label_turn),name1);
	if(logicBoard[row][column]==0){
	//Parte logica
	logicBoard[row][column]=select_color(ColorPlayer1);
	flag1=verify_move(logicBoard,&row,&column,PLAYER,ColorPlayer1);
	printf("\nTurno del jugador");
	line();
	print_board(logicBoard);
	//Parte de alzar la imagen gtk
	getsPosition(ColorPlayer1);
	if(i%2==0 && j%2!=0){
		gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),column,row)),imagenes[horizontal]);
	}else{
		if(i%2!=0 && j%2==0){
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),column,row)),imagenes[vertical]);
		}
	}
	if(flag1==FALSE){
		move_pc();
		print_board(logicBoard);
	}else{
		flag1=FALSE;
	}
	}else{
		dialog = gtk_message_dialog_new(GTK_WINDOW(window_name),
				GTK_DIALOG_DESTROY_WITH_PARENT,
				GTK_MESSAGE_WARNING,
				GTK_BUTTONS_OK,
				"Error, seleccion una posicion valida.");
		gtk_window_set_title(GTK_WINDOW(dialog), "Error");
		gtk_dialog_run(GTK_DIALOG(dialog));
		gtk_widget_destroy(dialog);
	}
	printf("\n%i",end_game(logicBoard));
	printf("\n%i",boardSize+1);
	if(end_game(logicBoard)==((boardSize-1)*(boardSize-1))){
		winer();
	}
}
void open_statistics(GtkWidget *widget, gpointer data){
	/*
	 * Procedimiento que abre la ventana de estadisticas
	*/
	gtk_widget_show_all(window_statistics);
	gtk_widget_hide(window_menu);
}
void open_credits(GtkWidget *widget, gpointer data){
	gtk_widget_show_all(window_credits);
	gtk_widget_hide(window_menu);
}
void open_newGame(GtkWidget *widget, gpointer data){
	gtk_widget_show_all(window_name);
	gtk_widget_hide(window_menu);
}
void emptyLabels(GtkWidget *label){
	const gchar *empty="";
	gtk_label_set_text(GTK_LABEL(label),empty);
}
void emptyEntry(GtkWidget *entry){
	const gchar *empty="";
	gtk_entry_set_text(GTK_ENTRY(entry),empty);
}
void isClickedExit(GtkWidget *widget, gpointer data){
	exit(1);
}
void isClickedBack1(GtkWidget *widget, gpointer data){
	/*Cuando se vuelve de la ventana estadisticas al menu*/
	gtk_widget_hide(window_statistics);
	gtk_widget_show_all(window_menu);
}
void isClickedBack2(GtkWidget *widget, gpointer data){
	/*Cuando se vuelve de la ventana estadisticas al menu*/
	emptyLabels(label_description);
	gtk_widget_hide(window_credits);
	gtk_widget_show_all(window_menu);
	gtk_image_set_from_file(GTK_IMAGE(image_programmer),"img/vacio.png");
}
void isClickedBack3(GtkWidget *widget, gpointer data){
	/*Cuando se vuelve de la ventana name al menu*/
			dialog = gtk_message_dialog_new(GTK_WINDOW(window_choiceTurn),
					           GTK_DIALOG_DESTROY_WITH_PARENT,
					           GTK_MESSAGE_QUESTION,
					           GTK_BUTTONS_YES_NO,
					           "Estas seguro que desea salir?, no se guardara la partida actual.");
			gtk_window_set_title(GTK_WINDOW(dialog), "Salir?");
			if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
				emptyEntry(txt_player);
				emptyEntry(txt_pc);
				gtk_widget_hide(window_name);
				gtk_widget_show_all(window_menu);
			}
			gtk_widget_destroy(dialog);
}
void isClickedBack4(GtkWidget *widget, gpointer data){
	/*Cuando se vuelve de la ventana choiceTurn a name*/
	gtk_widget_hide(window_choiceTurn);
	gtk_widget_show_all(window_name);
}
void isClickedBack5(GtkWidget *widget, gpointer data){
	gtk_widget_hide(window_turnSelected);
	gtk_widget_show_all(window_choiceTurn);
}
void isClickedBack6(GtkWidget *widget, gpointer data){
	/*Cuando se vuelve de la ventana choiceColor a turnSelected*/
	gtk_widget_hide(window_choiceColor);
	gtk_widget_show_all(window_turnSelected);
}
void isClickedBack7(GtkWidget *widget, gpointer data){
	/*Cuando se vuelve de la ventana turnSelected a choiceColor*/
	gtk_widget_hide(window_colorSelected);
	gtk_widget_show_all(window_choiceColor);
}
void isClickedBack8(GtkWidget *widget, gpointer data){
	/*Cuando se vuelve de la ventana choiceColor a turnSelected*/
	gtk_widget_hide(window_choiceBoardSize);
	gtk_widget_show_all(window_colorSelected);
}
void isClickedCancel1(GtkWidget *widget, gpointer data){
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_choiceTurn),
				           GTK_DIALOG_DESTROY_WITH_PARENT,
				           GTK_MESSAGE_QUESTION,
				           GTK_BUTTONS_YES_NO,
				           "Estas seguro que desea salir?, no se guardara la partida actual.");
		gtk_window_set_title(GTK_WINDOW(dialog), "Salir?");
		if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
			emptyEntry(txt_player);
			emptyEntry(txt_pc);
			emptyEntry(txt_boardSize);
			gtk_widget_hide(window_choiceTurn);
			gtk_widget_show_all(window_menu);
		}
	gtk_widget_destroy(dialog);
}
void isClickedCancel2(GtkWidget *widget, gpointer data){
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_choiceTurn),
				           GTK_DIALOG_DESTROY_WITH_PARENT,
				           GTK_MESSAGE_QUESTION,
				           GTK_BUTTONS_YES_NO,
				           "Estas seguro que desea salir?, no se guardara la partida actual.");
		gtk_window_set_title(GTK_WINDOW(dialog), "Salir?");
		if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
			emptyEntry(txt_player);
			emptyEntry(txt_pc);
			emptyEntry(txt_boardSize);
			gtk_widget_hide(window_turnSelected);
			gtk_widget_show_all(window_menu);
		}
	gtk_widget_destroy(dialog);
}
void isClickedCancel3(GtkWidget *widget, gpointer data){
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_choiceTurn),
				           GTK_DIALOG_DESTROY_WITH_PARENT,
				           GTK_MESSAGE_QUESTION,
				           GTK_BUTTONS_YES_NO,
				           "Estas seguro que desea salir?, no se guardara la partida actual.");
		gtk_window_set_title(GTK_WINDOW(dialog), "Salir?");
		if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
			emptyEntry(txt_player);
			emptyEntry(txt_pc);
			emptyEntry(txt_boardSize);
			gtk_widget_hide(window_choiceColor);
			gtk_widget_show_all(window_menu);
		}
	gtk_widget_destroy(dialog);
}
void isClickedCancel4(GtkWidget *widget, gpointer data){
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_choiceTurn),
				           GTK_DIALOG_DESTROY_WITH_PARENT,
				           GTK_MESSAGE_QUESTION,
				           GTK_BUTTONS_YES_NO,
				           "Estas seguro que desea salir?, no se guardara la partida actual.");
		gtk_window_set_title(GTK_WINDOW(dialog), "Salir?");
		if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
			emptyEntry(txt_player);
			emptyEntry(txt_pc);
			emptyEntry(txt_boardSize);
			gtk_widget_hide(window_colorSelected);
			gtk_widget_show_all(window_menu);
		}
	gtk_widget_destroy(dialog);
}
void isClickedCancel5(GtkWidget *widget, gpointer data){
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_choiceTurn),
				           GTK_DIALOG_DESTROY_WITH_PARENT,
				           GTK_MESSAGE_QUESTION,
				           GTK_BUTTONS_YES_NO,
				           "Estas seguro que desea salir?, no se guardara la partida actual.");
		gtk_window_set_title(GTK_WINDOW(dialog), "Salir?");
		if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
			emptyEntry(txt_player);
			emptyEntry(txt_pc);
			emptyEntry(txt_boardSize);
			gtk_widget_hide(window_choiceBoardSize);
			gtk_widget_show_all(window_menu);
		}
	gtk_widget_destroy(dialog);
}

void isClickedPlayer(GtkWidget *widget, gpointer data){
	/*Funcion cuando se apreta el boton para seleccionar quien comienza primero*/
	PlayerFirtsTurn=PLAYER;
	gtk_label_set_text(GTK_LABEL(label_nameFirtsTurn),name1);
	gtk_image_set_from_file(GTK_IMAGE(image_playerFirtsTurn),"img/jugador.jpg");
	gtk_widget_hide(window_choiceTurn);
	gtk_widget_show_all(window_turnSelected);
}
void isClickedPc(GtkWidget *widget, gpointer data){
	PlayerFirtsTurn=CPU;
	gtk_label_set_text(GTK_LABEL(label_nameFirtsTurn),name2);
	gtk_image_set_from_file(GTK_IMAGE(image_playerFirtsTurn),"img/pc.jpg");
	gtk_widget_hide(window_choiceTurn);
	gtk_widget_show_all(window_turnSelected);
}
void isClickedEthel(GtkWidget *widget, gpointer data){
	gtk_image_set_from_file(GTK_IMAGE(image_programmer),"img/Ethel.jpg");
	gtk_label_set_text(GTK_LABEL(label_description),"Ayudo con el diseño de la interfaz");
}
void isClickedDaniela(GtkWidget *widget, gpointer data){
	gtk_image_set_from_file(GTK_IMAGE(image_programmer),"img/Danusita.jpg");
	gtk_label_set_text(GTK_LABEL(label_description),"Programo y lloro");
}
void isClickedColor1(GtkWidget *widget, gpointer data){
	ColorPlayer1=RED;
	ColorPlayer2=BLUE;
	gtk_widget_hide(window_choiceColor);
	gtk_widget_show_all(window_colorSelected);
	gtk_label_set_text(GTK_LABEL(label_namePlayer1),name1);
	gtk_label_set_text(GTK_LABEL(label_namePc1),name2);
	gtk_image_set_from_file(GTK_IMAGE(image_color1),"img/color1.png");
	gtk_image_set_from_file(GTK_IMAGE(image_color2),"img/color2.png");
}
void isClickedColor2(GtkWidget *widget, gpointer data){
	ColorPlayer1=BLUE;
	ColorPlayer2=RED;
	gtk_widget_hide(window_choiceColor);
	gtk_widget_show_all(window_colorSelected);
	gtk_label_set_text(GTK_LABEL(label_namePlayer1),name1);
	gtk_label_set_text(GTK_LABEL(label_namePc1),name2);
	gtk_image_set_from_file(GTK_IMAGE(image_color1),"img/color2.png");
	gtk_image_set_from_file(GTK_IMAGE(image_color2),"img/color1.png");
}
void isClickedNext1(GtkWidget *widget, gpointer data){
	playerName[0]='\0';
	pcName[0]='\0';
	name1=gtk_entry_get_text(GTK_ENTRY(txt_player));
	name2=gtk_entry_get_text(GTK_ENTRY(txt_pc));
	sprintf(playerName,"%s",name1);
	sprintf(pcName,"%s",name2);
	if(name1[0]=='\0' || name2[0]=='\0'){
		//Verifica que se completaran los campos
		  dialog = gtk_message_dialog_new(GTK_WINDOW(window_name),
		            GTK_DIALOG_DESTROY_WITH_PARENT,
		            GTK_MESSAGE_WARNING,
		            GTK_BUTTONS_OK,
		            "Error, complete los campos.");
		  gtk_window_set_title(GTK_WINDOW(dialog), "Error");
		  gtk_dialog_run(GTK_DIALOG(dialog));
		  gtk_widget_destroy(dialog);
	}else{
		dialog = gtk_message_dialog_new(GTK_WINDOW(window_name),
		            GTK_DIALOG_DESTROY_WITH_PARENT,
		            GTK_MESSAGE_QUESTION,
		            GTK_BUTTONS_YES_NO,
		            "Dese elegir quien comienza primero?");
		gtk_window_set_title(GTK_WINDOW(dialog), "Consultita");
		choice_turns(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES);
		gtk_widget_destroy(dialog);
	}
}
void isClickedNext2(GtkWidget *widget, gpointer data){
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_name),
			            GTK_DIALOG_DESTROY_WITH_PARENT,
			            GTK_MESSAGE_QUESTION,
			            GTK_BUTTONS_YES_NO,
			            "Desea elegir el color?");
	gtk_window_set_title(GTK_WINDOW(dialog), "Consultita");
	choice_colors(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES);
	gtk_widget_destroy(dialog);
}
void isClickedNext3(GtkWidget *widget, gpointer data){
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_name),
			            GTK_DIALOG_DESTROY_WITH_PARENT,
			            GTK_MESSAGE_QUESTION,
			            GTK_BUTTONS_YES_NO,
			            "Desea elegir el tamaño del tablero?");
	gtk_window_set_title(GTK_WINDOW(dialog), "Consultita");
	choice_board(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES);
	gtk_widget_destroy(dialog);
}
void isClickedNext4(GtkWidget *widget, gpointer data){
	const gchar *size=gtk_entry_get_text(GTK_ENTRY(txt_boardSize));
	char acumuletor[2];
	sprintf(acumuletor,"%s",size);
	boardSize=atoi(acumuletor);
	check_size_board(atoi(acumuletor));
}
void getsPosition(int color){
	switch(color){
	case 4:
		//Color rojo
		horizontal=2;
		vertical=3;
		break;
	case 5:
		horizontal=4;
		vertical=5;
	}
}

GtkWidget *crear_tablero(){
	int i, j,size;
	size=(boardSize+(boardSize+1));
	logicBoard=create_board(size);
	initialize_board(logicBoard);
 //auxiliar para cargar la imagen
	eventbox = gtk_event_box_new();
	board = gtk_grid_new();
	//Inicializa mi matriz logica para el juego
	for (i = 0; i < boardSize+(boardSize-1); i++) {
		for (j = 0; j < boardSize+(boardSize-1); j++) {
			if(i%2==0 && j%2==0){
				image = gtk_image_new_from_file(imagenes[0]);
				gtk_grid_attach(GTK_GRID(board), GTK_WIDGET(image), j, i, 1, 1);
			}else{
				image = gtk_image_new_from_file(imagenes[1]);
				gtk_grid_attach(GTK_GRID(board), GTK_WIDGET(image), j, i, 1, 1);
			}
		}
	}
	gtk_container_add(GTK_CONTAINER(eventbox), board);
	if(PlayerFirtsTurn==CPU){
		move_pc();
		gtk_label_set_text(GTK_LABEL(label_turn),name2);
	}
	g_signal_connect(eventbox, "button-press-event", G_CALLBACK(move_player),board);
	return eventbox;
}
void emptyBoard(){
	int i, j;
	for (i = 0; i < boardSize+(boardSize-1); i++) {
			for (j = 0; j < boardSize+(boardSize-1); j++) {
				if(i%2==0 && j%2==0){
					gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),j,i)),imagenes[0]);
				}else{
					gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),j,i)),imagenes[1]);
				}
			}
		}
}
void isClickedPause(GtkWidget *widget, gpointer data){
	gtk_widget_set_sensitive(window_board,FALSE);
	gtk_widget_show_all(window_pause);
}
void isClickedContinue(GtkWidget *widget, gpointer data){
	gtk_widget_hide(window_pause);
	gtk_widget_set_sensitive(window_board,TRUE);
}
void isClickedStarAgain(GtkWidget *widget, gpointer data){
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_pause),
		         GTK_DIALOG_DESTROY_WITH_PARENT,
		         GTK_MESSAGE_QUESTION,
		         GTK_BUTTONS_YES_NO,
		         "Estas seguro que desea salir?");
	gtk_window_set_title(GTK_WINDOW(dialog), "Consultita");
	if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
		add_points[0]=0;
		add_points[1]=0;
		gtk_widget_set_sensitive(window_board,TRUE);
		gtk_widget_hide(window_pause);
		emptyBoard();
		gtk_label_set_text(GTK_LABEL(label_pointsPlayer1),"Puntos : 0");
		gtk_label_set_text(GTK_LABEL(label_pointsPlayer2),"Puntos : 0");
		initialize_board(logicBoard);
	}
	gtk_widget_destroy(dialog);
}
void isCLickedOk(GtkWidget *widget, gpointer data){
	emptyEntry(txt_player);
	emptyEntry(txt_pc);
	emptyEntry(txt_boardSize);
	add_points[0]=0;
	add_points[1]=0;
	free(logicBoard);
	gtk_widget_hide(window_winer);
	gtk_widget_destroy(eventbox);
	gtk_widget_show_all(window_menu);
}
void isClickedMenu(GtkWidget *widget, gpointer data){
	emptyEntry(txt_player);
	emptyEntry(txt_pc);
	emptyEntry(txt_boardSize);
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_pause),
	            GTK_DIALOG_DESTROY_WITH_PARENT,
	            GTK_MESSAGE_QUESTION,
	            GTK_BUTTONS_YES_NO,
	            "Estas seguro que desea salir?");
	  gtk_window_set_title(GTK_WINDOW(dialog), "Consultita");
	  if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
		  free(logicBoard);
		  gtk_widget_hide(window_pause);
		  gtk_widget_hide(window_board);
		  gtk_widget_destroy(eventbox);
		  gtk_widget_set_sensitive(window_board,TRUE);
		  gtk_widget_show_all(window_menu);
	  }
	  gtk_widget_destroy(dialog);
}
void winer(){
	if(add_points[CPU]>add_points[PLAYER]){
		printf("GANO LA PC Puntos de la cpu: %i y del juagdor %i",add_points[CPU],add_points[PLAYER]);
		gtk_label_set_text(GTK_LABEL(label_status),"GANO LA PC");
		gtk_image_set_from_file(GTK_IMAGE(image_winner),"img/pc.jpg");
	}else{
		if(add_points[CPU]==add_points[PLAYER]){
			printf("EMPATE Puntos de la cpu: %i y del juagdor %i",add_points[CPU],add_points[PLAYER]);
			gtk_label_set_text(GTK_LABEL(label_status),"EMPATE");
		}else{
			if(add_points[CPU]<add_points[PLAYER]){
				printf("GANO EL JUGADOR Puntos de la cpu: %i y del juagdor %i",add_points[CPU],add_points[PLAYER]);
				gtk_label_set_text(GTK_LABEL(label_status),"GANO EL JUGADOR");
				gtk_image_set_from_file(GTK_IMAGE(image_winner),"img/jugador.jpg");
			}
		}
	}
	gtk_widget_hide(window_board);
	gtk_widget_show_all(window_winer);
}
void setSquare(int row,int column,int color){
	if(color==4){
		gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),column,row)),imagenes[6]);
	}else{
		gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),column,row)),imagenes[7]);
	}
}
int verify_move(int **board,int *row,int *column,int player,int color){
	/*
	* Funcion que verifica si en donde se puso la linea se formo una caja en el EMPTYBOX
	* si se formo modifica el valor de este por RED o BLUE
	* Parametros:
	* 	board	-> posicion en la memoria del tablero.
	* 	row		-> posicion del valor de la fila donde se realizo el movimiento.
	* 	column	-> posicion del valor de la columna donde se realizo el movimiento.
	* 	player  -> jugador que realizo el movimiento.
	* 	color	-> color del jugador que corresponde la jugada.
	* Retorno:
	*  Retorna flag que es una bandera, puede tener valores 1 o 0
	*  TRUE		-> si se formo la caja
	*  FALSE	-> si no se formo una caja
	*/
	int acumuletor,flag=FALSE;
	for(int i=0;i<boardSize+(boardSize-1);i++){
		for(int j=0;j<boardSize+(boardSize-1);j++){
			if(i%2!=0 && j%2!=0){
				if(i-1==*row && j==*column){
					if(box(board,*row+1,*column)){
						acumuletor=*row+1;
						board[acumuletor][*column]=select_color(color);
						setSquare(acumuletor,*column,color);
						add_points[player]+= 10;
						setPoints(add_points[player],player);
						flag=TRUE;
					}
				}
				if(i+1==*row && j==*column){
					if(box(board,*row-1,*column)){
						acumuletor=*row-1;
						board[acumuletor][*column]=select_color(color);
						setSquare(acumuletor,*column,color);
						add_points[player]+= 10;
						setPoints(add_points[player],player);
						flag=TRUE;
					}
				}
				if(j-1==*column && i==*row){
					if(box(board,*row,*column+1)){
						acumuletor=*column+1;
						board[*row][acumuletor]=select_color(color);
						setSquare(*row,acumuletor,color);
						add_points[player]+= 10;
						setPoints(add_points[player],player);
						flag=TRUE;
					}
				}
				if(j+1==*column && i==*row){
					if(box(board,*row,*column-1)){
						acumuletor=*column-1;
						board[*row][acumuletor]=select_color(color);
						setSquare(*row,acumuletor,color);
						add_points[player]+= 10;
						setPoints(add_points[player],player);
						flag=TRUE;
					}
				}
			}
		}
	}
	return flag;
}
void setPoints(int points,int player){
	gchar *temp = g_strdup_printf("Puntos : %i ",points);
	if(player==PLAYER){
		gtk_label_set_text(GTK_LABEL(label_pointsPlayer1),temp);
	}else{
		gtk_label_set_text(GTK_LABEL(label_pointsPlayer2),temp);
	}
	g_free(temp);
}

