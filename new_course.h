#pragma once

#include "course.h"

class new_course:public course {
	
	Q_OBJECT;
	
	public:
		new_course(QWidget* parent = 0);
		
		private:
			QPushButton* n_cou_submit;
			void create_buttons();
};
