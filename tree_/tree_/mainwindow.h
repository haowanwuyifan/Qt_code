#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

class mainwindow : public QMainWindow
{
	Q_OBJECT

public:
	mainwindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::mainwindowClass ui;

private slots:
void build();
void in();
void de();
void se();
};
