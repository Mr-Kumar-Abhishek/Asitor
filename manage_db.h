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
		QAction *about;
		QAction *license;
		QAction *aboutQT;
		QMenu *db_menu;
		QMenu *help_menu;
};