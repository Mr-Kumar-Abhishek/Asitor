#pragma once

#include "sub_win.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class close_db: public sub_win {
	
	Q_OBJECT

	public:
		close_db(QWidget *parent = 0);

	private:
		QVBoxLayout* vbox;
		QHBoxLayout* hbox;
		QLabel *ask_close;
		QPushButton *cancel_close_db;
		QPushButton *ok_close_db;
		void create_buttons();
		void create_labels();
};
