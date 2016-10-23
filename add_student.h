#pragma once

#include "new_student.h"

class add_student:public new_student {

    Q_OBJECT;
    
    public:
        add_student(QWidget* parent = 0);
        
};
