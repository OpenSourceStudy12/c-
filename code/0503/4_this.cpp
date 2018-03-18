#include <iostream>
using namespace std;

//this: 每一个成员函数里都有this

class Point
{
private:
	int x;
	int y;
public:
	Point(){ x=0; y=0; }
	Point(int x,int y)
	{
		cout << this << endl;
		this->x=x;
		this->y=y;
	}
	void setX(int x)
	{
		cout << this << endl;
		this->x=x;
	}
	void display()
	{
		cout << "x=" << x << ", y=" << y << endl;
	}	
};

int main()
{
	Point p1(1,2);
	cout << &p1 << endl;
	p1.display();
	
	p1.setX(9);
	p1.display();
	
	Point p2(3,4);
	cout << &p2 << endl;
	
}
