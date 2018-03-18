#include <iostream>

using namespace std;

class Test
{
public:
	int x;
	int y;
	const int z;       //const修饰成员变量,只能通过参数初始化列表初始化

	Test(int a=0,int b=0,int c=0):z(c){ x=a; y=b; }
	void display() const        
	{
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		cout << "z=" << z << endl;
	}
	
	int getx() const      //const 修饰成员函数，只能访问成员变量，不能修改成员变量
	{ 
		//x=100;
		return x; 
	}
	
	int gety(){ return y; }
	int getz(){ return z; }
	
	void setx(int x){ this->x=x; }
		
};

void fun(const Test & t1)    //const 修饰对象引用
{
	t1.setx(99);
	t1.display();
}

int main()
{
/*
	const Test t1(1,2,3);     //const修饰对象,只能调用常成员函数
	
	cout << t1.getx() << endl;
	//cout << t1.gety() << endl;
	t1.display();*/
	
	Test t2(1,2,3);
	fun(t2);

#if 0
	Test t1(1,2,3);
	t1.display();
	
	cout << t1.getx() << endl;
	
	
	t1.x=90;
	t1.y=23;
	//t1.z=100;
	t1.display();
	
	Test t2;
	t2.display();
	
	//t2.z=123;
#endif
}
