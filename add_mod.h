#pragma once

#include "c_modules.h"

class add_mod : public c_modules {
	
	Q_OBJECT;
	
	public:
		add_mod(QWidget* parent = 0);
		
	private:
		QPushButton* am_add;
		void create_buttons();
	
};
