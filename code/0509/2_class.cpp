#include <iostream>
using namespace std;

//虚函数：virtual

//多态
//1,存在继承关系
//2,在子类和父类里存在同名的虚函数
//3,存在基类的指针或者引用

class Parent
{
protected:
	int x;
public:
	Parent(int x1=0):x(x1){}
	~Parent(){}
	virtual void fun()
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
};

class Child : public Parent
{
private:
	int y;
public:
	Child(int x1=0,int y1=0):Parent(x1),y(y1){}
	~Child(){}
	virtual void fun()
	{
		cout << __func__ << "  " << __LINE__ << endl;
	}
};

int main()
{
	Parent *ptr=new Child;
	ptr->fun();
	
	ptr=new Parent;
	ptr->fun();
	

#if 0
	Parent p1;
	Child c1;
	p1=c1;           //子类对象可以赋值给基类对象
	
	Parent & p2=c1;      //子类对象可以初始化基类引用
	
	Parent *ptr=new Child;     //基类指针指向子类对象
#endif
}
