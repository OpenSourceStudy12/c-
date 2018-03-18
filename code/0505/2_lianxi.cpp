#include <iostream>
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int y=2000,int m=1,int d=1):year(y),month(m),day(d){}
	~Date(){}
	void display()
	{
		cout << year << "-" << month << "-" << day;
	}
	
	int getYear(){ return year; }
	int getMonth(){ return month; }
	int getDay(){ return day; }
	void set(int y,int m,int d)
	{
		year=y;
		month=m;
		day=d;
	}
};

class CAount
{
private:
	double money;
	Date date;
	static float rate;
public:
	CAount(double m=0,int y=2000,int mo=1,int d=1):money(m),date(y,mo,d){}
	~CAount(){}
	
	static void setRate(float r)
	{
		rate=r;
	}
	static float getRate()
	{
		return rate;
	}
	
	void saveMoney(double m,int y,int mo,int d)
	{
		saveRate(y,mo,d);
		money=money+m;
	}
	
	void lendMoney(double m,int y,int mo,int d)
	{
		float tmp=calRate(y,mo,d);
		if(m<=(money+tmp))
		{
			money=money+tmp;
			money=money-m;
			date.set(y,mo,d);
		}
		else
			cout << "余额不足\n";
			
	}
	float calRate(int y,int m,int d)
	{
		int days=(y-date.getYear())*360+(m-date.getMonth())*30+(d-date.getDay())+1;
		return money*rate/360*days;
	}
	void saveRate(int y,int m,int d)
	{
		float tmp=calRate(y,m,d);
		money=money+tmp;
		date.set(y,m,d);
	}
	
	void display()
	{
		cout << money << "  ";
		date.display();
		cout << endl << endl;
	}	
};

float CAount::rate=0.036;

int main()
{
	CAount c1(100000,2014,1,1);
	c1.saveRate(2014,3,10);
	c1.display();
	
	c1.lendMoney(200000,2014,3,30);
	c1.lendMoney(50000,2014,4,4);
	c1.display();
}
