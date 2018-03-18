#include <iostream>
#include <cstdlib>
using namespace std;

//new: 申请空间，空间在堆上，操作符, 自动调用构造函数
//delete：释放空间，操作符， 自动调用析构函数

class Test
{
public:
	Test(){ cout << __func__ << "  " << __LINE__ << endl; }
	~Test(){ cout << __func__ << "  " << __LINE__ << endl; }
};

int main()
{
	//Test *p1=(Test*)malloc(sizeof(Test));
	//free(p1);
	
	Test *p2=new Test;
	delete p2;

#if 0
	int *ptr=new int;
	*ptr=123;
	cout << *ptr << endl;
	delete ptr;
	
	int *num=new int[4];
	int i=0;
	for(i=0;i<4;i++)
	{
		num[i]=i;
		cout << num[i] << "  ";
	}
	cout << endl;
	delete[] num;
#endif
/*
	int *ptr=(int *)malloc(sizeof(int));
	*ptr=123;
	free(ptr);
	
	int *num=(int *)malloc(sizeof(int)*4);
	int i=0;
	for(i=0;i<4;i++)
		num[i]=(i+1)*10;
	for(i=0;i<4;i++)
		cout << num[i] << "  ";
	cout << endl;
	free(num);
*/
}
