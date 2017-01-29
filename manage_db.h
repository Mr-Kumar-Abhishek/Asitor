#pragma once

#include <QObject>
#include <QtGui>
#include <QMainWindow>
#include <QMdiArea>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>

class manage_db : public QMainWindow {

	Q_OBJECT

	public:
		manage_db();

	private slots:

		void on_new_db();
		void on_open_db();
		void switchingLayout();
		void on_about();
		void on_close_db();
		void on_new_student();
		void on_license();
		void on_view_student();
		void on_edit_student();
		void on_del_student();
		void on_add_student();
		void on_add_course();
		void on_view_course();
		void on_edit_course();
		void on_del_course();
		void on_new_mod();
		
	private:

		void make_actions();
		void make_menus();
		void make_status_bar();
		
		QMdiArea *mdiSpace;
		QString data_path;

		QAction *newdb;
		QAction *opendb;
		QAction *closedb;

		QAction *switcher;

		QAction *quit;

		QAction *fresh_student;
		QAction *admission;
		QAction *see_student;
		QAction *editing_student;
		QAction *delete_student;

		QAction *add_course;
		QAction *see_course;
		QAction *editing_course;
		QAction *delete_course;

		QAction *new_mod;
		QAction *view_mod;
		QAction *edit_mod;
		QAction *del_mod;

		QAction *about;
		QAction *license;
		QAction *aboutQT;
		
		QMenu *db_menu;
		QMenu *student_menu;
		QMenu *course_menu;
		QMenu *mod_menu;
		QMenu *help_menu;
};
