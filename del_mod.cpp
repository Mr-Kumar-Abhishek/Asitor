#include "del_mod.h"

del_mod::del_mod(QWidget* parent):c_modules(parent){
	
	this->setWindowTitle("Delete Modules");
	
	QHBoxLayout* hbox = new QHBoxLayout();
	
	create_buttons();
	
	hbox->addWidget(cm_delete, 1, Qt::AlignRight);
	hbox->addWidget(cm_cancel, 0);
	
	vbox->addLayout(hbox);
	
	setLayout(vbox);
	
}

void del_mod::create_buttons(){
	
	cm_delete = new QPushButton("delete", this);
	
}
