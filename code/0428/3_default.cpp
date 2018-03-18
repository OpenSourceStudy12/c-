#include <iostream>
using namespace std;

//1 默认值的顺序必须是依次从右往左
//2 实参和形参的匹配顺序依次从左往右
//3. 默认值放在函数声明里

//避免函数重载和带默认值函数发生冲突

int sum(int a,int b,int c=0,int d=0);

int sum(int a,int b,int c,int d)
{
	return a+b+c+d;
}

/*
int sum(int a,int b,int c)
{
	return a+b+c;
}
*/

int main()
{
	int a;
	int b;
	int c;
	int d;
	
	cin >> a;
	cin >> b;
	cout << sum(a,b) << endl;
	
	cin >> a;
	cin >> b;
	cin >> c;
	cout << sum(a,b,c) << endl;
	
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cout << sum(a,b,c,d) << endl;
	
	//sum(a,b,0,d)
}

#if 0
int sum(int a,int b)
{
	return a+b;
}

int sum(int a,int b,int c)
{
	return a+b+c;
}

int sum(int a,int b,int c,int d)
{
	return a+b+c+d;
}
#endif
