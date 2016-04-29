#pragma once

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class about_app : public QWidget {

	Q_OBJECT

	public:
		about_app(QWidget *parent = 0);

	private slots:
		void on_okay();

	private:
		QLabel* about_text;
		QPushButton* about_ok;
};