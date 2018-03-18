#include <iostream>

using namespace std;

int fun(int num,int x=10)
{
	return num*x;
}

int f1(int a,int b=10,int c=9)      //默认值的顺序只能是从右往左，实参和形参的传参匹配顺序只能是从左往右
{
	return a+b+c;
}

int f2(int a=12,int b=10)
{
	return a+b;
}


int main()
{
	
	cout << f2() << endl;
	cout << f2(1) << endl;
	cout << f2(1,2) << endl;
	
	int i=0;
	for(i=1;i<10;i++)
	{
		cout << fun(i) << endl;
	}
	
	cout << fun(45) << endl;
	
	cout << f1(111) << endl;
	cout << f1(120,1) << endl;
	cout << f1(1,2,3) << endl;
	cout << f1(12,10,1)
}
