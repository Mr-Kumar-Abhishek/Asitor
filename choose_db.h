#pragma once

#include "sub_win.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlQuery>
#include <QDir>
#include <QMessageBox>
#include <QDialog>
#include <QFileDialog>

class choose_db : public sub_win{

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
		QPushButton *cbutton;
		QLineEdit *filepath;
		QLabel *open_db_file;
		void check_user(QString db_file);
};
