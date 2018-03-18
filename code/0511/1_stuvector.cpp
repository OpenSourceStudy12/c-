#include <iostream>
#include <vector>
#include <algorithm> 
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
	
	bool checkNum(int n)
	{
		return num==n;
	}
	
	friend ostream & operator<<(ostream & out, Stu & s1);
	friend bool operator<(Stu & s1,Stu & s2);
	friend bool f3(Stu *s1,Stu *s2);
};

ostream & operator<<(ostream & out, Stu & s1)
{
	out << s1.num << "  " << s1.name << endl;
	return out;
}

void fun(Stu *s1)
{
	cout << "-------------------------\n";
	cout << *s1 << endl;
}

bool f1(int a,int b)
{
	return a>b;
}

bool operator<(Stu & s1,Stu & s2)
{
	return s1.num<s2.num;
}

bool f2(Stu *s1, Stu *s2)
{
	return (*s1)<(*s2);
}

bool f3(Stu *s1,Stu *s2)
{
	return s1->name<s2->name;
}

int main()
{

#if 1
	vector<Stu *> v1;
	
	v1.push_back(new Stu(1002,"qwe"));
	v1.push_back(new Stu(1008,"aaa"));
	v1.push_back(new Stu(1001,"ert"));
	v1.push_back(new Stu(1006,"zxc"));
	
	for(auto tmp : v1)
		cout << *tmp << endl;
	
	sort(v1.begin(),v1.end(),f3);
	
	for_each(v1.begin(),v1.end(),fun);
/*	
	int num;
	cin >> num;
	
	vector<Stu*>::iterator it=v1.begin();
	while(it!=v1.end())
	{
		if((*it)->checkNum(num))
		{
			Stu *tmp=*it;
			v1.erase(it);
			delete tmp;
			
			break;
		}
		it++;
	}
*/	
	
#endif

#if 0

	vector<int> v1={3,1,7,5,9};
	//sort(v1.begin(),v1.end());
	sort(v1.begin(),v1.end(),f1);
	for(auto tmp : v1)
		cout << tmp << "  ";
	cout << endl;		
#endif	

#if 0
	vector<Stu> v1;
	
	Stu s1(1001,"aaa");
	v1.push_back(s1);
	
	Stu s2(1002,"sss");
	v1.push_back(s2);
	
	for(auto tmp : v1)
	{
		cout << tmp << endl;
	}
#endif	
	
}
