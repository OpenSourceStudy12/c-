#include<iostream>
using namespace std;

//函数模板  class/typename
template <class T>
T _max(T a,T b)
{
	return a>b?a:b;
}

int main()
{
	int x=1;
	int y=3;
	cout << _max(x,y) << endl;
	
	double f1=1.2;
	double f2=3.4;
	//cout << _max(f1,f2) << endl;
	cout << _max<double>(f1,f2) << endl;
	
}


#if 0
int _max(int a,int b)
{
	return a>b?a:b;
}

float _max(float a,float b)
{
	return a>b?a:b;
}

char _max(char a,char b)
{
	return a>b?a:b;
}
#endif
