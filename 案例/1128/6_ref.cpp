#include <iostream>
using namespace std;

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

void f3(int & a,int &b)              //引用作为函数参数
{
	int tmp=a;
	a=b;
	b=tmp;
}

void fun(int & a)
{
	a=100;
}

int add1(int a,int b)
{
	int sum=a+b;
	return sum;
}

int s=0;
int & add2(int a,int b)        //引用作为函数返回值， 不能返回普通局部变量的引用 
{
	static int sum=a+b;
	return sum;
	
	//s=a+b;
	//return s;
}

int main()
{
	int a1=12;
	int a2=10;
	int sum1=add1(a1,a2);
	cout << sum1 << endl;
	
	int sum2=add2(a1,a2);
	cout << sum2 << endl;

	int x1=0;
	fun(x1);
	cout << x1 << endl;
	
	
	int n1=12;
	int n2=10;
	//f1(n1,n2);
	//f2(&n1,&n2);
	f3(n1,n2);
	cout << n1 << endl;
	cout << n2 << endl;


/*
	int num=100;
	int n1=123;
	int & re_num=num;        //引用必须做初始化,  初始化以后不能再作为其他变量的引用
	
	re_num=123;
	cout << re_num << endl;
	cout << num << endl;
	
	const int & f1=100;
	//f1=123;
*/
}
