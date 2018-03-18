/*
函数模板:
template 函数模板关键字
<> 中用 typename/class 定义虚拟的数据类型

template <class T>
T max(T a,T b)
{
	return x>y?x:y
}

int main
{
	int x = 1,y = 2;
	float f1 = 1.34,f2 = 34.13;

	cout<<max(x,y)<<endl;
	cout<<max<float>(x,y)<<endl;

}

*/ 

#include<iostream>

using namespace std;

template <class T,class M >
M _max(T x,M y)
{
	return x>y?x:y;
}

int main()
{
	int x = 1,y = 2;
	float f1 = 1.34,f2 = 34.13;

	cout<<_max(x,f1)<<endl;
	cout<<_max<float>(f1,f2)<<endl;

}
