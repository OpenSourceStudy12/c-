#include <iostream>
using namespace std;

//友元函数:
//友元类：

class Time;

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int y=2000,int m=1,int d=1):year(y),month(m),day(d){}
	~Date(){}
	
	void display(Time & t1);

};

class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time(int h=0,int m=0,int s=0):hour(h),minute(m),second(s){}
	~Time(){}
	
	int getHour(){ return hour; }
	int getMinute(){ return minute; }
	int getSecond(){ return second; }
	
	//friend void Date::display(Time & t1);
	friend void print_time(Time & t1); 
	
	friend Date;
};

void Date::display(Time & t1)
{
	cout << year << "-" << month << "-" << day << "  ";
	cout << t1.hour << ":" << t1.minute << ":" << t1.second << endl;
	//cout << t1.getHour() << ":" << t1.getMinute() << ":" << t1.getSecond() << endl;
}


void print_time(Time & t1)
{
	cout << t1.hour << ":" << t1.minute << ":" << t1.second << endl;
	//cout << t1.getHour() << ":" << t1.getMinute() << ":" << t1.getSecond() << endl;
}

int main()
{
	Time t1(16,48,0);
	print_time(t1);
	
	Date d1(2017,5,4);
	d1.display(t1);
}
