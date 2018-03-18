#include <iostream>
using namespace std;

//类：自定义的数据类型
//类的定义：
/*
class 类名
{
	成员.........
	（成员变量和成员函数）
};
*/
//对象：类的变量
//定义： class 类名 对象名;   类名 对象名



//结构体
struct Stu
{
	int num;
	string name;
};

class Student
{
public:
	int num;
	string name;
	
	void fun()
	{
		cout << "Student : " << __func__ << "  " << __LINE__ << endl;
	}
};

int main()
{
	struct Stu s1;     //结构体变量
	s1.num=100;
	s1.name="aaa";
	
	//class Student s2;       //对象
	Student s2;
	s2.num=1002;
	s2.name="qwe";
	cout << s2.num << "  " << s2.name << endl;
	
	s2.fun();
	
}

