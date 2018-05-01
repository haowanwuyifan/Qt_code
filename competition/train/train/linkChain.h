#pragma once
#include<string>
#include<map>
#include"time.h"
#define inf 100000.0;
using std::string;
using std::map;
//��ʾ�������飬
struct consume
{
	double value;
	int flag;
	consume():value(100000),flag(1){}
};
//��ʾ��ͨ���ߣ��𳵣����дΣ����ɻ������ࣩ�Ƚ�ͨ��Ϣ�Ľṹ
struct element
{
	double money;//��Ʊ
	int bHour,bMinute;//����ʱ��
	//int byear, bmonth, bday;//Ҳ���Լ��������գ������ļ�ԭ���ڴ˴�����
	int eHour,eMinute;//����ʱ��
	//int eyear,emonth,eday;
	string cTime;//����ʱ��
 	string vechile;//�г����
	int flag;//���ǰ������
	element() :money(100000), flag(-1) {}
};
//��Ѱ�����ʱ��ʱ������������ʱ��С�ڿ�ʼʱ����������Ҫ�Խ���ʱ������ڼ�һ,����ļ�������ȫ���Բ�Ҫ����ṹ
struct element2
{
	double money;//��Ʊ
	int bHour, bMinute;//����ʱ��
	int eHour, eMinute;//����ʱ��
	string cTime;//����ʱ��
	string vechile;//�г����
	int flag;//���ǰ������
	int sig;//��Ϊ��ǣ�����ж����������ͬ��Ʊ�ۣ���Ըó��н��б��
	element2() :money(100000), flag(-1),sig(0){}
};
//������������Ĵ洢�ṹ
struct element3
{
	int flag;//��־λ
	int sig;//�洢���б��
	element3():flag(-1),sig(-1){}
};
//�����ڽ�����ṹ
struct chainNode
{
	//��Ա����
	element* cost;//������룬ʱ�䣬��Ǯ�����ĵĶ�̬����,����ÿ���������վ�ķɻ��������
	string city;//����
	chainNode* next;
//	int num;
	int muse;//δ�ÿռ�
	int used;//���ÿռ�
	//����
	chainNode(){}
	chainNode(element*& cost, const string& city,int theMuse,int theUsed)
	{
		muse = theMuse; used = theUsed;
		cost = new element[muse];
		this->cost = cost;
		this->city = city;
		this->muse = muse;
		this->used = used;
	}
	chainNode(element*& cost, const string& city,int theMuse,int theUsed, chainNode* next)
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
//�����ڽ�����
class linkChain
{
public:
	linkChain(int theCapacity=800);
	linkChain(const linkChain& theLinkChain);
	~linkChain();

	void changeArray1();//�ı����鳤��
	bool empty();//�ж��Ƿ�Ϊ��
	int getSize();//��������
	//����֮��������Ψһ��Ӧ�ĺ�����ܲ�����
	bool checkEdge(string city1, string city2);//����֮��ı��Ƿ���ڣ��������������
	bool searchCity(string theCity);//�жϳ����Ƿ����
	bool checkTransport(string city1, string city2, string theVechile, int theBHour,int theBMinute);//���ð����ĳһʱ���Ƿ����
	void searchRoute(string city1, string city2);//Ѱ��������֮���ֱ��·�߲������
	void eraseEdge(string city1,string city2);//ɾ������֮��ı�
	void eraseTransport(string city1, string city2, int theBHour, int theBMinute,string theVechile);//ɾ��ĳһ���г���ɻ�
	void insertEdge(string city1,string city2, int theBHour, int theBMinute, int theEHour, int theEMinute, 
		string theCtime, double theMoney, string theVechile);//���ӳ���
	void Dijkstra(string city1, string city2,int select);//��㣬�յ�
	bool full();//�ж����Ѿ����Ƿ��޷���������
	void searchPath(string city1,string city2,int select);
	bool Bfull();//�жϴ洢BFS�������Ƿ�Ϊ��
	string BFS(string city1,string city2);
	void searchStore(string city1, string city2);
protected:
	alist* cityArray;
	int size;//��������
	int capacity;//����
	int e;//���б���
	consume *costCity;//��������
	element2 *pathCity;//�洢����·��
	//int* storeCity;
	element3* storeCity;//�洢������������ĳ��У�
	map<string, int> m1;//�������������֮�佨��ӳ���ϵ
	map<int, string> m2;
 };