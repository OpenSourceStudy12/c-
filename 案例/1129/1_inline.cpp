#include <iostream>
using namespace std;

inline int findMax(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int n1=12;
	int n2=23;
	int max=findMax(n1,n2);     //int max=n1>n2?n1:n2;
	cout << max << endl;
}
