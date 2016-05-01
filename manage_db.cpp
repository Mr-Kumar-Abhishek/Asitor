#include "about_app.h"
#include "choose_db.h"
#include "new_db.h"
#include "close_db.h"
#include "manage_db.h"

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
	newdb->setStatusTip(tr("Create New Database File"));
	connect(newdb, SIGNAL(triggered()), this, SLOT(on_new_db()));

	opendb = new QAction("&Open", this);
	opendb->setShortcut(tr("CTRL+O"));
	opendb->setStatusTip(tr("Open Database File."));
	connect(opendb, SIGNAL(triggered()), this, SLOT(on_open_db()));

	closedb = new QAction("&Close", this);
	closedb->setStatusTip(tr("Close Database File"));
	connect(closedb, SIGNAL(triggered()), this, SLOT(on_close_db()));

	switcher = new QAction("Switch Layout Direction", this);
	connect(switcher, SIGNAL(triggered()), this, SLOT(switchingLayout()));

	quit = new QAction("&Quit", this);
	quit->setShortcut(tr("CTRL+Q"));
	quit->setStatusTip(tr("Quit Asitor ?"));
	connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));

	about = new QAction("&About", this);
	about->setStatusTip(tr("About Asitor."));
	connect(about, SIGNAL(triggered()), this, SLOT(on_about()));

	license = new QAction("&License", this);
	license->setStatusTip(tr("Asitor's License"));

	aboutQT = new QAction("About QT", this);
	aboutQT->setStatusTip(tr("About QT Library."));
	connect(aboutQT, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void manage_db::make_menus () {
	
	db_menu = menuBar()->addMenu("&Database");
	db_menu->addAction(newdb);
	db_menu->addAction(opendb);
	db_menu->addAction(closedb);
	db_menu->addSeparator();
	db_menu->addAction(switcher);
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

void manage_db::on_about(){
	about_app* a_win = new about_app(this);
	mdiSpace->addSubWindow(a_win);
	a_win->show();
}

void manage_db::on_close_db() {
	close_db* x_db = new close_db(this);
	mdiSpace->addSubWindow(x_db);
	x_db->show();
}

void manage_db::switchingLayout(){
	if(layoutDirection() == Qt::LeftToRight) {
		setStatusTip(tr("Switching Layout: From Right To Left."));
		qApp->setLayoutDirection(Qt::RightToLeft);
		setStatusTip(tr("Switched Layout: From Right To Left."));
	}else if (layoutDirection() == Qt::RightToLeft) {
		setStatusTip(tr("Switching Layout: From Left To Right."));
		qApp->setLayoutDirection(Qt::LeftToRight);
		setStatusTip(tr("Switched Layout: From Left To Right."));
	}else {
		QMessageBox* layoutERR = new QMessageBox();
		layoutERR->setText("Something went wrong while switching the layout ! :( ");
		layoutERR->exec();
	}
}

