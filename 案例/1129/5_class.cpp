#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class stu
{
private:
	int num;
	string name;
public:
	void setnum(int n);
	void setname(string n);
	
	void display();
};

void stu::setnum(int n)
{
	num=n;
}

void stu::setname(string n)
{
	name=n;
}

void stu::display()
{
	cout << "num : " << num << "      name : " << name << endl;
}

int main()
{
	stu s1;
	s1.setnum(1004);
	s1.setname("asd");
	s1.display();
}

#if 0
struct stu
{
	int num;
	char name[20];
};

class student
{
private:                   //成员变量
	int num;
	string name;
public:                                                //成员函数
	void setnum(int n1) { num=n1; }       //成员函数定义在类的里面，就是内联函数
	void setname(string s1) { name=s1; }
	int getnum() { return num; }
	string getname() { return name; }
	void display()
	{
		cout << "num\tname" << endl;
		cout << num << "\t" << name << endl;
	}
};

int main()
{
	student s2;
	s2.setnum(1003);
	s2.setname("abc");
	s2.display();
	//cout << s2.getnum() << "  " << s2.getname() << endl;
	
	/*s2.num=1002;
	s2.name="abc";
	cout << s2.num << "   " << s2.name << endl;*/
	
	struct stu s1;
	s1.num=1001;
	strcpy(s1.name,"aaa");
	cout << s1.num << "   " << s1.name << endl;
}

#endif
