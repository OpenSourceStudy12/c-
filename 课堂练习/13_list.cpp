/*
参数初始化列表:给成员变量初始化

class Point
{
private:
	int x,y;
public:
	Point():x(0),y(0){}      //Point(){x=0;y=0;}
	Point(int x1,int y1):x(x1),y(y1){}
}

const 修饰的成员变量只能通过参数初始化列表赋值
const 修饰成员函数，常成员函数，不能修改成员变量的值
const 修饰对象，常对象，只能访问常成员函数(不包括构造函数和析构函数)

class Point
{
private:
	int x;
	const int y;
public:
	Point():x(0),y(0){}  // Point():y(0){x=0;}
	Point(int x1,int y1):x(x1),y(y1){}  //Point(int x1,int y1):y(y1){x=x1;}
}
  
 
*/


#include<iostream>
using namespace std;

class Point
{
private:
	int x;
	const int y;
public:
	Point():x(0),y(0){}      //Point(){x=0;y=0;}
	Point(int x1,int y1):x(x1),y(y1){} //只能通过参数初始化列表给y赋值

/*      不能给y初始化赋值
	Point(int x,int y)
	{
		this->x=x;
		this->y=y;
	}
*/
	void display() const
	{
		cout<<"x="<<x<<' '<<"y="<<y<<endl;
	}
	int getX() const       //常成员函数，只能访问成员变量，但不能修改成员变量
	{
		return x;
	}


};

int main()
{
	Point p1(2,6);
	p1.display();

	const Point p2(9,8);
	p2.display();
	cout<<p2.getX()<<endl;
}



