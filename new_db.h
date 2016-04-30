#pragma once

#include "sub_win.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlQuery>
#include <QGridLayout>
#include <QDir>
#include <QMessageBox>
#include <QDialog>
#include <QFileDialog>

class new_db : public sub_win {
	
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
		QPushButton* ncancel;
		QPushButton* browse; 
		bool exec_query(QSqlQuery query, QMessageBox* db_messages, bool success);
};
