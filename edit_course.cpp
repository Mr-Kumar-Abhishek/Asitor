#include "edit_course.h"

edit_course::edit_course(QWidget* parent):course(parent) {
	
	this->setWindowTitle("Edit Course");
	
	QHBoxLayout* hbox = new QHBoxLayout();
	
	create_buttons();
	
	hbox->addWidget(e_cou_update, 1, Qt::AlignRight);
	hbox->addWidget(cou_cancel, 0);
	
	vbox->addLayout(hbox);
	vbox->addStretch(1);
	setLayout(vbox);	
	
}

void edit_course::create_buttons(){
	
	e_cou_update = new QPushButton("Update", this);
	
}
