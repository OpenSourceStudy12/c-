#include <iostream>
using namespace std;

//类型转换：(类型)表达式
//类型转换：static_cast<类型>(表达式)

class Test
{
public:
	int n=0;
	void f1(){ cout << __func__ << "  " << __LINE__ << endl; }
};

int main()
{
	int n=0;
	float f=12.3;
	//n=(int)f;
	n=static_cast<int>(f);
	cout << n << endl;
	
	int m=0;
	Test t1;
	int *p1=&m;
	Test *p2=&t1;
	//p2=(Test *)&m;
	p2=static_cast<Test *>(&m);


#if 0
	char str[]="asdff";
	cout << str << endl;
	cout << static_cast<void *>(str) << endl;
#endif
}
