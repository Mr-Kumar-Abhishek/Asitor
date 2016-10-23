#include "new_student.h"

new_student::new_student(QWidget* parent):student(parent){

	this->setWindowTitle("New Student");
	
	QHBoxLayout* hbox = new QHBoxLayout();
	
	create_buttons();
	hbox->addWidget(n_stu_submit, 1, Qt::AlignRight);
	hbox->addWidget(stu_cancel, 0);

	vbox->addLayout(hbox);
	vbox->addStretch(1);

	setLayout(vbox);
}

void new_student::create_buttons() {

	n_stu_submit = new QPushButton("Submit", this);
	
}

