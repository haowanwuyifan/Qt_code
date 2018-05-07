#pragma once
#include <QWidget>
#include"linkChain.h"
#include<qtablewidget.h>

class TableWidget : public QWidget
{
	Q_OBJECT
public:
	linkChain * train;
	TableWidget(QWidget *p = 0);
	QTableWidget* table;
};