#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void MainWindow::build()
{
	QString t = ui->radiusLineEdit->text();
	QList<QString> a = t.split(",");
	int size = a.size();
	d->avl->buildtree(a, size);
	d->update();
}