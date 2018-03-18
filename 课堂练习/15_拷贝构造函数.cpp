/*
拷贝构造函数
浅拷贝:
深拷贝:


class Test
{
private:
	int x;
public:
	Test():x(0){}
	Test(int x1):x(x1){}
	
	//拷贝构造函数 根据一个对象创造另一个对象 若没有定义拷贝构造函数，系统会自己自己定义 在类中存在指针变量时，需要自己定义拷贝构造函数，若类中没有指针类型的变量，无需自己定义拷贝构造函数
	Test(const Test &t1)
	{
		x = t1.x;
	}

}
 
*/
#include<iostream>
using namespace std;

class T
{
	private:
		int size;
		int *ptr;
	public:
		T():size(0),ptr(NULL){}
		T(int n,int *num)
		{
			size = n;
			ptr = new int[n];
			int i;
			for(i=0;i<n;i++)
			{
				ptr[i] = num[i];
			}
		}
		T(const T &t1)
		{
			size = t1.size;
			int i;
			ptr = new int[size];
			for(i=0;i<size;i++)
			{
				ptr[i] = t1.ptr[i];
			}
		}
		~T()
		{
			delete []ptr;
		}
		void display()
		{
			int i;
			for(i=0;i<size;i++)
			{
				cout<<ptr[i]<<' ';
			}
		}
		void setdata(int index,int data)
		{
			if(index <0 || index >= size)
				return;
			ptr[index] = data;
		}
};


int main()
{
	int num[5]={2,5,7,3,8};
	T t1(5,num);
	t1.display();
	cout<<endl;

	t1.setdata(3,20);
	t1.display();
	cout<<endl;

	T t2(t1);
	t2.display();
	cout<<endl;

}


