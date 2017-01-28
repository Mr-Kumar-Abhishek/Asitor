#pragma once

#include "course.h"

class edit_course: public course {
	
	Q_OBJECT;
	
	public:
		edit_course(QWidget* parent = 0);
	
	private: 
		QPushButton* e_cou_update;
		void create_buttons();
	
};
