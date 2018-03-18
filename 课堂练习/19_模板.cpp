/*
模板:

模板参数:
template<模板参数表>
class 类名
{

}

template<class T>  // class T 定义虚拟数据类型
class Arr
{
private:
	int size;
	T* ptr;
public:
	Arr(int n)
	{
		size=n;
		ptr =- new T[size];
	}
	~Arr()
	{
		delete []ptr;
	}
	void set(int index,T data)
	{
		ptr[index]=data;
	}
	void print()
	{
		int i;
		for(i=0;i<size;i++)
			cout<<ptr[i];
	}
	
	T & operator[](int index);
}

//外部定义成员函数 下标运算符重载
template<class T> 
T& Arr<T>::operator[](int index)
{
	if(index>=0 || index <size)
		exit(-1);
	return ptr[index]; 
}

类中类:
class A
{
public:
	class B
	{
	
	};
	B b1;

}

int mian()
{
	A a1;
	A::B b1;
}


标准模板类:STL
容器：
向量、

迭代器：
算法：
函数对象：















*/

#include<iostream>
using namespace std;

#if 0
template<class T,class B>
class Arr
{
private:
	int size;
	T *ptt;
	B *ptb;
public:
	Arr(int index=0)
	{
		size = index+1;
		ptt = new T[size];
		ptb = new B[size];
	}
	~Arr()
	{
		delete []ptt;
		delete []ptb;
	}
	void set(T data1,B data2,int index=0)
	{
		if(index < size)
		{
			ptt[index] = data1;
			ptb[index] = data2;
		}
	}
	int getSize()
	{
		return size;
	}
	void display();
	T &operator[](int);
	
};

template<class T,class B>
void Arr<T,B>::display()
{
	int i;
	for(i=0;i<size;i++)
	{
		cout<<ptt[i]<<' ';
	}
	cout<<endl;
	for(i=0;i<size;i++)
	{
		cout<<ptb[i]<<' ';
	}
	cout<<endl;

}

T& Arr<T,B>::operator[](int index)
{
	if(index>=0 && index<size)
		return ptt[index];
}





int main()
{
	Arr<int,int>a1(4);
	int i;
	for(i=0;i<a1.getSize();i++)
	{
		//a1.set((i+1)*10,(i+1)*100,i);
		cin>>a1[index]
	}
	a1.display();

}
#endif


