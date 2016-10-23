#pragma once

#include "student.h"

class add_student:public student {

    Q_OBJECT;
    
    public:
        add_student(QWidget* parent = 0);
    
    private:
        QPushButton* admit_stu;
        void create_buttons();
};
