#include <iostream>
#include <cstring>
using namespace std;

//构造函数和析构函数调用顺序相反

class Stu
{
private:
	int num;
	char *name;
public:
	Stu()
	{
		num=0;
		name=new char[20];
		strcpy(name,"noname");
	}
	Stu(int n,const char *str)
	{
		num=n;
		name=new char[20];
		strcpy(name,str);
	}
	/*******/
	~Stu()
	{
		cout << num << endl;
		cout << __func__ << "  " << __LINE__ << endl;
		delete[] name;
	}
	
	void display()
	{
		cout << num << "  " << name << endl;
	}
};

int main()
{
	Stu s1;
	s1.display();
	
	Stu s2(1002,"aaa");
	s2.display();
}
