#include"mytime.h"
#include<cstdlib>
#include<iostream>
using std::exit;
using std::cout;
using std::cin;
//计算某一天在一年中的第几天的类外函数
namespace
{
	int daysAccount(Time& t)
	{
		int year = t.year;
		int month = t.month;
		int day = t.day;
		int days = 0;
		int mmonth = month - 1;
		if (month > 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
			days++;
		days = days + day;
		while(month > 0)
		{
			switch (mmonth)
			{
			    case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					days += 31; break;
				case 4:
				case 6:
				case 9:
				case 11:
					days += 30; break;
				case 2:
					days += 28; break;
				default:
					break;
			}
			month--;
			mmonth--;
		}
		return days;
	}
}

Time::Time(int theYear, int theMonth, int theDay, int theHours, int theMinutes):year(theYear)
                                       ,month(theMonth),day(theDay),hours(theHours),minutes(theMinutes){}

bool Time::operator>=(const Time& t)
{
	if (year > t.year)
	{
		return true;
	}
	else if (year == t.year)
	{
		if (month>t.month)
		{
			return true;
		}
		else if (month == t.month)
		{
			if (day > t.day)
			{
				return true;
			}
			else if (day == t.day)
			{
				if (hours > t.hours)
				{
					return true;
				}
				else if (hours == t.hours)
				{
					if (minutes > t.minutes)
					{
						return true;
					}
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
	{
		return false;
	}
}
//对两个时间相减，返回分钟
int sub(Time& t1, Time& t2)
{
	if (t1 >= t2)
	{
		int tempDay1 = daysAccount(t1);
		int tempDay2 = daysAccount(t2);
		int subDay = tempDay1 - tempDay2;
		int subHours = t1.hours - t2.hours;
		int subMinutes = t1.minutes - t2.minutes;
		int costTime = 60 * (24 * subDay + subHours) + subMinutes;
		return costTime;
	}
	else
	{
		cout << "the date of left must be >= the right one";
		system("pause");
		return 0;
	}
}

void Time::inputDate()
{
	cout << "please enter the date of depature.\n";
	cout << "Year:";
		cin >> year; cout << "\n";
	cout << "Month:";
	cin >> month; cout << "\n";
	cout << "Day:";
	cin >> day; cout << "\n";
	cout << "hour:";
	cin >> hours; cout << "\n";
	cout << "minute:";
		cin >> minutes;
}

istream& operator>>(istream& in, Time& t)
{
	int s = 0;
	char a='N';
	{
		//in >> t.year;
		//in >> t.month;
		//in >> t.day;
		cout << "时：\n";
		in >> t.hours;
		cout << "  分：\n";
		in >> t.minutes; 
		if (t.year <0)
		{
			cout << "The year must be >0\n" ;
			s = 1;
		}
		if (t.month > 12 || t.month < 0)
		{
			cout << "The month must be >0 and <=12\n";
			s = 1;
		}
		if (t.hours < 0 || t.hours>23)
		{
			cout << "小时出错\n";
			s = 1;

		}
		if (t.minutes < 0 || t.minutes>60)
		{
			cout << "分钟有误\n";
			s = 1;
		}
		if (s == 1)
		{
			cout << "Do you want to change?(y/n)";
			cin >> a;
		}
	}while (a == 'y'||a=='Y');
	return in;
}

ostream& operator << (ostream& out, Time& t)
{
	out << t.year << "年" << t.month << "月" << t.day << "日 ";
		out << t.hours << ":" << t.minutes;
	return out;
}
