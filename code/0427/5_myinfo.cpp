#include<iostream>
using namespace std;

int main(int argc,char* argv[])
{
	int age;
	cout << "请输入年龄：";
	cin >> age;
	 
	if(argc>=2)
		cout << "my name is " << argv[1];
	else
		cout << "my name is secret";
	cout << ", " << age << " years old\n";

	return 0;
}
