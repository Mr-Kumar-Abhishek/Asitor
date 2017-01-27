#include "new_course.h"

new_course::new_course(QWidget* parent):course(parent){
	
	this->setWindowTitle("New Course");

	QHBoxLayout* hbox = new QHBoxLayout();
	
	create_buttons();
	
	hbox->addWidget(n_cou_submit, 1, Qt::AlignRight);
	hbox->addWidget(cou_cancel, 0);
	
	vbox->addLayout(hbox);
	vbox->addStretch(1);
	setLayout(vbox);	
	
}

void new_course::create_buttons(){
	
	n_cou_submit = new QPushButton("Save", this);
	
}
