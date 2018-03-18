#include <iostream>
using namespace std;

//避免命名冲突
//命名空间的定义
/*
namespace 空间名称
{
	成员 （变量，函数，typedef ......）
}
*/

//使用
//1.空间名::成员名称
//2,using 空间名::成员名称;
//3 using namespace 空间名;

namespace A
{
	int flag;
	void fun() { std::cout << "A::fun()" << std::endl;}
}

namespace B
{
	bool flag;
	void fun(){ std::cout << "B::fun()" << std::endl;}
}

//::  域解析符
int main()
{
	using namespace A;
	flag=11;
	cout << flag << endl;
	fun();
	
	B::flag=false;
	
	

#if 0
	using A::flag;
	flag=100;
	cout << flag << endl;
	
	B::flag=true;
#endif	

#if 0
	A::flag=123;
	cout << A::flag << endl;
	
	B::flag=true;
	cout << B::flag << endl;
#endif
}
