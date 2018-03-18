#include <iostream>
using namespace std;

#define PI 3.14

class Circle
{
private:
	float x;
	float y;
	float r;
public:
	void setPoint(float x1,float y1)
	{
		x=x1;
		y=y1;
	}
	void setR(float r1)
	{
		r=r1;
	}
	float area()
	{
		return PI*r*r;
	}
	float per()
	{
		return 2*PI*r;
	}
	void display()
	{
		cout << "(" << x << "," << y << ")  " << r << endl;
	}
};

int main()
{
	Circle c1;
	c1.setPoint(3,4);
	c1.setR(10);
	c1.display();
	
	cout << c1.area() << endl;
	cout << c1.per() << endl;
}
