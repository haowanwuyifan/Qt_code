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

	ascend = new QPushButton(this);
	ascend->setText("Ascend");
	connect(ascend, SIGNAL(clicked()), this, SLOT(ascendclicked()));

	QHBoxLayout * hlayouts = new QHBoxLayout;
	hlayouts->addWidget(normal);
	hlayouts->addWidget(abnormal);
	hlayouts->addWidget(ascend);

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

	p = new QDialog(this);
	p->resize(300,200);
	QPushButton* pb = new QPushButton(p);
	pb->setText("OK");
	connect(pb, SIGNAL(clicked()), this, SLOT(restart()));
	QLabel* pt = new QLabel(p);
	pt->setText("error!");
	QVBoxLayout *vlayouts = new QVBoxLayout(p);
	vlayouts->addWidget(pt);
	vlayouts->addWidget(pb);
}

int mainwindow::deabnormal(QList<QString> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i].length() != 1)
		{
			return -1;
		}
		else
		{
			for (int j = 0; j < i; j++)
			{
				if (a[i].contains(a[j], Qt::CaseInsensitive))
				{
					return -1;
				}
			}
			
		}
	}
	return 1;
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
	if (deabnormal(a) == -1)
	{
		p->setModal(true);
		p->show();
	}
	else
	{
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
	if (deabnormal(a) == -1)
	{
		p->setModal(true);
		p->show();
	}
	else
	{
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
	if (d->avl->get_mode() == 0)
	{
		d->avl->Delete(a[tim]);
		Temp(d->avl, d->avl->getroot());
		d->update();
	}
	else if (d->avl->get_mode() == 1)
	{
		d->avl->_Delete(a[tim].toInt());
		Temp(d->avl, d->avl->getroot());
		d->update();
	}
}

void mainwindow::deleteclicked()
{
	if (d->avl->get_mode() == 0)
	{
		QString _de = todelete->text();
		QList<QString> a = _de.split(",");
		if (deabnormal(a) == -1)
		{
			p->setModal(true);
			p->show();
		}
		else
		{
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
	}
	else if (d->avl->get_mode() == 1)
	{
		Temp(d->avl, d->avl->getroot());
		QString _de = todelete->text();
		QList<QString> a = _de.split(",");
		if (deabnormal(a) == -1)
		{
			p->setModal(true);
			p->show();
		}
		else
		{
			int* n = new int[a.size()];
			for (int i = 0; i < a.size(); i++)
			{
				n[i] = a[i].toInt();
				if (n[i] <= 0)
				{
					p->setModal(true);
					p->show();
				}
			}
			d->avl->_Delete(n[0]);
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
	}
	
}

void mainwindow::searchtimer()
{
	if (d->avl->get_mode() == 0)
	{
		QString se = find->text();
		node* sta = d->avl->Search(se);
		d->update();
		if (temp == sta)
		{
			//d->avl->removepath(temp);
			//temp = d->avl->getroot();
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
					d->avl->removepath(temp);
					temp = d->avl->getroot();
					if (time->isActive())
					{
						time->stop();
						disconnect(time, SIGNAL(timeout()), this, SLOT(searchtimer()));
					}
					

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
					d->avl->removepath(temp);
					temp = d->avl->getroot();
					if (time->isActive())
					{
						time->stop();
						disconnect(time, SIGNAL(timeout()), this, SLOT(searchtimer()));
					}
					

				}
			}
		}
	}
	else if (d->avl->get_mode() == 1)
	{
		QString se = find->text();
		int num = se.toInt();
		node* sta = d->avl->Search_(num);
		d->update();
		if (temp == sta)
		{
			//d->avl->removepath(temp);
			//temp = d->avl->getroot();
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
					d->avl->removepath(temp);
					temp = d->avl->getroot();
					if (time->isActive())
					{
						time->stop();
						disconnect(time, SIGNAL(timeout()), this, SLOT(searchtimer()));
					}
					

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
					d->avl->removepath(temp);
					temp = d->avl->getroot();
					if (time->isActive())
					{
						time->stop();
						disconnect(time, SIGNAL(timeout()), this, SLOT(searchtimer()));
					}
					

				}
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
			p->setModal(true);
			p->show();
		}
		else
		{
			d->avl->removepath(temp);
			d->update();
			temp = d->avl->getroot();
			d->avl->setpath(temp);
			d->update();
			connect(time, SIGNAL(timeout()), this, SLOT(searchtimer()));
			time->start(1000);
			if (!time->isActive())
			{
				disconnect(time, SIGNAL(timeout()), this, SLOT(searchtimer()));
			}
		}
	}
	else if (d->avl->get_mode() == 1)
	{
		Temp(d->avl, d->avl->getroot());
		QString se = find->text();
		int num = se.toInt();
		if (num <= 0)
		{
			p->setModal(true);
			p->show();
		}
		else
		{
			node* st = d->avl->Search_(num);
			if (st == NULL)
			{
				p->setModal(true);
				p->show();
			}
			else
			{
				d->avl->removepath(temp);
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
		
	}
}

void mainwindow::ascendtimer()
{
	d->update();
	
	if (d->avl->succ(temp) != NULL)
	{
		d->avl->removepath(temp);
		temp = d->avl->succ(temp);
		d->avl->setpath(temp);
	}
	else
	{
		d->avl->removepath(temp);
		temp = d->avl->getroot();
		if (time->isActive())
		{
			time->stop();
			disconnect(time, SIGNAL(timeout()), this, SLOT(ascendtimer()));
		}
	}
}

void mainwindow::ascendclicked()
{
	temp = d->avl->getroot();
	while (temp&&temp->leftchild)
	{
		temp = temp->leftchild;
	}
	d->avl->setpath(temp);
	d->update();
	connect(time, SIGNAL(timeout()), this, SLOT(ascendtimer()));
	time->start(1000);
	if (!time->isActive())
	{
		
		disconnect(time, SIGNAL(timeout()), this, SLOT(ascendtimer()));
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

void mainwindow::mode_change(int id)
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

void mainwindow::tolgclikced(int id, bool status)
{
	mode_change(3 - id);
	Temp(d->avl, d->avl->getroot());
	d->update();
}

