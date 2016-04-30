#pragma once

#include <QObject>
#include <QWidget>

class sub_win : public QWidget {
	Q_OBJECT

	public: 
		sub_win(QWidget *parent = 0);

	private slots:
		void close_me(); 
};