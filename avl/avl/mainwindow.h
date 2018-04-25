#pragma once

#include <QtWidgets/QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include<qradiobutton.h>
#include<qbuttongroup.h>
#include<QTimer>
#include"mydraw.h"
#include<qdialog.h>
#include<qlabel.h>
#include<qprocess.h>
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
	QButtonGroup* modeselect;
	QRadioButton* normal;
	QRadioButton* abnormal;
	QPushButton* ascend;
	DrawWidget *d;
	QTimer *time;
	QDialog* p;
	int tim;
	node* temp;
	mainwindow(QWidget *parent = Q_NULLPTR);
	void true_buildtimer(QList<QString> a);
	void true_inserttimer(QList<QString> a);
	void true_deletetimer(QList<QString> a);
	void mode_change(int id);
	int deabnormal(QList<QString> a);

private slots:
	void insertclicked();
	void deleteclicked();
	void initialclicked();
	void searchclicked();
	void ascendclicked();
	void ascendtimer();
	void buildtimer();
	void inserttimer();
	void deletetimer();
	void searchtimer();
	void tolgclikced(int id, bool status);
	void btnclicked(int id);
	void restart();
};
