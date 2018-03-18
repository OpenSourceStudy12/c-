#include <iostream>
#include <cstring>
using namespace std;

class CString
{
private:
	int length;
	char *str;
public:
	CString()
	{
		length=100;
		str=new char[length];
		memset(str,'\0',length);
	}
	CString(const char *src)
	{
		length=strlen(src)+1;
		str=new char[length];
		strcpy(str,src);
	}
	CString(char ch)
	{
		length=100;
		str=new char[length];
		memset(str,'\0',length);
		str[0]=ch;
	}
	
	CString(CString & s1) //拷贝构造函数 深拷贝
	{
		length=s1.length;
		str=new char[length];
		strcpy(str,s1.str);
	}
	
	~CString()
	{
		delete [] str;
	}
	
	bool setString(const char *src)
	{
		if(length>=(strlen(src)+1))
		{
			strcpy(str,src);
			return true;
		}
		return false;	
	}	
	void display()
	{
		cout << "length : " << length << "  " << str << endl;
	}
};

int main()
{
	CString s1("asd");
	s1.display();
	
	if(s1.setString("zzasd"))
		s1.display();
	else
		cout << "error\n";
}


