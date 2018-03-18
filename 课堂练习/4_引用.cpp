/*
typedef 对数据类型取别名

引用:变量的别名 不会分配内存
语法:
数据类型 & 引用名称 = 变量

用法：
int num;
int& re_num = num;

num = 12;
cout<<num<<endl<<re_num<<endl;//num == re_num == 12

re_num = 100;
cout<<num<<endl<<re_num<<endl;//num == re_num == 100
 

1.必须初始化
2.从始至终只能引用一个变量
3.对引用操作就是对变量操作
 
对 void 不能引用
对数组不能引用
主要用于函数引用 
*/

#include<iostream>
#include<cstdio>
using namespace std;

//函数参数引用
void fun(int& a,int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

//函数返回引用
int& fun1(int& x,int& y)
{
 	static int m = x>y?x:y;
	int temp;
	temp = x;
	x = y;
	y = temp;
	return m;
}

/*
函数返回引用时不能返回局部变量
可以返回静态变量的引用和全局变量
可以返回形参引用(形参本身是引用)
*/
int main()
	cout<<"二年级学生成绩总分:"<<sum(a,b,c)<<endl;
{
	int max;
	int a,b;
	cout<<"a = ";
	cin>>a;
	cout<<"b = ";
	cin>>b;
	max = fun1(a,b);
	cout<<"max = "<<max<<endl;
	cout<<"a = "<<a<<endl<<"b = "<<b<<endl;
/*
	int a;
	int b;
	cout<<"a = ";
	cin>>a;
	//cout<<endl;;
	cout<<"b = ";
	cin>>b;
	//cout<<"\n";
	fun(a,b);//a,b的值将交换 a=3,b=2;
	cout<<"a = "<<a<<endl<<"b = "<<b<<endl;
	//printf("-");
	//printf("-");
	cout<<"123";
	cout<<"123";
*/
	return 0;
}













