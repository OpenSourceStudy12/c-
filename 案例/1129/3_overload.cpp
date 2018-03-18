#include <iostream>

using namespace std;

int findMax(int a)
{
	return a;
}

int findMax(int a,int b)
{
	return a>b?a:b;
}

int findMax(int num[],int n)
{
	int max=num[0];
	int i=0;
	for(i=0;i<n;i++)
	{
		if(max<num[i])
			max=num[i];
	}
	return max;
}

float findMax(float a,float b)
{
	return a>b?a:b;
}

void f1(int n1,float f1)
{
	cout << __LINE__ << endl;
}

void f1(float f1,int n1)    //函数重载：函数名相同，形参的类型不同，或者个数不同，或者形参顺序不同，跟函数的返回值类型无关
{
	cout << __LINE__ << endl;
}

int main()
{
	int x1=1;
	int x2=2;
	findMax(x1);
	
	int num1=1;
	float f123=1.2;
	f1(num1,f123);
	f1(f123,num1);
	
	
	int num[5]={1,4,2,3,6};
	cout << findMax(num,5) << endl;
	int n1=1;
	int n2=2;
	cout << findMax(n1,n2) << endl;
	float f1=1.2;
	float f2=4.5;
	cout << findMax(f1,f2) << endl;
}

