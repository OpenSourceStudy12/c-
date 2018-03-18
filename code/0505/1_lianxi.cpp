#include <iostream>
using namespace std;

class Student
{
	int num;
	string name;
	float score;
	
	friend int main();
};

int main()
{
	Student s1;
	cout << "num : ";
	cin >> s1.num;
	cout << "name : ";
	cin >> s1.name;
	cout << "score : " ;
	cin >> s1.score;
	
	cout << s1.num << "  " << s1.name << "  " << s1.score << endl;
}
