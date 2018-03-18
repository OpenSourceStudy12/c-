#include <iostream>
#include <cstdlib>
using namespace std;

//类模板
//template<class T> 模板头
//T 类参数
template<class T>
class Arr
{
private:
	int size;
	T* ptr;
public:
	Arr(int n)
	{
		size=n;
		ptr=new T[size];
	}
	~Arr()
	{
		delete[] ptr;
	}
	int getsize() const { return size; }
	void set(int index,T data)
	{
		ptr[index]=data;
	}
	void display()
	{
		int i=0;
		for(i=0;i<size;i++)
			cout << ptr[i] << "  ";
		cout << endl;
	}
	
	T & operator[](int index);
};

template<class T>
T& Arr<T>::operator[](int index)
{
	if(index<0||index>=size)
		exit(-1);
	return ptr[index];
}

int main()
{
	Arr<int> a1(4);
	int i=0;
	for(i=0;i<a1.getsize();i++)
	{
		a1.set(i,(i+1)*10);
	}
	
	a1.display();
	
	Arr<string> a2(3);
	string str;
	for(i=0;i<a2.getsize();i++)
	{
		cin >> a2[i];
	}
	
	for(i=0;i<a2.getsize();i++)
	{
		cout << a2[i] << endl;
	}
	
	//a2[i]="qwe";
}

#if 0
class Arr_Int
{
private:
	int size;
	int *ptr;
public:
	Arr_Int(int n)
	{
		size=n;
		ptr=new int[size];
	}
	Arr_Int()
	{
		delete [] ptr;
	}
	void set(int index,int value){}
	void display(){}
};

class Arr_Float
{
private:
	int size;
	float *ptr;
public:
	Arr_Float(int n)
	{
		size=n;
		ptr=new float[size];
	}
	~Arr_Float()
	{
		delete[] ptr;
	}
	void set(int index,float f){}
	void display(){}
};

class Arr_Char
{

};
#endif
