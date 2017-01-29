#pragma once

#include "sub_win.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

class c_modules: public sub_win {
	
	Q_OBJECT;
	
	public:
		c_modules(QWidget* parent = 0);
		
	protected:
		QVBoxLayout* vbox;
		QGridLayout* grid;
		QPushButton* cm_cancel;
		
	private:
		QLabel* mod_name;
		QLabel* mod_code;
		QLabel* mod_desc;
		QLineEdit* mod_name_line;
		QLineEdit* mod_code_line;
		QTextEdit* mod_desc_text;
		
		void make_labels();
		void make_line_edits();
		void make_text_edits();
		void make_buttons();
		
};
