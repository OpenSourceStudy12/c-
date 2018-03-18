#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point(int x1=0,int y1=0):x(x1),y(y1){}
	~Point(){}
	void display()
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}
	
	void offset(int,int); // 提供对点的移动 
	void offset(const Point &); // 提供对点的移动，偏移量用Point类对象表示 
	bool operator == (const Point &); // 判定两个对象是否相同 
	bool operator != (const Point &); // 判定两个对象是否不相同 
	void operator += (const Point &); //相加并将结果放在左操作数中
	void operator -= (const Point &); //相减并将结果放在左操作数中 
	
	Point & operator + (const Point &); //将两个点对象相加, 
	Point & operator-(Point &); //将两个点对象相减
	int getx(){return x;} 
	int gety(){return y;} 
};

void Point::offset(int x1,int y1)
{
	x=x+x1;
	y=y+y1;
}

void Point::offset(const Point &p1)
{
	x=x+p1.x;
	y=y+p1.y;
}

bool Point::operator == (const Point &p1)
{
	if(x==p1.x&&y==p1.y)
		return true;
	return false;
}

bool Point::operator != (const Point &p1)
{
	if(x==p1.x&&y==p1.y)
		return false;
	return true;
}

void Point::operator += (const Point &p1)       //x+=5    x=x+5;
{
	x=x+p1.x;
	y=y+p1.y;
}

void Point::operator -= (const Point &p1)
{
	x=x-p1.x;
	y=y-p1.y;
}

Point & Point::operator + (const Point &p1)
{
	static Point tmp;
	tmp.x=x+p1.x;
	tmp.y=y+p1.y;
	return tmp;
}


int main()
{
	Point p1(2,3);
	Point p2(5,6);
	
	p1+=p2;
	p1.display();
	
	//p1.offset(8,9);
	//p1.display();
	
	//Point tmp=p1+p2;
	//tmp.display();
	
	//if(p1!=p2)
		//cout << "p1!=p2\n";
		
}

