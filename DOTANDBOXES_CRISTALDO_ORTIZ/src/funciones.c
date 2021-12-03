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
int getsSize(int size){
	/*Funcion que recibe el tamaño del tablero y devuelve el tamaño que se utiliza para el proceso
	 * Parametros:
	 * 	size -> tamaño del tablero introducido por el jugador
	 * Retorno:
	 *  El tamaño nuevo para el tablero*/
	return (size+(size-1));
}
int getNumberLines(int **board,int rowOdd,int columnOdd){
    int acumuletor=0;
	if(board[rowOdd-1][columnOdd]==BLUE || board[rowOdd-1][columnOdd]==RED){
		acumuletor++;
	}
	if(board[rowOdd+1][columnOdd]==BLUE || board[rowOdd+1][columnOdd]==RED){
		acumuletor++;
	}
	if(board[rowOdd][columnOdd-1]==BLUE || board[rowOdd][columnOdd-1]==RED){
		acumuletor++;
	}
	if(board[rowOdd][columnOdd+1]==BLUE || board[rowOdd][columnOdd+1]==RED){
		acumuletor++;
	}
    //Retorna cuantas lineas hay en la posicion
    return acumuletor;
}
void getEmptyLine(int **board,int *row,int *column){
	if(board[*row-1][*column]==0){
		*row=*row-1;
	}
	if(board[*row+1][*column]==0){
		*row=*row+1;
	}
	if(board[*row][*column-1]==0){
		*column=*column-1;
	}
	if(board[*row][*column+1]==0){
		*column=*column+1;
	}
}
void copyArray(char*array1, char*array2){
	//funcion para copiar el texto de un array a otro asumiendo que hay memoria suficiente
	int i=0;
	while (i<strlen(array2)){
		array1[i]=array2[i];
		i++;
	}
	array1[i]='\0';
}

char *readText(FILE *fp){
    char *contents = NULL;
    size_t len = 0;
    getline(&contents,&len,fp);
    return contents;
}
void statistics(int result,const gchar *name){
	char file[]="estadisticas.txt";
	char aux[21], *token=NULL, **contents = NULL;
	int game=0,win,loss,draws,flag=FALSE, cont = 1, rowPlayer=-1;

	FILE *fileP = fopen(file,"r");
	if(fileP==NULL){
		fileP=fopen(file,"w");
		fprintf(fileP,"Nombre\tJ\tG\tP\tE");
		fclose(fileP);
		fileP=fopen(file,"r");
	}
	contents = (char**)malloc(sizeof(char*));
	while(feof(fileP)==0){
		if (cont!=1){
			contents = (char**)realloc(contents,(cont)*sizeof(char*));
		}
		contents[cont-1]=readText(fileP);
		copyArray(aux,contents[cont-1]);
		token= strtok(aux," ");
		if(strcmp(token,name)==0) {
			flag = TRUE;
			rowPlayer = cont-1;
			win = atoi(strtok (NULL, " "));
			loss = atoi(strtok (NULL, " "));
			draws= atoi(strtok (NULL, " "));
		}
		cont++;
	}
	fclose(fileP);
	cont--;
	fileP = fopen (file, "w");
	for (int i=0; i < cont; i++) {
		if (i != rowPlayer && *contents[i] != '\n'){
			fprintf (fileP,"%s",contents[i]);
		}
		free (contents[i]);
	}
	if (contents!=NULL){
		free (contents);
	}
	if (!flag) {
		win=0;
		loss=0;
		draws=0;
		game=0;
	}
	switch(result){
		case 1:
			win++;
			break;
		case 2:
			loss++;
			break;
		case 3:
			draws++;
			break;

	}
	game++;
	fprintf (fileP, "\n%s %d %d %d %d",name,game,win,loss,draws);  //escribe los datos del jugador
	fclose (fileP);
}
//--------------------------------------------------------------------------------------------------------
