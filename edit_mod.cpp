#include "edit_mod.h"

edit_mod::edit_mod(QWidget* parent):c_modules(parent){
		
	this->setWindowTitle("Update Modules");
		
	QHBoxLayout* hbox = new QHBoxLayout();
	
	create_buttons();

	hbox->addWidget(cm_update, 1, Qt::AlignRight);
	hbox->addWidget(cm_cancel, 0);
	
	vbox->addLayout(hbox);
	
	setLayout(vbox);

}

void edit_mod::create_buttons(){
	
	cm_update = new QPushButton("Update", this);
	
}
