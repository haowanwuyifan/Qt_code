#pragma once

#include <QtWidgets/QDialog>
#include "ui_area.h"

class area : public QDialog
{
	Q_OBJECT

public:
	area(QWidget *parent = Q_NULLPTR);

private:
	Ui::areaClass ui;

	public slots:
	void Btn_Click();
};
