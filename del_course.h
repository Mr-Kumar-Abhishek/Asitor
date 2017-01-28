#pragma once

#include "course.h"

class del_course: public course {
	
	Q_OBJECT;
	
	public:
		del_course(QWidget* parent);
		
	private:
		QPushButton* cou_delete;
		void create_buttons();
		
};
