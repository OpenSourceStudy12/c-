#include <iostream>
using namespace std;

class Circle
{
private:
	int x;
	int y;
	int r;
public:
	Circle():x(0),y(0),r(0){}      //参数初始化列表
	Circle(int a,int b,int c):x(a),y(b),r(c){}
	
	//Circle(){ x=0; y=0 ;r=0; }
	//Circle(int a,int b,int c){ x=a; y=b; r=c;}
	~Circle(){}
	
	void display(){ cout << "x=" << x << "  y=" << y << "  r=" << r << endl;}
};

int main()
{
	Circle c1;
	c1.display();
	
	Circle c2(6,3,9);
	c2.display();
}
