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
	~Point(){}
	void display()
	{
		cout << "(" << x << "," << y << ")";
	}
	
	int getX(){ return x; }
	int getY(){ return y; }
};

class Line
{
private:
	Point p1;
	Point p2;
public:
	Line(float x1=0,float y1=0,float x2=0,float y2=0):p1(x1,y1),p2(x2,y2){}
	~Line(){}
	void display()
	{
		cout << "p1 : " ;
		p1.display();
		cout << "   p2 : ";
		p2.display();
		cout << endl;
	}
	float distance()
	{
		float t1=pow(p1.getX()-p2.getX(),2);
		float t2=pow(p1.getY()-p2.getY(),2);
		return sqrt(t1+t2);
	}
};

int main()
{
	Line line1;
	line1.display();
	cout << "length : " << line1.distance() << endl;
	
	Line line2(1,1,5,5);
	line2.display();
	cout << "length : " << line2.distance() << endl;
}
