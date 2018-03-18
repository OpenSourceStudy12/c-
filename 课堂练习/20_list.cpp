#if 0
#include<iostream>
#include<list>
using namespace std;

bool fun(int x,int y)
{
	return (x>y);
}

int main()
{
	list<int>s1;
	if(s1.empty())
		cout<<"null..";
	s1.push_front(2); // 2
	s1.push_front(5); // 5 2
	s1.push_back(7); // 5 2 7

	list<int>::iterator it;
	for(it=s1.begin();it!=s1.end();it++)
	{
		cout<<*it<<' ';
	}
	
	it=s1.begin();
	insert(it,6); // 6 5 2 7
	insert(it,2,13); // 6 5 13 2 7
	for(auto tmp:s1)
		cout<<s1;

/*	advance(it,2); //it向后移动2 list中 it不能直接+,
	
	s1.pop_front(); //5 13 2 7
	s2.pop_back(); // 5 13 2

	s1.erase(it); //5 13
*/

	s1.sort(); //默认升序排序
	s2.sort(fun);
}
#endif

#include<iostream>
#include<list>
#include<cstdlib>
#include<cstdio>
#include<unistd.h>
#include<algorithm>
using namespace std;

#define ADD    1
#define MOD    2
#define SEARCH 3
#define PRINT  4
#define DEL    5
#define EXIT   0

class Stu
{
private:
	int num;
	string name;
	float score;
public:
	Stu(int num=0,const string &name="no name",float score=0):num(num),name(name),score(score){}
	int getNum();
	friend istream & operator>>(istream &,Stu &);
	friend ostream & operator<<(ostream &,Stu &);
	bool operator<(Stu *);
	bool operator>(Stu *);
	~Stu(){}
};

int Stu::getNum()
{
	return num;
}

istream &operator>>(istream &in,Stu &s)
{
	cout<<"num:";
	in>>s.num;
	cout<<"name:";
	in>>s.name;
	cout<<"score:";
	in>>s.score;
	return in;
}

ostream &operator<<(ostream &out,Stu &s)
{
	out<<s.num<<'\t'<<s.name<<'\t'<<s.score<<endl;
	return out;
}

bool Stu::operator<(Stu *s)
{
	return(this->score<s->score);
}

bool Stu::operator>(Stu *s)
{
	return(this->score>s->score);
}

class Systerm
{
private:
	list<Stu *> s;   
public:
	Systerm();
	~Systerm();
	void start();
	void menu();
	void add_stu();
	void del_stu();
	void search_stu();
	void print_stu();
	void mod_stu();
	//static bool f1(Stu &s1,Stu &s2);
	static bool f2(Stu *s1,Stu *s2);
	void stu_sort();
	static void pt(Stu *stu);
};

Systerm::Systerm(){}
Systerm::~Systerm(){}
void Systerm::menu()
{
	system("clear");
	cout<<"\n学生管理系统\n\n";
	cout<<"1 add student\n";
	cout<<"2 mod student\n";
	cout<<"3 search student\n";
	cout<<"4 print student\n";
	cout<<"5 del student\n";
	cout<<"0 exit\n\n";
	cout<<"please select ";
}

void Systerm::start()
{
	int select;
	int flag = 1;
	while(flag)
	{
		menu();
		cin>>select;
		switch(select)
		{
			case ADD:
				add_stu();
				break;
			case MOD:
				mod_stu();
				break;
			case SEARCH:
				search_stu();
				break;
			case PRINT:
				print_stu();
				break;
			case DEL:
				del_stu();
				break;
			case EXIT:
				flag = 0;
				break;
			default:
				cout<<"输入无效，重新输入\n";
				sleep(1);
				break;
		}
	}
}

void Systerm::add_stu()
{
	system("clear");
	Stu *ps = new Stu;
	cin>>(*ps);	
	s.push_front(ps);
	cout<<"\n添加成功\n";	
	sleep(1);
}

void Systerm::del_stu()
{
	system("clear");
	if(s.empty())
	{
		cout<<"no student..\n";
		sleep(1);
		return;
	}
	int num,flag=0;
	cout<<"请输入要删除学生的学号:";
	cin>>num;
	list<Stu *>::iterator it;	

	for(it=	s.begin();it!=s.end();it++)
	{
		if((*it)->getNum()==num)
		{
			Stu *ps = (*it);
			s.erase(it);
			delete ps;
			cout<<"\n删除成功\n";		
			flag = 1;
			break;
		}
	}
	if(!flag)
	{
		cout<<"\n该学生不存在\n";
	}
	sleep(1);

}

void Systerm::search_stu()
{
	system("clear");
	if(s.empty())
	{
		cout<<"no student..\n";
		sleep(1);
		return;
	}
	int i,num,flag=0;
	cout<<"请输入学生学号:";
	cin>>num;
	
	for(auto tmp:s)
	{
		if(tmp->getNum() == num)
		{
			cout<<"num"<<'\t'<<"name"<<'\t'<<"score\n";
			cout<<(*tmp);
			getchar();
			getchar();
			return;
		}
	}
	cout<<"\n未查找到该学生\n";
	sleep(1);
}

void Systerm::pt(Stu *stu)
{
	cout<<(*stu);
}
void Systerm::print_stu()
{
	system("clear");
	int i;
	if(s.empty())
	{
		cout<<"no student..\n";
		sleep(1);
		return;
	}
	s.sort(f2);
	cout<<"num"<<'\t'<<"name"<<'\t'<<"score\n";
	for_each(s.begin(),s.end(),pt);
	getchar();
	getchar();
}

void Systerm::mod_stu()
{
	system("clear");
	if(s.empty())
	{
		cout<<"no student..\n";
		sleep(1);
		return;
	}
	int i,num,flag=0;
	cout<<"请输入要修改学的生学号:";
	cin>>num;
	for(auto tmp:s)
	{
		if(tmp->getNum() == num)
		{
			cin>>(*tmp);
			//s.emplace(s.begin()+i,t);
			//s.erase(s.begin()+i+1);
			cout<<"\n修改成功\n";
			cout<<"num"<<'\t'<<"name"<<'\t'<<"score\n";
			cout<<(*tmp);
			getchar();
			getchar();
			return;
		}
	}
	cout<<"\n未找到该学生\n";
	sleep(1);
}

bool Systerm::f2(Stu *s1,Stu *s2)
{
	return s1>s2;
}

void Systerm::stu_sort()
{
	s.sort(f2);
}

int main()
{
	Systerm p;
	p.start();

}










