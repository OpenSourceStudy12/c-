#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
	float x;
	float y;
public:
	Point(float x1=0,float y1=0):x(x1),y(y1){}
	
	void display()
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}
	
	float getx(){ return x; }
	float gety(){ return y; }
};

class Line
{
private:
	Point p1;
	Point p2;
public:
	Line(float a=0,float b=0,float c=0,float d=0):p1(a,b),p2(c,d){}
	float distance()
	{ 
		float f1=pow(p1.getx()-p2.getx(),2);
		float f2=pow(p1.gety()-p2.gety(),2);
		return sqrt(f1+f2);
	}
	
	void showLine()
	{
		p1.display();
		p2.display();
	}
};

int main()
{
	Line n1;
	n1.showLine();
	cout << n1.distance() << endl;
	
	Line n2(1,1,5,5);
	n2.showLine();
	cout << n2.distance() << endl;
}


