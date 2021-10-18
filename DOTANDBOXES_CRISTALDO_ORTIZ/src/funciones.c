/*
 * funciones.c
 *
 *  Created on: 18 oct. 2021
 *      Author: lp1-2021
 */
#include "declaraciones.h"
#include "declaracionesGTK.h"
int add_points[2] = {0};
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
int check_size_board(int number){
	/*
	 * Funcion que verifica el tamaño para el tablero que introduce el usuario.
	 * Parámetros:
	 *  number -> tamaño del tablero que elige el usuario
	 * Retorno:
	 * 	El tamaño verificado que cumpla las condiciones de mayor o igual a 3 o menor o igual a 15.
	 */
	while(number<3 || number>15){
		printf("\nError, introduzca un valor entre 3 y 15: ");
		scanf("%i",&number);
	}
	return number;
}
void line(){
	/*Procedimiento que imprime una linea larga para separacion de turnos.
	 * Parametros:
	 * 	Ninguno
	 * Retorno:
	 *  Ninguno*/
	printf("\n------------------------------------------");
}
int yes_no_options(int option){
	/*Funcion que verifica si el usuario introduce un numero valido 0 o 1.
	* Parametros:
	* 	option -> opcion introducida por el teclado
	* Retorno:
	*  El valor de option verificado */
	while(option != 1 && option != 0){
		puts("Opción inexistente. Intente de nuevo. 1- Si 0-No");
		scanf("%i",&option);
	}
	return option;
}
int play_game(){
	/*
	* Funcion que sirve para iniciar el juego dependiendo de la seleccion del usuario.
	* Parametros:
	* 	Ninguno.
	* Retorno:
	*  1 -> TRUE
	*  0 -> FALSE
	*/
	int option;
	puts("Iniciar el juego? 1- Si 0-No");
	scanf("%i",&option);
	option = yes_no_options(option);
	if(option == TRUE){
		return TRUE;
	}else{
		return FALSE;
	}

}
int **create_board(int size){
	/*
	* Funcion que crea el tablero dependiendo del tamaño que recibe.
	* Parametros:
	* 	size -> tamaño introducido por el usuario.
	* Retorno:
	*  La posicion de memoria donde se encuentra el tablero creado.
	*/
	int **board;
	board=malloc(size*sizeof(int *));
	for(int i=0;i<size;i++){
		board[i]=malloc(size*sizeof(int *));
	}
	return board;
}
void initialize_board(int **array){
	/*
	* Procedimiento que inicializa el tablero. Se crean los puntos y las cajas vacias.
	* Parametros:
	* 	array -> posicion en la memoria del tablero.
	* Retorno:
	*  	Ninguno
	*/
	for(int i=0;i<boardSize +(boardSize-1);i++){
		for(int j=0;j<boardSize +(boardSize-1);j++){
			if(i%2==0 && j%2==0){
				array[i][j]=DOT;
			}else{
				if(i%2!=0 && j%2!=0){
					array[i][j]=EMPTYBOX;
				}
			}
		}
	}
}
void print_board(int **array){
	/*
	* Procedimiento que imprime el tablero en la consola.
	* Parametros:
	* 	array -> posicion en la memoria del tablero.
	* Retorno:
	*  	Ninguno
	*/
	printf("\n");
	for(int i=0;i<boardSize+(boardSize-1);i++){
		for(int j=0;j<boardSize +(boardSize-1);j++){
			printf(" %i ",array[i][j]);
		}printf("\n");
	}
}
int box(int **board,int row, int column){
	/*
	* Funcion que verifica si se formo una caja en una posicion del tablero
	* Parametros:
	* 	board 	-> posicion en la memoria del tablero.
	* 	row 	-> fila del tablero a verificar.
	* 	column	-> columna del tablero a verificar.
	* Retorno:
	*  TRUE 	-> Si se formo una caja
	*  FALSE 	-> Si no se formo la caja
	*/
	if((board[row][column+1]==RED || board[row][column+1]==BLUE) && (board[row][column-1]==RED || board[row][column-1]==BLUE) && (board[row+1][column]==RED || board[row+1][column]==BLUE) && (board[row-1][column]==RED || board[row-1][column]==BLUE)){
		return TRUE;
	}else{
		return FALSE;
	}
}
int select_color(int color){
	/*
	* Funcion que nos ayuda a identicar el color.
	* Parametros:
	* 	color	-> el color a verificar
	* Retorno:
	*  RED		-> Si el color es igual a rojo
	*  BLUE 	-> Si el color no es igual a rojo
	*/
	if(color==RED){
		return RED;
	}else{
		return BLUE;
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
						add_points[player]+= 10;
						flag=TRUE;
					}
				}
				if(i+1==*row && j==*column){
					if(box(board,*row-1,*column)){
						acumuletor=*row-1;
						board[acumuletor][*column]=select_color(color);
						add_points[player]+= 10;
						flag=TRUE;
					}
				}
				if(j-1==*column && i==*row){
					if(box(board,*row,*column+1)){
						acumuletor=*column+1;
						board[*row][acumuletor]=select_color(color);
						add_points[player]+= 10;
						flag=TRUE;
					}
				}
				if(j+1==*column && i==*row){
					if(box(board,*row,*column-1)){
						acumuletor=*column-1;
						board[*row][acumuletor]=select_color(color);
						add_points[player]+= 10;
						flag=TRUE;
					}
				}
			}
		}
	}
	return flag;
}
void choice_colors(int *color1,int *color2){
	/*
	* Procedimiento que permite 2 opciones, que el usuario seleccione el color deseado o se selecciona
	* aleatoriamente.
	* Parametros:
	* 	color1 -> posicion en la memoria para el color del jugador 1
	* 	color2 -> posicion en la memoria para el color del jugador 2
	* Retorno:
	*  	Ninguno
	*/
	int color, option;
	printf("\nDesea elegir color ? 1- Si 0-No");
	scanf("%i",&option);
	option = yes_no_options(option);
	if(option == TRUE){
		printf("\nElegir color a usar 1- Rojo 0-Azul");
		scanf("%i",&color);
			while(color != 1 && color !=0){
				printf("\nOpción inexistente");
				printf("\nElegir color 1- Rojo 0-Azul");
				scanf("%i",&color);
			}
			if(color == TRUE){
				puts("Color a usar: Rojo ");
				*color1=RED;
				*color2=BLUE;
			}else{
				puts("Color a usar: Azul ");
				*color1=BLUE;
				*color2=RED;
			}
	}else{
		puts("Elección de color aleatoriamente");
		color = random_number(1,0);
	}
	if(color == TRUE){
		puts("Color a usar: Rojo ");
		*color1=RED;
		*color2=BLUE;
	}else{
		puts("Color a usar: Azul ");
		*color1=BLUE;
		*color2=RED;
	}
}
int end_game(int **array){
	/*
	* Funcion que termina al verificar si ya se formaron todas las cajas posibles
	* Parametros:
	* 	array	-> posicion en la memoria del tablero.
	* Retorno:
	* 	La cantidad de cajas formadas en el tablero
	*/
	int acumuletor=0;
	for(int i=0;i<boardSize+(boardSize-1);i++){
			for(int j=0;j<boardSize +(boardSize-1);j++){
				if(i%2!=0 && j%2!=0){
					if(array[i][j]==RED || array[i][j]==BLUE){
						acumuletor++;
					}
				}
		}
	}
	return acumuletor;
}
int **choice_board(){
	/*
	* Funcion que permite 2 opciones, si el usuario quiere definir el tamaño del tablero o
	* se selecciona aleatoriamente.
	* Parametros:
	* 	Ninguno.
	* Retorno:
	* 	Retorna la posicion en la memoria del tablero con su tamaño ya definido.
	*/
	int option,newSize;
	puts("Elegir tamaño del tablero? 1-Si 0-No");
	scanf("%d",&option);
	option =yes_no_options(option);
	if(option == TRUE){
		printf("\nIntroduzca el tamaño del tablero: ");
		scanf("%i",&boardSize);
		boardSize=check_size_board(boardSize);
		newSize=boardSize+(boardSize-1);
		int **board=create_board(newSize);
		initialize_board(board);
		print_board(board);
		return board;
		}else{
			boardSize = random_number(15,3);
			printf("Tamaño del tablero %i",boardSize);
			boardSize=check_size_board(boardSize);
			newSize=boardSize+(boardSize-1);
			int **board=create_board(newSize);
			initialize_board(board);
			print_board(board);
			return board;
		}
}
int choice_turns(){
	/*
	* Funcion que permite 2 opciones, que el usuario eliga quien comienza o se selecciona aleatoriamente.
	* Parametros:
	* 	Ninguno.
	* Retorno:
	* 	CPU		-> Si comienza el CPU
	* 	PLAYER 	-> Si comienza el jugador
	*/
	int choice,player;
	puts("Elegir quién comienza? 1-Si 0-No");
	scanf("%i",&choice);
	choice = yes_no_options(choice);
	if(choice==TRUE){
		puts("Elegir quién comienza 1-CPU 0-JUGADOR");
		scanf("%i",&player);
		while(player != 1 && player !=0){
			puts("Opción inexistente");
			puts("Elegir quién comienza 1-CPU 0-JUGADOR");
			scanf("%i",&player);
		}
		if(player == TRUE){
			puts("Comienza CPU ");
			return CPU;
		}else{
			puts("Comienza JUGADOR ");
			return PLAYER;
		}
	}else{
		puts("Elección de quién empieza aleatoriamente");
				player = random_number(1,0);
	}
	if(player == TRUE){
		puts("Comienza CPU ");
		return CPU;
	}else{
		puts("Comienza JUGADOR ");
		return PLAYER;
	}

}
int move_pc(int **board,int color){
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
	int row,column,flag;
	printf("\nTurno de la CPU");
	line();
	printf("\nEligiendo.....");
	row=random_number(max,0);
	column=random_number(max,0);
	while(board[row][column]!=0){
		row=random_number(max,0);
		column=random_number(max,0);
	}
	printf("\nPosicion a poner la linea: %i, %i",row,column);
	board[row][column]=select_color(color);
	flag=verify_move(board,&row,&column,CPU,color);
	printf("\nPuntaje CPU: %i",add_points[CPU]);
	if(flag==TRUE){
		return flag;
	}else{
		return flag;
	}
}
int move_player(int **array,int color){
	/*
	* Funcion que realiza,verifica los movimientos del jugador.
	* Parametros:
	* 	board	-> posicion en la memoria del tablero.
	* 	color 	-> color que corresponde para el jugador.
	* Retorno:
 	* 	TRUE 	-> si se formo una caja.
	* 	FALSE	-> si no se formo una caja.
	*/
	int row,column,flag;
	printf("\nTurno del jugador");
	line();
	puts("\nIntroduzca la Posicion a colocar la raya. Considerar que los 1 son los puntos y los 3 son vacío ");
	printf("\nFila: ");
	scanf("%i",&row);
	printf("\nColumna: ");
	scanf("%i",&column);
	printf("\nPosición %i, %i",row,column);
	while(array[row][column]!=0){ //verificar que no esta ocupado
		printf("\nPosicion ocupada o no existe. Intente de nuevo");
		printf("\nFila: ");
		scanf("%i",&row);
		printf("\nColumna: ");
		scanf("%i",&column);
		printf("\nPosición %i, %i",row,column);
	}
	array[row][column] = select_color(color);
	flag=verify_move(array,&row,&column,PLAYER,color);
	printf("\nPuntaje Jugador: %i",add_points[PLAYER]);
	if(flag==TRUE){
		return flag;
	}else{
		return flag;
	}
}
void start_game(){
	/*
	* Procedimiento que se encarga de iniciar el juego, organizar los turnos por banderas y
	* verificar si se termina el juego.
	* Parametros:
	* 	Ninguno.
	* Retorno:
	* 	Ninguno.
	*/
	int **board =choice_board(),flag=FALSE,color1,color2;
		if(choice_turns()==PLAYER){
			choice_colors(&color1,&color2);
			//Juega el jugador
			while(end_game(board)<(boardSize+1)){
				if(flag==FALSE){
					flag=move_player(board,color1);
					print_board(board);
				}else{
					flag=FALSE;
				}
				if(flag==FALSE){
					flag=move_pc(board,color2);
					print_board(board);
				}else{
					flag=FALSE;
				}
			}
		}else{
			//Juega la pc
			choice_colors(&color1,&color2);
			while(end_game(board)<(boardSize+1)){
				if(flag==FALSE){
					flag=move_pc(board,color2);
					print_board(board);
				}else{
					flag=FALSE;
				}
				if(flag==FALSE){
					flag=move_player(board,color1);
					print_board(board);
				}else{
					flag=FALSE;
				}
			}
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
		break;
	}
}
void isClickedCancel(GtkWidget *widget, gpointer data){
	switch(cancel){
	case 1:
		dialog = gtk_message_dialog_new(GTK_WINDOW(window_choiceTurn),
		           GTK_DIALOG_DESTROY_WITH_PARENT,
		           GTK_MESSAGE_QUESTION,
		           GTK_BUTTONS_YES_NO,
		           "Estas seguro que desea salir?, no se guardara la partida actual.");
		 gtk_window_set_title(GTK_WINDOW(dialog), "Salir?");
		 if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
			  gtk_widget_hide(window_choiceTurn);
			  gtk_widget_show_all(window_menu);
			  emptyEntry(txt_player);
			  emptyEntry(txt_pc);
		 }
		 gtk_widget_destroy(dialog);
		 break;
	}
}
void isClickedPlayer(GtkWidget *widget, gpointer data){
	/*Funcion cuando se apreta el boton para seleccionar quien comienza primero*/
	gtk_widget_hide(window_choiceTurn);
	gtk_widget_show_all(window_turnSelected);
	back=5;
}
void isClickedPc(GtkWidget *widget, gpointer data){
	gtk_widget_hide(window_choiceTurn);
	gtk_widget_show_all(window_turnSelected);
	back=5;
}
void isClickedEthel(GtkWidget *widget, gpointer data){
	const gchar *description="Ayudo con el diseño de la interfaz";
	gtk_image_set_from_file(GTK_IMAGE(image_programmer),"img/Ethel.jpg");
	gtk_label_set_text(GTK_LABEL(label_description),description);
}
void isClickedDaniela(GtkWidget *widget, gpointer data){
	const gchar *description="Programo y lloro";
	gtk_image_set_from_file(GTK_IMAGE(image_programmer),"img/Danusita.jpg");
	gtk_label_set_text(GTK_LABEL(label_description),description);
}
void isClickedNext1(GtkWidget *widget, gpointer data){
	playerName[0]='\0';
	pcName[0]='\0';
	name1=gtk_entry_get_text(GTK_ENTRY(txt_player));
	name2=gtk_entry_get_text(GTK_ENTRY(txt_pc));
	sprintf(playerName,"%s",name1);
	sprintf(pcName,"%s",name2);
	if(name1[0]=='\0' || name2[0]=='\0'){
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

		if(gtk_dialog_run(GTK_DIALOG(dialog))==GTK_RESPONSE_YES){
			gtk_widget_show_all(window_choiceTurn);
			gtk_widget_hide(window_name);
			gtk_label_set_text(GTK_LABEL(label_namePlayer),name1);
			gtk_label_set_text(GTK_LABEL(label_namePc),name2);
			cancel=1;
			back=4;
		}else{
			gtk_widget_show_all(window_turnSelected);
			gtk_widget_hide(window_name);
		}
		gtk_widget_destroy(dialog);
	}
}

