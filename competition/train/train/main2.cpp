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
	linkChain train;//火车
	linkChain plane;//飞机
	ifstream infile;
	string file_name;
	string theWay;//出行方式
	int theBHour,theBMinute;//开始时间2
	int theEHour, theEMinute;//结束时间3
	string theCTime;//消耗时间6
	double theMoney;//车票0
	string theVechile;//列车班次1
	string theCity1;//起始车站4
	string theCity2;//终止车站5
	char next;
	char ans='N';
	cout << "请输入火车文件名:\n";
	cin >> file_name;
	infile.open(file_name.c_str(), ios::in);

	if (infile.fail())
	{
		cout << "Input file opening failed.\n";
		system("pause");
		exit(1);
	}
	//文件输入
	while (!infile.eof())
	{
		infile >> theVechile >> theBHour>>next>>theBMinute
			>> theEHour>>next>>theEMinute
			>> theCity1 >> theCity2 >> theCTime >>next>>next>>theMoney;
		train.insertEdge(theCity1, theCity2, theBHour,theBMinute, theEHour,theEMinute, theCTime, theMoney, theVechile);
	}
	infile.close();
	//////////////////
	cout << "请输入飞机文件名:\n";
	cin >> file_name;
	infile.open(file_name.c_str(), ios::in);

	if (infile.fail())
	{
		cout << "Input file opening failed.\n";
		system("pause");
		exit(1);
	}
	//文件输入
	while (!infile.eof())
	{
		infile >> theVechile >> theBHour >> next >> theBMinute
			>> theEHour >> next >> theEMinute
			>> theCity1 >> theCity2 >> theCTime >> next >> next >> theMoney;
		plane.insertEdge(theCity1, theCity2, theBHour, theBMinute, theEHour, theEMinute, theCTime, theMoney, theVechile);
	}
	infile.close();
	//手动输入
	cout << "\n请手动输入火车的数据（y/n）";
	cin >> ans;
	while (ans == 'y' || ans == 'Y')
	{
		if (ans == 'y' || ans == 'Y')
		{
			cout << "出发城市：";
			cin >> theCity1;
			cout << "\n终止城市：";
			cin >> theCity2;
			cout << "\n出发时间\n";
			cout << "时："; cin >> theBHour;
			cout << " 分："; cin >> theBMinute;
			cout << "\n到达时间\n";
			cout << "时："; cin >> theEHour;
			cout << " 分："; cin >> theEMinute;
			cout << "\n耗时：";
			cin >> theCTime;
			cout << "\n花费：";
			cin >> theMoney;
			cout << "\n列车号：";
			cin >> theVechile;
			train.insertEdge(theCity1, theCity2, theBHour, theBMinute, theEHour, theEMinute, theCTime, theMoney, theVechile);
		}
			cout << "\n您想继续手动添加数据吗？(y/n)";
			cin >> ans;
	} 
	//////////////////////////////////////////////
	cout << "\n请手动输入飞机的数据（y/n）";
	cin >> ans;
	while (ans == 'y' || ans == 'Y')
	{
		if (ans == 'y' || ans == 'Y')
		{
			cout << "出发城市：";
			cin >> theCity1;
			cout << "\n终止城市：";
			cin >> theCity2;
			cout << "\n出发时间\n";
			cout << "时："; cin >> theBHour;
			cout << " 分："; cin >> theBMinute;
			cout << "\n到达时间\n";
			cout << "时："; cin >> theEHour;
			cout << " 分："; cin >> theEMinute;
			cout << "\n耗时：";
			cin >> theCTime;
			cout << "\n花费：";
			cin >> theMoney;
			cout << "\n列车号：";
			cin >> theVechile;
			plane.insertEdge(theCity1, theCity2, theBHour, theBMinute, theEHour, theEMinute, theCTime, theMoney, theVechile);
		}
		cout << "\n您想继续手动添加数据吗？(y/n)";
		cin >> ans;
	}
	//删除城市
	cout << "\n你想删除城市吗？(y/n)";
	cin >> ans;
	while (ans == 'y' || ans == 'Y')
	{
		cout << "\n输入你想删除的交通方式(火车/飞机)：";
		cin >> theWay;
		cout << "\n输入需要删除的城市\n";
		cout << "输入起点： ";
		cin >> theCity1;
		cout << "\n" << "输入终点：";
		cin >> theCity2;
		if (theWay == "火车")
			train.eraseEdge(theCity1, theCity2);
		else if (theWay == "飞机")
			plane.eraseEdge(theCity1, theCity2);
		else
		{
			cout << "不存在该交通方式";
			continue;
		}
		cout << "\n你想继续删除城市吗？(y/n)";
		cin >> ans;
	}
	//对路径进行搜索的优化方案
	do {
		cout << "请输入起点： ";
		cin >> theCity1;
		cout << "\n" << "请输入终点：";
		cin >> theCity2;
		cout << "\n请输入您的出行方式(火车/飞机):";
		cin >> theWay;
		cout << "\n以下是直达路径：\n";
		if (theWay == "火车")
			train.searchRoute(theCity1, theCity2);
		else if (theWay == "飞机")
			plane.searchRoute(theCity1, theCity2);
		
		cout << "\n你可以选择以下方案对路线进行规划：\n";
		cout << "方案一（您可以输入1）：最省钱方案\n";
		cout << "方案二（您可以输入2）：最省时方案\n";
		cout << "方案三（您可以输入3）：中转方案（最小）\n";
		cout << "   输入其他可以取消方案选择\n";
		int a;
		Time t0;
		cout << "\n请输入您想选择的方案（1/2/3/其它）：";
		cin >> a;
		if (a == 1 || a == 2)
		{
			if (theWay == "火车")
			{
				if (train.checkEdge(theCity1, theCity2))
				{
					train.Dijkstra(theCity1, theCity2, a);
					train.searchPath(theCity1, theCity2, a);
				}
				else
					cout << "\n不存在到达该城市的列车。\n";
			}
			else if (theWay == "飞机")
			{
				if (plane.checkEdge(theCity1, theCity2))
				{
					plane.Dijkstra(theCity1, theCity2, a);
					plane.searchPath(theCity1, theCity2, a);
				}
				else
					cout << "\n不存在到达该城市的航班。\n";
			}
			else
				cout << "\n本程序不支持该交通方式\n";
		}
		else if (a == 3)
		{
			if (theWay == "火车")
			{
				if (train.checkEdge(theCity1, theCity2))
				{
					train.searchStore(theCity1, theCity2);
				//train.searchStore(theCity1, theCity2);
				}
				else
					cout << "\n不存在到达该城市的列车。\n";
			}
			else if (theWay == "飞机")
			{
				if (plane.checkEdge(theCity1, theCity2))
				{
					plane.searchStore(theCity1, theCity2);
				}
				else
					cout << "\n不存在到达该城市的航班。\n";
			}
			else
				cout << "\n本程序不支持该交通方式\n";
		}
		else
		{
			cout << "谢谢使用！\n";
		}
		cout << "\n您想继续输入吗（y/n）?";
		cin>>ans;
	} while (ans=='y'||ans=='Y');
	system("pause");
	return 0;
}
