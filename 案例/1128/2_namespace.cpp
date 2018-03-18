#include <iostream>

//using namespace std;

//定义命名空间
namespace A
{
	int flag;
	void f1() { std::cout << "A::f1()" << std::endl; }
}

namespace B
{
	bool flag;
	void f1() { std::cout << "B::f1()" << std::endl; }
}


int main()
{
	B::flag=true;           //::域解析符
	A::flag=1;
	
	std::cout << "flag=" << A::flag << std::endl;
	/*
	using A::flag;
	flag=123;
	cout << "flag=" << flag << endl;
	
	A::f1();*/
	
	using namespace A;
	flag=100;
	std::cout << flag << std::endl;
	f1();
}
