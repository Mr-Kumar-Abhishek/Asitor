#include "del_course.h"

del_course::del_course(QWidget* parent):course(parent){
	
	this->setWindowTitle("Delete Course");
	
	QHBoxLayout* hbox = new QHBoxLayout();
	
	create_buttons();
	
	hbox->addWidget(cou_delete, 1, Qt::AlignRight);
	hbox->addWidget(cou_cancel, 0);
	
	vbox->addLayout(hbox);
	vbox->addStretch(1);
	setLayout(vbox);	
	
}

void del_course::create_buttons(){
	
	cou_delete = new QPushButton("Delete", this);

}
