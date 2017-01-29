#include "view_mod.h"

view_mod::view_mod(QWidget* parent):c_modules(parent){
	
	this->setWindowTitle("View Modules");
	
	QHBoxLayout* hbox = new QHBoxLayout(this);
	
	hbox->addWidget(cm_cancel, 0, Qt::AlignRight);
	vbox->addLayout(hbox);
	
	setLayout(vbox);
	
}
