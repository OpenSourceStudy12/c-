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
	RMB():yuan(0),jiao(0),fen(0){}
	RMB(int y,int j,int f):yuan(y),jiao(j),fen(f){}
	RMB(const RMB & r1){ yuan=r1.yuan; jiao=r1.jiao; fen=r1.fen; }//拷贝构造函数
	RMB(double d1)//转型构造函数	
	{
		stringstream ss;
		ss << (d1*100);
		int num;
		ss >> num;
		yuan=num/100;
		jiao=num%100/10;
		fen=num%10;
	}
	~RMB(){}
	
	RMB operator++()
	{
		fen++;
		if(fen>=10)
		{
			fen=fen-10;
			jiao++;
			if(jiao>=10)
			{
				jiao=jiao-10;
				yuan++;
			}
		}
		return *this;
	}
	RMB operator++(int n)
	{
		RMB tmp=*this;
		fen++;
		if(fen>=10)
		{
			fen=fen-10;
			jiao++;
			if(jiao>=10)
			{
				jiao=jiao-10;
				yuan++;
			}
		}
		return tmp;
	}
	
	RMB operator+(const RMB & r1)
	{
		RMB tmp;
		int flag=0;
		tmp.fen=fen+r1.fen;
		if(tmp.fen>=10)
		{
			tmp.fen=tmp.fen-10;
			flag=1;
		}
		tmp.jiao=jiao+r1.jiao+flag;
		flag=0;
		if(tmp.jiao>=10)
		{
			tmp.jiao=tmp.jiao-10;
			flag=1;
		}
		tmp.yuan=yuan+r1.yuan+flag;
		return tmp;
	}
	
	
	friend ostream & operator<<(ostream& out, const RMB &);
};

ostream & operator<<(ostream& out, const RMB & r1)
{
	out << "现在有 : " << r1.yuan << "元" << r1.jiao << "角" << r1.fen << "分";
	return out;
}
void fn(const RMB & x) 
{
	cout<<"In fn: "<<x<<endl; 
}

int main()
{
	RMB m1; cout<<m1<<endl<<endl<<endl;
	RMB m2(1001, 9, 9);
	m2++;
	cout<<m2<<endl;
	++m2; 
	cout<<m2<<endl<<endl<<endl;
	RMB m3(m2); cout<<m3<<endl<<endl<<endl;
	RMB m4=m1+m2; cout<<m4<<endl; 
	m4=m1+50.0; cout<<m4<<endl<<endl<<endl;
	fn(50.13); 
}







