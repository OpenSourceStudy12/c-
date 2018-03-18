#include<iostream>

using namespace std;

int separate(string &re_str,int *num)
{
	int i,j,sum;
	for(i=0,j=0;i<re_str.size();i++)
	{
		sum = 0;
		if(re_str[i] >= '0' && re_str[i] <= '9')
		{
			while(re_str[i] >= '0' && re_str[i] <= '9')
			{
				sum = sum*10+re_str[i]-'0';
				re_str.erase(i,1);
			}
			num[j++] = sum;
		}
	}
	return j;
	//re_str1[j] = '\0';
	//re_str2[k] = '\0';
}

void sort(string &s)
{
	int i,j,flag;
	char ch;
	for(i=0;i<s.size()-1;i++)
	{
		flag = 0;
		for(j=0;j<s.size()-1-i;j++)
		{
			if(s[j] > s[j+1])
			{
				ch = s[j];		
				s[j] = s[j+1];
				s[j+1] = ch;
				flag = 1;
			}
		}
		if(!flag)
			break;
	}
}

void sort( int *num,int n)
{
	int i,j,flag;
	int temp;
	for(i=0;i<n-1;i++)
	{
		flag = 0;
		for(j=0;j<n-1-i;j++)
		{
			if(num[j] > num[j+1])
			{
				temp = num[j];		
				num[j] = num[j+1];
				num[j+1] = temp;
				flag = 1;
			}
		}
		if(!flag)
			break;
	}
}

void display(string str)
{
	int i;
	for(i=0;i<str.size();i++)
	{
		cout<<' '<<str[i]<<' ';
	}
	cout<<endl;

}

void display(int num[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<' '<<num[i]<<' ';
	}
	cout<<endl;

}


int main()
{
	string str;
	int num[20],n;
	//str1 = "djkhJKGkeh";
	//str2 = "3245657346";
	cout<<"str = ";
	getline(cin,str);
	n = separate(str,num);
	sort(str);
	sort(num,n);
	display(str);
	display(num,n);
	return 0;
}
