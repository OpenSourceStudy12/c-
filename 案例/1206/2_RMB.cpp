#include <iostream>
#include <sstream>
using namespace std;

class RMB
{
private:
	int yuan;
	int jiao;
	int fen;
public:
#if 1
	RMB():yuan(0),jiao(0),fen(0){}
	RMB(int y,int j,int f) { yuan=y; jiao=j; fen=f; }
	RMB(const RMB &r1){ yuan=r1.yuan; jiao=r1.jiao; fen=r1.fen; } // 拷贝构造函数
	RMB(const double f1) // 类型转换构造函数,将一个实型数据转换成人民币对象
	{
		stringstream s1;
		s1 << (f1*100);
		int num;
		s1 >> num;
		
		fen=num%10;
		jiao=num/10%10;
		yuan=num/100;
	}
	~RMB(){ cout << "析构函数被调用!" << endl; } // 析构函数
	
	friend ostream & operator<<(ostream& out, const RMB &r1); // 在屏幕上输出Rmb的值,输出格式如下: // 现在有: 元 角 分
	friend istream & operator>>(istream & in, RMB & r1);
	
	//(1)前自增运算符重载函数,要求实现对分自增1,并且考虑进位问题 
	//(2)后自增运算符重载函数,要求实现对分自增1,并且考虑进位问题 
	//(3)重载“+”运算符,要求实现下面两种加法运算
	RMB operator++()
	{
		fen=fen+1;
		if(fen>=10)
		{
			fen=fen-10;
			jiao=jiao+1;
			if(jiao>=10)
			{
				jiao=jiao-10;
				yuan=yuan+1;
			}
		}
		return *this;
	}
	
	RMB operator++(int i)
	{
		RMB tmp=*this;
		fen=fen+1;
		if(fen>=10)
		{
			fen=fen-10;
			jiao=jiao+1;
			if(jiao>=10)
			{
				jiao=jiao-10;
				yuan=yuan+1;
			}
		}
		return tmp;
	}
	
	friend RMB operator+(const RMB & r1,const RMB & r2);
	
#endif
};

ostream & operator<<(ostream& out, const RMB &r1)
{
	out <<"现在有 : " << r1.yuan << "元 " << r1.jiao << "角 " << r1.fen << "分" << endl;
	return out;
}
istream & operator>>(istream & in, RMB & r1)
{
	cout << "请输入： \n元 ：" ;
	in >> r1.yuan;
	cout << "角：";
	in >> r1.jiao;
	cout <<"分：";
	in >> r1.fen;
	return in;
}

RMB operator+(const RMB & r1,const RMB & r2)
{
	RMB tmp;
	tmp.fen=r1.fen+r2.fen;
	int flag=0;
	if(tmp.fen>=10)
	{
		tmp.fen=tmp.fen-10;
		flag=1;
	}
	
	tmp.jiao=r1.jiao+r2.jiao+flag;
	flag=0;
	if(tmp.jiao>=10)
	{
		tmp.jiao=tmp.jiao-10;
		flag=1;
	}
	
	tmp.yuan=r1.yuan+r2.yuan+flag;
	
	return tmp;	
}
void fn(const RMB& x) 
{
	cout<<"In fn: "<<x<<endl; 
}

int main() 
{
#if 0
	RMB m1; 
	cout<<m1<<endl<<endl<<endl;
	RMB m2(1001, 9, 9);
	RMB t1=++m2;
	cout<<"m2" << m2<<endl;
	cout<<"t1" << t1<<endl;
	++m2; 
	cout<<m2<<endl<<endl<<endl; 
#endif
	RMB m1;
	RMB m2(1001, 9, 9);
	RMB m3(m2); 
	cout<<m3<<endl<<endl<<endl;
	RMB m4=m1+m2;
	 cout<<m4<<endl; 
	 m4=m1+50.0; 
	cout<<m4<<endl<<endl<<endl;
	fn(50.13);
}
