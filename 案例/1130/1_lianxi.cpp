#include <iostream>

using namespace std;

int main()
{
	string str;
	char s1[20];
	int num[20];
	
	int i=0;
	int j=0;
	int k=0;
	bool flag=false;
	
	cin >> str;
	
	while(i<str.length())
	{
		if(str[i]>='a'&&str[i]<='z')
		{
			s1[j]=str[i];
			j++;
			flag=false;
		}
		if(str[i]>='0'&&str[i]<='9')
		{
			if(flag==true)
			{
				k--;
				num[k]=num[k]*10+(str[i]-'0');
				k++;
			}
			else
			{
				num[k]=str[i]-'0';
				k++;
			}
			flag=true;
		}
		i++;
	}
	s1[j]='\0';
	
	cout << s1 << endl;
	
	for(i=0;i<k;i++)
	{
		cout << num[i] << endl;
	}
	
	
}
