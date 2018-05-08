#include "linkChain.h"
#include<iostream>
#include<QString>
#include<cstdlib>
#include<queue>
#include<stack>
#include<iomanip>
using std::queue;
using std::stack;
using std::cout;
using std::exit;

namespace
{//改变存储列车属性的数组长度
void changeArray2(element*& array, int theSize, int& theCapacity)
{
	if (theSize > theCapacity)
	{
		//cout << "Error!"<<"Your size"<<"("<<theSize<<")"<<">"<<"your capacity"<<"("<<theCapacity<<")"<<", theSize must be < theCapacity";
		system("pause");
	}
	theCapacity = 2 * theCapacity;
	element* temp = new element[theCapacity];
	//copy(array, array + theSize, temp);
	for (int i = 0; i < theSize; i++)
	{
		temp[i].bHour = array[i].bHour;
		temp[i].bMinute = array[i].bMinute;
		temp[i].eHour = array[i].eHour;
		temp[i].eMinute = array[i].eMinute;
		temp[i].cTime = array[i].cTime;
		temp[i].flag = array[i].flag;
		temp[i].money = array[i].money;
		temp[i].vechile = array[i].vechile;
	}
	delete[] array;
	array = temp;
}
}


QString linkChain::tostring(int a)
{
	QString s = QString::number(a);
	return s;
}

QString linkChain::tostring(double a)
{
	QString s = QString::number(a);
	return s;
}

//改变邻接链表左侧数组长度
void linkChain::changeArray1()
{
	capacity = capacity*2;
	alist* cityArray1 = new alist[capacity];
	for (int i = 0; i <size; i++)
	{
		if (cityArray[i].to.next == NULL)
			cityArray1[i].to.next = NULL;
		else
		{
			cityArray1[i].flag = cityArray[i].flag;
			cityArray1[i].to.city = cityArray[i].to.city;
			chainNode* p = cityArray[i].to.next;
			cityArray1[i].to.next = new chainNode(p->cost, p->city, p->muse, p->used);
			chainNode* pp = cityArray1[i].to.next;
			for (int j = 0; j < p->used; j++)
			{
				pp->cost[j].bHour = p->cost[j].bHour;
				pp->cost[j].bMinute = p->cost[j].bMinute;
				pp->cost[j].eHour = p->cost[j].eHour;
				pp->cost[j].eMinute = p->cost[j].eMinute;
				pp->cost[j].cTime = p->cost[j].cTime;
				pp->cost[j].vechile = p->cost[j].vechile;
				pp->cost[j].money = p->cost[j].money;
				pp->cost[j].flag = p->cost[j].flag;
			}
			p = p->next;
			while (p != NULL)
			{
				pp->next = new chainNode(p->cost, p->city, p->muse, p->used);
				pp = pp->next;
				for (int j = 0; j < p->used; j++)
				{
					pp->cost[j].bHour = p->cost[j].bHour;
					pp->cost[j].bMinute = p->cost[j].bMinute;
					pp->cost[j].eHour = p->cost[j].eHour;
					pp->cost[j].eMinute = p->cost[j].eMinute;
					pp->cost[j].cTime = p->cost[j].cTime;
					pp->cost[j].vechile = p->cost[j].vechile;
					pp->cost[j].money = p->cost[j].money;
					pp->cost[j].flag = p->cost[j].flag;
				}
				p = p->next;
			}
			pp->next = NULL;
		}
	}
	for (int i = size; i < capacity; i++)
		cityArray1[i].to.next = NULL;
	cityArray = new alist[capacity];
	for (int i = 0; i <size; i++)
	{
		if (cityArray1[i].to.next == NULL)
			cityArray[i].to.next = NULL;
		else
		{
			cityArray[i].flag = cityArray1[i].flag;
			cityArray[i].to.city = cityArray1[i].to.city;
			chainNode* p = cityArray1[i].to.next;
			cityArray[i].to.next = new chainNode(p->cost, p->city, p->muse, p->used);
			chainNode* pp = cityArray[i].to.next;
			for (int j = 0; j < p->used; j++)
			{
				pp->cost[j].bHour = p->cost[j].bHour;
				pp->cost[j].bMinute = p->cost[j].bMinute;
				pp->cost[j].eHour = p->cost[j].eHour;
				pp->cost[j].eMinute = p->cost[j].eMinute;
				pp->cost[j].cTime = p->cost[j].cTime;
				pp->cost[j].vechile = p->cost[j].vechile;
				pp->cost[j].money = p->cost[j].money;
				pp->cost[j].flag = p->cost[j].flag;
			}
			p = p->next;
			int a = 0;
			while (p != NULL)
			{
				pp->next = new chainNode(p->cost, p->city, p->muse, p->used);
				pp = pp->next;
				for (int j = 0; j < p->used; j++)
				{
					pp->cost[j].bHour = p->cost[j].bHour;
					pp->cost[j].bMinute = p->cost[j].bMinute;
					pp->cost[j].eHour = p->cost[j].eHour;
					pp->cost[j].eMinute = p->cost[j].eMinute;
					pp->cost[j].cTime = p->cost[j].cTime;
					pp->cost[j].vechile = p->cost[j].vechile;
					pp->cost[j].money = p->cost[j].money;
					pp->cost[j].flag = p->cost[j].flag;
				}
					p = p->next;
			}
			pp->next = NULL;
		}
	}
	for (int i = size; i < capacity; i++)
		cityArray[i].to.next = NULL;
	for (int i = 0; i <capacity; i++)
	{
		if (cityArray1[i].to.next == NULL)
			delete cityArray1[i].to.next;
		else
		{
			chainNode* first = cityArray1[i].to.next;
			while (first != NULL)
			{
				chainNode* nextNode = first->next;
				//delete[] first->cost;
				delete first;
				first = nextNode;
			}
		}
	}
	delete[] cityArray1;
}

linkChain::linkChain(int theCapacity)
{
	if (theCapacity < 0)
	{
		cout << "Error! The amount of citys must be >=0 ";
		exit(1);
	}
	capacity = theCapacity;
	size = 0; 
	e = 0;
	cityArray = new alist[theCapacity];
	for (int i = 0; i < capacity; i++)
	{
		cityArray[i].to.next = NULL;
	}
}

linkChain::linkChain(const linkChain& theLinkChain)
{
	size = theLinkChain.size;
	e = theLinkChain.e;
	capacity = theLinkChain.capacity;
	cityArray = new alist[capacity];
	for (int i = 0; i < theLinkChain.size;i++)
	{
		cityArray[i].flag = theLinkChain.cityArray[i].flag;
		cityArray[i].to.city = theLinkChain.cityArray[i].to.city;
		chainNode* p = theLinkChain.cityArray[i].to.next;
		cityArray[i].to.next = new chainNode(p->cost, p->city, p->muse, p->used);
		chainNode* pp = cityArray[i].to.next;
		while(p!=NULL)
		{
			pp->next = new chainNode(p->cost, p->city,p->muse, p->used,pp->next);
			for (int j = 0; j < p->used; j++)
			{
				pp->cost[j].bHour = p->cost[j].bHour;
				pp->cost[j].bMinute = p->cost[j].bMinute;
				pp->cost[j].eHour = p->cost[j].eHour;
				pp->cost[j].eMinute = p->cost[j].eMinute;
				pp->cost[j].vechile = p->cost[j].vechile;
				pp->cost[j].money = p->cost[j].money;
				pp->cost[j].flag = p->cost[j].flag;
			}
			p = p->next;
			pp = pp->next;
		}
		delete pp;
		delete p;
	}
}

linkChain::~linkChain()
{
	//先删除链，以及链指向的数组
	for (int i = 0; i < capacity; i++)
	{
		if (cityArray[i].to.next == NULL)
			delete[] cityArray[i].to.next;
		else
		{
			chainNode* p = cityArray[i].to.next;
			while (p != NULL)
			{
				chainNode* nextNode = p->next;
				delete[] p->cost;
				delete p;
				p = nextNode;
			}
		}
	}
	delete[] cityArray;
	delete[] costCity;
	delete[] pathCity;
}

bool linkChain::empty()
{
	if (size <= 0)
		return true;
	else
		return false;
}

int linkChain::getSize()
{
		return size;
}
//检查数组中是否有该城市
bool linkChain::searchCity(QString theCity)
{
	for (int i = 0; i < size; i++)
	{
		if (cityArray[i].to.city == theCity)
			return true;
    }
	return false;
}
//检查两城市之间是否存在路线,广度优先搜索
bool linkChain::checkEdge(QString city1, QString city2)
{
	queue<int> reg;//存储将标记flag变为0的点，在最后要再转为1；
	queue<QString> a;
	int i = 0;
	for (i; i < size; i++)
	{
		if (cityArray[i].to.city == city1)
			break;
	}
	if (i == size)
	{
		return false;
	}
	if (cityArray[i].to.next == NULL)
		return false;
	else
	{
		chainNode* p = cityArray[i].to.next;
		a.push(p->city);
		cityArray[i].flag = 0;
		reg.push(i);
		while (!a.empty())
		{
			a.pop();
			while (p != NULL)
			{
				if (p->city != city2)
				{
					a.push(p->city);
					p = p->next;
				}
				else
				{
					while (!reg.empty())
					{
						cityArray[reg.front()].flag = 1;
						reg.pop();
					}
					return true;
				}
			}
			int j = 0;
			while (j < size)
			{
				if (a.empty())
				{
					while (!reg.empty())
					{
						cityArray[reg.front()].flag = 1;
						reg.pop();
					}
					return false;
				}
				else if (a.front() == cityArray[j].to.city&&cityArray[j].flag != 0)
				{
					p = cityArray[j].to.next;
					cityArray[j].flag = 0;
					reg.push(j);
					break;
				}
				j++;
				if (j == size && a.front() != cityArray[j - 1].to.city)
				{
					j = 0;
					a.pop();
					if (a.empty())
					{
						while (!reg.empty())
						{
							cityArray[reg.front()].flag = 1;
							reg.pop();
						}
						return false;
					}
				}
			}

		}
		if (a.empty())
		{
			while (!reg.empty())
			{
				cityArray[reg.front()].flag = 1;
				reg.pop();
			}
			return false;
		}
	}
}
//检查城市之间是否存在直达的列车，方便以后添加车辆
bool linkChain::checkTransport(QString city1, QString city2, QString theVechile, int theBHour, int theBMinute)
{
	if (city1 == city2)
	{
		cout << "Depature city and your destincton cannot be the same";
		system("pause");
	}
	int i = 0;
	while (cityArray[i].to.city != city1 && i<size)//判断两个城市名是否相等，可改进
	{
		i++;
	}
	if (i<size)
	{
		chainNode* theNode;
		theNode = cityArray[i].to.next;
		while (theNode != NULL)
		{
			int j = 0;
			if (theNode->city != city2)
				theNode = theNode->next;
			else
			{
				for (; j < theNode->used; j++)
					if (theNode->cost[j].bHour == theBHour&&theNode->cost[j].bMinute ==theBMinute && theNode->cost[j].vechile == theVechile)
						break;
			}
			if (j > 0 && j < theNode->used)
				break;
			else if(theNode!=NULL)
				theNode = theNode->next;
		}
		if (theNode != NULL)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
//搜索直达路径
void linkChain::searchRoute(QString city1, QString city2,QTableWidget *table, QDialog *p2)
{
	//cout << "  列次  " << "  出发时间  " << "  到达时间  " << "  耗时  " << "  出发地  " << "  目的地  " << "  车票  \n";
	int i = 0;
	int t = 0;
	//table->clear();
	for (; i < size; i++)
	{
		if (cityArray[i].to.city == city1)
		{
			chainNode* p = cityArray[i].to.next;
			while (p != NULL)
			{
				if (p->city == city2)
				{

					for (int j = 0; j < p->used; j++)
					{
						table->setItem(j, 0, new QTableWidgetItem(p->cost[j].vechile));
						table->setItem(j, 1, new QTableWidgetItem(tostring(p->cost[j].bHour) + ":" + tostring(p->cost[j].bMinute)));
						table->setItem(j, 2, new QTableWidgetItem(tostring(p->cost[j].eHour) + ":" + tostring(p->cost[j].eMinute)));
						table->setItem(j, 3, new QTableWidgetItem(p->cost[j].cTime));
						table->setItem(j, 4, new QTableWidgetItem(city1));
						table->setItem(j, 5, new QTableWidgetItem(city2));
						table->setItem(j, 6, new QTableWidgetItem(tostring(p->cost[j].money)));
						/*cout << "  "<<p->cost[j].vechile << "   " << p->cost[j].bHour << ":" << p->cost[j].bMinute << "   " << p->cost[j].eHour << ":" << p->cost[j].eMinute
						<< "   " << p->cost[j].cTime << "   " << city1 << "   " <<city2<<"   "<<p->cost[j].money << "\n";*/
					}
					break;
				}
				p = p->next;
			}
			if (p == NULL)
				t = 1;//编译器原因，p在跳出循环后会被释放，在接下来的判断中无法利用p指针；
			break;
		}
	}
	if (i == size ||  t== 1)
	{
		p2->setModal(true);
		p2->show();
	}
}
//删除两个城市
void linkChain::eraseEdge(QString city1,QString city2)
{
	//判断城市是否存在
	if (!checkEdge(city1, city2))
	{
		if (!searchCity(city1))
		{
			cout << "Cannot find your departure city";
		}
		if (!searchCity(city2))
		{
			cout << "Cannot find your destinction!";
		}
		return ;
	}
	//删除城市之间的边
	for (int i = 0; i < size; ++i)
	{
		if (cityArray[i].to.city == city1)
		{
			chainNode* deleteNode,*theNode=NULL;
			deleteNode = cityArray[i].to.next;
			while (deleteNode->city != city2)
			{
				theNode = deleteNode;
				deleteNode = deleteNode->next;
			}
			if (deleteNode->next == NULL)
				delete deleteNode;
			else
			{
				theNode->next = deleteNode->next;
				delete deleteNode;
			}
			e--;
		}

	}
}
//插入路径
void linkChain::insertEdge(QString city1, QString city2, int theBHour, int theBMinute, int theEHour, int theEMinute, 
	                        QString theCtime,double theMoney,QString theVechile)
{
	element* thecost;
		int i = 0;
		for (; i < size; i++)
		{
			if (cityArray[i].to.city == city1)
				break;
		}
		if (i == size)
		{
			if (size >= capacity)
			{
				changeArray1();
			}
			cityArray[size].to.city = city1;
			m1[city1] = size;
			m2[size] = city1;
			size++;
		}

		chainNode* theNode=cityArray[i].to.next;
		chainNode* p = cityArray[i].to.next;
		int listSize = 0;
		while (theNode!=NULL&&theNode->city != city2 )
		{
			listSize++;
			p = theNode;
			theNode = theNode->next;
		}
		if (theNode!=NULL)
		{
			int j = 0;
			for (; j < theNode->used; j++)
			{
				if (theNode->cost[j].vechile == theVechile && theNode->cost[j].bHour == theBHour && theNode->cost[j].bMinute == theBMinute
					&& theNode->cost[j].eHour == theEHour && theNode->cost[j].eMinute == theEMinute && theNode->cost[j].money == theMoney)
				{//当重复时，确定是否接着输入,由于爬取的数据重复内容过多，就不进行判断，默认跳过
					//qDebug() << "The rout " << theVechile << " from " << city1 << " to " << city2 << " has been exited\n";
					break;
					/*cout << "\n" << "Go on?(Y/N)";
					std::cin >> ans;
					if (ans == 'y' || ans == 'Y')
						break;
					else
						exit(1);*/
				}
				else if (theNode->cost[j].vechile == theVechile)//可以对临时变更的信息及时更新
				{
					char ans;
					cout << "您确认要更新该趟列车信息？(y/n)";
					std::cin >> ans;
					if (ans == 'y' || ans == 'Y')
					{
						theNode->cost[j].bHour = theBHour;
						theNode->cost[j].bMinute = theBMinute;
						theNode->cost[j].eHour = theEHour;
						theNode->cost[j].eMinute = theEMinute;
						theNode->cost[j].money = theMoney;
					}
					else
						break;
				}
			}
			if (j == theNode->used)
			{
				if (theNode->used >= theNode->muse)
				changeArray2(theNode->cost, theNode->used, theNode->muse);
				theNode->cost[j].vechile = theVechile;
				theNode->cost[j].bHour = theBHour;
				theNode->cost[j].bMinute = theBMinute;
				theNode->cost[j].eHour = theEHour;
				theNode->cost[j].eMinute = theEMinute;
				theNode->cost[j].cTime = theCtime;
				theNode->cost[j].money = theMoney;
				theNode->used++; e++;
			}
		}
		else
		{
			if (listSize == 0)
			{
				cityArray[i].to.next = new chainNode(thecost, city2, 50, 0, cityArray[i].to.next);
				cityArray[i].to.next->cost[0].vechile = theVechile;
				cityArray[i].to.next->cost[0].bHour = theBHour;
				cityArray[i].to.next->cost[0].bMinute = theBMinute;
				cityArray[i].to.next->cost[0].eHour = theEHour;
				cityArray[i].to.next->cost[0].eMinute = theEMinute;
				cityArray[i].to.next->cost[0].cTime = theCtime;
				cityArray[i].to.next->cost[0].money = theMoney;
				cityArray[i].to.next->used++; e++;
			}
			else
			{
				p->next = new chainNode(thecost, city2, 50, 0, p->next);
				p = p->next;
				p->cost[0].vechile = theVechile;
				p->cost[0].bHour = theBHour;
				p->cost[0].bMinute = theBMinute;
				p->cost[0].eHour = theEHour;
				p->cost[0].eMinute = theEMinute;
				p->cost[0].cTime = theCtime;
				p->cost[0].money = theMoney;
				p->used++; e++;
			}
		}
}
//删除路径
void linkChain::eraseTransport(QString city1, QString city2, int theBHour, int theBMinute, QString theVechile)
{
	if (checkTransport(city1, city2, theVechile, theBHour, theBMinute))
	{
		int i = 0;
		for (i; i < size; i++)
		{
			if (cityArray[i].to.city == city1)
				break;
		}
		chainNode* p = cityArray[i].to.next;
		while (p->city!=city2)
		{
			p = p->next;
		}
		int j = 0;
		for (j; j < p->used; j++)
		{
			if (p->cost[j].bHour == theBHour&&p->cost[j].bMinute==theBMinute)
				break;
		}
		for (j; j < p->used; j++)
		{
			p->cost[j].bHour = p->cost[j + 1].bHour;
			p->cost[j].bMinute = p->cost[j + 1].bMinute;
			p->cost[j].eHour = p->cost[j + 1].eHour;
			p->cost[j].eMinute = p->cost[j + 1].eMinute;
			p->cost[j].cTime = p->cost[j + 1].cTime;
			p->cost[j].flag = p->cost[j + 1].flag;
			p->cost[j].money = p->cost[j + 1].money;
			p->cost[j].vechile = p->cost[j + 1].vechile;
		}
		p->used--;
	}
	else
	{
		cout << "Cannot find this route";
		exit(1);
	}
}
//判断消费数组是否为满
bool linkChain::full()
{
	int temp = inf;
	for (int i = 0; i < size; ++i)
	{
		if (costCity[i].flag==1&&costCity[i].value<temp)
			return false;
	}
	return true;
}
//寻找最短消耗路线
void linkChain::searchPath(QString city1,QString city2,int select, QTableWidget *table, QString &res)
{
	int* tempPath;
	tempPath = new int[size];
	int tot = 0;
	int temp=m1[city2];
	int temp2 = temp;
	while (temp != m1[city1])
	{
		tempPath[tot] = temp;
		tot++;
		temp = pathCity[temp].flag;
	}
	tempPath[tot] = temp;

	if (select == 1)
	{
		int kk = 0;
		//cout << "总消费为：" << costCity[temp2].value << "元\n";
		res = "总消费为："+QString::number(costCity[temp2].value)+ "元";
		//cout << "列次\t" << "出发时间\t" << "到达时间\t" << "耗时\t" << "出发地\t" << "目的地\t" << "车票（元）\n";
		for (int i = tot; i > 0; --i)
		{
				int k = tempPath[i - 1];
				//table->clear();
				if (pathCity[k].sig == 0)
				{
					table->setItem(kk, 0, new QTableWidgetItem(pathCity[k].vechile));
					table->setItem(kk, 1, new QTableWidgetItem(tostring(pathCity[k].bHour) + ":" + tostring(pathCity[k].bMinute)));
					table->setItem(kk, 2, new QTableWidgetItem(tostring(pathCity[k].eHour) + ":" + tostring(pathCity[k].eMinute)));
					table->setItem(kk, 3, new QTableWidgetItem(pathCity[k].cTime));
					table->setItem(kk, 4, new QTableWidgetItem(m2[tempPath[i]]));
					table->setItem(kk, 5, new QTableWidgetItem(m2[k]));
					table->setItem(kk, 6, new QTableWidgetItem(tostring(pathCity[k].money)));
					kk++;
					/*cout << pathCity[k].vechile << "\t" << pathCity[k].bHour << ":" << pathCity[k].bMinute << "\t" << pathCity[k].eHour << ":" <<
						pathCity[k].eMinute << "\t" << pathCity[k].cTime << "\t" << m2[tempPath[i]] << "\t" << m2[k] << "\t" << pathCity[k].money << "\n";*/
				}
				else
				{
					chainNode* p = cityArray[tempPath[i]].to.next;
					while (p != NULL)
					{
						if (p->city == m2[k])
						{
							for (int j = 0; j < p->used; j++)
							{
								if (p->cost[j].money == pathCity[k].money)
								{
									table->setItem(kk, 0, new QTableWidgetItem(p->cost[j].vechile));
									table->setItem(kk, 1, new QTableWidgetItem(tostring(p->cost[j].bHour) + ":" + tostring(p->cost[j].bMinute)));
									table->setItem(kk, 2, new QTableWidgetItem(tostring(p->cost[j].eHour) + ":" + tostring(p->cost[j].eMinute)));
									table->setItem(kk, 3, new QTableWidgetItem(p->cost[j].cTime));
									table->setItem(kk, 4, new QTableWidgetItem(m2[tempPath[i]]));
									table->setItem(kk, 5, new QTableWidgetItem(m2[k]));
									table->setItem(kk, 6, new QTableWidgetItem(tostring(p->cost[j].money)));
									kk++;
								}
								/*cout << p->cost[j].vechile << "\t" << p->cost[j].bHour << ":" << p->cost[j].bMinute
									<< "\t" << p->cost[j].eHour << ":" <<
									p->cost[j].eMinute << "\t" << p->cost[j].cTime << "\t" << m2[tempPath[i]]
									<< "\t" << m2[k] << "\t" << p->cost[j].money << "\n";*/
							}
						}
						p = p->next;
					}
				}
				if (i - 1 > 0)
				{
					QTableWidgetItem *items = new QTableWidgetItem("转");
					table->setItem(kk, 5, items);
					kk++;
				}
					
		}
		QTableWidgetItem *item = new QTableWidgetItem(res);
		table->setItem(kk, 3, item);
		table->resizeColumnsToContents();
		table->resizeRowsToContents();
		
	}
	else if (select == 2)
	{
		int kk = 0;
		int value=costCity[temp2].value;
		int tempMinute = (int)(value)%60;
		int pretempHour =(int)((value - tempMinute)/60);
		int tempHour = (int)(pretempHour) % 24;
		int tempDay = (int)((pretempHour - tempHour) / 24);
		//cout << "总耗时为：" << tempDay<<"天"<<tempHour << "时" << tempMinute << "分\n";
		//cout << "列次\t" << "出发时间\t" << "到达时间\t" << "耗时\t" << "出发地\t" << "目的地\t" << "车票（元）\n";
		//table->clear();
		res = "总耗时为：" + QString::number(tempDay) + "天" + QString::number(tempHour) + "时" + QString::number(tempMinute) + "分";
		for (int i = tot; i > 0; --i)
		{
				int k = tempPath[i - 1];
				table->setItem(kk, 0, new QTableWidgetItem(pathCity[k].vechile));
				table->setItem(kk, 1, new QTableWidgetItem(tostring(pathCity[k].bHour) + ":" + tostring(pathCity[k].bMinute)));
				table->setItem(kk, 2, new QTableWidgetItem(tostring(pathCity[k].eHour) + ":" + tostring(pathCity[k].eMinute)));
				table->setItem(kk, 3, new QTableWidgetItem(pathCity[k].cTime));
				table->setItem(kk, 4, new QTableWidgetItem(m2[tempPath[i]]));
				table->setItem(kk, 5, new QTableWidgetItem(m2[k]));
				table->setItem(kk, 6, new QTableWidgetItem(tostring(pathCity[k].money)));
				kk++;
				/*cout << pathCity[k].vechile << "\t" << pathCity[k].bHour << ":" << pathCity[k].bMinute << "\t" << pathCity[k].eHour << ":" <<
					pathCity[k].eMinute << "\t" << pathCity[k].cTime << "\t" << m2[tempPath[i]] << "\t" << m2[k] << "\t" << pathCity[k].money << "\n";*/
				if (i - 1 > 0)
				{
					QTableWidgetItem *items = new QTableWidgetItem("转");
					table->setItem(kk, 5, items);
					kk++;
				}
				//cout << "                          " << "转\n";
		}
		
		QTableWidgetItem *item = new QTableWidgetItem(res);
		table->setItem(kk, 3, item);
		table->resizeColumnsToContents();
		table->resizeRowsToContents();
	}

}
//迪杰特拉算法
void linkChain::Dijkstra(QString city1, QString city2,int select, QDialog *p3)
{
	int i = 0;
	for (; i < size; i++)
		if (city1 == cityArray[i].to.city)
			break;
	//判断是否存在
	if (i == size)
	{
		p3->setModal(true);
		p3->show();
		return;
	}
	//如果第二个城市没有插入左侧数组中，map映射会找不到相应的映射，所以在插入前需要判断，如果不存在需要建立映射
	int j = 0;
	for (; j < size; j++)
	{
		if (cityArray[j].to.city == city2)
			break;
	}
	if (j == size)
	{
		if (size >= capacity)
		{
			changeArray1();
		}
		cityArray[size].to.city = city2;
		m1[city2] = size;
		m2[size] = city2;
		size++;
	}

	Time t0,t1, t2,t3;
	costCity = new consume[size];
	pathCity = new element2[size];
	chainNode* p = cityArray[i].to.next;
	while (p != NULL)
	{
		double fmin = inf;
		double min = inf;
			int j = 0;
			int k = m1[p->city];
			for (; j < p->used; j++)
			{
				t1.hours = p->cost[j].bHour;
				t1.minutes = p->cost[j].bMinute;
				double tempValue;
				if (t1 >= t0)
				{
					if (select == 1)//方案一
					{
						tempValue = p->cost[j].money;
						if (tempValue== min && tempValue != fmin)//输出多个路径
							pathCity[k].sig = min;
					}
					else if (select == 2)//方案二
					{
						t2.hours = p->cost[j].eHour;
						t2.minutes = p->cost[j].eMinute;
						if (t2 >= t1)
						{
							tempValue = sub(t2, t1);

						}
						else//t2可能为第二天
						{
							t2.day = t2.day + 1;
							tempValue = sub(t2, t1);
							t2.day--;//t3的生命周期为整个函数，所以加完后需要恢复
						}
					}
					if ((tempValue<min) && searchCity(p->city))//判断是否符合时间要求,优化
	//由于数据本身原因，会存在链上的数据在数组中找不到的情况，所以必须加上searchCity（）判断该城市是否可以插入
					{
							min = tempValue;
							costCity[k].value = min;
							pathCity[k].bHour = p->cost[j].bHour;
							pathCity[k].bMinute = p->cost[j].bMinute;
							pathCity[k].cTime = p->cost[j].cTime;
							pathCity[k].eHour = p->cost[j].eHour;
							pathCity[k].eMinute = p->cost[j].eMinute;
							pathCity[k].money = p->cost[j].money;
							pathCity[k].vechile = p->cost[j].vechile;
					}
				}
			}
			pathCity[k].flag = m1[city1];//标记前驱城市
		p = p->next;
	}

	costCity[m1[city1]].value = 0;
	costCity[m1[city1]].flag = 0;//到达自己的为最小的，不能再更改，标为零；

	while (!full())
	{
		double fmin = inf;
		double temp = inf;
		int u ;
		for (int i = 0; i < size; ++i)
			if (costCity[i].flag==1&&costCity[i].value < temp)
			{
				temp = costCity[i].value;
				u = i;
			}
		costCity[u].flag = 0;//选出最小的一个消耗数组

		p = cityArray[u].to.next;
		t2.hours = pathCity[u].eHour;
		t2.minutes = pathCity[u].eMinute;
			while (p != NULL)
			{
				double min = inf;
				int j = 0;
				int g = j;//保存最小消耗的j所在的数组的位置
				double temp;
				int k = m1[p->city];
				for (; j < p->used; j++)
				{
					t1.hours = p->cost[j].bHour;
					t1.minutes = p->cost[j].bMinute;
					if (t1 >= t2)
					{//选出在一个数组下最小的值
						t3.hours = p->cost[j].eHour;
						t3.minutes = p->cost[j].eMinute;
						if (select == 1)
						{
							temp = p->cost[j].money;
							g = j;
							if (temp == min && temp != fmin)//输出多个路径
								pathCity[k].sig = min;
						}
						else if (select == 2)
						{
							if (t3 >= t1)
							{
								temp = sub(t3, t2);
								g = j;
							}
							else
							{
								t3.day = t3.day + 1;
								temp = sub(t3, t2);
								t3.day--;//恢复
								g = j;
							}
						}
						if (temp < min)
							min = temp;
					}
				}
				double newCost = costCity[u].value + min;
				if (costCity[k].flag&&costCity[k].value > newCost&&searchCity(p->city))
				{
					costCity[k].value = newCost;
					pathCity[k].bHour = p->cost[g].bHour;
					pathCity[k].bMinute = p->cost[g].bMinute;
					pathCity[k].cTime = p->cost[g].cTime;
					pathCity[k].eHour = p->cost[g].eHour;
					pathCity[k].eMinute = p->cost[g].eMinute;
					pathCity[k].money = p->cost[g].money;
					pathCity[k].vechile = p->cost[g].vechile;
					pathCity[k].flag = u;//标记前驱城市
				}
				p = p->next;
			}
	}
}

bool linkChain::Bfull()
{
	for (int i = 0; i < size; i++)
		if (storeCity[i].flag == -1&& storeCity[i].sig != -1)
			return false;
	return true;
}
//广度优先搜索找到最少转站次数
/*void linkChain::BFS(QString city1, QString city2)
{
	queue<int> count;
	int all=0;
	int i = 0;
	for (; i < size; i++)
		if (city1 == cityArray[i].to.city)
			break;
	//判断是否存在
	if (i == size)
	{
		cout << "Cannot find this route!";
		return;
	}
	//如果第二个城市没有插入左侧数组中，map映射会找不到相应的映射，所以在插入前需要判断，如果不存在需要建立映射
	int j = 0;
	for (; j < size; j++)
	{
		if (cityArray[j].to.city == city2)
			break;
	}
	if (j == size)
	{
		if (size >= capacity)
		{
			changeArray1();
		}
		cityArray[size].to.city = city2;
		m1[city2] = size;
		m2[size] = city2;
		size++;
	}
	int jud = m1[city2];
	storeCity = new element3[size];
	chainNode* p = cityArray[i].to.next;
	int u=0;
	int k;
	while (p != NULL)
	{
		k = m1[p->city];
		if(k!=0)
		storeCity[k].sig = m1[city1];//标记前驱
		p = p->next;
		storeCity[k].flag = all;
	}
	count.push(all);
	//int f = 0;//判断跳出循环的标志位
	//while (!Bfull())
	while(jud!=k)
	{
		int n = count.front();
		int m = 0;
		for (; m < size; m++)
		{
			if (storeCity[m].sig != -1 && storeCity[m].flag == n)
			{
				u = m;
				break;
			}
			if (m == size-1)
			{
				count.pop();
				cout << "aaaaaaaaaaaaa";
			}
		} 
		//storeCity[u].sig = 0;
		p = cityArray[u].to.next;
		all++;
		//cout << all << "\n";
		while (p != NULL)
		{
			k = m1[p->city];
			if (storeCity[k].flag == -1&&k!=0)
			{
				storeCity[k].sig = u;
				storeCity[k].flag = all;
			}
			if (k == jud)
				break;
			p = p->next;
		}
		count.push(all);
	}
}*/
QString linkChain::BFS(QString city1, QString city2)
{
	if (city1 == city2)
	{
		return city1;
	}
	else
	{
		queue<int> reg;
		QString nextCity;
		queue<QString> a;
		int i = 0;
		for (i; i < size; i++)
		{
			if (cityArray[i].to.city == city1)
				break;
		}
		chainNode* p = cityArray[i].to.next;
		a.push(city1);
		a.push(p->city);
		cityArray[i].flag = 0;
		reg.push(i);
		while (!a.empty())
		{
			nextCity = a.front();
			a.pop();
			while (p != NULL)
			{
				if (p->city != city2)
				{
					a.push(p->city);
					p = p->next;
				}
				else
				{
					while (!reg.empty())
					{
						cityArray[reg.front()].flag = 1;
						reg.pop();
					}
					//BFS(city1, nextCity);
					return nextCity;
				}
			}
			int j = 0;
			while (j < size)
			{
                 if (a.front() == cityArray[j].to.city&&cityArray[j].flag != 0)
				{
					p = cityArray[j].to.next;
					cityArray[j].flag = 0;
					reg.push(j);
					break;
				}
				j++;
				if (j == size && a.front() != cityArray[j - 1].to.city)
				{
					j = 0;
					a.pop();
				}
			}
		}
	}
}

void linkChain::searchStore(QString city1,QString city2, QTableWidget *table, QString &res)
{
	int kk = 0;
	stack<QString> tempPath;
	QString nextCity;
	nextCity = city2;
	tempPath.push(nextCity);
	do {
		nextCity=BFS(city1, nextCity);
		tempPath.push(nextCity);
	} while (tempPath.top() != city1);
	QString tempCity;
	//cout << "至少需要转" << tempPath.size()-1<<"站\n";
	res= "至少需要转" + QString::number(tempPath.size() - 1) + "站";
	//cout << "列次\t" << "出发时间\t" << "到达时间\t" << "耗时\t" << "出发地\t" << "目的地\t" << "车票（元）\n";
	while (nextCity!=city2)
	{
		tempCity = tempPath.top();
		tempPath.pop();
		chainNode* p=cityArray[m1[tempCity]].to.next;
		while (p != NULL)
		{
			nextCity = tempPath.top();
			//table->clear();
			if (p->city == nextCity)
			{
				for (int j = 0; j < p->used; j++)
				{
					table->setItem(kk, 0, new QTableWidgetItem(p->cost[j].vechile));
					table->setItem(kk, 1, new QTableWidgetItem(tostring(p->cost[j].bHour) + ":" + tostring(p->cost[j].bMinute)));
					table->setItem(kk, 2, new QTableWidgetItem(tostring(p->cost[j].eHour) + ":" + tostring(p->cost[j].eMinute)));
					table->setItem(kk, 3, new QTableWidgetItem(p->cost[j].cTime));
					table->setItem(kk, 4, new QTableWidgetItem(tempCity));
					table->setItem(kk, 5, new QTableWidgetItem(nextCity));
					table->setItem(kk, 6, new QTableWidgetItem(tostring(p->cost[j].money)));
					kk++;
				}
					/*cout << p->cost[j].vechile << "\t" << p->cost[j].bHour << ":" << p->cost[j].bMinute
					<< "\t" << p->cost[j].eHour << ":" <<
					p->cost[j].eMinute << "\t" << p->cost[j].cTime << "\t" << tempCity
					<< "\t" << nextCity << "\t" << p->cost[j].money << "\n";*/
			}
			p = p->next;
		}
		
		if (nextCity != city2)
		{
			table->setItem(kk, 5, new QTableWidgetItem("转"));
			kk++;
		}
			/*cout << "                          " << "转\n";*/
	}
	QTableWidgetItem *item = new QTableWidgetItem(res);
	table->setItem(kk, 3, item);
	table->resizeColumnsToContents();
	table->resizeRowsToContents();
}
