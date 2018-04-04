#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStringList"
//#include"AVL.h"
//#include"myqueue.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_overBtn_clicked()
{
    this->hide();
    dialog->show();
    QString t=ui->radiusLineEdit->text();
    QStringList a=t.split(",");
    int size=a.size();


}

void MainWindow::on_inBtn_clicked()
{
    char in=ui->radiusLineEdit_in->text();
    //char a=in;
    int n=(int)in-96;
    d->avl->insert(n);
}
