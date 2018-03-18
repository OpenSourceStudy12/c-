#include<iostream>
#include<cstring>
using namespace std;

class CString
{
	private:
		char *pbuff;
		int length;
	public:
		CString();
		CString(const char *src);
		CString(char ch);
		CString(const CString &s);
		~CString()
		{
			delete pbuff;
		}
		bool SetString(const char *src);
		void display();
};

CString::CString()
{
	length = 100;
	pbuff = new char[length];
	//pbuff[0] = '\0';
	memset(pbuff,'\0',length);
}

CString::CString(const char *src)
{
	length = strlen(src)+1;
	pbuff = new char[length];
	strcpy(pbuff,src);
}

CString::CString(char ch)
{
	length = 100;
	pbuff = new char[length];
	memset(pbuff,'\0',length);
	pbuff[0] = ch;
}

CString::CString(const CString &s)
{
	length = s.length;
	pbuff = new char[length];
	strcpy(pbuff,s.pbuff);
}

bool CString::SetString(const char *src)
{
	if(length < strlen(src)+1)
	{
	/*
		length = strlen(src)+1;
		delete pbuff;
		pbuff = new char[length];
		strcpy(pbuff,src);	
	*/
		return false;
	}
	else
	{
		strcpy(pbuff,src);
		return true;
	}
}

void CString::display()
{
	int i=0;
	while(pbuff[i] != '\0')
	{
		cout<<pbuff[i++]<<' ';
	}
	cout<<endl;
}


int main()
{
	CString s1;
	s1.display();
	cout<<endl;

	CString s2("1234567890");
	s2.display();
	cout<<endl;

	CString s3('L');
	s3.display();
	cout<<endl;

	int t = s2.SetString("qwe asd zxc");
	if(t)
		s2.display();
	else
		cout<<"输入的字符串过长！\n";
	cout<<endl;

	CString s4(s3);
	s4.display();
}


