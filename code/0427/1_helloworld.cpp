//源码后缀：.cpp

//g++ 文件名
//g++ 文件名 -o 可执行文件名

//头文件：c语言头文件后缀  .h
//                c++语言头文件没有后缀

#include <iostream>
#include <cstdio>

using namespace std;

//argc：参数的个数
//argv数组：参数的名称
int main(int argc,char *argv[])
{
	cout << "hello world" << endl;
	
	printf("hello C++\n");
	
	cout << argc << endl;
	int i=0;
	for(i=0;i<argc;i++)
	{
		cout << argv[i] << endl;
	}
	
	return 0;
}
