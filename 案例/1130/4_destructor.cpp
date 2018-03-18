#include <iostream>

using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	//带默认值的构造函数
	Point(int x1=0,int y1=0) { x=x1; y=y1;   cout << "(" << x << ", " << y << ")\t" ; cout << "----constructor----\n"; }
	
	//析构函数：资源回收
	
	//定义
	//函数名： ～类名（）
	//没有参数,没有返回值
	//对象释放的时候自动调用
	//析构函数不能重载
	~Point(){   cout << "(" << x << ", " << y << ")\t" ;   cout << "----destructor--------\n"; }
	
	
	//构造函数和析构函数的调用顺序相反，
	

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
