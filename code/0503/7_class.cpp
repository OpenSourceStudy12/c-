#include <iostream>
using namespace std;

class Stu
{
private:
	int num;
	string name;
	int score;
public:
	Stu()
	{
		num=0;
		name="noname";
		score=0;
		cout << __func__ << "  " << __LINE__ << endl;
	}
	Stu(int n,const string & str,int s):num(n),name(str),score(s)
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	
	void display()
	{
		cout << num << "  " << name << "  " << score << endl;
	}
};

class Tea
{
private:
	int num;
	string name;
public:
	Tea():num(0),name("noname")
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	Tea(int n,const string & str):num(n),name(str)
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	
	void display()
	{
		cout << num << "  " << name << endl;
	}
};

class Group
{
private:
	Stu stu;
	Tea tea;
public:
	Group(){}
	Group(int n1,const string & str1,int s1,int n2,const string & str2):stu(n1,str1,s1),tea(n2,str2)
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
	
	void display()
	{
		stu.display();
		tea.display();
	}
};

int main()
{
	Group g1(1001,"aaa",90,2001,"sss");
	g1.display();
	
	Group g2;
	g2.display();
}

