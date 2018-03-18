/*
纯虚函数：virtual 返回类型 函数名()= 0;

抽象类：含有纯虚函数的类，不能定义对象
若子类没有重新纯虚函数，则子类继承父类中的纯虚函数，也是抽象类
构造函数不能定义成纯虚函数


class Base
{
protected:
	int id;
	string name;
public:
	Base(int i=0,const string &str=""):id(i),name(srr){}
	~Base(){}
	virtual void display()=0;

};

class Student:public Base
{
private:
	int score;
public:
	Student(int i=0,const string &sre="",int sc=0):Base(i,str),score(sc){}
	~Student(){};
	
}

*/

#include<iostream>
using namespace std;

class Worker
{
protected:
	int num;
	string name;
	char sex;
public:
	//virtual Worker(int num=0,const string &name="no",char sex='M')=0;
	Worker(int num=0,const string &name="no",char sex='M'):num(num),name(name),sex(sex){}
	~Worker(){}
	virtual void display()=0;

};

class Manager:public Worker
{
private:
	float salary;
public:
	//Worker(int num=0,const strng &name="no",char sex='M'):num(num,name(name),sex(sex)){}
	Manager(int num=0,const string &name="no",char sex='M',float salary=0):Worker(num,name,sex)
	{
		this->salary = salary;
	}
	void display()
	{
		cout<<num<<' '<<name<<' '<<sex<<' '<<salary<<endl;
	}
};

int main()
{
	Manager m1(1001,"lrh",'M',15000);
	m1.display();

}






