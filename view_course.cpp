#include "view_course.h"

view_course::view_course(QWidget* parent):course(parent){

		this->setWindowTitle("view course");
		
		QHBoxLayout* hbox = new QHBoxLayout();
		
		hbox->addWidget(cou_cancel, 0, Qt::AlignRight);
	
		vbox->addLayout(hbox);
		vbox->addStretch(1);
		setLayout(vbox);	
	
};
