#pragma once

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>

class choose_db : public QWidget{

	Q_OBJECT

	public:
		choose_db(QWidget *parent = 0);

	private slots:
		void on_okay();
		void on_browse();
		void on_cancel();

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
