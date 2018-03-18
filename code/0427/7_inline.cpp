#include <iostream>
using namespace std;

//内联函数: inline
//函数编译时，函数体替换函数调用
/*
1.函数体1-5行，函数功能简单
2.内联函数不能包含复杂结构，例如if-else for
3.
4.递归函数不能定义成内联函数
*/

//带参数宏定义
#define _MAX(x,y) x>y?x:y

inline int _max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	char name[20];
	cin >> name;     //scanf("%s",name);
	cout << name << endl;    //printf("%s\n",name);

#if 0
	int x=10;
	int y=11;
	int m=_max(x,y);     //int m=(x>y?x:y);
	cout << m << endl;
	
	int n=_MAX(12,45);    //int n=12>45?12:45
	cout << n << endl;
#endif
}
