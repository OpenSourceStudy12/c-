#include <iostream>
using namespace std;

//继承关系下构造函数的调用顺序：自上往下，先父类后子类
//继承关系下析构函数的调用顺序: 先子类后父类

//子类和父类存在同名函数：优先调用子类的同名函数，调用父类的同名函数时加上类名和域解析符

class Person
{
protected:
	int id;
	string name;
public:
	Person()
	{
		id=0;
		name="noname";
		cout << __func__ << "  " << __LINE__ << endl;
	}
	Person(int i,const string & str)
	{
		id=i;
		name=str;
		cout << __func__ << "  " << __LINE__ << endl;
	}
	~Person()
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	
	void fun()
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
};

class Student : public Person
{
private:
	int score;
public:
	Student()
	{
		score=0;
		cout << __func__ << "  " << __LINE__ << endl;
	}
	Student(int i,const string & str,int s):Person(i,str)
	{
		score=s;
		cout << __func__ << "  " << __LINE__ << endl;
	}
	~Student()
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	void display()
	{
		cout << id << "  " << name << "  " << score << endl;
	}
	
	void fun()
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	void fun(int num)
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
};

int main()
{
	Student s1;
	s1.display();
	cout<<"-----------------"<<endl;
	Student s2(1002,"zxc",90);
	s2.display();
	
	s2.Person::fun();
	
	s2.fun();
	s2.fun(123);
}
