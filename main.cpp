#include "manage_db.h"
#include "asitor.h"


int main(int argc, char* argv[]) {
	

	int width = 800;
	int height = 600;

	int screen_width;
	int screen_height;

	int x,y; // for storing the center values

	QApplication asitor(argc, argv);

	QPixmap asitor_splasher(":/splash.gif");

	QSplashScreen splash(asitor_splasher);
	splash.setToolTip("Welcome !!");
	splash.show();
	asitor.processEvents();

	manage_db* m_db = new manage_db; // choose_db widget to select database

	QDesktopWidget *our_desktop = QApplication::desktop(); // taking desktop as a desktop widget

	screen_width = our_desktop->width(); // screen's width
	screen_height = our_desktop->height(); // screen's height

	// getting center values..

	y = (screen_height - height ) / 2;
	x = (screen_width - width ) / 2; 

	m_db->resize(width, height);
	m_db->move(x,y);
	m_db->show();
	splash.finish(m_db);
	return asitor.exec();
}