#include <iostream>
#include <cstdlib>

using namespace std;

class Test
{
private:
	int x;
public:
	Test(int x1=0){ x=x1; cout << "----Test()-----\n"; }
	~Test() { cout << "------~Test()-----\n"; }
	
	//this 关键字，每个成员函数都有一个this指针，this指向调用这个成员函数的对象
	void setx(int x){ this->x=x; }
	
	void fun() { cout << "x=" << x <<  endl; cout << "----fun()----\n"; }	
};

int main()
{
	//malloc free 函数
	//new delete  操作符  调用构造函数和析构函数
	
	Test *t1=(Test *)malloc(sizeof(Test));
	t1->fun();
	free(t1);
	
	Test *t2=new Test(100);
	t2->setx(123);
	t2->fun();
	delete t2;
	
	Test t3;
	t3.setx(90);
	t3.fun();
	
	
	
	
	
#if 0
	int *p1=new int;
	*p1=123;
	cout << p1 << "   " << *p1 << endl;
	delete p1;
	
	int *p2=new int[4];
	int i=0;
	for(i=0;i<4;i++)
	{
		p2[i]=i*5;
	}
	for(i=0;i<4;i++)
	{
		cout << p2[i] << endl;
	}
	delete[] p2;


	int *ptr=(int *)malloc(100);
	if(ptr==NULL)
		return 0;
	
	ptr[0]=100;
	cout << ptr[0] << endl;
	
	free(ptr);
	
#endif	

/*
	Test t1;
	
	Test *ptr=&t1;
	
	t1.fun();
	
	ptr->fun();*/
}
