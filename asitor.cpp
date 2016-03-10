#include "asitor.h"

new_db::new_db(QWidget *parent):QWidget(parent) {
	this->setWindowTitle("New Database");
	this->setWindowIcon(QIcon("asitor.ico"));
	this->resize(350,200);
	this->setWindowFlags(Qt::WindowCloseButtonHint);
	QLabel* admin_email = new QLabel("Admin Email: ", this);
	QLabel* password = new QLabel("Password: ", this);
	QLineEdit *email_line = new QLineEdit(this);
	QLineEdit *pass_line = new QLineEdit(this);
	QPushButton* nokay = new QPushButton("Okay", this);
	QPushButton* ncancel = new QPushButton("Cancel", this);

	QGridLayout* grid = new QGridLayout();
	grid->addWidget(admin_email, 0, 0);
	grid->addWidget(email_line, 0, 1);
	grid->addWidget(password, 1, 0);
	grid->addWidget(pass_line, 1, 1);

	QVBoxLayout *vbox = new QVBoxLayout(this);
	vbox->addLayout(grid);

	QHBoxLayout* hbox = new QHBoxLayout();
	hbox->addWidget(nokay, 1, Qt::AlignRight);
	hbox->addWidget(ncancel, 0);

	vbox->addStretch(1);
	vbox->addLayout(hbox);

	setLayout(vbox);
}

choose_db::choose_db(QWidget *parent):QWidget(parent) {
	QPushButton *qbutton = new QPushButton("Quit", this);
	QPushButton *obutton = new QPushButton("Okay", this);
	QPushButton *bbutton = new QPushButton("Browse..", this);
	QPushButton *nbutton = new QPushButton("New", this);
    QLineEdit *filepath = new QLineEdit;
	QLabel *label = new QLabel("Choose database file:", this);
	
	QGridLayout * grid = new QGridLayout(this);
	grid->addWidget(label,0, 0);
	grid->addWidget(filepath, 0, 1);
	grid->addWidget(bbutton, 0 ,3);
	grid->addWidget(nbutton, 1, 1);
	grid->addWidget(obutton, 1, 2);
	grid->addWidget(qbutton, 1, 3);

	setLayout(grid);

	connect(bbutton, SIGNAL(clicked()), this, SLOT(on_browse()));
	connect(nbutton, SIGNAL(clicked()), this, SLOT(on_new()));
	connect(obutton, SIGNAL(clicked()), this, SLOT(on_okay()));
	connect(qbutton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void choose_db::on_okay() {}
void choose_db::on_browse() {
    QString directory = QFileDialog::getOpenFileName(this,tr("Find Database Files"), QDir::homePath(), tr("Database files (*.db)"));
}
void choose_db::on_new() {
	new_db* n_db = new new_db;
	n_db->show();
	this->hide();
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

	choose_db* c_db = new choose_db; // choose_db widget to select database

	QDesktopWidget *our_desktop = QApplication::desktop(); // taking desktop as a desktop widget

	screen_width = our_desktop->width(); // screen's width
	screen_height = our_desktop->height(); // screen's height

	// getting center values..

	y = (screen_height - height ) / 2;
	x = (screen_width - width ) / 2; 

	c_db->resize(width, height);
	c_db->move(x,y);
	c_db->setWindowTitle("Asitor");
	c_db->setWindowIcon(QIcon("asitor.ico"));
	c_db->setWindowFlags(Qt::WindowCloseButtonHint);
	c_db->show();
	splash.finish(c_db);
	return asitor.exec();
}