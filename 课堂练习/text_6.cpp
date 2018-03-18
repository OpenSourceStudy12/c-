#include<iostream>
using namespace std;

class CTime
{
	private:
		int hour;
		int minute;
		int second;
	public:
		CTime(int hour=0,int minute=0,int second=0);	
		int SetTime(int hour=0,int minute=0,int second=0);
		int getHour()
		{
			return hour;
		}	
		int getMinute()
		{
			return minute;
		}	
		int getSecond()
		{
			return second;
		}
		void ShowTime(bool flag);	

};

CTime::CTime(int hour,int minute,int second)
{
	if(hour >= 0 && hour< 24 && minute >= 0 && minute < 60 
			&& second >= 0 && second < 60)
	{
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}
	else
	{
		this->hour = 0;
		this->minute = 0;
		this->second = 0;
	}
}

int CTime::SetTime(int hour,int minute,int second)
{
	if(hour >= 0 && hour< 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60)
	{
		this->hour = hour;
		this->minute = minute;
		this->second = second;
		return 1;
	}
	return 0;
}

void CTime::ShowTime(bool flag)
{
	if(flag)
	{
		cout<<hour<<":"<<minute<<":"<<second<<endl;
	}
	else
	{
		if(hour<=12)
		{
			cout<<"AM:"<<hour<<":"<<minute<<":"<<second<<endl;
		}
		else
		{
			cout<<"PM:"<<hour-12<<":"<<minute<<":"<<second<<endl;
		
		}
	}
};

class CDate
{
	private:
		int year;
		int month;
		int day;
	public:
		CDate(int year=2000,int month=1,int second=1);
		int SetDate(int year=2000,int month=1,int day=1);
		int getYear()
		{
			return year;
		}
		int getMonth()
		{
			return month;
		}
		int getDay()
		{
			return day;
		}
		void ShowDate(bool);
};

bool date_check(int year,int month,int day)
{
	if(month <= 0 || month >= 12)
		return false;
	switch(month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(day > 31)
				return false;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(day > 30)
				return false;
			break;
		case 2:
			if(year%4==0 && year%100!=0 || year%400==0)
				if(day > 29)
					return false;
			else
				if(day > 28)
					return false;
			break;
	}
	return true;
}


CDate::CDate(int year,int month,int day)
{
	if(date_check(year,month,day))
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}
	else
	{
		this->year = 2000;
		this->month = 1;
		this->day = 1;
	}
}

int CDate::SetDate(int year,int month,int day)
{
	if(date_check(year,month,day))
	{
		this->year = year;
		this->month = month;
		this->day = day;
		return 1;
	}
	return 0;
}

void CDate::ShowDate(bool flag)
{
	if(flag)
	{
		cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
	}
	else
	{
		cout<<year<<'/'<<month<<'/'<<day<<endl;
	}
}

class CDateTime
{
	private:
		CTime time;
		CDate date;
	public:
		CDateTime(int h=0,int m=0,int s=0,int y=2000,int mm=1,int d=1):time(h,m,s),date(y,mm,d){}
		int SetDateTime(int h=0,int m=0,int s=0,int y=2000,int mm=1,int d=1);
		void ShowDateTime(bool,bool);
		int getYear()
		{
			return date.getYear();
		}
		int getMonth()
		{
			return date.getMonth();
		}
		int getDay()
		{
			return date.getDay();
		}
		int getHour()
		{
			return time.getHour();
		}
		int getMinute()
		{
			return time.getMinute();
		}
		int getSecond()
		{
			return time.getSecond();
		}

};

int CDateTime::SetDateTime(int h,int m,int s,int y,int mm,int d)
{
	bool f_d,f_t;
	f_d = date.SetDate(y,mm,d);
	f_t = time.SetTime(h,m,s);
	if(f_d & f_t)
		return 1;
	else if(!f_d & f_t)
		return -1;
	else
		return -2;
}

void CDateTime::ShowDateTime(bool f_d,bool f_t)
{
	date.ShowDate(f_d);
	time.ShowTime(f_t);
}


int main()
{
	CDateTime d1(23,12,5,2014,5,2);
	d1.ShowDateTime(true,false);
	cout<<endl;

	CDateTime d2;
	d2.ShowDateTime(true,false);
	cout<<endl;

	int iStatus;
	iStatus = d2.SetDateTime(21,55,5,2014,5,3);
	switch(iStatus)
	{
		case 1:
			cout<<"日期和时间设置正确！"<<endl;
			break;
		case -1:
			cout<<"日期数据设置不正确！"<<endl;
			break;
		case -2:
			cout<<"时间数据设置不正确！"<<endl;
			break;
	}
	d2.ShowDateTime(true,false);
	cout<<endl;

	cout<<"月="<<d2.getMonth()<<endl;
	cout<<"分钟="<<d2.getMinute()<<endl;
}




