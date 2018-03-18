#include <iostream>

using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	//构造函数：初始化成员变量
	
	//定义
	//1.函数名：和类名相同
	//2.无返回值
	//3.创建对象的时候自动调用
	
	//在类里，可以有多个构造函数，多个构造函数构成重载
	Point(){ x=0; y=0;  cout << "----------------constructor----------\n"; }
	Point(int x1,int y1) { x=x1; y=y1; cout << "----constructor----\n"; }
	

	void setx(int x1) { x=x1; }
	void sety(int y1) { y=y1; }
	int getx() { return x; }
	int gety() { return y; }
};

int main()
{
	Point p1;
	cout << p1.getx() << endl;
	cout << p1.gety() << endl;
	
	Point p2(2,3);
	cout << p2.getx() << endl;
	cout << p2.gety() << endl;
}
