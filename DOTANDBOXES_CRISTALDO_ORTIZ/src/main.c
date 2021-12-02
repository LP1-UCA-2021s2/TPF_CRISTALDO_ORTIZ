#include "declaracionesGTK.h"
#include "declaraciones.h"
int main(int argc,char *argv[]) {
	srand(time(NULL));
	GError *error=NULL;
	gtk_init(&argc,&argv);
	builder=gtk_builder_new();
	//Se carga el builder
	if(gtk_builder_add_from_file(builder,"interfaz.glade",&error)==0){
		g_print("Error en la funcion gtk_builder_add_from_file: \n");
		return 1;
	}

	/*VENTANAS*/

	window_menu=GTK_WIDGET(gtk_builder_get_object(builder,"window_menu"));
	g_signal_connect(window_menu,"destroy",gtk_main_quit,NULL);

	window_statistics=GTK_WIDGET(gtk_builder_get_object(builder,"window_statistics"));
	g_signal_connect(window_statistics,"destroy",gtk_main_quit,NULL);

	window_credits=GTK_WIDGET(gtk_builder_get_object(builder,"window_credits"));
	g_signal_connect(window_credits,"destroy",gtk_main_quit,NULL);

	window_name=GTK_WIDGET(gtk_builder_get_object(builder,"window_name"));
	g_signal_connect(window_name,"destroy",gtk_main_quit,NULL);

	window_choiceTurn=GTK_WIDGET(gtk_builder_get_object(builder,"window_choiceTurn"));
	g_signal_connect(window_choiceTurn,"destroy",gtk_main_quit,NULL);

	window_turnSelected=GTK_WIDGET(gtk_builder_get_object(builder,"window_turnSelected"));
	g_signal_connect(window_turnSelected,"destroy",gtk_main_quit,NULL);

	window_turnSelected1=GTK_WIDGET(gtk_builder_get_object(builder,"window_turnSelected1"));
	g_signal_connect(window_turnSelected1,"destroy",gtk_main_quit,NULL);

	window_choiceBoardSize=GTK_WIDGET(gtk_builder_get_object(builder,"window_choiceBoardSize"));
	g_signal_connect(window_choiceBoardSize,"destroy",gtk_main_quit,NULL);

	window_choiceColor=GTK_WIDGET(gtk_builder_get_object(builder,"window_choiceColor"));
	g_signal_connect(window_choiceColor,"destroy",gtk_main_quit,NULL);

	window_colorSelected=GTK_WIDGET(gtk_builder_get_object(builder,"window_colorSelected"));
	g_signal_connect(window_colorSelected,"destroy",gtk_main_quit,NULL);

	window_colorSelected1=GTK_WIDGET(gtk_builder_get_object(builder,"window_colorSelected1"));
	g_signal_connect(window_colorSelected1,"destroy",gtk_main_quit,NULL);

	window_pause=GTK_WIDGET(gtk_builder_get_object(builder,"window_pause"));
	g_signal_connect(window_pause,"destroy",gtk_main_quit,NULL);

	window_board=GTK_WIDGET(gtk_builder_get_object(builder,"window_board"));
	g_signal_connect(window_board,"destroy",gtk_main_quit,NULL);

	window_winner=GTK_WIDGET(gtk_builder_get_object(builder,"window_winner"));
	g_signal_connect(window_winner,"destroy",gtk_main_quit,NULL);

	window_choiceModo=GTK_WIDGET(gtk_builder_get_object(builder,"window_choiceModo"));
	g_signal_connect(window_winner,"destroy",gtk_main_quit,NULL);

	window_pcName=GTK_WIDGET(gtk_builder_get_object(builder,"window_pcName"));
	g_signal_connect(window_pcName,"destroy",gtk_main_quit,NULL);

	window_choiceTurn1=GTK_WIDGET(gtk_builder_get_object(builder,"window_choiceTurn1"));
	g_signal_connect(window_choiceTurn1,"destroy",gtk_main_quit,NULL);

	window_choiceColor1=GTK_WIDGET(gtk_builder_get_object(builder,"window_choiceColor1"));
	g_signal_connect(window_choiceColor1,"destroy",gtk_main_quit,NULL);

	/*BOTONES*/
	btn_newGame=GTK_WIDGET(gtk_builder_get_object(builder,"btn_newGame"));
	g_signal_connect(btn_newGame,"clicked", G_CALLBACK(open_newGame),NULL);

	btn_statistics=GTK_WIDGET(gtk_builder_get_object(builder,"btn_statistics"));
	g_signal_connect(btn_statistics,"clicked", G_CALLBACK(open_statistics),NULL);

	btn_credits=GTK_WIDGET(gtk_builder_get_object(builder,"btn_credits"));
	g_signal_connect(btn_credits,"clicked", G_CALLBACK(open_credits),NULL);

	btn_exit=GTK_WIDGET(gtk_builder_get_object(builder,"btn_exit"));
	g_signal_connect(btn_exit,"clicked", G_CALLBACK(isClickedExit),NULL);

	/*BOTONES BACK*/

	btn_back1=GTK_WIDGET(gtk_builder_get_object(builder,"btn_back1"));
	g_signal_connect(btn_back1,"clicked", G_CALLBACK(isClickedBack1),NULL);

	btn_back2=GTK_WIDGET(gtk_builder_get_object(builder,"btn_back2"));
	g_signal_connect(btn_back2,"clicked", G_CALLBACK(isClickedBack2),NULL);

	btn_back3=GTK_WIDGET(gtk_builder_get_object(builder,"btn_back3"));
	g_signal_connect(btn_back3,"clicked", G_CALLBACK(isClickedBack3),NULL);

	btn_back4=GTK_WIDGET(gtk_builder_get_object(builder,"btn_back4"));
	g_signal_connect(btn_back4,"clicked", G_CALLBACK(isClickedBack4),NULL);

	btn_back5=GTK_WIDGET(gtk_builder_get_object(builder,"btn_back5"));
	g_signal_connect(btn_back5,"clicked", G_CALLBACK(isClickedBack5),NULL);

	btn_back6=GTK_WIDGET(gtk_builder_get_object(builder,"btn_back6"));
	g_signal_connect(btn_back6,"clicked", G_CALLBACK(isClickedBack6),NULL);

	btn_back7=GTK_WIDGET(gtk_builder_get_object(builder,"btn_back7"));
	g_signal_connect(btn_back7,"clicked", G_CALLBACK(isClickedBack7),NULL);

	btn_back8=GTK_WIDGET(gtk_builder_get_object(builder,"btn_back8"));
	g_signal_connect(btn_back8,"clicked", G_CALLBACK(isClickedBack8),NULL);

	btn_back9=GTK_WIDGET(gtk_builder_get_object(builder,"btn_back9"));
	g_signal_connect(btn_back9,"clicked", G_CALLBACK(isClickedBack9),NULL);

	/*BOTONES NEXT*/

	btn_next1=GTK_WIDGET(gtk_builder_get_object(builder,"btn_next1"));
	g_signal_connect(btn_next1,"clicked", G_CALLBACK(isClickedNext1),NULL);

	btn_next2=GTK_WIDGET(gtk_builder_get_object(builder,"btn_next2"));
	g_signal_connect(btn_next2,"clicked", G_CALLBACK(isClickedNext2),NULL);

	btn_next3=GTK_WIDGET(gtk_builder_get_object(builder,"btn_next3"));
	g_signal_connect(btn_next3,"clicked", G_CALLBACK(isClickedNext3),NULL);

	btn_next4=GTK_WIDGET(gtk_builder_get_object(builder,"btn_next4"));
	g_signal_connect(btn_next4,"clicked", G_CALLBACK(isClickedNext4),NULL);

	btn_next5=GTK_WIDGET(gtk_builder_get_object(builder,"btn_next5"));
	g_signal_connect(btn_next5,"clicked", G_CALLBACK(isClickedNext5),NULL);

	btn_next6=GTK_WIDGET(gtk_builder_get_object(builder,"btn_next6"));
	g_signal_connect(btn_next6,"clicked", G_CALLBACK(isClickedNext6),NULL);

	btn_next7=GTK_WIDGET(gtk_builder_get_object(builder,"btn_next7"));
		g_signal_connect(btn_next7,"clicked", G_CALLBACK(isClickedNext7),NULL);

	/*BOTONES CANCEL*/

	btn_cancel1=GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancel1"));
	g_signal_connect(btn_cancel1,"clicked", G_CALLBACK(isClickedCancel1),NULL);

	btn_cancel2=GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancel2"));
	g_signal_connect(btn_cancel2,"clicked", G_CALLBACK(isClickedCancel2),NULL);

	btn_cancel3=GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancel3"));
	g_signal_connect(btn_cancel3,"clicked", G_CALLBACK(isClickedCancel3),NULL);

	btn_cancel4=GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancel4"));
	g_signal_connect(btn_cancel4,"clicked", G_CALLBACK(isClickedCancel4),NULL);

	btn_cancel5=GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancel5"));
	g_signal_connect(btn_cancel5,"clicked", G_CALLBACK(isClickedCancel5),NULL);

	btn_cancel6=GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancel6"));
	g_signal_connect(btn_cancel6,"clicked", G_CALLBACK(isClickedCancel6),NULL);

	btn_cancel7=GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancel7"));
	g_signal_connect(btn_cancel7,"clicked", G_CALLBACK(isClickedCancel7),NULL);

	btn_cancel8=GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancel8"));
	g_signal_connect(btn_cancel8,"clicked", G_CALLBACK(isClickedCancel8),NULL);

	btn_cancel9=GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancel9"));
	g_signal_connect(btn_cancel9,"clicked", G_CALLBACK(isClickedCancel9),NULL);

	btn_cancel10=GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancel10"));
		g_signal_connect(btn_cancel10,"clicked", G_CALLBACK(isClickedCancel10),NULL);

	/*BOTONES OTROS*/

	btn_ethel=GTK_WIDGET(gtk_builder_get_object(builder,"btn_ethel"));
	g_signal_connect(btn_ethel,"clicked", G_CALLBACK(isClickedEthel),NULL);

	btn_daniela=GTK_WIDGET(gtk_builder_get_object(builder,"btn_daniela"));
	g_signal_connect(btn_daniela,"clicked", G_CALLBACK(isClickedDaniela),NULL);

	btn_player=GTK_WIDGET(gtk_builder_get_object(builder,"btn_player"));
	g_signal_connect(btn_player,"clicked", G_CALLBACK(isClickedPlayer),NULL);

	btn_pc=GTK_WIDGET(gtk_builder_get_object(builder,"btn_pc"));
	g_signal_connect(btn_pc,"clicked", G_CALLBACK(isClickedPc),NULL);

	btn_color1=GTK_WIDGET(gtk_builder_get_object(builder,"btn_color1"));
	g_signal_connect(btn_color1,"clicked", G_CALLBACK(isClickedColor1),NULL);

	btn_color2=GTK_WIDGET(gtk_builder_get_object(builder,"btn_color2"));
	g_signal_connect(btn_color2,"clicked", G_CALLBACK(isClickedColor2),NULL);

	btn_color3=GTK_WIDGET(gtk_builder_get_object(builder,"btn_color3"));
	g_signal_connect(btn_color3,"clicked", G_CALLBACK(isClickedColor3),NULL);

	btn_color4=GTK_WIDGET(gtk_builder_get_object(builder,"btn_color4"));
	g_signal_connect(btn_color4,"clicked", G_CALLBACK(isClickedColor4),NULL);

	btn_pause=GTK_WIDGET(gtk_builder_get_object(builder,"btn_pause"));
	g_signal_connect(btn_pause,"clicked", G_CALLBACK(isClickedPause),NULL);

	btn_continue=GTK_WIDGET(gtk_builder_get_object(builder,"btn_continue"));
	g_signal_connect(btn_continue,"clicked", G_CALLBACK(isClickedContinue),NULL);

	btn_starAgain=GTK_WIDGET(gtk_builder_get_object(builder,"btn_starAgain"));
	g_signal_connect(btn_starAgain,"clicked", G_CALLBACK(isClickedStarAgain),NULL);

	btn_menu=GTK_WIDGET(gtk_builder_get_object(builder,"btn_menu"));
	g_signal_connect(btn_menu,"clicked", G_CALLBACK(isClickedMenu),NULL);

	btn_ok=GTK_WIDGET(gtk_builder_get_object(builder,"btn_ok"));
	g_signal_connect(btn_ok,"clicked", G_CALLBACK(isCLickedOk),NULL);

	btn_nextPlayer=GTK_WIDGET(gtk_builder_get_object(builder,"btn_nextPlayer"));
	g_signal_connect(btn_nextPlayer,"clicked", G_CALLBACK(isCLickedNextPlayer),NULL);

	btn_help=GTK_WIDGET(gtk_builder_get_object(builder,"btn_help"));
	g_signal_connect(btn_help,"clicked", G_CALLBACK(isClickedHelp),NULL);

	btn_pcVspc=GTK_WIDGET(gtk_builder_get_object(builder,"btn_pcVspc"));
	g_signal_connect(btn_pcVspc,"clicked", G_CALLBACK(isClickedPcVsPc),NULL);

	btn_pcVsplayer=GTK_WIDGET(gtk_builder_get_object(builder,"btn_pcVsplayer"));
	g_signal_connect(btn_pcVsplayer,"clicked", G_CALLBACK(isClickedPcVsPlayer),NULL);

	btn_pcLocal=GTK_WIDGET(gtk_builder_get_object(builder,"btn_pcLocal"));
	g_signal_connect(btn_pcLocal,"clicked", G_CALLBACK(isClickedPcLocal),NULL);

	btn_pcOponent=GTK_WIDGET(gtk_builder_get_object(builder,"btn_pcOponent"));
	g_signal_connect(btn_pcOponent,"clicked", G_CALLBACK(isClickedPcOponent),NULL);

	/*IMAGENES*/
	image_programmer=GTK_WIDGET(gtk_builder_get_object(builder,"image_programmer"));

	image_playerFirtsTurn=GTK_WIDGET(gtk_builder_get_object(builder,"image_playerFirtsTurn"));

	image_playerFirtsTurn1=GTK_WIDGET(gtk_builder_get_object(builder,"image_playerFirtsTurn1"));

	image_color1=GTK_WIDGET(gtk_builder_get_object(builder,"image_color1"));

	image_color2=GTK_WIDGET(gtk_builder_get_object(builder,"image_color2"));

	image_color3=GTK_WIDGET(gtk_builder_get_object(builder,"image_color3"));

	image_color4=GTK_WIDGET(gtk_builder_get_object(builder,"image_color4"));

	image_player1=GTK_WIDGET(gtk_builder_get_object(builder,"image_player1"));

	image_player2=GTK_WIDGET(gtk_builder_get_object(builder,"image_player2"));

	image_winner=GTK_WIDGET(gtk_builder_get_object(builder,"image_winner"));
	/*ENTRADAS*/
	txt_player=GTK_WIDGET(gtk_builder_get_object(builder,"txt_player"));

	txt_pc=GTK_WIDGET(gtk_builder_get_object(builder,"txt_pc"));

	txt_boardSize=GTK_WIDGET(gtk_builder_get_object(builder,"txt_boardSize"));

	txt_pcLocal=GTK_WIDGET(gtk_builder_get_object(builder,"txt_pcLocal"));

	txt_pcOponent=GTK_WIDGET(gtk_builder_get_object(builder,"txt_pcOponent"));

	/*LABELS*/

	label_description=GTK_WIDGET(gtk_builder_get_object(builder,"label_description"));

	label_namePlayer=GTK_WIDGET(gtk_builder_get_object(builder,"label_namePlayer"));

	label_namePc=GTK_WIDGET(gtk_builder_get_object(builder,"label_namePc"));

	label_nameFirtsTurn=GTK_WIDGET(gtk_builder_get_object(builder,"label_nameFirtsTurn"));

	label_nameFirtsTurn1=GTK_WIDGET(gtk_builder_get_object(builder,"label_nameFirtsTurn1"));

	label_namePlayer1=GTK_WIDGET(gtk_builder_get_object(builder,"label_namePlayer1"));

	label_namePc1=GTK_WIDGET(gtk_builder_get_object(builder,"label_namePc1"));

	label_namePcLocal=GTK_WIDGET(gtk_builder_get_object(builder,"label_namePcLocal"));

	label_namePcOponent=GTK_WIDGET(gtk_builder_get_object(builder,"label_namePcOponent"));

	label_namePcLocal2=GTK_WIDGET(gtk_builder_get_object(builder,"label_namePcLocal2"));

	label_namePcOponent2=GTK_WIDGET(gtk_builder_get_object(builder,"label_namePcOponent2"));

	label_turn=GTK_WIDGET(gtk_builder_get_object(builder,"label_turn"));

	label_status=GTK_WIDGET(gtk_builder_get_object(builder,"label_status"));

	label_pointsPlayer1=GTK_WIDGET(gtk_builder_get_object(builder,"label_pointsPlayer1"));

	label_pointsPlayer2=GTK_WIDGET(gtk_builder_get_object(builder,"label_pointsPlayer2"));

	label_points=GTK_WIDGET(gtk_builder_get_object(builder,"label_points"));

	box_board = GTK_WIDGET(gtk_builder_get_object(builder, "box_board"));
	gtk_widget_show_all(window_menu);
	gtk_main();
	print_board(logicBoard);

	return EXIT_SUCCESS;
}
