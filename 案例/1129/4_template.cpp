#include <iostream>
using namespace std;

template<typename T>
T findmax(T a,T b)
{
	return a>b?a:b;
}

template<typename T,typename S>
void fun(T n1,S n2)
{
	cout << n1 << endl;
	cout << n2 << endl;
}


int main()
{
	int n1=1;
	int n2=2;
	cout << findmax(n1,n2) << endl;
	
	float f1=1.2;
	float f2=2.3;
	cout << findmax(f1,f2) << endl;
	
	fun(n1,f1);
}
	
