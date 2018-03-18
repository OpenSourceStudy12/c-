#include <iostream>
using namespace std;

//const : 修饰成员变量，只能通过初始化列表初始化
//const修饰成员函数，常成员函数，不能修改成员变量的值
//const修饰对象，常对象，只能访问常成员函数

class Point
{
private:
	int x;
	const int y;
public:
	Point():x(0),y(0){}                //Point():y(0){ x=0; }
	Point(int x1,int y1):x(x1),y(y1){}
	~Point(){}
	void display() const
	{
		cout << x << "  " << y << endl;
	}
	
	void setX(int x)
	{
		this->x=x;
	}
	int getX() const
	{
		return x;
	}
};

int main()
{
	Point p1(4,5);
	p1.display();
	
	p1.setX(7);
	cout << "x=" << p1.getX() << endl;
	
	const Point p2(7,5);
	p2.display();
}
