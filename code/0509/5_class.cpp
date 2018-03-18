#include <iostream>
#include <cstring>
using namespace std;

#if 0
class CString
{
private:
	int size;
	char *ptr;
public:
	CString(int s,char *src)
	{
		size=s;
		ptr=new char[size];
		strcpy(ptr,src);
	}
};

int main()
{
	char str[10]="asd";
	CString s1(20,str);
	cout << sizeof(CString) << endl;
}
#endif

#if 1
class Test
{
private:
	int x;
	char y;
public:
	Test(int x1=0,char y1='0'):x(x1),y(y1){}
	~Test(){}
	virtual void f1(){}
	virtual void f2(){}
};

class Child : public Test
{
private:
	int z;
public:
	Child(int z=0):z(z){}
	
	void f1(){}
	void f2(){}
};


int main()
{
	cout << sizeof(Child) << endl; //类中有virtural关键字时，类空间大小 + 4bit
}
#endif
