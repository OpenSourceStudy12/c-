#include <iostream>

using namespace std;

class Com
{
private:
	int real;
	int imag;
public:
	Com(int r=0,int i=0):real(r),imag(i){}
	
	//Com(){ real=0; imag=0; }
	//Com(int r){ real=r; imag=0; }        //转型构造函数
	//Com(int r,int i){ real=r; imag=0; }
	
	void display()
	{
		cout << real << "+i" << imag << endl;
	}
	
	//运算符重载
	//意义不变
	//不改变运算符优先级
	//不改变运算符的属性
	Com operator+(const Com & c1)
	{
		Com tmp;
		tmp.real=this->real+c1.real;
		tmp.imag=imag+c1.imag;
		return tmp;
	}
	
	Com operator-(Com & c1)
	{
		Com tmp;
		tmp.real=real-c1.real;
		tmp.imag=imag-c1.imag;
		return tmp;
	}
	
	friend Com operator*(const Com & c1,const Com & c2);
	friend istream & operator>>(istream & in, Com & c1);
	friend ostream & operator<<(ostream & out, Com & c1);
	
	Com operator++()       //++i;     
	{
		real=real+1;
		imag=imag+1;
		return *this;
	}
	
	Com operator++(int i)              //i++
	{
		Com tmp=*this;
		real=real+1;
		imag=imag+1;
		return tmp;
	}
};

//将运算符重载函数定义成顶层函数
//成员函数：左边操作数必须是对象，右边操作数可以是对象也可以是常量（必须存在对应的转型构造函数），
//顶层函数：一个操作数是对象，另外一个操作数可以是对象也可以是常量，
Com operator*(const Com & c1,const Com & c2)
{
	Com tmp;
	tmp.real=c1.real*c2.real;
	tmp.imag=c1.imag*c2.imag;
	return tmp;
}

//重载输入和输出运算符
istream & operator>>(istream & in, Com & c1)
{
	in >> c1.real >> c1.imag;
	return in;
}

ostream & operator<<(ostream & out, Com & c1)
{
	//out << c1.real << "+i" << c1.imag;
	out << "real : " << c1.real << "\timag : " << c1.imag ;
	return out;
}


int main()
{
	int num;
	int n3=num;
	int n1=num++;
	int n2=++num;
	//cin >> num;
	//cout << num << endl;
	
	Com c1;
	cin >> c1;
	cout << c1 << endl;
	
	Com c2=c1;      //
	cout << c2 << endl;
	
	//++c1;
	//c1.display();
	
	//Com c2=c1++;
	//c1.display();
	//c2.display();


#if 0
	Com c1(2,6);
	c1.display();
	
	Com c2(3,4);
	c2.display();
	
	Com tmp=c1+c2;       //c1+c2  ---->     c1.operator+(c2);
	tmp.display();
	
	Com t=c1-c2;        //c1-c2    ------->     c1.operator-(c2);
	t.display();
	
	Com t1=c1+12;     //   c1.operator+(12)
	t1.display();
	
	//12+c1;           //12.operator+(c1);
	
	Com t2=c1*c2;     //operator*(c1,c2);
	t2.display();
	
	//Com t3=c1*2;
	Com t3=2*c1;      //operator(2,c1);
	 t3.display(); 
	
	int n1=23;
	int n2=12;
	int sum=n2+n1;
#endif
}
