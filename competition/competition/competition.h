#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include"mytime.h"
#include"mytable.h"
#include<QFile>  
#include<QDebug>    
#include<QTextStream>  
#include<QDataStream> 
#include<qlineedit.h>
#include <qpushbutton.h>
#include<qradiobutton.h>
#include<qbuttongroup.h>
#include<qdialog.h>
#include<qlabel.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include<qwidget.h>
#include<qdialog.h>
#include<qprocess.h>

class competition : public QMainWindow
{
	Q_OBJECT

public:
	competition(QWidget *parent = 0);
	TableWidget *tab;//火车
	QString theWay;//出行方式
	int theBHour, theBMinute;//开始时间2
	int theEHour, theEMinute;//结束时间3
	QString theCTime;//消耗时间6
	double theMoney;//车票0
	QString theVechile;//列车班次1
	QString theCity1;//起始车站4
	QString theCity2;//终止车站5
	char next;
	QButtonGroup* modeselect;
	QRadioButton* distance;
	QRadioButton* fare;
	QRadioButton* time;
	QRadioButton* change;
	QLabel *begin;
	QLineEdit *beg;
	QLabel *end;
	QLineEdit *en;
	QPushButton *start;
	QVBoxLayout *vlayout;
	QDialog* p1;
	QDialog* p2;
	QDialog* p3;
private:
	
private slots :
	void build();
    //void tolgclikced(int id, bool status);
	void btnclicked(int id);
	void restart1();
	void restart2();
	void restart3();
};
