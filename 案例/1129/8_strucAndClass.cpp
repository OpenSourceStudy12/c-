#include <iostream>
using namespace std;

struct s      //成员默认是公有的，在C++里。结构体里可以定义成员变量和成员函数
{
	int num;
	void fun() { cout << num << endl;}
};

class c      //成员默认是私有的
{
public:
	int num;
	void fun() { cout << num << endl; }
};

int main()
{
	s  s1;
	s1.num=100;
	s1.fun();
	
	c c1;
	c1.num=1001;
	c1.fun();
}
