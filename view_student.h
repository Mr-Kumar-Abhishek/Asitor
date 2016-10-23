#pragma once

#include "new_student.h"

class view_student:public new_student {

    Q_OBJECT;
    
    public:
        view_student(QWidget* parent = 0);
    
};
