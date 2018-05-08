#include "competition.h"

competition::competition(QWidget *parent)
	: QMainWindow(parent)
{
	
	modeselect = new QButtonGroup(this);
	distance = new QRadioButton(this);
	distance->setText("ֱ��");
	fare = new QRadioButton(this);
	fare->setText("��������");
	time = new QRadioButton(this);
	time->setText("ʱ�����");
	change = new QRadioButton(this);
	change->setText("תվ����");
	modeselect->addButton(distance, 1);
	modeselect->addButton(fare, 2);
	modeselect->addButton(time, 3);
	modeselect->addButton(change, 4);
	distance->setChecked(true);
	//connect(modeselect, SIGNAL(buttonToggled(int, bool)), this, SLOT(tolgclikced(int, bool)));
	connect(modeselect, SIGNAL(buttonClicked(int)), this, SLOT(btnclicked(int)));

	begin = new QLabel(this);
	beg = new QLineEdit(this);
	begin->setText("��������㣺");
	end = new QLabel(this);
	en = new QLineEdit(this);
	end->setText("�������յ㣺");
	start = new QPushButton(this);
	start->setText("���");
	connect(start, SIGNAL(clicked()), this, SLOT(build()));

	QHBoxLayout * hlayout0 = new QHBoxLayout;
	hlayout0->addWidget(distance);
	hlayout0->addWidget(fare);

	QHBoxLayout * hlayout1 = new QHBoxLayout;
	hlayout1->addWidget(time);
	hlayout1->addWidget(change);

	QHBoxLayout * hlayout2 = new QHBoxLayout;
	hlayout2->addWidget(begin);
	hlayout2->addWidget(beg);
	hlayout2->addWidget(end);
	hlayout2->addWidget(en);
	hlayout2->addWidget(start);

	tab = new TableWidget(this);
	vlayout = new QVBoxLayout;
	vlayout->addLayout(hlayout0);
	vlayout->addLayout(hlayout1);
	vlayout->addLayout(hlayout2);
	vlayout->addWidget(tab);

	QWidget *widget = new QWidget(this);
	widget->setLayout(vlayout);

	this->setCentralWidget(widget);

	QFile file("e.txt");
	if (!file.open(QIODevice::ReadOnly))
	{
		std::cerr << "Cannot open file for writing: " << qPrintable(file.errorString()) << std::endl;
		return;
	}
	QTextStream out(&file);
	//�ļ�����
	while (!out.atEnd())
	{
		out >> theVechile >> theBHour >> next >> theBMinute
			>> theEHour >> next >> theEMinute
			>> theCity1 >> theCity2 >> theCTime;
		out.skipWhiteSpace();
		out >> next >> theMoney;
		tab->train->insertEdge(theCity1, theCity2, theBHour, theBMinute, theEHour, theEMinute, theCTime, theMoney, theVechile);
	}
	file.close();

	p1 = new QDialog(this);
	p1->resize(300, 200);
	QPushButton* pb = new QPushButton(p1);
	pb->setText("ȷ��");
	connect(pb, SIGNAL(clicked()), this, SLOT(restart1()));
	QLabel* pt = new QLabel(p1);
	pt->setText("�����ڵ���ó��е��г�");
	QVBoxLayout *vlayouts = new QVBoxLayout(p1);
	vlayouts->addWidget(pt);
	vlayouts->addWidget(pb);

	p2 = new QDialog(this);
	p2->resize(300, 200);
	QPushButton* pb2 = new QPushButton(p2);
	pb2->setText("ȷ��");
	connect(pb2, SIGNAL(clicked()), this, SLOT(restart2()));
	QLabel* pt2 = new QLabel(p2);
	pt2->setText("�Ҳ���ֱ��·��");
	QVBoxLayout *vlayouts2 = new QVBoxLayout(p2);
	vlayouts2->addWidget(pt2);
	vlayouts2->addWidget(pb2);
	
	p3 = new QDialog(this);
	p3->resize(300, 200);
	QPushButton* pb3 = new QPushButton(p3);
	pb3->setText("OK");
	connect(pb3, SIGNAL(clicked()), this, SLOT(restart3()));
	QLabel* pt3 = new QLabel(p3);
	pt3->setText("�޷��ҵ���·��");
	QVBoxLayout *vlayouts3 = new QVBoxLayout(p3);
	vlayouts3->addWidget(pt3);
	vlayouts3->addWidget(pb3);
}

void competition::build()
{
	tab->table->clear();
	QString thecity1 = beg->text();
	QString thecity2 = en->text();
	if (tab->train->checkEdge(theCity1, theCity2))
	{
		tab->train->searchRoute(thecity1, thecity2, tab->table, p2);
	}
}


void competition::btnclicked(int id)
{

	tab->table->clear();
	QStringList header;
	header << "  �д�  " << "  ����ʱ��  " << "  ����ʱ��  " << "  ��ʱ  " << "  ������  " << "  Ŀ�ĵ�  " << "  ��Ʊ  ";
	tab->table->setHorizontalHeaderLabels(header);
	QString res;
	QString theCity1 = beg->text();
	QString theCity2 = en->text();
	tab->table->clear();
	if (tab->train->checkEdge(theCity1, theCity2))
	{
		if (id == 1)
		{
			tab->train->searchRoute(theCity1, theCity2, tab->table,p2);
		}
		else if (id == 2 || id == 3)
		{
			tab->train->Dijkstra(theCity1, theCity2, id - 1,p3);
			tab->train->searchPath(theCity1, theCity2, id - 1, tab->table, res);
		}
		else if (id == 4)
		{
			tab->train->searchStore(theCity1, theCity2, tab->table, res);
		}
	}
	else
	{
		p1->setModal(true);
		p1->show();
	}
	//tab->table->update();
}


void competition::restart1()
{
	p1->hide();
}

void competition::restart2()
{
	p2->hide();
}

void competition::restart3()
{
	p3->hide();
}