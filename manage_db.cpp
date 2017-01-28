#include "about_app.h"
#include "choose_db.h"
#include "new_db.h"
#include "close_db.h"
#include "new_student.h"
#include "license.h"
#include "view_student.h"
#include "edit_student.h"
#include "del_student.h"
#include "add_student.h"
#include "new_course.h"
#include "view_course.h"
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

	setUnifiedTitleAndToolBarOnMac(true);
}

void manage_db::make_actions () {
	
	/* Database Menu QActions */

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



	/* Student menu QActions */

	fresh_student = new QAction("&New", this);
	fresh_student->setStatusTip(tr("Make a new student profile."));
	connect(fresh_student, SIGNAL(triggered()), this, SLOT(on_new_student()));

	admission = new QAction("&Admission", this);
	admission->setStatusTip(tr("Admit student from a previously saved student profile."));
	connect(admission, SIGNAL(triggered()), this, SLOT(on_add_student()));
	
	see_student = new QAction("&View", this);
	see_student->setStatusTip(tr("View details of any student profile in the database."));
	connect(see_student, SIGNAL(triggered()), this, SLOT(on_view_student()));

	editing_student = new QAction("&Edit", this);
	editing_student->setStatusTip(tr("Edit details of any student profile in the database."));
	connect(editing_student, SIGNAL(triggered()), this, SLOT(on_edit_student()));

	delete_student = new QAction("&Delete", this);
	delete_student->setStatusTip(tr("Delete any particular student profile from the database."));
	connect(delete_student, SIGNAL(triggered()), this, SLOT(on_del_student()));



	/*Course menu QActions */

	add_course = new QAction("&Add", this);
	add_course->setStatusTip(tr("Add a new course."));
	connect(add_course, SIGNAL(triggered()), this, SLOT(on_add_course()));
	
	see_course = new QAction("&View", this);
	see_course->setStatusTip(tr("View available courses and their details."));
	connect(see_course, SIGNAL(triggered()), this, SLOT(on_view_course()));

	edit_course = new QAction("&Edit", this);
	edit_course->setStatusTip("Edit details of a previously saved course.");

	del_course = new QAction("&Delete", this);
	del_course->setStatusTip("Delete a course from the database.");




	/*Module menu QActions */

	add_mod =  new QAction("&Add", this);
	add_mod->setStatusTip("Add a module in a course.");

	view_mod = new QAction("&View", this);
	view_mod->setStatusTip("View module details in any course.");

	edit_mod = new QAction("&Edit", this);
	edit_mod->setStatusTip("Edit details of a module in a course.");

	del_mod = new QAction("&Delete", this);
	del_mod->setStatusTip("Delete a module from the database.");



	/* Help menu QActions */

	about = new QAction("&About", this);
	about->setStatusTip(tr("About Asitor."));
	connect(about, SIGNAL(triggered()), this, SLOT(on_about()));

	license = new QAction("&License", this);
	license->setStatusTip(tr("Asitor's License"));
	connect(license, SIGNAL(triggered()),this, SLOT(on_license()));

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

	student_menu = menuBar()->addMenu("&Students");
	student_menu->addAction(fresh_student);
	student_menu->addAction(admission);
	student_menu->addAction(see_student);
	student_menu->addAction(editing_student);
	student_menu->addAction(delete_student);

	course_menu = menuBar()->addMenu("&Courses");
	course_menu->addAction(add_course);
	course_menu->addAction(see_course);
	course_menu->addAction(edit_course);
	course_menu->addAction(del_course);

	mod_menu = menuBar()->addMenu("&Modules");
	mod_menu->addAction(add_mod);
	mod_menu->addAction(view_mod);
	mod_menu->addAction(edit_mod);
	mod_menu->addAction(del_mod);
	
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

void manage_db::on_new_student() {
	new_student* n_stu = new new_student(this);
	mdiSpace->addSubWindow(n_stu);
	n_stu->show();
}

void manage_db::on_license(){
	license_win* l_win = new license_win(this);
	mdiSpace->addSubWindow(l_win);
	l_win->show();
}

void manage_db::on_view_student() {
	view_student* v_stu = new view_student(this);
	mdiSpace->addSubWindow(v_stu);
	v_stu->show();
}

void manage_db::on_del_student(){
	del_student* d_stu = new del_student(this);
	mdiSpace->addSubWindow(d_stu);
	d_stu->show();
}

void manage_db::on_edit_student() {
	edit_student* e_stu = new edit_student(this);
	mdiSpace->addSubWindow(e_stu);
	e_stu->show();
}

void manage_db::on_add_student(){
	add_student* a_stu = new add_student(this);
	mdiSpace->addSubWindow(a_stu);
	a_stu->show();
}

void manage_db::on_add_course(){
	new_course* a_cou = new new_course(this);
	mdiSpace->addSubWindow(a_cou);
	a_cou->show();
}

void manage_db::on_view_course(){
	view_course* v_cou = new view_course(this);
	mdiSpace->addSubWindow(v_cou);
	v_cou->show();
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

