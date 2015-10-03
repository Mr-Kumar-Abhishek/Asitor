#include "includes/asitor.h"

struct loginer {
	GtkEntry entry_uname; //username textbox
	GtkEntry entry_upass; //pasword textbox
};

typedef struct loginer txtboxes;

G_MODULE_EXPORT void on_login_btn_clicked(GtkButton *button, txtboxes *gtexters){
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
}
int main(int argc, char **argv){
	int proc; //holds the proc value for the entire application 
	GtkBuilder *builder;
	GtkWidget *window;
	GError *error = NULL;
	/* Init GTK+ */
	gtk_init( &argc, &argv );

	/* Create new GtkBuilder object */
	builder = gtk_builder_new();
	/* Load UI from file. If error occurs, report it and quit application.
	 Replace "tut.glade" with your saved project. */
	if( ! gtk_builder_add_from_file( builder, "gui/login.glade", &error )){
		g_warning( "%s", error->message );
		g_free( error );
		return( 1 );
	}
	/* Get main window pointer from UI */
	window = GTK_WIDGET( gtk_builder_get_object( builder, "login" ) );
	/* Connect signals */
	gtk_builder_connect_signals( builder, NULL );
	/* Destroy builder, since we don't need it anymore */
	g_object_unref( G_OBJECT( builder ) );
	/* Show window. All other widgets are automatically shown by GtkBuilder */
	gtk_widget_show( window );
	/* Start main loop */
	gtk_main();
	return 0;
}
