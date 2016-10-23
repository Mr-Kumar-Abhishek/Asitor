#pragma once

#include "student.h"

class edit_student:public student{
    
    Q_OBJECT;
    
    public:
        edit_student(QWidget* parent = 0);
        
    private:
		QPushButton* edit_update;
		void create_buttons();
		
};
