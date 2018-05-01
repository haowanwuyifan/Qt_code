#include "train.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	train w;
	w.show();
	return a.exec();
}
