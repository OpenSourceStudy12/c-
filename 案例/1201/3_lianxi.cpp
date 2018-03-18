#include <iostream>

using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time(int h=0,int m=0,int s=0)
	{
		if((h>=0&&h<=23) && (m>=0&&m<60) && (s>=0&&s<60))
		{
			hour=h;
			minute=m;
			second=s;
		}
		else
		{
			hour=0;
			minute=0;
			second=0;
		}
	}
	
	int SetTime(int h=0,int m=0,int s=0)    //如果时间合法,则赋值并返回 1,否则不赋值,并返回 0
	{
		if((h>=0&&h<=23) && (m>=0&&m<60) && (s>=0&&s<60))
		{
			hour=h;
			minute=m;
			second=s;
			return 1;
		}
		return 0;
	}

	int getHour() { return hour; }
	int getMinute() { return minute; }
	int getSecond() { return second; }
	

	//flag 为 True 则以 24 小时制显示时间,否则以 AM PM 的方式显示 //自己考虑是否需要添加其他成员函数};
	void ShowTime(bool flag)
	{
		if(flag)
			cout << hour << ":" << minute << ":" << second << endl;
		else
		{
			if(hour>12)
				cout << "PM: " << hour-12 << ":" << minute << ":" << second << endl;
			else
				cout << "AM: " << hour << ":" << minute << ":" << second << endl;
		}
	}
};

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int y=2000,int m=1,int d=1) //如果日期合法,则赋值,否则赋值 2000 年 1 月 1 日
	{
		if((m>=1&&m<=12) && (d>=1&&d<=30))
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
	
	int SetDate(int y=2000,int m=1,int d=1) //如果日期合法,则赋值并返回 1,否则不赋值,并返回 0
	{
		if((m>=1&&m<=12) && (d>=1&&d<=30))
		{
			year=y;
			month=m;
			day=d;
			return 1;
		}
		return 0;
	}
	int GetYear(){ return year; }
	int GetMonth() { return month; }
	int GetDay(){ return day; }

	//flag 为 TRUE,则以中文的方式显示日期,否则以 MM/DD/YYYY 的方式显示日期
	void ShowDate(bool flag)
	{
		if(flag)
			cout << year << "-" << month << "-" << day << endl;
		else
			cout << month << "/" << day << "/" << year << endl;
	}
//自己考虑是否需要添加其他成员函数
};

class DateTime
{
private:
	Time m_time;
	Date m_date; 
public:
	//添加必要的构造函数
	DateTime(int y=2000,int m=1,int d=1,int h=0,int m1=0,int s=0):m_time(h,m1,s),m_date(y,m,d){}

	//int SetDateTime(...); 自己设计参数,考虑该函数的返回值加以表示全部正确、 日期不对、时间不对等情况
	int SetDateTime(int y=2000,int m=1,int d=1,int h=0,int m1=0,int s=0)
	{
		int f1=m_time.SetTime(h,m1,s);
		int f2=m_date.SetDate(y,m,d);
		if(f1==1&&f2==1)
			return 1;
		else if(f1!=1&&f2==1)
			return -2;
		else if(f1==1&&f2!=1)
			return -1;
	}

	//void ShowDateTime(...); 自己设计参数,考虑可以中文日期和西文日期格式, 以及 24 小时和 AM PM 都可以控制
	void ShowDateTime(bool f1,bool f2)
	{
		m_time.ShowTime(f2);
		m_date.ShowDate(f1);
	}
	
	int GetMonth()
	{
		return m_date.GetMonth();
	}
	
	int GetMinute()
	{
		return m_time.getMinute();
	}
};

int main()
{
	DateTime d1(2014, 5, 2, 12, 12, 5);
	
	d1.ShowDateTime(false, true); //第1个参数表示以英文方式显示日期, 第2个参数表示以24小时制方式显示时间
	DateTime d2;
	d2.ShowDateTime(true, false); //第1个参数表示以中文方式显示日期, 第2个参数表示以AM PM的方式显示时间

#if 1
	int iStatus;
	iStatus=d2.SetDateTime(2014, 5, 2, 3, 55, 5); 
	switch(iStatus)
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
	d2.ShowDateTime(false, false);
#endif

	cout<<"月="<<d2.GetMonth()<<endl; //认真考虑一下如何实现此操作?
	cout<<"分钟="<<d2.GetMinute()<<endl; //认真考虑一下如何实现此操作?
}
