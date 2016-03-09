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


class choose_db : public QWidget{

	 Q_OBJECT

	public:
		choose_db(QWidget *parent = 0);

	private slots:
		void on_okay();
		void on_browse();
		void on_new();
};
