#include "del_student.h"

del_student::del_student(QWidget *parent):student(parent){
	this->setWindowTitle("Delete Student");
		
    QHBoxLayout* hbox = new QHBoxLayout();
	
	create_buttons();
	hbox->addWidget(delete_stu, 1, Qt::AlignRight);
    hbox->addWidget(stu_cancel, 0);

    vbox->addLayout(hbox);
    vbox->addStretch(1);
    
    setLayout(vbox);
}

void del_student::create_buttons(){
	delete_stu = new QPushButton("Delete", this);
}
