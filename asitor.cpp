#include <QApplication>
#include <QWidget>

int main(int argc, char* argv[]) {
	QApplication asitor(argc, argv);

	QWidget splash;

	splash.resize(250, 150);
	splash.setWindowTitle("Asitor");
	splash.show();

	return asitor.exec();
}