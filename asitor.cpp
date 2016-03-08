#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QPixmap>
#include <QSplashScreen>
#include <QIcon>

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

	QWidget choose_db; // choose_db widget to select database

	QDesktopWidget *our_desktop = QApplication::desktop(); // taking desktop as a desktop widget

	screen_width = our_desktop->width(); // screen's width
	screen_height = our_desktop->height(); // screen's height

	// getting center values..

	y = (screen_height - height ) / 2;
	x = (screen_width - width ) / 2; 

	choose_db.resize(width, height);
	choose_db.move(x,y);
	choose_db.setWindowTitle("Asitor");
	choose_db.setWindowIcon(QIcon("asitor.ico"));
	choose_db.show();
	splash.finish(&choose_db);
	return asitor.exec();
}