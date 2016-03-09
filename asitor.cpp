#include "asitor.h"

choose_db::choose_db(QWidget *parent):QWidget(parent) {
	QPushButton *qbutton = new QPushButton("Quit", this);
	QPushButton *obutton = new QPushButton("Okay", this);
	QPushButton *bbutton = new QPushButton("Browse", this);
    QLineEdit *filepath = new QLineEdit;
	QLabel *label = new QLabel("Choose database file:", this);
	
	QGridLayout * grid = new QGridLayout(this);
	grid->addWidget(label,0, 0);
	grid->addWidget(filepath, 0, 1);
	grid->addWidget(bbutton, 0 ,2);
	grid->addWidget(obutton, 1, 1);
	grid->addWidget(qbutton, 1, 2);

	setLayout(grid);

	connect(qbutton, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(bbutton, SIGNAL(clicked()), this, SLOT(on_browse()));
	connect(obutton, SIGNAL(clicked()), this, SLOT(on_okay()));
}

void choose_db::on_okay() {}
void choose_db::on_browse() {
    QString directory = QFileDialog::getOpenFileName(this,tr("Find Database Files"), QDir::homePath(), tr("Database files (*.db)"));
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