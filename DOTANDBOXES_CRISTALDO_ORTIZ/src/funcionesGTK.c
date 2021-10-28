/*
 * funciones.c
 *
 *  Created on: 18 oct. 2021
 *      Author: lp1-2021
 */
#include "declaracionesGTK.h"
#include "declaraciones.h"
char *imagenes[] = {"img/punto.png",
		"img/vacio1.png",
		"img/linea.png",
		"img/lineavertical.png",
		"img/linea1.png",
		"img/lineavertical1.png",
		"img/lleno1.png",
		"img/lleno2.png"};//Vector de imagenes para el juego.
int add_points[2] = {0,0}; //Acumulador de puntaje para los jugadores
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
	 * Procedimiento que verifica el tamaño para el tablero que introduce el usuario sea el correcto.
	 * Parámetros:
	 *  number -> tamaño del tablero que elige el usuario
	 * Retorno:
	 * 	Ninguna.
	 */
	if(number<3 || number>15){
		dialog = gtk_message_dialog_new(GTK_WINDOW(window_choiceBoardSize),
				GTK_DIALOG_DESTROY_WITH_PARENT,
				GTK_MESSAGE_WARNING,
				GTK_BUTTONS_OK,
				"Introduzca un valor valido para el tamaño del tablero."
				"\nRecuerde de introducir valores entre 3 y 15");
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
	 * Procedimiento que recibe la opcion elegida por el usuario para la eleccion del color.
	 * Parametros:
	 * 	option -> 	# Si es TRUE se abriran las ventanas window_choiceColor
	 * 				y se cierra la ventana window_turnSelected.
	 * 				# Si es FALSE se seleccionara de forma aleatoria el color para el jugador y el rival
	 * Retorno:
	 *  Ninguno.
	 */
	int color;
	if(option == TRUE){
		//El usuario desea elegir el color con que quisiera jugar.
		gtk_widget_show_all(window_choiceColor);
		gtk_widget_hide(window_turnSelected);
	}else{
		//El usuario no quiere elegir el color con el que jugara.
		gtk_label_set_text(GTK_LABEL(label_namePlayer1),name1);
		gtk_label_set_text(GTK_LABEL(label_namePc1),name2);
		color=random_number(1,0);
		if(color == TRUE){
			//El jugador le toca el rojo y al rival el azul
			ColorPlayer1=RED;
			ColorPlayer2=BLUE;
			gtk_image_set_from_file(GTK_IMAGE(image_color1),"img/color1.png");
			gtk_image_set_from_file(GTK_IMAGE(image_color2),"img/color2.png");
		}else{
			//Al rival le toca el rojo y al jugador el azul
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
	 * Procedimiento que recibe la opcion elegida por el usuario para la eleccion del tamaño del tablero.
	 * Parametros:
	 * 	option -> 	# Si es TRUE se abriran las ventanas window_choiceBoardSize
	 * 				y se cierra la ventana window_colorSelected.
	 * 				# Si es FALSE se seleccionara de forma aleatoria el tamaño del tablero.
	 * Retorno:
	 * 	Ninguno.
	 */
	if(option == TRUE){
		//El jugador acepto elegir el tamaño del tablero.
		gtk_widget_show_all(window_choiceBoardSize);
		gtk_widget_hide(window_colorSelected);
	}else{
		//El jugador no acepto elegir el tamaño del tablero.
		//Se selecciona de forma aleatoria.
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
	 * Procedimiento que recibe la opcion elegida por el usuario para elegir quien de los dos
	 * jugadores comienza.
	 * Parametros:
	 * 	choice -> 	# Si es TRUE se abriran las ventanas window_choiceTurn
	 * 				y se cierra la ventana window_name.
	 * 				# Si es FALSE se seleccionara de forma aleatoria quien comienza primero.
	 * Retorno:
	 * 	Ninguno.
	 */
	int player;
	if(choice==TRUE){
		//El usuario desea eligir quien comienza.
		gtk_widget_show_all(window_choiceTurn);
		gtk_widget_hide(window_name);
		gtk_label_set_text(GTK_LABEL(label_namePlayer),name1);
		gtk_label_set_text(GTK_LABEL(label_namePc),name2);
	}else{
		//Se elige quien comienza aleatoriamente.
		player = random_number(1,0);
		if(player == TRUE){
			//empieza la pc
			PlayerFirtsTurn=CPU;
			gtk_image_set_from_file(GTK_IMAGE(image_playerFirtsTurn),"img/pc.jpg");
			gtk_label_set_text(GTK_LABEL(label_nameFirtsTurn),name2);
		}else{
			//empieza el jugador
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
	 * Procedimiento que se encarga de realizar, verificar y colocar en el
	 * tablero, los movimientos de la computadora.
	 * Parametros:
	 * 	Ninguno.
	 * Retorno:
	 * 	Ninguno.
	 */
	int max=(boardSize+(boardSize-1))-1;
	gtk_label_set_text(GTK_LABEL(label_turn),name2);//Se envia el nombre de la pc en el apartado de turno
	int row,column,flag;
	getsPosition(ColorPlayer2);//Se obtienen las lineas (horizontal y vertical ) que corresponde al color seleccionado para la computadora.
	printf("\nTurno de la CPU");
	line();
	printf("\nEligiendo.....");
	row=random_number(max,0);
	column=random_number(max,0);
	while(logicBoard[row][column]!=0){
		//Se verifica que la computadora ponga en un lugar valido su jugada.
		//Si no se pide que vuelva a buscar un lugar que corresponda.
		row=random_number(max,0);
		column=random_number(max,0);
	}
	printf("\nPosicion a poner la linea: %i, %i",row,column);
	//Se carga en el tablero logico la linea
	logicBoard[row][column]=select_color(ColorPlayer2);
	if(row%2==0 && column%2!=0){
		//se verifica si en la posicion se pone una linea horizontal en el tablero del GTK
		gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),column,row)),imagenes[horizontal]);
	}else{
		//se verifica si en la posicion se pone una linea vertical en el tablero del GTK
		if(row%2!=0 && column%2==0){
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),column,row)),imagenes[vertical]);
		}
	}
	//Se llama a la funcion verify_move que se encarga de verficar si se formo una caja.
	flag=verify_move(logicBoard,&row,&column,CPU,ColorPlayer2);
	gtk_label_set_text(GTK_LABEL(label_turn),name1);
	print_board(logicBoard);
	//Se verifica si no termino aun el juego.
	if(end_game(logicBoard)==((boardSize-1)*(boardSize-1))){
		//Si termino el juego se llama la funcion winner que se encarga de mostrar que jugador gano.
		winner();
		flag=FALSE;
	}else{
		//Si no termino aun el juego y si se formo una caja vuelve a llamar a la funcion move_pc
		//para que esta juegue de nuevo.
		if(flag==TRUE){
			move_pc();
		}
	}
}
void move_player(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	/*
	 * Procedimiento que se encarga de realizar, verificar y colocar en el
	 * tablero, los movimientos del jugador.
	 * Parametros:
	 * 	event_box
	 * 	event
	 * 	data
	 * 	Retorno:
	 * 	 Ninguno.*/
	int row,column,flag1=0;
	guint i,j;
	i = (GUINT_FROM_LE(event->y) / 15); //las imagenes tienen son 15x15pixeles
	j = (GUINT_FROM_LE(event->x) / 15);
	row=i;
	column=j;
	//Se envia el nombre del jugador
	gtk_label_set_text(GTK_LABEL(label_turn),name1);
	//Se verifica que se haya seleccionado una posicion valida a poner la linea
	if(logicBoard[row][column]==0){
		//Se carga la linea en el tablero logico
		logicBoard[row][column]=select_color(ColorPlayer1);
		//Se llama a la funcion verify_move que se encarga de verficar si se formo una caja.
		flag1=verify_move(logicBoard,&row,&column,PLAYER,ColorPlayer1);
		printf("\nTurno del jugador");
		line();
		print_board(logicBoard);
		//Parte de alzar la imagen gtk
		getsPosition(ColorPlayer1);//Se obtienen las lineas (horizontal y vertical ) que corresponde al color seleccionado para el jugador
		if(i%2==0 && j%2!=0){
			//se verifica si en la posicion se pone una linea horizontal en el tablero del GTK
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),column,row)),imagenes[horizontal]);
		}else{
			if(i%2!=0 && j%2==0){
				//se verifica si en la posicion se pone una linea vertical en el tablero del GTK
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),column,row)),imagenes[vertical]);
			}
		}
		//Si flag1 es True es de nuevo el turno del jugador y no juega la pc
		//Si flag1 es False es el turno de la pc para jugar
		if(flag1==FALSE){
			move_pc();
			print_board(logicBoard);
		}else{
			flag1=FALSE;
		}
	}else{
		//Si al verificar no es un movimiento valido sale un mensaje de error.
		dialog = gtk_message_dialog_new(GTK_WINDOW(window_name),
				GTK_DIALOG_DESTROY_WITH_PARENT,
				GTK_MESSAGE_WARNING,
				GTK_BUTTONS_OK,
				"Error, seleccione una posicion valida.");
		gtk_window_set_title(GTK_WINDOW(dialog), "Error");
		gtk_dialog_run(GTK_DIALOG(dialog));
		gtk_widget_destroy(dialog);
	}
	//Se verifica si no termino aun el juego para desplegar la ventana winner.
	if(end_game(logicBoard)==((boardSize-1)*(boardSize-1))){
		winner();
	}
}
void open_statistics(GtkWidget *widget, gpointer data){
	/*
	 * Procedimiento que abre la ventana de estadisticas.
	 * Parametros:
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.
	 */
	gtk_widget_show_all(window_statistics);
	gtk_widget_hide(window_menu);
}
void open_credits(GtkWidget *widget, gpointer data){
	/*
	 * Procedimiento que abre la ventana de creditos.
	 * Parametros:
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.
	 */
	gtk_widget_show_all(window_credits);
	gtk_widget_hide(window_menu);
}
void open_newGame(GtkWidget *widget, gpointer data){
	/*
	 * Procedimiento que abre la ventana para ingresar los nombres para los jugadores.
	 * Parametros:
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.
	 */
	gtk_widget_show_all(window_name);
	gtk_widget_hide(window_menu);
}
void emptyLabels(GtkWidget *label){
	/*
	 *Procedimiento para vaciar los labels del juego.
	 *Parametros:
	 *	label -> label a vaciar
	 *Retorno:
	 *	Ninguno
	 */
	const gchar *empty="";
	gtk_label_set_text(GTK_LABEL(label),empty);
}
void emptyEntry(GtkWidget *entry){
	/*
	 *Procedimiento para vaciar los entrys del juego.
	 *Parametros:
	 *	entry -> entry a vaciar
	 *Retorno:
	 *	Ninguno
	 */
	const gchar *empty="";
	gtk_entry_set_text(GTK_ENTRY(entry),empty);
}
void isClickedExit(GtkWidget *widget, gpointer data){
	/*Procedimiento para salir del juego
	 * Parametros:
	 * 	widget
	 * 	data
	 * Retorno:
	 * 	Ninguno*/
	exit(1);
}
void isClickedBack1(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_back1 que sirve para volver de estadisticas al menu
	 * Parametros:
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	gtk_widget_hide(window_statistics);
	gtk_widget_show_all(window_menu);
}
void isClickedBack2(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_back2 que sirve para volver de creditos al menu
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	//Vacia o limpia la descripcion
	emptyLabels(label_description);
	gtk_widget_hide(window_credits);
	gtk_widget_show_all(window_menu);
	//Vacia o limpia la imagen
	gtk_image_set_from_file(GTK_IMAGE(image_programmer),"img/vacio.png");
}
void isClickedBack3(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_back3 que sirve para volver de name al menu
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_name),
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
	/*Procedimiento para el btn_back4 que sirve para volver de window_choiceTurn al window_name
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	gtk_widget_hide(window_choiceTurn);
	gtk_widget_show_all(window_name);
}
void isClickedBack5(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_back5 que sirve para volver de window_turnSelected al window_choiceTurn
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	gtk_widget_hide(window_turnSelected);
	gtk_widget_show_all(window_choiceTurn);
}
void isClickedBack6(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_back6 que sirve para volver de window_choiceColor al window_turnSelected
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	gtk_widget_hide(window_choiceColor);
	gtk_widget_show_all(window_turnSelected);
}
void isClickedBack7(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_back7 que sirve para volver de window_colorSelected al window_choiceColor
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	gtk_widget_hide(window_colorSelected);
	gtk_widget_show_all(window_choiceColor);
}
void isClickedBack8(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_back8 que sirve para volver de window_choiceBoardSize al window_colorSelected
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	gtk_widget_hide(window_choiceBoardSize);
	gtk_widget_show_all(window_colorSelected);
}
void isClickedCancel1(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_cancel1 que sirve para volver al menu del window_choiceTurn
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
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
	/*Procedimiento para el btn_cancel2 que sirve para volver al menu del window_turnSelected
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_turnSelected),
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
	/*Procedimiento para el btn_cancel3 que sirve para volver al menu del window_choiceColor
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_choiceColor),
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
	/*Procedimiento para el btn_cancel4 que sirve para volver al menu del window_colorSelected
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_colorSelected),
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
	/*Procedimiento para el btn_cancel5 que sirve para volver al menu del window_choiceBoardSize
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_choiceBoardSize),
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
	/*Procedimiento cuando se clickea el btn_player en la ventana window_choiceTurn para la
	 * seleccion de quien comienza primero
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	PlayerFirtsTurn=PLAYER;
	gtk_label_set_text(GTK_LABEL(label_nameFirtsTurn),name1);
	gtk_image_set_from_file(GTK_IMAGE(image_playerFirtsTurn),"img/jugador.jpg");
	gtk_widget_hide(window_choiceTurn);
	gtk_widget_show_all(window_turnSelected);
}
void isClickedPc(GtkWidget *widget, gpointer data){
	/*Procedimiento cuando se clickea el btn_pc en la ventana window_choiceTurn para la
	 * seleccion de quien comienza primero
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	PlayerFirtsTurn=CPU;
	gtk_label_set_text(GTK_LABEL(label_nameFirtsTurn),name2);
	gtk_image_set_from_file(GTK_IMAGE(image_playerFirtsTurn),"img/pc.jpg");
	gtk_widget_hide(window_choiceTurn);
	gtk_widget_show_all(window_turnSelected);
}
void isClickedEthel(GtkWidget *widget, gpointer data){
	/*Procedimiento cuando se clickea el btn_ethel en la ventana window_credits para mostrar el avatar
	 * del programador
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	gtk_image_set_from_file(GTK_IMAGE(image_programmer),"img/Ethel.jpg");
	gtk_label_set_text(GTK_LABEL(label_description),"Ayudo con el diseño de la interfaz");
}
void isClickedDaniela(GtkWidget *widget, gpointer data){
	/*Procedimiento cuando se clickea el btn_daniela en la ventana window_credits para mostrar el avatar
	 * del programador
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	gtk_image_set_from_file(GTK_IMAGE(image_programmer),"img/Danusita.jpg");
	gtk_label_set_text(GTK_LABEL(label_description),"Programo y lloro");
}
void isClickedColor1(GtkWidget *widget, gpointer data){
	/*Procedimiento cuando se clickea el btn_color1 en window_choiceColor para la seleccion de color para
	 * cada jugador
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
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
	/*Procedimiento cuando se clickea el btn_color2 en window_choiceColor para la seleccion de color para
	 * cada jugador
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
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
	/*Procedimiento para el btn_next1 del window_name
	 * Parametros:
	 * 	widget
	 * 	data
	 * Retorno:
	 * 	Ninguno*/
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
		//Si se completaron los campos correctamente abre el dialogo para preguntar si desea elegir quien
		//comienza primero.
		dialog = gtk_message_dialog_new(GTK_WINDOW(window_name),
				GTK_DIALOG_DESTROY_WITH_PARENT,
				GTK_MESSAGE_QUESTION,
				GTK_BUTTONS_YES_NO,
				"Desea elegir quien comienza primero?"
				"\nRecuerde que se seleccionara automaticamente si no desea elegir.");
		gtk_window_set_title(GTK_WINDOW(dialog), "Consultita");
		switch(gtk_dialog_run(GTK_DIALOG(dialog))){
		case -8:
			//YES
			choice_turns(TRUE);
			break;
		case -9:
			//NO
			choice_turns(FALSE);
			break;
		}
		gtk_widget_destroy(dialog);
	}
}
void isClickedNext2(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_next2 del window_name
	 * Parametros:
	 * 	widget
	 * 	data
	 * Retorno:
	 * 	Ninguno*/
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_turnSelected),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_QUESTION,
			GTK_BUTTONS_YES_NO,
			"Desea elegir el color?"
			"\nRecuerde que se seleccionara automaticamente si no desea elegir.");
	gtk_window_set_title(GTK_WINDOW(dialog), "Consultita");
	switch(gtk_dialog_run(GTK_DIALOG(dialog))){
	case -8:
		//YES
		choice_colors(TRUE);
		break;
	case -9:
		//NO
		choice_colors(FALSE);
		break;
	}
	gtk_widget_destroy(dialog);
}
void isClickedNext3(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_next3 del window_colorSelected
	 * Parametros:
	 * 	widget
	 * 	data
	 * Retorno:
	 * 	Ninguno*/
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_colorSelected),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_QUESTION,
			GTK_BUTTONS_YES_NO,
			"Desea elegir el tamaño del tablero?"
			"\nRecuerde que se seleccionara automaticamente si no desea elegir.");
	gtk_window_set_title(GTK_WINDOW(dialog), "Consultita");
	switch(gtk_dialog_run(GTK_DIALOG(dialog))){
	case -8:
		//YES
		choice_board(TRUE);
		break;
	case -9:
		//NO
		choice_board(FALSE);
		break;
	}
	gtk_widget_destroy(dialog);
}
void isClickedNext4(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_next4 del window_choiceBoardSize
	 * Parametros:
	 * 	widget
	 * 	data
	 * Retorno:
	 * 	Ninguno*/
	const gchar *size=gtk_entry_get_text(GTK_ENTRY(txt_boardSize)); //Se obtiene el tamaño electo por el jugador
	char acumuletor[2];
	sprintf(acumuletor,"%s",size); //Se carga en el vector pa verificar
	boardSize=atoi(acumuletor); //Se carga en la variable global del tamaño del tablero
	check_size_board(atoi(acumuletor)); //Se envia en la funcion para verificar que sea un tamaño correcto
}
void getsPosition(int color){
	/*Procedimiento encargado de obtener la posicion de la imagen en el vector imagenes (las lineas en especial)
	 * Parametros:
	 * 	color -> color a buscar en el vector
	 * Retorno:
	 * 	Ninguno.*/
	switch(color){
	case 4:
		//Color rojo
		horizontal=2;
		vertical=3;
		break;
	case 5:
		//Color azul
		horizontal=4;
		vertical=5;
	}
}

GtkWidget *crear_tablero(){
	/* Funcion que se encarga de crear el tablero para el juego tanto como el tablero logico
	 * como el visual.
	 * Parametros:
	 * 	Ninguno.
	 * Retorno:
	 * 	eventbox.*/
	int i, j,size;
	size=getsSize(boardSize);//Se obtiene el tamaño del tablero con el que trabajaremos
	logicBoard=create_board(size); //Se crea el tablero logico
	initialize_board(logicBoard); //Inicializa el tablero
	eventbox = gtk_event_box_new();
	board = gtk_grid_new();
	for (i = 0; i < getsSize(boardSize); i++) {
		for (j = 0; j < getsSize(boardSize); j++) {
			if(i%2==0 && j%2==0){
				//Se cargan los puntos del tablero
				image = gtk_image_new_from_file(imagenes[0]);
				gtk_grid_attach(GTK_GRID(board), GTK_WIDGET(image), j, i, 1, 1);
			}else{
				//Se cargan los espacios vacios en el tablero
				image = gtk_image_new_from_file(imagenes[1]);
				gtk_grid_attach(GTK_GRID(board), GTK_WIDGET(image), j, i, 1, 1);
			}
		}
	}
	gtk_container_add(GTK_CONTAINER(eventbox), board);
	if(PlayerFirtsTurn==CPU){
		//Si es el turno de la pc juega primero
		move_pc();
		gtk_label_set_text(GTK_LABEL(label_turn),name2);
	}
	g_signal_connect(eventbox, "button-press-event", G_CALLBACK(move_player),board);
	return eventbox;
}
void emptyBoard(){
	/*Procedimiento que se encarga de limpiar el tablero visual+
	 * Parametros:
	 * 	Ninguno
	 * Retorno:
	 * 	Ninguno*/
	int i, j;
	for (i = 0; i < getsSize(boardSize); i++) {
		for (j = 0; j < getsSize(boardSize); j++) {
			if(i%2==0 && j%2==0){
				//Se cargan los puntos
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),j,i)),imagenes[0]);
			}else{
				//Se encargan los espacios vacios
				gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),j,i)),imagenes[1]);
			}
		}
	}
}
void isClickedPause(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_pause desplega el menu de pausa y bloquea el tablero
	 * Parametro:
	 * 	widget
	 * 	data
	 * Retorno:
	 * Ninguno.*/
	gtk_widget_set_sensitive(window_board,FALSE);
	gtk_widget_show_all(window_pause);
}
void isClickedContinue(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_continue cierra la ventana pausa y desbloquea el tablero.
	 * Parametro:
	 * 	widget
	 * 	data
	 * Retorno:
	 * Ninguno.*/
	gtk_widget_hide(window_pause);
	gtk_widget_set_sensitive(window_board,TRUE);
}
void isClickedStarAgain(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_starAgain cierra la ventana pausa y comienza de nuevo el tablero
	 * Parametro:
	 * 	widget
	 * 	data
	 * Retorno:
	 * Ninguno.*/
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_pause),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_QUESTION,
			GTK_BUTTONS_YES_NO,
			"Estas seguro que desea reiniciar la partida?"
			"\n No se guardara la partida actual.");
	gtk_window_set_title(GTK_WINDOW(dialog), "Consultita");
	if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
		//Se limpia el contador de puntos
		add_points[0]=0;
		add_points[1]=0;
		//Se desbloquea el tablero
		gtk_widget_set_sensitive(window_board,TRUE);
		//Se esconde la ventana pause
		gtk_widget_hide(window_pause);
		//Se limpia el tablero visual
		emptyBoard();
		gtk_label_set_text(GTK_LABEL(label_pointsPlayer1),"Puntos : 0");
		gtk_label_set_text(GTK_LABEL(label_pointsPlayer2),"Puntos : 0");
		//Se reinicia el tablero logico
		initialize_board(logicBoard);
		if(PlayerFirtsTurn==CPU){
			//Si es el turno de la pc juega primero
			move_pc();
			gtk_label_set_text(GTK_LABEL(label_turn),name2);
		}
	}
	gtk_widget_destroy(dialog);
}
void isCLickedOk(GtkWidget *widget, gpointer data){
	/*Procedimiento del btn_ok de la ventana window_winner para regresar al menu
	 * Parametros:
	 * 	widget
	 * 	data
	 * Retorno:
	 * 	Ninguno*/
	//Se limpia todos los entrys y labels
	emptyEntry(txt_player);
	emptyEntry(txt_pc);
	emptyEntry(txt_boardSize);
	//Se vacia los acumuladores de puntajes
	add_points[0]=0;
	add_points[1]=0;
	//Se libera la memoria
	free(logicBoard);
	gtk_widget_hide(window_winner);
	gtk_widget_destroy(eventbox);
	gtk_widget_show_all(window_menu);
}
void isClickedMenu(GtkWidget *widget, gpointer data){
	/*Procedimiento del btn_menu de la ventana window_pause para regresar al menu y no guardar la partida
	 * Parametros:
	 * 	widget
	 * 	data
	 * Retorno:
	 * 	Ninguno*/
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_pause),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_QUESTION,
			GTK_BUTTONS_YES_NO,
			"Estas seguro que desea salir?"
			"\n No se guardara la partida actual.");
	gtk_window_set_title(GTK_WINDOW(dialog), "Consultita");
	if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
		//Limpia todos los entrys y labels
		emptyEntry(txt_player);
		emptyEntry(txt_pc);
		emptyEntry(txt_boardSize);
		//Se limpia los puntos
		gtk_label_set_text(GTK_LABEL(label_pointsPlayer1),"Puntos : 0");
		gtk_label_set_text(GTK_LABEL(label_pointsPlayer2),"Puntos : 0");
		free(logicBoard);
		gtk_widget_hide(window_pause);
		gtk_widget_hide(window_board);
		gtk_widget_destroy(eventbox);
		gtk_widget_set_sensitive(window_board,TRUE);
		gtk_widget_show_all(window_menu);
	}
	gtk_widget_destroy(dialog);
}
void winner(){
	/*Procedimiento que verifica quien gano el juego y desplega la ventana window_winner y
	 * cierra la ventana window_board
	 * Parametro:
	 * 	Ninguno
	 * Retorno:
	 * 	Ninguno.*/
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
	gtk_widget_show_all(window_winner);
}
void setSquare(int row,int column,int color){
	/*Procedimiento para enviar el cuadrado cuando se forma una caja de su respectivo color
	 * Parametros.
	 * 	row -> fila de la matriz visual
	 * 	column -> columna de la matriz visual
	 * 	color -> color del jugador que corresponde la caja*/
	if(color==4){
		//Color rojo
		gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),column,row)),imagenes[6]);
	}else{
		//Color azul
		gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),column,row)),imagenes[7]);
	}
}
int verify_move(int **board,int *row,int *column,int player,int color){
	/*
	 * Funcion que verifica si en donde se puso la linea se formo una caja en el EMPTYBOX
	 * si se formo modifica el valor de este por RED o BLUE y retorna dos valores
	 * true y false
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
	for(int i=0;i<getsSize(boardSize);i++){
		for(int j=0;j<getsSize(boardSize);j++){
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
	/*Procedimiento que se encargar de actualizar los puntos para cada jugador.
	 * Parametros:
	 *	points -> puntos del jugador
	 *	player -> jugador que se le actualiza los puntos
	 * Retorno:
	 * 	Ninguno.*/
	gchar *temp = g_strdup_printf("Puntos : %i ",points);
	if(player==PLAYER){
		gtk_label_set_text(GTK_LABEL(label_pointsPlayer1),temp);
	}else{
		gtk_label_set_text(GTK_LABEL(label_pointsPlayer2),temp);
	}
	g_free(temp);
}

