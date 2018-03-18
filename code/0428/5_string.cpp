#include <iostream>
using namespace std;

int main()
{
#if 1
	string s1="qweasd";
	string s2="zxc";
	
	s1.insert(1,s2);    //insert(int pos,string s): 在字符串里从pos位置插入字符串s
	
	cout << s1 << endl;
	//s1.erase(3,2);        //erase() : 删除，第一个参数是删除的起始位置，第二个参数是删除的长度
	
	s1.replace(1,4,"ooo");    //replace: 修改
	
	cout << s1.find("ea",4) << endl;   //npos    //find(): 查找子字符串，查找成功，返回子字符串的起始下标，否则，返回npos;
	
	
	cout << s1 << endl;
	
	
	
	/*
	s1.swap(s2);      //swap(): 交换字符串
	cout << "after swap : " << endl;
	cout << "s1 : " << s1 << endl;
	cout << "s2 : " << s2 << endl;
	*/
	
#endif
#if 0
	string s1="asd";
	string s2="asd";
	
	cout << s2.compare(s1) << endl;     //compare(): 比较字符串大小
	
	//> >= < <= == !=
	if(s1==s2)
		cout << "same\n" ;
	else if(s1>s2)
		cout << "s1>s2\n";
	else
		cout << "s2>s1\n";
#endif	

#if 0
	string s1;
	if(s1.empty())         //empty(): 判断字符串是否为空
		cout << "empty string\n";
	
	s1="qwe asd";         //= 赋值
	cout << s1 << endl;
	cout << s1.size() << endl;
	
	string s2;
	s2=s1;
	cout << "s2 : " << s2 << endl;
	
	string s3;
	s3=s1+s2;       //+ 
	cout << s3 << endl;
	
	string str1="abc";
	string str2="qwe";
	//str1=str1+str2;
	//str1+=str2;       //str1=str1+str2;
	str1.append(str2);  //追加
	cout << str1 << endl;
#endif	
	
	

#if 0
	string str1;
	cin >> str1;
	
	string str2(str1);
	cout << "str2 : " << str2 << endl;
	
	string str3(5,'w');
	cout << str3 << endl;
	
	char s[20]="abc";
	string str4(s);
	cout << str4 << endl;      //"abc"
	
	str4[1]='z';        //string : 通过下标遍历
	cout << str4 << endl;
	
	cout << str4.size() << endl;     //size(): 计算字符串的长度
	
	int i=0;
	for(i=0;i<str4.size();i++)
	{
		cout << str4[i] << endl;
	}
#endif	
	
	

#if 0
//输入和输出
	string str1;
	//cin >> str1;      //不接受空格
	
	getline(cin,str1);   //可包含空格
	cout << str1 << endl;
#endif	

#if 0
	char str[20];
	//cin >> str;
	//cout << str << endl;
	
	cin.getline(str,20);
	cout << str << endl;
#endif
}
