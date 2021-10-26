#include "declaraciones.h"
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
			array[i][j]=0;
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
/*int move_player(int **array,int color){
	* Funcion que realiza,verifica los movimientos del jugador.
	* Parametros:
	* 	board	-> posicion en la memoria del tablero.
	* 	color 	-> color que corresponde para el jugador.
	* Retorno:
 	* 	TRUE 	-> si se formo una caja.
	* 	FALSE	-> si no se formo una caja.
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
}*/
/*
*/
