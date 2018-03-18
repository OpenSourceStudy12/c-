#include <iostream>
using namespace std;

class Time;

class Date
{
private:
	int y;
	int m;
	int d;
public:
	Date(int y1=2000,int m1=1,int d1=1):y(y1),m(m1),d(d1){}
	
	void display(Time & t1);
	void fun(Time & t1);
};

class Time
{
private:
	int h;
	int m;
	int s;
public:

	friend Date;	              //友元类：将Date类声明为Time类的友元类，Date类里所有的成员函数变成Time类的友元函数
	
	Time(int h1=0,int m1=0,int s1=0):h(h1),m(m1),s(s1){}
	
	int geth(){ return h;}
	int getm(){ return m; }
	int gets(){ return s; }
	
	//friend void Date::display(Time & t1);     //将Date类的成员函数声明为Time类的友元函数
};

void Date::display(Time & t1)
{
	cout << y << "-" << m << "-" << d << endl;
	//cout << t1.geth() << ":" << t1.getm() << ":" << t1.gets() << endl; 
	cout << t1.h << ":" << t1.m << ":" << t1.s << endl;
}

void Date::fun(Time & t1)
{
	cout << t1.h << endl;
}

// 提高效率，但是破坏封装
//单向的 
//不具有传递性


int main()
{
	Time t1(12,45,12);
	Date d1(2016,12,5);
	d1.display(t1);
	
	d1.fun(t1);
}


#if 0

class Test
{
private:
	int x;
	int y;
public:
	Test(int x1=0,int y1=0){ x=x1; y=y1; }
	
	int getx() { return x; }
	int gety() { return y; }
	
	friend void display(Test & t1);       //将顶层函数声明为Test类友元函数，
									//友元函数里可以通过对象访问私有成员
};

void display(Test & t1)
{
	//cout << t1.getx() << endl;
	//cout << t1.gety() << endl;
	
	cout << t1.x << endl;
	cout << t1.y << endl;
}

int main()
{
	Test t1;
	display(t1);
	
	Test t2(2,3);
	display(t2);
	
}
#endif
