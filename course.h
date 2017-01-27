#pragma once

#include "sub_win.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

class course : public sub_win {
    
    Q_OBJECT;
    
    public:
        course(QWidget* parent = 0);
    
    protected:
        QVBoxLayout* vbox;
        QGridLayout* grid;
        QPushButton* cou_cancel;
        
    private:
        QLabel* course_code;
        QLabel* course_name;
        QLabel* course_desc;
        
        QLineEdit* c_code_line;
        QLineEdit* c_name_line;
        
        QTextEdit* c_desc;
        
        void make_labels();
        void make_line_edits();
        void make_text_edits();
        void make_buttons();
};
