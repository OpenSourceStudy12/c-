#include <iostream>
using namespace std;

//虚基类
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

class B : virtual public A     //虚继承
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
		//A::display();
		cout << "y=" << y << endl;
	}
};

class C : virtual public A     //虚继承
{
protected:
	int z;
public:
	C(int x1=0,int z1=0):A(x1),z(z1)
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	~C()
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	void display()
	{
		//A::display();
		cout << "z=" << z << endl;
	}
};

class D : public B, public C //多继承
{
private:
	int num;
public:
	D(int x1=0,int y1=0,int z1=0,int n1=0):A(x1),B(x1,y1),C(x1,z1)
	{
		num=n1;
		cout << __func__ << "  " << __LINE__ << endl;
	}
	~D()
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	void display()
	{
		A::display();
		B::display();
		C::display();
		cout << "num=" << num << endl;
	}
};

int main()
{
	D d1;
	d1.display();
	
	D d2(5,1,8,7);
	d2.display();
}







