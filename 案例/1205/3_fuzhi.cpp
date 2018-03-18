#include <iostream>
using namespace std;

class Arr
{
private:
	int size;
	int *ptr;
public:
	Arr(){ size=0; ptr=NULL; }
	Arr(int num[],int cnt)
	{
		size=cnt;
		ptr=new int[size];
		int i=0;
		for(i=0;i<size;i++)
		{
			ptr[i]=num[i];
		}
	}
	/*
	Arr(const Arr & a1)
	{
		size=a1.size;
		ptr=new int[size];
		int i=0;
		for(i=0;i<size;i++)
			ptr[i]=a1.ptr[i];
	}
	*/
	void display()
	{
		cout << size << endl;
		int i=0;
		for(i=0;i<size;i++)
			cout << "ptr[" << i << "] : " << ptr[i] << endl;
	}
	
	void setnum(int i,int data)
	{
		ptr[i]=data;
	}
	
	Arr operator=(const Arr & a1)
	{
		size=a1.size;
		delete[] ptr;
		ptr=new int[size];
		int i=0;
		for(i=0;i<size;i++)
			ptr[i]=a1.ptr[i];
		return *this;
	}
};

int main()
{
	int num[5]={3,4,5,6,7};
	Arr a1(num,5);
	a1.display();
	
	Arr a2;
	a2=a1;
	a2.display();
	
	a1.setnum(2,123);
	a1.display();
	a2.display();

	
	
	
}

