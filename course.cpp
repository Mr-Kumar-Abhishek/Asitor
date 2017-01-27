#include "course.h"

course::course(QWidget* parent):sub_win(parent){
	this->setWindowTitle("Course");
	this->resize(550,120);
	this->setWindowFlags(Qt::WindowCloseButtonHint);
	
	make_labels();
	make_text_edits();
	make_line_edits();
	make_buttons();
	
	
	vbox = new QVBoxLayout(this);
	
	grid = new QGridLayout();
	grid->addWidget(course_code, 0, 0);
	grid->addWidget(c_code_line, 0 , 1);
	grid->addWidget(course_name, 1, 0);
	grid->addWidget(c_name_line, 1, 1); 
	
	vbox->addLayout(grid);
	vbox->addWidget(course_desc);
	vbox->addWidget(c_desc);
	vbox->addSpacing(30); 
	
	connect(cou_cancel, SIGNAL(clicked()), this , SLOT(close_me()));
}

void course::make_buttons(){
	
	cou_cancel = new QPushButton("Cancel", this);
	
}

void course::make_labels(){
	
	course_code = new QLabel("Course Code :", this);
	course_desc = new QLabel("Course Description:", this);
	course_name = new QLabel("Course Name :", this);
	
}

void course::make_line_edits(){
	
	c_code_line = new QLineEdit(this);
	c_name_line = new QLineEdit(this);
	
}

void course::make_text_edits(){
	c_desc = new QTextEdit(this);
}
