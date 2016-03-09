#include "asitor.h"

choose_db::choose_db(QWidget *parent):QWidget(parent) {
	QPushButton *qbutton = new QPushButton("Quit", this);
	qbutton->setGeometry(200, 100, 40, 30);

	connect(qbutton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

int main(int argc, char* argv[]) {
	

	int width = 250;
	int height = 150;

	int screen_width;
	int screen_height;

	int x,y; // for storing the center values

	QApplication asitor(argc, argv);

	QPixmap asitor_splasher(":/splash.gif");

	QSplashScreen splash(asitor_splasher);
	splash.setToolTip("Welcome !!");
	splash.show();
	asitor.processEvents();

	choose_db c_db; // choose_db widget to select database

	QDesktopWidget *our_desktop = QApplication::desktop(); // taking desktop as a desktop widget

	screen_width = our_desktop->width(); // screen's width
	screen_height = our_desktop->height(); // screen's height

	// getting center values..

	y = (screen_height - height ) / 2;
	x = (screen_width - width ) / 2; 

	c_db.resize(width, height);
	c_db.move(x,y);
	c_db.setWindowTitle("Asitor");
	c_db.setWindowIcon(QIcon("asitor.ico"));
	c_db.show();
	splash.finish(&c_db);
	return asitor.exec();
}