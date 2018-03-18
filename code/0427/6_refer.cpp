#include <iostream>
using namespace std;

//引用：变量的别名
// 类型名 & 引用名称=变量
/*
1,必须初始化
2,绑定同一个变量
3,对引用操作，其实就是对变量操作
*/

void f1(int a,int b)
{
	int tmp=a;
	a=b;
	b=tmp;
}

void f2(int *p1,int *p2)
{
	int tmp=*p1;
	*p1=*p2;
	*p2=tmp;
}

void f3(int & a,int & b)
{
	int tmp=a;
	a=b;
	b=tmp;
}

//返回引用：不要返回局部变量的引用
//1返回静态局部变量的引用
//2,返回全局变量的引用
//3.返回传进来的形参（引用）的引用
int & _max(int a,int b)     //返回引用
{
	static int n=a>b?a:b;	
	return n;
}

void fun(const int & a)
{
	
}


int main()
{
	int tmp=_max(23,56);

#if 0
	int x=23;
	int y=90;
	//f1(x,y);       //传值调用，x和y没有交换
	
	//f2(&x,&y);     //传变量的地址，x和y交换
	
	f3(x,y);         //传引用调用，x和y交换
#endif
#if 0
	int num;
	
	//引用：变量的别名
	int & re_num=num;
	
	num=12;
	cout << num << endl;
	cout << re_num << endl;
	
	re_num=100;
	cout << num << endl;
	cout << re_num << endl;
	
	const int & n=3;
	//n=12;
#endif	
}
