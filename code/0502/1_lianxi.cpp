#include <iostream>
using namespace std;

struct Stu
{
	int num;
	string name;
};

void fun(struct Stu s[],int cnt)
{
	int i=0;
	for(i=0;i<cnt;i++)
	{
		cout << "num : " ;
		cin >> s[i].num;
		cout << "name : " ;
		cin >> s[i].name;
	}
}

void display(struct Stu s[],int cnt)
{
	int i=0;
	cout << "num\tname\n";
	for(i=0;i<cnt;i++)
	{
		cout << s[i].num << "\t" << s[i].name << endl;
	}
}

int findByName(struct Stu s[],int cnt)
{
	string str;
	cout << "name : " ;
	cin >> str;
	int i=0;
	for(i=0;i<cnt;i++)
	{
		if(s[i].name==str)
			return i;
	}
	return -1;
}

int main()
{
	struct Stu s[3];
	fun(s,3);
	display(s,3);
	int result=findByName(s,3);
	if(result!=-1)
		cout << s[result].num << "\t" << s[result].name << endl;
	else
		cout << "no student\n";
	return 0;	
}
