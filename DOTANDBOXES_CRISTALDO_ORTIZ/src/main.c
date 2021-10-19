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

	/*BOTONES*/
	btn_newGame=GTK_WIDGET(gtk_builder_get_object(builder,"btn_newGame"));
	g_signal_connect(btn_newGame,"clicked", G_CALLBACK(open_newGame),NULL);

	btn_statistics=GTK_WIDGET(gtk_builder_get_object(builder,"btn_statistics"));
	g_signal_connect(btn_statistics,"clicked", G_CALLBACK(open_statistics),NULL);

	btn_credits=GTK_WIDGET(gtk_builder_get_object(builder,"btn_credits"));
	g_signal_connect(btn_credits,"clicked", G_CALLBACK(open_credits),NULL);

	btn_exit=GTK_WIDGET(gtk_builder_get_object(builder,"btn_exit"));
	g_signal_connect(btn_exit,"clicked", G_CALLBACK(isClickedExit),NULL);

	btn_back1=GTK_WIDGET(gtk_builder_get_object(builder,"btn_back1"));
	g_signal_connect(btn_back1,"clicked", G_CALLBACK(isClickedBack),NULL);

	btn_back2=GTK_WIDGET(gtk_builder_get_object(builder,"btn_back2"));
	g_signal_connect(btn_back2,"clicked", G_CALLBACK(isClickedBack),NULL);

	btn_back3=GTK_WIDGET(gtk_builder_get_object(builder,"btn_back3"));
	g_signal_connect(btn_back3,"clicked", G_CALLBACK(isClickedBack),NULL);

	btn_back4=GTK_WIDGET(gtk_builder_get_object(builder,"btn_back4"));
	g_signal_connect(btn_back4,"clicked", G_CALLBACK(isClickedBack),NULL);

	btn_back5=GTK_WIDGET(gtk_builder_get_object(builder,"btn_back5"));
	g_signal_connect(btn_back5,"clicked", G_CALLBACK(isClickedBack),NULL);

	btn_next1=GTK_WIDGET(gtk_builder_get_object(builder,"btn_next1"));
	g_signal_connect(btn_next1,"clicked", G_CALLBACK(isClickedNext1),NULL);

	btn_next2=GTK_WIDGET(gtk_builder_get_object(builder,"btn_next2"));
	g_signal_connect(btn_next2,"clicked", G_CALLBACK(isClickedNext1),NULL);

	btn_cancel1=GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancel1"));
	g_signal_connect(btn_cancel1,"clicked", G_CALLBACK(isClickedCancel),NULL);

	btn_cancel2=GTK_WIDGET(gtk_builder_get_object(builder,"btn_cancel2"));
	g_signal_connect(btn_cancel2,"clicked", G_CALLBACK(isClickedCancel),NULL);

	btn_ethel=GTK_WIDGET(gtk_builder_get_object(builder,"btn_ethel"));
	g_signal_connect(btn_ethel,"clicked", G_CALLBACK(isClickedEthel),NULL);

	btn_daniela=GTK_WIDGET(gtk_builder_get_object(builder,"btn_daniela"));
	g_signal_connect(btn_daniela,"clicked", G_CALLBACK(isClickedDaniela),NULL);

	btn_player=GTK_WIDGET(gtk_builder_get_object(builder,"btn_player"));
	g_signal_connect(btn_player,"clicked", G_CALLBACK(isClickedPlayer),NULL);

	btn_pc=GTK_WIDGET(gtk_builder_get_object(builder,"btn_pc"));
	g_signal_connect(btn_pc,"clicked", G_CALLBACK(isClickedPc),NULL);
	/*IMAGENES*/
	image_programmer=GTK_WIDGET(gtk_builder_get_object(builder,"image_programmer"));
	/*ENTRADAS*/
	txt_player=GTK_WIDGET(gtk_builder_get_object(builder,"txt_player"));

	txt_pc=GTK_WIDGET(gtk_builder_get_object(builder,"txt_pc"));
	/*LABELS*/
	label_description=GTK_WIDGET(gtk_builder_get_object(builder,"label_description"));

	label_namePlayer=GTK_WIDGET(gtk_builder_get_object(builder,"label_namePlayer"));

	label_namePc=GTK_WIDGET(gtk_builder_get_object(builder,"label_namePc"));

	label_nameFirtsTurn=GTK_WIDGET(gtk_builder_get_object(builder,"label_nameFirtsTurn"));
	/*
	if(play_game() == 1){
		start_game();
	}else{
		puts("Saliendo del juego");
		exit(0);
	}*/
	gtk_widget_show_all(window_menu);
	gtk_main();
	return EXIT_SUCCESS;
}
