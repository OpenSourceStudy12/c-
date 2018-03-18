#include <iostream>
using namespace std;

void fun(string str,char ch[],int num[],int *n,int *m)
{
	int i=0;
	int size=str.size();
	*n=0;
	*m=0;
	while(i<size)
	{
		if(str[i]>='a'&&str[i]<='z')
		{
			ch[*n]=str[i];
			(*n)++;
			i++;
		}
		if(str[i]>='0'&&str[i]<='9')
		{
			num[*m]=str[i]-'0';
			i++;
			while(i<size)
			{
				if(str[i]>='0'&&str[i]<='9')
				{
					num[*m]=num[*m]*10+(str[i]-'0');
					i++;
				}
				else
					break;
			}
			(*m)++;
		}
	}
}

int main()
{
	string str;
	char ch[20];
	int num[20];
	cout << "str : ";
	cin >> str;
	
	int n=0;
	int m=0;
	fun(str,ch,num,&n,&m);
	
	int i=0;
	for(i=0;i<n;i++)
	{
		cout << ch[i] << "  " ;
	}
	cout << "\n";
	for(i=0;i<m;i++)
	{
		cout << num[i] << "  ";
	}
	cout << "\n";
	return 0;
}
