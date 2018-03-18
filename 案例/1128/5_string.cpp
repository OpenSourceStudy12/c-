#include <iostream>
using namespace std;

int main()
{
	string s1="asdf";
	string s2="df";
	
	s1.erase(1,2);     //erase  删除
	cout << s1 << endl;
	
	//s1.replace(0,3,"xyzabc");    //replace : 替换
	//cout << s1 << endl;
		
#if 0	
	s1.insert(0,s2);       //插入子字符串
	cout << s1 << endl;	
		
	cout << "s1=" << s1 << endl;
	cout << "s2=" << s2 << endl;
	s1.swap(s2);      //交换两个字符串
	cout << "after swap:\n";
	cout << "s1=" << s1 << endl;
	cout << "s2=" << s2 << endl;

	cout << s1.find(s2,3) << endl;    //find 查找子字符串，返回值为子字符串的起始下标
	
	string s3=s1.substr(2);
	cout << "s3=" << s3 <<endl;
	
	string s4=s1.substr(1,2);       //查找子字符串
	cout << "s4=" << s4 <<endl;
#endif	
	

#if 0
	string s1="asdf";
	int i=0;
	int len=s1.length();
	for(i=0;i<len;i++)
	{
		cout << s1[i] << endl;
	}
	s1[2]='x';     //asxf
	cout << s1 << endl;
#endif	
	


#if 0
	string s1="aaa";
	string s2="abc";
	string s3=s1+s2;
	cout << s3 << endl;
	
	if(s1.empty())    //empty 判断字符串是否为空
		cout << "empty string\n";
	else
		cout << "s1=" << s1 << endl;
		
	cout << s2.length() << endl;   //length  计算字符串的长度
	
	if(s1.compare(s2)==0)
	{
		cout << "s1==s2" << endl;
	}
	else
	{
		cout << "s1!=s2" << endl;
	}
	
	if(s1==s2)
	{
		cout << "s1==s2" << endl;
	}
	else if(s1>s2)
	{
		cout << "s1>s2" << endl;
	}
	else if(s2>s1)
	{
		cout << "s2>s1" << endl;
	}
#endif		

#if 0
	string s1;
	s1="hello world";
	cout << s1 << endl;
	
	string s2(s1);      //string s2;   s2=s1;    //string s2=s1;
	cout << s2 << endl;
	
	string s3,s4;
	s3="aaa";
	s4=s3;
	cout << s3 << endl;
	cout << s4 << endl;

	string s5(s1,6,4);
	cout << s5 << endl;
	
	string s6(5,'n');
	cout << s6 << endl;
	
	string s7;
	getline(cin,s7);
	//cin >> s7;
	cout << s7 << endl;
#endif

/*
	char str[20];
	cin.getline(str,20);
	cout << str << endl;
	//cin >> str;
	//cout << str << endl;
	*/
}
