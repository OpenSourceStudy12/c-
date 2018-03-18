#if 0

[构造函数,拷贝构造,析构函数,浅拷贝和深拷贝]类定义：
class CString {
char * m_pbuff; //指向字符串的指针
int m_length; //表示当前字符串的最大允许长度,也就是字符数组的长度 
public:
CString(); //构造函数1,设置为空字符串,m_length=100
CString(char *src); //构造函数2,在考虑了src的长度后初始化当前对象, m_length>=src的长度+1
CString(char ch); //构造函数3,0号元素赋值为ch, m_length=100
int SetString(char *src); //设置字符串,在考虑了src的长度后设置当前对 象,m_length>=src的长度+1
};
请编写程序实现如下功能:
􏰀 为其中的每个成员函数给出实现代码;
􏰀 自行根据需要决定是否需要添加拷贝构造函数和析构函数;

#endif

#include <iostream>
#include <cstring>
using namespace std;

class CString
{
private:
	char *buf;
	int length;
public:
	CString()
	{
		length=100;
		buf=new char[length];
		buf[0]='\0';
	}
	
	CString(char *str)
	{
		if(strlen(str)<100)
			length=100;
		else
			length=strlen(str)+1;
		
		buf=new char[length];
		strcpy(buf,str);
	}
	
	CString(char ch)
	{
		length=100;
		buf=new char[length];
		buf[0]=ch;
		buf[1]='\0';
	}
	
	CString(CString & s1)
	{
		length=s1.length;
		buf=new char[length];
		strcpy(buf,s1.buf);
	}
	
	~CString()
	{
		cout << "~CString()\n";
		delete[] buf;
	}
	
	int SetString(char *src)
	{
		if(strlen(src)<100)
		{
			strcpy(buf,src);
			return 0;
		}
		return -1;
	}
	
	void display()
	{
		cout << length << " : " << buf << endl;
	}
};

int main()
{
	char str[]="hello world";
	
	CString s1;
	s1.display();
	
	CString s2(str);
	s2.display();
	
	CString s3('a');
	s3.display();
	
	CString s4(s2);
	cout << "S4 : " ;
	s4.display(); 
	
	char str1[]="asdf";
	s4.SetString(str1);
	s4.display(); 
}
