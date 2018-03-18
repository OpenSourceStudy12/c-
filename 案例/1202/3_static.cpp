#include <iostream>
using namespace std;

class Test
{
public:
	static int x;
	int y;
	//static int fun(){ return x+y; }   //error    //static修饰成员函数，该成员函数属于类
	                                                      //静态成员函数，只能访问访问静态成员，
	static int fun(){ return x; }
};

int Test::x=0;

int main()
{
	Test t1;
	t1.x=12;
	t1.y=10;
	cout << t1.fun() << endl;
	cout << Test::fun() << endl;      //一般情况下，静态成员函数通过类名和域解析符来进行调用
	
/*
	Test t1;
	cout << t1.x << "   " << Test::x << endl;
	
	Test t2;
	cout << t2.x << "  " << Test::x << endl;
	
	t1.x=12;
	cout << t1.x << "  " << t2.x << "  " << Test::x << endl;
	
	t2.x=90;
	cout << t1.x << "  " << t2.x << "  " << Test::x << endl;
*/
}


#if 0
class Stu 
{
public:
	static int num;     //static修饰成员变量，该成员变量是属于类
	Stu(){ num++;  }
	~Stu(){ num--; }	 
};

int Stu::num=0;      //定义静态成员变量和初始化

int main()
{
	Stu s1;
	cout << s1.num << "  " << Stu::num << endl;      //静态成员变量可以通过类名访问，也可以通过对象访问
	
	Stu s2;
	cout << s2.num << "  " << Stu::num << endl;      // 实现数据共享
	

}
#endif

