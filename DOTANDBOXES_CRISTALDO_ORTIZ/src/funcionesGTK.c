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
					"img/linea1.png",
					"img/lineavertical1.png"};
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
		cancel=3;
		back=6;
	}else{
		//puts("Elección de color aleatoriamente");
		gtk_label_set_text(GTK_LABEL(label_namePlayer1),name1);
		gtk_label_set_text(GTK_LABEL(label_namePc1),name2);
		color=random_number(1,0);
		if(color == TRUE){
			//El jugador le toca el rojo y a la pc el azul
			gtk_image_set_from_file(GTK_IMAGE(image_color1),"img/color1.png");
			gtk_image_set_from_file(GTK_IMAGE(image_color2),"img/color2.png");
		}else{
			//A la pc le toca el roja y al jugador el azul
			gtk_image_set_from_file(GTK_IMAGE(image_color1),"img/color2.png");
			gtk_image_set_from_file(GTK_IMAGE(image_color2),"img/color1.png");
		}
		back=7;
		cancel=4;
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
		back=8;
		cancel=5;
		}else{
			boardSize = random_number(15,3);
			gtk_box_pack_start(GTK_BOX(box_board), crear_tablero(), TRUE, FALSE, 20);
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
		cancel=1;
		back=4;
	}else{
		//Se elige quien comienza aleatoriamente
		back=4;
		cancel=2;
		player = random_number(1,0);
		if(player == TRUE){
			gtk_label_set_text(GTK_LABEL(label_nameFirtsTurn),name2);
		}else{
			gtk_label_set_text(GTK_LABEL(label_nameFirtsTurn),name1);
		}
		gtk_widget_show_all(window_turnSelected);
		gtk_widget_hide(window_name);
	}
}
void open_statistics(GtkWidget *widget, gpointer data){
	/*
	 * Procedimiento que abre la ventana de estadisticas
	*/
	back=1;
	gtk_widget_show_all(window_statistics);
	gtk_widget_hide(window_menu);
}
void open_credits(GtkWidget *widget, gpointer data){
	back=2;
	gtk_widget_show_all(window_credits);
	gtk_widget_hide(window_menu);
}
void open_newGame(GtkWidget *widget, gpointer data){
	back=3;
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
void isClickedBack(GtkWidget *widget, gpointer data){
	switch(back){
	case 1:
		/*Cuando se vuelve de la ventana estadisticas al menu*/
		gtk_widget_hide(window_statistics);
		gtk_widget_show_all(window_menu);
		break;
	case 2:
		/*Cuando se vuelve de la ventana creditos al menu*/
		emptyLabels(label_description);
		gtk_widget_hide(window_credits);
		gtk_widget_show_all(window_menu);
		gtk_image_set_from_file(GTK_IMAGE(image_programmer),"img/vacio.png");
		break;
	case 3:
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
		break;
	case 4:
		/*Cuando se vuelve de la ventana choiceTurn a name*/
		gtk_widget_hide(window_choiceTurn);
		gtk_widget_show_all(window_name);
		back=3;
		break;
	case 5:
		/*Cuando se vuelve de la ventana turnSelected a choiceTurn*/
		gtk_widget_hide(window_turnSelected);
		gtk_widget_show_all(window_choiceTurn);
		back=4;
		cancel=1;
		break;
	case 6:
		/*Cuando se vuelve de la ventana choiceColor a turnSelected*/
		back=5;
		cancel=2;
		gtk_widget_hide(window_choiceColor);
		gtk_widget_show_all(window_turnSelected);
		break;
	case 7:
		/*Cuando se vuelve de la ventana turnSelected a choiceColor*/
		back=6;
		cancel=3;
		gtk_widget_hide(window_colorSelected);
		gtk_widget_show_all(window_choiceColor);
		break;
	case 8:
		/*Cuando se vuelve de la ventana choiceBoardSize a colorSelected*/
		back=7;
		cancel=4;
		gtk_widget_hide(window_choiceBoardSize);
		gtk_widget_show_all(window_colorSelected);
		break;
	}
}
void isClickedCancel(GtkWidget *widget, gpointer data){
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
		switch(cancel){
			case 1:
				gtk_widget_hide(window_choiceTurn);
				gtk_widget_show_all(window_menu);
				break;
			case 2:
				gtk_widget_hide(window_turnSelected);
				gtk_widget_show_all(window_menu);
				break;
			case 3:
				gtk_widget_hide(window_choiceColor);
				gtk_widget_show_all(window_menu);
				break;
			case 4:
				gtk_widget_hide(window_colorSelected);
				gtk_widget_show_all(window_menu);
				break;
			case 5:
				gtk_widget_hide(window_choiceBoardSize);
				gtk_widget_show_all(window_menu);
				break;
			}
	}
	gtk_widget_destroy(dialog);
}
void isClickedPlayer(GtkWidget *widget, gpointer data){
	/*Funcion cuando se apreta el boton para seleccionar quien comienza primero*/
	gtk_label_set_text(GTK_LABEL(label_nameFirtsTurn),name1);
	gtk_widget_hide(window_choiceTurn);
	gtk_widget_show_all(window_turnSelected);
	back=5;
	cancel=2;
}
void isClickedPc(GtkWidget *widget, gpointer data){
	gtk_label_set_text(GTK_LABEL(label_nameFirtsTurn),name2);
	gtk_widget_hide(window_choiceTurn);
	gtk_widget_show_all(window_turnSelected);
	back=5;
	cancel=2;
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
	cancel=4;
	back=7;
	gtk_widget_hide(window_choiceColor);
	gtk_widget_show_all(window_colorSelected);
	gtk_label_set_text(GTK_LABEL(label_namePlayer1),name1);
	gtk_label_set_text(GTK_LABEL(label_namePc1),name2);
	gtk_image_set_from_file(GTK_IMAGE(image_color1),"img/color1.png");
	gtk_image_set_from_file(GTK_IMAGE(image_color2),"img/color2.png");
}
void isClickedColor2(GtkWidget *widget, gpointer data){
	cancel=4;
	back=7;
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
	FirtsTurn=gtk_label_get_text(GTK_LABEL(label_nameFirtsTurn));
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_name),
			            GTK_DIALOG_DESTROY_WITH_PARENT,
			            GTK_MESSAGE_QUESTION,
			            GTK_BUTTONS_YES_NO,
			            "Dese elegir el color?");
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
void tablero_cb(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	guint i,j;
	i = (GUINT_FROM_LE(event->y) / 15); //las imagenes tienen son 50x50pixeles
	j = (GUINT_FROM_LE(event->x) / 15);

	if(i%2==0 && j%2!=0){
		gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),j,i)),imagenes[2]);
	}else{
		if(i%2!=0 && j%2==0){
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),j,i)),imagenes[3]);
		}
	}
}
GtkWidget *crear_tablero(){
	int i, j;
 //auxiliar para cargar la imagen
	eventbox = gtk_event_box_new();
	board = gtk_grid_new();
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
	g_signal_connect(eventbox, "button-press-event", G_CALLBACK(tablero_cb),board);
	return eventbox;
}
void nose(){
	int i, j;
	puts("entra");
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
		gtk_widget_set_sensitive(window_board,TRUE);
		gtk_widget_hide(window_pause);
		nose();
	}
	gtk_widget_destroy(dialog);
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
		  gtk_widget_hide(window_pause);
		  gtk_widget_hide(window_board);
		  gtk_widget_destroy(eventbox);
		  gtk_widget_set_sensitive(window_board,TRUE);
		  gtk_widget_show_all(window_menu);
	  }
	  gtk_widget_destroy(dialog);
}
