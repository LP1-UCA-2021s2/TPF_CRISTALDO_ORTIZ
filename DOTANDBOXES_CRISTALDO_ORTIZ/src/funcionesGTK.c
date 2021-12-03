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
int chain[100];
int modo=0;
//posi 0 para la pc
//posi 1 para el jugador

/*FUNCIONES*/
int randomOdd(int max,int min){
    int number;
    number=rand()%(max-min+1) + min;
    while(number%2==0){
        number=rand()%(max-min+1) + min;
    }
    return number;
}
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
		if(modo==1){
			gtk_box_pack_start(GTK_BOX(box_board), crear_tablero(), TRUE, FALSE, 20);
			gtk_label_set_text(GTK_LABEL(label_pointsPlayer1),"Puntos : 0");
			gtk_label_set_text(GTK_LABEL(label_pointsPlayer2),"Puntos : 0");
			gtk_widget_show_all(window_board);
			gtk_widget_hide(window_choiceBoardSize);
		}else{
			gtk_box_pack_start(GTK_BOX(box_board), crear_tablero(), TRUE, FALSE, 20);
			gtk_label_set_text(GTK_LABEL(label_pointsPlayer1),"Puntos : 0");
			gtk_label_set_text(GTK_LABEL(label_pointsPlayer2),"Puntos : 0");
			gtk_widget_show_all(window_board);
			gtk_widget_hide(window_choiceBoardSize);
		}

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
	char *content=NULL;
	char buff[100];
	int sizeCont=1;
	char file[]="estadisticas.txt";
	FILE *fileP = fopen(file,"r");
	if(fileP==NULL){
		fileP=fopen(file,"w");
		fprintf(fileP,"Nombre\tJ\tG\tP\tE");
		fclose(fileP);
		fileP=fopen(file,"r");
	}
	content=(char*)malloc(sizeof(char));
	content[0]='\0';
	while(fgets(buff,100,fileP)){
		sizeCont=sizeCont+strlen(buff);
		content=(char*)realloc(content,sizeCont*sizeof(char));
		strcat(content,buff);
	}
	fclose(fileP);

	GtkWidget *window;
	GtkWidget *view;
	GtkWidget *vbox;
	GtkWidget *scrolledwindow;
	GtkTextBuffer *buffer;
	GtkTextIter iter;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
	gtk_window_set_title(GTK_WINDOW(window), "Estadisticas");

	vbox = gtk_box_new(FALSE, 0);
	scrolledwindow = gtk_scrolled_window_new(NULL, NULL);
	view = gtk_text_view_new();
	gtk_box_pack_start(GTK_BOX(vbox), view, TRUE, TRUE, 0);

	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));

	gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);

	gtk_text_buffer_insert(buffer, &iter,content, -1);
	 gtk_container_add(GTK_CONTAINER(scrolledwindow),vbox);
	gtk_container_add(GTK_CONTAINER(window),scrolledwindow);

	gtk_widget_show_all(window);
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
	gtk_widget_show_all(window_choiceModo);
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
void isClickedPcVsPlayer(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_back1 que sirve para volver de estadisticas al menu
	 * Parametros:
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	modo=1;
	gtk_widget_hide(window_choiceModo);
	gtk_widget_show_all(window_name);
}
void isClickedPcVsPc(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_back1 que sirve para volver de estadisticas al menu
	 * Parametros:
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	modo=0;
	gtk_widget_hide(window_choiceModo);
	gtk_widget_show_all(window_pcName);
}
void isClickedPcLocal(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_back1 que sirve para volver de estadisticas al menu
	 * Parametros:
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	PlayerFirtsTurn=PCLOCAL;
	gtk_label_set_text(GTK_LABEL(label_nameFirtsTurn1),namepc1);
	gtk_image_set_from_file(GTK_IMAGE(image_playerFirtsTurn1),"img/jugador.jpg");
	gtk_widget_hide(window_choiceTurn1);
	gtk_widget_show_all(window_turnSelected1);
}
void isClickedPcOponent(GtkWidget *widget, gpointer data){
	/*Procedimiento para el btn_back1 que sirve para volver de estadisticas al menu
	 * Parametros:
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	PlayerFirtsTurn=PCOPONENT;
	gtk_label_set_text(GTK_LABEL(label_nameFirtsTurn1),namepc2);
	gtk_image_set_from_file(GTK_IMAGE(image_playerFirtsTurn1),"img/pc.jpg");
	gtk_widget_hide(window_choiceTurn1);
	gtk_widget_show_all(window_turnSelected1);
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
	gtk_widget_hide(window_name);
	gtk_widget_show_all(window_choiceModo);
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
void isClickedBack9(GtkWidget *widget, gpointer data){
	gtk_widget_hide(window_pcName);
	gtk_widget_show_all(window_choiceModo);
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
		if(modo==1){
			emptyEntry(txt_player);
			emptyEntry(txt_pc);

		}else{
			emptyEntry(txt_pcLocal);
			emptyEntry(txt_pcOponent);
		}
		emptyEntry(txt_boardSize);
		gtk_widget_hide(window_choiceBoardSize);
		gtk_widget_show_all(window_menu);
	}
	gtk_widget_destroy(dialog);
}
void isClickedCancel6(GtkWidget *widget, gpointer data){
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_choiceTurn1),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_QUESTION,
			GTK_BUTTONS_YES_NO,
			"Estas seguro que desea salir?, no se guardara la partida actual.");
	gtk_window_set_title(GTK_WINDOW(dialog), "Salir?");
	if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
		emptyEntry(txt_pcLocal);
		emptyEntry(txt_pcOponent);
		gtk_widget_hide(window_choiceColor1);
		gtk_widget_show_all(window_menu);
	}
	gtk_widget_destroy(dialog);
}
void isClickedCancel7(GtkWidget *widget, gpointer data){
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_choiceTurn1),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_QUESTION,
			GTK_BUTTONS_YES_NO,
			"Estas seguro que desea salir?, no se guardara la partida actual.");
	gtk_window_set_title(GTK_WINDOW(dialog), "Salir?");
	if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
		emptyEntry(txt_pcLocal);
		emptyEntry(txt_pcOponent);
		gtk_widget_hide(window_choiceTurn1);
		gtk_widget_show_all(window_menu);
	}
	gtk_widget_destroy(dialog);
}
void isClickedCancel8(GtkWidget *widget, gpointer data){
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_pcName),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_QUESTION,
			GTK_BUTTONS_YES_NO,
			"Estas seguro que desea salir?, no se guardara la partida actual.");
	gtk_window_set_title(GTK_WINDOW(dialog), "Salir?");
	if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
		emptyEntry(txt_pcLocal);
		emptyEntry(txt_pcOponent);
		gtk_widget_hide(window_pcName);
		gtk_widget_show_all(window_menu);
	}
	gtk_widget_destroy(dialog);
}
void isClickedCancel9(GtkWidget *widget, gpointer data){
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_pcName),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_QUESTION,
			GTK_BUTTONS_YES_NO,
			"Estas seguro que desea salir?, no se guardara la partida actual.");
	gtk_window_set_title(GTK_WINDOW(dialog), "Salir?");
	if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
		emptyEntry(txt_pcLocal);
		emptyEntry(txt_pcOponent);
		gtk_widget_hide(window_turnSelected1);
		gtk_widget_show_all(window_menu);
	}
	gtk_widget_destroy(dialog);
}
void isClickedCancel10(GtkWidget *widget, gpointer data){
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_pcName),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_QUESTION,
			GTK_BUTTONS_YES_NO,
			"Estas seguro que desea salir?, no se guardara la partida actual.");
	gtk_window_set_title(GTK_WINDOW(dialog), "Salir?");
	if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
		emptyEntry(txt_pcLocal);
		emptyEntry(txt_pcOponent);
		gtk_widget_hide(window_colorSelected1);
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
void isClickedColor3(GtkWidget *widget, gpointer data){
	/*Procedimiento cuando se clickea el btn_color2 en window_choiceColor para la seleccion de color para
	 * cada jugador
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	ColorPlayer1=RED;
	ColorPlayer2=BLUE;
	gtk_widget_hide(window_choiceColor1);
	gtk_widget_show_all(window_colorSelected1);
	gtk_label_set_text(GTK_LABEL(label_namePcLocal2),namepc1);
	gtk_label_set_text(GTK_LABEL(label_namePcOponent2),namepc2);
	gtk_image_set_from_file(GTK_IMAGE(image_color3),"img/color1.png");
	gtk_image_set_from_file(GTK_IMAGE(image_color4),"img/color2.png");
}
void isClickedColor4(GtkWidget *widget, gpointer data){
	/*Procedimiento cuando se clickea el btn_color2 en window_choiceColor para la seleccion de color para
	 * cada jugador
	 * 	widget
	 * 	data
	 * Retorno:
	 *  Ninguno.*/
	ColorPlayer1=BLUE;
	ColorPlayer2=RED;
	gtk_widget_hide(window_choiceColor);
	gtk_widget_show_all(window_colorSelected1);
	gtk_label_set_text(GTK_LABEL(label_namePcLocal2),namepc1);
	gtk_label_set_text(GTK_LABEL(label_namePcOponent2),namepc2);
	gtk_image_set_from_file(GTK_IMAGE(image_color3),"img/color2.png");
	gtk_image_set_from_file(GTK_IMAGE(image_color4),"img/color1.png");
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
void isClickedNext5(GtkWidget *widget, gpointer data){
		pcLocal[0]='\0';
		pcOponent[0]='\0';
		namepc1=gtk_entry_get_text(GTK_ENTRY(txt_pcLocal));
		namepc2=gtk_entry_get_text(GTK_ENTRY(txt_pcOponent));
		sprintf(pcLocal,"%s",namepc1);
		sprintf(pcOponent,"%s",namepc2);
		if(pcLocal[0]=='\0' || pcOponent[0]=='\0'){
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
			gtk_widget_hide(window_pcName);
			gtk_widget_show_all(window_choiceTurn1);
			gtk_label_set_text(GTK_LABEL(label_namePcLocal),namepc1);
			gtk_label_set_text(GTK_LABEL(label_namePcOponent),namepc2);
		}
}
void isClickedNext6(GtkWidget *widget, gpointer data){
	gtk_widget_show_all(window_choiceColor1);
	gtk_widget_hide(window_turnSelected1);
}
void isClickedNext7(GtkWidget *widget, gpointer data){
	gtk_widget_show_all(window_choiceBoardSize);
	gtk_widget_hide(window_colorSelected1);
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
	gtk_widget_set_sensitive(btn_nextPlayer,FALSE);
	if(add_points[CPU]>add_points[PLAYER]){
		gchar *temp=g_strdup_printf("%i",add_points[CPU]);
		gtk_label_set_text(GTK_LABEL(label_status),"GANO LA PC");
		gtk_label_set_text(GTK_LABEL(label_points),temp);
		gtk_image_set_from_file(GTK_IMAGE(image_winner),"img/pc.jpg");
		statistics(2,name1);
		g_free(temp);
	}else{
		if(add_points[CPU]==add_points[PLAYER]){
			gchar *temp=g_strdup_printf("%i",add_points[CPU]);
			gtk_label_set_text(GTK_LABEL(label_points),temp);
			gtk_widget_set_sensitive(btn_nextPlayer,TRUE);
			gtk_image_set_from_file(GTK_IMAGE(image_winner),"img/pc.jpg");
			gtk_label_set_text(GTK_LABEL(label_status),"EMPATE");
			g_free(temp);
			statistics(3,name1);
		}else{
			if(add_points[CPU]<add_points[PLAYER]){
				gchar *temp=g_strdup_printf("%i",add_points[PLAYER]);
				gtk_label_set_text(GTK_LABEL(label_status),"GANO EL JUGADOR");
				gtk_label_set_text(GTK_LABEL(label_points),temp);
				gtk_image_set_from_file(GTK_IMAGE(image_winner),"img/jugador.jpg");
				statistics(1,name1);
				g_free(temp);
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
void isCLickedNextPlayer(GtkWidget *widget, gpointer data){
	/*Procedimiento que se utiliza para mostrar el otro jugador cuando hay un empate
	 * Parametros
	 * widget
	 * data
	 * Retorno
	 * 	Ninguno*/
	gchar *temp=g_strdup_printf("%i",add_points[PLAYER]);
	gtk_widget_set_sensitive(btn_nextPlayer,FALSE);
	gtk_label_set_text(GTK_LABEL(label_points),temp);
	gtk_image_set_from_file(GTK_IMAGE(image_winner),"img/jugador.jpg");
	gtk_label_set_text(GTK_LABEL(label_status),"EMPATE");
	g_free(temp);
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
	int max=getsSize(boardSize)-1;
	gtk_label_set_text(GTK_LABEL(label_turn),name2);
	int rowOdd=0,columnOdd=0;
	int row=0,column=0,flag,numberOfBox=(((boardSize-1)*(boardSize-1))),aux=0;
	getsPosition(ColorPlayer2);
	printf("\nTurno de la CPU");
	line();
	printf("\nEligiendo.....");
	flag=markFourthLine(logicBoard,&row,&column,ColorPlayer2,CPU);
	if(flag==FALSE){
		row=randomOdd(max,1);
		column=randomOdd(max,1);
		while(getNumberLines(logicBoard,row,column)>=2 && exitsMoves(logicBoard)<numberOfBox){
			row=randomOdd(max,1);
			column=randomOdd(max,1);
		}
		if(exitsMoves(logicBoard)<numberOfBox){
			puts("Entro en exitsMoves<numberBox");
			if(getNumberLines(logicBoard,row,column)<2){
				puts("getNumberLines(logicBoard,row,column)<2");
				validMove(logicBoard,&row,&column,0);
			}
		}else{
			if(exitsMoves(logicBoard)==numberOfBox){
				cleanChain(logicBoard);
				searchChains(logicBoard);
				selectSmallestChain(logicBoard,&row,&column);
				printf("\n%i %i ",row,column);
				aux=random_number(4,1);
				printf("\n%i",aux);
				rowOdd=row;
				columnOdd=column;
				randomLine(aux,&row,&column);
				while(logicBoard[row][column]!=0){
					aux=random_number(4,1);
					row=rowOdd;
					column=columnOdd;
					randomLine(aux,&row,&column);
				}

			}
		}

	}
	printf("\nSe selecciono en la posicion %i %i",row,column);
	logicBoard[row][column]=select_color(ColorPlayer2);
	placeLinesInTheGrid(row,column,ColorPlayer2);
	flag=verify_move(logicBoard,&row,&column,CPU,ColorPlayer2);
	gtk_label_set_text(GTK_LABEL(label_turn),name1);
	print_board(logicBoard);
	if(end_game(logicBoard)==numberOfBox){
		winner();
		flag=FALSE;
	}else{
		if(flag==TRUE){
			move_pc();
		}
	}
}
int markFourthLine(int **array,int *row,int *column,int color,int player){
	int i,j,flag=FALSE;
	for(i=0;i<getsSize(boardSize);i++){
		for(j=0;j<getsSize(boardSize);j++){
			if(i%2!=0 && j%2!=0){
				if(getNumberLines(array,i,j)==3){
					*row=i;
					*column=j;
					getEmptyLine(array,row,column);
					flag=TRUE;
					break;
				}
			}
		}
	}
	return flag;
}
int createChains(int **array,int rowOdd,int columnOdd,int id,int size){
	array[rowOdd][columnOdd]=id;
	//Arriba
	if(array[rowOdd-1][columnOdd]==0){
		if(rowOdd-2>=1 && array[rowOdd-2][columnOdd]%3!=0){
			size=createChains(array,rowOdd-2,columnOdd,id,size);
		}
	}
	//Abajo
	if(array[rowOdd+1][columnOdd]==0){
		if(rowOdd+2<getsSize(boardSize)-1 && array[rowOdd+2][columnOdd]%3!=0){
			size=createChains(array,rowOdd+2,columnOdd,id,size);
		}
	}
	//Izquierda
	if(array[rowOdd][columnOdd-1]==0){
		if(columnOdd-2>=1 && array[rowOdd][columnOdd-2]%3!=0){
			size=createChains(array,rowOdd,columnOdd-2,id,size);
		}
	}
	//Derecha
	if(array[rowOdd][columnOdd+1]==0){
		if(columnOdd+2<getsSize(boardSize)-1 && array[rowOdd][columnOdd+2]%3!=0){
			size=createChains(array,rowOdd,columnOdd+2,id,size);
		}
	}
	return ++size;
}
void searchChains(int **board){
	int size,id=1;
	for(int i=0;i<getsSize(boardSize);i++){
		for(int j=0;j<getsSize(boardSize);j++){
			if(i%2!=0 && j%2!=0){
				if(board[i][j]==2){
					size=createChains(board,i,j,id*3,0);
					chain[id]=size;
					id++;
				}
			}
		}
	}
	chain[0]=id-1;
}
void cleanChain(int **board){
	for(int k=0;k<100;k++){
		if(chain[k]!=0){
			chain[k]=0;
		}
	}
	for(int i=0;i<getsSize(boardSize);i++){
		for(int j=0;j<getsSize(boardSize);j++){
			if(i%2!=0 && j%2!=0){
				if(board[i][j]!=BLUE && board[i][j]!=RED){
					board[i][j]=2;
				}
			}
		}
	}
}
void selectSmallestChain(int **board,int *row,int *column){
	int max=(getsSize(boardSize)-1);
	int minor=chain[1],id=1;
	for(int i=0;i<100;i++){
		if(chain[i]!=0){
			printf("\nLA longi de la cadena id %i es: %i",i*3,chain[i]);
		}
	}
	for(int i=1;i<100;i++){
		if(chain[i]<minor && chain[i]!=0){
			minor=chain[i];
			id=i;
		}
	}
	while(board[*row][*column]!=id*3){
		*row=randomOdd(max,1);
		*column=randomOdd(max,1);
	}
	printf("\n-%i-",id);
	printf("\nLa caja seleccionada es: %i %i el peso es de %i",*row,*column,minor);
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
void randomLine(int number,int *row,int *column){
	switch(number){
	case 1:
		*row=*row+1;
		break;
	case 2:
		*row=*row-1;
		break;
	case 3:
		*column=*column+1;
		break;
	case 4:
		*column=*column-1;
		break;
	}
}
void validMove(int **board,int *rowOdd,int *columnOdd,int aux1){
	int aux=0,row=*rowOdd,column=*columnOdd;
	if(aux1!=0){
		randomLine(aux1,&row,&column);
	}else{
		aux=random_number(4,1);
		randomLine(aux,&row,&column);
		while(board[row][column]!=0){
			aux=random_number(4,1);
			row=*rowOdd;
			column=*columnOdd;
			randomLine(aux,&row,&column);
		}
	}
	if(board[row][column]==0){
		//Arriba
		if(*rowOdd-1==row && *rowOdd%2!=0 && *columnOdd%2!=0){
			if(*rowOdd-2>=1){
				if(getNumberLines(board,*rowOdd-2,*columnOdd)!=2){
					puts("arriba");
					*rowOdd=row;
				}else{
					puts("xd1");

				}
			}else{
				puts("arriba");
				*rowOdd=row;
			}
		}
		//Abajo
		if(*rowOdd+1==row && *rowOdd%2!=0 && *columnOdd%2!=0){
			if(*rowOdd+2<getsSize(boardSize)-1){
				if(getNumberLines(board,*rowOdd+2,*columnOdd)!=2){
					puts("abajo");
					*rowOdd=row;
				}else{
					puts("xd2");
				}
			}else{
				puts("abajo");
				*rowOdd=row;
			}
		}
		//Izquierda
		if(*columnOdd-1==column && *rowOdd%2!=0 && *columnOdd%2!=0){
			if(*columnOdd-2>=1){
				if(getNumberLines(board,*rowOdd,*columnOdd-2)!=2){
					puts("izquierda");
					*columnOdd=column;
				}else{
					puts("xd3");
				}
			}else{
				puts("izquierda");
				*columnOdd=column;
			}
		}
		//Derecha
		if(*columnOdd+1==column && *rowOdd%2!=0 && *columnOdd%2!=0){
			if(*columnOdd+2<getsSize(boardSize)-1){
				if(getNumberLines(board,*rowOdd,*columnOdd+2)!=2){
					*columnOdd=column;
					puts("derecha");
				}else{
					puts("xd4");
				}
			}else{
				*columnOdd=column;
				puts("derecha");
			}
		}
	}
	if(aux1>4){
		printf("entro en de rodeado sin movi posible jaja");
		aux=random_number(4,1);
		randomLine(aux,&row,&column);
		while(board[row][column]!=0){
			aux=random_number(4,1);
			row=*rowOdd;
			column=*columnOdd;
			randomLine(aux,&row,&column);
		}
		*rowOdd=row;
		*columnOdd=column;
	}
	if(*columnOdd%2!=0 && *rowOdd%2!=0){
		puts("ENtro en el recursiva");
		printf("%i %i",*rowOdd,*columnOdd);
		aux1++;
		validMove(board,rowOdd,columnOdd,aux1);
	}
}
int exitsMoves(int **board){
	int sum=0;
	for(int i=0;i<getsSize(boardSize);i++){
		for(int j=0;j<getsSize(boardSize);j++){
			if(i%2!=0 && j%2!=0){
				if(getNumberLines(board,i,j)>=2){
					sum++;
				}
			}
		}
	}
	return sum;
}
void placeLinesInTheGrid(int row,int column,int color){
	getsPosition(color);
	if(row%2==0 && column%2!=0){
		gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),column,row)),imagenes[horizontal]);
	}else{
		if(row%2!=0 && column%2==0){
			gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(board),column,row)),imagenes[vertical]);
		}
	}
}
void isClickedHelp(GtkWidget *widget,gpointer data){
	/*Procedimiento para el btn_help del window_board
		 * Parametros:
		 * 	widget
		 * 	data
		 * Retorno:
		 * 	Ninguno*/
	dialog = gtk_message_dialog_new(GTK_WINDOW(window_board),
				GTK_DIALOG_DESTROY_WITH_PARENT,
				GTK_MESSAGE_QUESTION,
				GTK_BUTTONS_OK,
				"Unir los puntos de forma vertical u horizontal para crear cajas."
				"\n El último en cerrar la caja, se lleva el punto y debe jugar de nuevo."
				"\n Una caja vale 10 puntos."
				"\n Se termina la partida al unir todos los puntos.");

	gtk_window_set_title(GTK_WINDOW(dialog), "Ayudita");
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}
void readCoords(char *fileName){
	fPc = fopen (fileName, "r");
	int initialX,initialY,finalX,finalY;
	fscanf(fPc,"%d,%d\n",&initialX,&initialY);
	fscanf(fPc,"%d,%d",&finalX,&finalY);

	fclose(fPc);
	remove(fileName);

	int line = typeOfLine(initialX,initialY,finalX,finalY);
	int row = 0,column = 0;
	if(line == 0){
		row = initialX;
		column = initialY++;
	}else{
		row = initialX++;
		column = initialY;
	}

	placeLinesInTheGrid(row,column,ColorPlayer2); //color de la pc oponente
}
