#include <iostream>
using namespace std;

//析构函数：资源回收
//1,函数名：～类名
//2,没有返回值，也没有void
//3，没有参数
//4,对象被释放的时候自动调用

class Point
{
private:
	int x;
	int y;
public:
	Point(int x1=0,int y1=0)
	{
		x=x1;
		y=y1;
	}
	/*
	Point();
	Point(int x1);
	Point(int x1,int y1);*/
	~Point()
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	void display()
	{
		cout << "x=" << x << ", y=" << y << endl;
	}
};

int main()
{
	Point p1;
	p1.display();
}
