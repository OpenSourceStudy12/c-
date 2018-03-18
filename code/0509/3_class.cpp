#include <iostream>
using namespace std;

class Parent
{
private:
	int *ptr1;
public:
	Parent(int n)
	{
		cout << __func__ << "  " << __LINE__ << endl;
		ptr1=new int[n];
	}
	virtual ~Parent()
	{
		cout << __func__ << "  " << __LINE__ << endl;
		delete[] ptr1;
	}
};

class Child : public Parent
{
private:
	int *ptr2;
public:
	Child(int n):Parent(n)
	{
		cout << __func__ << "  " << __LINE__ << endl;
		ptr2=new int[n];
	}
	virtual ~Child()
	{
		cout << __func__ << "  " << __LINE__ << endl;
		delete[] ptr2;
	}
};

int main()
{
	//Child c1(5);
	
	Parent *ptr=new Child(5);
	delete ptr;
}
