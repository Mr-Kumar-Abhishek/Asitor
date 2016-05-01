#include "close_db.h"

close_db::close_db(QWidget *parent): sub_win(parent) {
	this->setWindowTitle("Close Database");
	ask_close = new QLabel("Do you really want to close this database ??", this);
	cancel_close_db = new QPushButton("Cancel", this);
	ok_close_db = new QPushButton("Okay", this);

	QVBoxLayout *vbox = new QVBoxLayout(this);
	
	QHBoxLayout *hbox = new QHBoxLayout();
	hbox->addWidget(ask_close);
	vbox->addLayout(hbox);
	
	hbox = new QHBoxLayout();
	hbox->addWidget(ok_close_db, 1, Qt::AlignRight);
	hbox->addWidget(cancel_close_db, 0);

	vbox->addLayout(hbox);

	setLayout(vbox);

	connect(cancel_close_db, SIGNAL(clicked()), this, SLOT(close_me()));
}