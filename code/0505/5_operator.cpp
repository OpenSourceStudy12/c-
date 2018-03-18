#include <iostream>
using namespace std;

class Fraction
{
private:
	int fenzi;
	int fenmu;
public:
	//Fraction(int f1=0,int f2=1):fenzi(f1),fenmu(f2){}
	
	Fraction():fenzi(0),fenmu(1){}
	Fraction(int f1,int f2):fenzi(f1),fenmu(f2){}
	
	//转型构造函数
	Fraction(int f1)
	{
		fenzi=f1;
		fenmu=1;
		cout << "Fraction(int f1)\n";
	}
	
	~Fraction(){}
	void display()
	{
		cout << fenzi << "/" << fenmu;
	}
	
	//b/a+d/c=(b*c+a*d)/(a*c)
	Fraction operator+(Fraction f)
	{
		Fraction tmp;
		tmp.fenzi=fenzi*f.fenmu+fenmu*f.fenzi;
		tmp.fenmu=fenmu*f.fenmu;
		return tmp;
	}
	//1/2  ++  1/2+1   3/2
	Fraction operator++()
	{
		fenzi=fenzi+fenmu;
		return *this;
	}
	
	Fraction operator++(int n)
	{
		Fraction tmp=*this;
		fenzi=fenzi+fenmu;
		return tmp;
	}
	
	friend Fraction operator-(Fraction f1,Fraction f2);
	friend istream & operator>>(istream & in,Fraction & f1);
	friend ostream & operator<<(ostream & out,Fraction & f1);
};

//b/a-d/c=(b*c-a*d)/(a*c)
Fraction operator-(Fraction f1,Fraction f2)
{
	Fraction tmp;
	tmp.fenzi=f1.fenzi*f2.fenmu-f1.fenmu*f2.fenzi;
	tmp.fenmu=f1.fenmu*f2.fenmu;
	return tmp;
}

istream & operator>>(istream & in,Fraction & f1)
{
	cout << "fenzi : ";
	in >> f1.fenzi;
	cout << "fenmu : ";
	in >> f1.fenmu;
	return in;
}

ostream & operator<<(ostream & out,Fraction & f1)
{
	out << f1.fenzi << "/" << f1.fenmu ;
	return out;
}

int main()
{
#if 0
	Fraction f1(1,2);
	//Fraction f2=++f1;	  //f1=f1+1; f2=f1;
	Fraction f2=f1++;         //f2=f1;  f1=f1+1;
	
	cout << "f1 : " << f1 << endl;
	cout << "f2 : " << f2 << endl;
#endif
	
#if 0
	//int n1;
	//cin >> n1;
	//cout << n1 << endl;
	
	Fraction f1;
	cin >> f1;         //operator>>(cin,f1);
	cout << f1 << endl;      //operator(cout,f1);
#endif	
#if 1
	Fraction f1(1,2);
	//普通函数
	//对象-对象
	//对象-常量    必须存在对应的转型构造函数
	//常量-对象
	Fraction f3=f1-1;   //operator-(f1,1);
	Fraction f4=2-f1;     //operator-(2,f1);
	f3.display();
	cout << endl;
#endif
#if 0 
	Fraction f1(1,3);
	Fraction f2(1,2);
	//成员函数
	//对象+对象
	//对象+常量       必须存在对应的转型构造函数
	Fraction f3=f1+f2;    //f1.operator+(f2);
	Fraction f4=f2+f1;     //f2.opeartor+(f1)
	
	f3.display();
	cout << endl;
#endif
#if 0
	Fraction f1(1,3);
	f1.display();
	cout << endl;
	
	Fraction f2(1,4);
	f2.display();
	cout << endl;
	
	Fraction f3=f1+f2;      //Fraction f3=f1.operator+(f2)
	f3.display();
	cout << endl;
	
	f3=f1-f2;       //operator-(f1,f2);
	f3.display();
	cout << endl;
#endif
#if 0
	int n1=12;
	int n2=23;
	int sum=n1+n2;
#endif
}
