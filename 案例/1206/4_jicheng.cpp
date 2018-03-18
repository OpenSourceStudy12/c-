#include <iostream>
using namespace std;

#if 0
继承方式     父类成员              子类                类外
public          public                    YES                  YES
		     private                   NO                  NO
		     protected               YES                  NO
private	     public                    YES                  NO
		     private                   NO                  NO
		     protected               YES                  NO
protected

#endif
class Parent
{
private:
	int x;
protected:
	int y;
public:
	int z;
};

class Child : private  Parent
{
public:
	void display()
	{
		cout << "x : " << x << endl;
		cout << "y : " << y << endl;
		cout << "z : " << z << endl;
	}
};

int main()
{
	Child c1;
	cout << "x : " << c1.x << endl;
	cout << "y : " << c1.y << endl;
	cout << "z : " << c1.z << endl;
}

