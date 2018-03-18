#include <iostream>
using namespace std;

//c++支持间接继承 /多重继承

class A
{
protected:
	int x;
public:
	A(int x1=0):x(x1)
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	~A()
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	void display()
	{
		cout << "x=" << x << endl;
	}
};

class B :public A
{
protected:
	int y;
public:
	B(int x1=0,int y1=0):A(x1),y(y1)
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	~B()
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	void display()
	{
		A::display();
		cout << "y=" << y << endl;
	}
};

class C : public B
{
private:
	int z;
public:
	C(int x1=0,int y1=0,int z1=0):B(x1,y1),z(z1)
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	~C()
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	void display()
	{
		B::display();
		cout << "z=" << z << endl; 
	}
};

int main()
{
	C c1;
	c1.display();
	
	C c2(5,1,9);
	c2.display();
}
