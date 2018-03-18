#include<iostream>
using namespace std;

extern "C"
{
	void fun1();
	void fun2();
}

void fun3()
{
	cout<<__FILE__<<" "<<__func__<<" "<<__LINE__<<endl;
}

int main()
{
	fun1();
	fun2();
	fun3();
	return 0;
}
