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
#include <QVBoxLayout>
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
	QPushButton* merge;
	QLineEdit* diin;
	QPushButton* divide;
	QLineEdit* merinp;
	DrawWidget* c;
	DrawWidget *d;
	DrawWidget* e;
	QWidget* tem;
	//QVBoxLayout* vlayout0;
	QVBoxLayout *vlayout;
	QTimer *time;
	QTimer *time2;
	QTimer *time3;
	QDialog* p;
	QPushButton* inse;
	QLineEdit* infind;
	QPushButton* inde;
	QLineEdit* inre;
	QHBoxLayout* hlayout6;
	//QHBoxLayout* hlayout7;
	int tim;
	node* temp;
	mainwindow(QWidget *parent = Q_NULLPTR);
	void true_buildtimer(QList<QString> a);
	void true_inserttimer(QList<QString> a);
	void true_deletetimer(QList<QString> a);
	void true_mergetimer(QList<QString> a);
	void true_dividetimer(QList<QString> a);
	void true_indetimer(QList<QString> a);
	int deabnormal(QList<QString> a);

private slots:
	void insertclicked();
	void deleteclicked();
	void initialclicked();
	void searchclicked();
	void ascendclicked();
	void divideclicked();
	void inseclicked();
	void indeclicked();
	void mergetimer();
	void dividetimer();
	void ascendtimer();
	void buildtimer();
	void inserttimer();
	void deletetimer();
	void searchtimer();
	void insetimer();
	void indetimer();
	void tolgclikced(int id, bool status);
	void btnclicked(int id);
	void restart();
	void mergeclicked();
	
};
