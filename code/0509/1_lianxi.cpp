#include <iostream>
using namespace std;

class Base
{
protected:
	string name;
	int age;
public:
	Base(const string & str="noname",int age=0):name(str),age(age){}
	~Base(){}
	void display()
	{
		cout << "name : " << name << endl;
		cout << "age : " << age << endl;
	}
};

class Leader : virtual public Base
{
protected:
	string zhiwu;
	string bumen;
public:
	Leader(const string & str="noname",int a=0,const string & z="no",const string & b="no"):Base(str,a)
	{
		zhiwu=z;
		bumen=b;
	}
	~Leader(){}
	void display()
	{
		Base::display();
		cout << "zhiwu : " << zhiwu << endl;
		cout << "bumen : " << bumen << endl;
	}
};

class Engineer : virtual public Base
{
protected:
	string zhicheng;
	string zhuanye;
public:
	Engineer(const string & str="noname",int a=0,const string & z1="no",const string & z2="no"):Base(str,a)
	{
		zhicheng=z1;
		zhuanye=z2;
	}
	~Engineer(){}
	void display()
	{
		Base::display();
		cout << "zhicheng : " << zhicheng << endl;
		cout << "zhuanye : " << zhuanye << endl;
	}
};

class Chairman : public Leader, public Engineer
{
public:
	Chairman(const string & str="noname",int a=0,const string & z="no",const string & b="no",const string & z1="no",const string & z2="no"):Base(str,a),Leader(str,a,z,b),Engineer(str,a,z1,z2){}
	~Chairman(){}
	void display()
	{
		cout << "name : " << name << endl;
		cout << "age : " << age << endl;
		cout << "zhiwu : " << zhiwu << endl;
		cout << "bumen : " << bumen << endl;
		cout << "zhicheng : " << zhicheng << endl;
		cout << "zhuanye : " << zhuanye << endl;
	}
};

int main()
{
	Chairman c1;
	c1.display();
	
	Chairman c2("aaa",45,"zxc","abc","engineer","computor");
	c2.display();
}
