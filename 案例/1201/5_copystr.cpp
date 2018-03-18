#include <iostream>

using namespace std;

class Arr
{
private:
	int length;
	int *ptr;
public:
	Arr(){ length=0; ptr=NULL; }
	Arr(int num[],int cnt) 
	{ 
		length=cnt; 
		ptr=new int[cnt];
		int i=0;
		for(i=0;i<cnt;i++)
			ptr[i]=num[i];
	}
	
	//Arr(Arr & a){ length=a.length; ptr=a.ptr; }
	//自定义拷贝构造函数
	Arr(Arr &a)
	{
		length=a.length;
		ptr=new int[length];
		int i=0;
		for(i=0;i<length;i++)
			ptr[i]=a.ptr[i];
	}
	
	void setindex(int index,int value)
	{
		ptr[index]=value;
	}
	
	void display()
	{
		cout << "length=" << length << "    ptr=" << ptr << endl;
		int i=0;
		for(i=0;i<length;i++)
			cout << ptr[i] << "   " ;
		cout << endl;
	}
	
	~Arr()
	{
		cout << "~Test()\n";
		delete[] ptr;
	}
};

int main()
{
	int n[5]={1,2,3,4,5};
	Arr a1(n,5);
	a1.display();
	
	//a1.setindex(3,100);
	//a1.display();
	
	Arr a2(a1);
	a2.display();
	
	a2.setindex(4,99);
	
	a1.display();
	a2.display();
}


#if 0
class Test
{
private:
	int x;
	int y;
public:
	Test(){x=0; y=0;}
	Test(int x,int y){ this->x=x; this->y=y;}
	
	//拷贝构造函数
	//Test(const Test & t1) { x=t1.x; y=t1.y; cout << "Test(Test & t1)\n"; }
	
	//如果定义类的时候没有定义拷贝构造函数，系统会自动生成拷贝构造函数，只是简单的赋值
	
	void display() { cout << "x=" << x << ", y=" << y << endl;}
};

int main()
{
	Test t1;
	t1.display();
	
	Test t2(2,3);
	t2.display();
	
	Test t3(t2);
	t3.display();
	
	Test t4(t1);
	t4.display();
	
}
#endif
