#include "new_db.h"

new_db::new_db(QWidget *parent):sub_win(parent) {
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
	ncancel = new QPushButton("Cancel", this);
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
	hbox->addWidget(ncancel, 0);

	vbox->addStretch(1);
	vbox->addLayout(hbox);

	setLayout(vbox);

	connect(browse, SIGNAL(clicked()), this, SLOT(on_browse()));
	connect(nokay, SIGNAL(clicked()), this, SLOT(on_okay()));
	connect(ncancel, SIGNAL(clicked()), this, SLOT(close_me()));
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
				db_messages->setText("Database was succesfully created.");
				db_messages->exec();
			 /*
				manage_db* asitor_main = new manage_db();
				asitor_main->show();
				this->hide();	
			 */
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
