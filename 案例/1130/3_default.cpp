#include <iostream>

using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	//Point(){}
	//Point(){ x=0; y=0;  cout << "----------------constructor----------\n"; }
	
	//默认的构造函数：如果定义类的时候，没有任何构造函数，系统会自动生成一个默认构造函数
	
	//在类里定义了一个任何构造函数，系统都不会生成默认的构造函数
	//Point() { x=0; y=0; }
	//Point(int x1,int y1) { x=x1; y=y1; cout << "----constructor----\n"; }
	
	//带默认值的构造函数
	Point(int x1=0,int y1=0) { x=x1; y=y1; cout << "----constructor----\n"; }
	
	//定义构造函数的时候，1 选择带默认值的构造函数， 2,构造函数重载
	//Point(){ x=0; y=0; }
	//Point(int x1) { x=x1; y=0; }
	//Point(int x1,int y1){ x=x1; y=y1; }

	void setx(int x1) { x=x1; }
	void sety(int y1) { y=y1; }
	int getx() { return x; }
	int gety() { return y; }
};

int main()
{
	Point p1(1,2);
	cout << p1.getx() << endl;
	cout << p1.gety() << endl;
	
	Point p2;
	cout << p2.getx() << endl;
	cout << p2.gety() << endl;
	
	Point p3(10);
	cout << p3.getx() << endl;
	cout << p3.gety() << endl;
}
