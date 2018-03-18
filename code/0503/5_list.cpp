#include <iostream>
using namespace std;

//初始化列表

class Point
{
private:
	int x;
	int y;
public:
	Point():x(0),y(0){}      //Point(){ x=0; y=0; }
	Point(int x1,int y1):x(x1),y(y1){}
	~Point(){}
	void display() {cout << x << "  " << y << endl; }
};

int main()
{
	Point p1(1,4);
	p1.display();
}
