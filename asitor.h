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


class manage_db : public QMainWindow {

	Q_OBJECT

	public:
		manage_db(QString data_path);
};

class choose_db : public QWidget{

	Q_OBJECT

	public:
		choose_db(QWidget *parent = 0);

	private slots:
		void on_okay();
		void on_browse();
		void on_new();

	private:
		QLabel* admin_email; 
		QLabel* password;
		QLabel* choose_dir;
		QLabel* give_db_name;
		QLineEdit *email_line; 
		QLineEdit *pass_line;
		QPushButton *qbutton;
		QPushButton *obutton;
		QPushButton *bbutton;
		QPushButton *nbutton;
		QLineEdit *filepath;
		QLabel *label;
		void check_user(QString db_file);
};

class new_db : public QWidget {
	
	Q_OBJECT

	public:
		new_db(QWidget *parent = 0);

	private slots:
		void on_back();
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
		QPushButton* ncancel; 
		QPushButton* browse; 
		QPushButton* nback; 
		bool exec_query(QSqlQuery query, QMessageBox* db_messages, bool success);
};
