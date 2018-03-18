#include <iostream>
#include <list>
using namespace std;

class Stu
{
private:
	int num;
	string name;
public:
	Stu(){ num=0; name="noname"; }
	Stu(int n,const string & str):num(n),name(str){}
	~Stu(){}
	
	int getNum()
	{
		return num;
	}
	
	bool checkNum(int n)
	{
		return num==n;
	}
	
	friend ostream & operator<<(ostream & out, Stu & s1);
};

ostream & operator<<(ostream & out, Stu & s1)
{
	out << s1.num << "  " << s1.name << endl;
	return out;
}

bool fun(Stu *s1,Stu *s2)
{
	return (s1->getNum())<(s2->getNum());
}

class Compare
{
private:
	static int count;
public:
	//Compare(int c=0):count(c){}
	
	bool operator()(Stu *s1,Stu *s2)
	{
		cout << count << endl;
		count++;
		return s1->getNum()<s2->getNum();
	}
};

int Compare::count=0;

int main()
{
	list<Stu *> s1;
	s1.push_back(new Stu(1001,"aaa"));
	s1.push_back(new Stu(1008,"qwe"));
	s1.push_back(new Stu(1005,"qwe"));
	s1.push_back(new Stu(1002,"qwe"));
	
	list<Stu *>::iterator it;
	for(it=s1.begin();it!=s1.end();it++)
	{
		cout << **it << endl;
	}
	
	//s1.sort(fun);
	Compare c1;         //函数对象
	s1.sort(c1);              
	for(auto tmp:s1)
		cout << *tmp << endl;
/*	
	int num=0;
	cin >> num;
	for(it=s1.begin();it!=s1.end();it++)
	{
		if((*it)->checkNum(num))
		{
			Stu *tmp=*it;
			s1.erase(it);
			delete tmp;
			break;
		}
	}
	
	for(auto tmp:s1)
		cout << *tmp << endl;
*/	
}
