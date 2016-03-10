#include "asitor.h"

manage_db::manage_db(){
	this->setWindowTitle("Asitor");
}

new_db::new_db(QWidget *parent):QWidget(parent) {
	this->setWindowTitle("New Database");
	this->setWindowIcon(QIcon("asitor.ico"));
	this->resize(350,200);
	this->setWindowFlags(Qt::WindowCloseButtonHint);
	admin_email = new QLabel("Admin Email: ", this);
	password = new QLabel("Password: ", this);
	choose_dir = new QLabel("Choose Folder: ", this);
	email_line = new QLineEdit(this);
	pass_line = new QLineEdit(this);
	dir_line = new QLineEdit(this);
	nokay = new QPushButton("Okay", this);
	ncancel = new QPushButton("Cancel", this);
	browse = new QPushButton("Browse..", this);
	nback = new QPushButton("<< Back", this);

	QGridLayout* grid = new QGridLayout();
	grid->addWidget(admin_email, 0, 0);
	grid->addWidget(email_line, 0, 1);
	grid->addWidget(password, 1, 0);
	grid->addWidget(pass_line, 1, 1);

	QVBoxLayout *vbox = new QVBoxLayout(this);
	vbox->addLayout(grid);
	vbox->addSpacing(20);

	QGridLayout* grid2 = new QGridLayout();

	grid2->addWidget(choose_dir, 0, 1);
	grid2->addWidget(dir_line, 0, 2);
	grid2->addWidget(browse, 0, 3);
	vbox->addLayout(grid2);

	QHBoxLayout* hbox = new QHBoxLayout();
	hbox->addWidget(nback, 2, Qt::AlignLeft);
	hbox->addWidget(nokay, 1, Qt::AlignRight);
	hbox->addWidget(ncancel, 0);

	vbox->addStretch(1);
	vbox->addLayout(hbox);

	setLayout(vbox);

	connect(nback, SIGNAL(clicked()), this, SLOT(on_back()));
	connect(browse, SIGNAL(clicked()), this, SLOT(on_browse()));
	connect(ncancel, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void new_db::on_back() {
	choose_db* c_db = new choose_db;
	c_db->show();
	this->hide();
}

void new_db::on_browse() {
	 QString directory_path = QFileDialog::getExistingDirectory(this,tr("Select Folder"), QDir::homePath());
	 dir_line->insert(directory_path);
}
choose_db::choose_db(QWidget *parent):QWidget(parent) {
	this->setWindowTitle("Asitor");
	this->setWindowIcon(QIcon("asitor.ico"));
	this->setWindowFlags(Qt::WindowCloseButtonHint);
	qbutton = new QPushButton("Quit", this);
	obutton = new QPushButton("Okay", this);
	bbutton = new QPushButton("Browse..", this);
	nbutton = new QPushButton("New", this);
	filepath = new QLineEdit(this);
	label = new QLabel("Choose database file:", this);
	
	QGridLayout* grid = new QGridLayout();
	grid->addWidget(label,0, 0);
	grid->addWidget(filepath, 0, 1);
	grid->addWidget(bbutton, 0 ,2);
	grid->addWidget(nbutton, 0, 3);

	grid->addWidget(obutton, 1, 2);
	grid->addWidget(qbutton, 1, 3);

	QVBoxLayout *vbox = new QVBoxLayout(this);
	vbox->addSpacing(15);
	vbox->addLayout(grid);

	QHBoxLayout* hbox = new QHBoxLayout();
	hbox->addWidget(obutton, 1, Qt::AlignRight);
	hbox->addWidget(qbutton, 0);
	vbox->addStretch(1);
	vbox->addLayout(hbox);

	setLayout(vbox);

	connect(bbutton, SIGNAL(clicked()), this, SLOT(on_browse()));
	connect(nbutton, SIGNAL(clicked()), this, SLOT(on_new()));
	connect(obutton, SIGNAL(clicked()), this, SLOT(on_okay()));
	connect(qbutton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void choose_db::on_okay() {
	QString db_file = filepath->text();
	QMessageBox* db_messages = new QMessageBox(this);
	if(QFile(db_file).exists()) {
		QFileInfo* db_file_info = new QFileInfo(db_file);
		if (!db_file_info->isDir()) {
			QString db_check = db_file.right(3);
			if (QString::compare(db_check, ".db", Qt::CaseInsensitive) == 0) {
				qint64 size = db_file_info->size();
				if(size != 0) {
					manage_db* asitor_main = new manage_db();
					asitor_main->show();
					this->hide();
				}else{
					db_messages->setText("something is fishy here .. not a proper database file.");
					db_messages->exec();
				}
			}else {
				db_messages->setText("Oops ... not a database file to work on...");
				db_messages->exec();
			}
		}else {
			db_messages->setText("oops, got a directory instead of a file ..");
			db_messages->exec();
		}
	}else {
		db_messages->setText("File or folder doesn't exist at the specified location.");
		db_messages->exec();
	}
}

void choose_db::on_browse() {
    QString filename = QFileDialog::getOpenFileName(this,tr("Find Database Files"), QDir::homePath(), tr("Database files (*.db)"));
    filepath->insert(filename);
}
void choose_db::on_new() {
	new_db* n_db = new new_db;
	n_db->show();
	this->hide();
}

int main(int argc, char* argv[]) {
	

	int width = 550;
	int height = 120;

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
	c_db->show();
	splash.finish(c_db);
	return asitor.exec();
}