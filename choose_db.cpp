#include "choose_db.h"

choose_db::choose_db(QWidget *parent):sub_win(parent) {
	this->setWindowTitle("Open Database Connection");
	this->setWindowFlags(Qt::WindowCloseButtonHint);
	this->resize(550,120);

	make_labels();
	make_line_edits();
	make_buttons();
	
	QVBoxLayout *vbox = new QVBoxLayout(this);

	QGridLayout *grid = new QGridLayout();
	grid->addWidget(admin_email, 0,0);
	grid->addWidget(email_line, 0, 1);
	grid->addWidget(password, 1, 0);
	grid->addWidget(pass_line, 1, 1);

	vbox->addLayout(grid);

	
	QGridLayout* grid2 = new QGridLayout();
	grid2->addWidget(open_db_file,0, 0);
	grid2->addWidget(filepath, 0, 1);
	grid2->addWidget(bbutton, 0 ,2);

	
	//vbox->addSpacing(15);
	vbox->addLayout(grid2);

	QHBoxLayout* hbox = new QHBoxLayout();
	hbox->addWidget(obutton, 1, Qt::AlignRight);
	hbox->addWidget(cbutton, 0);
	vbox->addStretch(1);
	vbox->addLayout(hbox);

	setLayout(vbox);

	connect(bbutton, SIGNAL(clicked()), this, SLOT(on_browse()));
	connect(obutton, SIGNAL(clicked()), this, SLOT(on_okay()));
	connect(cbutton, SIGNAL(clicked()), this, SLOT(close_me()));
}

void choose_db::make_buttons(){
	obutton = new QPushButton("Okay", this);
	bbutton = new QPushButton("Browse..", this);
	cbutton = new QPushButton("Cancel", this);
}

void choose_db::make_line_edits(){
	email_line = new QLineEdit(this);
	pass_line = new QLineEdit(this);
	pass_line->setEchoMode(QLineEdit::Password); 
	filepath = new QLineEdit(this);
}

void choose_db::make_labels(){
	admin_email = new QLabel("Admin Email: ", this);
	password = new QLabel("Password: ", this);
	open_db_file = new QLabel("Database File:", this);
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
    		db_messages->setText("Succesfully logged into the database.");
    		db_messages->exec();
    	/*	
    		manage_db* asitor_main = new manage_db();
			asitor_main->show();
			this->hide(); */
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
