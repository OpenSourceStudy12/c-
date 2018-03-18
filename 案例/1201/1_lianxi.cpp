#include <iostream>

#define PI 3.141

using namespace std;

class Circle
{
private:
	float x;
	float y;
	float r;
public:
	Circle(float x1=0,float y1=0,float r1=0):x(x1),y(y1),r(r1){}
	
	float area(){ return PI*r*r; }
	float peri(){ return 2*PI*r; }
	
	void setXandY(float x1,float y1) { x=x1; y=y1;}
	void setR(float r1){ r=r1; }
};

class Column
{
private:
	Circle c1;
	float h;
public:
	Column(float x1=0,float y1=0,float r1=0,float h1=0):c1(x1,y1,r1),h(h1){}
	
	void setPoint(float x1,float y1){ c1.setXandY(x1,y1); }
	void setr1(float r1){ c1.setR(r1); }
	void setH(float h1) { h=h1; }
	float cperi(){ return c1.peri(); }
	float harea(){ return cperi()*h; }
	float vol(){ return c1.area()*h; }
};

int main()
{
	Column c1(2,5,1,1);
	cout << c1.harea() << endl;
	cout << c1.vol() << endl;
}
