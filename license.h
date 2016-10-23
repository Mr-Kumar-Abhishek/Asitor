#pragma once

#include "sub_win.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class license_win : public sub_win {
	
	Q_OBJECT
    
    public:
        license_win(QWidget *parent = 0);
        
        
    private:
        QLabel* license_text;
        QPushButton* license_okay;

};
