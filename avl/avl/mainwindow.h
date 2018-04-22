#pragma once

#include <QtWidgets/QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include<QTimer>
#include"mydraw.h"
class mainwindow : public QMainWindow
{
	Q_OBJECT

public:
	QLineEdit * initial;
	QPushButton* build;
	QLineEdit * elem;
	QPushButton *insert;
	QLineEdit * todelete;
	QPushButton *buttondelete;
	QLineEdit* find;
	QPushButton* search;
	DrawWidget *d;
	QTimer *time;
	int tim;
	mainwindow(QWidget *parent = Q_NULLPTR);
	void true_buildtimer(QList<QString> a);
	void true_inserttimer(QList<QString> a);
	void true_deletetimer(QList<QString> a);
	void true_searchtimer(QList<QString> a);

private slots:
	void insertclicked();
	void deleteclicked();
	void initialclicked();
	void searchclicked();
	void buildtimer();
	void inserttimer();
	void deletetimer();
	void searchtimer();
};
