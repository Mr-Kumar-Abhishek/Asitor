#pragma once

#include "c_modules.h"

class edit_mod: public c_modules {
	
	Q_OBJECT;
	
	public:
	
		edit_mod(QWidget* parent = 0);
		
	private:
		QPushButton* cm_update;
		void create_buttons();
		
};
