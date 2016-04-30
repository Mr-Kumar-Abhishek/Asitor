#include "sub_win.h"

sub_win::sub_win(QWidget *parent): QWidget(parent) {}

void sub_win::close_me() {
	this->parentWidget()->close();
}