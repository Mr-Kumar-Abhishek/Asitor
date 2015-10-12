#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

typedef struct loginer {
	GtkEntry *entry_uname; //username textbox
	GtkEntry *entry_upass; //pasword textbox
}txtboxes;


void init_db_messages() {
	 GtkWidget* dialog;

 	dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "the text");
 	
 	gtk_window_set_title(GTK_WINDOW(dialog), "the title");

 	//gint result = 

 	gtk_dialog_run(GTK_DIALOG(dialog));

 	 	if(dialog!=NULL)
  {
    gtk_widget_hide(dialog);
    gtk_widget_destroy(dialog);
//    gtk_widget_hide(window);
//    gtk_widget_destroy(window);
  }

}
/*
void init_db () {
		// initializing engine
		int ret;
        do {

        	if (SQLITE_OK != (ret = sqlite3_initialize())){
        		init_db_messages("Initialization Faliure", "uh , oh... failed to initialize library");
            	break;
        	}

        }while(0);
}
*/
G_MODULE_EXPORT void on_login_destroy ()
{
    gtk_main_quit ();
}


G_MODULE_EXPORT void on_login_btn_clicked(GtkButton *button, txtboxes* gtexters, GtkWidget *window){
	char luemail[255];
	char lupass[255];

	//getting text from the text boxes
 	const gchar *emailer = gtk_entry_get_text(gtexters->entry_uname);
 	const gchar *passer = gtk_entry_get_text(gtexters->entry_upass);

 	// getting text from text boxes (input)
 	strcpy(luemail, emailer);
 	strcpy(lupass, passer);


 	//reversing and setting new text (output)
 	gtk_entry_set_text(gtexters->entry_uname, lupass);
 	gtk_entry_set_text(gtexters->entry_upass, luemail);

 	init_db_messages();

}


int main(int argc, char **argv){
	GtkBuilder *builder;
	GtkWidget *window;
	txtboxes gtexters;
	GError *error = NULL;
	/* Init GTK+ */
	gtk_init( &argc, &argv );

	/* Create new GtkBuilder object */
	builder = gtk_builder_new();
	/* Load UI from file. If error occurs, report it and quit application.
	 Replace "gui/login.glade" with your saved project with your startup form.*/
	if( ! gtk_builder_add_from_file( builder, "login.glade", &error )){
		g_warning( "%s", error->message );
		g_free( error );
		return( 1 );
	}
	/* Get main window pointer from UI */
	window = GTK_WIDGET( gtk_builder_get_object( builder, "login" ) );
	
	//connecting each structure member to it appropriate gtkwidget
	
	gtexters.entry_uname = GTK_ENTRY(gtk_builder_get_object(builder, "entry_uname" ));
	gtexters.entry_upass = GTK_ENTRY(gtk_builder_get_object(builder, "entry_upass" )); 

	/* Connect signals with appropriate handlers so that handlers could be called when button is clicked */
	gtk_builder_connect_signals( builder, &gtexters);
	/* Destroy builder, since we don't need it anymore */
	g_object_unref( G_OBJECT( builder ) );
	/* Show window. All other widgets are automatically shown by GtkBuilder */
	gtk_widget_show( window );
	/* Start main loop */
	gtk_main();
	return 0;
}
