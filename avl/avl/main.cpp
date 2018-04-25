#include "mainwindow.h"
#include <QtWidgets/QApplication>

void mainwindow::restart()
{
	qApp->closeAllWindows();
	QProcess::startDetached(qApp->applicationFilePath(), QStringList());
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	mainwindow w;
	w.resize(800, 600);
	w.show();
	return a.exec();
}
