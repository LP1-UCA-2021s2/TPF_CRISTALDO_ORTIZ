#include "declaraciones.h"
#define TRUE 1
#define FALSE 0
int add_points[2] = {0,0};
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
int **create_board(int size){
	//Crea el tablero
	int **array;
	array=malloc(size*sizeof(int *));
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
		array[i]=malloc(size*sizeof(int *));
		board[i]=malloc(size*sizeof(int *));
	}
	return array;
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
/*void start_game(){
	* Procedimiento que se encarga de iniciar el juego, organizar los turnos por banderas y
	* verificar si se termina el juego.
	* Parametros:
	* 	Ninguno.
	* Retorno:
	* 	Ninguno.
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
}*/
