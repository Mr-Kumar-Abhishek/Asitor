#pragma once

#include "sub_win.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QPushButton>
#include <QFrame>
#include <QSplitter>


class new_student: public sub_win {

	Q_OBJECT;

	public:
		new_student(QWidget* parent = 0);

	private:
		QLabel* student_name;
		QLabel* guardian_name;
		QLabel* cellphone_no_1;
		QLabel* cellphone_no_2;
		QLabel* email_id;
		QLabel* gender;
		QLabel* dob;
		QLabel* acd;
		QLabel* education;
		QLabel* university;
		QLabel* institute;
		QLabel* marks;
		QLabel* degree;
		QLabel* pass_year;
		QLabel* ssc;
		QLabel* hsc;
		QLabel* graduation;
		QLabel* post_graduation;
		QLabel* course_applied;
		QLabel* exam_appearing;
		QLabel* taken_test;
		QLabel* postal_address;
		QLabel* address_label;
		QLabel* pin_code;


		QComboBox* gender_combo;
		QComboBox* course_applied_combo;
		QComboBox* exam_appearing_combo;

		QLineEdit* stu_name_line;
		QLineEdit* gua_name_line;
		QLineEdit* celphn_1_line;
		QLineEdit* celphn_2_line;
		QLineEdit* email_line;
		QLineEdit* dob_line;

		QLineEdit* ssc_uni_line;
		QLineEdit* hsc_uni_line;
		QLineEdit* graduation_uni_line;
		QLineEdit* post_graduation_uni_line;

		QLineEdit* ssc_insti_line;
		QLineEdit* hsc_insti_line;
		QLineEdit* graduation_insti_line;
		QLineEdit* post_graduation_insti_line;

		QLineEdit* ssc_marks_line;
		QLineEdit* hsc_marks_line;
		QLineEdit* graduation_marks_line;
		QLineEdit* post_graduation_marks_line;

		QLineEdit* ssc_degree_line;
		QLineEdit* hsc_degree_line;
		QLineEdit* graduation_degree_line;
		QLineEdit* post_graduation_degree_line;

		QLineEdit* pass_year_ssc_line;
		QLineEdit* pass_year_hsc_line;
		QLineEdit* pass_year_graduation_line;
		QLineEdit* pass_year_post_graduation_line;

		QLineEdit* pin_code_line;

		QTextEdit* address;

		QPushButton* n_stu_submit;
		QPushButton* n_stu_cancel;

		void make_labels();
		void make_line_edits();
		void make_comboboxes();
		void make_text_edits();
		void make_buttons();
};