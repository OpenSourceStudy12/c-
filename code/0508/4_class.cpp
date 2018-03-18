#include <iostream>
using namespace std;

//class 派生类：继承方式 基类{   };
//Person : 基类/父类
//Student：派生类/子类

class Person
{
public:
	int id;
	string name;
	//Person(int id=0,const string & str="noname"):id(id),name(str){}
	//~Person(){}
	void display(){ cout << id << "  " << name << endl; }
};

class Student : public Person
{
public:
	int score;
	void print()
	{
		//cout << id << "  " << name << "  " << score << endl;
		display();
		cout << score << endl;
	}
};

int main()
{
	Student s1;
	cin >> s1.id;
	cin >> s1.name;
	cin >> s1.score;
	s1.print();
	s1.display();
	return 0;
}








#if 0
class Person
{
private:
	int id;
	string name;
public:
	Person(int id=0,const string & str="noname"):id(id),name(str){}
	~Person(){}
	void display(){ cout << id << "  " << name << endl; }
};

class Student
{
private:
	int id;
	string name;
	int score;
public:
	Student(int id=0,const string & str="noname",int s=0):id(id),name(str),score(s){}
	~Student(){}
	
	void display(){ cout << id << "  " << name << "  " << score << endl; }
};

int main()
{
	Person p1(1001,"asd");
	p1.display();
	
	Student s1(1002,"qwe",100);
	s1.display();
}
#endif
