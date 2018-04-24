#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

mainwindow::mainwindow(QWidget *parent)
	: QMainWindow(parent)
{
	modeselect = new QButtonGroup(this);
	normal = new QRadioButton(this);
	normal->setText("normal");
	abnormal = new QRadioButton(this);
	abnormal->setText("index");
	modeselect->addButton(normal, 1);
	modeselect->addButton(abnormal, 2);
	normal->setChecked(true);
	connect(modeselect, SIGNAL(buttonToggled(int, bool)), this, SLOT(tolgclikced(int, bool)));
	connect(modeselect, SIGNAL(buttonClicked(int)), this, SLOT(btnclicked(int)));

	QHBoxLayout * hlayouts = new QHBoxLayout;
	hlayouts->addWidget(normal);
	hlayouts->addWidget(abnormal);

	initial = new QLineEdit(this);
	build = new QPushButton(this);
	build->setText("over");
	connect(build, SIGNAL(clicked()), this, SLOT(initialclicked()));

	find = new QLineEdit(this);
	search = new QPushButton(this);
	search->setText("search");
	connect(search, SIGNAL(clicked()), this, SLOT(searchclicked()));

	QHBoxLayout * hlayout0 = new QHBoxLayout;
	hlayout0->addWidget(initial);
	hlayout0->addWidget(build);
	hlayout0->addWidget(find);
	hlayout0->addWidget(search);

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
	vlayout->addLayout(hlayouts);
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
	Temp(d->avl, d->avl->getroot());
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
	Temp(d->avl, d->avl->getroot());
	d->update();
}

void mainwindow::insertclicked()
{
	QString _in = elem->text();
	QList<QString> a = _in.split(",");
	
		d->avl->Insert(a[0]);
		Temp(d->avl, d->avl->getroot());
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
	Temp(d->avl, d->avl->getroot());
	d->update();
}

void mainwindow::deleteclicked()
{
	QString _de = todelete->text();
	QList<QString> a = _de.split(",");
	
		d->avl->Delete(a[0]);
		Temp(d->avl, d->avl->getroot());
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

void mainwindow::searchtimer()
{
	QString se = find->text();
	node* sta = d->avl->Search(se);
	d->update();
	if (temp == sta)
	{
		d->avl->removepath(temp);
		temp = d->avl->getroot();
		if (time->isActive())
		{
			time->stop();
			disconnect(time, SIGNAL(timeout()), this, SLOT(searchtimer()));
		}
	}
	else
	{
		if (sta->element.first < temp->element.first)
		{
			d->avl->removepath(temp);
			if (temp->leftchild != NULL)
			{
				temp = temp->leftchild;
				d->avl->setpath(temp);
			}
			else
			{
				if (time->isActive())
				{
					time->stop();
					disconnect(time, SIGNAL(timeout()), this, SLOT(searchtimer()));
				}
				d->avl->removepath(temp);
				temp = d->avl->getroot();
				
			}
		}
		else if (sta->element.first > temp->element.first)
		{
			d->avl->removepath(temp);
			if (temp->rightchild != NULL)
			{
				temp = temp->rightchild;
				d->avl->setpath(temp);
			}
			else
			{
				if (time->isActive())
				{
					time->stop();
					disconnect(time, SIGNAL(timeout()), this, SLOT(searchtimer()));
				}
				d->avl->removepath(temp);
				temp = d->avl->getroot();
				
			}
		}
	}
}

void mainwindow::searchclicked()
{
	if (d->avl->get_mode() == 0)
	{
		QString se = find->text();
		node* st = d->avl->Search(se);
		if (st == NULL)
		{
			exit;
		}
		else
		{
			d->update();
			temp = d->avl->getroot();
			d->avl->setpath(temp);
			d->update();
			connect(time, SIGNAL(timeout()), this, SLOT(searchtimer()));
			time->start(1000);
			if (!time->isActive())
			{
				//time->stop();
				disconnect(time, SIGNAL(timeout()), this, SLOT(searchtimer()));
			}
		}
	}
	else if (d->avl->get_mode() == 1)
	{
		QString se = find->text();
		int num = se.toInt();
	}
}

void mainwindow::btnclicked(int id)
{
	if (id == 1)
	{
		d->avl->set_mode(0);
	}
	else if (id == 2)
	{
		d->avl->set_mode(1);
	}
}