#include <iostream>
using namespace std;

class Stu
{
private:
	int num;
	string name;
	static int cnt;
public:
	//static int cnt;

	Stu(int n=0,const string & str="nonmae"):num(n),name(str)
	{
		cnt++;
	}
	~Stu(){}
	void display()
	{
		cout << num << "  " << name << endl;
	}
	
	//静态成员函数:只能访问静态成员变量
	static int getCnt()
	{
		return cnt;
	}
};

//*****
//静态成员变量初始化
int Stu::cnt=0;

int main()
{
	Stu *s1=new Stu(1001,"aaa");
	cout << s1->getCnt() << endl;
	
	cout << Stu::getCnt() << endl;
	
	Stu *s2=new Stu(1002,"ssss");
	cout << s1->getCnt() << "  " << s2->getCnt() << "  " << Stu::getCnt() << endl;

#if 0
	Stu *s1=new Stu(1001,"asd");
	Stu *s2=new Stu(1002,"qwe");
	
	cout << s1->cnt << "  " << s2->cnt << "  " << Stu::cnt << endl;
	
	Stu *s3=new Stu(1003,"zxc");
	cout << s1->cnt << "  " << s2->cnt << "  " << s3->cnt << " " << Stu::cnt << endl;
#endif	
}


