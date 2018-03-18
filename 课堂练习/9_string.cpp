/*
c字符串:
cin 同scanf 不能读取' ' ,
 
cin.getline可以读取' ',
格式cin.getline(数组指针,最大长度,'结束字符');重载函数

类同c中结构体,类中可以定义函数，结构体中不能定义函数


c++字符串:
string (字符串类型) 是c++库定义的一个类，每一个string变量都是一个对象
int main()
{
	string str1;
	cin>>sr1;         //不能读取' '
	getline(cin,str1);//可读取' '
	cout<<str1<<endl;

	string str2(str1); //根据str1创建str2,str2与str1内容一样

	string str3(5,'w'); //str3 = "wwwww"

	char s[20]="abc";
	string str4(s);    //用字符数组创建字符串 str4为"abc"

	str4[1] = 'z';   //string:通过下标遍历

	cout<<str4.size()<<endl; //求字符串长度 或用 length
	int i;
	fot(i=0;i<str4.size();i++) 
	{
		cout<<str4[i]<<endl;
	}

	//字符串赋值
	string str6;
	if(str6.empty())   //empty() 判断字符串是否为空
		cout<<"empty string\n";
	str6 = "qwe asd";  //字符串赋常量

	string str7 = str6;  //赋字符串变量

	//字符串链接
	string str8 = str6+str7;
	string s1 = "aaa";
	string s2 = "bbb";
	s1 = s1 + s2;// s1 += s2;//s1.append(s2);
	
	//字符串比较大小 < <= > >= == !=
	1.用compare() 比较字符串大小
	string s3 = "asd";
	string s4 = "123";
	cout<<s1.compare(s2)<<endl;// 大---1,小---(-1) 等---0
	2.或用关系运算比较大小
	if(s3==s4)
		cout<<"same"<<endl;
	else if(s3 > s4)
		cout<<"s3 > s4"<<endl;
	else
		cout<<"s3 < s4"<<endl;

	//交换两个字符串 swap()
	string s5 = "asd";
	string s6 = "qwe"
	s1.swap(s2);
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;
	
	//插入字符串 insert(int pos,string str) 在字符串pos位置插入str
	s1.insert(1,s2);

	//删除字符串 erase(int pos,int length) pos 起始位置 length 删除长度 默认位置0,长度 npos
	s1.erase(3,2); //从s1中下标为3位置开始删除长度位2的字符串

	//修改 replace(int pos,int length,string str);
	s1.replace(1,5,"ooo");

	//查找 find //查找成功返回子字符串位置，查找失败返回npos
	cout<<s1.find(ea)<<endl;



}	
  
*/

#include<iostream>

using namespace std;

int main()
{
/*	string str1 = "abc";
	cout<<"str1:"<<str1<<endl;

	string str2;
	cin>>str2;
	cout<<"str2:"<<str2<<endl;

	string str3(str1);
	cout<<"str3:"<<str3<<endl;
*/
/*
	string str4;
	getline(cin,str4);
	cout<<"str4:"<<str4<<endl;

	char ch[20]="132efdcv";
	string str5(ch);
	cout<<"str5:"<<str5<<endl;

	int i;
	cout<<"size(str5):"<<str5.size()<<endl;
	for(i=0;i<str5.size();i++)
	{
		cout<<str5[i]<<endl;
	}

	char sh[20];
	cin.getline(sh,20);
	cout<<sh<<endl;
*/

	string s1 = "abc";
	string s2 = "h34242342";
	/*字符串链接*/
	//string s3 = s1 +s2;
	//cout<<"s3 = "<<s3<<endl;
	//s1 += s2;
	//cout<<"s1 = "<<s1<<endl;
	//s2 = s1;
	//cout<<"s2 = "<<s2<<endl;
//	s2.append(s1);
//	cout<<"s2 = "<<s2<<endl;
	/************************/
	/*字符串比较大小*/
	//int k;
	//s1=s2;
	//k = s1.compare(s2);
	//cout<<"k = "<<k<<endl;
	s1=s2;
	if(s1 > s2)
		cout<<"s1>s2"<<endl;
	else if(s1 < s2)
		cout<<"s1 < s2"<<endl;
	else
		cout<<"s1 == s2"<<endl;
	/*******************************/


	char t1[10];
	string t2;
	cin.getline(t1,10);
	getline(cin,t2);
	cout<<"t1[] = "<<t1<<endl;
	cout<<"t2 = "<<t2<<endl;

}





























