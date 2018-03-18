/*
內联函数:inline 
作用:在函数编译时函数体替换函数调用(避免头重脚轻)
注意:
1.函数体1-5行，函数功能简单
2.內联函数不能包含复杂结构，例如if-else,for
3.內联函数由编译器决定
4.递归函数不能定义成內联函数

*/

#include<iostream>
#include<cstdio>
#define MAX(x,y) x>y?x:y

using namespace std;

inline int _max(int x,int y)
{
	return x>y?x:y;
}

int main()
{
	int x,y;
	cout<<"x = ";
	cin>>x;
	cout<<"y = ";
	cin>>y;
	int max = _max(x,y);
	cout<<"max = "<<max<<endl;
}
