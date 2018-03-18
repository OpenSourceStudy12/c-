#include <iostream>
using namespace std;

/*
继承方式        父类                  子类是否能访问          类外
public       private                       NO		     	 NO
			 protected                    YES 				 NO
			 public                       YES				 YES
			 
private		 private                       NO				 NO				
			 protected                    YES				 NO
			 public		                  YES				 NO
			 
protected	 private		               NO                NO
			 protected                    YES                NO
			 public                       YES                NO
*/


class A
{
private:
	int x;
protected:
	int y;
public:
	int z;
};

class B : private A
{
private:
	int a;
protected:
	int b;
public:
	int c;
	
	void display()
	{
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		cout << "z=" << z << endl << endl;
		
		cout << "a=" << a << ", b=" << b << ", c=" << c << endl;
	}
};

int main()
{
	B b1;
	b1.x=1;
	b1.y=2;
	b1.z=34;
	b1.a=11;
	b1.b=90;
	b1.c=5;
}
