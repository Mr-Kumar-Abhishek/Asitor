#include "new_student.h"

new_student::new_student(QWidget* parent):sub_win(parent){

	this->setWindowTitle("New Student");
	this->resize(550,120);

	make_labels();
	make_line_edits();
	make_comboboxes();
	make_text_edits();
	make_buttons();
	
	QVBoxLayout* vbox = new QVBoxLayout(this);

	QGridLayout* grid = new QGridLayout();

	grid->addWidget(student_name, 0, 0);
	grid->addWidget(stu_name_line, 0, 1);

	grid->addWidget(guardian_name, 1, 0);
	grid->addWidget(gua_name_line, 1, 1);

	grid->addWidget(email_id, 2, 0);
	grid->addWidget(email_line, 2, 1);
	
	vbox->addLayout(grid);
	vbox->addSpacing(15);

	grid = new QGridLayout();

	grid->addWidget(cellphone_no_1, 0, 0);
	grid->addWidget(celphn_1_line, 0, 1);
	grid->addWidget(cellphone_no_2, 0, 2);
	grid->addWidget(celphn_2_line, 0, 3);
	grid->addWidget(gender, 1, 0);
	grid->addWidget(gender_combo, 1, 1);
	grid->addWidget(dob, 1, 2);
	grid->addWidget(dob_line, 1, 3);

	vbox->addLayout(grid);
	vbox->addSpacing(15);

	vbox->addWidget(acd);
	vbox->addSpacing(15);

	grid = new QGridLayout();

	grid->addWidget(education, 0, 0);
	grid->addWidget(university, 0, 1);
	grid->addWidget(institute, 0, 2);
	grid->addWidget(marks, 0, 3);
	grid->addWidget(degree, 0, 4);
	grid->addWidget(pass_year, 0,5);

	grid->addWidget(ssc, 1,0);
	grid->addWidget(ssc_uni_line, 1, 1);
	grid->addWidget(ssc_insti_line, 1, 2);
	grid->addWidget(ssc_marks_line, 1, 3);
	grid->addWidget(ssc_degree_line,1, 4);
	grid->addWidget(pass_year_ssc_line, 1, 5);

	grid->addWidget(hsc, 2, 0);
	grid->addWidget(hsc_uni_line, 2, 1);
	grid->addWidget(hsc_insti_line, 2, 2);
	grid->addWidget(hsc_marks_line, 2, 3);
	grid->addWidget(hsc_degree_line, 2, 4);
	grid->addWidget(pass_year_hsc_line, 2, 5);

	grid->addWidget(graduation, 3, 0);
	grid->addWidget(graduation_uni_line, 3, 1);
	grid->addWidget(graduation_insti_line, 3, 2);
	grid->addWidget(graduation_marks_line, 3, 3);
	grid->addWidget(graduation_degree_line, 3, 4);
	grid->addWidget(pass_year_graduation_line, 3, 5);

	grid->addWidget(post_graduation, 4, 0);
	grid->addWidget(post_graduation_uni_line, 4 ,1);
	grid->addWidget(post_graduation_insti_line, 4, 2);
	grid->addWidget(post_graduation_marks_line, 4, 3);
	grid->addWidget(post_graduation_degree_line, 4, 4);
	grid->addWidget(pass_year_post_graduation_line, 4, 5);

	vbox->addLayout(grid);
	vbox->addSpacing(15);

	grid = new QGridLayout();
	grid->addWidget(course_applied, 0, 1);
	grid->addWidget(course_applied_combo, 0, 2 );
	grid->addWidget(exam_appearing, 0, 3);
	grid->addWidget(exam_appearing_combo, 0, 4);
	vbox->addLayout(grid);

	vbox->addSpacing(30);
	vbox->addWidget(postal_address);
	vbox->addSpacing(15);
	vbox->addWidget(address);
	vbox->addSpacing(30);


	QHBoxLayout* hbox = new QHBoxLayout();
	hbox->addWidget(n_stu_submit, 1, Qt::AlignRight);
	hbox->addWidget(n_stu_cancel, 0);

	vbox->addLayout(hbox);
	vbox->addStretch(1);

	setLayout(vbox);

	connect(n_stu_cancel, SIGNAL(clicked()), this , SLOT(close_me()));
}

void new_student::make_buttons() {

	n_stu_submit = new QPushButton("Submit", this);
	n_stu_cancel = new QPushButton("Cancel", this);

}

void new_student::make_text_edits() {

	address = new QTextEdit(this);

}

void new_student::make_comboboxes(){

	gender_combo = new QComboBox(this);
	gender_combo->addItem("");
	gender_combo->addItem("other");
	gender_combo->addItem("female");
	gender_combo->addItem("male");

	course_applied_combo = new QComboBox(this);
	course_applied_combo->addItem("");
	course_applied_combo->addItem("test course 1");
	course_applied_combo->addItem("test course 2");

	exam_appearing_combo = new QComboBox(this);
	exam_appearing_combo->addItem("");
	exam_appearing_combo->addItem("demo exam 1");
	exam_appearing_combo->addItem("demo exam 2");

}

void new_student::make_line_edits() {

	stu_name_line = new QLineEdit(this);
	gua_name_line = new QLineEdit(this);
	celphn_1_line = new QLineEdit(this);
	celphn_2_line = new QLineEdit(this);
	email_line = new QLineEdit(this);
	dob_line = new QLineEdit(this);

	ssc_uni_line = new QLineEdit(this);
	hsc_uni_line = new QLineEdit(this);
	graduation_uni_line = new QLineEdit(this);
	post_graduation_uni_line = new QLineEdit(this);

	ssc_insti_line = new QLineEdit(this);
	hsc_insti_line = new QLineEdit(this);
	graduation_insti_line = new QLineEdit(this);
	post_graduation_insti_line = new QLineEdit(this);

	ssc_marks_line = new QLineEdit(this);
	hsc_marks_line = new QLineEdit(this);
	graduation_marks_line = new QLineEdit(this);
	post_graduation_marks_line = new QLineEdit(this);

	ssc_degree_line = new QLineEdit(this);
	hsc_degree_line = new QLineEdit(this);
	graduation_degree_line = new QLineEdit(this);
	post_graduation_degree_line = new QLineEdit(this);

	pass_year_ssc_line = new QLineEdit(this);
	pass_year_hsc_line = new QLineEdit(this);
	pass_year_graduation_line = new QLineEdit(this);
	pass_year_post_graduation_line = new QLineEdit(this);

} 

void new_student::make_labels() {

	student_name = new QLabel("Student's Name : ", this);
	guardian_name = new QLabel("Gaurdian's Name : ", this);
	cellphone_no_1 = new QLabel("Primary Cellphone No.", this);
	cellphone_no_2 = new QLabel("Secondary Cellphone No.", this);	
	email_id = new QLabel("Email ID : ", this);
	gender = new QLabel("Gender : ", this);
	dob = new QLabel("Date of Birth :", this);

	acd = new QLabel("<u><b>Academic Details</b></u> <b>:</b>", this);

	education = new QLabel("<b>Education</b>", this);
	university = new QLabel("<b>Board / University</b>", this);
	institute = new QLabel("<b>&nbsp;Institute</b>", this);
	marks = new QLabel("<b>%Marks / CGPA</b>", this);

	degree = new QLabel("<b>Degree</b>", this);
	pass_year = new QLabel("<b>Year of passing</b>", this);
	ssc = new QLabel("SSC(10<sup>th</sup>)", this);
	hsc = new QLabel("HSC(12<sup>th</sup>)", this);
	graduation = new QLabel("Graduation", this);
	post_graduation = new QLabel("Post Graduation", this);

	course_applied = new QLabel("Course opted for :", this);
	exam_appearing = new QLabel("Exam to appear for :", this);

	postal_address = new QLabel("<b>Postal Address with pin code : <b>", this);

}
