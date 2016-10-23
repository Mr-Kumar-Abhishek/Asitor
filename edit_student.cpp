#include "edit_student.h"

edit_student::edit_student(QWidget *parent):student(parent){
    this->setWindowTitle("Edit Student");
    
    QHBoxLayout* hbox = new QHBoxLayout();
	
	create_buttons();
	hbox->addWidget(edit_update, 1, Qt::AlignRight);
    hbox->addWidget(stu_cancel, 0);

    vbox->addLayout(hbox);
    vbox->addStretch(1);
    
    setLayout(vbox);
}

void edit_student::create_buttons() {
	edit_update = new QPushButton("Update", this);
}
