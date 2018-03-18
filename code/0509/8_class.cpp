#include <iostream>
using namespace std;

class Base
{
public:
	virtual float fun(float money)=0;
	virtual ~Base(){}
};

class A : public Base
{
public:
	~A(){}
	float fun(float money)
	{
		return money;
	}
};

class B : public Base
{
private:
	float count;
public:
	B(float c=1)
	{
		count=c;
	}
	~B(){}
	float fun(float money)
	{
		return money*count;
	}
};

class C : public Base
{
private:
	float all;
	float ret;
public:
	C(float a1=100,float r=15)
	{	
		all=a1;
		ret=r;
	}
	~C(){}
	float fun(float money)
	{
		if(money>=all)
			return money-ret;
		return money;
	}
};

class Shop
{
private:
	string name;
	int count;
	float price;
	Base *ptr;
public:
	Shop():name("aaa"),count(0),price(0),ptr(NULL){}
	~Shop(){}
	
	void start();
	
};

void Shop::start()
{
	int select=0;
	
	cout << "count : " ;
	cin >> count;
	cout << "price : ";
	cout << "1 正常收费\t2 打八五折\t3满80减10\n";
	cin >> select;
	if(select==1)
	{
		ptr=new A;
	}
	else if(select==2)
	{
		ptr=new B(0.85);
	}
	else if(select==3)
	{
		ptr=new C(80,10);
	}
	else
	{
		cout << "select error\n";
		ptr=new A;
	}
	cout << "实际收费：";
	cout << ptr->fun(count*price) << endl;
}

int main()
{
	Shop s1;
	s1.start();
}

