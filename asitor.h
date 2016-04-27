#pragma once

#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QSplashScreen>
#include <QIcon>
#include <QLabel>
#include <QGridLayout>
#include <QObject>
#include <QDialog>
#include <QFileDialog>
#include <QComboBox>
#include <QDir>
#include <QLineEdit>
#include <QMessageBox>
#include <QMdiArea>
#include <QMainWindow>
#include <QtSql>
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
		
	private:

		void make_actions();
		void make_menus();
		void make_status_bar();
		
		QMdiArea *mdiSpace;
		QString data_path;
		QAction *newdb;
		QAction *opendb;
		QAction *closedb;
		QAction *quit;
		QAction *about;
		QAction *license;
		QAction *aboutQT;
		QMenu *db_menu;
		QMenu *help_menu;
};

class choose_db : public QWidget{

	Q_OBJECT

	public:
		choose_db(QWidget *parent = 0);

	private slots:
		void on_okay();
		void on_browse();

	private:
		QLabel* admin_email; 
		QLabel* password;
		QLabel* choose_dir;
		QLineEdit *email_line; 
		QLineEdit *pass_line;
		QPushButton *obutton;
		QPushButton *bbutton;
		QLineEdit *filepath;
		QLabel *open_db_file;
		void check_user(QString db_file);
};

class new_db : public QWidget {
	
	Q_OBJECT

	public:
		new_db(QWidget *parent = 0);

	private slots:
		void on_browse();
		void on_okay();

	private:
		QLabel* admin_email; 
		QLabel* password;
		QLabel* choose_dir;
		QLabel* give_db_name;
		QLineEdit *email_line; 
		QLineEdit *pass_line; 
		QLineEdit *dir_line;
		QLineEdit *db_name_line; 
		QPushButton* nokay;
		QPushButton* browse; 
		bool exec_query(QSqlQuery query, QMessageBox* db_messages, bool success);
};
