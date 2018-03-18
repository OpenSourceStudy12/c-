// c++ 文件后缀 .cpp

#include<iostream> //c++标准输入输出文件

#include<cstdio>   //调用c的标准输入输出文件

using namespace std;

int main(int argc,char **argv)
{
	cout<<"hello word"<<endl;

	cout<<argc<<endl;
	int i;
	for(i=0;i<argc;i++)
	{
		cout<<argv[i]<<endl;
	}
	printf("hello c\n");
	return 0;
}


