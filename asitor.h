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


class choose_db : public QWidget{

	Q_OBJECT

	public:
		choose_db(QWidget *parent = 0);

	private slots:
		void on_okay();
		void on_browse();
		void on_new();

	private:
		QPushButton *qbutton;
		QPushButton *obutton;
		QPushButton *bbutton;
		QPushButton *nbutton;
		QLineEdit *filepath;
		QLabel *label;
};

class new_db : public QWidget {
	
	Q_OBJECT

	public:
		new_db(QWidget *parent = 0);

	private slots:
		void on_back();
		void on_browse();

	private:
		QLabel* admin_email; 
		QLabel* password;
		QLabel* choose_dir;
		QLineEdit *email_line; 
		QLineEdit *pass_line; 
		QLineEdit *dir_line; 
		QPushButton* nokay;
		QPushButton* ncancel; 
		QPushButton* browse; 
		QPushButton* nback; 
};
