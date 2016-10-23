#include "view_student.h"

view_student::view_student(QWidget *parent):student(parent) {
    this->setWindowTitle("View Student");
    
    QHBoxLayout* hbox = new QHBoxLayout();
	
    hbox->addWidget(stu_cancel, 0, Qt::AlignRight);

    vbox->addLayout(hbox);
    vbox->addStretch(1);
    
    setLayout(vbox);
}
