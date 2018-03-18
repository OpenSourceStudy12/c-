#include <iostream>
using namespace std;

//函数重载：函数名相同，形参的类型，或者个数，或者顺序不同，构成函数重载
//**** 和函数返回值类型无关

int _max(int a,int b)
{
	cout << __LINE__ << endl;
	return a>b?a:b;
}
int _max(int a) { }
int _max(int a,float b){ cout << __LINE__ << endl;  return a; }
int _max(float a,int b){ cout << __LINE__ << endl;  return b; }

//float _max(int a){}         //error

float _max(float a,float b)
{
	return a>b?a:b;
}

int _max(int num[],int cnt)
{
	cout << __LINE__ << endl;
	int max=num[0];
	int i=0;
	for(i=0;i<cnt;i++)
	{
		if(max<num[i])
			max=num[i];
	}
	return max;
}

int main()
{
	int x=12;
	int y=23;
	cout << _max(x,y) << endl;
	
	int num[3]={3,6,1};
	cout << _max(num,3) << endl;
	
	float f=1.2;
	_max(f,x);
}



#if 0
int _maxInt(int a,int b)
{
	return a>b?a:b;
}

float _maxFloat(float a,float b)
{
	return a>b?a:b;
}

int _maxArr(int num[],int cnt)
{
	int max=num[0];
	int i=0;
	for(i=0;i<cnt;i++)
	{
		if(max<num[i])
			max=num[i];
	}
	return max;
}
#endif
