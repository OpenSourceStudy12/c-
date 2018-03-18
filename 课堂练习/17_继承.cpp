#if 1
/*继承:
class 派生类 ：继承方式(public private protected) 父类{成员包括父类成员和自己新建的成员}

*/

/*

继承方式     父类         子类访问      类外
publi       private         0            0
            protected       1            0
	    public          1            1

private     private         0            0
            ptotected       1            0
            public          1            0

protected   private         0            0
            protected       1            0
	    public          1            0


class A
{
private:
	int x;
protected:
	int y;
public:
	int z;

};


public 继承
class B:public A
{
private:
	int a;
protected:
	int b;
public:
	int c;
	void display()
	{
		cout<<x<<endl;//子类中不能访问父类私有成员
		cout<<y<<endl;//子类中可以访问父类的受保护成员，外边不能访问
		cout<<z<<endl<<endl;
		cout<<a<<endl;//类外不能访问私有成员
		cout<<b<<endl;//类外不能访问受保护成员
		cout<<c<<endl;
	
	}
};

private 继承(父类中成员变成子类中私有成员)
class B:private A
{
private:
	int a;
protected:
	int b;
public:
	int c;
	void display()
	{
		cout<<x<<endl;//子类中不能访问父类私有成员
		cout<<y<<endl;//子类中可以访问父类的受保护成员，外边不能访问
		cout<<z<<endl<<endl;//子类可以访问父类公有成员 类外不能
		cout<<a<<endl;//类外不能访问私有成员
		cout<<b<<endl;//类外不能访问受保护成员
		cout<<c<<endl;
	
	}
};
*/
#endif

#if 0
#include<iostream>
using namespace std;

class A
{
private:
	int x;
protected:
	int y;
public:
	int z;

};


//protected 继承
class B:protected A
{
private:
	int a;
protected:
	int b;
public:
	int c;
	void display()
	{
		cout<<x<<endl;//子类中不能访问父类私有成员
		cout<<y<<endl;//子类中可以访问父类的受保护成员，外边不能访问
		cout<<z<<endl<<endl;
		cout<<a<<endl;//类外不能访问私有成员
		cout<<b<<endl;//类外不能访问受保护成员
		cout<<c<<endl;
	
	}
};

int main()
{
	B b;
	b.x=1;
	b.y=1;
	b.z=1;
	b.a=1;
	b.b=1;
	b.c=1;

}

#endif

/*

继承关系下的构造函数
构造函数调用顺序：自上往下，先父类后子类

class Person（父类）
{
protected:
	int id;
	string name;
public:
	Person()
	{
		id = 0;
		name = "no name"
	}

	Person(int i,const string & str)
	{
		id = i;
		name = str;
	}
	~Person(){}
	//Person(int n=0,const string &str =="no name"):id(n),name(str){}
	void display()
	{
		cout<<id<<' '<<name;
	
	}
};

class Stuent:public Person
{
private:
	int score;
public:
	Student()
	{
		score = 0;
	}
	Student(int i,const string &str,int s):Person(i,str)
	{
		score = s;
	
	}
	~Student(){}
	void print()
	{
		display();
		cout<<score<<endl;
	}
};
*/

/*
继承关系下析构函数
调用顺序:自下往上 先子类后父类

若子类与父类中有同名函数:则优先调用的是子类中的同名函数
如想调用父类中同名函数:   类名::函数()
(与函数参数无关)

*/







