#include "2_class.h"

Person::Person()
{
	num=0;
	name="noname";
}

Person::Person(int n,const string & str)
{
	num=n;
	name=str;
}

Person::~Person(){}

void Person::display()
{
	cout << num <<  "  " << name << endl;
}
