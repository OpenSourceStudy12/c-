/*
带默认值函数:
int sum(int a,int b,int c=0,int d=0)
{
	return a+b+c+d;
}

1.带默认值顺序从右往左(右边参数是默认值，左边参数才能为默认值)
2.实参与形参匹配顺序从左到右(给右边默认值传值时，左边默认值不能跳过)
3.默认值函数的声明默认值跟着函数声明(定义时不用带默认值)

带默认值函数与重载函数有时会产生冲突
*/

#include<iostream>
using namespace std;

int sum(int a,int b,int c=0,int d=0)
{
	return a+b+c+d;
}

int main()
{
	int a,b,c,d;
	cout<<"一年级学生成绩:(语文、数学)"<<endl;
	cin>>a;
	cin>>b;
	cout<<"一年级学生成绩总分:"<<sum(a,b)<<endl;

	cout<<"二年级学生成绩:(语文、数学、英语)<<endl";
	cin>>a;
	cin>>b;
	cin>>c;
	cout<<"二年级学生成绩总分:"<<sum(a,b,c)<<endl;

	cout<<"三年级学生成绩:(语文、数学、英语、c语言)<<endl";
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	cout<<"三年级学生成绩总分:"<<sum(a,b,c,d)<<endl;
}
