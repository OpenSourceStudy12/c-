#include <iostream>
#include <fstream> 
#include <vector>
using namespace std;

struct stu
{
	int num;
	string name;
};

ostream & operator<<(ostream & out, stu & s1)
{
	out << s1.num << "\t" << s1.name;
	return out;
}

int main()
{
	vector<stu> v1={{1001,"aaa"},{1002,"qwe"}};
	ofstream out("stu1.txt",ios::out);
	
	for(int i=0;i<v1.size();i++)
		out << v1[i] << endl;
		//out << v1[i].num << "\t" << v1[i].name << endl;
	
	out.close();


#if 0
	int num[4]={0};
	ifstream in("data.txt",ios::in);
	int i=0;
	for(i=0;i<4;i++)
		in >> num[i];
	for(i=0;i<4;i++)
		cout << num[i] << "  ";
	cout << endl; 
	
	in.close();
#endif
#if 0
	//写文本文件
	int num[]={3,6,1,4};
	ofstream out("data.txt",ios::out);      //以写的方式打开文件
	
	int i=0;
	for(i=0;i<4;i++)
	{
		out << num[i] << endl;
	}
	
	out.close();       //关闭文件
#endif
}
