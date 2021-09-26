#include "datos.h"
int yes_no_options(int option){
	while(option != 1 && option != 0){
		puts("Opción inexistente. Intente de nuevo. 1- Si 0-No");
		scanf("%i",&option);
	}
	return option;
}
int play_game(){
	// el jugador decide si quiere jugar o no
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
	//Crea el tablero
	int **array;
	array=malloc(size*sizeof(int *));
	for(int i=0;i<size;i++){
		array[i]=malloc(size*sizeof(int *));
	}
	return array;
}
void initialize_board(int **array){
	//Iniciliza el tablero para el juego
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
	//Imprime el tablero
	printf("\n");
	for(int i=0;i<boardSize+(boardSize-1);i++){
		for(int j=0;j<boardSize +(boardSize-1);j++){
			printf(" %i ",array[i][j]);
		}printf("\n");
	}
}
int box(int **board,int row, int column){
	//Funcion si es que se formo la caja
	if(board[row][column+1]==LINE && board[row][column-1]==LINE && board[row+1][column]==LINE && board[row-1][column]==LINE){
		return TRUE;
	}else{
		return FALSE;
	}
}
int verify_move(int **board,int *row,int *column,int player){
	int acumuletor,flag=FALSE;
	//Procedimiento que verifica cerca de que 3 se puso una linea
	for(int i=0;i<boardSize+(boardSize-1);i++){
		for(int j=0;j<boardSize+(boardSize-1);j++){
			if(i%2!=0 && j%2!=0){
				if(i-1==*row && j==*column){
					if(box(board,*row+1,*column)){
						acumuletor=*row+1;
						board[acumuletor][*column]=BOX;
						add_points[player]+= 10;
						flag=TRUE;
					}
				}
				if(i+1==*row && j==*column){
					if(box(board,*row-1,*column)){
						acumuletor=*row-1;
						board[acumuletor][*column]=BOX;
						add_points[player]+= 10;
						flag=TRUE;
					}
				}
				if(j-1==*column && i==*row){
					if(box(board,*row,*column+1)){
						acumuletor=*column+1;
						board[*row][acumuletor]=BOX;
						add_points[player]+= 10;
						flag=TRUE;
					}
				}
				if(j+1==*column && i==*row){
					if(box(board,*row,*column-1)){
						acumuletor=*column-1;
						board[*row][acumuletor]=BOX;
						add_points[player]+= 10;
						flag=TRUE;
					}
				}
			}
		}
	}
	return flag;
}
int choice_colors(){
	//FUncion que elige el color
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
				return RED;
			}else{
				puts("Color a usar: Azul ");
				return BLUE;
			}
	}else{
		puts("Elección de color aleatoriamente");
		color = random_number(1,0);
	}
	if(color == TRUE){
		puts("Color a usar: Rojo ");
		return RED;
	}else{
		puts("Color a usar: Azul ");
		return BLUE;
	}
}
int end_game(int **array){
	//FUncion que determina cuando finaliza la partida
	//acumula la cantidad de cajas formadas en el tablero
	int acumuletor=0;
	for(int i=0;i<boardSize+(boardSize-1);i++){
			for(int j=0;j<boardSize +(boardSize-1);j++){
				if(i%2!=0 && j%2!=0){
					if(array[i][j]==BOX){
						acumuletor++;
					}
				}
		}
	}
	return acumuletor;
}
int **choice_board(){
	//Funcion que se encarga de definir el tamaño del tablero
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
	//Funcion que se encarga de definir quien empieza
	int choice,player;
	puts("Elegir quién comienza? 1-Si 0-No");
	scanf("%i",&choice);
	choice = yes_no_options(choice);//validacion de la opcion
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
	} // imprime la elección
	if(player == TRUE){
		puts("Comienza CPU ");
		return CPU;
	}else{
		puts("Comienza JUGADOR ");
		return PLAYER;
	}

}
int move_pc(int **board){
	//Funcion que se encarga de realiazar los movimientos de la pc
	int max=(boardSize+(boardSize-1))-1;
	int row,column,flag;
	printf("\nTurno de la CPU");
	line();
	printf("\nEligiendo.....");
	row=random_number(max,0);
	column=random_number(max,0);
	while(board[row][column]==DOT || board[row][column]==LINE || board[row][column]==EMPTYBOX || board[row][column] == BOX){
		row=random_number(max,0);
		column=random_number(max,0);
	}
	printf("\nPosicion a poner la linea: %i, %i",row,column);
	board[row][column]=LINE;
	flag=verify_move(board,&row,&column,CPU);
	printf("\nPuntaje CPU: %i",add_points[CPU]);
	if(flag==TRUE){
		return flag;
	}else{
		return flag;
	}
}
int move_player(int **array){
	//Procedimiento que se encarga de los movimientos del jugador
	int row,column,flag;
	printf("\nTurno del jugador");
	line();
	puts("\nIntroduzca la Posicion a colocar la raya. Considerar que los 1 son los puntos y los 3 son vacío ");
	printf("\nFila: ");
	scanf("%i",&row);
	printf("\nColumna: ");
	scanf("%i",&column);
	printf("\nPosición %i, %i",row,column);
	while(array[row][column] == LINE || array[row][column] == EMPTYBOX || array[row][column] == DOT || array[row][column] == BOX){ //verificar que no esta ocupado
		printf("\nPosicion ocupada o no existe. Intente de nuevo");
		printf("\nFila: ");
		scanf("%i",&row);
		printf("\nColumna: ");
		scanf("%i",&column);
		printf("\nPosición %i, %i",row,column);
	}
	array[row][column] = LINE;
	flag=verify_move(array,&row,&column,PLAYER);
	printf("\nPuntaje Jugador: %i",add_points[PLAYER]);
	if(flag==TRUE){
		return flag;
	}else{
		return flag;
	}
}
void start_game(){
	//Procedimiento que se utilizar para empezar el juego por turnos
	int **board =choice_board(),flag=FALSE;
		if(choice_turns()==PLAYER){
			choice_colors();
			//Juega el jugador
			while(end_game(board)<(boardSize+1)){
				if(flag==FALSE){
					flag=move_player(board);
					print_board(board);
				}else{
					flag=FALSE;
				}
				if(flag==FALSE){
					flag=move_pc(board);
					print_board(board);
				}else{
					flag=FALSE;
				}
			}
		}else{
			//Juega la pc
			while(end_game(board)<(boardSize+1)){
				if(flag==FALSE){
					flag=move_player(board);
					print_board(board);
				}else{
					flag=FALSE;
				}
				if(flag==FALSE){
					flag=move_pc(board);
					print_board(board);
				}else{
					flag=FALSE;
				}
			}
		}
}
int main(void) {
	srand(time(NULL));
	if(play_game() == 1){
		start_game();
	}else{
		puts("Saliendo del juego");
		exit(0);
	}
	return EXIT_SUCCESS;
}
