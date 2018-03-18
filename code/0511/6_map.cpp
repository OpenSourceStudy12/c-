#include<iostream>
#include<map>
#include <vector>
using namespace std;

//map:字典  键-值 对

class Stu
{
private:
	int num;
	string name;
public:
	Stu(int n=0,const string & str="noname"):num(n),name(str){}
	~Stu(){}
	
	friend ostream & operator<<(ostream & out, Stu & s1);
};

ostream & operator<<(ostream & out, Stu & s1)
{
	out << s1.num << "  " << s1.name;
	return out;
}

int main()
{
#if 0
	vector<Stu *> v1;
	v1.push_back(new Stu(1001,"aaa"));
	v1.push_back(new Stu(1002,"asd"));
	v1.push_back(new Stu(1003,"qwe"));
	
	vector<Stu *> v2;
	v2.push_back(new Stu(2001,"aaa"));
	v2.push_back(new Stu(2002,"asd"));
	v2.push_back(new Stu(2003,"qwe"));
	
	map<string,vector<Stu *>*> m1;
	m1["grade1"]=&v1;
	m1["grade2"]=&v2;
	
	map<string,vector<Stu*>*>::iterator it;
	for(it=m1.begin();it!=m1.end();it++)
	{
		cout << it->first << " : " << endl;
		vector<Stu *> *tmp=it->second;
		for(auto t1 : *tmp)
			cout << *t1 << endl;
		cout << endl;
	}
#endif

#if 0
	vector<Stu *> v1;
	v1.push_back(new Stu(1001,"aaa"));
	v1.push_back(new Stu(1002,"asd"));
	v1.push_back(new Stu(1003,"qwe"));
	
	vector<Stu *> v2;
	v2.push_back(new Stu(2001,"aaa"));
	v2.push_back(new Stu(2002,"asd"));
	v2.push_back(new Stu(2003,"qwe"));
	
	map<string,vector<Stu *>> m1;
	m1["grade1"]=v1;
	m1["grade2"]=v2;
	
	map<string,vector<Stu*>>::iterator it;
	for(it=m1.begin();it!=m1.end();it++)
	{
		cout << it->first << " : " << endl;
		vector<Stu *> tmp=it->second;
		for(auto t1 : tmp)
			cout << *t1 << endl;
		cout << endl;
	}
#endif	




#if 1
	map<string,string> m1;
	
	m1["shanghai"]="shanghai";
	m1["jiangsu"]="nanjing";
	m1["anhui"]="hefei";
	
	m1.insert(pair<string,string>("jiangxi","nanchang"));
	
	m1["jiangsu"]="suzhou";
	
	map<string,string>::iterator it;
	for(it=m1.begin();it!=m1.end();it++)
	{
		cout << it->first << "  " << it->second << endl;
	}
	
	for(auto tmp:m1)
		cout << tmp.first << "  " << tmp.second << endl ;
	
	cout << m1.size() << endl;
	
	it=m1.find("jiangsu");
	if(it!=m1.end())
		cout << it->first << "  " << it->second << endl;
	else
		cout << "查找失败\n";
#endif	
	
	
}
