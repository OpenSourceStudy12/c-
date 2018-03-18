/*

//命名空间的定义  可以避免命名冲突

namespace 空间名
{
	成员(变量,函数，typedef..)
}

使用空间成员方法:
1: 空间名::成员
2：using 空间名::成员 声明空间的一个成员
3：using namespace 空间名 //声明空间的全部成员

using namespace std;//标准命名空间

*/

#include<iostream>
#include<cstdio>

using namespace std;

namespace a
{
	bool flag=0;
	void fun(){cout<<flag<<endl;}
}

namespace b
{
	bool flag=1;
	void fun(){cout<<a::flag<<endl;}
}

int main()
{
	using namespace b;
	fun();
	//using b::fun;
	using b::flag;
	fun();

/*
	using namespace a;
	cout<<flag<<endl;
	using b::flag;
	cout<<flag<<endl;
*/
/*
	using namespace a;
	cout<<flag<<endl;
	using b::flag;
	cout<<flag<<endl;
*/
/*	cout<<a::flag<<endl;
	cout<<b::flag<<endl;
*/	return 0;
}

