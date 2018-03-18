#include <iostream>
using namespace std;

#if 1
class Arr
{
private:
	int size;
	int *ptr;
public:
	Arr(){ size=0; ptr=NULL; }
	Arr(int s)
	{
		size=s;
		ptr=new int[size];
		int i=0;
		for(i=0;i<size;i++)
			ptr[i]=(i+1)*10;
	}
	Arr(int s,int num[])
	{
		size=s;
		ptr=new int[size];
		int i=0;
		for(i=0;i<size;i++)
			ptr[i]=num[i];
	}
	
	Arr(const Arr & a1) //拷贝构造函数 深拷贝
	{
		size=a1.size;
		ptr=new int[size];
		int i=0;
		for(i=0;i<size;i++)
			ptr[i]=a1.ptr[i];
	}
	
	/*
	Arr(const Arr & a1)  //拷贝构造函数 浅拷贝 
	{
		size=a1.size;
		ptr=a1.ptr;
	}
	*/
	
	~Arr(){ delete[] ptr; }
	
	void display()
	{
		int i=0;
		for(i=0;i<size;i++)
			cout << ptr[i] << "  ";
		cout << endl;
	}
	
	void setData(int index,int data)
	{
		if(index<0||index>=size)
			return;
		ptr[index]=data;
	}
};

int main()
{
	int num[4]={5,2,8,6};
	Arr a1(4,num);
	a1.display();
	
	Arr a2(a1);
	a2.display();
	
	a1.setData(1,100);
	a1.display();
	a2.display();
	
	
}
#endif 

#if 0 
class Test
{
private:
	int x;
public:
	Test():x(0){}
	Test(int x1):x(x1){}
	
	//拷贝构造函数
	Test(const Test & t1)
	{
		x=t1.x;
		cout << __LINE__ << endl;
	}
	
	void display()
	{
		cout << x << endl;
	}
};

int main()
{
	Test t1(5);
	t1.display();
	
	Test t2(t1);
	t2.display();
}

#endif
