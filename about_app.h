#pragma once

#include "sub_win.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class about_app : public sub_win {

	Q_OBJECT

	public:
		about_app(QWidget *parent = 0);

	private:
		QLabel* about_text;
		QPushButton* about_ok;
};