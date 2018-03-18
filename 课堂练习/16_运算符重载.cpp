/*
运算符重载: 1.运算符重载与原来运算符意义相近
	    2.运算符重载不会改变本质意义
	    3.不改变运算符优先级顺序

//成员函数
//对象 + - * / 对象
//对象 + - * / 常量(必须存在对应的转型构造函数)

//普通函数
//对象 + - * / 对象
//对象 + - * / 常量(存在转型构造函数)
//常量 + - * / 对象(存在转型构造函数)

class Fraction
{
private:
	int fz;
	int fm;
public:
	Fraction(int z=0,int m=1):fz(z),fm(m){}
	Fraction operator+(Fraction f)
	{
		Fraction temp;
		temp.fz = fz*f.fm+fm*f.fz;
		temp.fm = fm*f.fm;
		return temp;
	}
	friend ostream & operator<<(istream & out,Fraction & f1);
	friend istream & operator>>(istream & in,Fraction & f1);
};
 
cin 重载
istream & operator>>(istream & in,Fraction & f1)
{
	cout<<"fz:";
	in>>f1.fz;
	cout<<"fm:";
	in>>f1.fm;
	return in;
}

cout 重载
ostream & operator<<(istream & in,Fraction & f1)
{
	out<<f1.fz<<'/'<<f1.fm;
	return out;
}


int main()
{
	Fraction f1;
	cin>>f1;//operater(cin,f1)
	cout<<f1;  //operater(cout,f1)
}

*/


#include<iostream>
using namespace std;

class Fraction
{
private:
	int fz;
	int fm;
public:
	Fraction():fz(0),fm(1){}
	Fraction(int f1,int f2):fz(f1),fm(f2){}
	//Fraction(int z=0,int m=1):fz(z),fm(m){}

	//转型构造函数 将一个整数转换成一个对象
	Fraction(int k)
	{
		fz = k;
		fm = 1;
	}

	void Setfz(int m)
	{
		fz = m;
	}
	void Setfm(int m)
	{
		fm = m;
	}
	int getfz()
	{
		return fz;
	}
	int getfm()
	{
		return fm;
	}

	//运算符重载函数
	Fraction operator+(Fraction f)
	{
		Fraction temp;
		temp.fz = fz*f.fm+fm*f.fz;
		temp.fm = fm*f.fm;
		return temp;
	}
	Fraction operator-(Fraction f)
	{
		Fraction temp;
		temp.fz = fz*f.fm-fm*f.fz;
		temp.fm = fm*f.fm;
		return temp;
	}
	Fraction operator*(Fraction f)
	{
		Fraction temp;
		temp.fz = fz*f.fz;
		temp.fm = fm*f.fm;
		return temp;
	}
	int operator>(Fraction f)
	{
		int t = fz*f.fm - fm*f.fz;
		if(t>0)
			return 1;
		else if(t<0)
			return -1;
		else
			return 0;
	}
	//前置++ 重载
	Fraction operator++()
	{
		fz += fm;
		return *this;
	}
	//后置++ 重载
	Fraction operator++(int k)
	{
		Fraction temp = *this;
		fz += fm;
		return temp;
	}
	//=重载 系统会自动重载=，当类成员中有指针时，必须自己重载=。
	Fraction operator=(Fraction f1)
	{
		fz = f1.fz;
		fm = f1.fm;
	}



	void display()
	{
		cout<<'('<<fz<<'/'<<fm<<')';
	}

	friend istream & operator>>(istream & in,Fraction &f1);
	friend ostream & operator<<(ostream & out,Fraction &f1);
};
//通常使用友元函数
Fraction operator*(Fraction f1,Fraction f2)
{
	Fraction temp;
	temp.Setfz(f1.getfz()*f2.getfz());
	temp.Setfm(f1.getfm()*f2.getfm());
	return temp;
}

//通常使用友元函数
Fraction operator/(Fraction f1,Fraction f2)
{
	Fraction temp;
	temp.Setfz(f1.getfz()*f2.getfm());
	temp.Setfm(f1.getfm()*f2.getfz());
	return temp;
}

//cin 重载
istream & operator>>(istream & in,Fraction &f1)
{
	cout<<"fz:";
	in>>f1.fz;
	cout<<"fm";
	in>>f1.fm;
	return in;
}

//cout 重载
ostream & operator<<(ostream & out,Fraction &f1)
{
	out<<f1.fz<<'/'<<f1.fm<<endl;
	return out;
}



int main()
{ 
#if 1
	Fraction f1(1,2);
	//Fraction f2(2,3);
	Fraction f3;  // = f1 + f2; //Fraction f3 = f1.operator+(f2)
	f3 = operator*(2,3);  // f3 = f1.operator+(2)
	f1.display();
	cout<<'*';
	cout<<2;
	cout<<'=';
	f3.display();
	cout<<endl;

	Fraction f4;
	cin>>f4;
	cout<<f4;

	Fraction f5 = f4++;
	cout<<f4;
	cout<<f5;
	
	

#endif
#if 0

	//+重载
	Fraction f1(1,2);
	Fraction f2(2,3);
	Fraction f3 = f1 + f2; //Fraction f3 = f1.operator+(f2)
	f1.display();
	cout<<'+';
	f2.display();
	cout<<'=';
	f3.display();
	cout<<endl;
	
	//-重载
	f3 = f1 - f2;
	f1.display();
	cout<<'-';
	f2.display();
	cout<<'=';
	f3.display();
	cout<<endl;

	//*重载
/*	f3 = operator *(f1,f2);
	f1.display();
	cout<<'*';
	f2.display();
	cout<<'=';
	f3.display();
	cout<<endl;
*/
	//*重载
	f3 = f1 * f2;
	f1.display();
	cout<<'*';
	f2.display();
	cout<<'=';
	f3.display();
	cout<<endl;

	// /重载
	f3 = operator /(f1,f2);
	f1.display();
	cout<<'/';
	f2.display();
	cout<<'=';
	f3.display();
	cout<<endl;

	//关系重载
	int n = f1>f2;
	if(n>0)
	{
		f1.display();
		cout<<'>';
		f2.display();
		cout<<endl;
	}

	if(n<0)
	{
		f1.display();
		cout<<'<';
		f2.display();
		cout<<endl;
	}
	if(n==0)
	{
		f1.display();
		cout<<'=';
		f2.display();
		cout<<endl;
	}
	return 0;	
#endif

}







