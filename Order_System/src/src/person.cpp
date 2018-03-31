#include"person.h"
using namespace std;


Person::Person(int num,const string & pass)
{
	this->num = num;
	//this->name = name;
	//this->tel = tel;
	passward = pass;
}

Person::Person(int num,const string & name,const string & tel,const string & pass)
{
	this->num = num;
	this->name = name;
	this->tel = tel;
	passward = pass;
}

Person::~Person()
{
	
}
