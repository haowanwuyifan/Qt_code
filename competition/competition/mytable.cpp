#include"mytable.h"
#include "linkChain.h"
#include<iostream>
#include<QString>
#include<cstdlib>
#include<queue>
#include<stack>
#include<iomanip>
#include<qtablewidget.h>
#pragma execution_character_set("utf-8")
using std::queue;
using std::stack;
using std::cout;
using std::exit;

TableWidget::TableWidget(QWidget *p) :QWidget(p)
{
	train = new linkChain;
	table = new QTableWidget(this);
	table->setRowCount(100);
	table->setColumnCount(7);
	table->resize(600, 600);
	//table->setWindowTitle("aaa");
	QStringList header;
	header << "  �д�  " << "  ����ʱ��  " << "  ����ʱ��  " << "  ��ʱ  " << "  ������  " << "  Ŀ�ĵ�  " << "  ��Ʊ  ";
	table->setHorizontalHeaderLabels(header);
	table->resizeColumnsToContents();
	table->resizeRowsToContents();
}
