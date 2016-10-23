#include "license.h"

license_win::license_win(QWidget* parent):sub_win(parent){
    
    this->setWindowTitle("LICENSE");
    
    license_text = new QLabel("This software is licensed under GNU GPL v3");
    license_okay = new QPushButton("Okay");
    QVBoxLayout* vbox = new QVBoxLayout(this);
    
    vbox->addWidget(license_text, 1);
    vbox->addWidget(license_okay, 0, Qt::AlignRight);
    setLayout(vbox);
    
    connect(license_okay, SIGNAL(clicked()), this, SLOT(close_me()));
}
