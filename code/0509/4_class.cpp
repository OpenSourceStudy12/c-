#include <iostream>
using namespace std;

class Point 
{
protected:
	int x;
	int y;
public:
	Point()
	{
		x=0;
		y=0;
	}
	Point(int x)
	{
		this->x=x;
		y=0;
	}
	Point(int x1,int y1)
	{
		x=x1;
		y=y1;
	}
	
	virtual void display()
	{
		cout << "x=" << x << ", y=" << y << endl; 
	}
	
	void f1()
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
};

class Circle : public Point
{
private:
	int r;
public:
	Circle(int x=0,int y=0,int r=0):Point(x,y),r(r){}
	
	//重写或者覆盖
	void display()
	{
		cout << "x=" << x << ", y=" << y << ", r=" << r << endl;
	}
	
	void f1()
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
};

int main()
{
	Circle c1(1,2,3);
	c1.f1();
	c1.Point::f1();


#if 0
	Point *p1=new Circle(3,4,2);
	p1->display();
	delete p1;
	
	p1=new Point(1,2);
	p1->display();
	delete p1;
#endif
}




#if 0

void f1()        //f1_void()
{
	cout << __func__ << "  " << __LINE__ << endl;
}
void f1(int num)     //f1_int()
{
	cout << __func__ << "  " << __LINE__ << endl;
}
void f1(string str)      //f1_string()
{
	cout << __func__ << "  " << __LINE__ << endl;
}

int main()
{
	f1();
	f1(123);
	f1("aa");
}

#endif
