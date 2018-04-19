#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

mainwindow::mainwindow(QWidget *parent)
	: QMainWindow(parent)
{
	initial = new QLineEdit(this);
	build = new QPushButton(this);
	build->setText("over");
	connect(build, SIGNAL(clicked()), this, SLOT(initialclicked()));

	QHBoxLayout * hlayout0 = new QHBoxLayout;
	hlayout0->addWidget(initial);
	hlayout0->addWidget(build);

	elem = new QLineEdit(this);
	insert = new QPushButton(this);
	insert->setText("Insert");
	connect(insert, SIGNAL(clicked()), this, SLOT(insertclicked()));

	QHBoxLayout * hlayout1 = new QHBoxLayout;
	hlayout1->addWidget(elem);
	hlayout1->addWidget(insert);


	todelete = new QLineEdit(this);
	buttondelete = new QPushButton(this);
	buttondelete->setText("Remove");
	connect(buttondelete, SIGNAL(clicked()), this, SLOT(deleteclicked()));

	QHBoxLayout * hlayout2 = new QHBoxLayout;
	hlayout1->addWidget(todelete);
	hlayout1->addWidget(buttondelete);


	QVBoxLayout *vlayout = new QVBoxLayout;
	d = new DrawWidget(this);
	vlayout->addLayout(hlayout0);
	vlayout->addLayout(hlayout1);
	vlayout->addLayout(hlayout2);
	vlayout->addWidget(d);

	time = new QTimer(this);
	tim = 1;

	QWidget *widget = new QWidget(this);
	widget->setLayout(vlayout);

	this->setCentralWidget(widget);
}

void mainwindow::buildtimer()
{
	QString t = initial->text();
	QList<QString> a = t.split(",");
	if (tim < a.size())
	{
		true_buildtimer(a);
		tim++;
	}
	else
	{
		if (time->isActive())
		{
			time->stop();
			disconnect(time, SIGNAL(timeout()), this, SLOT(buildtimer()));
		}
		tim = 1;
	}
}

void mainwindow::true_buildtimer(QList<QString> a)
{
	d->avl->Insert(a[tim]);
	d->update();
}

void mainwindow::initialclicked()
{
	QString t = initial->text();
	QList<QString> a = t.split(",");
	int size = a.size();
	d->avl->buildtree(a, size);
	d->update();
	if (a.size() > 1)
	{
		connect(time, SIGNAL(timeout()), this, SLOT(buildtimer()));
		time->start(1000);
		if (!time->isActive())
		{
			//time->stop();
			disconnect(time, SIGNAL(timeout()), this, SLOT(buildtimer()));
		}
	}
	
}

void mainwindow::inserttimer()
{
	QString _in = elem->text();
	QList<QString> a = _in.split(",");
	if (tim < a.size())
	{
		true_inserttimer(a);
		tim++;
	}
	else
	{
		if (time->isActive())
		{
			time->stop();
			disconnect(time, SIGNAL(timeout()), this, SLOT(inserttimer()));
		}
		tim = 1;
	}
}

void mainwindow::true_inserttimer(QList<QString> a)
{
	d->avl->Insert(a[tim]);
	d->update();
}

void mainwindow::insertclicked()
{
	QString _in = elem->text();
	QList<QString> a = _in.split(",");
	d->avl->Insert(a[0]);
	d->update();
	if (a.size() > 1)
	{
		connect(time, SIGNAL(timeout()), this, SLOT(inserttimer()));
		time->start(1000);
		if (!time->isActive())
		{
			//time->stop();
			disconnect(time, SIGNAL(timeout()), this, SLOT(inserttimer()));
		}
	}
}

void mainwindow::deletetimer()
{
	QString _de = todelete->text();
	QList<QString> a = _de.split(",");
	if (tim < a.size())
	{
		true_deletetimer(a);
		tim++;
	}
	else
	{
		if (time->isActive())
		{
			time->stop();
			disconnect(time, SIGNAL(timeout()), this, SLOT(deletetimer()));
		}
		tim = 1;
	}
}

void mainwindow::true_deletetimer(QList<QString> a)
{
	d->avl->Delete(a[tim]);
	d->update();
}

void mainwindow::deleteclicked()
{
	QString _de = todelete->text();
	QList<QString> a = _de.split(",");
	d->avl->Delete(a[0]);
	d->update();
	if (a.size() > 0)
	{
		connect(time, SIGNAL(timeout()), this, SLOT(deletetimer()));
		time->start(1000);
		if (!time->isActive())
		{
			//time->stop();
			disconnect(time, SIGNAL(timeout()), this, SLOT(deletetimer()));
		}
	}
	
}


