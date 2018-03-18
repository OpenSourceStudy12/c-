#include <iostream>
using namespace std;

class Person
{
public:
	int id;
	string name;
	char sex;
public:
	Person(int i=0, string n="noname",char s='m'):id(i),name(n),sex(s){}
};

class Student:public Person
{
public:
	float score;
public:
	Student():score(0){}
};

int main()
{
	Student s1;
	cout << s1.id << endl;
	cout << s1.name << endl;
}


/*
class Student
{
private:
	int id;
	string name;
	char sex;
	float score;
public:
	Student(int i=0,string n="noname",char s='m',float f=0):id(i),name(n),sex(s),score(f){}
};*/
