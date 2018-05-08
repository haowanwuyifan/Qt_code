#include "competition.h"
#pragma execution_character_set("utf-8")
#include <QtWidgets/QApplication>



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	competition w;
	w.resize(600, 800);
	w.show();
	return a.exec();
}
