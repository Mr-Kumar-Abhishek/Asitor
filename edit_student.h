#pragma once

#include "new_student.h"

class edit_student:public new_student{
    
    Q_OBJECT;
    
    public:
        edit_student(QWidget* parent = 0);
};
