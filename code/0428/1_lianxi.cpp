#include <iostream>
using namespace std;

#define LEN 20
#define SIZE 4

struct stu
{
	int num;
	char name[LEN];
};

void set_data(struct stu & s1)
{
	cout << "num : ";
	cin >> s1.num;
	cout << "name : " ;
	cin >> s1.name;
}

void display(const struct stu & s1)
{
	cout << s1.num << "\t\t" << s1.name << endl;
}

int main()
{
	struct stu s[SIZE];
	int i=0;
	for(i=0;i<SIZE;i++)
	{
		cout << "请输入第" << i+1 << "个学生的学号：";
		cin >> s[i].num;
		cout << "请输入第" << i+1 << "个学生的姓名：";
		cin >> s[i].name;
	}
	
	cout << "num\t\tname\n"; 
	for(i=0;i<SIZE;i++)
	{
		cout << s[i].num << "\t\t" << s[i].name << endl;
	}
	
	set_data(s[1]);
	display(s[1]);
	
	return 0;
}
