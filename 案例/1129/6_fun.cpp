#include <iostream>
#include "6_fun.h"

void tea::setData(int n,string na,int c)
{
	num=n;
	name=na;
	cls=c;
}

void tea::display()
{
	cout << num << endl;
	cout << name << endl;
	cout << cls << endl;
}

int main()
{
	tea t1;
	t1.setData();
	t1.display();
}
