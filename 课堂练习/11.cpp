/*
new:申请堆上的空间，是操作符 自动调用构造函数   malloc()是函数调用
delete:释放空间，是操作符 自动调用析构函数       free()是函数调用
 
int main()
{
	int *ptr = new int;
	*ptr = 123;
	cout<<*ptr<<endl;
	delete ptr;

	int *pt = new int[4];//申请数组空间16 byte
	delete []pt;  //释放数组空间
	
}

*/



#include<iostream>
using namespace std;

class S
{
	public:
		S()
		{
			cout<<__func__<<' '<<__LINE__<<endl;
		}
		~S()
		{
			cout<<__func__<<' '<<__LINE__<<endl;
		
		}

	//private:
		int i;
		int j;
};
int main()
{
	int *pt = new int;
	*pt = 123;
	cout<<*pt<<endl;
	delete pt;

	int *ptr = new int[5];
	int i;
	for(i=0;i<5;i++)
	{
		ptr[i] = (i+1)*10;
	}
	for(i=0;i<5;i++)
	{
		cout<<ptr[i]<<' ';
	}
	cout<<endl;
	delete []ptr;


	S *p = new S;
	p->i = 11;
	p->j = 23;
	cout<<p->i<<endl;
	cout<<p->j<<endl;
	//p->S();
	//p->~S();
	delete p;
}










