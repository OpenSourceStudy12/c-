#include <iostream>
using namespace std;

//结构体：成员包含成员变量和成员函数
//结构体成员默认的是public，类的成员默认的是private
struct Test
{
	int x;
	int y;
	void fun()
	{
		cout << "struct Test : " << __func__ << "  " << __LINE__ << endl;
	}
};

class A
{
public:
	int x;
	void fun()
	{
		cout << "class A : " << __func__ << "  " << __LINE__ << endl;
	}
};

int main()
{
	//struct Test t1;
	Test t1;
	t1.x=123;
	t1.y=23;
	t1.fun();
	Test *p1=&t1;
	p1->fun();
	
	A a1;
	a1.x=111;
	a1.fun();
	A *p2=&a1;
	p2->fun();
	return 0;
}
