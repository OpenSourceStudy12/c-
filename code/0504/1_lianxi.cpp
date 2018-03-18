#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time(int h=0,int m=0,int s=0);
	~Time();
	int setTime(int h=0,int m=0,int s=0);
	int getHour();
	int getMinute();
	int getSecond();
	void display(bool flag);
};

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int y=2000,int m=1,int d=1);
	~Date();
	int setDate(int y=2000,int m=1,int d=1);
	int getYear();
	int getMonth();
	int getDay();
	void display(bool flag);
};

class DateTime
{
private:
	Time time;
	Date date;
public:
	DateTime(int h=0,int m=0,int s=0,int y=2000,int mo=1,int d=1);
	~DateTime();
	
	int setDateTime(int h=0,int m=0,int s=0,int y=2000,int mo=1,int d=1);
	void display(bool flag1,bool flag2);
};

Time::Time(int h,int m,int s)
{
	if(h>=0&&h<24)
	{
		if(m>=0&&m<60)
		{
			if(s>=0&&s<60)
			{
				hour=h;
				minute=m;
				second=s;
				return;
			}
		}
	}
	
	hour=0;
	minute=0;
	second=0;	
}

Time::~Time(){}

int Time::setTime(int h,int m,int s)
{
	bool b1=(h>=0&&h<24);
	bool b2=(m>=0&&m<60);
	bool b3=(s>=0&&s<60);
	if(b1&&b2&&b3)
	{
		hour=h;
		minute=m;
		second=s;
		return 1;
	}
	else
		return 0;
}

int Time::getHour(){ return hour; }
int Time::getMinute(){ return minute; }
int Time::getSecond(){ return second; }

void Time::display(bool flag)
{
	if(flag)
	{
		cout << hour << ":" << minute << ":" << second << endl;
	}
	else
	{
		if(hour<=12)
		{
			cout << "AM  " << hour << ":";
		}
		else
		{
			cout << "PM  " << hour-12 << ":";
		}
		cout << minute << ":" << second << endl;
	}
}


Date::Date(int y,int m,int d)
{
	if((m>=1&&m<=12)&&(d>=1&&d<=30))
	{
		year=y;
		month=m;
		day=d;
	}
	else
	{
		year=2000;
		month=1;
		day=1;
	}
}

Date::~Date(){}

int Date::setDate(int y,int m,int d)
{
	if((m>=1&&m<=12)&&(d>=1&&d<=30))
	{
		year=y;
		month=m;
		day=d;
		return 1;
	}
	else
	{
		return 0;
	}
}
	
int Date::getYear(){ return year; }
int Date::getMonth(){ return month; }
int Date::getDay(){ return day; }

void Date::display(bool flag)
{
	if(flag)
		cout << year << "-" << month << "-" << day << endl;
	else
		cout << month << "/" << day << "/" << year << endl;
}

DateTime::DateTime(int h,int m,int s,int y,int mo,int d):time(h,m,s),date(y,mo,d){}
DateTime::~DateTime(){}
	
int DateTime::setDateTime(int h,int m,int s,int y,int mo,int d)
{
	int tmp1=time.setTime(h,m,s);
	int tmp2=date.setDate(y,mo,d);
	if(tmp1&&tmp2)
		return 1;
	else if((tmp2==0)&&tmp1)
		return -1;
	else if(tmp1==0&&tmp2)
		return -2;
	else
		return -3;
}

void DateTime::display(bool flag1,bool flag2)
{
	date.display(flag1);
	time.display(flag2);
}

int main()
{
	DateTime d1;
	d1.display(true,true);
	
	DateTime d2(17,55,5,2017,5,4);
	d2.display(true,true);
	
	int state=d2.setDateTime(14,90,1,2014,2,2);
	
	switch(state)
	{
		case 1:
			cout<<"日期和时间数据设置正确!"<<endl;
			break; 
		case -1:
			cout<<"日期数据设置不正确!"<<endl;
			break; 
		case -2:
			cout<<"时间数据设置不正确!"<<endl;
			break; 
	}
}











