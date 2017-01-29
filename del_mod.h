#pragma once

#include "c_modules.h"

class del_mod: public c_modules{
	
	Q_OBJECT;
	
	public:
		del_mod(QWidget* parent = 0);
		
	private:
		QPushButton* cm_delete;
		void create_buttons();
};
