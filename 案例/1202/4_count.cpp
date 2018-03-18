#if 0

[静态成员]现需要处理银行活期存款业务,设账户类为,CAount,请 根据如下需求实现该类,并在 main 函数中测试。
 每个账户需要有一个浮点型的成员 m_Money 用于存储账上余额;
 每个账户需要描述存款的日期;
 银行的年利息采用浮点型静态数据成员 m_InterestRate 描述,从而避免为每个 账户存储利息;
 为年利息成员提供静态成员 SetInterestRate 进行设置;
 为年利息成员提供静态成员 GetInterestRate 进行获取;
 提供存款成员函数 SaveMoney;
 提供取款成员函数 LendMoney;
 提供计算利息函数 CalcInterest;
 提供结算利息函数 SaveInterest,该函数将计算出的利息结算到本金中。
 为简化计算,请考虑以下定义或限制:
1) 本题目不考虑闰年,每个月都认为 30 天,一年认为 360 天。2) 存款仅考虑发生一次!
3) 取款允许发生多次,但取款是否允许需要考虑“本金是否足够”的条件

#endif

#include <iostream>
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int y=2000,int m=1,int d=1){ year=y; month=m; day=d; }
	
	void set(int y,int m,int d){ year=y; month=m; day=d; }
	int getYear(){ return year; }
	int getMonth(){ return month; }
	int getDay() { return day; }
	
	void display()
	{
		cout << year << "-" << month << "-" << day ;
	}
};

class Aount
{
private:
	float money;
	Date date;
	static float rate;
public:
	Aount(float m=0,int y=2000,int m1=1,int d=1):money(m),date(y,m1,d){}
	
	static void setRate(float r){ rate=r; }
	static float getRate(){ return rate; }
	
	void saveMoney(float m,int y,int m1,int d)
	{
		float r=calcInterest(y,m1,d);
		money=money+r+m;
		date.set(y,m1,d);
	}
	
	void lendMoney(float m,int y,int m1,int d)
	{
		if(m>money)
		{
			cout << "余额不足\n";
			return ;
		}
		
		float r=calcInterest(y,m1,d);
		money=money+r-m;
		date.set(y,m1,d);
	}
	
	float calcInterest(int y,int m,int d)
	{
		int days=360*(y-date.getYear())+30*(m-date.getMonth())+(d-date.getDay())+1;
		//100000*0.036/360*70
		return money*rate/360*days;
	}
	
	void saveInterest(int y,int m,int d)
	{
		float r=calcInterest(y,m,d);
		money=money+r;
		date.set(y,m,d);
	}
	
	void display()
	{
		cout << "余额 : " << money;
		cout << "   " ;
		date.display();
		cout << endl;
	}
};

float Aount::rate=0.036;

int main()
{
	Aount::setRate(0.038);
	Aount c1(100000,2014,1,1);
	//cout << c1.calcInterest(2014,3,10) << endl;
	c1.saveInterest(2014,3,10);
	c1.display();
	
	c1.lendMoney(50000,2014,4,4);
	c1.display();
	
	
}

