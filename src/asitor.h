#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

typedef struct loginer {
	GtkEntry *entry_uname; //username textbox
	GtkEntry *entry_upass; //pasword textbox
}txtboxes;
