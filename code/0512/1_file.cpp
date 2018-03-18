#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Stu
{
private:
	int num;
	string name;
	int c_score;
	int math_score;
public:
	Stu(int n=0,const string & str="noname",int c=0,int math=0):num(n),name(str),c_score(c),math_score(math){}
	~Stu(){}
	
	int getNum(){ return num; }
	string getName(){ return name; }
	int getC(){ return c_score; }
	int getMath(){ return math_score; }
	
	friend ostream & operator<<(ostream & out, Stu & s1);
	friend bool operator<(Stu & s1,Stu &s2);
};

ostream & operator<<(ostream & out, Stu & s1)
{
	out << s1.num << "  " << s1.name << "  " << s1.c_score << "  " << s1.math_score;
	return out;
}

class Com
{
private:
	int select;
public:
	Com():select(0){}
	Com(int s):select(s){}
	~Com(){}
	
	bool operator()(Stu *s1,Stu *s2)
	{
		switch(select)
		{
			case 0:
				return s1->getNum()<s2->getNum();
			case 1:
				return s1->getName()<s2->getName();
			case 2:
				return  s1->getC()>s2->getC();
			case 3:
				return s1->getMath()<s2->getMath();
		}
	}		
};

bool operator<(Stu & s1,Stu &s2)
{
	return s1.c_score<s2.c_score;
}

bool fun(Stu *s1,Stu *s2)
{
	return *s1<*s2;
}

class Test
{
private:
	string str;
public:
	Test(const string & s="noname"):str(s){}
	~Test(){}
	
	bool operator()(Stu *s1)
	{
		return str==s1->getName();
	}
};

int main()
{
	vector<Stu *> v1;
	v1.push_back(new Stu(1001,"wer",78,89));
	v1.push_back(new Stu(1006,"asd",71,69));
	v1.push_back(new Stu(1004,"wzxc",90,98));
	v1.push_back(new Stu(1003,"dfg",89,67));
	v1.push_back(new Stu(1008,"asc",88,60));
	
	for(auto tmp : v1)
	{
		cout << *tmp << endl;
	}
	
	cout << "\n\n---------------------------------\n";
	Com c1;
	sort(v1.begin(),v1.end(),c1);
	for(auto tmp : v1)
	{
		cout << *tmp << endl;
	}
	
	cout << "\n\n---------------------------------\n";
	Com c2(2);
	sort(v1.begin(),v1.end(),c2);
	for(auto tmp : v1)
	{
		cout << *tmp << endl;
	}
	
	cout << "\n\n---------------------------------\n";
	vector<Stu*>::iterator it;
	it=max_element(v1.begin(),v1.end(),fun);
	if(it!=v1.end())
	{
		cout << **it << endl;
	}
	
	cout << "\n\n---------------------------------\n";
	Test t1("aaa");
	it=find_if(v1.begin(),v1.end(),t1);
	if(it!=v1.end())
		cout << **it << endl;
	else
		cout << "no student\n";
	
	
}
