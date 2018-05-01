#include"linkChain.h"
#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>
using std::cin;
using std::cout;
using std::ifstream;
using std::ios;

int main()
{
	linkChain train;//��
	linkChain plane;//�ɻ�
	ifstream infile;
	string file_name;
	string theWay;//���з�ʽ
	int theBHour,theBMinute;//��ʼʱ��2
	int theEHour, theEMinute;//����ʱ��3
	string theCTime;//����ʱ��6
	double theMoney;//��Ʊ0
	string theVechile;//�г����1
	string theCity1;//��ʼ��վ4
	string theCity2;//��ֹ��վ5
	char next;
	char ans='N';
	cout << "��������ļ���:\n";
	cin >> file_name;
	infile.open(file_name.c_str(), ios::in);

	if (infile.fail())
	{
		cout << "Input file opening failed.\n";
		system("pause");
		exit(1);
	}
	//�ļ�����
	while (!infile.eof())
	{
		infile >> theVechile >> theBHour>>next>>theBMinute
			>> theEHour>>next>>theEMinute
			>> theCity1 >> theCity2 >> theCTime >>next>>next>>theMoney;
		train.insertEdge(theCity1, theCity2, theBHour,theBMinute, theEHour,theEMinute, theCTime, theMoney, theVechile);
	}
	infile.close();
	//////////////////
	cout << "������ɻ��ļ���:\n";
	cin >> file_name;
	infile.open(file_name.c_str(), ios::in);

	if (infile.fail())
	{
		cout << "Input file opening failed.\n";
		system("pause");
		exit(1);
	}
	//�ļ�����
	while (!infile.eof())
	{
		infile >> theVechile >> theBHour >> next >> theBMinute
			>> theEHour >> next >> theEMinute
			>> theCity1 >> theCity2 >> theCTime >> next >> next >> theMoney;
		plane.insertEdge(theCity1, theCity2, theBHour, theBMinute, theEHour, theEMinute, theCTime, theMoney, theVechile);
	}
	infile.close();
	//�ֶ�����
	cout << "\n���ֶ�����𳵵����ݣ�y/n��";
	cin >> ans;
	while (ans == 'y' || ans == 'Y')
	{
		if (ans == 'y' || ans == 'Y')
		{
			cout << "�������У�";
			cin >> theCity1;
			cout << "\n��ֹ���У�";
			cin >> theCity2;
			cout << "\n����ʱ��\n";
			cout << "ʱ��"; cin >> theBHour;
			cout << " �֣�"; cin >> theBMinute;
			cout << "\n����ʱ��\n";
			cout << "ʱ��"; cin >> theEHour;
			cout << " �֣�"; cin >> theEMinute;
			cout << "\n��ʱ��";
			cin >> theCTime;
			cout << "\n���ѣ�";
			cin >> theMoney;
			cout << "\n�г��ţ�";
			cin >> theVechile;
			train.insertEdge(theCity1, theCity2, theBHour, theBMinute, theEHour, theEMinute, theCTime, theMoney, theVechile);
		}
			cout << "\n��������ֶ����������(y/n)";
			cin >> ans;
	} 
	//////////////////////////////////////////////
	cout << "\n���ֶ�����ɻ������ݣ�y/n��";
	cin >> ans;
	while (ans == 'y' || ans == 'Y')
	{
		if (ans == 'y' || ans == 'Y')
		{
			cout << "�������У�";
			cin >> theCity1;
			cout << "\n��ֹ���У�";
			cin >> theCity2;
			cout << "\n����ʱ��\n";
			cout << "ʱ��"; cin >> theBHour;
			cout << " �֣�"; cin >> theBMinute;
			cout << "\n����ʱ��\n";
			cout << "ʱ��"; cin >> theEHour;
			cout << " �֣�"; cin >> theEMinute;
			cout << "\n��ʱ��";
			cin >> theCTime;
			cout << "\n���ѣ�";
			cin >> theMoney;
			cout << "\n�г��ţ�";
			cin >> theVechile;
			plane.insertEdge(theCity1, theCity2, theBHour, theBMinute, theEHour, theEMinute, theCTime, theMoney, theVechile);
		}
		cout << "\n��������ֶ����������(y/n)";
		cin >> ans;
	}
	//ɾ������
	cout << "\n����ɾ��������(y/n)";
	cin >> ans;
	while (ans == 'y' || ans == 'Y')
	{
		cout << "\n��������ɾ���Ľ�ͨ��ʽ(��/�ɻ�)��";
		cin >> theWay;
		cout << "\n������Ҫɾ���ĳ���\n";
		cout << "������㣺 ";
		cin >> theCity1;
		cout << "\n" << "�����յ㣺";
		cin >> theCity2;
		if (theWay == "��")
			train.eraseEdge(theCity1, theCity2);
		else if (theWay == "�ɻ�")
			plane.eraseEdge(theCity1, theCity2);
		else
		{
			cout << "�����ڸý�ͨ��ʽ";
			continue;
		}
		cout << "\n�������ɾ��������(y/n)";
		cin >> ans;
	}
	//��·�������������Ż�����
	do {
		cout << "��������㣺 ";
		cin >> theCity1;
		cout << "\n" << "�������յ㣺";
		cin >> theCity2;
		cout << "\n���������ĳ��з�ʽ(��/�ɻ�):";
		cin >> theWay;
		cout << "\n������ֱ��·����\n";
		if (theWay == "��")
			train.searchRoute(theCity1, theCity2);
		else if (theWay == "�ɻ�")
			plane.searchRoute(theCity1, theCity2);
		
		cout << "\n�����ѡ�����·�����·�߽��й滮��\n";
		cout << "����һ������������1������ʡǮ����\n";
		cout << "������������������2������ʡʱ����\n";
		cout << "������������������3������ת��������С��\n";
		cout << "   ������������ȡ������ѡ��\n";
		int a;
		Time t0;
		cout << "\n����������ѡ��ķ�����1/2/3/��������";
		cin >> a;
		if (a == 1 || a == 2)
		{
			if (theWay == "��")
			{
				if (train.checkEdge(theCity1, theCity2))
				{
					train.Dijkstra(theCity1, theCity2, a);
					train.searchPath(theCity1, theCity2, a);
				}
				else
					cout << "\n�����ڵ���ó��е��г���\n";
			}
			else if (theWay == "�ɻ�")
			{
				if (plane.checkEdge(theCity1, theCity2))
				{
					plane.Dijkstra(theCity1, theCity2, a);
					plane.searchPath(theCity1, theCity2, a);
				}
				else
					cout << "\n�����ڵ���ó��еĺ��ࡣ\n";
			}
			else
				cout << "\n������֧�ָý�ͨ��ʽ\n";
		}
		else if (a == 3)
		{
			if (theWay == "��")
			{
				if (train.checkEdge(theCity1, theCity2))
				{
					train.searchStore(theCity1, theCity2);
				//train.searchStore(theCity1, theCity2);
				}
				else
					cout << "\n�����ڵ���ó��е��г���\n";
			}
			else if (theWay == "�ɻ�")
			{
				if (plane.checkEdge(theCity1, theCity2))
				{
					plane.searchStore(theCity1, theCity2);
				}
				else
					cout << "\n�����ڵ���ó��еĺ��ࡣ\n";
			}
			else
				cout << "\n������֧�ָý�ͨ��ʽ\n";
		}
		else
		{
			cout << "ллʹ�ã�\n";
		}
		cout << "\n�������������y/n��?";
		cin>>ans;
	} while (ans=='y'||ans=='Y');
	system("pause");
	return 0;
}
