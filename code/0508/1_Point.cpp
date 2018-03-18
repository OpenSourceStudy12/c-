#include <iostream>
using namespace std;

class Point 
{
private:
	int x;
	int y;
public:
	Point():x(0),y(0){}
	Point(int x1,int y1):x(x1),y(y1){}
	Point(Point & p1)
	{
		x=p1.x;
		y=p1.y;
	}
	~Point(){}
	
	void display()
	{
		cout << "(" << x << "," << y << ")" ;
	}
	
	void offset(int x1,int y1);
	void offset(Point & p1);
	bool operator == (const Point &); // 判定两个对象是否相同 
	bool operator != (const Point &); // 判定两个对象是否不相同 
	void operator += (const Point &); //相加并将结果放在左操作数中
	void operator -= (const Point &); //相减并将结果放在左操作数中
	
	friend istream & operator>>(istream & in, Point & p1);
	friend ostream & operator<<(ostream & out, Point & p1);
};

void Point::offset(int x1,int y1)
{
	x=x+x1;
	y=y+y1;
}
void Point::offset(Point & p1)
{
	x=x+p1.x;
	y=y+p1.y;
}
bool Point::operator == (const Point & p1)
{
	if((x==p1.x)&&(y==p1.y))
		return true;
	return false;
}
bool Point::operator != (const Point & p1)
{
	if((x==p1.x)&&(y==p1.y))
		return false;
	return true;
}

void Point::operator += (const Point & p1)
{
	x=x+p1.x;
	y=y+p1.y;
}

void Point::operator -= (const Point & p1)
{
	x=x-p1.x;
	y=y-p1.y;
}

istream & operator>>(istream & in, Point & p1)
{
	cout << "x : ";
	in >> p1.x;
	cout << "y : ";
	in >> p1.y;
	return in;
}
ostream & operator<<(ostream & out, Point & p1)
{
	out << "(" << p1.x << "," << p1.y << ")";
	return out;
}

int main()
{
	Point p1(2,3);
	p1.display();
	cout << endl;
	
	Point p2(5,6);
	p2.display();
	cout << endl;
	
	if(p1==p2)
		cout << "p1==p2\n";
	if(p1!=p2)
		cout << "p1!=p2\n";
		
	p1+=p2;     //p1.operator(p2);    p1=p1+p2;
	p1.display();
	cout << endl;
	
	cin >> p1;
	cout << p1 << endl;
}







