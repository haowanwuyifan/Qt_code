#pragma once
//�����time�࣬���ڸ�·��������ʱ��ʱ�����𣬷��㴦��ʱ����Ⱥ�˳���Լ�ʱ���
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
	friend istream& operator >> (istream& in, Time& t);//�ļ�����
	friend ostream& operator << (ostream& out, Time& t);
	bool operator>=(const Time& t2);//������������ж���ʱ��֮��Ĵ�С��ϵ
	void inputDate();//�ֶ�����;
					 //Time operator+(const Time& t);
	friend int sub(Time& t1, Time& t2);//��ʱ���
};