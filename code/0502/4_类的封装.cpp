#include <iostream>
using namespace std;

//封装：
//private：私有成员
//public：公有成员

class Stu
{
protected:
	int num;
	string name;
public:
	void setNum(int n)
	{
		num=n;
	}
	//1 对象作为参数传引用 2 不做修改常引用
	void setName(const string & n)
	{
		name=n;
	}
	int getNum()
	{
		return num;
	}
	string getName()
	{
		return name;
	}
	inline void display();
	/*void display()
	{
		cout << num << "  " << name << endl;
	}*/
};

void Stu::display()
{
	cout << num << "  " << name << endl;
}

int main()
{
#if 0
	Stu s1;
	s1.setNum(1001);
	s1.setName("aaa");
	
	cout << s1.getNum() << "  " << s1.getName() << endl;
	
	Stu s2;
	s2.setNum(1002);
	s2.setName("qwe");
	s2.display();
#endif

#if 1
	Stu s1;
	s1.num=1001;
	s1.name="aaa";
	//s1.score=90;
#endif
}
