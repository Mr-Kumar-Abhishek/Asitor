#include "about_app.h"

about_app::about_app(QWidget *parent):QWidget(parent) {
	this->setWindowTitle("About Asitor");
	QVBoxLayout* vbox = new QVBoxLayout(this);
	about_text = new QLabel("Asitor is an open-source, cross-platform, student information management system.", this);
	about_ok = new QPushButton("Okay", this);
	vbox->addWidget(about_text, 1);
	vbox->addWidget(about_ok, 0, Qt::AlignRight);
	setLayout(vbox);
	connect(about_ok, SIGNAL(clicked()), this, SLOT(on_okay()));
}

void about_app::on_okay(){
	this->parentWidget()->close();
}