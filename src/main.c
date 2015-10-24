#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <glib.h>
#include <glib/gprintf.h>
#include <gtksourceview/gtksourceview.h>
#include <gtksourceview/gtksourcebuffer.h>
#include <gtksourceview/gtksourcelanguage.h>
#include <gtksourceview/gtksourcelanguagemanager.h>

typedef struct loginer {
	GtkEntry *entry_uname; //username textbox
	GtkEntry *entry_upass; //pasword textbox
}txtboxes;

void init_db () {
		
		int flag = 0;
		int ret;
		char text[256];
		char title[] = "Database Connection";
		GtkWidget* dialog;
		sqlite3* database = NULL;
		sqlite3_stmt* statement = NULL;
        do {
        	// initializing library
        	if (SQLITE_OK != (ret = sqlite3_initialize())){
        		strcpy(text,"uh oh.. failed to initialize library");
        		flag= 1;
            	break;
        	}
        	 // opening connection to a DB
			if (SQLITE_OK != (ret = sqlite3_open_v2(":memory:", &database, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL))){
				strcpy(text,"aww.. snap..Failed to open connection");
				flag=1;
				break;
			}
			// preparing statement
			if (SQLITE_OK != (ret = sqlite3_prepare_v2(database, "SELECT SQLITE_VERSION()", -1, &statement, NULL))){
				strcpy(text, "oops .. failed to prepare statements");
				flag = 1;
				break;
			}

			 if (SQLITE_ROW != (ret = sqlite3_step(statement))){
				strcpy(text, "hmm... failed to step look into it");
				break;
			}
        }while(0);
        	if(flag == 1) {
        		dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE,"%s", text);
 				
        	}else {
        		dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE,"%s", sqlite3_column_text(statement, 0));	
        	}
        	gtk_window_set_title(GTK_WINDOW(dialog), title);
 			gtk_dialog_run(GTK_DIALOG(dialog));
 	 		if(dialog!=NULL){
    			gtk_widget_hide(dialog);
    			gtk_widget_destroy(dialog);	
       
  			}
         // cleaning up
		if (NULL != statement) sqlite3_finalize(statement);
		if (NULL != database) sqlite3_close(database);
		sqlite3_shutdown();
        
}
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

 	init_db();

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
