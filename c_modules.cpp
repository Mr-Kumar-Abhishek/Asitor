#include "c_modules.h"

c_modules::c_modules(QWidget* parent):sub_win(parent){
	
	this->setWindowTitle("Modules");
	this->resize(550,120);
	this->setWindowFlags(Qt::WindowCloseButtonHint);
	
	make_labels();
	make_line_edits();
	make_text_edits();
	make_buttons();
	
	vbox = new QVBoxLayout(this);
	
	grid = new QGridLayout();
	grid->addWidget(mod_code, 0, 0);
	grid->addWidget(mod_code_line, 0, 1);
	grid->addWidget(mod_name, 1, 0);
	grid->addWidget(mod_name_line, 1, 1);
	
	vbox->addLayout(grid);
	
	vbox->addWidget(mod_desc);
	vbox->addWidget(mod_desc_text);
	vbox->addSpacing(30);
	
	connect(cm_cancel, SIGNAL(clicked()), this, SLOT(close_me()));
	
}

void c_modules::make_labels(){
	mod_name = new QLabel("Module Name:", this);
	mod_code = new QLabel("Module Code:", this);
	mod_desc = new QLabel("Module Description:", this);
}

void c_modules::make_line_edits(){
	mod_name_line = new QLineEdit(this);
	mod_code_line = new QLineEdit(this);
}

void c_modules::make_text_edits(){
	mod_desc_text = new QTextEdit(this);
}

void c_modules::make_buttons(){
	cm_cancel = new QPushButton("cancel", this);
}
