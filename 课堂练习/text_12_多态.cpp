/*

赋值兼容规则:

派生类对象可以赋值给基类对象
子类对象可以初始化基类对象的引用i
基类对象指针可以指向子类对象


多态条件
1.存在继承关系
2.在子类和父类中存在同名虚函数(定义函数前加 virtual,放在函数声明前)(包括析构函数)
3.存在基类指针或引用

绑定:
静态绑定
动态绑定 

虚函数:
动态绑定基础
非静态的成员函数
继承性：派生类中的同名函数无论是否声明都是虚函数
调用方式:基类指针或引用


重载：在同作用域中，函数名相同，参数个数，类型，顺序不同 
重写/覆盖：子重新定义父类中函数(虚函数)
隐藏：同名函数不是虚函数会形成隐藏


class Parent
{
protevted:
	int x;
public:
	Parent(int x1=0):x(x1){}
	virtual void fun(){} //虚函数

};


class Child:public:Parent
{
private:
	int y;
public:
	Child(int x1=0,int y1=0):Parent(x1),y(y1){}
	virtual void fun(){} //虚函数

};

int main()
{
	Parent p1;
	Child c1;
	p1=c1;  //子类对象可以给基类对象赋值

	Parent &p2 = c1;//子类对象可以初始化基类对象的引用i

	Parent *ptr = new Child; //基类对象指针可以指向子类对象

	//ptr->fun; //调用的是基类的函数
}


















*/








