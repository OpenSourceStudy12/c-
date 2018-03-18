#include <iostream>

#define PI 3.14

using namespace std;

class Circle
{
private:
	float x;
	float y;
	float r;
public:
	void setXandY(float x1,float y1);
	void setR(float f1);
	
	float getX(){ return x;}
	float getY(){ return y;}
	float getR() { return r;}
	
	float area();
	float peri();
};

void Circle::setXandY(float x1,float y1)
{
	x=x1;
	y=y1;
}

void Circle::setR(float f1)
{
	r=f1;
}

float Circle::area()
{
	return PI*r*r;
}

float Circle::peri()
{
	return 2*PI*r;
}

void display(Circle & c1)      //通过引用传递对象
{
	cout << "point : (" << c1.getX() << ", " << c1.getY() << ")    r=" << c1.getR() << endl;
}

Circle & init(float x1,float y1,float r1)    //通过引用返回类对象
{
	static Circle c1;
	c1.setXandY(x1,y1);
	c1.setR(r1);
	return c1;
}

int main()
{
	Circle c2=init(1,1,4);
	display(c2);
	
	Circle c1;
	c1.setXandY(2,6);
	c1.setR(1.2);
	display(c1);
	cout << "area : " << c1.area() << endl;
	cout << "peri : " << c1.peri() << endl;
}
