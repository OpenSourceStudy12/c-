#include <iostream>
#include <cstring>
using namespace std;

class Stu
{
private:
	int num;
	char *name;
public:
	Stu()
	{
		num=0;
		name=new char[20];
		memset(name,'\0',20);
	}
	Stu(int n,const char *str)
	{
		num=n;
		name=new char[20];
		strcpy(name,str);
	}
	~Stu(){ delete [] name; }
	
	void display()
	{
		cout << num << "  " << name << endl;
	}
	
	void setName(const char *str)
	{
		strcpy(name,str);
	}
	
	void operator=(Stu & s1)
	{
		num=s1.num;
		strcpy(name,s1.name);
	}
	
	/*
	void operator=(Stu & s1)
	{
		num=s1.num;
		name=s1.name;
	}*/
};

int main()
{
	Stu s1(1001,"aaa");
	s1.display();
	
	Stu s2;
	s2=s1;
	
	s2.display();
	
	s1.setName("abc");
	s1.display();
	s2.display();
}

#if 0
class Fraction
{
private:
	int fenzi;
	int fenmu;
public:
	Fraction(int f1=0,int f2=1):fenzi(f1),fenmu(f2){}
	~Fraction(){}	
	void display()
	{
		cout << fenzi << "/" << fenmu << endl;
	}

	void operator=(Fraction f1)
	{
		fenzi=f1.fenzi;
		fenmu=f1.fenmu;
		cout << __func__ << "  " << __LINE__ << endl;
	}

};


int main()
{
	Fraction f1(1,2);
	Fraction f2;
	
	f2=f1;      //f2.operator(f1);
	
	f1.display();
	f2.display();
	
}

#endif
