#include "add_mod.h"

add_mod::add_mod(QWidget* parent):c_modules(parent) {
	
	this->setWindowTitle("Add modules");
	
	QHBoxLayout* hbox = new QHBoxLayout(this);
	
	create_buttons();
	
	hbox->addWidget(am_add, 1, Qt::AlignRight);
	hbox->addWidget(cm_cancel, 0);
	
	vbox->addLayout(hbox);
	setLayout(vbox);
	 
}

void add_mod::create_buttons(){
	
	am_add = new QPushButton("Add", this);
	
}
