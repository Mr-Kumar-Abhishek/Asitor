#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QIcon>

int main(int argc, char* argv[]) {
	

	int width = 250;
	int height = 150;

	int screen_width;
	int screen_height;

	int x,y; // for storing the center values

	QApplication asitor(argc, argv);

	QWidget splash; // splash widget to welcome the user

	QDesktopWidget *our_desktop = QApplication::desktop(); // taking desktop as a desktop widget

	screen_width = our_desktop->width(); // screen's width
	screen_height = our_desktop->height(); // screen's height

	// getting center values..

	y = (screen_height - height ) / 2;
	x = (screen_width - width ) / 2; 

	splash.resize(width, height);
	splash.move(x,y);
	splash.setWindowTitle("Asitor");
	splash.setToolTip("Welcome !!");
	splash.setWindowIcon(QIcon("asitor.ico"));
	splash.show();

	return asitor.exec();
}