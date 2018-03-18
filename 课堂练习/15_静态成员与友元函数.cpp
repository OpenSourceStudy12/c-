/*
静态成员: static : (可以通过类名和对象访问)

友元函数: friend       缺点:破坏了类的封装

友元类:1.友元关系是单向的
       2.没有传递形(A是B的友元，B是C的友元，但A不是C的友元)

class Stu;//类的声明

class Tea
{
private:
	int num;
	string name;
public:
	Tea(int n=0,const string &str):num(n),name(str)
	{
		cnt++;
	}
	~Tea(){}

	//静态成员函数 只能访问类中静态成员变量，不能访问其它变量。
	static int getCnt()
	{
		return cnt;
	}
	void ptint(Tea &tea);
	void display(Stu &stu);
};

class Stu
{
private:
	int num;
	string name;
public:
	//静态成员变量
	static int cnt;
	Stu(int n=0,const string &str):num(n),name(str)
	{
		cnt++;
	}
	~Stu(){}

	//静态成员函数 只能访问类中静态成员变量，不能访问其它变量。
	static int getCnt()
	{
		return cnt;
	}
	int getNum()
	{
		return num;
	}
	string getName()
	{
		return name;
	}
	friend void ptint(Stu &stu);
	//友元函数
	//frined void Tea::display(Stu &stu);
	//友元类
	friend Tea;(Tea中所有函数是stu类的友元函数)
};

//静态成员变量初始化
int Stu::cnt = 0;

void print(Stu &stu)
{
	cout<<Stu.num<<endl;
}

void Tea::display(Stu &stu)
{
	cout<<tea.num<<tea.name<<endl;
	cout<<stu.num<<stu.name<<endl;
	//cout<<stu.getNum()<<stu.getName()<<endl;
}


int main()
{
	Stu *s1 = new Stu(1001,"qwe");
        Stu *s2 = new Stu(1002,"asd");	
	cout<<s1->cnt<<s2->cnt<<Stu::cnt<<endl;//2

	cout<<s1->getCnt()<<Stu::getCnt()<<endl;//2
}


 
*/

#include<iostream>
using namespace std;

class Stu;//类的声明

class Tea
{
private:
	int num;
	string name;
public:
	Tea(int n=0,const string &str="no name"):num(n),name(str)
	{
	}
	~Tea(){}

//	void ptint(Tea &tea);
	void display(Stu &stu);
};
class Stu
{
	private:
		int num;
		string name;
	public:
		static int cnt;
		Stu(int n=0,const string &str = "no name"):num(n),name(str)
		{
			cnt++;
		}
		static int getCnt()
		{
			return cnt;
		}
	friend void Tea::display(Stu &stu);
};
int Stu::cnt = 0;

void Tea::display(Stu &stu)
{
	cout<<stu.num<<' '<<stu.name<<endl;
	cout<<num<<' '<<name<<endl;
	//cout<<stu.getNum()<<stu.getName()<<endl;
}

int main()
{
	Stu stu(1001,"lrh");
	Stu *s1 = new Stu(1002,"ly");
	cout<<stu.getCnt()<<s1->getCnt()<<Stu::cnt<<Stu::getCnt()<<endl;
	delete s1;

	Tea tea(2001,"zxc");
	tea.display(stu);
	return 0;
}












