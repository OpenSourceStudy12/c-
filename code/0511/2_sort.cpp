#include <iostream>
using namespace std;

bool f1(int a,int b)
{
	return a>b;
}

bool f2(int a,int b)
{
	return a<b;
}

void fun(int num[],int size,bool (*pfun)(int,int))
{
	int i=0;
	int j=0;
	int tmp=0;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			//if(num[j]>num[j+1])
			if(pfun(num[j],num[j+1]))
			{
				tmp=num[j];
				num[j]=num[j+1];
				num[j+1]=tmp;
			}
		}
	}
}

int main()
{
	int num[5]={6,1,8,3,5};
	//fun(num,5);
	
	//fun(num,5,f1);
	fun(num,5,f2);
	
	for(auto tmp:num)
		cout << tmp << "  ";
	cout << endl;	
}


