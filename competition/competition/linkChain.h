#pragma once
#include<QString>
#include<map>
#include"mytime.h"
#include<qtablewidget.h>
#include<qdialog.h>
#pragma execution_character_set("utf-8")
#define inf 100000.0;
using std::map;
//表示消费数组，
struct consume
{
	double value;
	int flag;
	consume():value(100000),flag(1){}
};
//表示交通工具，火车（火车列次），飞机（航班）等交通信息的结构
struct element
{
	double money;//车票
	int bHour,bMinute;//到达时间
	//int byear, bmonth, bday;//也可以加上年月日，由于文件原因在此处忽略
	int eHour,eMinute;//结束时间
	//int eyear,emonth,eday;
	QString cTime;//消耗时间
 	QString vechile;//列车班次
	int flag;//标记前驱城市
	element() :money(100000), flag(-1) {}
};
//在寻找最短时间时，若遇到结束时间小于开始时间的情况，需要对结束时间的日期加一,如果文件日期齐全可以不要这个结构
struct element2
{
	double money;//车票
	int bHour, bMinute;//到达时间
	int eHour, eMinute;//结束时间
	QString cTime;//消耗时间
	QString vechile;//列车班次
	int flag;//标记前驱城市
	int sig;//作为标记，如果有多个城市有相同的票价，则对该城市进行标记
	element2() :money(100000), flag(-1),sig(0){}
};
//广度优先搜索的存储结构
struct element3
{
	int flag;//标志位
	int sig;//存储城市标号
	element3():flag(-1),sig(-1){}
};
//建立邻接链表结构
struct chainNode
{
	//成员变量
	element* cost;//代表距离，时间，金钱等消耗的动态数组,代表每个机场或火车站的飞机或火车数量
	QString city;//城市
	chainNode* next;
//	int num;
	int muse;//未用空间
	int used;//已用空间
	//方法
	chainNode(){}
	chainNode(element*& cost, const QString& city,int theMuse,int theUsed)
	{
		muse = theMuse; used = theUsed;
		cost = new element[muse];
		this->cost = cost;
		this->city = city;
		this->muse = muse;
		this->used = used;
	}
	chainNode(element*& cost, const QString& city,int theMuse,int theUsed, chainNode* next)
	{
		muse = theMuse; used = theUsed;
		cost = new element[muse];
		this->cost = cost;
		this->city = city;
		this->muse = muse;
		this->used = used;
		this->next = next;
	}
};

struct alist
{
	int flag;
	chainNode to;
	alist():flag(1) {}
};
//建立邻接链表
class linkChain
{
public:
	linkChain(int theCapacity = 800);
	linkChain(const linkChain& theLinkChain);
	~linkChain();

	
	void changeArray1();//改变数组长度
	bool empty();//判断是否为空
	int getSize();//城市数量
	//城市之间相连，唯一对应的航班可能不存在
	bool checkEdge(QString city1, QString city2);//城市之间的边是否存在（广度优先搜索）
	bool searchCity(QString theCity);//判断城市是否存在
	bool checkTransport(QString city1, QString city2, QString theVechile, int theBHour,int theBMinute);//检查该班次在某一时刻是否存在
	void searchRoute(QString city1, QString city2,QTableWidget *table,QDialog *p2);//寻找两城市之间的直达路线并输出；
	void eraseEdge(QString city1,QString city2);//删除城市之间的边
	void eraseTransport(QString city1, QString city2, int theBHour, int theBMinute,QString theVechile);//删除某一班列车或飞机
	void insertEdge(QString city1,QString city2, int theBHour, int theBMinute, int theEHour, int theEMinute, 
		QString theCtime, double theMoney, QString theVechile);//增加城市
	void Dijkstra(QString city1, QString city2,int select, QDialog *p3);//起点，终点
	bool full();//判断消费矩阵是否无法继续插入
	void searchPath(QString city1,QString city2,int select, QTableWidget *table, QString &res);
	bool Bfull();//判断存储BFS的数组是否为空
	QString BFS(QString city1,QString city2);
	void searchStore(QString city1, QString city2, QTableWidget *table, QString &res);
	QString tostring(int);
	QString tostring(double);
	
protected:
	alist* cityArray;
	int size;//城市数量
	int capacity;//容量
	int e;//城市边数
	consume *costCity;//消费数组
	element2 *pathCity;//存储矩阵路径
	//int* storeCity;
	element3* storeCity;//存储广度优先搜索的城市；
	map<QString, int> m1;//城市与数组序号之间建立映射关系
	map<int, QString> m2;
 };