#include <iostream>
using namespace std;

//默认的构造函数：在定义类的时候没有定义任何一个构造函数，系统会生成默认的构造函数
//在定义类的时候定义类任何一个构造函数，系统都不会生成默认的构造函数

class Point
{
private:
	int x;
	int y;
public:
	//Point(){}      //默认的构造函数
	Point(int x1,int y1)
	{
		x=x1;
		y=y1;
	}
	Point()
	{
		x=0;
		y=0;
	}
	void display()
	{
		cout << "x=" << x << ", y=" << y << endl;
	}
};

int main()
{
	Point p1(1,2);
	p1.display();
	
	Point p2;
	p2.display();
}
