#include<iostream>
using namespace std;

void set(const int *p)
{
	int a = 8 ;
	p = &a;
	cout<<*p<<endl;
}


int main()
{
	int a = 5,b=6;
	int *const p = &a;
	cout<<*p<<endl;
	//*p = 8;
	p=&b;
	cout<<*p<<endl;
	//set(p);
	return 0;
}
