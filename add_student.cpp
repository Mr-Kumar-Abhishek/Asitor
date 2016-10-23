#include "add_student.h"

add_student::add_student(QWidget* parent):student(parent){
    this->setWindowTitle("Admission");
    
    QHBoxLayout* hbox = new QHBoxLayout();
	
	create_buttons();
	hbox->addWidget(admit_stu, 1, Qt::AlignRight);
    hbox->addWidget(stu_cancel, 0);

    vbox->addLayout(hbox);
    vbox->addStretch(1);
    
    setLayout(vbox);
}

void add_student::create_buttons(){
	admit_stu = new QPushButton("Admit", this);
}
