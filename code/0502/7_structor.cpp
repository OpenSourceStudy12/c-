#include <iostream>
using namespace std;

//构造函数：给成员变量初始化
//构造函数：1,函数名和类名相同，2, 没有返回值，也没有void 3, 定义对象时自动调用

class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	//构造函数
	Time(int h=0,int m=0,int s=0);
#if 0
	Time(int h=0,int m=0,int s=0)
	{
		hour=h;
		minute=m;
		second=s;
		cout << __func__ << "  " << __LINE__ << endl;
	}
#endif
#if 0
	Time(int h,int m,int s)
	{
		hour=h;
		minute=m;
		second=s;
		cout << __func__ << "  " << __LINE__ << endl;
	}
	Time(int m,int s)
	{
		hour=15;
		minute=m;
		second=s;
		cout << __func__ << "  " << __LINE__ << endl;
	}
	Time()
	{
		hour=0;
		minute=0;
		second=0;
		cout << __func__ << "  " << __LINE__ << endl;
	}
#endif
	void display()
	{
		cout << hour << ":" << minute << ":" << second << endl;
	}
};

Time::Time(int h,int m,int s)
{
	hour=h;
	minute=m;
	second=s;
}

int main()
{
	Time t1(15,20,20);
	t1.display();
	
	Time t2(15,48);
	t2.display();
	
	Time t3;
	t3.display();
}
