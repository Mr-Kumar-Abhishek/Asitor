#pragma once

#include "student.h"


class new_student: public student{

	Q_OBJECT;

	public:
		new_student(QWidget* parent = 0);

	private:
		QPushButton* n_stu_submit;
		void create_buttons();
};
