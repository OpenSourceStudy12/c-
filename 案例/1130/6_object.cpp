#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point():x(0),y(0){ cout << "-------Point()--------\n"; }
	Point(int a,int b):x(a),y(b){ cout << "-------Point(int a,int b)--------\n"; }
	
	void display(){ cout << "(" << x << "," << y << ")" << endl; }
};

class Circle
{
private:
	Point p1;
	int r;
public:
	Circle(){ cout << "-------Circle()---------\n"; r=0; }
	Circle(int x1,int y1,int r1):p1(x1,y1),r(r1){ cout << "-----Circle(int, int, int)----\n"; }
	//Circle(Point p,int r1){ cout << "-------Circle(Point p,int r1)---------\n"; p1=p; r=r1; }
	
	void display(){ p1.display(); cout << "r=" << r << endl; }
};

int main()
{
	Circle c1(2,2,6);
	c1.display();


#if 0
	Point p1(1,2);
	p1.display();
	
	/*Circle c1;
	c1.display();*/
	
	Circle c2(p1,3);
	c2.display();
#endif
}
