#ifndef _2_CLASS
#define _2_CLASS

#include <iostream>
using namespace std;

class Person
{
private:
	int num;
	string name;
public:
	Person();
	Person(int n,const string & str);
	~Person();
	void display();
};

#endif
