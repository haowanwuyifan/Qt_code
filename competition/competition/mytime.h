#pragma once
//定义的time类，由于各路线在运行时有时间区别，方便处理时间的先后顺序，以及时间差
#include<iostream>
using std::istream;
using std::ostream;
class Time
{
public:
	int year;
	int month;
	int day;
	int hours;
	int minutes;
	Time(int theyear = 2018, int themonth = 1, int theday = 1, int thehours = 0, int theminutes = 0);
	friend istream& operator >> (istream& in, Time& t);//文件输入
	friend ostream& operator << (ostream& out, Time& t);
	bool operator>=(const Time& t2);//重载运算符，判断两时间之间的大小关系
	void inputDate();//手动输入;
					 //Time operator+(const Time& t);
	friend int sub(Time& t1, Time& t2);//求时间差
};