#pragma once

#include "student.h"

class del_student:public student{
    
    Q_OBJECT;
    
    public:
        del_student(QWidget* parent = 0);
        
    private:
		QPushButton* delete_stu;
		void create_buttons();
    
};
