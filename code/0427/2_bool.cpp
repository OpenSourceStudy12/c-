#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool fun()
{
	char num[10];
	char psw[10];
	printf( "请输入帐号：");
	scanf("%s",num);
	printf("请输入密码：");
	scanf("%s",psw);
	if(strcmp(num,"1001")==0&&strcmp(psw,"111")==0)
		return true;
	else
		return false;
}

int main()
{
	//bool b1=fun();
	if(fun())
		printf("登录........\n");
	else
		printf("帐号或者密码错误\n");
	
	cout << sizeof(bool) << endl;
}
