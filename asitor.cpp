#include "asitor.h"

manage_db::manage_db(){
	QString data_path;
	this->setWindowTitle("Asitor");
	this->setWindowIcon(QIcon("asitor.ico"));
	
	make_actions();
	make_menus();
	make_status_bar();

	mdiSpace = new QMdiArea;
	mdiSpace->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	mdiSpace->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setCentralWidget(mdiSpace);
/*	QSqlDatabase* db = new QSqlDatabase();
	*db = QSqlDatabase::addDatabase("QSQLITE");
	db->setDatabaseName(data_path);
	QMessageBox* db_messages = new QMessageBox();
	if(db->open()){
		db_messages->setText("Database file opened succesfully");
		db->close();
	}else{
		db_messages->setText("Error occured, couldn't open database file.");
	}
	db_messages->exec(); */
}

void manage_db::make_actions () {
	
	newdb = new QAction("&New", this);
	newdb->setShortcut(tr("CTRL+N"));
	connect(newdb, SIGNAL(triggered()), this, SLOT(on_new_db()));

	opendb = new QAction("&Open", this);
	opendb->setShortcut(tr("CTRL+O"));
	connect(opendb, SIGNAL(triggered()), this, SLOT(on_open_db()));

	closedb = new QAction("&Close", this);

	quit = new QAction("&Quit", this);
	quit->setShortcut(tr("CTRL+Q"));
	connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));

	about = new QAction("&About", this);

	license = new QAction("&License", this);

	aboutQT = new QAction("About QT", this);
	connect(aboutQT, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void manage_db::make_menus () {
	
	db_menu = menuBar()->addMenu("&Database");
	db_menu->addAction(newdb);
	db_menu->addAction(opendb);
	db_menu->addAction(closedb);
	db_menu->addSeparator();
	db_menu->addAction(quit);
	help_menu =  menuBar()->addMenu("&Help");
	help_menu->addAction(about);
	help_menu->addAction(license);
	help_menu->addAction(aboutQT);

}

void manage_db::make_status_bar() {
	statusBar()->showMessage(tr("Ready"));
}

void manage_db::on_new_db(){
	new_db* n_db =  new new_db(this);
	mdiSpace->addSubWindow(n_db);
	n_db->show();
}

void manage_db::on_open_db() {
	choose_db* c_db = new choose_db();
	mdiSpace->addSubWindow(c_db);
	c_db->show();
}

new_db::new_db(QWidget *parent):QWidget(parent) {
	this->setWindowTitle("New Database");
	this->resize(400,200);
	this->setWindowFlags(Qt::WindowCloseButtonHint);
	admin_email = new QLabel("Admin Email: ", this);
	password = new QLabel("Password: ", this);
	choose_dir = new QLabel("Choose Folder: ", this);
	give_db_name = new QLabel("Database File Name: ");
	email_line = new QLineEdit(this);
	pass_line = new QLineEdit(this);
	pass_line->setEchoMode(QLineEdit::Password);
	dir_line = new QLineEdit(this);
	db_name_line = new QLineEdit(this);
	nokay = new QPushButton("Okay", this);
	browse = new QPushButton("Browse..", this);

	QGridLayout* grid = new QGridLayout();
	grid->addWidget(admin_email, 0, 0);
	grid->addWidget(email_line, 0, 1);
	grid->addWidget(password, 1, 0);
	grid->addWidget(pass_line, 1, 1);
	grid->addWidget(give_db_name, 2, 0);
	grid->addWidget(db_name_line, 2, 1);

	QVBoxLayout *vbox = new QVBoxLayout(this);
	vbox->addLayout(grid);
	vbox->addSpacing(10);

	QGridLayout* grid2 = new QGridLayout();

	grid2->addWidget(choose_dir, 0, 1);
	grid2->addWidget(browse, 0, 2);
	grid2->addWidget(dir_line, 0, 3);
	vbox->addLayout(grid2);

	QHBoxLayout* hbox = new QHBoxLayout();
	hbox->addWidget(nokay, 1, Qt::AlignRight);

	vbox->addStretch(1);
	vbox->addLayout(hbox);

	setLayout(vbox);

	connect(browse, SIGNAL(clicked()), this, SLOT(on_browse()));
	connect(nokay, SIGNAL(clicked()), this, SLOT(on_okay()));
}

void new_db::on_okay() {
	QMessageBox* db_messages = new QMessageBox();
	bool success = true;
	QDir dir;
	QString db_dir = dir_line->text();
	QString db_name = db_name_line->text();
	if(!QFile(db_dir).exists()) {
		dir.mkpath(db_dir);
	}
	QString db_check = db_name.right(3);
	if (QString::compare(db_check, ".db", Qt::CaseInsensitive) != 0) {
		db_name = db_name + ".db";
	}
	QString db_path = db_dir + "/" + db_name;
	if(!QFile(db_path).exists()){

		QString email = email_line->text();
		QString pass =  pass_line->text();
		QSqlDatabase* db = new QSqlDatabase();

		*db = QSqlDatabase::addDatabase("QSQLITE");

		db->setDatabaseName(db_path);
		if(db->open()){
			QSqlQuery query;
			query.prepare("create table user(email text, pass text)");
			success = exec_query(query, db_messages, success);
			query.prepare("insert into user values( '" + email + "', '" + pass + "' )");
			success = exec_query(query, db_messages, success);
			db->close();
			if (success == true){
				manage_db* asitor_main = new manage_db();
				asitor_main->show();
				this->hide();	
			}
		}else{
			db_messages->setText("Error occured while creating new database file.");
			db_messages->exec();
		}
	}else{
		QFileInfo* db_path_info = new QFileInfo(db_path);
		if (db_path_info->isDir()) {
			db_messages->setText("Error: A directory already exists with name of the database file specified.");
			db_messages->exec();
		}else{
			db_messages->setText("Error: A file already exists with name of the database file specified.");
			db_messages->exec();
		}
	}
	
	
}

bool new_db::exec_query(QSqlQuery query, QMessageBox* db_messages, bool success) {
	if(!query.exec()){
		success = false;
		db_messages->setText("Error occured while registration.");	
	}
	return success;
}

void new_db::on_browse() {
	 QString directory_path = QFileDialog::getExistingDirectory(this,tr("Select Folder"), QDir::homePath());
	 dir_line->insert(directory_path);
}

choose_db::choose_db(QWidget *parent):QWidget(parent) {
	this->setWindowTitle("Asitor");
	this->setWindowIcon(QIcon("asitor.ico"));
	this->setWindowFlags(Qt::WindowCloseButtonHint);
	this->resize(550,120);
	admin_email = new QLabel("Admin Email: ", this);
	password = new QLabel("Password: ", this);
	give_db_name = new QLabel("Database File Name: ");
	email_line = new QLineEdit(this);
	pass_line = new QLineEdit(this);
	pass_line->setEchoMode(QLineEdit::Password); 
	obutton = new QPushButton("Okay", this);
	bbutton = new QPushButton("Browse..", this);
	filepath = new QLineEdit(this);
	label = new QLabel("Choose database file:", this);
	
	QVBoxLayout *vbox = new QVBoxLayout(this);

	QGridLayout *grid = new QGridLayout();
	grid->addWidget(admin_email, 0,0);
	grid->addWidget(email_line, 0, 1);
	grid->addWidget(password, 1, 0);
	grid->addWidget(pass_line, 1, 1);

	vbox->addLayout(grid);

	
	QGridLayout* grid2 = new QGridLayout();
	grid2->addWidget(label,0, 0);
	grid2->addWidget(filepath, 0, 1);
	grid2->addWidget(bbutton, 0 ,2);

	
	//vbox->addSpacing(15);
	vbox->addLayout(grid2);

	QHBoxLayout* hbox = new QHBoxLayout();
	hbox->addWidget(obutton, 1, Qt::AlignRight);
	vbox->addStretch(1);
	vbox->addLayout(hbox);

	setLayout(vbox);

	connect(bbutton, SIGNAL(clicked()), this, SLOT(on_browse()));
	connect(obutton, SIGNAL(clicked()), this, SLOT(on_okay()));
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
					check_user(db_file);
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

void choose_db::check_user(QString db_file){
	QSqlDatabase* db = new QSqlDatabase();
	*db = QSqlDatabase::addDatabase("QSQLITE");
	db->setDatabaseName(db_file);
	QMessageBox* db_messages = new QMessageBox();
	QString admin;
	QString pass;
	if(db->open()){
		QSqlQuery query;
    	QString queryString = "SELECT email, pass FROM user";
 		query.exec(queryString);
 		while (query.next()) {
        	QSqlRecord record = query.record();
        	admin =	record.value(0).toString();
        	pass  = record.value(1).toString();
    	}
    	QString chk_admin = email_line->text();
    	QString chk_pass =  pass_line->text();
    	if(QString::compare(chk_admin, admin) == 0 && QString::compare(chk_pass, pass) == 0){
    		manage_db* asitor_main = new manage_db();
			asitor_main->show();
			this->hide();
    	}else{
    		db_messages->setText("Email and/or password is incorrect !");
    		db_messages->exec();
    	}
		db->close();
	}else{
		db_messages->setText("Error occured, couldn't open database file.");
		db_messages->exec();
	}
}

void choose_db::on_browse() {
    QString filename = QFileDialog::getOpenFileName(this,tr("Find Database Files"), QDir::homePath(), tr("Database files (*.db)"));
    filepath->insert(filename);
}


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