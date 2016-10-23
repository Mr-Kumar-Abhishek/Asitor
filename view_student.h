#pragma once

#include "student.h"

class view_student:public student {

    Q_OBJECT;
    
    public:
        view_student(QWidget* parent = 0);
    
};
